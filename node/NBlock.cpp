#include "Node.h"

shared_ptr<CType> CBlockVar::getType(Compiler* compiler, CResult& result) {
    if (statements.size() == 0) {
        return compiler->typeVoid;
    }
    return statements.back()->getType(compiler, result);
}

shared_ptr<ReturnValue> CBlockVar::transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    shared_ptr<ReturnValue> returnValue;
    
    for (auto it : statements) {
        auto isLastStatement = it == statements.back();
        returnValue = it->transpileGet(compiler, result, thisFunction, thisVar, trOutput, trBlock, isLastStatement ? returnMode : CTM_Undefined, nullptr, thisName);
    }
    
    return returnValue;
}

void CBlockVar::transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) {
    assert(false);
}

void CBlockVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "{\n";
    for (auto it : statements) {
        auto isLastStatement = it == statements.back();
        stringstream line;
        it->dump(compiler, result, thisFunction, thisVar, isLastStatement ? returnMode : CTM_Undefined, nullptr, functions, line, dotSS, level + 1);
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

shared_ptr<CVar> NBlock::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar) {
    vector<shared_ptr<CVar>> statementVars;
    for (auto it : statements) {
        auto resultVar = it->getVar(compiler, result, thisFunction, thisVar);
        if (resultVar) {
            statementVars.push_back(resultVar);
        }
    }
    return make_shared<CBlockVar>(loc, statementVars);
}
