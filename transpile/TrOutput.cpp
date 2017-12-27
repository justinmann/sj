#include <sjc.h>
#include "../compiler/Compiler.h"

TrOutput::TrOutput() {
}

void TrOutput::writeToStream(Compiler* compiler, ostream& stream, bool hasMainLoop) {
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
    
    auto level = 0;
    for (auto line : ccodeTypedefs) {
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

    if (strings.size() > 0) {
        for (auto t : strings) {
            stream << "const char* " << t.first << " = \"" << t.second << "\";\n";
        }
        stream << "\n";
    }
    
    level = 0;
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
    
    if (vtbls.size() > 0) {
        for (auto t : vtbls) {
            stream << t.second->ctype << " " << t.first << ";\n";
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
    
    mainFunction->writeVariablesToStream(compiler, stream, 0);

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
        function.second->writeToStream(compiler, stream, 1);
        stream << "}\n";
        stream << "\n";
    }

    stream << "int main(int argc, char** argv) {\n";
    if (compiler->outputDebugLeaks) {
        stream << "    _object_start();\n";
    }

    if (vtbls.size() > 0) {
        for (auto t : vtbls) {
            for (auto line : t.second->functions) {
                TrBlock::addSpacing(stream, 1);
                stream << t.first << "." << line.first << " = " << line.second << ";\n";
            }
        }
    }

    mainFunction->writeBodyToStream(compiler, stream, 1);
    stream << "    main_destroy();\n";
    stream << "    return 0;\n";
    stream << "}\n";
    stream << "\n";
    stream << "void main_destroy() {\n";
    mainFunction->writeVariablesReleaseToStream(compiler, stream, 1);
    if (compiler->outputDebugLeaks) {
        stream << "    _object_report();\n";
    }
    stream << "}\n";
}

