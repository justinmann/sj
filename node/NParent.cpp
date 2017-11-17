#include "Node.h"

NParent::NParent(CLoc loc) : NVariableBase(NodeType_Parent, loc) { }

shared_ptr<ReturnValue> NParent::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, const char* thisName) {
    auto parentFunction = thisFunction->parent.lock();
    if (!parentFunction) {
        return nullptr;
    }
    auto parentTypes = parentFunction->getThisTypes(compiler, result);
    if (!parentTypes) {
        return nullptr;
    }

    return make_shared<ReturnValue>(
        parentTypes->localValueType,
        "_parent");
}

shared_ptr<CVar> NParent::getVarImpl(Compiler *compiler, CResult &result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, CTypeReturnMode returnMode) {
    if (dotVar) {
        result.addError(loc, CErrorCode::InvalidVariable, "this must be the first var in a dot chain");
        return nullptr;
    }
    
    auto parentFunction = thisFunction->parent.lock();
    parentFunction->setHasRefCount();
    return parentFunction->getThisVar(compiler, result, returnMode);
}
