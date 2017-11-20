#include "Node.h"

void NOptionDot::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    left->define(compiler, result, thisFunction);
    right->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NOptionDot::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto getValueNode = make_shared<NGetValue>(loc, left, true);
    auto localDotNode = make_shared<NDot>(loc, getValueNode, right);
    auto localDotVar = localDotNode->getVar(compiler, result, thisFunction, thisVar, dotVar, CTM_Undefined);
    if (!localDotVar) {
        return nullptr;
    }
    auto ctype = localDotVar->getType(compiler, result);
    if (ctype == compiler->typeVoid) {
        auto ifNode = make_shared<NIf>(loc, make_shared<NNot>(loc, make_shared<NIsEmpty>(loc, left)), localDotNode, nullptr);
        return ifNode->getVar(compiler, result, thisFunction, thisVar, dotVar, returnMode);
    }
    else {
        shared_ptr<NBase> valueNode;
        if (!ctype->isOption) {
            valueNode = make_shared<NValue>(loc, localDotNode);
            ctype = ctype->getOptionType();
        }
        else {
            valueNode = localDotNode;
        }
        
        if (!ctype) {
            result.addError(loc, CErrorCode::TypeMismatch, "cannot find type");
            return nullptr;
        }
        
        auto emptyNode = make_shared<NEmpty>(loc, make_shared<CTypeName>(ctype));
        auto ifNode = make_shared<NIf>(loc, make_shared<NIsEmpty>(loc, left), emptyNode, valueNode);
        return ifNode->getVar(compiler, result, thisFunction, thisVar, dotVar, returnMode);
    }
}
