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
extern int yyparse(void*, Compiler*, CParseFile*);
extern int yylex_init_extra(YYLOCATION l, void**);
extern int yylex_destroy(void*);
extern YY_BUFFER_STATE yy_scan_string(const char*, void*);
extern void yy_delete_buffer(YY_BUFFER_STATE, void*);

CLoc CLoc::undefined = CLoc();

Compiler::Compiler() {
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

shared_ptr<CParseFile> Compiler::genNodeFile(const string& fileName) {
    std::ifstream t(fileName);
    std::string str;
    
    if (t.fail()) {
        addError(CLoc(), CErrorCode::InvalidString, "file does not exist '%s'", fileName.c_str());
        return nullptr;
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

shared_ptr<CParseFile> Compiler::genNode(const string& fileName, const string& code) {
#ifdef YYDEBUG
    yydebug = 1; // use this to trigger the verbose debug output from bison
#endif

    auto parseFile = make_shared<CParseFile>();
    parseFile->fileName = make_shared<string>(fileName);
    parseFile->compiler = this;
    void* scanner;
    
    YYLOCATION loc = { 1, 1 };
    yylex_init_extra(loc, &scanner);
    auto yy_buf = yy_scan_string(code.c_str(), scanner);
    yyparse(scanner, this, parseFile.get());
    yy_delete_buffer(yy_buf, scanner);
    yylex_destroy(scanner);
    
    return parseFile;
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

	auto globalFile = genNodeFile(fileName);
	if (errors.size() == 0) {
        auto globalBlock = globalFile->block;
		anonFunction = make_shared<NFunction>(CLoc::undefined, FT_Public, nullptr, "global", nullptr, nullptr, nullptr, globalBlock, nullptr, nullptr, nullptr);
		currentFunctionDefintion = CFunctionDefinition::create(this, nullptr, FT_Public, "", nullptr, nullptr);
		state = CompilerState::Define;
        anonFunction->define(this, currentFunctionDefintion);

		if (errors.size() == 0) {
			globalFunctionDefinition = currentFunctionDefintion->funcsByName["global"];
            NodeList includeStatements;
			for (auto index = (size_t)0; index < includedBlocks.size(); index++) {
				auto includedBlock = includedBlocks[index].second;
				includedBlock->define(this, globalFunctionDefinition);
                includeStatements.insert(includeStatements.end(), includedBlock->statements.begin(), includedBlock->statements.end());
			}
            globalBlock->statements.insert(globalBlock->statements.begin(), includeStatements.begin(), includeStatements.end());

            // Force global function to have void return
            globalBlock->statements.push_back(make_shared<NVoid>(CLoc::undefined));

			if (errors.size() == 0) {
                state = CompilerState::Compile;
				currentFunction = make_shared<CFunction>(currentFunctionDefintion, FT_Public, templateTypes, weak_ptr<CFunction>(), nullptr, vector<shared_ptr<NCCode>>());
				currentFunction->init(this, nullptr);
                auto currentScope = currentFunction->getScope(this, CTM_Stack);
				anonFunction->getVar(this, currentScope, CTM_Stack);
                globalFunction = static_pointer_cast<CFunction>(currentFunction->getCFunction(this, CLoc::undefined, "global", nullptr, nullptr, CTM_Stack));
                auto globalScope = globalFunction->getScope(this, CTM_Stack);
                auto mainLoop = static_pointer_cast<CFunction>(globalFunction->getCFunction(this, CLoc::undefined, "mainLoop", globalScope, nullptr, CTM_Stack));
#ifdef VAR_OUTPUT
				currentFunction->dump(this, 0);
#endif

				if (errors.size() == 0) {
                    if (debugStream) {
                        map<shared_ptr<CBaseFunction>, string> functionDumps;
                        stringstream ss;
                        stringstream dotSS;
                        globalFunction->dumpBody(this, functionDumps, ss, 0, CTM_Stack);
                        
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
                        output.structs[structName].push_back("intptr_t _refCount");
                    }
                    output.structOrder.push_back("sjs_object");

                    globalFunction->transpileDefinition(this, &output);

                    auto hasMainLoop = false;
                    if (mainLoop) {
                        mainLoop->transpileDefinition(this, &output);
                        hasMainLoop = true;
                    }

                    if (errors.size() == 0) {
                        output.writeToStream(stream, hasMainLoop);
                    }
				}
			}
		}
	}

	if (errors.size() > 0) {
		for (auto it : errors)
		{
            for (auto it2 : it.second) {
                for (auto it3 : it2.second) {
                    it3.second.writeToStream(errorStream);
                    errorStream << "\n";
                }
            }
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

void Compiler::includeFile(const string& fileName) {
    assert(state == CompilerState::Define);
    
    if (includedBlockFileNames.find(fileName) == includedBlockFileNames.end()) {
        auto parseFile = genNodeFile(fileName);
        if (parseFile && parseFile->block) {
            includedBlockFileNames[fileName] = true;
            includedBlocks.push_back(pair<string, shared_ptr<NBlock>>(fileName, parseFile->block));
        }
    }
}
