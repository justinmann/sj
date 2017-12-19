#include "Node.h"

void NGetOrElse::defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {

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
