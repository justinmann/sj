#pragma once

#include "TrVariable.h"

class TrFunction {
public:
	std::map<string, string> variables;
	std::vector<string> statements;

	void writeBodyToStream(ostream& stream);
    string createLocalVariable(string prefix, string type);
};
