#include "Node.h"

NodeType NOr::getNodeType() const {
    return NodeType_Or;
}

void NOr::define(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    left->define(compiler, result, thisFunction);
    right->define(compiler, result, thisFunction);
}

void NOr::fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    left->fixVar(compiler, result, thisFunction);
    right->fixVar(compiler, result, thisFunction);
}

shared_ptr<CType> NOr::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeBool;
}

Value* NOr::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const {
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
