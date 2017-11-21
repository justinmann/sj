#include "Node.h"

bool CNotVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CNotVar::getType(Compiler* compiler, CResult& result) {
    return compiler->typeBool;
}

void CNotVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto value = trBlock->createTempStoreVariable(loc, nullptr, compiler->typeBool, "not");
    var->transpile(compiler, result, trOutput, trBlock, nullptr, thisValue, value);
    auto resultValue = trBlock->createTempVariable(nullptr, compiler->typeBool, "result");
    stringstream line;
    line << resultValue->name << " = !" << value->name;
    trBlock->statements.push_back(line.str());
    storeValue->retainValue(compiler, result, trBlock, resultValue);
}

void CNotVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "!";
    var->dump(compiler, result, nullptr, functions, ss, dotSS, level);
}

void NNot::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NNot::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto var = node->getVar(compiler, result, thisFunction, thisVar, CTM_Undefined);
    if (!var) {
        return nullptr;
    }
    return make_shared<CNotVar>(loc, thisFunction, var);
}

