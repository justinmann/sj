//
//  Compiler.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef Compiler_h
#define Compiler_h

#include "../sj.pch"

// #define YYDEBUG 1
// #define DWARF_ENABLED
// #define VAR_OUTPUT
// #define NODE_OUTPUT
// #define MODULE_OUTPUT
// #define ASSERT_ON_ERROR
// #define ERROR_OUTPUT
// #define SYMBOL_OUTPUT
// #define EXCEPTION_OUTPUT
// #define DEBUG_CALLSTACK
// #define DEBUG_ALLOC
#define YY_NO_UNISTD_H

using namespace std;
namespace fs = boost::filesystem;

class CLoc {
public:
    string fullFileName;
    string shortFileName;
    unsigned line;
    unsigned col;
    
    CLoc() : fullFileName(""), shortFileName(""), line(0), col(0) {}
    CLoc(string fullFileName, string shortFileName, const unsigned line, const unsigned col) : fullFileName(fullFileName), shortFileName(shortFileName), line(line), col(col) {}
    static CLoc undefined;
};

#include "CType.h"
#include "CTypeName.h"
#include "../transpile/TrOutput.h"
#include "CVar.h"
#include "Exception.h"

#define STACK_REF_COUNT         1000000000000

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wformat-security"
#endif

template< typename... Args >
std::string strprintf( const char* format, Args... args ) {

    int length = std::snprintf( nullptr, 0, format, args... );
    assert( length >= 0 );
    
    char* buf = new char[length + 1];
    std::snprintf( buf, length + 1, format, args... );
    
    std::string str( buf );
    delete[] buf;
    return str;
}

class NFunction;
class NBlock;
class NBase;
class NAssignment;
class CInterfaceDefinition;
class CFunctionDefinition;

enum CErrorCode {
    Internal,
    Parser,
    TypeMismatch,
    IncludeOnlyInGlobal,
    InvalidType,
    InvalidArgumentCount,
    InvalidCharacter,
    InvalidVariable,
    InvalidDot,
    InvalidString,
    InvalidTemplateArg,
    UnknownFunction,
    UnknownVariable,
    ImmutableAssignment,
    ExpressionEmpty,
    NotVariable,
    TypeLoop,
    InvalidCast,
    NoDefaultValue,
    InvalidNumber,
    ParameterByIndexAfterByName,
    ParameterRedefined,
    ParameterDoesNotExist,
    ParameterRequired,
    TooManyParameters,
    InvalidFunction,
    StoringVoid,
    TemplateUnspecified,
    InterfaceDoesNotExist,
    InterfaceMethodDoesNotExist,
    InterfaceMethodTypeMismatch,
    InterfaceMethodConflict,
    InvalidMacro
};

class CError {
public:
    CErrorCode code;
    string fileName;
    unsigned line;
    unsigned col;
    string msg;
    
    void writeToStream(ostream& stream);
};

enum CompilerState {
    Define,
    Compile
};

class CParseFile {
public:
    Compiler* compiler;
    string fullFileName;
    string shortFileName;
    shared_ptr<NBlock> block;
};

class SJException : public exception { };

class Compiler
{
public:
    Compiler(bool outputLines, bool outputVSErrors);
    bool transpile(const string& fileName, ostream& stream, ostream& errorStream, ostream* debugStream);
    shared_ptr<CType> getType(const string& name, bool isOption) const;
    void includeFile(const string& fileName);

    template< typename... Args >
    void addError(CLoc loc, const CErrorCode code, const char* format, Args... args) {
        string str = strprintf(format, args...);
#ifdef ERROR_OUTPUT
        printf("ERROR: %d:%d %s\n", loc.line, loc.col, str.c_str());
#endif
        errors[loc.fullFileName][loc.line][str].code = code;
        errors[loc.fullFileName][loc.line][str].fileName = outputVSErrors ? fs::path(loc.fullFileName).string() : loc.shortFileName;
        errors[loc.fullFileName][loc.line][str].line = loc.line;
        errors[loc.fullFileName][loc.line][str].col = loc.col;
        errors[loc.fullFileName][loc.line][str].msg = str;
        
#ifdef ASSERT_ON_ERROR
        assert(false);
#endif
    }
    
    template< typename... Args >
    void addWarning(CLoc loc, const CErrorCode code, const char* format, Args... args) {
        string str = strprintf(format, args...);

        warnings[loc.fullFileName][loc.line][str].code = code;
        warnings[loc.fullFileName][loc.line][str].fileName = outputVSErrors ? fs::path(loc.fullFileName).string() : loc.shortFileName;
        warnings[loc.fullFileName][loc.line][str].line = loc.line;
        warnings[loc.fullFileName][loc.line][str].col = loc.col;
        warnings[loc.fullFileName][loc.line][str].msg = str;

#ifdef ERROR_OUTPUT
        printf("WARN: %d:%d %s\n", loc.line, loc.col, str.c_str());
#endif
    }
    
    bool outputLines;
    bool outputVSErrors;
    boost::filesystem::path rootPath;
    CompilerState state;
    map<string, map<unsigned, map<string, CError>>> errors;
    map<string, map<unsigned, map<string, CError>>> warnings;
    shared_ptr<CType> typeI32;
    shared_ptr<CType> typeI64;
    shared_ptr<CType> typeU32;
    shared_ptr<CType> typeU64;
    shared_ptr<CType> typePtr;
    shared_ptr<CType> typeF32;
    shared_ptr<CType> typeF64;
    shared_ptr<CType> typeBool;
    shared_ptr<CType> typeChar;
    shared_ptr<CType> typeVoid;
    map<string, shared_ptr<CTypes>> types;
    map<vector<string>, bool> namespaces;

private:
    shared_ptr<CParseFile> genNodeFile(const string& fileName);
    shared_ptr<CParseFile> genNode(const string& fileName, const string& code);
    
    map<string, bool> includedBlockFileNames;
    vector<pair<string, shared_ptr<NBlock>>> includedBlocks;

    shared_ptr<NBlock> globalBlock;
    vector<pair<string, vector<string>>> importNamespaces;
    vector<string> packageNamespace;
    shared_ptr<CFunctionDefinition> globalFunctionDefinition;
    shared_ptr<NFunction> anonFunction;
    shared_ptr<CFunctionDefinition> currentFunctionDefintion;
};

#endif /* Compiler_h */
