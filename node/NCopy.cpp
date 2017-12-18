#include "Node.h"

bool CCopyVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CCopyVar::getType(Compiler* compiler) {
    auto type = var->getType(compiler);
    if (type->typeMode == CTM_Value) {
        return type;
    }
    else if (type->typeMode != CTM_Heap) {
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
        auto rightValue = trBlock->createTempStoreVariable(loc, scope.lock(), type->typeMode == CTM_Heap ? type : type->getLocalType(), "copy");
        var->transpile(compiler, trOutput, trBlock, thisValue, rightValue);
        
        if (storeValue->op.isFirstAssignment) {
            storeValue->getValue()->addInitToStatements(trBlock);
        } else {
            storeValue->getValue()->addReleaseToStatements(trBlock);
        }
        
        if (!type->parent.expired()) {
            if (type->isOption) {
                assert(false);
            }

            stringstream lineStream;
            lineStream << type->parent.lock()->getCCopyFunctionName() << "(" << TrValue::convertToLocalName(storeValue->type, storeValue->getName(trBlock), storeValue->isReturnValue) << ", " << TrValue::convertToLocalName(rightValue->type, rightValue->getName(trBlock), rightValue->isReturnValue) << ")";
            trBlock->statements.push_back(TrStatement(loc, lineStream.str()));
        }
        else if (type->category == CTC_Function) {
            type->callback.lock()->writeCopy(trBlock, rightValue->getName(trBlock), storeValue->getName(trBlock), type->typeMode == CTM_Heap);
        }
        
        storeValue->hasSetValue = true;
    }
}

void CCopyVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "copy ";
    var->dump(compiler, functions, ss, level);
}

void NCopy::defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, importNamespaces, packageNamespace, thisFunction);
}

shared_ptr<CVar> NCopy::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = node->getVar(compiler, scope, CTM_Undefined);
    if (!leftVar) {
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler);
    if (!leftType) {
        return nullptr;
    }

    if (leftType->isOption) {
        auto getValueVar = make_shared<CGetValueVar>(loc, leftVar->scope.lock(), leftVar, true);
        auto copyVar = make_shared<CCopyVar>(loc, scope, getValueVar, returnMode);
        auto valueVar = make_shared<CValueVar>(loc, scope, copyVar);
        auto emptyVar = make_shared<CEmptyVar>(loc, leftType, scope);
        auto isEmptyVar = make_shared<CIsEmptyVar>(loc, scope, leftVar);
        return make_shared<CIfElseVar>(loc, scope, isEmptyVar, emptyVar, nullptr, valueVar, nullptr);
    }
    else {
        return make_shared<CCopyVar>(loc, scope, leftVar, returnMode);
    }
}
