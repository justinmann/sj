#include "Node.h"

shared_ptr<CType> CParentVar::getType(Compiler* compiler, CResult& result) {
    auto parentTypes = function->getThisTypes(compiler, result);
    if (!parentTypes) {
        return nullptr;
    }
    return parentTypes->localValueType;
}

void CParentVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto parentTypes = function->getThisTypes(compiler, result);
    if (!parentTypes) {
        return;
    }

    storeValue->setValue(compiler, result, loc, trBlock, make_shared<TrValue>(
        parentTypes->localValueType,
        "_parent"));
}

void CParentVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "parent";
}


shared_ptr<CVar> NParent::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    if (dotVar) {
        result.addError(loc, CErrorCode::InvalidVariable, "this must be the first var in a dot chain");
        return nullptr;
    }
    
    auto parentFunction = static_pointer_cast<CFunction>(thisFunction->parent.lock());
    parentFunction->setHasThis();
    return make_shared<CParentVar>(loc, nullptr, parentFunction);
}
