#pragma once

#include "TrBlock.h"

class TrOutput {
public:
	map<string, shared_ptr<TrBlock>> functions;
	map<string, vector<string>> structs;
    map<string, string> strings;
	TrBlock mainFunction;

	void writeToStream(ostream& stream);
};
