#include "Node.h"

shared_ptr<CType> CNotVar::getType(Compiler* compiler, CResult& result) {
    return compiler->typeBool;
}

shared_ptr<ReturnValue> CNotVar::transpileGet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> thisValue) {
    auto value = var->transpileGet(compiler, result, trOutput, trBlock, nullptr, thisValue);
    auto resultValue = trBlock->createTempVariable(compiler->typeBool, "result");
    stringstream line;
    line << resultValue->name << " = !" << value->name;
    trBlock->statements.push_back(line.str());
    return resultValue;
}

void CNotVar::transpileSet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, shared_ptr<ReturnValue> thisValue, AssignOp op, bool isFirstAssignment) {
    assert(false);
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

