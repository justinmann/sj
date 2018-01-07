#include <sjc.h>


bool CCopyVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CCopyVar::getType(Compiler* compiler) {
    auto type = var->getType(compiler);
    if (type->typeMode == CTM_Value) {
        return type;
    }
    else if (returnMode != CTM_Heap) {
        return type->getStackType();
    }
    else {
        return type->getHeapType();
    }
}

void CCopyVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto type = getType(compiler);
    if (type->typeMode == CTM_Value) {
        var->transpile(compiler, trOutput, trBlock, thisValue, storeValue);
    }
    else {
        auto destType = returnMode == CTM_Heap ? type->getHeapType() : type->getStackType();
        auto rightValue = trBlock->createCaptureStoreVariable(loc, scope.lock(), type->getTempType());
        var->transpile(compiler, trOutput, trBlock, thisValue, rightValue);

        if (!CType::isSameExceptMode(rightValue->type, storeValue->type)) {
            compiler->addError(loc, CErrorCode::InvalidType, "right type '%s' does not match left type '%s'", storeValue->type->fullName.c_str(), rightValue->type->fullName.c_str());
            return;
        }

        if (!storeValue->op.isFirstAssignment) {
            storeValue->getValue()->addReleaseToStatements(compiler, trBlock);
            storeValue->getValue()->addDestroyToStatements(compiler, trBlock);
        }

        storeValue->getValue()->addInitToStatements(compiler, trBlock);
        if (!type->parent.expired()) {
            if (type->isOption) {
                assert(false);
            }

            stringstream lineStream;
            lineStream << type->parent.lock()->getCCopyFunctionName() << "(";
            lineStream << TrValue::convertToLocalName(storeValue->type, storeValue->getName(trBlock), storeValue->isReturnValue);
            lineStream << ", " << TrValue::convertToLocalName(rightValue->type, rightValue->getCaptureText(), rightValue->isReturnValue) << ")";
            trBlock->statements.push_back(TrStatement(loc, lineStream.str()));
        }
        else if (type->category == CTC_Function) {
            type->callback.lock()->writeCopy(compiler, trBlock, rightValue->getCaptureText(), storeValue->getName(trBlock), type->typeMode == CTM_Heap);
        }
        
        storeValue->hasSetValue = true;
    }
}

void CCopyVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "copy ";
    var->dump(compiler, functions, ss, level);
}

void NCopy::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    node->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
}

void NCopy::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    node->initVars(compiler, scope, returnMode);
}

shared_ptr<CVar> NCopy::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
    auto leftVar = node->getVar(compiler, scope, returnType, returnMode);
    if (!leftVar) {
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler);
    if (!leftType) {
        return nullptr;
    }

    if (leftType->category == CTC_Function) {
        compiler->addError(loc, CErrorCode::InvalidType, "cannot copy callbacks");
        return nullptr;
    }

    if (leftType->category == CTC_Interface) {
        compiler->addError(loc, CErrorCode::InvalidType, "cannot copy interfaces");
        return nullptr;
    }

    if (!alwaysCopy) {
        if (returnMode == CTM_Undefined || leftType->typeMode == returnMode || leftType->typeMode == CTM_Value) {
            return leftVar;
        }
    }

    if (leftType->isOption) {
        auto getValueVar = make_shared<CGetValueVar>(loc, leftVar->scope.lock(), leftVar, true);
        auto copyVar = make_shared<CCopyVar>(loc, scope, getValueVar, returnMode);
        auto valueVar = make_shared<CValueVar>(loc, scope, copyVar);
        auto emptyType = valueVar->getType(compiler);
        auto emptyVar = make_shared<CEmptyVar>(loc, emptyType, scope);
        auto isValidVar = make_shared<CIsEmptyOrValidVar>(loc, scope, leftVar, false);
        return make_shared<CIfElseVar>(loc, scope, isValidVar, valueVar, nullptr, emptyVar, nullptr);
    }
    else {
        return make_shared<CCopyVar>(loc, scope, leftVar, returnMode);
    }
}
