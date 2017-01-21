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

Value* CDotVar::getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    auto leftValue = leftVar->getLoadValue(compiler, result, thisValue, dotValue, builder, catchBB);
    if (!leftValue) {
        return nullptr;
    }
    
    return rightVar->getLoadValue(compiler, result, thisValue, leftValue, builder, catchBB);
}

Value* CDotVar::getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    auto leftValue = leftVar->getLoadValue(compiler, result, thisValue, dotValue, builder, catchBB);
    if (!leftValue) {
        return nullptr;
    }

    return rightVar->getStoreValue(compiler, result, thisValue, leftValue, builder, catchBB);
}

string CDotVar::fullName() {
    return leftVar->fullName() + "." + rightVar->fullName();
}

NodeType NDot::getNodeType() const {
    return NodeType_Dot;
}

void NDot::define(Compiler *compiler, CResult &result, shared_ptr<CFunctionDefinition> thisFunction) {
    left->define(compiler, result, thisFunction);
    right->define(compiler, result, thisFunction);
}

void NDot::fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar) const {
    assert(compiler->state == CompilerState::FixVar);
    
    left->fixVar(compiler, result, thisFunction, dotVar);
    auto leftVar = left->getVar(compiler, result, thisFunction, dotVar);
    right->fixVar(compiler, result, thisFunction, leftVar);
}

string NDot::getName() const {
    return left->getName() + "." + right->getName();
}

shared_ptr<CVar> NDot::getVar(Compiler *compiler, CResult &result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar) const {
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

void NDot::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NDot'");
}

