#include "../compiler/Compiler.h"

TrOutput::TrOutput() {
    includes["<stdbool.h>"][""] = true;
    includes["<stdint.h>"][""] = true;
    includes["<stdlib.h>"][""] = true;
    includes["<stdio.h>"][""] = true;
#ifdef DEBUG_ALLOC
    includes["<assert.h>"][""] = true;
#endif
}

void TrOutput::writeToStream(ostream& stream, bool hasMainLoop) {
    for (auto ccodeInclude : ccodeIncludes) {
        stream << ccodeInclude << "\n";
    }

    for (auto include : includes) {
        for (auto ifdef : include.second) {
            if (ifdef.first.size() > 0) {
                stream << "#ifdef " << ifdef.first << "\n";
            }
            stream << "#include " << include.first << "\n";
            if (ifdef.first.size() > 0) {
                stream << "#endif\n";
            }
        }
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
    
    auto level = 0;
    for (auto line : ccodeStructs) {
        if (line.size() > 0) {
            auto firstChar = line.front();
            auto lastChar = line.back();
            if (firstChar == '}') {
                level--;
            }
            TrBlock::addSpacing(stream, level);
            stream << line;
            if (firstChar != '#' && lastChar == '{') {
                level++;
            }
        }
        stream << "\n";
    }

    if (structs.size() > 0) {
        int typeId = 1;
        for (auto t : structOrder) {
            stream << "#define " << t << "_typeId " << typeId++ << "\n";
        }
        stream << "\n";

        for (auto t : structOrder) {
            stream << "typedef struct td_" << t << " " << t << ";\n";
        }
        stream << "\n";

        for (auto t : structOrder) {
			stream << "struct td_" << t << " {\n";
			for (auto line : structs[t]) {
                if (line.size() == 0) {
                    continue;
                }
                stream << "    " << line;
                if (line.back() != ';') {
                    stream << ";";
                }
                stream << "\n";
			}
            stream << "};\n";
			stream << "\n";
		}
	}
    
    level = 0;
    for (auto line : ccodeDefines) {
        if (line.size() > 0) {
            auto firstChar = line.front();
            auto lastChar = line.back();
            if (firstChar == '}') {
                level--;
            }
            TrBlock::addSpacing(stream, level);
            stream << line;
            if (firstChar != '#' && lastChar == '{') {
                level++;
            }
        }
        stream << "\n";
    }
    
    shared_ptr<TrBlock> mainFunction = functions["sjf_global"];
    
    mainFunction->writeVariablesToStream(stream, 0);

    if (functions.size() > 0) {
		for (auto function : functions) {
            if (function.second == mainFunction) {
                continue;
            }
            stream << function.second->definition << ";\n";
		}
	}
        
    stream << "void main_destroy(void);\n";
    stream << "\n";

    level = 0;
    for (auto line : ccodeFunctions) {
        if (line.size() > 0) {
            auto firstChar = line.front();
            auto lastChar = line.back();
            if (firstChar == '}') {
                level--;
            }
            TrBlock::addSpacing(stream, level);
            stream << line;
            if (firstChar != '#' && lastChar == '{') {
                level++;
            }
        }
        stream << "\n";
    }

    for (auto function : functions) {
        if (function.second == mainFunction) {
            continue;
        }
        stream << function.second->definition << " {\n";
        function.second->writeToStream(stream, 1);
        stream << "}\n";
        stream << "\n";
    }

    stream << "int main(int argc, char** argv) {\n";
    mainFunction->writeBodyToStream(stream, 1);
    stream << "    main_destroy();\n";
    stream << "    return 0;\n";
    stream << "}\n";
    stream << "\n";
    stream << "void main_destroy() {\n";
    mainFunction->writeVariablesReleaseToStream(stream, 1);
    stream << "}\n";
}

