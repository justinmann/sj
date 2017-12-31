//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include <sjc.h>
#include "../node/Node.h"
#include <fstream>
#include <streambuf>
#include <iomanip>

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

Compiler::Compiler(bool outputLines, bool outputVSErrors, bool outputDebugLeaks, bool outputFree) : outputLines(outputLines), outputVSErrors(outputVSErrors), outputDebugLeaks(outputDebugLeaks), outputFree(outputFree) {
    auto ctypes = CType::create(emptyNamespace, "i32", "int32_t", "(int32_t)0", "int32_option", "int32_empty");
    typeI32 = ctypes->stackValueType;
    types["i32"] = ctypes;

    ctypes = CType::create(emptyNamespace, "i64", "int64_t", "(int64_t)0", "int64_option", "int64_empty");
    typeI64 = ctypes->stackValueType;
    types["i64"] = ctypes;

    ctypes = CType::create(emptyNamespace, "u32", "uint32_t", "(uint32_t)0", "uint32_option", "uint32_empty");
    typeU32 = ctypes->stackValueType;
    types["u32"] = ctypes;

    ctypes = CType::create(emptyNamespace, "u64", "uint64_t", "(uint64_t)0", "uint64_option", "uint64_empty");
    typeU64 = ctypes->stackValueType;
    types["u64"] = ctypes;

    ctypes = CType::create(emptyNamespace, "ptr", "void*", "(void*)0", "void_option", "void_empty");
    typePtr = ctypes->stackValueType;
    types["ptr"] = ctypes;

    ctypes = CType::create(emptyNamespace, "f32", "float", "0.0f", "float_option", "float_empty");
    typeF32 = ctypes->stackValueType;
    types["f32"] = ctypes;

    ctypes = CType::create(emptyNamespace, "f64", "double", "0.0", "double_option", "double_empty");
    typeF64 = ctypes->stackValueType;
    types["f64"] = ctypes;

    ctypes = CType::create(emptyNamespace, "bool", "bool", "false", "bool_option", "bool_empty");
    typeBool = ctypes->stackValueType;
    types["bool"] = ctypes;

    ctypes = CType::create(emptyNamespace, "char", "char", "'\0'", "char_option", "char_empty");
    typeChar = ctypes->stackValueType;
    types["char"] = ctypes;

    ctypes = CType::create(emptyNamespace, "void", "void", "", "", "");
    typeVoid = ctypes->stackValueType;
    types["void"] = ctypes;

    ctypes = CType::create(emptyNamespace, "type", "int32_t", "(int32_t)0", "int32_option", "int32_empty");
    typeType = ctypes->stackValueType;
    types["type"] = ctypes;
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

shared_ptr<CParseFile> Compiler::genNode(const string& fileName, const string& code) {
    auto parseFile = make_shared<CParseFile>();
    auto shortName = rootPath.empty() ? fs::path(fileName).generic_string() : fs::path(fileName).lexically_relative(rootPath).generic_string();
    parseFile->fullFileName = fileName;
    parseFile->shortFileName = shortName;
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

void CError::writeToStream(Compiler* compiler, ostream& stream) {
    if (compiler->outputVSErrors) {
        stream
            << fileName
            << "(" << line << "," << col << "): "
            << "error SJC" << setfill('0') << setw(4) << code
            << ": " << msg;
    }
    else {
        stream
            << fileName
            << ":" << line << ":" << col << ": "
            << "error: SJC" << setfill('0') << setw(4) << code
            << " " << msg;
    }
}

bool Compiler::transpile(const string& fileName, ostream& stream, ostream& errorStream, ostream* debugStream) {
    rootPath = fs::path(fileName).remove_filename();
    
    TrOutput output;
    auto templateTypes = vector<shared_ptr<CType>>();
    shared_ptr<CFunction> currentFunction;
    shared_ptr<CFunction> globalFunction;

    auto globalFile = genNodeFile(fileName);
    if (errors.size() == 0) {
        auto globalBlock = globalFile->block;
        globalBlock->statements.insert(globalBlock->statements.begin(), make_shared<NInclude>(CLoc(globalFile->fullFileName, globalFile->shortFileName, 1, 1), "lib/common/common.sj"));
        anonFunction = make_shared<NFunction>(CLoc::undefined, nullptr, "global", nullptr, nullptr, nullptr, nullptr, globalBlock, nullptr, nullptr, nullptr);
        currentFunctionDefintion = make_shared<CFunctionDefinition>();
        currentFunctionDefintion->init(this, importNamespaces, nullptr, packageNamespace, "", nullptr, nullptr);
        state = CompilerState::Define;
        anonFunction->initFunctions(this, importNamespaces, packageNamespace, currentFunctionDefintion);

        if (errors.size() == 0) {
            globalFunctionDefinition = currentFunctionDefintion->funcsByName[vector<string>()]["global"];

            NodeList includeStatements;
            for (auto index = (size_t)0; index < includedBlocks.size(); index++) {
                auto includedBlock = includedBlocks[index].second;
                includedBlock->initFunctions(this, importNamespaces, packageNamespace, globalFunctionDefinition);
                includeStatements.insert(includeStatements.end(), includedBlock->statements.begin(), includedBlock->statements.end());
            }
            globalBlock->statements.insert(globalBlock->statements.begin(), includeStatements.begin(), includeStatements.end());

            // Force global function to have void return
            globalBlock->statements.push_back(make_shared<NVoid>(CLoc::undefined));

            if (errors.size() == 0) {
                currentFunction = make_shared<CFunction>(importNamespaces, currentFunctionDefintion, templateTypes, weak_ptr<CFunction>(), nullptr, vector<shared_ptr<NCCode>>(), false, false);
                currentFunction->init(this, nullptr, CLoc::undefined);
                auto currentScope = currentFunction->getScope(this, CTM_Stack);
                globalFunction = static_pointer_cast<CFunction>(currentFunction->getCFunction(this, CLoc::undefined, "global", nullptr, nullptr, CTM_Stack));

                state = CompilerState::Compile;
                anonFunction->getVar(this, currentScope, nullptr, CTM_Stack);
                auto globalScope = globalFunction->getScope(this, CTM_Stack);
                auto mainLoop = static_pointer_cast<CFunction>(globalFunction->getCFunction(this, CLoc::undefined, "mainLoop", globalScope, nullptr, CTM_Stack));

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

                    globalFunction->transpileDefinition(this, &output);

                    auto hasMainLoop = false;
                    if (mainLoop) {
                        mainLoop->transpileDefinition(this, &output);
                        hasMainLoop = true;
                    }

                    auto returnMode = CTM_Stack;
                    string typeAsStringName = "sjf_type_asstring";
                    if (output.functions.find(typeAsStringName) != output.functions.end()) {
                        auto functionBlock = output.functions[typeAsStringName];
                        functionBlock->statements.clear();

                        auto calleeFunction = static_pointer_cast<CFunction>(globalFunction->getCFunction(this, CLoc::undefined, "type_asstring", nullptr, nullptr, returnMode));
                        auto calleeScope = calleeFunction->getScope(this, returnMode);

                        auto returnType = getType("sjs_string", false);
                        auto returnValue = functionBlock->createReturnStoreVariable(CLoc::undefined, nullptr, returnType);

                        functionBlock->statements.push_back(TrStatement(CLoc::undefined, "switch (t) {"));
                        for (auto type : types) {
                            auto ctype = type.second->localValueType;
                            functionBlock->statements.push_back(TrStatement(CLoc::undefined, "case " + to_string(ctype->typeId) + ":"));
                            auto str = make_shared<NString>(CLoc::undefined, ctype->shortName);
                            auto cvar = str->getVar(this, calleeScope, nullptr, nullptr, returnMode);
                            cvar->transpile(this, &output, functionBlock.get(), nullptr, returnValue);
                            functionBlock->statements.push_back(TrStatement(CLoc::undefined, "break;"));
                        }

                        functionBlock->statements.push_back(TrStatement(CLoc::undefined, "default:"));
                        auto str = make_shared<NString>(CLoc::undefined, "");
                        auto cvar = str->getVar(this, calleeScope, nullptr, nullptr, returnMode);
                        cvar->transpile(this, &output, functionBlock.get(), nullptr, returnValue);
                        functionBlock->statements.push_back(TrStatement(CLoc::undefined, "break;"));

                        functionBlock->statements.push_back(TrStatement(CLoc::undefined, "}"));

                        output.functions[typeAsStringName] = functionBlock;
                    }

                    if (errors.size() == 0) {
                        output.writeToStream(this, stream, hasMainLoop);
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
                    it3.second.writeToStream(this, errorStream);
                    errorStream << "\n";
                }
            }
        }
        return false;
    }
    return true;
}

shared_ptr<CType> Compiler::getType(const string& name, bool isOption) const {
    auto t = types.find(name);
    if (t != types.end()) {
        return isOption ? t->second->stackOptionType : t->second->stackValueType;
    }
    return nullptr;
}

void Compiler::includeFile(const string& fileName) {
    assert(state == CompilerState::Define);
    
    if (includedBlockFileNames.find(fileName) == includedBlockFileNames.end()) {
        auto parseFile = genNodeFile(fileName);
        if (parseFile && parseFile->block) {
            includedBlockFileNames[fileName] = true;

            globalFunctionDefinition = currentFunctionDefintion->funcsByName[vector<string>()]["global"];
            parseFile->block->initFunctions(this, importNamespaces, packageNamespace, globalFunctionDefinition);

            includedBlocks.push_back(pair<string, shared_ptr<NBlock>>(fileName, parseFile->block));
        }
    }
}
