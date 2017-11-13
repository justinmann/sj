#include "Node.h"

void NOptionDot::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {

}

shared_ptr<CVar> NOptionDot::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar) {
    auto getValueNode = make_shared<NGetValue>(loc, left, true);
    auto dotNode = make_shared<NDot>(loc, getValueNode, right);
    auto ctype = dotNode->getType(compiler, result, thisFunction, dotVar);
    shared_ptr<NBase> valueNode;
    if (!ctype->isOption) {
        valueNode = make_shared<NValue>(loc, dotNode);
        ctype = ctype->getOptionType();
    }
    else {
        valueNode = dotNode;
    }
    auto emptyNode = make_shared<NEmpty>(loc, make_shared<CTypeName>(ctype));
    auto ifNode = make_shared<NIf>(loc, make_shared<NIsEmpty>(loc, left), emptyNode, valueNode);
    return ifNode->getVar(compiler, result, thisFunction, thisVar, dotVar);
}

int NOptionDot::setHeapVarImpl(Compiler *compiler, CResult &result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, bool isHeapVar) {
    auto cvar = getVar(compiler, result, thisFunction, thisVar, dotVar);
    if (isHeapVar) {
        return cvar->setHeapVar(compiler, result, thisVar);
    }
    return 0;
}
