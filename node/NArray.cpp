#include "Node.h"

void NArray::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    for (auto it : *elements) {
        it->define(compiler, result, thisFunction);
    }
}

shared_ptr<CVar> NArray::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    for (auto it : *elements) {
        it->getVar(compiler, result, thisFunction);
        auto ctype2 = it->getType(compiler, result, thisFunction);
        if (!itemType) {
            itemType = ctype2;
        } else if (itemType != ctype2) {
            result.addError(loc, CErrorCode::InvalidVariable, "all variables in list must be the same type");
            return nullptr;
        }
    }
    
    if (itemType == nullptr) {
        result.addError(loc, CErrorCode::InvalidVariable, "cannot determine type");
        return nullptr;
    }
    
    createCall = make_shared<NCall>(loc, "array", make_shared<CTypeNameList>(itemType->name), nullptr);
    return createCall->getVar(compiler, result, thisFunction, nullptr);
}

shared_ptr<CType> NArray::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    return createCall->getType(compiler, result, thisFunction);
}

int NArray::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, bool isHeapVar) {
    if (isHeapVar) {
        if (!this->isHeapVar) {
            this->isHeapVar = true;
            return 1;
        }
    }
    return 0;
}

shared_ptr<ReturnValue> NArray::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    auto var = getVar(compiler, result, thisFunction);
    auto functionVar = var->getCFunctionForValue(compiler, result);
    auto isHeapVar = var->getHeapVar(compiler, result);
    auto sizeValue = ConstantInt::get(compiler->context, APInt(64, elements->size()));
    Value* arrayValue = nullptr;
    if (isHeapVar) {
        auto allocFunc = compiler->getAllocFunction();
        
        // Compute the size of the struct by getting a pointer to the second element from null
        vector<Value*> v;
        v.push_back(ConstantInt::get(compiler->context, APInt(32, 1)));
        auto arrayType = itemType->llvmRefType(compiler, result)->getPointerTo();
        auto nullPtr = ConstantPointerNull::get(arrayType);
        auto sizePtr = builder->CreateGEP(nullPtr, ArrayRef<llvm::Value *>(v));
        auto itemSizeValue = builder->CreatePtrToInt(sizePtr, Type::getInt64Ty(compiler->context));
        auto countValue = ConstantInt::get(compiler->context, APInt(64, elements->size()));
        auto sizeValue = builder->CreateMul(itemSizeValue, countValue);
        
        // Allocate and mutate to correct type
        vector<Value*> allocArgs;
        allocArgs.push_back(sizeValue);
        arrayValue = builder->CreateCall(allocFunc, allocArgs);
        arrayValue->mutateType(arrayType);
    } else {
        arrayValue = builder->CreateAlloca(itemType->llvmRefType(compiler, result), sizeValue);
    }
    
    auto index = 0;
    for (auto it : *elements) {
        auto itemValue = it->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
        if (!itemValue) {
            return nullptr;
        }
        
        if (isHeapVar) {
            assert(itemValue->type == RVT_HEAP);
        }
        itemValue->retainIfNeeded(compiler, result, builder);
    
        vector<Value*> v;
        v.push_back(ConstantInt::get(compiler->context, APInt(64, index)));
        auto itemPtr = builder->CreateGEP(arrayValue, ArrayRef<llvm::Value *>(v));
        builder->CreateStore(itemValue->value, itemPtr);
        index++;
    }
    
    return make_shared<ReturnValue>(functionVar, true, RVT_HEAP, arrayValue);
}

void NArray::dump(Compiler* compiler, int level) const {
    // dumpf(level, "value: %s", value.c_str());
}

NList::NList(CLoc loc, shared_ptr<NodeList> elements) : NBase(NodeType_List, loc) {
    array = make_shared<NArray>(loc, elements);
}

void NList::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    array->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NList::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    array->getVar(compiler, result, thisFunction);
    auto size = make_shared<NInteger>(loc, array->elements->size());
    createCall = make_shared<NCall>(loc, "list", make_shared<CTypeNameList>(array->itemType->name), make_shared<NodeList>(size, size, array));
    return createCall->getVar(compiler, result, thisFunction, nullptr);
}

