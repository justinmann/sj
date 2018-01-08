#include <sjc.h>

void NGetOrDefault::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    left->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
}

void NGetOrDefault::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    left->initVars(compiler, scope, returnMode);
}

shared_ptr<CVar> NGetOrDefault::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
    auto leftVar = left->getVar(compiler, scope, nullptr, returnType, returnMode);
    if (!leftVar) {
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler);
    if (!leftType) {
        return nullptr;
    }

    if (!leftType->isOption) {
        return leftVar;
    }

    if (leftType->category != CTC_Value) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "?? requires a value type");
        return nullptr;
    }

    shared_ptr<NBase> right;
    if (leftType->parent.expired()) {
        // Create constant node
        right = make_shared<NConstant>(loc, leftType->getValueType()->defaultValue.c_str(), leftType->getValueType());
    } else {
        // Create call node to create function
        right = make_shared<NCall>(loc, leftType->parent.lock(), nullptr);
    }

    if (leftType->isOption) {
        auto getValueNode = make_shared<NGetValue>(loc, left, true);
        auto ifNode = make_shared<NIf>(loc, make_shared<NIsEmptyOrValid>(loc, left, false), getValueNode, right, true);
        return ifNode->getVar(compiler, scope, dotVar, leftType, returnMode);
    }
    else {
        return leftVar;
    }
}
