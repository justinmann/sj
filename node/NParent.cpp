#include "Node.h"

bool CParentVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CParentVar::getType(Compiler* compiler) {
    auto parentTypes = function->getThisTypes(compiler);
    if (!parentTypes) {
        return nullptr;
    }
    return parentTypes->localValueType;
}

void CParentVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto parentTypes = function->getThisTypes(compiler);
    if (!parentTypes) {
        return;
    }

    storeValue->retainValue(compiler, trBlock, make_shared<TrValue>(nullptr, parentTypes->localValueType, "_parent"));
}

void CParentVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "parent";
}


shared_ptr<CVar> NParent::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    if (dotVar) {
        compiler->addError(loc, CErrorCode::InvalidVariable, "this must be the first var in a dot chain");
        return nullptr;
    }
    
    auto parentFunction = static_pointer_cast<CFunction>(scope->function->parent.lock());
    parentFunction->setHasThis();
    return make_shared<CParentVar>(loc, nullptr, parentFunction);
}
