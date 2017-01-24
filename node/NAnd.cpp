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

Value* NAnd::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
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
    
    return builder->CreateAnd(l, r);
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
