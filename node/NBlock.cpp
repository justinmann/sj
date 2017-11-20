#include "Node.h"

bool CBlockVar::getReturnThis() {
    return statements.back()->getReturnThis();
}

shared_ptr<CType> CBlockVar::getType(Compiler* compiler, CResult& result) {
    if (statements.size() == 0) {
        return compiler->typeVoid;
    }
    return statements.back()->getType(compiler, result);
}

void CBlockVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    for (auto it : statements) {
        auto isLastStatement = it == statements.back();
        it->transpile(compiler, result, trOutput, trBlock, nullptr, thisValue, isLastStatement ? storeValue : trBlock->createVoidStoreVariable());
    }
}

void CBlockVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "{\n";
    for (auto it : statements) {
        auto isLastStatement = it == statements.back();
        stringstream line;
        it->dump(compiler, result, nullptr, functions, line, dotSS, level + 1);
        auto t = line.str();
        if (t.size() > 0) {
            dumpf(ss, level + 1);
            ss << t << "\n";
        }
    }
    dumpf(ss, level);
    ss << "}";
}


void NBlock::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    for (auto it : statements) {
        it->define(compiler, result, thisFunction);
    }
}

shared_ptr<CVar> NBlock::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    vector<shared_ptr<CVar>> statementVars;
    for (auto it : statements) {
        auto isLastStatement = it == statements.back();
        auto resultVar = it->getVar(compiler, result, thisFunction, thisVar, isLastStatement ? returnMode : CTM_Undefined);
        if (resultVar) {
            statementVars.push_back(resultVar);
        }
    }
    return make_shared<CBlockVar>(loc, thisFunction, statementVars);
}
