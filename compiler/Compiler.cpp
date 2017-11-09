//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "../node/Node.h"
#include <fstream>
#include <streambuf>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

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

//std::string Type_print(Type* type) {
//    std::string type_str;
//    llvm::raw_string_ostream rso(type_str);
//    type->print(rso);
//    return rso.str();
//}
//
//Function* getFunctionFromBuilder(IRBuilder<>* builder) {
//    return builder->GetInsertBlock()->getParent();
//}

//IRBuilder<> getEntryBuilder(IRBuilder<>* builder) {
//    Function *function = getFunctionFromBuilder(builder);
//    return IRBuilder<>(&function->getEntryBlock(), function->getEntryBlock().end()--);
//}

#ifdef DEBUG_CALLSTACK
const char* callstack[9999];
int callstackIndex = 0;
map<void*, vector<vector<const char*>>> retains;
map<void*, vector<vector<const char*>>> releases;
map<void*, const char*> objTypes;

extern "C" void pushFunction(const char* str) {
    printf("push: %s\n", str);
    callstack[callstackIndex] = str;
    callstackIndex++;
}

extern "C" void popFunction() {
    callstackIndex--;
    printf("pop: %s\n", callstack[callstackIndex]);
}

extern "C" void recordRetain(void* v, const char* str) {
    printf("RETAIN: %llx %s\n", (int64_t)v, str);
    vector<const char*> stack(callstackIndex);
    for (int i = 0; i < callstackIndex; i++) {
        stack.push_back(callstack[i]);
    }
    retains[v].push_back(stack);
    objTypes[v] = str;
}

extern "C" void recordRelease(void* v, const char* str) {
    printf("RELEASE: %llx %s\n", (int64_t)v, str);
    vector<const char*> stack(callstackIndex);
    for (int i = 0; i < callstackIndex; i++) {
        stack.push_back(callstack[i]);
    }
    releases[v].push_back(stack);
    objTypes[v] = str;
}
#endif

extern "C" void debugFunction(const char* str, void* v, int64_t t) {
    printf("ERROR: %s %llx %lld\n", str, (uint64_t)v, t);
#ifdef DEBUG_CALLSTACK
    for (int i = 0; i < callstackIndex; i++) {
        printf("%s\n", callstack[i]);
    }
#endif
}

//class KaleidoscopeJIT {
//private:
//    shared_ptr<TargetMachine> TM;
//    const DataLayout DL;
//    ObjectLinkingLayer<> ObjectLayer;
//    IRCompileLayer<decltype(ObjectLayer)> CompileLayer;
//    
//public:
//    typedef decltype(CompileLayer)::ModuleSetHandleT ModuleHandle;
//    
//    KaleidoscopeJIT(shared_ptr<TargetMachine> tm) : TM(tm), DL(TM->createDataLayout()), CompileLayer(ObjectLayer, SimpleCompiler(*TM)) {
//        llvm::sys::DynamicLibrary::LoadLibraryPermanently(nullptr);
//    }
//    
//    TargetMachine &getTargetMachine() { return *TM; }
//    
//    ModuleHandle addModule(unique_ptr<Module> M) {
//        // Build our symbol resolver:
//        // Lambda 1: Look back into the JIT itself to find symbols that are part of
//        //           the same "logical dylib".
//        // Lambda 2: Search for external symbols in the host process.
//        auto Resolver = createLambdaResolver(
//                                             [&](const string &Name) {
//#ifdef SYMBOL_OUTPUT
//                                                 printf("Looking for %s\n", Name.c_str());
//#endif
//                                                 if (auto Sym = CompileLayer.findSymbol(Name, false))
//                                                     return Sym.toRuntimeDyldSymbol();
//                                                 return RuntimeDyld::SymbolInfo(nullptr);
//                                             },
//                                             [](const string &Name) {
//                                                 if (auto SymAddr =
//                                                     RTDyldMemoryManager::getSymbolAddressInProcess(Name))
//                                                     return RuntimeDyld::SymbolInfo(SymAddr, JITSymbolFlags::Exported);
//                                                 return RuntimeDyld::SymbolInfo(nullptr);
//                                             });
//        
//        // Build a singlton module set to hold our module.
//        vector<unique_ptr<Module>> Ms;
//        Ms.push_back(move(M));
//        
//        // Add the set to the JIT with the resolver we created above and a newly
//        // created SectionMemoryManager.
//        return CompileLayer.addModuleSet(move(Ms),
//                                         make_unique<SectionMemoryManager>(),
//                                         move(Resolver));
//    }
//    
//    JITSymbol findSymbol(const string Name) {
//        string MangledName;
//        raw_string_ostream MangledNameStream(MangledName);
//        Mangler::getNameWithPrefix(MangledNameStream, Name, DL);
//        return CompileLayer.findSymbol(MangledNameStream.str(), true);
//    }
//    
//    void removeModule(ModuleHandle H) {
//        CompileLayer.removeModuleSet(H);
//    }
//    
//};

