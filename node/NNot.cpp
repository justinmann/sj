#include "Node.h"

void NNot::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NNot::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    node->getVar(compiler, result, thisFunction);
    return nullptr;
}

shared_ptr<CType> NNot::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeBool;
}

int NNot::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, bool isHeapVar) {
    return node->setHeapVar(compiler, result, thisFunction, false);
}

shared_ptr<ReturnValue> NNot::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    auto v = node->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    if (!v)
        return nullptr;
    
    assert(v->type == RVT_SIMPLE);
    
    if (!v->value->getType()->isIntegerTy(1)) {
        result.addError(loc, CErrorCode::TypeMismatch, "must be bool");
        return nullptr;
    }
    
    return make_shared<ReturnValue>(builder->CreateNot(v->value));
}

void NNot::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NNot'");
    
    dumpf(level, "node: {");
    node->dump(compiler, level + 1);
    dumpf(level, "}");
}