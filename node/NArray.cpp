#include "Node.h"

void NArray::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    for (auto it : *elements) {
        it->define(compiler, result, thisFunction);
    }
}

shared_ptr<CVar> NArray::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    for (auto it : *elements) {
        it->getVar(compiler, result, thisFunction, thisVar);
        auto ctype2 = it->getType(compiler, result, thisFunction, thisVar);
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
    
    createCall = make_shared<NCall>(loc, "array", make_shared<CTypeNameList>(CTC_Value, itemType->name), nullptr);
    return createCall->getVar(compiler, result, thisFunction, thisVar, nullptr);
}

shared_ptr<CType> NArray::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return createCall->getType(compiler, result, thisFunction, thisVar);
}

int NArray::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    if (isHeapVar) {
        if (!this->isHeapVar) {
            this->isHeapVar = true;
            return 1;
        }
    }
    return 0;
}

shared_ptr<CType> NArray::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* output, TrFunction* function, stringstream& line) {
	assert(false);
	return nullptr;
}

//shared_ptr<ReturnValue> NArray::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    assert(compiler->state == CompilerState::Compile);
//    compiler->emitLocation(builder, &this->loc);
//    
//    auto var = getVar(compiler, result, thisFunction, thisVar);
//    auto functionVar = var->getCFunctionForValue(compiler, result);
//    auto isHeapVar = var->getHeapVar(compiler, result, thisVar);
//    auto sizeValue = ConstantInt::get(compiler->context, APInt(64, elements->size()));
//    Value* arrayValue = nullptr;
//    if (isHeapVar) {
//        auto allocFunc = compiler->getAllocFunction();
//        
//        // Compute the size of the struct by getting a pointer to the second element from null
//        vector<Value*> v;
//        v.push_back(ConstantInt::get(compiler->context, APInt(32, 1)));
//        auto arrayType = itemType->llvmRefType(compiler, result)->getPointerTo();
//        auto nullPtr = ConstantPointerNull::get(arrayType);
//        auto sizePtr = builder->CreateGEP(nullPtr, ArrayRef<llvm::Value *>(v));
//        auto itemSizeValue = builder->CreatePtrToInt(sizePtr, Type::getInt64Ty(compiler->context));
//        auto countValue = ConstantInt::get(compiler->context, APInt(64, elements->size()));
//        auto sizeValue = builder->CreateMul(itemSizeValue, countValue);
//        
//        // Allocate and mutate to correct type
//        vector<Value*> allocArgs;
//        allocArgs.push_back(sizeValue);
//        arrayValue = builder->CreateCall(allocFunc, allocArgs);
//        arrayValue->mutateType(arrayType);
//    } else {
//        arrayValue = builder->CreateAlloca(itemType->llvmRefType(compiler, result), sizeValue);
//    }
//    
//    auto index = 0;
//    for (auto it : *elements) {
//        auto itemValue = it->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, RRT_Auto);
//        if (!itemValue) {
//            return nullptr;
//        }
//        
//        if (isHeapVar) {
//            assert(itemValue->type == RVT_HEAP);
//        }
//        itemValue->retainIfNeeded(compiler, result, builder);
//    
//        vector<Value*> v;
//        v.push_back(ConstantInt::get(compiler->context, APInt(64, index)));
//        auto itemPtr = builder->CreateGEP(arrayValue, ArrayRef<llvm::Value *>(v));
//        builder->CreateStore(itemValue->value, itemPtr);
//        index++;
//    }
//    
//    return make_shared<ReturnValue>(functionVar, RVR_MustRelease, RVT_HEAP, false, arrayValue);
//}

void NArray::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    // dumpf(level, "value: %s", value.c_str());
}

NList::NList(CLoc loc, shared_ptr<NodeList> elements) : NBase(NodeType_List, loc) {
    array = make_shared<NArray>(loc, elements);
}

void NList::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    array->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NList::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    array->getVar(compiler, result, thisFunction, thisVar);
    auto size = make_shared<NInteger>(loc, array->elements->size());
    createCall = make_shared<NCall>(loc, "list", make_shared<CTypeNameList>(CTC_Value, array->itemType->name), make_shared<NodeList>(size, size, array));
    return createCall->getVar(compiler, result, thisFunction, thisVar, nullptr);
}

