#include "Node.h"

void CBaseFunction::setHasRefCount() {
    hasRefCount = true;
}

bool CBaseFunction::getHasParent(Compiler* compiler, CResult& result) {
    getThisType(compiler, result);
    return hasParent;
}

void CBaseFunction::setHasParent(Compiler* compiler, CResult& result) {
    if (parent.expired()) {
        return;
    }
    
    if (parent.lock()->getThisType(compiler, result) == nullptr) {
        return;
    }
    
    // Force parent to have a "this" struct
    parent.lock()->setHasRefCount();
    
    if (!hasParent) {
        getThisType(compiler, result);
        hasParent = true;
        
        for (auto it : delegateHasParent) {
            it(compiler, result);
        }
    }
}

void CBaseFunction::onHasParent(std::function<void(Compiler*, CResult&)> notify) {
    delegateHasParent.push_back(notify);
}

//void CBaseFunction::initStack(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
//    compiler->recordRetain(builder, thisValue, name);
//    if (hasRefCount) {
//        auto refCount = getRefCount(compiler, result, builder, thisValue);
//        assert(refCount);
//        builder->CreateStore(ConstantInt::get(compiler->context, APInt(64, STACK_REF_COUNT + 1)), refCount);
//    }
//}

//void CBaseFunction::initHeap(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
//    assert(hasRefCount);
//    compiler->recordRetain(builder, thisValue, name);
//    
//    auto refCount = getRefCount(compiler, result, builder, thisValue);
//    assert(refCount);
//    builder->CreateStore(ConstantInt::get(compiler->context, APInt(64, 1)), refCount);
//}
//
//void CBaseFunction::retainStack(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
//    assert(hasRefCount);
//    compiler->recordRetain(builder, thisValue, name);
//    
//    auto refCount = getRefCount(compiler, result, builder, thisValue);
//    assert(refCount);
//    auto foo = builder->CreateAdd(refCount, ConstantInt::get(compiler->context, APInt(64, 1)));
//    builder->CreateStore(foo, refCount);
//}
//
//void CBaseFunction::retainHeap(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
//    assert(hasRefCount);
//    compiler->recordRetain(builder, thisValue, name);
//    
//    auto refCount = getRefCount(compiler, result, builder, thisValue);
//    assert(refCount);
//    auto load = builder->CreateLoad(refCount);
//    auto add = builder->CreateAdd(load, ConstantInt::get(compiler->context, APInt(64, 1)));
//    builder->CreateStore(add, refCount);
//}
//
//void CBaseFunction::releaseStack(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
//    compiler->recordRelease(builder, thisValue, name);
//    
//#ifdef DEBUG_CALLSTACK
//    if (hasRefCount) {
//        auto refCount = getRefCount(compiler, result, builder, thisValue);
//        auto load = builder->CreateLoad(refCount);
//        auto sub = builder->CreateSub(load, ConstantInt::get(compiler->context, APInt(64, 1)));
//        builder->CreateStore(sub, refCount);
//        
//        Function *function = builder->GetInsertBlock()->getParent();
//        auto ifBB = BasicBlock::Create(compiler->context);
//        auto mergeBB = BasicBlock::Create(compiler->context);
//        
//        auto c = builder->CreateICmpNE(sub, ConstantInt::get(compiler->context, APInt(64, STACK_REF_COUNT)));
//        builder->CreateCondBr(c, ifBB, mergeBB);
//        
//        // If not at special stack ref count then fail
//        function->getBasicBlockList().push_back(ifBB);
//        builder->SetInsertPoint(ifBB);
//        
//        compiler->callDebug(builder, "did not release: " + name, thisValue, nullptr);
//        
//        builder->CreateBr(mergeBB);
//        
//        // Merge block
//        function->getBasicBlockList().push_back(mergeBB);
//        builder->SetInsertPoint(mergeBB);
//    }
//#endif
//    
//    // Call destructor
//    auto destructor = getDestructor(compiler, result);
//    if (destructor) {
//        auto args = vector<Value*>();
//        args.push_back(thisValue);
//        builder->CreateCall(destructor, ArrayRef<Value*>(args));
//    }
//}
//
//void CBaseFunction::releaseHeap(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
//    assert(hasRefCount);
//    compiler->recordRelease(builder, thisValue, name);
//    
//    auto refCount = getRefCount(compiler, result, builder, thisValue);
//    auto load = builder->CreateLoad(refCount);
//    auto sub = builder->CreateSub(load, ConstantInt::get(compiler->context, APInt(64, 1)));
//    builder->CreateStore(sub, refCount);
//    
//    Function *function = builder->GetInsertBlock()->getParent();
//    auto ifBB = BasicBlock::Create(compiler->context);
//    auto mergeBB = BasicBlock::Create(compiler->context);
//    
//    auto c = builder->CreateICmpSLE(sub, ConstantInt::get(compiler->context, APInt(64, 0)));
//    builder->CreateCondBr(c, ifBB, mergeBB);
//    
//    // If zero then delete
//    function->getBasicBlockList().push_back(ifBB);
//    builder->SetInsertPoint(ifBB);
//    
//    // Call destructor
//    auto destructor = getDestructor(compiler, result);
//    if (destructor) {
//        auto args = vector<Value*>();
//        args.push_back(thisValue);
//        builder->CreateCall(destructor, ArrayRef<Value*>(args));
//    }
//    
//    // Delete "this"
//    auto thisValueAsVoidPtr = builder->CreateBitCast(thisValue, Type::getInt8PtrTy(compiler->context));
//    auto args = vector<Value*>();
//    args.push_back(thisValueAsVoidPtr);
//    auto free = compiler->getFreeFunction();
//    builder->CreateCall(free, ArrayRef<Value*>(args));
//    
//    builder->CreateBr(mergeBB);
//    
//    // Merge block
//    function->getBasicBlockList().push_back(mergeBB);
//    builder->SetInsertPoint(mergeBB);
//}
