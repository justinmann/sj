#pragma once

#include "TrFunction.h"

class TrOutput {
public:
	map<string, shared_ptr<TrFunction>> functions;
	TrFunction mainFunction;
	shared_ptr<vector<CError>> errors;

	void writeToStream(ostream& stream);
};