Compiler::Compiler() {
    //InitializeNativeTarget();
    //InitializeNativeTargetAsmPrinter();
    //InitializeNativeTargetAsmParser();

	typeI32 = make_shared<CType>("i32", "int32_t", "(int32_t)0");
    typeI64 = make_shared<CType>("i64", "int64_t", "(int64_t)0");
    typeU32 = make_shared<CType>("u32", "uint32_t", "(uint32_t)0");
    typeU64 = make_shared<CType>("u64", "uint64_t", "(uint64_t)0");
    typePtr = make_shared<CType>("ptr", "uintptr_t", "(uintptr_t)0");
    typeF32 = make_shared<CType>("f32", "float", "0.0f");
    typeF64 = make_shared<CType>("f64", "double", "0.0");
	typeBool = make_shared<CType>("bool", "bool", "false");
	typeChar = make_shared<CType>("char", "char", "'\0'");
	typeVoid = make_shared<CType>("void", "void", "");
}

void Compiler::reset() {
    includedBlockFileNames.clear();
    includedBlocks.clear();
    //functionNames.clear();
    //entryBuilders.clear();
    //interfaceDefinitions.clear();
    //
    //allocFunction = nullptr;
    //reallocFunction = nullptr;
    //freeFunction = nullptr;
    //debugFunction = nullptr;
#ifdef DEBUG_CALLSTACK
    pushFunction = nullptr;
    popFunction = nullptr;
    recordRetainFunction = nullptr;
    recordReleaseFunction = nullptr;
    
    callstackIndex = 0;
    retains.clear();
    releases.clear();
#endif
    
    // Open a new module.
    //module = llvm::make_unique<Module>("sj", context);
    //
    //exception = llvm::make_unique<Exception>(&context, module.get());

    //// Create a new pass manager attached to it.
    //TheFPM = llvm::make_unique<legacy::FunctionPassManager>(module.get());
    /*
    // Do simple "peephole" optimizations and bit-twiddling optzns.
    TheFPM->add(createInstructionCombiningPass());
    // Reassociate expressions.
    TheFPM->add(createReassociatePass());
    // Eliminate Common SubExpressions.
    TheFPM->add(createGVNPass());
    // Simplify the control flow graph (deleting unreachable blocks, etc).
    TheFPM->add(createCFGSimplificationPass());
    */
//    TheFPM->doInitialization();
//
//#ifdef DWARF_ENABLED
//    // Add the current debug info version into the module.
//    module->addModuleFlag(Module::Warning, "Debug Info Version",
//                          DEBUG_METADATA_VERSION);
//    
//    // Darwin only supports dwarf2.
//    if (Triple(sys::getProcessTriple()).isOSDarwin())
//        module->addModuleFlag(llvm::Module::Warning, "Dwarf Version", 2);
//    
//    // Construct the DIBuilder, we do this here because we need the module.
//    DBuilder = llvm::make_unique<DIBuilder>(*module);
//    
//    // Initialize value types
//    typeInt = make_shared<CType>("int", Type::getInt64Ty(context), DBuilder->createBasicType("int", 64, 64, dwarf::DW_ATE_signed), ConstantInt::get(context, APInt(64, 0)));
//    typeBool = make_shared<CType>("bool", Type::getInt1Ty(context), DBuilder->createBasicType("bool", 1, 64, dwarf::DW_ATE_boolean), ConstantInt::get(context, APInt(1, 0)));
//    typeFloat = make_shared<CType>("float", Type::getDoubleTy(context), DBuilder->createBasicType("double", 64, 64, dwarf::DW_ATE_float), ConstantFP::get(context, APFloat(0.0)));
//    typeChar = make_shared<CType>("char", Type::getInt8Ty(context), DBuilder->createBasicType("char", 8, 64, dwarf::DW_ATE_UTF), ConstantInt::get(context, APInt(8, 0)));
//    typeVoid = make_shared<CType>("void", Type::getVoidTy(context), nullptr, nullptr);
//#else
//    // Initialize value types
//    typeInt = make_shared<CType>("int", Type::getInt64Ty(context), ConstantInt::get(context, APInt(64, 0)));
//    typeBool = make_shared<CType>("bool", Type::getInt1Ty(context), ConstantInt::get(context, APInt(1, 0)));
//    typeFloat = make_shared<CType>("float", Type::getDoubleTy(context), ConstantFP::get(context, APFloat(0.0)));
//    typeChar = make_shared<CType>("char", Type::getInt8Ty(context), ConstantInt::get(context, APInt(8, 0)));
//    typeVoid = make_shared<CType>("void", Type::getVoidTy(context), nullptr);
//#endif
}

