#include <sjc.h>
#include "Node.h"

bool COrVar::getReturnThis() {
    return false;
}

shared_ptr<CType> COrVar::getType(Compiler* compiler) {
    return compiler->typeBool;
}

void COrVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto leftValue = trBlock->createCaptureStoreVariable(loc, nullptr, compiler->typeBool);
    auto rightValue = trBlock->createCaptureStoreVariable(loc, nullptr, compiler->typeBool);
    leftVar->transpile(compiler, trOutput, trBlock, thisValue, leftValue);
    rightVar->transpile(compiler, trOutput, trBlock, thisValue, rightValue);

    stringstream line;
    line << leftValue->getCaptureText() << " || " << rightValue->getCaptureText();

    auto resultValue = make_shared<TrValue>(nullptr, compiler->typeBool, line.str(), false);
    storeValue->retainValue(compiler, loc, trBlock, resultValue);
}

void COrVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    leftVar->dump(compiler, functions, ss, level);
    ss << " || ";
    rightVar->dump(compiler, functions, ss, level);
}

void NOr::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    left->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    right->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
}

void NOr::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    left->initVars(compiler, scope, returnMode);
    right->initVars(compiler, scope, returnMode);
}

shared_ptr<CVar> NOr::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
    auto leftVar = left->getVar(compiler, scope, nullptr, compiler->typeBool, CTM_Undefined);
    if (!leftVar) {
        return nullptr;
    }
    auto rightVar = right->getVar(compiler, scope, nullptr, compiler->typeBool, CTM_Undefined);
    if (!rightVar) {
        return nullptr;
    }
    return make_shared<COrVar>(loc, scope, leftVar, rightVar);
}
