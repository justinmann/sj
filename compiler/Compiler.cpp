//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "Node.h"
#include <fstream>
#include <streambuf>
#include "library.h"

using namespace llvm::orc;

typedef struct yy_buffer_state *YY_BUFFER_STATE;
struct YYLOCATION {
    int l;
    int c;
};
extern int yyparse(void*, CResult*);
extern int yylex_init_extra(YYLOCATION l, void**);
extern int yylex_destroy(void*);
extern YY_BUFFER_STATE yy_scan_string(const char*, void*);
extern void yy_delete_buffer(YY_BUFFER_STATE, void*);

CLoc CLoc::undefined = CLoc();

std::string Type_print(Type* type) {
    std::string type_str;
    llvm::raw_string_ostream rso(type_str);
    type->print(rso);
    return rso.str();
}

IRBuilder<> getEntryBuilder(IRBuilder<>* builder) {
    Function *function = builder->GetInsertBlock()->getParent();
    return IRBuilder<>(&function->getEntryBlock(), function->getEntryBlock().begin());
}

#ifdef DEBUG_CALLSTACK
const char* callstack[9999];
int callstackIndex = 0;
map<void*, vector<vector<const char*>>> retains;
map<void*, vector<vector<const char*>>> releases;
map<void*, const char*> objTypes;

extern "C" void pushFunction(const char* str) {
    callstack[callstackIndex] = str;
    callstackIndex++;
}

extern "C" void popFunction() {
    callstackIndex--;
}

extern "C" void debugFunction(const char* str, void* v) {
    printf("ERROR: %s\n", str);
    for (int i = 0; i < callstackIndex; i++) {
        printf("%s\n", callstack[i]);
    }
}

extern "C" void recordRetain(void* v, const char* str) {
    vector<const char*> stack(callstackIndex);
    for (int i = 0; i < callstackIndex; i++) {
        stack.push_back(callstack[i]);
    }
    retains[v].push_back(stack);
    objTypes[v] = str;
}

extern "C" void recordRelease(void* v, const char* str) {
    vector<const char*> stack(callstackIndex);
    for (int i = 0; i < callstackIndex; i++) {
        stack.push_back(callstack[i]);
    }
    releases[v].push_back(stack);
    objTypes[v] = str;
}
#endif

class KaleidoscopeJIT {
private:
    unique_ptr<TargetMachine> TM;
    const DataLayout DL;
    ObjectLinkingLayer<> ObjectLayer;
    IRCompileLayer<decltype(ObjectLayer)> CompileLayer;
    
public:
    typedef decltype(CompileLayer)::ModuleSetHandleT ModuleHandle;
    
    KaleidoscopeJIT()
    : TM(EngineBuilder().selectTarget()), DL(TM->createDataLayout()),
    CompileLayer(ObjectLayer, SimpleCompiler(*TM)) {
        llvm::sys::DynamicLibrary::LoadLibraryPermanently(nullptr);
    }
    
    TargetMachine &getTargetMachine() { return *TM; }
    
    ModuleHandle addModule(unique_ptr<Module> M) {
        // Build our symbol resolver:
        // Lambda 1: Look back into the JIT itself to find symbols that are part of
        //           the same "logical dylib".
        // Lambda 2: Search for external symbols in the host process.
        auto Resolver = createLambdaResolver(
                                             [&](const string &Name) {
#ifdef SYMBOL_OUTPUT
                                                 printf("Looking for %s\n", Name.c_str());
#endif
                                                 if (auto Sym = CompileLayer.findSymbol(Name, false))
                                                     return Sym.toRuntimeDyldSymbol();
                                                 return RuntimeDyld::SymbolInfo(nullptr);
                                             },
                                             [](const string &Name) {
                                                 if (auto SymAddr =
                                                     RTDyldMemoryManager::getSymbolAddressInProcess(Name))
                                                     return RuntimeDyld::SymbolInfo(SymAddr, JITSymbolFlags::Exported);
                                                 return RuntimeDyld::SymbolInfo(nullptr);
                                             });
        
        // Build a singlton module set to hold our module.
        vector<unique_ptr<Module>> Ms;
        Ms.push_back(move(M));
        
        // Add the set to the JIT with the resolver we created above and a newly
        // created SectionMemoryManager.
        return CompileLayer.addModuleSet(move(Ms),
                                         make_unique<SectionMemoryManager>(),
                                         move(Resolver));
    }
    
