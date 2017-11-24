#include "Node.h"

bool CAndVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CAndVar::getType(Compiler* compiler) {
    return compiler->typeBool;
}

void CAndVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto leftValue = trBlock->createTempStoreVariable(loc, nullptr, compiler->typeBool, "and");
    auto rightValue = trBlock->createTempStoreVariable(loc, nullptr, compiler->typeBool, "and");
    leftVar->transpile(compiler, trOutput, trBlock, nullptr, thisValue, leftValue);
    rightVar->transpile(compiler, trOutput, trBlock, nullptr, thisValue, rightValue);

    stringstream line;
    line << leftValue->getName(trBlock) << " && " << rightValue->getName(trBlock);
    trBlock->statements.push_back(line.str());

    auto resultValue = make_shared<TrValue>(nullptr, compiler->typeBool, line.str(), false);
    storeValue->retainValue(compiler, loc, trBlock, resultValue);
}

void CAndVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    leftVar->dump(compiler, nullptr, functions, ss, dotSS, level);
    ss << " && ";
    rightVar->dump(compiler, nullptr, functions, ss, dotSS, level);
}

void NAnd::defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    left->define(compiler, thisFunction);
    right->define(compiler, thisFunction);
}

shared_ptr<CVar> NAnd::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = left->getVar(compiler, scope, nullptr, CTM_Undefined);
    if (!leftVar) {
        return nullptr;
    }
    auto rightVar = right->getVar(compiler, scope, nullptr, CTM_Undefined);
    if (!rightVar) {
        return nullptr;
    }
    return make_shared<CAndVar>(loc, scope, leftVar, rightVar);
}
