#pragma once

#include "TrVariable.h"
#include "TrStatement.h"

class Compiler;
class CResult;

enum AssignOp {
    ASSIGN_Mutable,
    ASSIGN_Immutable,
    ASSIGN_MutableCopy,
    ASSIGN_ImmutableCopy,
}; 

class CType;

class TrValue {
public:
    TrValue(shared_ptr<CType> type, string name);
    bool writeReleaseToStream(TrBlock* block, ostream& stream, int level);
    void addInitToStatements(TrBlock* block);
    void addRetainToStatements(TrBlock* block);
    void addReleaseToStatements(TrBlock* block);
    string getDotName(string rightName);
    string getPointerName();
    static string convertToLocalName(shared_ptr<CType> from, string name);

    shared_ptr<CType> type;
    string typeName;
    string name;
}; 

class TrStoreValue {
public:
    TrStoreValue(shared_ptr<CType> type, string name, AssignOp op, bool isFirstAssignment) : type(type), name(name), op(op), isFirstAssignment(isFirstAssignment), hasSetValue(false) {}
    void setValue(Compiler* compiler, CResult& result, CLoc& loc, TrBlock* block, shared_ptr<TrValue> rightValue);
    shared_ptr<TrValue> getValue();
    string getDotName(string rightName);
    string getPointerName();

    shared_ptr<CType> type;
    string name;
    AssignOp op;
    bool isFirstAssignment;
    bool hasSetValue;
};

class TrBlock {
public:
    TrBlock() : parent(nullptr) { }
    
    TrBlock* parent;
	bool hasThis;
    string definition;
    map<string, shared_ptr<TrValue>> variables;
    map<string, shared_ptr<CType>> stackValues;
	vector<TrStatement> statements;
    string returnLine;

    void writeToStream(ostream& stream, int level);
    void writeStackValuesToStream(ostream& stream, int level);
    void writeVariablesToStream(ostream& stream, int level);
    void writeBodyToStream(ostream& stream, int level);
    void writeVariablesReleaseToStream(ostream& stream, int level);
    void writeStackValuesReleaseToStream(ostream& stream, int level);
    void writeReturnToStream(ostream& stream, int level);
    shared_ptr<TrValue> getVariable(string name);
    shared_ptr<TrValue> createVariable(shared_ptr<CType> type, string name);
    shared_ptr<TrValue> createTempVariable(shared_ptr<CType> type, string prefix);
    shared_ptr<TrStoreValue> createTempStoreVariable(shared_ptr<CType> type, string prefix);
    shared_ptr<TrStoreValue> createVoidStoreVariable();
    shared_ptr<TrStoreValue> createReturnStoreVariable(shared_ptr<CType> type);
    string createStackValue(string prefix, shared_ptr<CType> type);
    string getFunctionName();

    static void addSpacing(ostream& stream, int level);
    static void resetVarNames();
    static string nextVarName(string prefix);
private:
    static map<string, int> varNames;
};