    JITSymbol findSymbol(const string Name) {
        string MangledName;
        raw_string_ostream MangledNameStream(MangledName);
        Mangler::getNameWithPrefix(MangledNameStream, Name, DL);
        return CompileLayer.findSymbol(MangledNameStream.str(), true);
    }
    
    void removeModule(ModuleHandle H) {
        CompileLayer.removeModuleSet(H);
    }
    
};

Compiler::Compiler() {
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();
    InitializeNativeTargetAsmParser();
    
    TheJIT = llvm::make_unique<KaleidoscopeJIT>();
    
    // Initialize value types
    typeInt = make_shared<CType>("int", Type::getInt64Ty(context), ConstantInt::get(context, APInt(64, 0)));
    typeBool = make_shared<CType>("bool", Type::getInt1Ty(context), ConstantInt::get(context, APInt(1, 0)));
    typeFloat = make_shared<CType>("float", Type::getDoubleTy(context), ConstantFP::get(context, APFloat(0.0)));
    typeChar = make_shared<CType>("char", Type::getInt8Ty(context), ConstantInt::get(context, APInt(8, 0)));
    typeVoid = make_shared<CType>("void", Type::getVoidTy(context), nullptr);
}

Compiler::~Compiler() {
#ifdef DWARF_ENABLED
    // Finalize the debug info.
    DBuilder->finalize();
#endif
}

void Compiler::InitializeModuleAndPassManager() {
    includedBlocks.clear();
    functionNames.clear();
    
    allocFunction = nullptr;
    freeFunction = nullptr;
#ifdef DEBUG_CALLSTACK
    pushFunction = nullptr;
    popFunction = nullptr;
    debugFunction = nullptr;
    recordRetainFunction = nullptr;
    recordReleaseFunction = nullptr;
    
    callstackIndex = 0;
    retains.clear();
    releases.clear();
#endif
    
    // Open a new module.
    module = llvm::make_unique<Module>("sj", context);
    module->setDataLayout(TheJIT->getTargetMachine().createDataLayout());
    
    exception = llvm::make_unique<Exception>(&context, module.get());

    // Create a new pass manager attached to it.
    TheFPM = llvm::make_unique<legacy::FunctionPassManager>(module.get());
    
    // Do simple "peephole" optimizations and bit-twiddling optzns.
    TheFPM->add(createInstructionCombiningPass());
    // Reassociate expressions.
    TheFPM->add(createReassociatePass());
    // Eliminate Common SubExpressions.
    TheFPM->add(createGVNPass());
    // Simplify the control flow graph (deleting unreachable blocks, etc).
    TheFPM->add(createCFGSimplificationPass());
    
    TheFPM->doInitialization();

#ifdef DWARF_ENABLED
    // Add the current debug info version into the module.
    module->addModuleFlag(Module::Warning, "Debug Info Version",
                          DEBUG_METADATA_VERSION);
    
    // Darwin only supports dwarf2.
    if (Triple(sys::getProcessTriple()).isOSDarwin())
        module->addModuleFlag(llvm::Module::Warning, "Dwarf Version", 2);
    
    // Construct the DIBuilder, we do this here because we need the module.
    DBuilder = llvm::make_unique<DIBuilder>(*module);
    
    // Create the compile unit for the module.
    // Currently down as "fib.ks" as a filename since we're redirecting stdin
    // but we'd like actual source locations.
    TheCU = DBuilder->createCompileUnit(dwarf::DW_LANG_C, "fib.ks", ".", "Kaleidoscope Compiler", 0, "", 0);

    ditypeInt = DBuilder->createBasicType("int", 64, 64, dwarf::DW_ATE_signed);
    ditypeBool = DBuilder->createBasicType("bool", 1, 64, dwarf::DW_ATE_boolean);
    ditypeFloat = DBuilder->createBasicType("double", 64, 64, dwarf::DW_ATE_float);
    ditypeVoid = nullptr;
#endif
}

