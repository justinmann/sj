#include "../compiler/Compiler.h"

void TrFunction::writeBodyToStream(ostream& stream) {
	for each (auto statement in statements)
	{
		stream << "    " << statement << ";\n";
	}
}
