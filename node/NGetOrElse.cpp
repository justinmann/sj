#include "Node.h"

void NGetOrElse::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    left->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    right->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
}

void NGetOrElse::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    left->initVars(compiler, scope, returnMode);
    right->initVars(compiler, scope, returnMode);
}

shared_ptr<CVar> NGetOrElse::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = left->getVar(compiler, scope, dotVar, returnMode);
    if (!leftVar) {
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler);
    if (!leftType) {
        return nullptr;
    }

    if (leftType->isOption) {
        auto getValueNode = make_shared<NGetValue>(loc, left, true);
        auto ifNode = make_shared<NIf>(loc, make_shared<NIsEmptyOrValid>(loc, left, false), getValueNode, right, true);
        return ifNode->getVar(compiler, scope, dotVar, returnMode);
    }
    else {
        return leftVar;
    }
}