shared_ptr<CResult> Compiler::genNodeFile(const string& fileName) {
    std::ifstream t(fileName);
    std::string str;
    
    if (t.fail()) {
        auto result = make_shared<CResult>();
        result->addError(CLoc(), CErrorCode::InvalidString, "file does not exist '%s'", fileName.c_str());
        return result;
    }
    
    t.seekg(0, std::ios::end);
    str.reserve((size_t)t.tellg());
    t.seekg(0, std::ios::beg);
    
    str.assign((std::istreambuf_iterator<char>(t)),
               std::istreambuf_iterator<char>());
    
    return genNode(fileName, str);
}
#ifdef YYDEBUG
extern int yydebug;
#endif

shared_ptr<CResult> Compiler::genNode(const string& fileName, const string& code) {
#ifdef YYDEBUG
    yydebug = 1; // use this to trigger the verbose debug output from bison
#endif

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
    NMatchReturn(const CLoc loc, shared_ptr<NBase> inner) : NBase(NodeType_Variable, loc), inner(inner) { };
    virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) { }

protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) { }
    
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
        auto type = getType(compiler, result, thisFunction, thisVar);
        if (type && !_callVar && !type->parent.expired()) {
            _callee = type->parent.lock();
            _callVar = CCallVar::create(compiler, result, CLoc::undefined, "??", make_shared<NodeList>(), thisFunction, weak_ptr<CVar>(), _callee);
            _callVar->getThisVar(compiler, result);
        }
        return nullptr;
    }
    
    virtual int setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
        if (_callVar) {
            vector<shared_ptr<NBase>> parameters(_callee->argDefaultValues.size());
            if (!_callVar->getParameters(compiler, result, parameters)) {
                return 0;
            }
            
            auto calleeVar = _callVar->getThisVar(compiler, result);
            auto count = 0;
            auto index = 0;
            for (auto argVar : parameters) {
                auto parameterVar = _callee->argVars[index];
                
                if (isHeapVar) {
                    parameterVar->setHeapVar(compiler, result, thisVar);
                }
                
                auto isDefaultAssignment = argVar == _callee->argDefaultValues[index];
                auto parameterHeapVar = parameterVar->getHeapVar(compiler, result, thisVar);
                if (argVar->nodeType == NodeType_Assignment) {
                    auto parameterAssignment = static_pointer_cast<NAssignment>(argVar);
                    assert(parameterAssignment->inFunctionDeclaration);
                    if (isDefaultAssignment) {
                        count += parameterAssignment->setHeapVar(compiler, result, _callee, calleeVar, parameterHeapVar);
                    } else {
                        count += parameterAssignment->setHeapVar(compiler, result, thisFunction, thisVar, parameterHeapVar);
                    }
                } else {
                    if (isDefaultAssignment) {
                        count += argVar->setHeapVar(compiler, result, _callee, calleeVar, parameterHeapVar);
                    } else {
                        count += argVar->setHeapVar(compiler, result, thisFunction, thisVar, parameterHeapVar);
                    }
                }
                index++;
            }
            
            if (isHeapVar) {
                count += calleeVar->setHeapVar(compiler, result, thisVar);
            }
            return count;
        }
        return 0;
    }
    
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
        return inner->getType(compiler, result, thisFunction, thisVar);
    }
    
    //virtual shared_ptr<ReturnValue> compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
    //    auto type = getType(compiler, result, thisFunction, thisVar);
    //    if (_callVar) {
    //        return _callVar->getLoadValue(compiler, result, thisVar, thisValue, false, nullptr, builder, catchBB, returnRefType);
    //    }
    //    return type->getDefaultValue(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB);
    //}
    
private:
    shared_ptr<CBaseFunction> _callee;
    shared_ptr<CCallVar> _callVar;
};

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
	}
	return str;
}

void CError::writeToStream(ostream& stream) {
    stream 
        << "ERROR:" << code << " " 
        << (fileName != nullptr ? fs::relative(fs::path(*fileName), fs::current_path()).generic_string() : "unknown")
        << "[" << line << ":" << col << "] " 
        << msg;
}

