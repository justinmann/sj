#include "Node.h"

shared_ptr<CType> NBool::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeBool;
}

Value* NBool::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, bool isReturnRetained) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    return ConstantInt::get(compiler->context, APInt(1, value));
}

void NBool::dump(Compiler* compiler, int level) const {
    dumpf(level, "value: %s", bool_to_str(value));
}
