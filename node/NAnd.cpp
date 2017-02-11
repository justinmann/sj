#include "Node.h"

void NAnd::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    left->define(compiler, result, thisFunction);
    right->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NAnd::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);
    left->getVar(compiler, result, thisFunction, thisVar);
    right->getVar(compiler, result, thisFunction, thisVar);
    return nullptr;
}

shared_ptr<CType> NAnd::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeBool;
}

int NAnd::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    auto count = left->setHeapVar(compiler, result, thisFunction, thisVar, false);
    count += right->setHeapVar(compiler, result, thisFunction, thisVar, false);
    return count;
}

shared_ptr<ReturnValue> NAnd::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(builder, this);
    
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
    
    assert(r->type == RVT_SIMPLE);
    
    if (!r->value->getType()->isIntegerTy(1)) {
        result.addError(loc, CErrorCode::TypeMismatch, "must be bool");
        return nullptr;
    }
    
    return make_shared<ReturnValue>(builder->CreateAnd(l->value, r->value));
}

void NAnd::dump(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CFunction>, string>& functions, stringstream& ss, int level) {
    left->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
    ss << " && ";
    right->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
}
