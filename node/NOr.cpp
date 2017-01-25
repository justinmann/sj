#include "Node.h"

void NOr::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    left->define(compiler, result, thisFunction);
    right->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NOr::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    left->getVar(compiler, result, thisFunction);
    right->getVar(compiler, result, thisFunction);
    return nullptr;
}

shared_ptr<CType> NOr::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeBool;
}

int NOr::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, bool isHeapVar) {
    auto count = left->setHeapVar(compiler, result, thisFunction, false);
    count += right->setHeapVar(compiler, result, thisFunction, false);
    return count;
}

Value* NOr::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    Value *l = left->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    if (!l) {
        return nullptr;
    }
    
    if (!l->getType()->isIntegerTy(1)) {
        result.addError(loc, CErrorCode::TypeMismatch, "must be bool");
        return nullptr;
    }
    
    Value *r = right->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    if (!r) {
        return nullptr;
    }
    
    if (!r->getType()->isIntegerTy(1)) {
        result.addError(loc, CErrorCode::TypeMismatch, "must be bool");
        return nullptr;
    }
    
    return builder->CreateOr(l, r);
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
