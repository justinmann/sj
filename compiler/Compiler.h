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

class CLoc {
public:
    shared_ptr<string> fileName;
    unsigned line;
    unsigned col;
    
    CLoc() : fileName(nullptr), line(0), col(0) {}
    CLoc(shared_ptr<string> fileName, const unsigned line, const unsigned col) : fileName(fileName), line(line), col(col) {}
    static CLoc undefined;
};

#include "../transpile/TrOutput.h"
#include "CType.h"
#include "CTypeName.h"
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

// Function* getFunctionFromBuilder(IRBuilder<>* builder);

// std::string Type_print(Type* type);

class NFunction;
class KaleidoscopeJIT;
class NBlock;
class NBase;
class NAssignment;
class CInterfaceDefinition;

enum CResultType {
    RESULT_ERROR,
    RESULT_VOID,
    RESULT_INT,
    RESULT_BOOL,
    RESULT_CHAR,
    RESULT_FLOAT,
    RESULT_STR
};

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
    const CErrorCode code;
    shared_ptr<string> fileName;
    const unsigned line;
    const unsigned col;
    const string msg;
    
    CError(CLoc& loc, const CErrorCode code): code(code), fileName(loc.fileName), line(loc.line), col(loc.col) { }
    CError(CLoc& loc, const CErrorCode code, const string& msg): code(code), fileName(loc.fileName), line(loc.line), col(loc.col), msg(msg) { }
	void writeToStream(ostream& stream);
};

class CResult {
public:
    CResultType type;
    union {
        int64_t iResult;
        bool bResult;
        double fResult;
        char cResult;
    };
    string strResult;
    
    vector<CError> errors;
    vector<CError> warnings;
    shared_ptr<string> fileName;
    shared_ptr<NBlock> block;
    shared_ptr<CType> returnType;
    
    template< typename... Args >
    void addError(CLoc& loc, const CErrorCode code, const char* format, Args... args) {
        string str = strprintf(format, args...);
#ifdef ERROR_OUTPUT
        printf("ERROR: %d:%d %s\n", loc.line, loc.col, str.c_str());
#endif
        errors.push_back(CError(loc, code, str));
#ifdef ASSERT_ON_ERROR
        assert(false);
#endif
    }

    template< typename... Args >
    void addWarning(CLoc& loc, const CErrorCode code, const char* format, Args... args) {
        string str = strprintf(format, args...);
        warnings.push_back(CError(loc, code, str));
#ifdef ERROR_OUTPUT
        printf("WARN: %d:%d %s\n", loc.line, loc.col, str.c_str());
#endif
    }
};

enum CompilerState {
    Define,
    FixVar,
    Compile
};

class SJException : public exception { };

class Compiler
{
public:
    Compiler();
	bool transpile(const string& fileName, ostream& stream, ostream& errorStream, ostream* debugStream);
    shared_ptr<CType> getType(const string& name) const;
    void includeFile(CResult& result, const string& fileName);

    CompilerState state;    
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
    shared_ptr<CType> typeI32Option;
    shared_ptr<CType> typeI64Option;
    shared_ptr<CType> typeU32Option;
    shared_ptr<CType> typeU64Option;
    shared_ptr<CType> typePtrOption;
    shared_ptr<CType> typeF32Option;
    shared_ptr<CType> typeF64Option;
    shared_ptr<CType> typeBoolOption;
    shared_ptr<CType> typeCharOption;
    map<string, shared_ptr<CTypes>> types;

private:
    void reset();
    shared_ptr<CResult> genNodeFile(const string& fileName);
    shared_ptr<CResult> genNode(const string& fileName, const string& code);    
    map<string, bool> includedBlockFileNames;
    vector<pair<string, shared_ptr<NBlock>>> includedBlocks;
};

#endif /* Compiler_h */