shared_ptr<CResult> Compiler::compileFile(const string& fileName) {
    std::ifstream t(fileName);
    std::string str;
    
    t.seekg(0, std::ios::end);
    str.reserve(t.tellg());
    t.seekg(0, std::ios::beg);
    
    str.assign((std::istreambuf_iterator<char>(t)),
               std::istreambuf_iterator<char>());
    
    return compile(fileName, str);
}

shared_ptr<CResult> Compiler::compile(const string& fileName, const string& code) {
    auto compilerResult = make_shared<CResult>();
    compilerResult->fileName = make_shared<string>(fileName);
    void* scanner;
    
    YYLOCATION loc = { 1, 1 };
    yylex_init_extra(loc, &scanner);
    auto yy_buf = yy_scan_string(code.c_str(), scanner);
    yyparse(scanner, compilerResult.get());
    yy_delete_buffer(yy_buf, scanner);
    yylex_destroy(scanner);
    
    return compilerResult;
}

extern int yydebug;

bool hasException = false;

extern "C" void throwException() {
    hasException = true;
}

class NMatchReturn : public NBase {
public:
    const shared_ptr<NBase> inner;
    NMatchReturn(const CLoc loc, shared_ptr<NBase> inner) : inner(inner), NBase(NodeType_Variable, loc) { };
    virtual void dump(Compiler* compiler, int level) const { }

protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) { }
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) { return nullptr; }
    virtual int setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, bool isHeapVar) { return 0; }
    
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
        return inner->getType(compiler, result, thisFunction);
    }
    
    virtual shared_ptr<ReturnValue> compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
        return inner->getType(compiler, result, thisFunction)->getDefaultValue(compiler, result, thisFunction, thisValue, builder, catchBB);
    }
};

