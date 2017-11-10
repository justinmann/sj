#include "../compiler/Compiler.h"

TrOutput::TrOutput() {
    includes["<stdbool.h>"] = true;
    includes["<stdint.h>"] = true;
    includes["<stdlib.h>"] = true;
}

void TrOutput::writeToStream(ostream& stream) {
    for (auto include : includes) {
        stream << "#include " << include.first << "\n";
    }
    stream << "\n";
    
    if (strings.size() > 0) {
        for (auto t : strings) {
            stream << "const char* " << t.first << " = \"" << t.second << "\";\n";
        }
        stream << "\n";
    }
    
	if (structs.size() > 0) {
        for (auto t : structs) {
            stream << "typedef struct td_" << t.first << " " << t.first << ";\n";
        }
        stream << "\n";

        int typeId = 1;
        for (auto t : structs) {
            stream << "int " << t.first << "_typeId = " << typeId++ << ";\n";
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

    stream << "\n";
	stream << "    return 0;\n";
	stream << "}\n";
}

