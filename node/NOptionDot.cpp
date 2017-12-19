#include "Node.h"

void NOptionDot::defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    left->define(compiler, importNamespaces, packageNamespace, thisFunction);
    right->define(compiler, importNamespaces, packageNamespace, thisFunction);
}

shared_ptr<CVar> NOptionDot::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = left->getVar(compiler, scope, dotVar, CTM_Undefined);
    if (!leftVar) {
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler);
    if (!leftType) {
        return nullptr;
    }

    if (!leftType->isOption) {
        auto rightVar = right->getVar(compiler, scope, leftVar, returnMode);
        if (!rightVar) {
            compiler->addError(loc, CErrorCode::InvalidDot, "right side of dot has no value");
            return nullptr;
        }
        return rightVar;
    }
    else {
        auto getValueNode = make_shared<NGetValue>(loc, left, true);
        auto localDotNode = make_shared<NDot>(loc, getValueNode, right);
        auto localDotVar = localDotNode->getVar(compiler, scope, dotVar, CTM_Undefined);
        if (!localDotVar) {
            return nullptr;
        }
        auto ctype = localDotVar->getType(compiler);
        if (ctype == compiler->typeVoid) {
            auto ifNode = make_shared<NIf>(loc, make_shared<NNot>(loc, make_shared<NIsEmpty>(loc, left)), localDotNode, nullptr);
            return ifNode->getVar(compiler, scope, dotVar, returnMode);
        }
        else {
            shared_ptr<NBase> valueNode;
            if (!ctype->isOption) {
                valueNode = make_shared<NValue>(loc, localDotNode);
                ctype = ctype->getOptionType();
            }
            else {
                valueNode = localDotNode;
            }

            if (!ctype) {
                compiler->addError(loc, CErrorCode::TypeMismatch, "cannot find type");
                return nullptr;
            }

            auto emptyNode = make_shared<NEmpty>(loc, make_shared<CTypeName>(ctype));
            auto ifNode = make_shared<NIf>(loc, make_shared<NIsEmpty>(loc, left), emptyNode, valueNode);
            return ifNode->getVar(compiler, scope, dotVar, returnMode);
        }
    }
}
