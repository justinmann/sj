#include "Node.h"

NodeType NChar::getNodeType() const {
    return NodeType_Char;
}

shared_ptr<CType> NChar::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeChar;
}

Value* NChar::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);    
    return ConstantInt::get(compiler->context, APInt(8, value));
}

void NChar::dump(Compiler* compiler, int level) const {
    dumpf(level, "value: %c", value);
}