shared_ptr<CType> NList::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return createCall->getType(compiler, result, thisFunction, thisVar);
}

int NList::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    return createCall->setHeapVar(compiler, result, thisFunction, thisVar, nullptr, isHeapVar);
}

//shared_ptr<ReturnValue> NList::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    assert(compiler->state == CompilerState::Compile);
//    return createCall->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, returnRefType);
//}

shared_ptr<CType> NList::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* output, TrFunction* function, stringstream& line) {
	assert(false);
	return nullptr;
}

void NList::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    // dumpf(level, "value: %s", value.c_str());
}

class CArrayGetFunction : public CFunction {
public:
    CArrayGetFunction(weak_ptr<CBaseFunctionDefinition> definition, CFunctionType type, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces) : CFunction(definition, type, templateTypes, parent, interfaces) {}
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    virtual shared_ptr<CVar> getReturnVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) { return nullptr; }
    //virtual Function* compileDestructorDefinition(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction) { return nullptr; }
    //virtual void compileDestructorBody(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, Function* function) { }
    //virtual shared_ptr<ReturnValue> call(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, shared_ptr<CVar> calleeVar, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters, ReturnRefType returnRefType);
};

NArrayGetFunction::NArrayGetFunction() : NFunction(CLoc::undefined, FT_Private, make_shared<CTypeName>(CTC_Value, "item"), "get", nullptr, nullptr, make_shared<NodeList>(
                                                                                                                                                           make_shared<NAssignment>(CLoc::undefined, nullptr, make_shared<CTypeName>(CTC_Value, "int"), "index", nullptr, false)
                                                                                                                                                           ), nullptr, nullptr, nullptr) { }

shared_ptr<CFunction> NArrayGetFunction::createCFunction(Compiler* compiler, CResult& result, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, CFunctionType type, const string& name, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, shared_ptr<CInterfaceMethod> interfaceMethod) {
    assert(!interfaceMethod);
    auto fun = make_shared<CArrayGetFunction>(definition, type, templateTypes, parent, interfaces);
    return fun->init(compiler, result, NFunction::shared_from_this(), nullptr);
}

shared_ptr<CType> CArrayGetFunction::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    return getVarType(compiler, result, make_shared<CTypeName>(CTC_Value, "item"));
}

//shared_ptr<ReturnValue> CArrayGetFunction::call(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, shared_ptr<CVar> calleeVar, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters, ReturnRefType returnRefType) {
//    auto parentValue = dotVar->getLoadValue(compiler, result, thisVar, thisValue, true, thisValue, builder, catchBB, RRT_Auto);
//    
//    auto indexValue = parameters[0]->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, RRT_Auto);
//    assert(indexValue->type == RVT_SIMPLE);
//    
//    vector<Value*> v;
//    v.push_back(indexValue->value);
//    auto itemPtr = builder->CreateGEP(parentValue->value, ArrayRef<llvm::Value *>(v));
//    auto itemType = getReturnType(compiler, result, thisVar);
//    auto itemFunction = itemType->parent.lock();
//    auto returnValue = make_shared<ReturnValue>(itemFunction, RVR_MustRetain, itemFunction ? RVT_HEAP : RVT_SIMPLE, false, builder->CreateLoad(itemPtr));
//    parentValue->releaseIfNeeded(compiler, result, builder);
//    return returnValue;
//}

class CArraySetFunction : public CFunction {
public:
    CArraySetFunction(weak_ptr<CBaseFunctionDefinition> definition, CFunctionType type, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces) : CFunction(definition, type, templateTypes, parent, interfaces) {}
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    virtual shared_ptr<CVar> getReturnVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) { return nullptr; }
    virtual int setHeapVarBody(Compiler *compiler, CResult& result, shared_ptr<CVar> thisVar);
    //virtual Function* compileDestructorDefinition(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction) { return nullptr; }
    //virtual void compileDestructorBody(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, Function* function) { }
    //virtual shared_ptr<ReturnValue> call(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, shared_ptr<CVar> calleeVar, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters, ReturnRefType returnRefType);
};

