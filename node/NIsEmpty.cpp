#include "Node.h"

bool CIsEmptyVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CIsEmptyVar::getType(Compiler* compiler) {
    return compiler->typeBool;
}

void CIsEmptyVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto leftValue = trBlock->createTempStoreVariable(loc, scope.lock(), var->getType(compiler), "isEmpty");
    var->transpile(compiler, trOutput, trBlock, nullptr, thisValue, leftValue);
    if (!leftValue->hasSetValue) {
        return;
    }
    
    if (!leftValue->type->isOption) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "isEmpty requires an option type");
        return;
    }
    
    stringstream line;
    if (leftValue->type->parent.expired()) {
        line << leftValue->getName(trBlock) << ".isEmpty";
    }
    else {
        line << "(" << leftValue->getName(trBlock) << " == 0)";
    }
    storeValue->retainValue(compiler, loc, trBlock, make_shared<TrValue>(nullptr, compiler->typeBool, line.str(), false));
}

void CIsEmptyVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "isEmpty(";
    var->dump(compiler, nullptr, functions, ss, dotSS, level);
    ss << ")";
}


void NIsEmpty::defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, thisFunction);
}

shared_ptr<CVar> NIsEmpty::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = node->getVar(compiler, scope, CTM_Undefined);
    if (!leftVar) {
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler);
    if (!leftType) {
        return nullptr;
    }

    if (!leftType->isOption) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "isEmpty requires an option type");
        return nullptr;
    }

    return make_shared<CIsEmptyVar>(loc, scope, leftVar);
}
