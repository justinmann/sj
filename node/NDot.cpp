#include "Node.h"
#include <sstream>

shared_ptr<CDotVar> CDotVar::create(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> leftVar_, shared_ptr<CVar> rightVar_) {
    assert(leftVar_);
    assert(rightVar_);
    auto c = make_shared<CDotVar>(loc, scope);
    c->leftVar = leftVar_;
    c->rightVar = rightVar_;
    return c;
}

bool CDotVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CDotVar::getType(Compiler* compiler) {
    return rightVar->getType(compiler);
}

void CDotVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto leftValue = trBlock->createTempStoreVariable(loc, nullptr, leftVar->getType(compiler)->getLocalType(), "dot");
    leftVar->transpile(compiler, trOutput, trBlock, dotValue, thisValue, leftValue);
	rightVar->transpile(compiler, trOutput, trBlock, leftValue->getValue(), thisValue, storeValue);
}

bool CDotVar::getCanStoreValue() {
    auto rightStoreVar = dynamic_pointer_cast<CStoreVar>(rightVar);
    if (rightStoreVar) {
        return rightStoreVar->getCanStoreValue();
    }
    return false;
}

shared_ptr<TrStoreValue> CDotVar::getStoreValue(Compiler* compiler, shared_ptr<CScope> scope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, AssignOp op, bool isFirstAssignment) {
    auto leftValue = trBlock->createTempStoreVariable(loc, nullptr, leftVar->getType(compiler)->getLocalType(), "dot");
    leftVar->transpile(compiler, trOutput, trBlock, dotValue, thisValue, leftValue);
    auto rightStoreVar = dynamic_pointer_cast<CStoreVar>(rightVar);
    if (!rightStoreVar) {
        compiler->addError(loc, CErrorCode::InvalidType, "right side cannot set value");
        return nullptr;
    }
    return rightStoreVar->getStoreValue(compiler, scope, trOutput, trBlock, leftValue->getValue(), thisValue, op, isFirstAssignment);
}

void CDotVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    stringstream temp;
    leftVar->dump(compiler, dotVar, functions, temp, dotSS, level);
    rightVar->dump(compiler, leftVar, functions, ss, temp, level);
}

void NDot::defineImpl(Compiler *compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    left->define(compiler, thisFunction);
    right->define(compiler, thisFunction);
}

shared_ptr<CVar> NDot::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = left->getVar(compiler, scope, dotVar, CTM_Undefined);
    if (!leftVar) {
        compiler->addError(loc, CErrorCode::InvalidDot, "left side of dot has no value");
        return nullptr;
    }

    auto rightVar = right->getVar(compiler, scope, leftVar, returnMode);
    if (!rightVar) {
        compiler->addError(loc, CErrorCode::InvalidDot, "right side of dot has no value");
        return nullptr;
    }

    return CDotVar::create(loc, rightVar->scope.lock(), leftVar, rightVar);
}
