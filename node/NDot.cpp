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

//shared_ptr<ReturnValue> CDotVar::getLoadValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    auto leftValue = leftVar->getLoadValue(compiler, result, thisVar, thisValue, dotInEntry, dotValue, builder, catchBB, RRT_Auto);
//    if (!leftValue) {
//        return nullptr;
//    }
//    
//    auto loadValue = rightVar->getLoadValue(compiler, result, thisVar, thisValue, leftValue->inEntry, leftValue->value, builder, catchBB, returnRefType);
//    leftValue->releaseIfNeeded(compiler, result, builder);
//    return loadValue;
//}

//Value* CDotVar::getStoreValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
//    auto leftValue = leftVar->getLoadValue(compiler, result, thisVar, thisValue, dotInEntry, dotValue, builder, catchBB, RRT_Auto);
//    if (!leftValue) {
//        return nullptr;
//    }
//
//    auto storeValue = rightVar->getStoreValue(compiler, result, thisVar, thisValue, leftValue->inEntry, leftValue->value, builder, catchBB);
//    leftValue->releaseIfNeeded(compiler, result, builder);
//    return storeValue;
//}

string CDotVar::fullName() {
    return leftVar->fullName() + "." + rightVar->fullName();
}

bool CDotVar::getHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    return rightVar->getHeapVar(compiler, result, leftVar);
}

int CDotVar::setHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    return rightVar->setHeapVar(compiler, result, leftVar);
}

shared_ptr<CType> CDotVar::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* output, TrFunction* function, stringstream& line) {
    assert(false);
	return nullptr;
}

void CDotVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    stringstream temp;
    leftVar->dump(compiler, result, thisFunction, thisVar, dotVar, functions, temp, dotSS, level);
    rightVar->dump(compiler, result, thisFunction, thisVar, leftVar, functions, ss, temp, level);
}

void NDot::defineImpl(Compiler *compiler, CResult &result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    left->define(compiler, result, thisFunction);
    right->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NDot::getVarImpl(Compiler *compiler, CResult &result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar) {
    auto leftVar = left->getVar(compiler, result, thisFunction, thisVar, dotVar);
    if (!leftVar) {
        return nullptr;
    }

    auto rightVar = right->getVar(compiler, result, thisFunction, thisVar, leftVar);
    if (!rightVar) {
        return nullptr;
    }

    return CDotVar::create(leftVar, rightVar);
}

int NDot::setHeapVarImpl(Compiler *compiler, CResult &result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, bool isHeapVar) {
    auto leftVar = left->getVar(compiler, result, thisFunction, thisVar, dotVar);
    if (!leftVar) {
        return 0;
    }
    
    auto count = left->setHeapVar(compiler, result, thisFunction, thisVar, dotVar, false);
    count += right->setHeapVar(compiler, result, thisFunction, thisVar, leftVar, isHeapVar);
    return count;
}

shared_ptr<CType> NDot::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* output, TrFunction* function, stringstream& line) {
	assert(false);
	return nullptr;
}

