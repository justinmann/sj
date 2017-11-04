#pragma once

#include "TrVariable.h"
#include "TrStatement.h"

class TrBlock {
public:
    TrBlock() : parent(nullptr) { }
    
    TrBlock* parent;
	bool hasThis;
    string definition;
    map<string, shared_ptr<TrVariable>> variables;
	vector<TrStatement> statements;
    string returnLine;

	void writeBodyToStream(ostream& stream, int level);
    shared_ptr<TrVariable> getVariable(string name);
    shared_ptr<TrVariable> createVariable(string name, string type, TrReleaseMode releaseMode, string destroyFunctionName);
    shared_ptr<TrVariable> createTempVariable(string prefix, string type, TrReleaseMode releaseMode, string destroyFunctionName);
    
    static void addSpacing(ostream& stream, int level);
    static void resetVarNames();
private:
    static map<string, int> varNames;
};
