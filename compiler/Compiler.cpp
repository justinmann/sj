//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "Node.h"

#include "llvm/ADT/APFloat.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/RuntimeDyld.h"
#include "llvm/ExecutionEngine/SectionMemoryManager.h"
#include "llvm/ExecutionEngine/Orc/CompileUtils.h"
#include "llvm/ExecutionEngine/Orc/JITSymbol.h"
#include "llvm/ExecutionEngine/Orc/IRCompileLayer.h"
#include "llvm/ExecutionEngine/Orc/LambdaResolver.h"
#include "llvm/ExecutionEngine/Orc/ObjectLinkingLayer.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Mangler.h"
#include "llvm/IR/Type.h"
#include "llvm/Support/DynamicLibrary.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Transforms/Scalar/GVN.h"

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

CType::CType(const char* name, Type* type) : name(name), llvmAllocType(type), llvmRefType(type) { }

CType::CType(Compiler* compiler, const char* name, vector<pair<string, shared_ptr<CType>>> members_) {
    auto structType = StructType::create(compiler->context, name);
    
    vector<Type*> structMembers;
    auto index = 0;
    for (auto it : members_) {
        membersByName[it.first] = pair<int, shared_ptr<CType>>(index, it.second);
        members.push_back(it.second);
        structMembers.push_back(it.second->llvmRefType);
        index++;
    }
    
    structType->setBody(ArrayRef<Type *>(structMembers));
    
    llvmAllocType = structType;
    llvmRefType = llvmAllocType->getPointerTo();
}

std::string Type_print(Type* type) {
    std::string type_str;
    llvm::raw_string_ostream rso(type_str);
    type->print(rso);
    return rso.str();
}

shared_ptr<CType> TLocalVar::getType(Compiler* compiler, CResult& result) {
    if (isInGetType) {
        result.errors.push_back(CError(CLoc::undefined, CErrorCode::TypeLoop));
        return nullptr;
    }
    
    isInGetType = true;
    if (!type) {
        type = shared_ptr<CType>(node->getReturnType(compiler, result));
    }
    isInGetType = false;
    return type;
}

Value* TLocalVar::getValue(Compiler* compiler, CResult& result) {
    if (!value) {
        Function* f = parent->getFunction(compiler, result);
        IRBuilder<> builder(&f->getEntryBlock(), f->getEntryBlock().begin());
        value = builder.CreateAlloca(getType(compiler, result)->llvmRefType, 0, node->name.c_str());
    }
    return value;
}

shared_ptr<CType> TFunctionVar::getType(Compiler* compiler, CResult& result) {
    if (isInGetType) {
        result.errors.push_back(CError(CLoc::undefined, CErrorCode::TypeLoop));
        return nullptr;
    }
    
    isInGetType = true;
    if (!type) {
        type = shared_ptr<CType>(assignment->getReturnType(compiler, result));
    }
    isInGetType = false;
    return type;
}

Value* TFunctionVar::getValue(Compiler* compiler, CResult& result) {
    if (!value) {
        value = parent->getArgumentValue(index, compiler);
    }
    return value;
}

TFunction::TFunction(TFunction* parent, const NFunctionDeclaration* node) : parent(parent), node(node), returnType(nullptr), thisType(nullptr), func(nullptr), isInGetType(false), isInGetFunction(false) {
    if (node) {
        int index = 0;
        for (auto &arg : *node->arguments) {
            if (arg->getNodeType() == NodeType::Assignment) {
                auto t = (const NAssignment*)arg.get();
                vars[t->name] = shared_ptr<TVar>((TVar*)new TFunctionVar(this, node, index, t));
            }
            index++;
        }
    }
}

shared_ptr<CType> TFunction::getReturnType(Compiler* compiler, CResult& result) {
    if (isInGetType) {
        result.errors.push_back(CError(CLoc::undefined, CErrorCode::TypeLoop));
        return nullptr;
    }
    
    isInGetType = true;
    if (!returnType) {
        returnType = shared_ptr<CType>(node->getBlockType(compiler, result));
    }
    isInGetType = false;
    return returnType;
}

