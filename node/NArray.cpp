#include "Node.h"

NodeType NArray::getNodeType() const {
    return NodeType_Array;
}

void NArray::define(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    for (auto it : *elements) {
        it->define(compiler, result, thisFunction);
    }
}

void NArray::fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    for (auto it : *elements) {
        it->fixVar(compiler, result, thisFunction);
        auto ctype2 = it->getReturnType(compiler, result, thisFunction);
        if (!itemType) {
            itemType = ctype2;
        } else if (itemType != ctype2) {
            result.addError(loc, CErrorCode::InvalidVariable, "all variables in list must be the same type");
            return;
        }
    }
    
    if (itemType == nullptr) {
        result.addError(loc, CErrorCode::InvalidVariable, "cannot determine type");
        return ;
    }
    
    createCall = make_shared<NCall>(loc, "array", make_shared<TemplateTypeNames>(itemType->name), nullptr);
}

shared_ptr<CType> NArray::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    return createCall->getReturnType(compiler, result, thisFunction);
}

Value* NArray::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    auto sizeValue = ConstantInt::get(compiler->context, APInt(64, elements->size()));
    auto alloca = builder->CreateAlloca(itemType->llvmRefType(compiler, result), sizeValue);
    
    auto index = 0;
    for (auto it : *elements) {
        auto itemValue = it->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
        if (!itemValue) {
            return nullptr;
        }
    
        vector<Value*> v;
        v.push_back(ConstantInt::get(compiler->context, APInt(64, index)));
        auto itemPtr = builder->CreateGEP(alloca, ArrayRef<llvm::Value *>(v));
        builder->CreateStore(itemValue, itemPtr);
        index++;
    }
    
    return alloca;
}

void NArray::dump(Compiler* compiler, int level) const {
    // dumpf(level, "value: %s", value.c_str());
}

NList::NList(CLoc loc, shared_ptr<NodeList> elements) : NBase(loc) {
    array = make_shared<NArray>(loc, elements);
}

NodeType NList::getNodeType() const {
    return NodeType_List;
}

void NList::define(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    array->define(compiler, result, thisFunction);
}

void NList::fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    array->fixVar(compiler, result, thisFunction);
    auto size = make_shared<NInteger>(loc, array->elements->size());
    createCall = make_shared<NCall>(loc, "list", make_shared<TemplateTypeNames>(array->itemType->name), make_shared<NodeList>(size, size, array));
}

shared_ptr<CType> NList::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    return createCall->getReturnType(compiler, result, thisFunction);
}

Value* NList::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const {
    assert(compiler->state == CompilerState::Compile);
    return createCall->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
}

void NList::dump(Compiler* compiler, int level) const {
    // dumpf(level, "value: %s", value.c_str());
}

shared_ptr<CType> NArrayGetFunction::getBlockType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    return thisFunction->getVarType(compiler, result, CLoc::undefined, "item", nullptr);
}

Value* NArrayGetFunction::call(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, shared_ptr<CFunction> callee, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters) {
    
    Value* parentValue = dotVar->getLoadValue(compiler, result, thisValue, thisValue, builder, catchBB);
    
    auto indexValue = parameters[0]->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    
    vector<Value*> v;
    v.push_back(indexValue);
    auto itemPtr = builder->CreateGEP(parentValue, ArrayRef<llvm::Value *>(v));
    return builder->CreateLoad(itemPtr);
}

shared_ptr<CType> NArraySetFunction::getBlockType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    return compiler->typeVoid;
}

Value* NArraySetFunction::call(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, shared_ptr<CFunction> callee, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters) {
    
    Value* parentValue = dotVar->getLoadValue(compiler, result, thisValue, thisValue, builder, catchBB);
    
    auto indexValue = parameters[0]->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    auto itemValue = parameters[1]->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    
    vector<Value*> v;
    v.push_back(indexValue);
    auto itemPtr = builder->CreateGEP(parentValue, ArrayRef<llvm::Value *>(v));
    builder->CreateStore(itemValue, itemPtr);
    
    return nullptr;
}

shared_ptr<CType> NArrayCreateFunction::getBlockType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    return make_shared<CArrayType>("", thisFunction);
}

Value* NArrayCreateFunction::call(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, shared_ptr<CFunction> callee, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters) {
    if (parameters.size() == 0) {
        return nullptr;
    }
    
    auto sizeValue = parameters[0]->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    auto itemType = callee->templateTypes[0]->llvmRefType(compiler, result);
    
    auto alloca = builder->CreateAlloca(itemType, sizeValue);
    // printf("alloca: %s\n", Type_print(alloca->getType()).c_str());
    return alloca;
}
