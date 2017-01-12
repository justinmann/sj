#include "Node.h"

NodeType NNot::getNodeType() const {
    return NodeType_Not;
}

void NNot::define(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result, thisFunction);
}

void NNot::fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    node->fixVar(compiler, result, thisFunction);
}

shared_ptr<CType> NNot::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeBool;
}

Value* NNot::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    Value *v = node->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    if (!v)
        return nullptr;
    
    if (!v->getType()->isIntegerTy(1)) {
        result.addError(loc, CErrorCode::TypeMismatch, "must be bool");
        return nullptr;
    }
    
    return builder->CreateNot(v);
}

void NNot::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NNot'");
    
    dumpf(level, "node: {");
    node->dump(compiler, level + 1);
    dumpf(level, "}");
}
