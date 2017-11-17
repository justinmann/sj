#include "Node.h"

shared_ptr<CType> CParentVar::getType(Compiler* compiler, CResult& result) {
    auto parentTypes = function->getThisTypes(compiler, result);
    if (!parentTypes) {
        return nullptr;
    }
    return parentTypes->localValueType;
}

shared_ptr<ReturnValue> CParentVar::transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    auto parentTypes = function->getThisTypes(compiler, result);
    if (!parentTypes) {
        return nullptr;
    }

    return make_shared<ReturnValue>(
        parentTypes->localValueType,
        "_parent");
}

void CParentVar::transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) {
    assert(false);
}

void CParentVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeReturnMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "parent";
}


shared_ptr<CVar> NParent::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar) {
    if (dotVar) {
        result.addError(loc, CErrorCode::InvalidVariable, "this must be the first var in a dot chain");
        return nullptr;
    }
    
    auto parentFunction = static_pointer_cast<CFunction>(thisFunction->parent.lock());
    parentFunction->setHasRefCount();
    return make_shared<CParentVar>(loc, parentFunction);
}