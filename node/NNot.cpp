#include "Node.h"

void NNot::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NNot::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar) {
    assert(compiler->state == CompilerState::FixVar);
    node->getVar(compiler, result, thisFunction, thisVar);
    return nullptr;
}

shared_ptr<CType> NNot::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeBool;
}

int NNot::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, bool isHeapVar) {
    return node->setHeapVar(compiler, result, thisFunction, thisVar, false);
}

shared_ptr<ReturnValue> NNot::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue) {    
    auto value = node->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, false);
    auto resultValue = trBlock->createTempVariable("result", compiler->typeBool, false, RVR_MustRetain);
    stringstream line;
    line << resultValue->name << " = !" << value->name;
    trBlock->statements.push_back(line.str());
    return resultValue;
}

//shared_ptr<ReturnValue> NNot::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    assert(compiler->state == CompilerState::Compile);
//    compiler->emitLocation(builder, &this->loc);
//    
//    auto v = node->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, RRT_Auto);
//    if (!v)
//        return nullptr;
//    
//    assert(v->type == RVT_SIMPLE);
//    
//    if (!v->value->getType()->isIntegerTy(1)) {
//        result.addError(loc, CErrorCode::TypeMismatch, "must be bool");
//        return nullptr;
//    }
//    
//    return make_shared<ReturnValue>(false, builder->CreateNot(v->value));
//}

void NNot::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "!";
    node->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
}
