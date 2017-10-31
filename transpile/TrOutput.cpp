#include "../compiler/Compiler.h"

void TrOutput::writeToStream(ostream& stream) {
    if (functions.size() > 0) {
        for (auto function : functions) {
            stream << function.second->definition << ";\n";
        }
        
        stream << "\n";
        
        for (auto function : functions) {
            stream << function.second->definition << " {\n";
            function.second->writeBodyToStream(stream);
            stream << "}\n";
            stream << "\n";
        }
    }

    stream << "int main() {\n";

	mainFunction.writeBodyToStream(stream);

	stream << "    return 0;\n";
	stream << "}\n";
}