shared_ptr<CResult> Compiler::run(const string& code) {
#ifdef YYDEBUG
    yydebug = 1; // use this to trigger the verbose debug output from bison
#endif
    
    // Recreate module, since we just took away and stored it in the JIT
    InitializeModuleAndPassManager();
    
    auto compilerResult = compile("repl", code);
#ifdef NODE_OUTPUT
    compilerResult->block->dump(this, 0);
#endif
    // Early exit if compile fails
    if (compilerResult->errors.size() > 0)
        return compilerResult;
    
    auto catchBlock = make_shared<NBlock>(CLoc::undefined);
    catchBlock->statements.push_back(make_shared<NCall>(CLoc::undefined, "throwException", nullptr, nullptr));
    catchBlock->statements.push_back(make_shared<NMatchReturn>(CLoc::undefined, compilerResult->block));
    
    // Define an extern for throwException at the beginning of the block
    auto throwExceptionFunction = make_shared<NFunction>(CLoc::undefined, FT_Extern, "throwException", make_shared<CTypeName>("void"), "throwException", nullptr);
    compilerResult->block->statements.insert(compilerResult->block->statements.begin(), throwExceptionFunction);
    
    auto arrayFunction = make_shared<NArrayCreateFunction>();
    compilerResult->block->statements.insert(compilerResult->block->statements.begin(), arrayFunction);
    
    auto anonFunction = make_shared<NFunction>(CLoc::undefined, FT_Public, nullptr, "global", nullptr, nullptr, compilerResult->block, catchBlock, nullptr);
    auto currentFunctionDefintion = CFunctionDefinition::create(this, *compilerResult, nullptr, FT_Public, "", nullptr);
    state = CompilerState::Define;
    anonFunction->define(this, *compilerResult, currentFunctionDefintion);
    
    // Early exit if compile fails
    if (compilerResult->errors.size() > 0)
        return compilerResult;
    
    auto globalFunctionDefinition = currentFunctionDefintion->funcsByName["global"];
    for (auto index = 0; index < includedBlocks.size(); index++) {
        auto block = includedBlocks[index].second;
        block->define(this, *compilerResult, globalFunctionDefinition);
        compilerResult->block->statements.insert(compilerResult->block->statements.begin(), block->statements.begin(), block->statements.end());
    }
    
    // Early exit if compile fails
    if (compilerResult->errors.size() > 0)
        return compilerResult;

    state = CompilerState::FixVar;
    auto templateTypes = vector<shared_ptr<CType>>();
    auto currentFunction = currentFunctionDefintion->getFunction(this, *compilerResult, CLoc::undefined, templateTypes, weak_ptr<CFunction>());
    anonFunction->getVar(this, *compilerResult, currentFunction);
    auto cfunction = currentFunction->getCFunction(this, *compilerResult, CLoc::undefined, "global", nullptr, nullptr);
#ifdef VAR_OUTPUT
    currentFunction->dump(this, *compilerResult, 0);
#endif
    
    // Early exit if compile fails
    if (compilerResult->errors.size() > 0)
        return compilerResult;

    state = CompilerState::Compile;
    anonFunction->compile(this, *compilerResult, currentFunction, nullptr, nullptr, nullptr);
    auto function = cfunction->getFunction(this, *compilerResult);
    cfunction->getDestructor(this, *compilerResult);
    auto returnType = cfunction->getReturnType(this, *compilerResult);
    if (!function) {
        return compilerResult;
    }
    auto thisType = cfunction->getThisType(this, *compilerResult);

#ifdef MODULE_OUTPUT
    module->dump();
#endif
    
    // Early exit if compilation fails
    if (compilerResult->errors.size() > 0)
        return compilerResult;

    if (verifyModule(*module.get()) && compilerResult->errors.size() == 0) {
        module->dump();
        
        auto output = new raw_os_ostream(std::cout);
        verifyModule(*module.get(), output);
        output->flush();
        
        assert(false);
    }
    
    auto H = TheJIT->addModule(move(module));
    
    // Search the JIT for the global symbol.
    auto globalFunction = TheJIT->findSymbol("global");
    auto globalDestructor = TheJIT->findSymbol("global_destructor");
    assert(globalFunction && "Function not found");
    
    auto thisSize = cfunction->thisVarsByName.size() * 8;
    auto thisPtr = malloc(thisSize);
    
    // Get the symbol's address and cast it to the right type (takes no
    // arguments, returns a double) so we can call it as a native function.
    hasException = false;
    if (returnType == typeInt) {
        int64_t (*FP)(void*) = (int64_t (*)(void*))(intptr_t)globalFunction.getAddress();
        int64_t result = FP(thisPtr);
        
        compilerResult->type = RESULT_INT;
        compilerResult->iResult = result;
    } else if (returnType == typeBool) {
        bool (*FP)(void*) = (bool (*)(void*))(intptr_t)globalFunction.getAddress();
        bool result = FP(thisPtr);
        
        compilerResult->type = RESULT_BOOL;
        compilerResult->bResult = result;
    } else if (returnType == typeFloat) {
        double (*FP)(void*) = (double (*)(void*))(intptr_t)globalFunction.getAddress();
        double result = FP(thisPtr);

        compilerResult->type = RESULT_FLOAT;
        compilerResult->fResult = result;
    } else if (returnType == typeVoid) {
        void (*FP)(void*) = (void (*)(void*))(intptr_t)globalFunction.getAddress();
        FP(thisPtr);

        compilerResult->type = RESULT_VOID;
    } else if (returnType->name == "list_char") {
        list_char* (*FP)(void*) = (list_char* (*)(void*))(intptr_t)globalFunction.getAddress();
        list_char* result = FP(thisPtr);
        
        compilerResult->type = RESULT_STR;
        compilerResult->strResult = result->str;
        
        // TODO: Delete the result
        // delete result;
    } else {
        printf("Unknown return type: %s\n", returnType->name.c_str());
        assert(false);
    }
    
    if (globalDestructor) {
        void (*FP)(void*) = (void (*)(void*))(intptr_t)globalDestructor.getAddress();
        FP(thisPtr);
    }
    free(thisPtr);
    
    
#ifdef DEBUG_CALLSTACK
    for (auto it : retains) {
        auto retainStacks = &it.second;
        auto releaseStacks = &releases[it.first];
        if (retainStacks->size() != releaseStacks->size()) {
            printf("%s: %" PRIx64 ": retain %lu release %lu\n", objTypes[it.first], (unsigned long long)it.first, retainStacks->size(), releaseStacks->size());
        }
    }

#endif

    // Delete the anonymous expression module from the JIT.
    TheJIT->removeModule(H);
    
    if (hasException) {
        throw SJException();
    }
    
    return compilerResult;
}

