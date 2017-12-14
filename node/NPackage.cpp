#include "Node.h"

void NPackage::defineImpl(Compiler* compiler, vector<vector<string>>& namespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    vector<string> newPackageNamespace = packageNamespace;
    for (auto t : ns) {
        newPackageNamespace.push_back(t);
    }
    node->define(compiler, namespaces, newPackageNamespace, thisFunction);
}

shared_ptr<CVar> NPackage::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    scope->pushNamespace(compiler, ns);
    auto var = node->getVar(compiler, scope, returnMode);
    scope->popNamespace(compiler, ns);
    return var;
}

