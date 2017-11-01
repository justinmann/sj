#include "../compiler/Compiler.h"

void TrOutput::writeToStream(ostream& stream) {
	if (structs.size() > 0) {
		for (auto t : structs) {
			stream << "typedef struct {\n";
			for (auto line : t.second) {
				stream << "    " << line << ";\n";
			}
            stream << "} " << t.first << ";\n";
			stream << "\n";
		}
	}

	if (functions.size() > 0) {
		for (auto function : functions) {
			stream << function.second->definition << ";\n";
		}

		stream << "\n";
	}
        
    for (auto function : functions) {
        stream << function.second->definition << " {\n";
        function.second->writeBodyToStream(stream, 1);
        stream << "}\n";
        stream << "\n";
    }

    stream << "int main() {\n";

	mainFunction.writeBodyToStream(stream, 1);

	stream << "    return 0;\n";
	stream << "}\n";
}