shared_ptr<CType> TFunction::getThisType(Compiler* compiler, CResult& result) {
    if (!thisType) {
        // Verify all arguments are assignments with valid types
        vector<pair<string, shared_ptr<CType>>> memberTypes;
        for (auto &it : *node->arguments) {
            if (it->getNodeType() != NodeType::Assignment) {
                result.errors.push_back(CError(CLoc::undefined, CErrorCode::NotVariable));
                return nullptr;
            }
            auto t = (const NAssignment*)it.get();
            
            auto memberType = t->getReturnType(compiler, result);
            if (!memberType) {
                assert(false);
                return nullptr;
            }
            memberTypes.push_back(pair<string, shared_ptr<CType>>(t->name, shared_ptr<CType>(memberType)));
        }
        
        thisType = make_shared<CType>(compiler, node->name.c_str(), memberTypes);
    }
    return thisType;
}

Function* TFunction::getFunction(Compiler* compiler, CResult& result) {
    if (isInGetFunction) {
        result.errors.push_back(CError(CLoc::undefined, CErrorCode::TypeLoop));
        return nullptr;
    }
    
    isInGetFunction = true;
    if (!func) {
        auto returnType = getReturnType(compiler, result);
        if (returnType) {
            vector<Type*> argTypes;
            argTypes.push_back(getThisType(compiler, result)->llvmRefType);
            FunctionType *FT = FunctionType::get(returnType->llvmRefType, argTypes, false);
            func = Function::Create(FT, Function::ExternalLinkage, node->name.c_str(), compiler->module.get());
            func->args().begin()->setName("this");
            
            // Create a new basic block to start insertion into.
            basicBlock = BasicBlock::Create(compiler->context, "entry", func);
            auto prevInsertPoint = compiler->builder.saveIP();
            compiler->builder.SetInsertPoint(basicBlock);
            
    #ifdef DWARF_ENABLED
            SmallVector<Metadata *, 8> EltTys;
            for (auto &argType : argTypes) {
                EltTys.push_back(compiler->getDIType(argType));
            }
            auto ditypes = compiler->DBuilder->createSubroutineType(compiler->DBuilder->getOrCreateTypeArray(EltTys));
            
            // Create a subprogram DIE for this function.
            DIFile *Unit = compiler->DBuilder->createFile(compiler->TheCU->getFilename(), compiler->TheCU->getDirectory());
            DIScope *FContext = Unit;
            unsigned LineNo = node->loc.line;
            unsigned ScopeLine = LineNo;
            DISubprogram *SP = compiler->DBuilder->createFunction(FContext, node->name.c_str(), StringRef(), Unit, LineNo,
                                                                  ditypes, false /* internal linkage */, true /* definition */, ScopeLine,
                                                                  DINode::FlagPrototyped, false);
            func->setSubprogram(SP);
            
            // Push the current scope.
            compiler->LexicalBlocks.push_back(SP);
            
            // Unset the location for the prologue emission (leading instructions with no
            // location in a function are considered part of the prologue and the debugger
            // will run past them when breaking on a function)
            compiler->emitLocation(nullptr);
    #endif

            compiler->builder.restoreIP(prevInsertPoint);
        }
    }
    isInGetFunction = false;
   
    return func;
}

BasicBlock* TFunction::getBasicBlock() {
    assert(func != nullptr);
    return basicBlock;
}

Argument* TFunction::getThis() {
    assert(func != nullptr);
    return (Argument*)func->args().begin();
}

Value* TFunction::getArgumentValue(int index, Compiler* compiler) {
    assert(func != nullptr);
    auto thisValue = getThis();
    vector<Value*> v;
    v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
    v.push_back(ConstantInt::get(compiler->context, APInt(32, index)));
    auto paramPtr = compiler->builder.CreateInBoundsGEP(thisType->llvmAllocType, thisValue, ArrayRef<Value *>(v), "paramPtr");
    return paramPtr;
}


