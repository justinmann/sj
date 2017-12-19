#pragma once

#include "TrBlock.h"

class TrVtbl {
public:
    string ctype;
    vector<pair<string, string>> functions;
};

class TrOutput {
public:
	map<string, shared_ptr<TrBlock>> functions;
	map<string, vector<string>> structs;
    map<string, shared_ptr<TrVtbl>> vtbls;
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