shared_ptr<CType> Compiler::getType(const string& name) const {
    if (name == "int") {
        return typeInt;
    } else if (name == "bool") {
        return typeBool;
    } else if (name == "char") {
        return typeChar;
    } else if (name == "float") {
        return typeFloat;
    } else if (name == "void") {
        return typeVoid;
    } else {
        return nullptr;
    }
}

void Compiler::emitLocation(const NBase *node) {
#ifdef DWARF_ENABLED
    if (!node)
        return builder->SetCurrentDebugLocation(DebugLoc());
    
    DIScope *Scope;
    if (LexicalBlocks.empty())
        Scope = TheCU;
    else
        Scope = LexicalBlocks.back();
    
    builder->SetCurrentDebugLocation(DebugLoc::get(node->loc.line, node->loc.col, Scope));
#endif
}

void Compiler::includeFile(CResult& result, const string& fileName) {
    assert(state == CompilerState::Define);
    
    if (includedBlockFileNames.find(fileName) == includedBlockFileNames.end()) {
        auto r = compileFile(fileName);
        for (auto it : r->warnings) {
            result.warnings.push_back(it);
        }

        if (r->errors.size() > 0) {
            for (auto it : r->errors) {
                result.errors.push_back(it);
            }
            return ;
        }
        
        assert(r->block);
        includedBlockFileNames[fileName] = true;
        includedBlocks.push_back(pair<string, shared_ptr<NBlock>>(fileName, r->block));
    }
}

Function* Compiler::getAllocFunction() {
    if (!allocFunction) {
        vector<Type*> argTypes;
        argTypes.push_back(Type::getInt64Ty(context));
        auto functionType = FunctionType::get(Type::getInt8PtrTy(context), argTypes, false);
        allocFunction = Function::Create(functionType, Function::ExternalLinkage, "_Znwm", module.get());
    }
    return allocFunction;
}

Function* Compiler::getFreeFunction() {
    if (!freeFunction) {
        vector<Type*> argTypes;
        argTypes.push_back(Type::getInt8PtrTy(context));
        auto functionType = FunctionType::get(Type::getVoidTy(context), argTypes, false);
        freeFunction = Function::Create(functionType, Function::ExternalLinkage, "_ZdlPv", module.get());
    }
    return freeFunction;
}

void Compiler::callPushFunction(IRBuilder<>* builder, const string& name) {
#ifdef DEBUG_CALLSTACK
    if (!pushFunction) {
        vector<Type*> argTypes;
        argTypes.push_back(Type::getInt8PtrTy(context));
        auto functionType = FunctionType::get(Type::getVoidTy(context), argTypes, false);
        pushFunction = Function::Create(functionType, Function::ExternalLinkage, "pushFunction", module.get());
    }
    
    GlobalValue* nameValue;
    auto it = functionNames.find(name);
    if (it == functionNames.end()) {
        nameValue = builder->CreateGlobalString(name);
        functionNames[name] = nameValue;
    } else {
        nameValue = it->second;
    }
    
    auto namePtr = builder->CreateBitCast(nameValue, Type::getInt8PtrTy(context));

    vector<Value*> args;
    args.push_back(namePtr);
    builder->CreateCall(pushFunction, ArrayRef<Value*>(args));
#endif
}