bool Compiler::transpile(const string& fileName, ostream& stream, ostream& errorStream, ostream* debugStream) {
	TrOutput output;
	shared_ptr<CVar> currentVar;
	shared_ptr<CVar> globalVar;
	shared_ptr<CFunctionDefinition> globalFunctionDefinition;
	shared_ptr<NFunction> anonFunction;
	shared_ptr<CFunctionDefinition> currentFunctionDefintion;
	auto templateTypes = vector<shared_ptr<CType>>();
	shared_ptr<CFunction> currentFunction;
	shared_ptr<CFunction> globalFunction;

	auto result = genNodeFile(fileName);
	if (result->errors.size() == 0) {
		anonFunction = make_shared<NFunction>(CLoc::undefined, FT_Public, nullptr, "global", nullptr, nullptr, nullptr, result->block, nullptr, nullptr);
		currentFunctionDefintion = CFunctionDefinition::create(this, *result, nullptr, FT_Public, "", nullptr, nullptr);
		state = CompilerState::Define;
        anonFunction->define(this, *result, currentFunctionDefintion);

		if (result->errors.size() == 0) {
			globalFunctionDefinition = currentFunctionDefintion->funcsByName["global"];
			for (auto index = (size_t)0; index < includedBlocks.size(); index++) {
				auto block = includedBlocks[index].second;
				block->define(this, *result, globalFunctionDefinition);
				result->block->statements.insert(result->block->statements.begin(), block->statements.begin(), block->statements.end());
			}
            result->block->statements.push_back(make_shared<NVoid>(CLoc::undefined));

			if (result->errors.size() == 0) {
				state = CompilerState::FixVar;
				currentFunction = make_shared<CFunction>(currentFunctionDefintion, FT_Public, templateTypes, weak_ptr<CFunction>(), nullptr);
				currentFunction->init(this, *result, nullptr, nullptr);
				currentFunction->createThisVar(this, *result, currentVar);
				anonFunction->getVar(this, *result, currentFunction, currentVar);
				globalFunction = static_pointer_cast<CFunction>(currentFunction->getCFunction(this, *result, "global", nullptr, nullptr));
				globalFunction->createThisVar(this, *result, globalVar);

#ifdef VAR_OUTPUT
				currentFunction->dump(this, *compilerResult, 0);
#endif

				if (result->errors.size() == 0) {
                    if (debugStream) {
                        map<shared_ptr<CBaseFunction>, string> functionDumps;
                        stringstream ss;
                        result->block->dump(this, *result, globalFunction, globalVar, functionDumps, ss, 0);
                        
                        vector<pair<string, string>> functionNames;
                        for (auto it : functionDumps) {
                            string s1 = it.first->fullName(true);
                            string s2 = it.second;
                            auto pair = make_pair(s1, s2);
                            functionNames.push_back(pair);
                        }

                        std::sort(functionNames.begin(), functionNames.end());

                        for (auto it : functionNames) {
                            *debugStream << it.second << "\n\n";
                        }
                        *debugStream << "global " << ss.str() << "\n\n";
                    }

					state = CompilerState::Compile;                    
                    vector<shared_ptr<NBase>> parameters;
                    globalFunction->transpile(this, *result, nullptr, nullptr, &output, &output.mainFunction, false, nullptr, globalVar, CLoc::undefined, parameters);

                    if (result->errors.size() == 0) {
                        output.writeToStream(stream);
                    }
				}
			}
		}
	}

	if (result->errors.size() > 0) {
		for (auto error : result->errors)
		{
			error.writeToStream(errorStream);
			errorStream << "\n";
		}
		return false;
	}
	return true;
}

shared_ptr<CResult> Compiler::compile(const string& fileName) {
    //reset();
    //
    //// Create the compile unit for the module.
    //TheCU = DBuilder->createCompileUnit(dwarf::DW_LANG_C, fileName, ".", "SJ Compiler", 0, "", 0);
    //
    //auto TargetTriple = sys::getDefaultTargetTriple();
    //module->setTargetTriple(TargetTriple);
    //
    //std::string Error;
    //auto Target = TargetRegistry::lookupTarget(TargetTriple, Error);
    //
    //// Print an error and exit if we couldn't find the requested target.
    //// This generally occurs if we've forgotten to initialise the
    //// TargetRegistry or we have a bogus target triple.
    //if (!Target) {
    //    errs() << Error;
    //    return nullptr;
    //}
    //
    //auto CPU = "generic";
    //auto Features = "";
    //
    //TargetOptions opt;
    //auto RM = Optional<Reloc::Model>();
    //auto TheTargetMachine = Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);
    //module->setDataLayout(TheTargetMachine->createDataLayout());
    //
    //auto result = genNodeFile(fileName);
    //// Early exit if compile fails
    //if (result->errors.size() > 0)
    //    return result;
    //
    //auto globalFunction = nodeToIL(*result);
    //if (!globalFunction) {
    //    return result;
    //}
    //
    //auto Filename = "output.o";
    //std::error_code EC;
    //raw_fd_ostream dest(Filename, EC, sys::fs::F_None);
    //
    //if (EC) {
    //    errs() << "Could not open file: " << EC.message();
    //    return result;
    //}
    //
    //legacy::PassManager pass;
    //auto FileType = TargetMachine::CGFT_ObjectFile; // TargetMachine::CGFT_AssemblyFile;
    //
    //if (TheTargetMachine->addPassesToEmitFile(pass, dest, FileType)) {
    //    errs() << "TheTargetMachine can't emit a file of this type";
    //    return result;
    //}
    //
    //pass.run(*module);
    //dest.flush();
    //
    //return result;
	return nullptr;
}

