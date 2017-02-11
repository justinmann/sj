#include "Node.h"

void NThrow::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NThrow::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    node->getVar(compiler, result, thisFunction, thisVar);
    return nullptr;
}

shared_ptr<CType> NThrow::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeVoid;
}

int NThrow::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    return node->setHeapVar(compiler, result, thisFunction, thisVar, true);
}

shared_ptr<ReturnValue> NThrow::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    
    auto value = node->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB);
    assert(value->value->getType()->isIntegerTy(64));
    compiler->emitLocation(builder, this);
    
    auto raiseException = compiler->exception->getRaiseException();
    auto args = ArrayRef<Value*>(value->value);
    
    if (catchBB) {
        auto continueBB = BasicBlock::Create(compiler->context);
        builder->CreateInvoke(raiseException, continueBB, catchBB, args);
        
        Function *function = builder->GetInsertBlock()->getParent();
        function->getBasicBlockList().push_back(continueBB);
        builder->SetInsertPoint(continueBB);
    } else {
        builder->CreateCall(raiseException, args);
    }
    return nullptr;
}

void NThrow::dump(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CFunction>, string>& functions, stringstream& ss, int level) {
    ss << "throw";
}
