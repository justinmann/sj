#include "Node.h"

shared_ptr<CType> NVoid::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeVoid;
}

Value* NVoid::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, bool isReturnRetained) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    return nullptr;
}

void NVoid::dump(Compiler* compiler, int level) const {
    dumpf(level, "value: 'void'");
}