shared_ptr<CResult> Compiler::run(const string& code) {
//    auto opts = TargetOptions();
//    // opts.ExceptionModel = ExceptionHandling::DwarfCFI;
//    auto tm = shared_ptr<TargetMachine>(EngineBuilder().setTargetOptions(opts).selectTarget());
//    unique_ptr<KaleidoscopeJIT> TheJIT = llvm::make_unique<KaleidoscopeJIT>(tm);
//    
//    // Recreate module, since we just took away and stored it in the JIT
//    reset();
//    
//    // Create the compile unit for the module.
//    TheCU = DBuilder->createCompileUnit(dwarf::DW_LANG_C, "repl.sj", ".", "SJ Compiler", 0, "", 0);
//    
//    module->setDataLayout(TheJIT->getTargetMachine().createDataLayout());
//    
//    auto result = genNode("repl", code);
//    // Early exit if compile fails
//    if (result->errors.size() > 0)
//        return result;
//    
//    auto globalFunction = nodeToIL(*result);
//    if (!globalFunction) {
//        return result;
//    }
//    
//    auto H = TheJIT->addModule(move(module));
//    
//    // Search the JIT for the global symbol.
//    auto globalFunctionSymbol = TheJIT->findSymbol("global");
//    auto globalDestructorSymbol = TheJIT->findSymbol("global_destructor");
//    assert(globalFunctionSymbol && "Function not found");
//    
//    auto structType = globalFunction->getStructType(this, *result);
//    auto thisSize = structType ? structType->getStructNumElements() * 8 : 0;
//    auto thisPtr = malloc(thisSize);
//    
//    // Get the symbol's address and cast it to the right type (takes no
//    // arguments, returns a double) so we can call it as a native function.
//    hasException = false;
//    if (result->returnType == typeInt) {
//        int64_t (*FP)(void*) = (int64_t (*)(void*))(intptr_t)globalFunctionSymbol.getAddress();
//        int64_t resultValue = FP(thisPtr);
//        
//        result->type = RESULT_INT;
//        result->iResult = resultValue;
//    } else if (result->returnType == typeBool) {
//        bool (*FP)(void*) = (bool (*)(void*))(intptr_t)globalFunctionSymbol.getAddress();
//        bool resultValue = FP(thisPtr);
//        
//        result->type = RESULT_BOOL;
//        result->bResult = resultValue;
//    } else if (result->returnType == typeChar) {
//        char (*FP)(void*) = (char (*)(void*))(intptr_t)globalFunctionSymbol.getAddress();
//        char resultValue = FP(thisPtr);
//        
//        result->type = RESULT_CHAR;
//        result->cResult = resultValue;
//    } else if (result->returnType == typeFloat) {
//        double (*FP)(void*) = (double (*)(void*))(intptr_t)globalFunctionSymbol.getAddress();
//        double resultValue = FP(thisPtr);
//        
//        result->type = RESULT_FLOAT;
//        result->fResult = resultValue;
//    } else if (result->returnType == typeVoid) {
//        void (*FP)(void*) = (void (*)(void*))(intptr_t)globalFunctionSymbol.getAddress();
//        FP(thisPtr);
//        
//        result->type = RESULT_VOID;
//    } else if (result->returnType->name == "list_char") {
//        list_char* (*FP)(void*) = (list_char* (*)(void*))(intptr_t)globalFunctionSymbol.getAddress();
//        list_char* resultValue = FP(thisPtr);
//        
//        result->type = RESULT_STR;
//        result->strResult = resultValue->str;
//        
//        // TODO: Delete the result
//        // delete result;
//    } else {
//        printf("Unknown return type: %s\n", result->returnType->name.c_str());
//        assert(false);
//    }
//    
//    if (globalDestructorSymbol) {
//        void (*FP)(void*) = (void (*)(void*))(intptr_t)globalDestructorSymbol.getAddress();
//        FP(thisPtr);
//    }
//    // TODO: free(thisPtr);
//    
//    
//#ifdef DEBUG_CALLSTACK
//    for (auto it : retains) {
//        auto retainStacks = &it.second;
//        auto releaseStacks = &releases[it.first];
//        if (retainStacks->size() != releaseStacks->size()) {
//            printf("%s: %" PRIx64 ": retain %lu release %lu\n", objTypes[it.first], (unsigned long long)it.first, retainStacks->size(), releaseStacks->size());
//        }
//    }
//    
//#endif
//    
//    // Delete the anonymous expression module from the JIT.
//    TheJIT->removeModule(H);
//    
//    if (hasException) {
//        throw (void*)new SJException();
//    }
//    
//    return result;
	return nullptr;
}

