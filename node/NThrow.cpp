#include "Node.h"

NodeType NThrow::getNodeType() const {
    return NodeType_Throw;
}

void NThrow::define(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    node->define(compiler, result, thisFunction);
}

void NThrow::fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    node->fixVar(compiler, result, thisFunction);
}

shared_ptr<CType> NThrow::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeVoid;
}

Value* NThrow::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const {
    assert(compiler->state == CompilerState::Compile);
    
    auto value = node->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    assert(value->getType()->isIntegerTy(64));
    compiler->emitLocation(this);
    
    auto raiseException = compiler->exception->getRaiseException();
    auto args = ArrayRef<Value*>(value);
    
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

void NThrow::dump(Compiler* compiler, int level) const {
    dumpf(level, "throw: ''");
}
