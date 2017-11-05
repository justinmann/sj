#pragma once

#include "TrVariable.h"
#include "TrStatement.h"

class CType;

enum ReturnValueRelease {
    RVR_MustRelease,
    RVR_MustRetain,
    RVR_Ignore
};

class ReturnValue {
public:
    ReturnValue(shared_ptr<CType> type_, bool isHeap_, ReturnValueRelease release_, string name_);
    ReturnValue(string typeName_, string name_);
    void writeReleaseToStream(ostream& stream, int level);
    static void addReleaseToStatements(TrBlock* block, string name, shared_ptr<CType> type);

    shared_ptr<CType> type;
    string typeName;
    bool isHeap;
    ReturnValueRelease release;
    string name;
}; 

class TrBlock {
public:
    TrBlock() : parent(nullptr) { }
    
    TrBlock* parent;
	bool hasThis;
    string definition;
    map<string, shared_ptr<ReturnValue>> variables;
	vector<TrStatement> statements;
    string returnLine;

	void writeBodyToStream(ostream& stream, int level);
    shared_ptr<ReturnValue> getVariable(string name);
    shared_ptr<ReturnValue> createVariable(string name, shared_ptr<CType> type, bool isHeap, ReturnValueRelease release);
    shared_ptr<ReturnValue> createTempVariable(string prefix, shared_ptr<CType> type, bool isHeap, ReturnValueRelease release);
    shared_ptr<ReturnValue> createTempVariable(string prefix, string typeName);

    static void addSpacing(ostream& stream, int level);
    static void resetVarNames();
private:
    static map<string, int> varNames;
};