//shared_ptr<CFunction> Compiler::nodeToIL(CResult& result) {
//    auto catchBlock = make_shared<NBlock>(CLoc::undefined);
//    catchBlock->statements.push_back(make_shared<NCall>(CLoc::undefined, "throwException", nullptr, nullptr));
//    catchBlock->statements.push_back(make_shared<NMatchReturn>(CLoc::undefined, result.block));
//    
//    // Define an extern for throwException at the beginning of the block
//    auto throwExceptionFunction = make_shared<NFunction>(CLoc::undefined, FT_Extern, "throwException", make_shared<CTypeName>(CTC_Value, "void"), "throwException", nullptr);
//    result.block->statements.insert(result.block->statements.begin(), throwExceptionFunction);
//    
//    auto arrayFunction = make_shared<NArrayCreateFunction>();
//    result.block->statements.insert(result.block->statements.begin(), arrayFunction);
//
//    auto anonFunction = make_shared<NFunction>(CLoc::undefined, FT_Public, nullptr, "global", nullptr, nullptr, nullptr, result.block, catchBlock, nullptr);
//    auto currentFunctionDefintion = CFunctionDefinition::create(this, result, nullptr, FT_Public, "", nullptr, nullptr);
//    state = CompilerState::Define;
//    anonFunction->define(this, result, currentFunctionDefintion);
//    
//    // Early exit if compile fails
//    if (result.errors.size() > 0)
//        return nullptr;
//
//    auto globalFunctionDefinition = currentFunctionDefintion->funcsByName["global"];
//    for (auto index = 0; index < includedBlocks.size(); index++) {
//        auto block = includedBlocks[index].second;
//        block->define(this, result, globalFunctionDefinition);
//        result.block->statements.insert(result.block->statements.begin(), block->statements.begin(), block->statements.end());
//    }
//    
//    // Early exit if compile fails
//    if (result.errors.size() > 0)
//        return nullptr;
//
//    state = CompilerState::FixVar;
//    auto templateTypes = vector<shared_ptr<CType>>();
//    auto currentFunction = make_shared<CFunction>(currentFunctionDefintion, FT_Public, templateTypes, weak_ptr<CFunction>(), nullptr);
//    currentFunction->init(this, result, nullptr, nullptr);
//    shared_ptr<CVar> currentVar;
//    currentFunction->createThisVar(this, result, currentVar);
//    anonFunction->getVar(this, result, currentFunction, currentVar);
//    auto globalFunction = static_pointer_cast<CFunction>(currentFunction->getCFunction(this, result, "global", nullptr, nullptr));
//    shared_ptr<CVar> globalVar;
//    globalFunction->createThisVar(this, result, globalVar);
//    
//#ifdef VAR_OUTPUT
//    currentFunction->dump(this, *compilerResult, 0);
//#endif
//    
//    // Early exit if compile fails
//    if (result.errors.size() > 0)
//        return nullptr;
//    
//#ifdef NODE_OUTPUT
//    map<shared_ptr<CBaseFunction>, string> functionDumps;
//    stringstream ss;
//    compilerResult->block->dump(this, *compilerResult, globalFunction, globalVar, functionDumps, ss, 0);
//    for (auto it : functionDumps) {
//        printf("%s\n\n", it.second.c_str());
//    }
//    printf("global %s\n\n", ss.str().c_str());
//#endif
//    
//    state = CompilerState::Compile;
//    anonFunction->compile(this, result, currentFunction, currentVar, nullptr, nullptr, nullptr, RRT_Auto);
//    auto function = globalFunction->getFunction(this, result, globalVar);
//    globalFunction->getDestructor(this, result);
//    result.returnType = globalFunction->getReturnType(this, result, globalVar);
//    if (!function) {
//        return nullptr;
//    }
//    auto thisType = globalFunction->getThisType(this, result);
//    
//#ifdef DWARF_ENABLED
//    DBuilder->finalize();
//#endif
//    
//#ifdef MODULE_OUTPUT
//    module->dump();
//#endif
//
//    // Early exit if compilation fails
//    if (result.errors.size() > 0)
//        return nullptr;
//    
//    if (verifyModule(*module.get()) && result.errors.size() == 0) {
//        module->dump();
//        
//        printf("----\n");
//        
//        auto output = new raw_os_ostream(std::cout);
//        verifyModule(*module.get(), output);
//        output->flush();
//        
//        assert(false);
//    }
//    
//    return globalFunction;
//}


