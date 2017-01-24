#include "Node.h"

shared_ptr<CType> NChar::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeChar;
}

Value* NChar::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);    
    return ConstantInt::get(compiler->context, APInt(8, value));
}

void NChar::dump(Compiler* compiler, int level) const {
    dumpf(level, "value: %c", value);
}