shared_ptr<CType> NList::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    return createCall->getType(compiler, result, thisFunction);
}

int NList::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, bool isHeapVar) {
    return createCall->setHeapVar(compiler, result, thisFunction, nullptr, isHeapVar);
}

shared_ptr<ReturnValue> NList::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    return createCall->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
}

void NList::dump(Compiler* compiler, int level) const {
    // dumpf(level, "value: %s", value.c_str());
}

shared_ptr<CType> NArrayGetFunction::getBlockType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    return thisFunction->getVarType(compiler, result, CLoc::undefined, make_shared<CTypeName>("item"));
}

shared_ptr<ReturnValue> NArrayGetFunction::call(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, shared_ptr<CFunction> callee, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters) {
    auto parentValue = dotVar->getLoadValue(compiler, result, thisValue, thisValue, builder, catchBB);
    
    auto indexValue = parameters[0]->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    assert(indexValue->type == RVT_SIMPLE);
    
    vector<Value*> v;
    v.push_back(indexValue->value);
    auto itemPtr = builder->CreateGEP(parentValue->value, ArrayRef<llvm::Value *>(v));
    auto itemType = getBlockType(compiler, result, callee);
    auto itemFunction = itemType->parent.lock();
    auto returnValue = make_shared<ReturnValue>(itemFunction, false, itemFunction ? RVT_HEAP : RVT_SIMPLE, builder->CreateLoad(itemPtr));
    parentValue->releaseIfNeeded(compiler, result, builder);
    return returnValue;
}

shared_ptr<CType> NArraySetFunction::getBlockType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    return compiler->typeVoid;
}

shared_ptr<ReturnValue> NArraySetFunction::call(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, shared_ptr<CFunction> callee, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters) {
    
    auto parentValue = dotVar->getLoadValue(compiler, result, thisValue, thisValue, builder, catchBB);
    
    auto indexValue = parameters[0]->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    assert(indexValue->type == RVT_SIMPLE);

    auto itemValue = parameters[1]->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    itemValue->retainIfNeeded(compiler, result, builder);
    
    vector<Value*> v;
    v.push_back(indexValue->value);
    auto itemPtr = builder->CreateGEP(parentValue->value, ArrayRef<llvm::Value *>(v));
    builder->CreateStore(itemValue->value, itemPtr);
    
    parentValue->releaseIfNeeded(compiler, result, builder);
    
    return nullptr;
}

shared_ptr<CType> NArrayDeleteFunction::getBlockType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    return compiler->typeVoid;
}

