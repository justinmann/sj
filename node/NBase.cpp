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

shared_ptr<CVar> NBase::getVar(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode) {
    assert(thisVar != nullptr);

    auto key1 = thisFunction.get();
    auto key2 = returnMode;
    
    if (_var[key1].find(key2) == _var[key1].end()) {
        _var[key1][key2] = getVarImpl(compiler, result, thisFunction, thisVar, returnMode);
        _thisVars[key1][key2] = thisVar.get();
    }

    assert(_thisVars[key1][key2] == thisVar.get());
    return _var[key1][key2];
}
