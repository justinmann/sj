#include "Node.h"

bool CGetValueVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CGetValueVar::getType(Compiler* compiler) {
    auto leftType = leftVar->getType(compiler);
    if (!leftType) {
        return nullptr;
    }

    if (!leftType->isOption) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "getValue requires an option type");
        return nullptr;
    }

    return leftType->getValueType();
}

void CGetValueVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    if (!storeValue->type->parent.expired()) {
        auto leftValue = make_shared<TrStoreValue>(storeValue->loc, storeValue->scope, storeValue->type->getOptionType(), storeValue->getName(trBlock), storeValue->op);
        leftVar->transpile(compiler, trOutput, trBlock, thisValue, leftValue);
        if (!leftValue->hasSetValue) {
            return;
        }
        storeValue->hasSetValue = true;

        if (!isProtectedWithEmptyCheck) {
            stringstream emptyCheck;
            emptyCheck << "if (" << leftValue->getName(trBlock) << "->_refCount == -1) { exit(-1); }";
            trBlock->statements.push_back(TrStatement(loc, emptyCheck.str()));
        }
    }
    else {
        auto leftValue = trBlock->createTempStoreVariable(loc, leftVar->scope.lock(), leftVar->getType(compiler), "getValue");
        leftVar->transpile(compiler, trOutput, trBlock, thisValue, leftValue);
        if (!leftValue) {
            return;
        }

        if (!leftValue->type->isOption) {
            compiler->addError(loc, CErrorCode::TypeMismatch, "getValue requires an option type");
            return;
        }

        stringstream line;
        if (leftValue->type->parent.expired() && leftValue->type->category != CTC_Function) {
            if (!isProtectedWithEmptyCheck) {
                stringstream emptyCheck;
                emptyCheck << "if (" << leftValue->getName(trBlock) << ".isempty) { exit(-1); }";
                trBlock->statements.push_back(TrStatement(loc, emptyCheck.str()));
            }
            line << leftValue->getName(trBlock) << ".value";
        }
        else {
            if (!isProtectedWithEmptyCheck) {
                stringstream emptyCheck;
                emptyCheck << "if (";
                if (leftValue->type->category == CTC_Function) {
                    emptyCheck << leftValue->getName(trBlock) << "._parent";
                }
                else {
                    emptyCheck << leftValue->getName(trBlock);
                }
                emptyCheck << " == 0) { exit(-1); }";
                trBlock->statements.push_back(TrStatement(loc, emptyCheck.str()));
            }
            line << leftValue->getName(trBlock);
        }

        storeValue->retainValue(compiler, loc, trBlock, make_shared<TrValue>(scope.lock(), leftValue->type->getValueType(), line.str(), false));
    }
}

void CGetValueVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "getValue(";
    leftVar->dump(compiler, functions, ss, level);
    ss << ")";
}


void NGetValue::defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, importNamespaces, packageNamespace, thisFunction);
}

shared_ptr<CVar> NGetValue::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = node->getVar(compiler, scope, CTM_Undefined);
    if (!leftVar) {
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler);
    if (!leftType) {
        return nullptr;
    }

    if (!leftType->isOption) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "getValue requires an option type");
        return nullptr;
    }

    return make_shared<CGetValueVar>(loc, leftVar->scope.lock(), leftVar, isProtectedWithEmptyCheck);
}