NArraySetFunction::NArraySetFunction() : NFunction(CLoc::undefined, FT_Private, make_shared<CTypeName>(CTC_Value, "void"), "set", nullptr, nullptr, make_shared<NodeList>(
                                                                                                                                                           make_shared<NAssignment>(CLoc::undefined, nullptr, make_shared<CTypeName>(CTC_Value, "int"), "index", nullptr, false),
                                                                                                                                                           make_shared<NAssignment>(CLoc::undefined, nullptr, make_shared<CTypeName>(CTC_Value, "item"), "item", nullptr, false)
                                                                                                                                                           ), nullptr, nullptr, nullptr) { }

shared_ptr<CFunction> NArraySetFunction::createCFunction(Compiler* compiler, CResult& result, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, CFunctionType type, const string& name, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, shared_ptr<CInterfaceMethod> interfaceMethod) {
    assert(!interfaceMethod);
    auto fun = make_shared<CArraySetFunction>(definition, type, templateTypes, parent, interfaces);
    return fun->init(compiler, result, NFunction::shared_from_this(), nullptr);
}

shared_ptr<CType> CArraySetFunction::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    return compiler->typeVoid;
}

int CArraySetFunction::setHeapVarBody(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    argVars[1]->setHeapVar(compiler, result, thisVar);
    return 0;
}

//shared_ptr<ReturnValue> CArraySetFunction::call(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, shared_ptr<CVar> calleeVar, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters, ReturnRefType returnRefType) {
//    
//    auto parentValue = dotVar->getLoadValue(compiler, result, thisVar, thisValue, true, thisValue, builder, catchBB, RRT_Auto);
//    auto parentFunction = dotVar->getCFunctionForValue(compiler, result);
//    auto parentHeapVar = dotVar->getHeapVar(compiler, result, thisVar);
//    
//    auto indexValue = parameters[0]->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, RRT_Auto);
//    assert(indexValue->type == RVT_SIMPLE);
//
//    auto itemValue = parameters[1]->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, RRT_Auto);
//    auto itemVar = parameters[1]->getVar(compiler, result, thisFunction, thisVar);
//    if (parentHeapVar) {
//        assert(itemVar == nullptr || itemVar->getHeapVar(compiler, result, thisVar));
//    }
//    itemValue->retainIfNeeded(compiler, result, builder);
//    
//    vector<Value*> v;
//    v.push_back(indexValue->value);
//    auto itemPtr = builder->CreateGEP(parentValue->value, ArrayRef<llvm::Value *>(v));
//    builder->CreateStore(itemValue->value, itemPtr);
//    
//    parentValue->releaseIfNeeded(compiler, result, builder);
//    
//    return nullptr;
//}

class CArrayGrowFunction : public CFunction {
public:
    CArrayGrowFunction(weak_ptr<CBaseFunctionDefinition> definition, CFunctionType type, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces) : CFunction(definition, type, templateTypes, parent, interfaces) {}
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    virtual shared_ptr<CVar> getReturnVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) { return nullptr; }
    virtual int setHeapVarBody(Compiler *compiler, CResult& result, shared_ptr<CVar> thisVar);
    //virtual Function* compileDestructorDefinition(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction) { return nullptr; }
    //virtual void compileDestructorBody(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, Function* function) { }
    //virtual shared_ptr<ReturnValue> call(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, shared_ptr<CVar> calleeVar, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters, ReturnRefType returnRefType);
};

NArrayGrowFunction::NArrayGrowFunction() : NFunction(CLoc::undefined, FT_Private, make_shared<CTypeName>(CTC_Value, "array", make_shared<CTypeNameList>(CTC_Value, "item")), "grow", nullptr, nullptr, make_shared<NodeList>(
                                                                                                                                                                                                             make_shared<NAssignment>(CLoc::undefined, nullptr, make_shared<CTypeName>(CTC_Value, "int"), "size", nullptr, false)
                                                                                                                                                                                                             ), nullptr, nullptr, nullptr) { }

