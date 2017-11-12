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

    
    stream << "typedef struct td_int32_option int32_option;\n";
    stream << "struct td_int32_option {\n";
    stream << "    bool isEmpty;\n";
    stream << "    int32_t value;\n";
    stream << "};\n";
    stream << "const int32_option int32_empty = { true };\n";
    stream << "\n";

    stream << "typedef struct td_uint32_option uint32_option;\n";
    stream << "struct td_uint32_option {\n";
    stream << "    bool isEmpty;\n";
    stream << "    uint32_t value;\n";
    stream << "};\n";
    stream << "const uint32_option uint32_empty = { true };\n";
    stream << "\n";

    stream << "typedef struct td_int64_option int64_option;\n";
    stream << "struct td_int64_option {\n";
    stream << "    bool isEmpty;\n";
    stream << "    int64_t value;\n";
    stream << "};\n";
    stream << "const int64_option int64_empty = { true };\n";
    stream << "\n";

    stream << "typedef struct td_uint64_option uint64_option;\n";
    stream << "struct td_uint64_option {\n";
    stream << "    bool isEmpty;\n";
    stream << "    uint64_t value;\n";
    stream << "};\n";
    stream << "const uint64_option uint64_empty = { true };\n";
    stream << "\n";

    stream << "typedef struct td_uintptr_option uintptr_option;\n";
    stream << "struct td_uintptr_option {\n";
    stream << "    bool isEmpty;\n";
    stream << "    uintptr_t value;\n";
    stream << "};\n";
    stream << "const uintptr_option uintptr_empty = { true };\n";
    stream << "\n";

    stream << "typedef struct td_char_option char_option;\n";
    stream << "struct td_char_option {\n";
    stream << "    bool isEmpty;\n";
    stream << "    char value;\n";
    stream << "};\n";
    stream << "const char_option char_empty = { true };\n";
    stream << "\n";

    stream << "typedef struct td_float_option float_option;\n";
    stream << "struct td_float_option {\n";
    stream << "    bool isEmpty;\n";
    stream << "    float value;\n";
    stream << "};\n";
    stream << "const float_option float_empty = { true };\n";
    stream << "\n";

    stream << "typedef struct td_double_option double_option;\n";
    stream << "struct td_double_option {\n";
    stream << "    bool isEmpty;\n";
    stream << "    double value;\n";
    stream << "};\n";
    stream << "const double_option double_empty = { true };\n";
    stream << "\n";

    if (strings.size() > 0) {
        for (auto t : strings) {
            stream << "const char* " << t.first << " = \"" << t.second << "\";\n";
        }
        stream << "\n";
    }
    
	if (structs.size() > 0) {
        int typeId = 1;
        for (auto t : structs) {
            stream << "#define " << t.first << "_typeId " << typeId++ << "\n";
        }
        stream << "\n";

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

    stream << "\n";
	stream << "    return 0;\n";
	stream << "}\n";
}

