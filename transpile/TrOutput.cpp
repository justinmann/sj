#include "../compiler/Compiler.h"

void TrOutput::writeToStream(ostream& stream) {
	stream << "int main() {\n";

	mainFunction.writeBodyToStream(stream);

	stream << "    return 0;\n";
	stream << "}\n";
}

