#pragma once

#include "TrBlock.h"

class TrOutput {
public:
	map<string, shared_ptr<TrBlock>> functions;
	map<string, vector<string>> structs;
    map<string, string> strings;
    map<string, bool> includes;
	TrBlock mainFunction;

    TrOutput();
	void writeToStream(ostream& stream);
};
