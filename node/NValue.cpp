#include "Node.h"

bool CValueVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CValueVar::getType(Compiler* compiler) {
    auto leftType = var->getType(compiler);
    if (!leftType) {
        return nullptr;
    }

    if (leftType->isOption) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "value cannot take an option type");
        return nullptr;
    }

    return leftType->getOptionType();
}

void CValueVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto leftValue = trBlock->createTempStoreVariable(loc, scope.lock(), var->getType(compiler), "value");
    var->transpile(compiler, trOutput, trBlock, nullptr, thisValue, leftValue);
    if (!leftValue->hasSetValue) {
        return;
    }

    if (leftValue->type->isOption) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "value cannot take an option type");
        return;
    }

    if (leftValue->type->parent.expired()) {
        auto returnValue = trBlock->createTempVariable(scope.lock(), leftValue->type->getOptionType(), "value");
        stringstream line1;
        line1 << returnValue->name << ".isEmpty = false";
        trBlock->statements.push_back(line1.str());

        stringstream line2;
        line2 << returnValue->name << ".value = " << leftValue->getName(trBlock);
        trBlock->statements.push_back(line2.str());

        storeValue->retainValue(compiler, loc, trBlock, returnValue);
    }
    else {
        storeValue->retainValue(compiler, loc, trBlock, make_shared<TrValue>(leftValue->scope, leftValue->type->getOptionType(), leftValue->getName(trBlock), leftValue->isReturnValue));
    }
}

void CValueVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "value(";
    var->dump(compiler, nullptr, functions, ss, dotSS, level);
    ss << ")";

}

void NValue::defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, thisFunction);
}

shared_ptr<CVar> NValue::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = node->getVar(compiler, scope, CTM_Heap);
    if (!leftVar) {
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler);
    if (!leftType) {
        return nullptr;
    }

    if (leftType->isOption) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "value cannot take an option type");
        return nullptr;
    }

    if (leftType->typeMode != CTM_Heap && leftType->typeMode != CTM_Value && leftType->typeMode != CTM_Local) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "value can only work on local, heap, or value objects");
        return nullptr;
    }

    return make_shared<CValueVar>(loc, leftVar->scope.lock(), leftVar);
}
