#pragma once

#include "TrFunction.h"

class TrOutput {
public:
	map<string, shared_ptr<TrFunction>> functions;
	TrFunction mainFunction;

	void writeToStream(ostream& stream);
};
