#pragma once

#include "TrVariable.h"
#include "TrStatement.h"

class CType;

enum ReturnValueRelease {
    RVR_MustRelease,
    RVR_MustRetain
};

class ReturnValue {
public:
    ReturnValue(shared_ptr<CType> type_, ReturnValueRelease releaseMode_) : type(type_), releaseMode(releaseMode_) {}

    shared_ptr<CType> type;
    ReturnValueRelease releaseMode;
}; 

class TrBlock {
public:
    TrBlock() : parent(nullptr) { }
    
    TrBlock* parent;
	bool hasThis;
    string definition;
    map<string, shared_ptr<TrVariable>> variables;
	vector<TrStatement> statements;
    string returnLine;
    shared_ptr<ReturnValue> returnValue;

	void writeBodyToStream(ostream& stream, int level);
    shared_ptr<TrVariable> getVariable(string name);
    shared_ptr<TrVariable> createVariable(string name, string type, TrReleaseMode releaseMode, string destroyFunctionName);
    shared_ptr<TrVariable> createTempVariable(string prefix, string type, TrReleaseMode releaseMode, string destroyFunctionName);
    
    static void addSpacing(ostream& stream, int level);
    static void resetVarNames();
private:
    static map<string, int> varNames;
};
