#include "Node.h"

bool CIsEmptyVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CIsEmptyVar::getType(Compiler* compiler) {
    return compiler->typeBool;
}

void CIsEmptyVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
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
    if (leftValue->type->parent.expired() && leftValue->type->category != CTC_Function) {
        line << leftValue->getName(trBlock) << ".isempty";
    }
    else {
        if (leftValue->type->category == CTC_Function) {
            line << "(" << leftValue->getName(trBlock) << "->_parent" << " == 0)";
        }
        else if (leftValue->type->category == CTC_Interface) {
            line << "(" << leftValue->getName(trBlock) << "._parent" << " == 0)";
        }
        else {
            line << "(" << leftValue->getName(trBlock) << " == 0)";
        }
    }
    storeValue->retainValue(compiler, loc, trBlock, make_shared<TrValue>(nullptr, compiler->typeBool, line.str(), false));
}

void CIsEmptyVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "isEmpty(";
    var->dump(compiler, functions, ss, level);
    ss << ")";
}


void NIsEmpty::defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, importNamespaces, packageNamespace, thisFunction);
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
