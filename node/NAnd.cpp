#include "Node.h"

void NAnd::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    left->define(compiler, result, thisFunction);
    right->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NAnd::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    left->getVar(compiler, result, thisFunction);
    right->getVar(compiler, result, thisFunction);
    return nullptr;
}

shared_ptr<CType> NAnd::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeBool;
}

int NAnd::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, bool isHeapVar) {
    auto count = left->setHeapVar(compiler, result, thisFunction, false);
    count += right->setHeapVar(compiler, result, thisFunction, false);
    return count;
}

shared_ptr<ReturnValue> NAnd::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    auto l = left->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    if (!l) {
        return nullptr;
    }
    
    assert(l->type == RVT_SIMPLE);

    if (!l->value->getType()->isIntegerTy(1)) {
        result.addError(loc, CErrorCode::TypeMismatch, "must be bool");
        return nullptr;
    }
    
    auto r = right->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    if (!r) {
        return nullptr;
    }
    
    assert(r->type == RVT_SIMPLE);
    
    if (!r->value->getType()->isIntegerTy(1)) {
        result.addError(loc, CErrorCode::TypeMismatch, "must be bool");
        return nullptr;
    }
    
    return make_shared<ReturnValue>(builder->CreateAnd(l->value, r->value));
}

void NAnd::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NAnd'");
    
    dumpf(level, "left: {");
    left->dump(compiler, level + 1);
    dumpf(level, "}");

    dumpf(level, "right: {");
    right->dump(compiler, level + 1);
    dumpf(level, "}");
}
