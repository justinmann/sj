#include "Node.h"

NodeType NBool::getNodeType() const {
    return NodeType_Bool;
}

shared_ptr<CType> NBool::getReturnType(Compiler* compiler, CResult& result) const {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeBool;
}

Value* NBool::compile(Compiler* compiler, CResult& result) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    return ConstantInt::get(compiler->context, APInt(1, value));
}

void NBool::dump(Compiler* compiler, int level) const {
    dumpf(level, "value: %s", bool_to_str(value));
}
