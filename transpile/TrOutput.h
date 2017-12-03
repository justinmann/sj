#pragma once

#include "TrBlock.h"

class TrOutput {
public:
	map<string, shared_ptr<TrBlock>> functions;
	map<string, vector<string>> structs;
    vector<string> structOrder;
    map<string, string> strings;
    map<string, map<string, bool>> includes;
    vector<string> ccodeIncludes;
    vector<string> ccodeStructs;
    vector<string> ccodeDefines;
    vector<string> ccodeTypedefs;
    vector<string> ccodeFunctions;

    TrOutput();
	void writeToStream(ostream& stream, bool hasMainLoop);
};
