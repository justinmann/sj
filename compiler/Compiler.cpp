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

    auto ctypes = CType::create("i32", "int32_t", "(int32_t)0", "int32_option", "int32_empty");
    typeI32 = ctypes->stackValueType;
    typeI32Option = ctypes->stackOptionType;

    ctypes = CType::create("i64", "int64_t", "(int64_t)0", "int64_option", "int64_empty");
    typeI64 = ctypes->stackValueType;
    typeI64Option = ctypes->stackOptionType;

    ctypes = CType::create("u32", "uint32_t", "(uint32_t)0", "uint32_option", "uint32_empty");
    typeU32 = ctypes->stackValueType;
    typeU32Option = ctypes->stackOptionType;

    ctypes = CType::create("u64", "uint64_t", "(uint64_t)0", "uint64_option", "uint64_empty");
    typeU64 = ctypes->stackValueType;
    typeU64Option = ctypes->stackOptionType;

    ctypes = CType::create("ptr", "uintptr_t", "(uintptr_t)0", "uintptr_option", "uintptr_empty");
    typePtr = ctypes->stackValueType;
    typePtrOption = ctypes->stackOptionType;

    ctypes = CType::create("f32", "float", "0.0f", "float_option", "float_empty");
    typeF32 = ctypes->stackValueType;
    typeF32Option = ctypes->stackOptionType;

    ctypes = CType::create("f64", "double", "0.0", "double_option", "double_empty");
    typeF64 = ctypes->stackValueType;
    typeF64Option = ctypes->stackOptionType;

    ctypes = CType::create("bool", "bool", "false", "bool_option", "bool_empty");
    typeBool = ctypes->stackValueType;
    typeBoolOption = ctypes->stackOptionType;

    ctypes = CType::create("char", "char", "'\0'", "char_option", "char_empty");
    typeChar = ctypes->stackValueType;
    typeCharOption = ctypes->stackOptionType;

    ctypes = CType::create("void", "void", "", "", "");
    typeVoid = ctypes->stackValueType;
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
	shared_ptr<CFunctionDefinition> globalFunctionDefinition;
	shared_ptr<NFunction> anonFunction;
	shared_ptr<CFunctionDefinition> currentFunctionDefintion;
	auto templateTypes = vector<shared_ptr<CType>>();
	shared_ptr<CFunction> currentFunction;
	shared_ptr<CFunction> globalFunction;

	auto result = genNodeFile(fileName);
	if (result->errors.size() == 0) {
		anonFunction = make_shared<NFunction>(CLoc::undefined, FT_Public, nullptr, "global", nullptr, nullptr, nullptr, result->block, nullptr, nullptr, nullptr);
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
            // Force global function to have void return
            result->block->statements.push_back(make_shared<NVoid>(CLoc::undefined));

			if (result->errors.size() == 0) {
				state = CompilerState::FixVar;
				currentFunction = make_shared<CFunction>(currentFunctionDefintion, FT_Public, templateTypes, weak_ptr<CFunction>(), nullptr, CTM_Stack);
				currentFunction->init(this, *result, nullptr, nullptr);
				auto currentVar = currentFunction->getThisVar(this, *result);
				anonFunction->getVar(this, *result, currentFunction, currentVar, CTM_Stack);
				globalFunction = static_pointer_cast<CFunction>(currentFunction->getCFunction(this, *result, "global", nullptr, nullptr, CTM_Stack));
                auto globalVar = globalFunction->getThisVar(this, *result);
                auto mainLoop = static_pointer_cast<CFunction>(globalFunction->getCFunction(this, *result, "mainLoop", globalFunction, nullptr, CTM_Stack));
#ifdef VAR_OUTPUT
				currentFunction->dump(this, *compilerResult, 0);
#endif

				if (result->errors.size() == 0) {
                    if (debugStream) {
                        map<shared_ptr<CBaseFunction>, string> functionDumps;
                        stringstream ss;
                        stringstream dotSS;
                        globalFunction->dumpBody(this, *result, functionDumps, ss, 0);
                        // globalVar->dump(this, *result, nullptr, nullptr, CTM_Stack, nullptr, functionDumps, ss, dotSS, 0);
                        
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
                        *debugStream << ss.str() << "\n\n";
                    }

					state = CompilerState::Compile;  

                    // Create the default object struct, all other object structs must have these variables
                    string structName = "sjs_object";
                    if (output.structs.find(structName) == output.structs.end()) {
                        output.structs[structName].push_back("int _refCount");
                    }

                    globalFunction->transpileDefinition(this, *result, &output);

                    auto hasMainLoop = false;
                    if (mainLoop) {
                        mainLoop->transpileDefinition(this, *result, &output);
                        hasMainLoop = true;
                    }

                    if (result->errors.size() == 0) {
                        output.writeToStream(stream, hasMainLoop);
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

shared_ptr<CType> Compiler::getType(const string& name) const {
    if (name == "i32") {
        return typeI32;
    }
    else if (name == "i64") {
        return typeI64;
    }
    else if (name == "u32") {
        return typeU32;
    }
    else if (name == "u64") {
        return typeU64;
    }
    else if (name == "f32") {
        return typeF32;
    }
    else if (name == "f64") {
        return typeF64;
    }
    else if (name == "ptr") {
        return typePtr;
    }
    else if (name == "bool") {
        return typeBool;
    }
    else if (name == "char") {
        return typeChar;
    }
    else if (name == "void") {
        return typeVoid;
    }
    else if (name == "i32?") {
        return typeI32Option;
    }
    else if (name == "i64?") {
        return typeI64Option;
    }
    else if (name == "u32?") {
        return typeU32Option;
    }
    else if (name == "u64?") {
        return typeU64Option;
    }
    else if (name == "f32?") {
        return typeF32Option;
    }
    else if (name == "f64?") {
        return typeF64Option;
    }
    else if (name == "ptr?") {
        return typePtrOption;
    }
    else if (name == "bool?") {
        return typeBoolOption;
    }
    else if (name == "char?") {
        return typeCharOption;
    }
    else {
        return nullptr;
    }
}

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
