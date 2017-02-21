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

using namespace llvm;
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

#include "CType.h"
#include "CTypeName.h"
#include "CVar.h"
#include "CArrayType.h"
#include "Exception.h"

#pragma clang diagnostic ignored "-Wformat-security"

#define STACK_REF_COUNT         1000000000000

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

Function* getFunctionFromBuilder(IRBuilder<>* builder);

std::string Type_print(Type* type);

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
    InterfaceMethodTypeMismatch
};

class CError {
public:
    const CErrorCode code;
    shared_ptr<string> fileName;
    const unsigned line;
    const unsigned col;
    const string msg;
    
    CError(const CLoc& loc, const CErrorCode code): fileName(loc.fileName), line(loc.line), col(loc.col), code(code) { }
    CError(const CLoc& loc, const CErrorCode code, const string& msg): fileName(loc.fileName), line(loc.line), col(loc.col), code(code), msg(msg) { }
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
    
    template< typename... Args >
    void addError(const CLoc& loc, const CErrorCode code, const char* format, Args... args) {
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
    void addWarning(const CLoc& loc, const CErrorCode code, const char* format, Args... args) {
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
    ~Compiler();

    shared_ptr<CResult> run(const string& code);
    
    void emitLocation(IRBuilder<>* builder, const NBase *node);
    shared_ptr<CType> getType(const string& name) const;
    void includeFile(CResult& result, const string& fileName);
    shared_ptr<IRBuilder<>> getEntryBuilder(Function* function);
    Function* getAllocFunction();
    Function* getReallocFunction();
    Function* getFreeFunction();
    void callPushFunction(IRBuilder<>* builder, const string& name);
    void callPopFunction(IRBuilder<>* builder);
    void callDebug(IRBuilder<>* builder, const string& name, Value* valuePtr, Value* valueInt);
    void recordRetain(IRBuilder<>* builder, Value* value, const string& name);
    void recordRelease(IRBuilder<>* builder, Value* value, const string& name);
    shared_ptr<CInterfaceDefinition> getInterfaceDefinition(string& name);

    // llvm vars
    CompilerState state;
    LLVMContext context;
    unique_ptr<Module> module;
    unique_ptr<KaleidoscopeJIT> TheJIT;
    unique_ptr<legacy::FunctionPassManager> TheFPM;
    unique_ptr<Exception> exception;
#ifdef DWARF_ENABLED
    DICompileUnit *TheCU;
    vector<DIScope *> LexicalBlocks;
    unique_ptr<DIBuilder> DBuilder;
#endif
    
    shared_ptr<CType> typeInt;
    shared_ptr<CType> typeFloat;
    shared_ptr<CType> typeBool;
    shared_ptr<CType> typeChar;
    shared_ptr<CType> typeVoid;
    
private:
    shared_ptr<CResult> compileFile(const string& fileName);
    shared_ptr<CResult> compile(const string& fileName, const string& code);
    void InitializeModuleAndPassManager();
    
    map<string, bool> includedBlockFileNames;
    vector<pair<string, shared_ptr<NBlock>>> includedBlocks;
    map<string, GlobalValue*> functionNames;
    map<Function*, shared_ptr<IRBuilder<>>> entryBuilders;
    map<string, shared_ptr<CInterfaceDefinition>> interfaceDefinitions;
    Function* allocFunction;
    Function* reallocFunction;
    Function* freeFunction;
    Function* debugFunction;
#ifdef DEBUG_CALLSTACK
    Function* pushFunction;
    Function* popFunction;
    Function* recordRetainFunction;
    Function* recordReleaseFunction;
#endif
};

#endif /* Compiler_h */
