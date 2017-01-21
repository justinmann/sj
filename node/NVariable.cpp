#include "Node.h"

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


NVariable::NVariable(CLoc loc, const char* name) : name(name), NVariableBase(loc) { }

NodeType NVariable::getNodeType() const {
    return NodeType_Variable;
}

void NVariable::fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar) const {
    assert(compiler->state == CompilerState::FixVar);
    getVar(compiler, result, thisFunction, dotVar);
}

string NVariable::getName() const {
    return name;
}

shared_ptr<CVar> NVariable::getVar(Compiler *compiler, CResult &result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar) const {
    shared_ptr<CVar> cvar = nullptr;
    
    auto cfunction = thisFunction;
    if (dotVar) {
        cfunction = dotVar->getCFunctionForValue(compiler, result);
    }
    
    auto parentFunctions = vector<shared_ptr<CFunction>>();
    while (cfunction && !cvar) {
        cvar = cfunction->getCVar(name);
        if (!cvar) {
            if (cfunction) {
                parentFunctions.insert(parentFunctions.begin(), cfunction);
                cfunction = cfunction->parent.lock();
            }
        }
    }
    
    if (cfunction == nullptr) {
        return nullptr;
    }
    
    if (cfunction != thisFunction && cvar->mode == CVarType::Local) {
        cvar = cfunction->localVarToThisVar(compiler, static_pointer_cast<CLocalVar>(cvar));
    }
    
    for (auto it : parentFunctions) {
        cvar = CParentVar::create(it, cvar);
    }
    
    return cvar;
}

void NVariable::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NVariable'");
    dumpf(level, "name: '%s'", name.c_str());
}

