#pragma once

#include "TrVariable.h"
#include "TrStatement.h"

class Compiler;
class CScope;

enum AssignOp {
    ASSIGN_Mutable,
    ASSIGN_Immutable,
    ASSIGN_MutableCopy,
    ASSIGN_ImmutableCopy,
}; 

class CType;

class TrValue {
public:
    TrValue(shared_ptr<CScope> scope, shared_ptr<CType> type, string name) : scope(scope), type(type), name(name) { assert(type != nullptr);  }
    bool writeReleaseToStream(TrBlock* block, ostream& stream, int level);
    void addInitToStatements(TrBlock* block);
    void addRetainToStatements(TrBlock* block);
    void addReleaseToStatements(TrBlock* block);
    string getDotName(string rightName);
    string getPointerName();
    static string convertToLocalName(shared_ptr<CType> from, string name);

    shared_ptr<CScope> scope;
    shared_ptr<CType> type;
    string name;
}; 

class TrStoreValue {
public:
    TrStoreValue(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type, string name, AssignOp op, bool isFirstAssignment) : loc(loc), scope(scope), type(type), name(name), op(op), isFirstAssignment(isFirstAssignment), isReturnValue(false), hasSetValue(false), isVoid(false) {}
    TrStoreValue(CLoc loc, shared_ptr<CType> type, bool isVoid) : loc(loc), scope(nullptr), type(type), name(""), op(ASSIGN_Immutable), isFirstAssignment(true), isReturnValue(false), hasSetValue(false), isVoid(isVoid) {}
    void retainValue(Compiler* compiler, TrBlock* block, shared_ptr<TrValue> rightValue);
    void takeOverValue(Compiler* compiler, TrBlock* block, shared_ptr<TrValue> rightValue);
    string getName(TrBlock* block);
    shared_ptr<TrValue> getValue();

    CLoc loc;
    shared_ptr<CScope> scope;
    shared_ptr<CType> type;
    AssignOp op;
    bool isFirstAssignment;
    bool hasSetValue;
    bool isReturnValue;
    shared_ptr<TrValue> value;

private:
    string name;
    bool isVoid;
};

class TrBlock {
public:
    TrBlock() : parent(nullptr) { }
    
    TrBlock* parent;
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