shared_ptr<CFunction> NArrayGrowFunction::createCFunction(Compiler* compiler, CResult& result, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, CFunctionType type, const string& name, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, shared_ptr<CInterfaceMethod> interfaceMethod) {
    assert(!interfaceMethod);
    auto fun = make_shared<CArrayGrowFunction>(definition, type, templateTypes, parent, interfaces);
    return fun->init(compiler, result, NFunction::shared_from_this(), nullptr);
}

shared_ptr<CType> CArrayGrowFunction::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    return make_shared<CArrayType>("", static_pointer_cast<CFunction>(parent.lock()));
}

int CArrayGrowFunction::setHeapVarBody(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    // TODO: thisFunction->parent.lock()->getThisVar()->setHeapVar(compiler, result);
    return 0;
}

//shared_ptr<ReturnValue> CArrayGrowFunction::call(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, shared_ptr<CVar> calleeVar, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters, ReturnRefType returnRefType) {
//    auto parentValue = dotVar->getLoadValue(compiler, result, thisVar, thisValue, true, thisValue, builder, catchBB, RRT_Auto);
//    auto parentFunction = dotVar->getCFunctionForValue(compiler, result);
//    auto parentHeapVar = dotVar->getHeapVar(compiler, result, thisVar);
//    assert(parentHeapVar);
//    
//    auto itemType = getVarType(compiler, result, make_shared<CTypeName>(CTC_Value, "item"));
//    auto itemLLVMType = itemType->llvmRefType(compiler, result);
//    auto itemFunction = itemType->parent.lock();
//    
//    auto countValue = parameters[0]->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, RRT_Auto);
//    assert(countValue->type == RVT_SIMPLE);
//
//    vector<Value*> v;
//    v.push_back(ConstantInt::get(compiler->context, APInt(32, 1)));
//    auto nullPtr = ConstantPointerNull::get((PointerType*)itemLLVMType);
//    auto sizePtr = builder->CreateGEP(nullPtr, ArrayRef<llvm::Value *>(v));
//    auto itemSizeValue = builder->CreatePtrToInt(sizePtr, Type::getInt64Ty(compiler->context));
//    auto sizeValue = builder->CreateMul(itemSizeValue, countValue->value);
//
//    auto arrayPtr = builder->CreateBitCast(parentValue->value, Type::getInt8PtrTy(compiler->context));
//
//    vector<Value*> reallocArgs;
//    reallocArgs.push_back(arrayPtr);
//    reallocArgs.push_back(sizeValue);
//
//    auto realloc = compiler->getReallocFunction();
//    auto returnPtr = builder->CreateCall(realloc, reallocArgs);
//    auto returnArray = builder->CreateBitCast(returnPtr, itemLLVMType->getPointerTo());
//
//    auto arrayFunction = parent.lock();
//    return make_shared<ReturnValue>(false, returnArray);
//}

class CArrayDeleteFunction : public CFunction {
public:
    CArrayDeleteFunction(weak_ptr<CBaseFunctionDefinition> definition, CFunctionType type, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces) : CFunction(definition, type, templateTypes, parent, interfaces) {}
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    virtual shared_ptr<CVar> getReturnVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) { return nullptr; }
    //virtual Function* compileDestructorDefinition(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction) { return nullptr; }
    //virtual void compileDestructorBody(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, Function* function) { }
    //virtual shared_ptr<ReturnValue> call(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, shared_ptr<CVar> calleeVar, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters, ReturnRefType returnRefType);
};

NArrayDeleteFunction::NArrayDeleteFunction() : NFunction(CLoc::undefined, FT_Private, make_shared<CTypeName>(CTC_Value, "void"), "delete", nullptr, nullptr, make_shared<NodeList>(
                                                                                                                                                                 make_shared<NAssignment>(CLoc::undefined, nullptr, make_shared<CTypeName>(CTC_Value, "int"), "size", nullptr, false)
                                                                                                                                                                 ), nullptr, nullptr, nullptr) { }

shared_ptr<CFunction> NArrayDeleteFunction::createCFunction(Compiler* compiler, CResult& result, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, CFunctionType type, const string& name, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, shared_ptr<CInterfaceMethod> interfaceMethod) {
    assert(!interfaceMethod);
    auto fun = make_shared<CArrayDeleteFunction>(definition, type, templateTypes, parent, interfaces);
    return fun->init(compiler, result, NFunction::shared_from_this(), nullptr);
}

