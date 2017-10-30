#include "../compiler/Compiler.h"

void TrFunction::writeBodyToStream(ostream& stream) {
	for each (auto variable in variables)
	{
		stream << "    " << variable.second << " " << variable.first << ";\n";
	}

	for each (auto statement in statements)
	{		
		stream << "    " << statement << ";\n";
	}
}
