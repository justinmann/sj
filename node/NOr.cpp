#include "Node.h"

shared_ptr<CType> COrVar::getType(Compiler* compiler, CResult& result) {
    return compiler->typeBool;
}

shared_ptr<ReturnValue> COrVar::transpileGet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    auto leftValue = leftVar->transpileGet(compiler, result, trOutput, trBlock, nullptr, thisName);
    auto rightValue = rightVar->transpileGet(compiler, result, trOutput, trBlock, nullptr, thisName);

    auto resultValue = trBlock->createTempVariable(leftValue->type, "result");
    stringstream line;
    line << resultValue->name << " = " << leftValue->name << " || " << rightValue->name;
    trBlock->statements.push_back(line.str());
    return resultValue;
}

void COrVar::transpileSet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName, AssignOp op, bool isFirstAssignment) {
    assert(false);
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
