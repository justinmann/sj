#pragma once

#include "TrFunction.h"

class TrOutput {
public:
	map<string, shared_ptr<TrFunction>> functions;
	map<string, vector<string>> structs;
	TrFunction mainFunction;

	void writeToStream(ostream& stream);
};
