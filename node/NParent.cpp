#include "Node.h"

shared_ptr<CType> CParentVar::getType(Compiler* compiler, CResult& result) {
    auto parentTypes = function->getThisTypes(compiler, result);
    if (!parentTypes) {
        return nullptr;
    }
    return parentTypes->localValueType;
}

shared_ptr<ReturnValue> CParentVar::transpileGet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> thisValue) {
    auto parentTypes = function->getThisTypes(compiler, result);
    if (!parentTypes) {
        return nullptr;
    }

    return make_shared<ReturnValue>(
        parentTypes->localValueType,
        "_parent");
}

void CParentVar::transpileSet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, shared_ptr<ReturnValue> thisValue, AssignOp op, bool isFirstAssignment) {
    assert(false);
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