shared_ptr<CType> CArrayDeleteFunction::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    return compiler->typeVoid;
}

//shared_ptr<ReturnValue> CArrayDeleteFunction::call(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, shared_ptr<CVar> calleeVar, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters, ReturnRefType returnRefType) {
//    auto parentValue = dotVar->getLoadValue(compiler, result, thisVar, thisValue, true, thisValue, builder, catchBB, RRT_Auto);
//    auto parentHeapVar = dotVar->getHeapVar(compiler, result, thisVar);
//    
//    auto itemType = getVarType(compiler, result, make_shared<CTypeName>(CTC_Value, "item"));
//    auto itemFunction = itemType->parent.lock();
//    if (itemFunction) {
//        auto sizeValue = parameters[0]->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, RRT_Auto);
//        assert(sizeValue->type == RVT_SIMPLE);
//        
//        compiler->callDebug(builder, "array_delete_size", nullptr, sizeValue->value);
//
//        // Delete items
//        auto startValue = ConstantInt::get(compiler->context, APInt(64, 0));
//        auto endValue = sizeValue->value;
//
//        auto loopBB = BasicBlock::Create(compiler->context, "loop");
//        auto afterBB = BasicBlock::Create(compiler->context, "afterloop");
//        
//        auto startCondition = builder->CreateICmpSLT(startValue, endValue);
//        builder->CreateCondBr(startCondition, loopBB, afterBB);
//        
//        // Make the new basic block for the loop header, inserting after current block.
//        Function *TheFunction = builder->GetInsertBlock()->getParent();
//        BasicBlock *preheaderBB = builder->GetInsertBlock();
//        TheFunction->getBasicBlockList().push_back(loopBB);
//        
//        // Start insertion in LoopBB.
//        builder->SetInsertPoint(loopBB);
//        
//        // Start the PHI node with an entry for Start.
//        auto indexValue = builder->CreatePHI(Type::getInt64Ty(compiler->context), 2);
//        indexValue->addIncoming(startValue, preheaderBB);
//        
//        compiler->callDebug(builder, "array_delete_item", nullptr, indexValue);
//
//        vector<Value*> v;
//        v.push_back(indexValue);
//        auto itemPtr = builder->CreateGEP(parentValue->value, ArrayRef<llvm::Value *>(v));
//        auto itemValue = builder->CreateLoad(itemPtr);
//        if (parentHeapVar) {
//            itemFunction->releaseHeap(compiler, result, builder, itemValue);
//        } else {
//            itemFunction->releaseStack(compiler, result, builder, itemValue);
//        }
//        
//        // Emit the step value.
//        Value *StepVal = ConstantInt::get(compiler->context, APInt(64, 1));
//        Value *NextVar = builder->CreateAdd(indexValue, StepVal, "nextvar");
//        
//        // Convert condition to a bool by comparing equal to 0.0.
//        auto endCondition = builder->CreateICmpSLT(NextVar, endValue);
//        
//        // Create the "after loop" block and insert it.
//        BasicBlock *loopEndBB = builder->GetInsertBlock();
//        
//        // Insert the conditional branch into the end of LoopEndBB.
//        builder->CreateCondBr(endCondition, loopBB, afterBB);
//        
//        // Any new code will be inserted in AfterBB.
//        TheFunction->getBasicBlockList().push_back(afterBB);
//        builder->SetInsertPoint(afterBB);
//        
//        // Add a new entry to the PHI node for the backedge.
//        indexValue->addIncoming(NextVar, loopEndBB);
//    }
//    
//    // Delete array
//    if (parentHeapVar) {
//        auto freeFunc = compiler->getFreeFunction();
//        
//        // Allocate and mutate to correct type
//        auto arrayPtr = builder->CreateBitCast(parentValue->value, Type::getInt8PtrTy(compiler->context));
//        vector<Value*> allocArgs;
//        allocArgs.push_back(arrayPtr);
//        builder->CreateCall(freeFunc, allocArgs);
//    }
//    
//    compiler->callDebug(builder, "array_delete_done", nullptr, 0);
//    
//    return nullptr;
//}

