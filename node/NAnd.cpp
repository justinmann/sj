#include <sjc.h>
#include "Node.h"

bool CAndVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CAndVar::getType(Compiler* compiler) {
    return compiler->typeBool;
}

void CAndVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto leftValue = trBlock->createTempStoreVariable(loc, nullptr, compiler->typeBool, "and");
    auto rightValue = trBlock->createTempStoreVariable(loc, nullptr, compiler->typeBool, "and");
    leftVar->transpile(compiler, trOutput, trBlock, thisValue, leftValue);
    rightVar->transpile(compiler, trOutput, trBlock, thisValue, rightValue);

    stringstream line;
    line << leftValue->getName(trBlock) << " && " << rightValue->getName(trBlock);

    auto resultValue = make_shared<TrValue>(nullptr, compiler->typeBool, line.str(), false);
    storeValue->retainValue(compiler, loc, trBlock, resultValue);
}

void CAndVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    leftVar->dump(compiler, functions, ss, level);
    ss << " && ";
    rightVar->dump(compiler, functions, ss, level);
}

void NAnd::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    left->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    right->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
}

void NAnd::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    left->initVars(compiler, scope, returnMode);
    right->initVars(compiler, scope, returnMode);
}

shared_ptr<CVar> NAnd::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
    auto leftVar = left->getVar(compiler, scope, nullptr, nullptr, CTM_Undefined);
    if (!leftVar) {
        return nullptr;
    }
    auto rightVar = right->getVar(compiler, scope, nullptr, nullptr, CTM_Undefined);
    if (!rightVar) {
        return nullptr;
    }
    return make_shared<CAndVar>(loc, scope, leftVar, rightVar);
}