TFunction* TFunction::getTFunction(const string& name) const {
    auto t = funcs.find(name);
    if (t != funcs.end()) {
        return t->second.get();
    }
    if (parent) {
        return parent->getTFunction(name);
    }
    return nullptr;
}

TVar* TFunction::getTVariable(const string& name) const {
    auto t = vars.find(name);
    if (t != vars.end()) {
        return t->second.get();
    }
    if (parent) {
        return parent->getTVariable(name);
    }
    return nullptr;
}

int TFunction::getThisIndex(const string& name) const {
    auto argIndex = 0;
    for (auto it : *node->arguments) {
        if (it->getNodeType() == NodeType::Assignment) {
            auto t = (const NAssignment*)it.get();
            if (t->name == name) {
                return argIndex;
            }
        }
        argIndex++;
    }
    return -1;
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

Compiler::Compiler() : builder(context) {
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

shared_ptr<CResult> Compiler::run(const char* code) {
#ifdef YYDEBUG
    yydebug = 1; // use this to trigger the verbose debug output from bison
#endif
    
    // Recreate module, since we just took away and stored it in the JIT
    InitializeModuleAndPassManager();
    
    auto compilerResult = compile(code);
    // Early exit if compile fails
    if (compilerResult->errors.size() > 0)
        return compilerResult;
    
    auto anonArgs = make_shared<NodeList>();
    auto anonFunction = make_unique<NFunctionDeclaration>(CLoc::undefined, "", "__anon_expr", anonArgs, compilerResult->block);
    currentFunction = new TFunction(nullptr, nullptr);
    anonFunction->define(this, *compilerResult);
    // Early exit if compile fails
    if (compilerResult->errors.size() > 0)
        return compilerResult;   
    
    anonFunction->compile(this, *compilerResult);
    auto function = currentFunction->getTFunction("__anon_expr")->getFunction(this, *compilerResult);
    auto returnType = function->getReturnType();
    
#ifdef MODULE_OUTPUT
    module->dump();
#endif
    
    // Early exit if compilation fails
    if (compilerResult->errors.size() > 0)
        return compilerResult;

    auto H = TheJIT->addModule(move(module));
    
    // Search the JIT for the __anon_expr symbol.
    auto ExprSymbol = TheJIT->findSymbol("__anon_expr");
    assert(ExprSymbol && "Function not found");
    
    // Get the symbol's address and cast it to the right type (takes no
    // arguments, returns a double) so we can call it as a native function.
    if (returnType == typeInt->llvmRefType) {
        int64_t (*FP)() = (int64_t (*)())(intptr_t)ExprSymbol.getAddress();
        int64_t result = FP();
        
        compilerResult->type = RESULT_INT;
        compilerResult->iResult = result;
    } else if (returnType == typeBool->llvmRefType) {
        bool (*FP)() = (bool (*)())(intptr_t)ExprSymbol.getAddress();
        bool result = FP();
        
        compilerResult->type = RESULT_BOOL;
        compilerResult->bResult = result;
    } else if (returnType == typeFloat->llvmRefType) {
        double (*FP)() = (double (*)())(intptr_t)ExprSymbol.getAddress();
        double result = FP();

        compilerResult->type = RESULT_FLOAT;
        compilerResult->fResult = result;
    } else if (returnType == typeVoid->llvmRefType) {
        void (*FP)() = (void (*)())(intptr_t)ExprSymbol.getAddress();
        FP();

        compilerResult->type = RESULT_VOID;
    } else {
        assert(false);
    }

    // Delete the anonymous expression module from the JIT.
    TheJIT->removeModule(H);
    
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
        return builder.SetCurrentDebugLocation(DebugLoc());
    
    DIScope *Scope;
    if (LexicalBlocks.empty())
        Scope = TheCU;
    else
        Scope = LexicalBlocks.back();
    
    builder.SetCurrentDebugLocation(DebugLoc::get(node->loc.line, node->loc.col, Scope));
#endif
}

