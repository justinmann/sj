#include "Node.h"

void NOptionDot::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {

}

shared_ptr<CVar> NOptionDot::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, CTypeReturnMode returnMode) {
    auto getValueNode = make_shared<NGetValue>(loc, left, true);
    auto dotNode = make_shared<NDot>(loc, getValueNode, right);
    auto ctype = dotNode->getType(compiler, result, thisFunction, dotVar);
    if (ctype == compiler->typeVoid) {
        auto ifNode = make_shared<NIf>(loc, make_shared<NNot>(loc, make_shared<NIsEmpty>(loc, left)), dotNode, nullptr);
        return ifNode->getVar(compiler, result, thisFunction, thisVar, dotVar);
    }
    else {
        shared_ptr<NBase> valueNode;
        if (!ctype->isOption) {
            valueNode = make_shared<NValue>(loc, dotNode);
            ctype = ctype->getOptionType();
        }
        else {
            valueNode = dotNode;
        }
        
        if (!ctype) {
            result.addError(loc, CErrorCode::TypeMismatch, "cannot find type");
            return nullptr;
        }
        
        auto emptyNode = make_shared<NEmpty>(loc, make_shared<CTypeName>(ctype));
        auto ifNode = make_shared<NIf>(loc, make_shared<NIsEmpty>(loc, left), emptyNode, valueNode);
        return ifNode->getVar(compiler, result, thisFunction, thisVar, dotVar);
    }
}
