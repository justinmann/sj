#include "Node.h"

bool CIsEmptyVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CIsEmptyVar::getType(Compiler* compiler, CResult& result) {
    return compiler->typeBool;
}

void CIsEmptyVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto leftValue = trBlock->createTempStoreVariable(var->getType(compiler, result), "temp");
    var->transpile(compiler, result, trOutput, trBlock, nullptr, thisValue, leftValue);
    if (!leftValue->hasSetValue) {
        return;
    }
    
    if (!leftValue->type->isOption) {
        result.addError(loc, CErrorCode::TypeMismatch, "isEmpty requires an option type");
        return;
    }
    
    stringstream line;
    if (leftValue->type->parent.expired()) {
        line << leftValue->name << ".isEmpty";
    }
    else {
        line << "(" << leftValue->name << " == 0)";
    }
    storeValue->setValue(compiler, result, loc, trBlock, make_shared<TrValue>(compiler->typeBool, line.str()));
}

void CIsEmptyVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "isEmpty(";
    var->dump(compiler, result, nullptr, functions, ss, dotSS, level);
    ss << ")";
}


void NIsEmpty::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NIsEmpty::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = node->getVar(compiler, result, thisFunction, thisVar, CTM_Undefined);
    if (!leftVar) {
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler, result);
    if (!leftType) {
        return nullptr;
    }

    if (!leftType->isOption) {
        result.addError(loc, CErrorCode::TypeMismatch, "isEmpty requires an option type");
        return nullptr;
    }

    return make_shared<CIsEmptyVar>(loc, thisFunction, leftVar);
}
