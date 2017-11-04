#include "../compiler/Compiler.h"

void TrVariable::writeReleaseToStream(ostream& stream, int level) {
    if (releaseMode == TRM_STACKDESTROY && destroyFunctionName.size() > 0) {
        TrBlock::addSpacing(stream, level);
        stream << destroyFunctionName << "(" << name << ");\n";
    }

    if (releaseMode == TRM_RELEASE) {
        TrBlock::addSpacing(stream, level);
        stream << name << "->_refCount--;\n";
        TrBlock::addSpacing(stream, level);
        stream << "if (" << name << "->_refCount == 0) {\n";
        if (destroyFunctionName.size() > 0) {
            TrBlock::addSpacing(stream, level + 1);
            stream << destroyFunctionName << "(" << name << ");\n";
        }
        TrBlock::addSpacing(stream, level + 1);
        stream << "free(" << name << ");\n";
        TrBlock::addSpacing(stream, level);
        stream << "}\n";
    }
}