class CArrayCreateFunction : public CFunction {
public:
    CArrayCreateFunction(weak_ptr<CBaseFunctionDefinition> definition, CFunctionType type, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces) : CFunction(definition, type, templateTypes, parent, interfaces) {}
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    virtual shared_ptr<CVar> getReturnVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    //virtual Function* compileDestructorDefinition(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction) { return nullptr; }
    //virtual void compileDestructorBody(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, Function* function) { }
    //virtual shared_ptr<ReturnValue> call(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, shared_ptr<CVar> calleeVar, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters, ReturnRefType returnRefType);
};

NArrayCreateFunction::NArrayCreateFunction() : NFunction(CLoc::undefined, FT_Private, nullptr, "array", make_shared<CTypeNameList>(CTC_Value, "item"), nullptr,
                                                         make_shared<NodeList>(
                                                             make_shared<NAssignment>(CLoc::undefined, nullptr, nullptr, "size", make_shared<NInteger>(CLoc::undefined, "0"), false),
                                                             make_shared<NArrayGetFunction>(),
                                                             make_shared<NArraySetFunction>(),
                                                             make_shared<NArrayGrowFunction>(),
                                                             make_shared<NArrayDeleteFunction>()
                                                         ), nullptr, nullptr, nullptr) { }

shared_ptr<CFunction> NArrayCreateFunction::createCFunction(Compiler* compiler, CResult& result, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, CFunctionType type, const string& name, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, shared_ptr<CInterfaceMethod> interfaceMethod) {
    assert(!interfaceMethod);
    auto fun = make_shared<CArrayCreateFunction>(definition, type, templateTypes, parent, interfaces);
    return fun->init(compiler, result, NFunction::shared_from_this(), nullptr);
}

shared_ptr<CType> CArrayCreateFunction::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    return make_shared<CArrayType>("array", shared_from_this());
}

shared_ptr<CVar> CArrayCreateFunction::getReturnVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    return thisVar;
}

//shared_ptr<ReturnValue> CArrayCreateFunction::call(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, shared_ptr<CVar> calleeVar, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters, ReturnRefType returnRefType) {
//    if (parameters.size() == 0) {
//        return nullptr;
//    }
//    
//    assert(returnRefType == RRT_Auto || returnRefType == RRT_MustRelease);
//    
//    auto countValue = parameters[0]->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, RRT_Auto);
//    assert(countValue->type == RVT_SIMPLE);
//    auto itemType = templateTypes[0]->llvmRefType(compiler, result);
//    
//    auto calleeHeapVar = calleeVar->getHeapVar(compiler, result, thisVar);
//    auto calleeFunction = calleeVar->getCFunctionForValue(compiler, result);
//    shared_ptr<ReturnValue> arrayValue = nullptr;
//    if (calleeHeapVar) {
//        auto allocFunc = compiler->getAllocFunction();
//        
//        // Compute the size of the struct by getting a pointer to the second element from null
//        vector<Value*> v;
//        v.push_back(ConstantInt::get(compiler->context, APInt(32, 1)));
//        auto arrayType = itemType->getPointerTo();
//        auto nullPtr = ConstantPointerNull::get(arrayType);
//        auto sizePtr = builder->CreateGEP(nullPtr, ArrayRef<llvm::Value *>(v));
//        auto itemSizeValue = builder->CreatePtrToInt(sizePtr, Type::getInt64Ty(compiler->context));
//        auto sizeValue = builder->CreateMul(itemSizeValue, countValue->value);
//        
//        // Allocate and mutate to correct type
//        vector<Value*> allocArgs;
//        allocArgs.push_back(sizeValue);
//        auto value = builder->CreateCall(allocFunc, allocArgs);
//        value->mutateType(arrayType);
//        arrayValue = make_shared<ReturnValue>(calleeFunction, RVR_MustRelease, RVT_HEAP, false, value);
//    } else {
//        auto value = builder->CreateAlloca(itemType, countValue->value);
//        arrayValue = make_shared<ReturnValue>(calleeFunction, RVR_MustRelease, RVT_HEAP, false, value);
//    }
//    
//    return arrayValue;
//}
