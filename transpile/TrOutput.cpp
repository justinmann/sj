#include "../compiler/Compiler.h"

void TrOutput::writeToStream(ostream& stream) {
    stream << "#include <stdio.h>\n";
    stream << "#include <stdlib.h>\n";
    stream << "#include <stdbool.h>\n";
    stream << "\n";
    
	if (structs.size() > 0) {
        for (auto t : structs) {
            stream << "typedef struct td_" << t.first << " " << t.first << ";\n";
        }
        stream << "\n";

        for (auto t : structs) {
			stream << "struct td_" << t.first << " {\n";
			for (auto line : t.second) {
				stream << "    " << line << ";\n";
			}
            stream << "};\n";
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