void Compiler::callPopFunction(IRBuilder<>* builder) {
#ifdef DEBUG_CALLSTACK
    if (!popFunction) {
        vector<Type*> argTypes;
        auto functionType = FunctionType::get(Type::getVoidTy(context), argTypes, false);
        popFunction = Function::Create(functionType, Function::ExternalLinkage, "popFunction", module.get());
    }

    vector<Value*> args;
    builder->CreateCall(popFunction, ArrayRef<Value*>(args));
#endif
}

void Compiler::callDebug(IRBuilder<>* builder, const string& name, Value* valueMisc) {
#ifdef DEBUG_CALLSTACK
    if (!debugFunction) {
        vector<Type*> argTypes;
        argTypes.push_back(Type::getInt8PtrTy(context));
        argTypes.push_back(Type::getInt8PtrTy(context));
        auto functionType = FunctionType::get(Type::getVoidTy(context), argTypes, false);
        debugFunction = Function::Create(functionType, Function::ExternalLinkage, "debugFunction", module.get());
    }
    
    GlobalValue* nameValue;
    auto it = functionNames.find(name);
    if (it == functionNames.end()) {
        nameValue = builder->CreateGlobalString(name);
        functionNames[name] = nameValue;
    } else {
        nameValue = it->second;
    }
    
    auto namePtr = builder->CreateBitCast(nameValue, Type::getInt8PtrTy(context));
    auto valuePtr = builder->CreateBitCast(valueMisc, Type::getInt8PtrTy(context));

    vector<Value*> args;
    args.push_back(namePtr);
    args.push_back(valuePtr);
    builder->CreateCall(debugFunction, ArrayRef<Value*>(args));
#endif
}

void Compiler::recordRetain(IRBuilder<>* builder, Value* value, const string& name) {
#ifdef DEBUG_CALLSTACK
    if (!recordRetainFunction) {
        vector<Type*> argTypes;
        argTypes.push_back(Type::getInt8PtrTy(context));
        argTypes.push_back(Type::getInt8PtrTy(context));
        auto functionType = FunctionType::get(Type::getVoidTy(context), argTypes, false);
        recordRetainFunction = Function::Create(functionType, Function::ExternalLinkage, "recordRetain", module.get());
    }
    
    GlobalValue* nameValue;
    auto it = functionNames.find(name);
    if (it == functionNames.end()) {
        nameValue = builder->CreateGlobalString(name);
        functionNames[name] = nameValue;
    } else {
        nameValue = it->second;
    }
    
    auto namePtr = builder->CreateBitCast(nameValue, Type::getInt8PtrTy(context));
    auto valuePtr = builder->CreateBitCast(value, Type::getInt8PtrTy(context));
    
    vector<Value*> args;
    args.push_back(valuePtr);
    args.push_back(namePtr);
    builder->CreateCall(recordRetainFunction, ArrayRef<Value*>(args));
#endif
}

void Compiler::recordRelease(IRBuilder<>* builder, Value* value, const string& name) {
#ifdef DEBUG_CALLSTACK
    if (!recordReleaseFunction) {
        vector<Type*> argTypes;
        argTypes.push_back(Type::getInt8PtrTy(context));
        argTypes.push_back(Type::getInt8PtrTy(context));
        auto functionType = FunctionType::get(Type::getVoidTy(context), argTypes, false);
        recordReleaseFunction = Function::Create(functionType, Function::ExternalLinkage, "recordRelease", module.get());
    }
    
    GlobalValue* nameValue;
    auto it = functionNames.find(name);
    if (it == functionNames.end()) {
        nameValue = builder->CreateGlobalString(name);
        functionNames[name] = nameValue;
    } else {
        nameValue = it->second;
    }
    
    auto namePtr = builder->CreateBitCast(nameValue, Type::getInt8PtrTy(context));
        auto valuePtr = builder->CreateBitCast(value, Type::getInt8PtrTy(context));
    
    vector<Value*> args;
    args.push_back(valuePtr);
    args.push_back(namePtr);
    builder->CreateCall(recordReleaseFunction, ArrayRef<Value*>(args));
#endif
}

