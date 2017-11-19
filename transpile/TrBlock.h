#pragma once

#include "TrVariable.h"
#include "TrStatement.h"

class CType;

class ReturnValue {
public:
    ReturnValue(shared_ptr<CType> type, string name);
    bool writeReleaseToStream(TrBlock* block, ostream& stream, int level);
    void addInitToStatements(TrBlock* block);
    void addAssignToStatements(TrBlock* block, string rightName, bool isFirstAssignment);
    void addCopyToStatements(TrBlock* block, string rightName);
    void addRetainToStatements(TrBlock* block);
    void addReleaseToStatements(TrBlock* block);

    shared_ptr<CType> type;
    string typeName;
    string name;
}; 

class TrBlock {
public:
    TrBlock() : parent(nullptr) { }
    
    TrBlock* parent;
	bool hasThis;
    string definition;
    map<string, shared_ptr<ReturnValue>> variables;
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
    shared_ptr<ReturnValue> getVariable(string name);
    shared_ptr<ReturnValue> createVariable(shared_ptr<CType> type, string name);
    shared_ptr<ReturnValue> createTempVariable(shared_ptr<CType> type, string prefix);
    string createStackValue(string prefix, shared_ptr<CType> type);
    string getFunctionName();

    static void addSpacing(ostream& stream, int level);
    static void resetVarNames();
    static string nextVarName(string prefix);
private:
    static map<string, int> varNames;
};
