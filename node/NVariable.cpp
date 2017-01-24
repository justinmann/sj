#include "Node.h"

shared_ptr<CVar> NVariableBase::getVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar) {
    if (!_hasGetVar) {
        _var = getVarImpl(compiler, result, thisFunction, dotVar);
        _hasGetVar = true;
    }
    return _var;
}


shared_ptr<CParentVar> CParentVar::create(shared_ptr<CFunction> parentFunction_, shared_ptr<CVar> childVar_) {
    auto c = make_shared<CParentVar>();
    c->name = "";
    c->mode = childVar_->mode;
    c->isMutable = childVar_->isMutable;
    c->nassignment = nullptr;
    c->parentFunction = parentFunction_;
    c->childVar = childVar_;
    return c;
}

shared_ptr<CType> CParentVar::getType(Compiler* compiler, CResult& result) {
    return childVar->getType(compiler, result);
}

Value* CParentVar::getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    auto parentPtr = parentFunction->getParentPointer(compiler, result, builder, dotValue);
    if (!parentPtr) {
        return nullptr;
    }
    
    auto parentValue = builder->CreateLoad(parentPtr, "parent");

    return childVar->getLoadValue(compiler, result, thisValue, parentValue, builder, catchBB);
}

Value* CParentVar::getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    auto parentPtr = parentFunction->getParentPointer(compiler, result, builder, dotValue);
    if (!parentPtr) {
        return nullptr;
    }
    
    auto parentValue = builder->CreateLoad(parentPtr, "parent");

    return childVar->getStoreValue(compiler, result, thisValue, parentValue, builder, catchBB);
}

string CParentVar::fullName() {
    return childVar->fullName();
}


NVariable::NVariable(CLoc loc, const char* name) : name(name), NVariableBase(NodeType_Variable, loc) { }

shared_ptr<CVar> NVariable::getVarImpl(Compiler *compiler, CResult &result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar) {
    auto cfunction = thisFunction;
    if (dotVar) {
        cfunction = dotVar->getCFunctionForValue(compiler, result);
    }
    
    return cfunction->getCVar(compiler, result, loc, name);
}

void NVariable::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NVariable'");
    dumpf(level, "name: '%s'", name.c_str());
}

