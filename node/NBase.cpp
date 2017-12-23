#include "Node.h"

void dumpf(stringstream& ss, int level) {
    for (int i = 0; i < level; i++) {
        ss << "  ";
    }
}

void NBase::initFunctions(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    if (!_hasInitFunctions) {
        _hasInitFunctions = true;
        initFunctionsImpl(compiler, importNamespaces, packageNamespace, thisFunction);
    }
}

void NBase::initVars(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    auto key1 = scope.get();
    if (!_hasInitVars[key1]) {
        _hasInitVars[key1] = true;
        initVarsImpl(compiler, scope, returnMode);
    }
}

shared_ptr<CVar> NBase::getVar(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    assert(scope != nullptr);
    auto key1 = scope.get();
    if (_var.find(key1) == _var.end()) {
        _var[key1] = getVarImpl(compiler, scope, returnMode);
    }
    return _var[key1];
}
