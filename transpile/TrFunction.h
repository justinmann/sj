#pragma once

#include "TrVariable.h"

class TrFunction {
public:
	std::vector<TrVariable> variables;
	std::vector<string> statements;

	void writeBodyToStream(ostream& stream);
};
