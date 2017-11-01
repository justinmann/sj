#pragma once

#include "TrVariable.h"
#include "TrStatement.h"

class TrBlock {
public:
    TrBlock() : parent(nullptr) { }
    
    TrBlock* parent;
    string definition;
    map<string, shared_ptr<TrVariable>> variables;
	vector<TrStatement> statements;

	void writeBodyToStream(ostream& stream, int level);
    shared_ptr<TrVariable> getVariable(string name);
    shared_ptr<TrVariable> createVariable(string name, string type);
    shared_ptr<TrVariable> createTempVariable(string prefix, string type);
    
    static void resetVarNames();
private:
    static map<string, int> varNames;
};
