#pragma once

#include "TrVariable.h"

class TrFunction {
public:
    string definition;
	map<string, string> variables;
	vector<string> statements;

	void writeBodyToStream(ostream& stream);
    string createLocalVariable(string prefix, string type);
};
