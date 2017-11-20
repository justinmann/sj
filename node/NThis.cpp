#include "Node.h"

shared_ptr<CType> CThisVar::getType(Compiler* compiler, CResult& result) {
    switch (typeMode) {
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
}

shared_ptr<ReturnValue> CThisVar::transpileGet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    return make_shared<ReturnValue>(getType(compiler, result), "_this");
}

void CThisVar::transpileSet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) {
    assert(false);
}

void CThisVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "this";
}

void CThisVar::setHasThis() {
    auto function = types->stackValueType->parent.lock();
    function->setHasThis();
}

CTypeMode CThisVar::getTypeMode() {
    if (typeMode == CTM_Undefined) {
        return CTM_Stack;
    }
    return typeMode;
}

shared_ptr<CVar> NThis::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    if (dotVar) {
        result.addError(loc, CErrorCode::InvalidVariable, "this must be the first var in a dot chain");
        return nullptr;
    }

    if (!thisVar) {
        result.addError(loc, CErrorCode::InvalidVariable, "function does not have a this value");
        return nullptr;
    }
    
    assert(returnMode != CTM_Value);
    if (returnMode != CTM_Undefined) {
        if (thisVar->typeMode == CTM_Undefined) {
            thisVar->typeMode = returnMode;
        }

        if (returnMode != thisVar->typeMode) {
            result.addError(loc, CErrorCode::TypeMismatch, "cannot change this from stack to heap in the same function");
        }
    }

    thisVar->setHasThis();
    return thisVar;
}
