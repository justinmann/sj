#include "Node.h"

NodeType NVoid::getNodeType() const {
    return NodeType_Void;
}

shared_ptr<CType> NVoid::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeVoid;
}

Value* NVoid::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    return nullptr;
}

void NVoid::dump(Compiler* compiler, int level) const {
    dumpf(level, "value: 'void'");
}
