#pragma once

#include "TrVariable.h"
#include "TrStatement.h"

class Compiler;
class CScope;
class CType;
class AssignOp;

class TrValue {
public:
    TrValue(shared_ptr<CScope> scope, shared_ptr<CType> type, string name, bool isReturnValue) : scope(scope), type(type), name(name), isReturnValue(isReturnValue) { assert(type != nullptr);  }
    void writeReleaseToStream(ostream& stream, int level);
    void addInitToStatements(TrBlock* block);
    void addRetainToStatements(TrBlock* block);
    void addReleaseToStatements(TrBlock* block);
    string getDotName(string rightName);
    string getPointerName();
    static string convertToLocalName(CTypeMode typeMode, string name, bool isReturnValue);
    static string convertToLocalName(shared_ptr<CType> from, string name, bool isReturnValue);

    shared_ptr<CScope> scope;
    shared_ptr<CType> type;
    string name;
    bool isReturnValue;
}; 

class TrStoreValue {
public:
    TrStoreValue(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type, string name, AssignOp op) : loc(loc), scope(scope), type(type), name(name), op(op), isReturnValue(false), hasSetValue(false), isVoid(false), isObjectCast(false) {}
    TrStoreValue(CLoc loc, shared_ptr<CType> type, bool isVoid) : loc(loc), scope(nullptr), type(type), name(""), op(AssignOp::immutableCreate), isReturnValue(false), hasSetValue(false), isVoid(isVoid), isObjectCast(false) {}
    void retainValue(Compiler* compiler, CLoc loc, TrBlock* block, shared_ptr<TrValue> rightValue);
    string getName(TrBlock* block);
    shared_ptr<TrValue> getValue();

    CLoc loc;
    shared_ptr<CScope> scope;
    shared_ptr<CType> type;
    AssignOp op;
    bool hasSetValue;
    bool isReturnValue;
    shared_ptr<TrValue> value;
    bool isVoid;
    bool isObjectCast;

private:
    string name;
};

class TrBlock {
public:
    TrBlock() : localVarParent(nullptr) { }
    
    TrBlock* localVarParent;
	bool hasThis;
    string definition;
    map<string, shared_ptr<TrValue>> variables;
	vector<TrStatement> statements;
    string returnLine;

    void writeToStream(ostream& stream, int level);
    void writeVariablesToStream(ostream& stream, int level);
    void writeBodyToStream(ostream& stream, int level);
    void writeVariablesReleaseToStream(ostream& stream, int level);
    void writeReturnToStream(ostream& stream, int level);
    shared_ptr<TrValue> getVariable(string name);
    shared_ptr<TrValue> createVariable(shared_ptr<CScope> scope, shared_ptr<CType> type, string name);
    shared_ptr<TrValue> createTempVariable(shared_ptr<CScope> scope, shared_ptr<CType> type, string prefix);
    shared_ptr<TrStoreValue> createTempStoreVariable(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type, string prefix);
    shared_ptr<TrStoreValue> createVoidStoreVariable(CLoc loc, shared_ptr<CType> type);
    shared_ptr<TrStoreValue> createReturnStoreVariable(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type);
    string getFunctionName();

    static void addSpacing(ostream& stream, int level);
    static void resetVarNames();
    static string nextVarName(string prefix);
private:
    static map<string, int> varNames;
};
