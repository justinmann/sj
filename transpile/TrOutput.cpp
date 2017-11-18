#include "../compiler/Compiler.h"

TrOutput::TrOutput() {
    includes["<stdbool.h>"] = true;
    includes["<stdint.h>"] = true;
    includes["<stdlib.h>"] = true;
    includes["<stdio.h>"] = true;
#ifdef DEBUG_ALLOC
    includes["<assert.h>"] = true;
#endif
}

void TrOutput::writeToStream(ostream& stream, bool hasMainLoop) {
    if (hasMainLoop) {
        includes["<emscripten.h>"] = true;
    }

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
    
    for (auto ccodeDefine : ccodeDefines) {
        stream << ccodeDefine << "\n";
    }
    
    auto hasGlobalStruct = structs.find("sjs_global") != structs.end();
    shared_ptr<TrBlock> mainFunction = functions["sjf_global"];
    
    if (functions.size() > 0) {
		for (auto function : functions) {
            if (function.second == mainFunction) {
                continue;
            }
            stream << function.second->definition << ";\n";
		}

		stream << "\n";
	}
        
    if (hasGlobalStruct) {
        stream << "sjs_global global;\n";
    }
    assert(mainFunction != nullptr);
    mainFunction->writeStackValuesToStream(stream, 0);
    stream << "\n";
    
    for (auto ccodeFunction : ccodeFunctions) {
        stream << ccodeFunction << "\n";
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

    stream << "int main() {\n";
    if (hasGlobalStruct) {
        stream << "    global._refCount = 1;\n";
        stream << "    sjs_global* _this = &global;\n";
    }
    mainFunction->writeVariablesToStream(stream, 1);
    mainFunction->writeBodyToStream(stream, 1);
    mainFunction->writeVariablesReleaseToStream(stream, 1);
    if (!hasMainLoop) {
        mainFunction->writeStackValuesReleaseToStream(stream, 1);
        if (hasGlobalStruct) {
            stream << "    sjf_global_destroy(&global);\n";
        }
    }
    else {
        stream << "    emscripten_set_main_loop_arg((em_arg_callback_func)sjf_mainLoop, &global, 0, 0);\n";
    }
    stream << "    return 0;\n";
    stream << "}\n";

    if (hasMainLoop) {
        stream << "void main_destroy() {\n";
        mainFunction->writeStackValuesReleaseToStream(stream, 1);
        if (hasGlobalStruct) {
            stream << "    sjf_global_destroy(&global);\n";
        }
        stream << "}\n";
    }
}

