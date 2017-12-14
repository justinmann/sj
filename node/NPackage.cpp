#include "Node.h"

void NPackage::defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, thisFunction);
}

shared_ptr<CVar> NPackage::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    scope->pushNamespace(compiler, ns);
    auto var = node->getVar(compiler, scope, returnMode);
    scope->popNamespace(compiler, ns);
    return var;
}

