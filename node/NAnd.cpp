#include "Node.h"

shared_ptr<CType> CAndVar::getType(Compiler* compiler, CResult& result) {
    return compiler->typeBool;
}

shared_ptr<ReturnValue> CAndVar::transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    auto leftValue = leftVar->transpileGet(compiler, result, thisFunction, thisVar, trOutput, trBlock, CTRM_NoPref, nullptr, thisName);
    auto rightValue = rightVar->transpileGet(compiler, result, thisFunction, thisVar, trOutput, trBlock, CTRM_NoPref, nullptr, thisName);

    auto resultValue = trBlock->createTempVariable(leftValue->type, "result");
    stringstream line;
    line << resultValue->name << " = " << leftValue->name << " && " << rightValue->name;
    trBlock->statements.push_back(line.str());
    return resultValue;
}

void CAndVar::transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) {
    assert(false);
}

void CAndVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeReturnMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    leftVar->dump(compiler, result, thisFunction, thisVar, returnMode, nullptr, functions, ss, dotSS, level);
    ss << " && ";
    rightVar->dump(compiler, result, thisFunction, thisVar, returnMode, nullptr, functions, ss, dotSS, level);
}

void NAnd::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    left->define(compiler, result, thisFunction);
    right->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NAnd::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar) {
    assert(compiler->state == CompilerState::FixVar);
    auto leftVar = left->getVar(compiler, result, thisFunction, thisVar, nullptr);
    if (!leftVar) {
        return nullptr;
    }
    auto rightVar = right->getVar(compiler, result, thisFunction, thisVar, nullptr);
    if (!rightVar) {
        return nullptr;
    }
    return make_shared<CAndVar>(loc, leftVar, rightVar);
}
