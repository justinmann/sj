#include "Node.h"
#include <sstream>

shared_ptr<CDotVar> CDotVar::create(CLoc loc, shared_ptr<CBaseFunction> scope, shared_ptr<CVar> leftVar_, shared_ptr<CVar> rightVar_) {
    auto c = make_shared<CDotVar>(loc, scope);
    c->leftVar = leftVar_;
    c->rightVar = rightVar_;
    return c;
}

shared_ptr<CType> CDotVar::getType(Compiler* compiler, CResult& result) {
    return rightVar->getType(compiler, result);
}

shared_ptr<ReturnValue> CDotVar::transpileGet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> thisValue) {
	auto leftValue = leftVar->transpileGet(compiler, result, trOutput, trBlock, dotValue, thisValue);
	return rightVar->transpileGet(compiler, result, trOutput, trBlock, leftValue, thisValue);
}

void CDotVar::transpileSet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, shared_ptr<ReturnValue> thisValue, AssignOp op, bool isFirstAssignment) {
    auto leftValue = leftVar->transpileGet(compiler, result, trOutput, trBlock, dotValue, thisValue);
    rightVar->transpileSet(compiler, result, trOutput, trBlock, leftValue, returnValue, thisValue, op, isFirstAssignment);
}


void CDotVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    stringstream temp;
    leftVar->dump(compiler, result, dotVar, functions, temp, dotSS, level);
    rightVar->dump(compiler, result, leftVar, functions, ss, temp, level);
}

void NDot::defineImpl(Compiler *compiler, CResult &result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    left->define(compiler, result, thisFunction);
    right->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NDot::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = left->getVar(compiler, result, thisFunction, thisVar, dotVar, CTM_Undefined);
    if (!leftVar) {
        result.addError(loc, CErrorCode::InvalidDot, "left side of dot has no value");
        return nullptr;
    }

    auto rightVar = right->getVar(compiler, result, thisFunction, thisVar, leftVar, returnMode);
    if (!rightVar) {
        result.addError(loc, CErrorCode::InvalidDot, "right side of dot has no value");
        return nullptr;
    }

    return CDotVar::create(loc, rightVar->scope.lock(), leftVar, rightVar);
}
