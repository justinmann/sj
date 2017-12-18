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

void CValueVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    if (!storeValue->type->parent.expired() && storeValue->type->typeMode == CTM_Stack) {
        /* TODO: stringstream line1;
        if (storeValue->isReturnValue) {
            line1 << storeValue->getName(trBlock) << "->_refCount = 1";
        }
        else {
            line1 << storeValue->getName(trBlock) << "._refCount = 1";
        }
        trBlock->statements.push_back(TrStatement(loc, line1.str()));
        */
        auto leftValue = make_shared<TrStoreValue>(storeValue->loc, storeValue->scope, storeValue->type->getValueType(), storeValue->getName(trBlock), storeValue->op);
        leftValue->isReturnValue = storeValue->isReturnValue;
        var->transpile(compiler, trOutput, trBlock, thisValue, leftValue);
        if (!leftValue->hasSetValue) {
            return;
        }
        storeValue->hasSetValue = true;
    }
    else {
        auto leftValue = trBlock->createTempStoreVariable(loc, scope.lock(), var->getType(compiler), "value");
        var->transpile(compiler, trOutput, trBlock, thisValue, leftValue);
        if (!leftValue->hasSetValue) {
            return;
        }

        if (leftValue->type->isOption) {
            compiler->addError(loc, CErrorCode::TypeMismatch, "value cannot take an option type");
            return;
        }

        if (leftValue->type->parent.expired() && leftValue->type->category != CTC_Function) {
            auto returnValue = trBlock->createTempVariable(scope.lock(), leftValue->type->getOptionType(), "value");
            stringstream line1;
            line1 << returnValue->name << ".isempty = false";
            trBlock->statements.push_back(TrStatement(loc, line1.str()));

            stringstream line2;
            line2 << returnValue->name << ".value = " << leftValue->getName(trBlock);
            trBlock->statements.push_back(TrStatement(loc, line2.str()));

            storeValue->retainValue(compiler, loc, trBlock, returnValue);
        }
        else {
            storeValue->retainValue(compiler, loc, trBlock, make_shared<TrValue>(leftValue->scope, leftValue->type->getOptionType(), leftValue->getName(trBlock), leftValue->isReturnValue));
        }
    }
}

void CValueVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "value(";
    var->dump(compiler, functions, ss, level);
    ss << ")";

}

void NValue::defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, importNamespaces, packageNamespace, thisFunction);
}

shared_ptr<CVar> NValue::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = node->getVar(compiler, scope, returnMode);
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

    return make_shared<CValueVar>(loc, leftVar->scope.lock(), leftVar);
}
