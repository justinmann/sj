#include "Node.h"

bool COrVar::getReturnThis() {
    return false;
}

shared_ptr<CType> COrVar::getType(Compiler* compiler, CResult& result) {
    return compiler->typeBool;
}

void COrVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto leftValue = trBlock->createTempStoreVariable(loc, nullptr, compiler->typeBool, "left");
    auto rightValue = trBlock->createTempStoreVariable(loc, nullptr, compiler->typeBool, "right");
    leftVar->transpile(compiler, result, trOutput, trBlock, nullptr, thisValue, leftValue);
    rightVar->transpile(compiler, result, trOutput, trBlock, nullptr, thisValue, rightValue);

    stringstream line;
    line << leftValue->name << " || " << rightValue->name;
    trBlock->statements.push_back(line.str());

    auto resultValue = make_shared<TrValue>(nullptr, compiler->typeBool, line.str());
    storeValue->setValue(compiler, result, trBlock, resultValue);
}

void COrVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    leftVar->dump(compiler, result, nullptr, functions, ss, dotSS, level);
    ss << " && ";
    rightVar->dump(compiler, result, nullptr, functions, ss, dotSS, level);
}

void NOr::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    left->define(compiler, result, thisFunction);
    right->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NOr::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = left->getVar(compiler, result, thisFunction, thisVar, nullptr, CTM_Undefined);
    if (!leftVar) {
        return nullptr;
    }
    auto rightVar = right->getVar(compiler, result, thisFunction, thisVar, nullptr, CTM_Undefined);
    if (!rightVar) {
        return nullptr;
    }
    return make_shared<COrVar>(loc, thisFunction, leftVar, rightVar);
}
