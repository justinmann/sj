#include "Node.h"

void NOr::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    left->define(compiler, result, thisFunction);
    right->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NOr::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);
    left->getVar(compiler, result, thisFunction, thisVar);
    right->getVar(compiler, result, thisFunction, thisVar);
    return nullptr;
}

shared_ptr<CType> NOr::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeBool;
}

int NOr::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    auto count = left->setHeapVar(compiler, result, thisFunction, thisVar, false);
    count += right->setHeapVar(compiler, result, thisFunction, thisVar, false);
    return count;
}

shared_ptr<ReturnValue> NOr::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    auto l = left->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB);
    if (!l) {
        return nullptr;
    }
    
    assert(l->type == RVT_SIMPLE);
    
    if (!l->value->getType()->isIntegerTy(1)) {
        result.addError(loc, CErrorCode::TypeMismatch, "must be bool");
        return nullptr;
    }
    
    auto r = right->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB);
    if (!r) {
        return nullptr;
    }
    
    assert(l->type == RVT_SIMPLE);

    if (!r->value->getType()->isIntegerTy(1)) {
        result.addError(loc, CErrorCode::TypeMismatch, "must be bool");
        return nullptr;
    }
    
    return make_shared<ReturnValue>(builder->CreateOr(l->value, r->value));
}

void NOr::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NOr'");
    
    dumpf(level, "left: {");
    left->dump(compiler, level + 1);
    dumpf(level, "}");

    dumpf(level, "right: {");
    right->dump(compiler, level + 1);
    dumpf(level, "}");
}