shared_ptr<ReturnValue> NArrayDeleteFunction::call(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, shared_ptr<CFunction> callee, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters) {
    auto parentValue = dotVar->getLoadValue(compiler, result, thisValue, thisValue, builder, catchBB);
    auto parentHeapVar = dotVar->getHeapVar(compiler, result);
    
    auto itemType = callee->getVarType(compiler, result, CLoc::undefined, make_shared<CTypeName>("item"));
    auto itemFunction = itemType->parent.lock();
    if (itemFunction) {
        auto sizeValue = parameters[0]->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
        assert(sizeValue->type == RVT_SIMPLE);

        // Delete items
        auto startValue = ConstantInt::get(compiler->context, APInt(64, 0));
        auto endValue = sizeValue->value;

        auto loopBB = BasicBlock::Create(compiler->context, "loop");
        auto afterBB = BasicBlock::Create(compiler->context, "afterloop");
        
        auto startCondition = builder->CreateICmpSLE(startValue, endValue);
        builder->CreateCondBr(startCondition, loopBB, afterBB);
        
        // Make the new basic block for the loop header, inserting after current block.
        Function *TheFunction = builder->GetInsertBlock()->getParent();
        BasicBlock *preheaderBB = builder->GetInsertBlock();
        TheFunction->getBasicBlockList().push_back(loopBB);
        
        // Start insertion in LoopBB.
        builder->SetInsertPoint(loopBB);
        
        // Start the PHI node with an entry for Start.
        auto indexValue = builder->CreatePHI(Type::getInt64Ty(compiler->context), 2);
        indexValue->addIncoming(startValue, preheaderBB);
        
        vector<Value*> v;
        v.push_back(indexValue);
        auto itemPtr = builder->CreateGEP(parentValue->value, ArrayRef<llvm::Value *>(v));
        auto itemValue = builder->CreateLoad(itemPtr);
        if (parentHeapVar) {
            itemFunction->releaseHeap(compiler, result, builder, itemValue);
        } else {
            itemFunction->releaseStack(compiler, result, builder, itemValue);
        }
        
        // Emit the step value.
        Value *StepVal = ConstantInt::get(compiler->context, APInt(64, 1));
        Value *NextVar = builder->CreateAdd(indexValue, StepVal, "nextvar");
        
        // Convert condition to a bool by comparing equal to 0.0.
        auto endCondition = builder->CreateICmpSLT(indexValue, endValue);
        
        // Create the "after loop" block and insert it.
        BasicBlock *loopEndBB = builder->GetInsertBlock();
        
        // Insert the conditional branch into the end of LoopEndBB.
        builder->CreateCondBr(endCondition, loopBB, afterBB);
        
        // Any new code will be inserted in AfterBB.
        TheFunction->getBasicBlockList().push_back(afterBB);
        builder->SetInsertPoint(afterBB);
        
        // Add a new entry to the PHI node for the backedge.
        indexValue->addIncoming(NextVar, loopEndBB);
    }
    
    // Delete array
    if (parentHeapVar) {
        auto freeFunc = compiler->getFreeFunction();
        
        // Allocate and mutate to correct type
        auto arrayPtr = builder->CreateBitCast(parentValue->value, Type::getInt8PtrTy(compiler->context));
        vector<Value*> allocArgs;
        allocArgs.push_back(arrayPtr);
        builder->CreateCall(freeFunc, allocArgs);
    }
    
    return nullptr;
}

shared_ptr<CType> NArrayCreateFunction::getBlockType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    return make_shared<CArrayType>("", thisFunction);
}

shared_ptr<CVar> NArrayCreateFunction::getReturnVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    return thisFunction->getThisVar();
}

shared_ptr<ReturnValue> NArrayCreateFunction::call(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, shared_ptr<CFunction> callee, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters) {
    if (parameters.size() == 0) {
        return nullptr;
    }
    
    auto countValue = parameters[0]->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    assert(countValue->type == RVT_SIMPLE);
    auto itemType = callee->templateTypes[0]->llvmRefType(compiler, result);
    
    auto calleeVar = callee->getThisVar();
    auto calleeHeapVar = calleeVar->getHeapVar(compiler, result);
    auto calleeFunction = calleeVar->getCFunctionForValue(compiler, result);
    shared_ptr<ReturnValue> arrayValue = nullptr;
    if (calleeHeapVar) {
        auto allocFunc = compiler->getAllocFunction();
        
        // Compute the size of the struct by getting a pointer to the second element from null
        vector<Value*> v;
        v.push_back(ConstantInt::get(compiler->context, APInt(32, 1)));
        auto arrayType = itemType->getPointerTo();
        auto nullPtr = ConstantPointerNull::get(arrayType);
        auto sizePtr = builder->CreateGEP(nullPtr, ArrayRef<llvm::Value *>(v));
        auto itemSizeValue = builder->CreatePtrToInt(sizePtr, Type::getInt64Ty(compiler->context));
        auto sizeValue = builder->CreateMul(itemSizeValue, countValue->value);
        
        // Allocate and mutate to correct type
        vector<Value*> allocArgs;
        allocArgs.push_back(sizeValue);
        auto value = builder->CreateCall(allocFunc, allocArgs);
        value->mutateType(arrayType);
        arrayValue = make_shared<ReturnValue>(calleeFunction, true, RVT_HEAP, value);
    } else {
        auto value = builder->CreateAlloca(itemType, countValue->value);
        arrayValue = make_shared<ReturnValue>(calleeFunction, true, RVT_HEAP, value);
    }
    
    return arrayValue;
}
