#include "Node.h"

shared_ptr<CType> NVoid::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeVoid;
}

shared_ptr<ReturnValue> NVoid::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    return nullptr;
}

void NVoid::dump(Compiler* compiler, int level) const {
    dumpf(level, "value: 'void'");
}
