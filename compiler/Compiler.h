//
//  Compiler.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef Compiler_h
#define Compiler_h

// #define YYDEBUG 1
// #define DWARF_ENABLED
// #define VAR_OUTPUT
// #define NODE_OUTPUT
// #define MODULE_OUTPUT
// #define ASSERT_ON_ERROR

#include "../sj.pch"

using namespace llvm;
using namespace std;

#include "CType.h"
#include "CVar.h"
#include "CFunction.h"

#pragma clang diagnostic ignored "-Wformat-security"

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

IRBuilder<> getEntryBuilder(IRBuilder<>* builder);

std::string Type_print(Type* type);

class NFunction;
class KaleidoscopeJIT;
class NBlock;
class NBase;
class NAssignment;

enum CResultType {
    RESULT_ERROR,
    RESULT_VOID,
    RESULT_INT,
    RESULT_BOOL,
    RESULT_FLOAT
};

enum CErrorCode {
    Internal,
    Parser,
    TypeMismatch,
    InvalidType,
    InvalidArgumentCount,
    InvalidCharacter,
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
    InvalidFunction
};

class CLoc {
public:
    const unsigned line;
    const unsigned col;
    
    CLoc(const unsigned line, const unsigned col) : line(line), col(col) {}
    static CLoc undefined;
};

class CError {
public:
    const CErrorCode code;
    const unsigned line;
    const unsigned col;
    const string msg;
    
    CError(const CLoc loc, const CErrorCode code): line(loc.line), col(loc.col), code(code) { }
    CError(const CLoc loc, const CErrorCode code, const string& msg): line(loc.line), col(loc.col), code(code), msg(msg) { }
};

class CResult {
public:
    CResultType type;
    union {
        int64_t iResult;
        bool bResult;
        double fResult;
    };
    
    vector<CError> errors;
    vector<CError> warnings;
    shared_ptr<NBlock> block;
    
    template< typename... Args >
    void addError(const CLoc loc, const CErrorCode code, const char* format, Args... args) {
        string str = strprintf(format, args...);
        errors.push_back(CError(loc, code, str));
        printf("ERROR: %s\n", str.c_str());
#ifdef ASSERT_ON_ERROR
        assert(false);
#endif
    }

    template< typename... Args >
    void addWarning(const CLoc loc, const CErrorCode code, const char* format, Args... args) {
        string str = strprintf(format, args...);
        warnings.push_back(CError(loc, code, str));
        printf("ERROR: %s\n", str.c_str());
    }
};

enum CompilerState {
    Define,
    FixVar,
    Compile
};

class Compiler
{
public:
    Compiler();
    ~Compiler();

    shared_ptr<CResult> run(const char* code);
    
    void emitLocation(const NBase *node);
    shared_ptr<CType> getType(const char* name) const;
    Value* getDefaultValue(shared_ptr<CType> type);
    
    // llvm vars
    CompilerState state;
    LLVMContext context;
    unique_ptr<Module> module;
    unique_ptr<KaleidoscopeJIT> TheJIT;
    unique_ptr<legacy::FunctionPassManager> TheFPM;
#ifdef DWARF_ENABLED
    DICompileUnit *TheCU;
    vector<DIScope *> LexicalBlocks;
    unique_ptr<DIBuilder> DBuilder;
#endif
    
    shared_ptr<CType> typeInt;
    shared_ptr<CType> typeFloat;
    shared_ptr<CType> typeBool;
    shared_ptr<CType> typeVoid;
    
private:
    shared_ptr<CResult> compile(const char* code);
    void InitializeModuleAndPassManager();
};

#endif /* Compiler_h */
