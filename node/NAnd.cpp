#include "Node.h"

bool CAndVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CAndVar::getType(Compiler* compiler, CResult& result) {
    return compiler->typeBool;
}

void CAndVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto leftValue = trBlock->createTempStoreVariable(loc, nullptr, compiler->typeBool, "and");
    auto rightValue = trBlock->createTempStoreVariable(loc, nullptr, compiler->typeBool, "and");
    leftVar->transpile(compiler, result, trOutput, trBlock, nullptr, thisValue, leftValue);
    rightVar->transpile(compiler, result, trOutput, trBlock, nullptr, thisValue, rightValue);

    stringstream line;
    line << leftValue->name << " && " << rightValue->name;
    trBlock->statements.push_back(line.str());

    auto resultValue = make_shared<TrValue>(nullptr, compiler->typeBool, line.str());
    storeValue->retainValue(compiler, result, trBlock, resultValue);
}

void CAndVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    leftVar->dump(compiler, result, nullptr, functions, ss, dotSS, level);
    ss << " && ";
    rightVar->dump(compiler, result, nullptr, functions, ss, dotSS, level);
}

void NAnd::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    left->define(compiler, result, thisFunction);
    right->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NAnd::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = left->getVar(compiler, result, thisFunction, thisVar, nullptr, CTM_Undefined);
    if (!leftVar) {
        return nullptr;
    }
    auto rightVar = right->getVar(compiler, result, thisFunction, thisVar, nullptr, CTM_Undefined);
    if (!rightVar) {
        return nullptr;
    }
    return make_shared<CAndVar>(loc, thisFunction, leftVar, rightVar);
}
