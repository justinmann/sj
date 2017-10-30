#include "../compiler/Compiler.h"

void TrOutput::writeToStream(ostream& stream, ostream& errorStream) {
	stream << "int main() {\n";

	mainFunction.writeBodyToStream(stream);

	stream << "    return 0;\n";
	stream << "}\n";

	for each (auto error in errors)
	{
		error.writeToStream(errorStream);
		errorStream << "\n";
	}
}

