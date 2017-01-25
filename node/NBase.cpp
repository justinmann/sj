#include "Node.h"

void NBase::define(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    if (!_hasDefined) {
        _hasDefined = true;
        defineImpl(compiler, result, thisFunction);
    }
}

shared_ptr<CVar> NBase::getVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    if (!_hasGetVar) {
        _var = getVarImpl(compiler, result, thisFunction);
        _hasGetVar = true;
    }
    return _var;
}

shared_ptr<CType> NBase::getType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    if (!_hasGetType) {
        _type = getTypeImpl(compiler, result, thisFunction);
        _hasGetType = true;
    }
    return _type;
}

int NBase::setHeapVar(Compiler *compiler, CResult &result, shared_ptr<CFunction> thisFunction, bool isHeapVar) {
    return setHeapVarImpl(compiler, result, thisFunction, isHeapVar);
}


Value* NBase::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    return compileImpl(compiler, result, thisFunction, thisValue, builder, catchBB);
}

