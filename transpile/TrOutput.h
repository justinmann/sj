#pragma once

#include "TrFunction.h"

class TrOutput {
public:
	map<string, shared_ptr<TrFunction>> functions;
	TrFunction mainFunction;
	vector<CError> errors;

	void writeToStream(ostream& stream, ostream& errorStream);
};
