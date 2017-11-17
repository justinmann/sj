#include "Node.h"

void NGetOrElse::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {

}

shared_ptr<CVar> NGetOrElse::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar) {
    auto getValueNode = make_shared<NGetValue>(loc, left, true);
    auto ifNode = make_shared<NIf>(loc, make_shared<NIsEmpty>(loc, left), right, getValueNode);
    return ifNode->getVar(compiler, result, thisFunction, thisVar, dotVar);
}
