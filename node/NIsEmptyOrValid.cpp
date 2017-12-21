#include "Node.h"

bool CIsEmptyOrValidVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CIsEmptyOrValidVar::getType(Compiler* compiler) {
    return compiler->typeBool;
}

void CIsEmptyOrValidVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto leftValue = trBlock->createTempStoreVariable(loc, scope.lock(), var->getType(compiler)->getLocalType(), "isEmpty");
    var->transpile(compiler, trOutput, trBlock, thisValue, leftValue);
    if (!leftValue->hasSetValue) {
        return;
    }
    
    if (!leftValue->type->isOption) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "isEmpty requires an option type");
        return;
    }
    
    stringstream line;
    if (isEmpty) {
        if (leftValue->type->parent.expired() && leftValue->type->category != CTC_Function) {
            line << "!" << leftValue->getName(trBlock) << ".isvalid";
        }
        else {
            if (leftValue->type->category == CTC_Function) {
                line << "(" << leftValue->getName(trBlock) << "._parent" << " == 0)";
            }
            else if (leftValue->type->category == CTC_Interface) {
                line << "(" << leftValue->getName(trBlock) << "._parent" << " == 0)";
            }
            else {
                line << "(" << leftValue->getName(trBlock) << " == 0)";
            }
        }
    }
    else {
        if (leftValue->type->parent.expired() && leftValue->type->category != CTC_Function) {
            line << leftValue->getName(trBlock) << ".isvalid";
        }
        else {
            if (leftValue->type->category == CTC_Function) {
                line << "(" << leftValue->getName(trBlock) << "._parent" << " != 0)";
            }
            else if (leftValue->type->category == CTC_Interface) {
                line << "(" << leftValue->getName(trBlock) << "._parent" << " != 0)";
            }
            else {
                line << "(" << leftValue->getName(trBlock) << " != 0)";
            }
        }
    }
    storeValue->retainValue(compiler, loc, trBlock, make_shared<TrValue>(nullptr, compiler->typeBool, line.str(), false));
}

void CIsEmptyOrValidVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    if (isEmpty) {
        ss << "isEmpty(";
    }
    else {
        ss << "isValid(";
    }
    var->dump(compiler, functions, ss, level);
    ss << ")";
}


void NIsEmptyOrValid::defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, importNamespaces, packageNamespace, thisFunction);
}

shared_ptr<CVar> NIsEmptyOrValid::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = node->getVar(compiler, scope, CTM_Undefined);
    if (!leftVar) {
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler);
    if (!leftType) {
        return nullptr;
    }

    if (!leftType->isOption) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "%s requires an option type", (isEmpty ? "isEmpty" : "isValid"));
        return nullptr;
    }

    return make_shared<CIsEmptyOrValidVar>(loc, scope, leftVar, isEmpty);
}
