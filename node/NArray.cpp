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
    
    createCall = make_shared<NCall>(loc, "array", make_shared<TemplateTypeNames>(itemType->name), nullptr);
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

Value* NArray::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, bool isReturnRetained) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    auto var = getVar(compiler, result, thisFunction);
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
        auto itemValue = it->compile(compiler, result, thisFunction, thisValue, builder, catchBB, true);
        if (!itemValue) {
            return nullptr;
        }
        
        // retain item
        auto itemVar = it->getVar(compiler, result, thisFunction);
        if (itemVar) {
            auto itemFunction = itemVar->getCFunctionForValue(compiler, result);
            if (itemFunction) {
                if (isHeapVar) {
                    itemFunction->retainHeap(compiler, result, builder, itemValue);
                } else {
                    itemFunction->retainStack(compiler, result, builder, itemValue);
                }
            }
        }
    
        vector<Value*> v;
        v.push_back(ConstantInt::get(compiler->context, APInt(64, index)));
        auto itemPtr = builder->CreateGEP(arrayValue, ArrayRef<llvm::Value *>(v));
        builder->CreateStore(itemValue, itemPtr);
        index++;
    }
    
    return arrayValue;
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
    createCall = make_shared<NCall>(loc, "list", make_shared<TemplateTypeNames>(array->itemType->name), make_shared<NodeList>(size, size, array));
    return createCall->getVar(compiler, result, thisFunction, nullptr);
}

shared_ptr<CType> NList::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    return createCall->getType(compiler, result, thisFunction);
}

int NList::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, bool isHeapVar) {
    return createCall->setHeapVar(compiler, result, thisFunction, nullptr, isHeapVar);
}

Value* NList::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, bool isReturnRetained) {
    assert(compiler->state == CompilerState::Compile);
    return createCall->compile(compiler, result, thisFunction, thisValue, builder, catchBB, isReturnRetained);
}

void NList::dump(Compiler* compiler, int level) const {
    // dumpf(level, "value: %s", value.c_str());
}

shared_ptr<CType> NArrayGetFunction::getBlockType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    return thisFunction->getVarType(compiler, result, CLoc::undefined, "item", nullptr);
}

Value* NArrayGetFunction::call(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, shared_ptr<CFunction> callee, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters, bool returnIsRetained) {
    // TODO: handle retained
    
    Value* parentValue = dotVar->getLoadValue(compiler, result, thisValue, thisValue, builder, catchBB, false);
    
    auto indexValue = parameters[0]->compile(compiler, result, thisFunction, thisValue, builder, catchBB, false);
    
    vector<Value*> v;
    v.push_back(indexValue);
    auto itemPtr = builder->CreateGEP(parentValue, ArrayRef<llvm::Value *>(v));
    return builder->CreateLoad(itemPtr);
}

shared_ptr<CType> NArraySetFunction::getBlockType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    return compiler->typeVoid;
}

Value* NArraySetFunction::call(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, shared_ptr<CFunction> callee, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters, bool returnIsRetained) {
    // TODO: handle retained
    
    Value* parentValue = dotVar->getLoadValue(compiler, result, thisValue, thisValue, builder, catchBB, false);
    
    auto indexValue = parameters[0]->compile(compiler, result, thisFunction, thisValue, builder, catchBB, false);
    
    // TODO: retain value
    auto itemValue = parameters[1]->compile(compiler, result, thisFunction, thisValue, builder, catchBB, true);
    
    vector<Value*> v;
    v.push_back(indexValue);
    auto itemPtr = builder->CreateGEP(parentValue, ArrayRef<llvm::Value *>(v));
    builder->CreateStore(itemValue, itemPtr);
    
    return nullptr;
}

shared_ptr<CType> NArrayCreateFunction::getBlockType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    return make_shared<CArrayType>("", thisFunction);
}

shared_ptr<CVar> NArrayCreateFunction::getReturnVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    return thisFunction->getThisVar();
}

Value* NArrayCreateFunction::call(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, shared_ptr<CFunction> callee, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters, bool returnIsRetained) {
    // TODO: handle retained
    if (parameters.size() == 0) {
        return nullptr;
    }
    
    auto countValue = parameters[0]->compile(compiler, result, thisFunction, thisValue, builder, catchBB, false);
    auto itemType = callee->templateTypes[0]->llvmRefType(compiler, result);
    
    auto thisVar = thisFunction->getThisVar();
    Value* arrayValue = nullptr;
    if (thisVar->getHeapVar(compiler, result)) {
        auto allocFunc = compiler->getAllocFunction();
        
        // Compute the size of the struct by getting a pointer to the second element from null
        vector<Value*> v;
        v.push_back(ConstantInt::get(compiler->context, APInt(32, 1)));
        auto arrayType = itemType->getPointerTo();
        auto nullPtr = ConstantPointerNull::get(arrayType);
        auto sizePtr = builder->CreateGEP(nullPtr, ArrayRef<llvm::Value *>(v));
        auto itemSizeValue = builder->CreatePtrToInt(sizePtr, Type::getInt64Ty(compiler->context));
        auto sizeValue = builder->CreateMul(itemSizeValue, countValue);
        
        // Allocate and mutate to correct type
        vector<Value*> allocArgs;
        allocArgs.push_back(sizeValue);
        arrayValue = builder->CreateCall(allocFunc, allocArgs);
        arrayValue->mutateType(arrayType);
    } else {
        arrayValue = builder->CreateAlloca(itemType, countValue);
    }
    return arrayValue;
}
