#include "Node.h"

shared_ptr<CType> CThisVar::getType(Compiler* compiler, CResult& result, CTypeMode returnMode) {
    switch (typeMode) {
    case CTM_Stack:
        return types->stackValueType;
    case CTM_Heap:
        return types->heapValueType;
    case CTM_Undefined:
        switch (returnMode) {
        case CTM_Stack:
            return types->stackValueType;
        case CTM_Heap:
            return types->heapValueType;
        case CTM_Undefined:
            return types->stackValueType;
        default:
            assert(false);
            return nullptr;
        }
    default:
        assert(false);
        return nullptr;
    }
}

shared_ptr<ReturnValue> CThisVar::transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    assert(returnMode != CTM_Value);
    if (typeMode == CTM_Undefined) {
        typeMode = returnMode;
    }
    assert(returnMode == typeMode);

    return make_shared<ReturnValue>(thisVar->getType(compiler, result, CTM_Undefined), "_this");
}

void CThisVar::transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) {
    assert(false);
}

void CThisVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "this";
}

void CThisVar::setHasRefCount() {
    auto function = types->stackValueType->parent.lock();
    function->setHasRefCount();
}

CTypeMode CThisVar::getTypeMode() {
    if (typeMode == CTM_Undefined) {
        return CTM_Stack;
    }
    return typeMode;
}

shared_ptr<CVar> NThis::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar) {
    if (dotVar) {
        result.addError(loc, CErrorCode::InvalidVariable, "this must be the first var in a dot chain");
        return nullptr;
    }

    if (!thisVar) {
        result.addError(loc, CErrorCode::InvalidVariable, "function does not have a this value");
        return nullptr;
    }
    
    thisVar->setHasRefCount();    
    return thisVar;
}
