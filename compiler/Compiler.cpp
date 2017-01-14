//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "Node.h"

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

CLoc CLoc::undefined = CLoc(-1, -1);

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
    typeInt = make_shared<CType>("int", Type::getInt64Ty(context));
    typeBool = make_shared<CType>("bool", Type::getInt1Ty(context));
    typeFloat = make_shared<CType>("float", Type::getDoubleTy(context));
    typeVoid = make_shared<CType>("void", Type::getVoidTy(context));
}

Compiler::~Compiler() {
#ifdef DWARF_ENABLED
    // Finalize the debug info.
    DBuilder->finalize();
#endif
}

void Compiler::InitializeModuleAndPassManager() {
    // Open a new module.
    module = llvm::make_unique<Module>("my cool jit", context);
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

shared_ptr<CResult> Compiler::compile(const char* code) {
    auto compilerResult = make_shared<CResult>();
    void* scanner;
    
    YYLOCATION loc = { 1, 1 };
    yylex_init_extra(loc, &scanner);
    auto yy_buf = yy_scan_string(code, scanner);
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
    NMatchReturn(const CLoc loc, shared_ptr<NBase> inner) : inner(inner), NBase(loc) { };
    virtual NodeType getNodeType() const { return NodeType_Variable; }
    virtual void define(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) { }
    virtual void fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) { }
    
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
        return inner->getReturnType(compiler, result, thisFunction);
    }
    
    virtual Value* compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const {
        return compiler->getDefaultValue(inner->getReturnType(compiler, result, thisFunction));
    }
    
    virtual void dump(Compiler* compiler, int level) const {
        
    }
};

shared_ptr<CResult> Compiler::run(const char* code) {
#ifdef YYDEBUG
    yydebug = 1; // use this to trigger the verbose debug output from bison
#endif
    
    // Recreate module, since we just took away and stored it in the JIT
    InitializeModuleAndPassManager();
    
    auto compilerResult = compile(code);
#ifdef NODE_OUTPUT
    compilerResult->block->dump(this, 0);
#endif
    // Early exit if compile fails
    if (compilerResult->errors.size() > 0)
        return compilerResult;
    
    auto anonArgs = NodeList();
    
    auto catchBlock = make_shared<NBlock>(CLoc::undefined);
    catchBlock->statements.push_back(make_shared<NCall>(CLoc::undefined, "throwException", StringList(), NodeList()));
    catchBlock->statements.push_back(make_shared<NMatchReturn>(CLoc::undefined, compilerResult->block));
    
    // Define an extern for throwException at the beginning of the block
    auto throwExceptionFunction = make_shared<NFunction>(CLoc::undefined, FT_Extern, "void", "throwException", StringList(), NodeList(), nullptr, nullptr);
    compilerResult->block->statements.insert(compilerResult->block->statements.begin(), throwExceptionFunction);
    
    auto anonFunction = make_shared<NFunction>(CLoc::undefined, FT_Public, "", "global", StringList(), anonArgs, compilerResult->block, catchBlock);
    auto currentFunction = CFunction::create(this, *compilerResult, nullptr, FT_Public, "", nullptr);
    state = CompilerState::Define;
    anonFunction->define(this, *compilerResult, currentFunction);
    
    // Early exit if compile fails
    if (compilerResult->errors.size() > 0)
        return compilerResult;
    
    state = CompilerState::FixVar;
    anonFunction->fixVar(this, *compilerResult, currentFunction);
#ifdef VAR_OUTPUT
    currentFunction->dump(this, *compilerResult, 0);
#endif
    
    // Early exit if compile fails
    if (compilerResult->errors.size() > 0)
        return compilerResult;

    state = CompilerState::Compile;
    anonFunction->compile(this, *compilerResult, currentFunction, nullptr, nullptr, nullptr);
    auto cfunction = currentFunction->getCFunction("global");
    auto function = cfunction->getFunction(this, *compilerResult);
    if (!function) {
        return compilerResult;
    }
    auto returnType = function->getReturnType();
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
    auto ExprSymbol = TheJIT->findSymbol("global");
    assert(ExprSymbol && "Function not found");
    
    auto thisSize = cfunction->thisVarsByName.size() * 8;
    auto thisPtr = malloc(thisSize);
    
    // Get the symbol's address and cast it to the right type (takes no
    // arguments, returns a double) so we can call it as a native function.
    hasException = false;
    if (returnType->isIntegerTy() && returnType->getScalarSizeInBits() == 64) {
        int64_t (*FP)(void*) = (int64_t (*)(void*))(intptr_t)ExprSymbol.getAddress();
        int64_t result = FP(thisPtr);
        
        compilerResult->type = RESULT_INT;
        compilerResult->iResult = result;
    } else if (returnType->isIntegerTy() && returnType->getScalarSizeInBits() == 1) {
        bool (*FP)(void*) = (bool (*)(void*))(intptr_t)ExprSymbol.getAddress();
        bool result = FP(thisPtr);
        
        compilerResult->type = RESULT_BOOL;
        compilerResult->bResult = result;
    } else if (returnType->isDoubleTy()) {
        double (*FP)(void*) = (double (*)(void*))(intptr_t)ExprSymbol.getAddress();
        double result = FP(thisPtr);

        compilerResult->type = RESULT_FLOAT;
        compilerResult->fResult = result;
    } else if (returnType->isVoidTy()) {
        void (*FP)(void*) = (void (*)(void*))(intptr_t)ExprSymbol.getAddress();
        FP(thisPtr);

        compilerResult->type = RESULT_VOID;
    } else {
        assert(false);
    }
    
    free(thisPtr);

    // Delete the anonymous expression module from the JIT.
    TheJIT->removeModule(H);
    
    if (hasException) {
        throw SJException();
    }
    
    return compilerResult;
}

shared_ptr<CType> Compiler::getType(const char* name) const {
    if (strcmp(name, "int") == 0) {
        return typeInt;
    } else if (strcmp(name, "bool") == 0) {
        return typeBool;
    } else if (strcmp(name, "float") == 0) {
        return typeFloat;
    } else if (strcmp(name, "void") == 0) {
        return typeVoid;
    } else {
        assert(false);
        return nullptr;
    }
}

Value* Compiler::getDefaultValue(shared_ptr<CType> type) {
    if (type == typeInt) {
        return ConstantInt::get(context, APInt(64, 0));
    } else if (type == typeBool) {
        return ConstantInt::get(context, APInt(1, 0));
    } else if (type == typeFloat) {
        return ConstantFP::get(context, APFloat(0.0));
    } else if (type == typeVoid) {
        return nullptr;
    } else {
        assert(false);
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
