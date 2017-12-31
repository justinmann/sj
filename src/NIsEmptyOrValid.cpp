#include <sjc.h>


bool CIsEmptyOrValidVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CIsEmptyOrValidVar::getType(Compiler* compiler) {
    return compiler->typeBool;
}

void CIsEmptyOrValidVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto leftValue = trBlock->createCaptureStoreVariable(loc, scope.lock(), var->getType(compiler)->getTempType());
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
            line << "!" << leftValue->getCaptureText() << ".isvalid";
        }
        else {
            if (leftValue->type->category == CTC_Function) {
                line << "(" << leftValue->getCaptureText() << "._parent" << " == 0)";
            }
            else if (leftValue->type->category == CTC_Interface) {
                line << "(" << leftValue->getCaptureText() << "._parent" << " == 0)";
            }
            else {
                line << "(" << leftValue->getCaptureText() << " == 0)";
            }
        }
    }
    else {
        if (leftValue->type->parent.expired() && leftValue->type->category != CTC_Function) {
            line << leftValue->getCaptureText() << ".isvalid";
        }
        else {
            if (leftValue->type->category == CTC_Function) {
                line << "(" << leftValue->getCaptureText() << "._parent" << " != 0)";
            }
            else if (leftValue->type->category == CTC_Interface) {
                line << "(" << leftValue->getCaptureText() << "._parent" << " != 0)";
            }
            else {
                line << "(" << leftValue->getCaptureText() << " != 0)";
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


void NIsEmptyOrValid::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
}

void NIsEmptyOrValid::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    node->initVars(compiler, scope, returnMode);
}

shared_ptr<CVar> NIsEmptyOrValid::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
    auto leftVar = node->getVar(compiler, scope, nullptr, CTM_Undefined);
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
