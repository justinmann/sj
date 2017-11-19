#include "Node.h"
#include <sstream>

shared_ptr<CDotVar> CDotVar::create(CLoc loc, shared_ptr<CVar> leftVar_, shared_ptr<CVar> rightVar_) {
    auto c = make_shared<CDotVar>(loc);
//    c->name = "";
//    c->mode = rightVar_->mode;
//    c->isMutable = rightVar_->isMutable;
//    c->nassignment = nullptr;
    c->leftVar = leftVar_;
    c->rightVar = rightVar_;
    return c;
}

shared_ptr<CType> CDotVar::getType(Compiler* compiler, CResult& result, CTypeMode returnMode) {
    return rightVar->getType(compiler, result, CTM_Undefined);
}

//string CDotVar::fullName() {
//    return leftVar->fullName() + "." + rightVar->fullName();
//}

shared_ptr<ReturnValue> CDotVar::transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName) {
	auto leftValue = leftVar->transpileGet(compiler, result, thisFunction, thisVar, trOutput, trBlock, CTM_Undefined, dotValue, thisName);
	return rightVar->transpileGet(compiler, result, thisFunction, thisVar, trOutput, trBlock, returnMode, leftValue, thisName);
}

void CDotVar::transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) {
    auto leftValue = leftVar->transpileGet(compiler, result, thisFunction, thisVar, trOutput, trBlock, CTM_Undefined, dotValue, thisName);
    rightVar->transpileSet(compiler, result, thisFunction, thisVar, trOutput, trBlock, leftValue, returnValue, thisName);
}


void CDotVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    stringstream temp;
    leftVar->dump(compiler, result, thisFunction, thisVar, CTM_Undefined, dotVar, functions, temp, dotSS, level);
    rightVar->dump(compiler, result, thisFunction, thisVar, returnMode, leftVar, functions, ss, temp, level);
}

void NDot::defineImpl(Compiler *compiler, CResult &result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    left->define(compiler, result, thisFunction);
    right->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NDot::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar) {
    auto leftVar = left->getVar(compiler, result, thisFunction, thisVar, dotVar);
    if (!leftVar) {
        result.addError(loc, CErrorCode::InvalidDot, "left side of dot has no value");
        return nullptr;
    }

    auto rightVar = right->getVar(compiler, result, thisFunction, thisVar, leftVar);
    if (!rightVar) {
        result.addError(loc, CErrorCode::InvalidDot, "right side of dot has no value");
        return nullptr;
    }

    return CDotVar::create(loc, leftVar, rightVar);
}
