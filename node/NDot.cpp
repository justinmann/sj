#include "Node.h"
#include <sstream>

shared_ptr<CDotVar> CDotVar::create(shared_ptr<CVar> leftVar_, shared_ptr<CVar> rightVar_) {
    auto c = make_shared<CDotVar>();
    c->name = "";
    c->mode = rightVar_->mode;
    c->isMutable = rightVar_->isMutable;
    c->nassignment = nullptr;
    c->leftVar = leftVar_;
    c->rightVar = rightVar_;
    return c;
}

shared_ptr<CType> CDotVar::getType(Compiler* compiler, CResult& result) {
    return rightVar->getType(compiler, result);
}

shared_ptr<ReturnValue> CDotVar::getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    auto leftValue = leftVar->getLoadValue(compiler, result, thisValue, dotValue, builder, catchBB);
    if (!leftValue) {
        return nullptr;
    }
    
    auto loadValue = rightVar->getLoadValue(compiler, result, thisValue, leftValue->value, builder, catchBB);
    leftValue->releaseIfNeeded(compiler, result, builder);
    return loadValue;
}

Value* CDotVar::getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    auto leftValue = leftVar->getLoadValue(compiler, result, thisValue, dotValue, builder, catchBB);
    if (!leftValue) {
        return nullptr;
    }

    auto storeValue = rightVar->getStoreValue(compiler, result, thisValue, leftValue->value, builder, catchBB);
    leftValue->releaseIfNeeded(compiler, result, builder);
    return storeValue;
}

string CDotVar::fullName() {
    return leftVar->fullName() + "." + rightVar->fullName();
}

void NDot::defineImpl(Compiler *compiler, CResult &result, shared_ptr<CFunctionDefinition> thisFunction) {
    left->define(compiler, result, thisFunction);
    right->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NDot::getVarImpl(Compiler *compiler, CResult &result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar) {
    auto leftVar = left->getVar(compiler, result, thisFunction, dotVar);
    if (!leftVar) {
        return nullptr;
    }

    auto rightVar = right->getVar(compiler, result, thisFunction, leftVar);
    if (!rightVar) {
        return nullptr;
    }

    return CDotVar::create(leftVar, rightVar);
}

int NDot::setHeapVarImpl(Compiler *compiler, CResult &result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar, bool isHeapVar) {
    auto leftVar = left->getVar(compiler, result, thisFunction, dotVar);
    if (!leftVar) {
        return 0;
    }
    
    auto count = left->setHeapVar(compiler, result, thisFunction, dotVar, false);
    count += right->setHeapVar(compiler, result, thisFunction, leftVar, isHeapVar);
    return count;
}

void NDot::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NDot'");
}

