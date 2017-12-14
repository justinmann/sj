#include "Node.h"

bool CNotVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CNotVar::getType(Compiler* compiler) {
    return compiler->typeBool;
}

void CNotVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto value = trBlock->createTempStoreVariable(loc, nullptr, compiler->typeBool, "not");
    var->transpile(compiler, trOutput, trBlock, thisValue, value);
    auto resultValue = trBlock->createTempVariable(nullptr, compiler->typeBool, "result");
    stringstream line;
    line << resultValue->name << " = !" << value->getName(trBlock);
    trBlock->statements.push_back(TrStatement(loc, line.str()));
    storeValue->retainValue(compiler, loc, trBlock, resultValue);
}

void CNotVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "!";
    var->dump(compiler, functions, ss, level);
}

void NNot::defineImpl(Compiler* compiler, vector<vector<string>>& namespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, namespaces, packageNamespace, thisFunction);
}

shared_ptr<CVar> NNot::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto var = node->getVar(compiler, scope, CTM_Undefined);
    if (!var) {
        return nullptr;
    }
    return make_shared<CNotVar>(loc, scope, var);
}

