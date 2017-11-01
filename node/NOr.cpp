#include "Node.h"

void NOr::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    left->define(compiler, result, thisFunction);
    right->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NOr::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);
    left->getVar(compiler, result, thisFunction, thisVar);
    right->getVar(compiler, result, thisFunction, thisVar);
    return nullptr;
}

shared_ptr<CType> NOr::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeBool;
}

int NOr::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    auto count = left->setHeapVar(compiler, result, thisFunction, thisVar, false);
    count += right->setHeapVar(compiler, result, thisFunction, thisVar, false);
    return count;
}

shared_ptr<CType> NOr::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, stringstream& trLine) {
	assert(false);
	return nullptr;
}

//shared_ptr<ReturnValue> NOr::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    assert(compiler->state == CompilerState::Compile);
//    compiler->emitLocation(builder, &this->loc);
//    
//    auto l = left->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, RRT_Auto);
//    if (!l) {
//        return nullptr;
//    }
//    
//    assert(l->type == RVT_SIMPLE);
//    
//    if (!l->value->getType()->isIntegerTy(1)) {
//        result.addError(loc, CErrorCode::TypeMismatch, "must be bool");
//        return nullptr;
//    }
//    
//    auto r = right->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, RRT_Auto);
//    if (!r) {
//        return nullptr;
//    }
//    
//    assert(l->type == RVT_SIMPLE);
//
//    if (!r->value->getType()->isIntegerTy(1)) {
//        result.addError(loc, CErrorCode::TypeMismatch, "must be bool");
//        return nullptr;
//    }
//    
//    return make_shared<ReturnValue>(false, builder->CreateOr(l->value, r->value));
//}

void NOr::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    left->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
    ss << " || ";
    right->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
}
