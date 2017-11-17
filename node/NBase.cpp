#include "Node.h"

void dumpf(stringstream& ss, int level) {
    for (int i = 0; i < level; i++) {
        ss << "  ";
    }
}

void NBase::define(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    if (!_hasDefined) {
        _hasDefined = true;
        defineImpl(compiler, result, thisFunction);
    }
}

shared_ptr<CVar> NBase::getVar(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar) {
    if (_var.find(thisFunction.get()) == _var.end()) {
        assert(compiler->state == CompilerState::FixVar);
        _var[thisFunction.get()] = getVarImpl(compiler, result, thisFunction, thisVar);
    }
    return _var[thisFunction.get()];
}