shared_ptr<CType> Compiler::getType(const string& name) const {
    if (name == "i32") {
        return typeI32;
    } else if (name == "i64") {
        return typeI64;
    } else if (name == "u32") {
        return typeU32;
    } else if (name == "u64") {
        return typeU64;
    } else if (name == "f32") {
        return typeF32;
    } else if (name == "f64") {
        return typeF64;
    } else if (name == "ptr") {
        return typePtr;
    } else if (name == "bool") {
        return typeBool;
    } else if (name == "char") {
        return typeChar;
    } else if (name == "void") {
        return typeVoid;
    } else {
        return nullptr;
    }
}

//void Compiler::emitLocation(IRBuilder<>* builder, const CLoc *loc) {
//#ifdef DWARF_ENABLED
//    if (!loc)
//        return builder->SetCurrentDebugLocation(DebugLoc());
//    
//    DIScope *Scope;
//    if (LexicalBlocks.empty())
//        Scope = TheCU;
//    else
//        Scope = LexicalBlocks.back();
//    
//    builder->SetCurrentDebugLocation(DebugLoc::get(loc->line, loc->col, Scope));
//#endif
//}

void Compiler::includeFile(CResult& result, const string& fileName) {
    assert(state == CompilerState::Define);
    
    if (includedBlockFileNames.find(fileName) == includedBlockFileNames.end()) {
        auto r = genNodeFile(fileName);
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

//shared_ptr<IRBuilder<>> Compiler::getEntryBuilder(Function* function) {
//    auto it = entryBuilders.find(function);
//    if (it == entryBuilders.end()) {
//        auto basicBlock = BasicBlock::Create(context, "entry", function);
//        auto builder = make_shared<IRBuilder<>>(basicBlock);
//        entryBuilders[function] = builder;
//        return builder;
//    } else {
//        return it->second;
//    }
//}
//
//Function* Compiler::getAllocFunction() {
//    if (!allocFunction) {
//        vector<Type*> argTypes;
//        argTypes.push_back(Type::getInt64Ty(context));
//        auto functionType = FunctionType::get(Type::getInt8PtrTy(context), argTypes, false);
//#ifdef DEBUG_ALLOC
//        allocFunction = Function::Create(functionType, Function::ExternalLinkage, "debugMalloc", module.get());
//#else
//        allocFunction = Function::Create(functionType, Function::ExternalLinkage, "malloc", module.get());
//#endif
//    }
//    return allocFunction;
//}
//
//Function* Compiler::getReallocFunction() {
//    if (!reallocFunction) {
//        vector<Type*> argTypes;
//        argTypes.push_back(Type::getInt8PtrTy(context));
//        argTypes.push_back(Type::getInt64Ty(context));
//        auto functionType = FunctionType::get(Type::getInt8PtrTy(context), argTypes, false);
//#ifdef DEBUG_ALLOC
//        reallocFunction = Function::Create(functionType, Function::ExternalLinkage, "debugRealloc", module.get());
//#else
//        reallocFunction = Function::Create(functionType, Function::ExternalLinkage, "realloc", module.get());
//#endif
//    }
//    return reallocFunction;
//}
//
//Function* Compiler::getFreeFunction() {
//    if (!freeFunction) {
//        vector<Type*> argTypes;
//        argTypes.push_back(Type::getInt8PtrTy(context));
//        auto functionType = FunctionType::get(Type::getVoidTy(context), argTypes, false);
//#ifdef DEBUG_ALLOC
//        freeFunction = Function::Create(functionType, Function::ExternalLinkage, "debugFree", module.get());
//#else
//        freeFunction = Function::Create(functionType, Function::ExternalLinkage, "free", module.get());
//#endif
//    }
//    return freeFunction;
//}
//
//void Compiler::callPushFunction(IRBuilder<>* builder, const string& name) {
//#ifdef DEBUG_CALLSTACK
//    if (!pushFunction) {
//        vector<Type*> argTypes;
//        argTypes.push_back(Type::getInt8PtrTy(context));
//        auto functionType = FunctionType::get(Type::getVoidTy(context), argTypes, false);
//        pushFunction = Function::Create(functionType, Function::ExternalLinkage, "pushFunction", module.get());
//    }
//    
//    GlobalValue* nameValue;
//    auto it = functionNames.find(name);
//    if (it == functionNames.end()) {
//        nameValue = builder->CreateGlobalString(name);
//        functionNames[name] = nameValue;
//    } else {
//        nameValue = it->second;
//    }
//    
//    auto namePtr = builder->CreateBitCast(nameValue, Type::getInt8PtrTy(context));
//
//    vector<Value*> args;
//    args.push_back(namePtr);
//    builder->CreateCall(pushFunction, ArrayRef<Value*>(args));
//#endif
//}
//
//
//void Compiler::callPopFunction(IRBuilder<>* builder) {
//#ifdef DEBUG_CALLSTACK
//    if (!popFunction) {
//        vector<Type*> argTypes;
//        auto functionType = FunctionType::get(Type::getVoidTy(context), argTypes, false);
//        popFunction = Function::Create(functionType, Function::ExternalLinkage, "popFunction", module.get());
//    }
//
//    vector<Value*> args;
//    builder->CreateCall(popFunction, ArrayRef<Value*>(args));
//#endif
//}
//
//void Compiler::callDebug(IRBuilder<>* builder, const string& name, Value* valuePtr, Value* valueInt) {
//    if (!debugFunction) {
//        vector<Type*> argTypes;
//        argTypes.push_back(Type::getInt8PtrTy(context));
//        argTypes.push_back(Type::getInt8PtrTy(context));
//        argTypes.push_back(Type::getInt64Ty(context));
//        auto functionType = FunctionType::get(Type::getVoidTy(context), argTypes, false);
//        debugFunction = Function::Create(functionType, Function::ExternalLinkage, "debugFunction", module.get());
//    }
//    
//    GlobalValue* nameValue;
//    auto it = functionNames.find(name);
//    if (it == functionNames.end()) {
//        nameValue = builder->CreateGlobalString(name);
//        functionNames[name] = nameValue;
//    } else {
//        nameValue = it->second;
//    }
//    
//    auto namePtr = builder->CreateBitCast(nameValue, Type::getInt8PtrTy(context));
//    Value* valueVoidPtr = nullptr;
//    if (!valuePtr) {
//        valueVoidPtr = ConstantPointerNull::get(Type::getInt8PtrTy(context));
//    } else {
//        valueVoidPtr = builder->CreateBitCast(valuePtr, Type::getInt8PtrTy(context));
//    }
//
//    if (!valueInt) {
//        valueInt = ConstantInt::get(context, APInt(64, 0));
//    }
//
//    vector<Value*> args;
//    args.push_back(namePtr);
//    args.push_back(valueVoidPtr);
//    args.push_back(valueInt);
//    builder->CreateCall(debugFunction, ArrayRef<Value*>(args));
//}
//
//void Compiler::recordRetain(IRBuilder<>* builder, Value* value, const string& name) {
//#ifdef DEBUG_CALLSTACK
//    if (!recordRetainFunction) {
//        vector<Type*> argTypes;
//        argTypes.push_back(Type::getInt8PtrTy(context));
//        argTypes.push_back(Type::getInt8PtrTy(context));
//        auto functionType = FunctionType::get(Type::getVoidTy(context), argTypes, false);
//        recordRetainFunction = Function::Create(functionType, Function::ExternalLinkage, "recordRetain", module.get());
//    }
//    
//    GlobalValue* nameValue;
//    auto it = functionNames.find(name);
//    if (it == functionNames.end()) {
//        nameValue = builder->CreateGlobalString(name);
//        functionNames[name] = nameValue;
//    } else {
//        nameValue = it->second;
//    }
//    
//    auto namePtr = builder->CreateBitCast(nameValue, Type::getInt8PtrTy(context));
//    auto valuePtr = builder->CreateBitCast(value, Type::getInt8PtrTy(context));
//    
//    vector<Value*> args;
//    args.push_back(valuePtr);
//    args.push_back(namePtr);
//    builder->CreateCall(recordRetainFunction, ArrayRef<Value*>(args));
//#endif
//}
//
//void Compiler::recordRelease(IRBuilder<>* builder, Value* value, const string& name) {
//#ifdef DEBUG_CALLSTACK
//    if (!recordReleaseFunction) {
//        vector<Type*> argTypes;
//        argTypes.push_back(Type::getInt8PtrTy(context));
//        argTypes.push_back(Type::getInt8PtrTy(context));
//        auto functionType = FunctionType::get(Type::getVoidTy(context), argTypes, false);
//        recordReleaseFunction = Function::Create(functionType, Function::ExternalLinkage, "recordRelease", module.get());
//    }
//    
//    GlobalValue* nameValue;
//    auto it = functionNames.find(name);
//    if (it == functionNames.end()) {
//        nameValue = builder->CreateGlobalString(name);
//        functionNames[name] = nameValue;
//    } else {
//        nameValue = it->second;
//    }
//    
//    auto namePtr = builder->CreateBitCast(nameValue, Type::getInt8PtrTy(context));
//        auto valuePtr = builder->CreateBitCast(value, Type::getInt8PtrTy(context));
//    
//    vector<Value*> args;
//    args.push_back(valuePtr);
//    args.push_back(namePtr);
//    builder->CreateCall(recordReleaseFunction, ArrayRef<Value*>(args));
//#endif
//}

shared_ptr<CInterfaceDefinition> Compiler::getInterfaceDefinition(string& name) {
    auto it = interfaceDefinitions.find(name);
    if (it == interfaceDefinitions.end()) {
        auto result = make_shared<CInterfaceDefinition>(name);
        interfaceDefinitions[name] = result;
        return result;
    } else {
        return it->second;
    }
}

