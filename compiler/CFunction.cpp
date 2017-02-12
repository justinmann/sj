//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "Node.h"
#define STACK_REF_COUNT         1000000000000

CTypeNameList::CTypeNameList(const string& name) {
    push_back(make_shared<CTypeName>(name));
}

shared_ptr<CFunction> CFunction::create(Compiler* compiler, CResult& result, const CLoc& loc, weak_ptr<CFunctionDefinition> definition_, vector<shared_ptr<CType>>& templateTypes_, weak_ptr<CFunction> parent_, CFunctionType type_, const string& name_, shared_ptr<NFunction> node_) {
    auto c = make_shared<CFunction>();
    c->definition = definition_;
    c->templateTypes = templateTypes_;
    c->parent = parent_;
    c->type = type_;
    c->name = name_;
    c->node = node_;
    c->hasRefCount = false;
    c->hasParent = false;
    c->_structType = nullptr;
    c->function = nullptr;
    
    for (auto it : templateTypes_) {
        c->name = c->name + "_" + it->name;
    }
    
    if (c->node) {
        if (node_->templateTypeNames) {
            assert(node_->templateTypeNames->size() == templateTypes_.size());
            auto index = 0;
            for (auto templateTypeName : *node_->templateTypeNames) {
                if (templateTypeName->templateTypeNames != nullptr) {
                    result.addError(loc, CErrorCode::InvalidType, "cannot use ! in template type name");
                    return nullptr;
                }
                c->templateTypesByName[templateTypeName->name] = templateTypes_[index];
                index++;
            }
        }
        
        for (auto it : c->node->assignments) {
            if (it->var) {
                result.addError(it->loc, CErrorCode::InvalidDot, "cannot use '.' in variable declaration for a function: '%s'", it->name.c_str());
            }

            int index = (int)c->thisVars.size();
            auto thisVar = CNormalVar::createFunctionVar(c->node->loc, it->name, c, c->node, index, it, nullptr);
            c->thisVarsByName[it->name] = pair<int, shared_ptr<CVar>>(index, thisVar);
            c->thisVars.push_back(thisVar);
        }
    }
    
    return c;
}

void CFunction::createThisVar(Compiler* compiler, CResult& result, shared_ptr<CVar>& thisVar) {
    thisVar = CNormalVar::createThisVar(CLoc::undefined, shared_from_this(), getThisType(compiler, result));
    if (node) {
        node->getVarBody(compiler, result, shared_from_this(), thisVar);
        node->setHeapVarBody(compiler, result, shared_from_this(), thisVar);
    }
}

shared_ptr<CType> CFunction::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    if (isInGetType) {
        result.addError(CLoc::undefined, CErrorCode::TypeLoop, "while trying to determine type a cycle was detected");
        return nullptr;
    }
    
    isInGetType = true;
    
    if (!returnType) {
        returnType = node->getBlockType(compiler, result, shared_from_this(), thisVar);
    }
    
    isInGetType = false;
    return returnType;
}

shared_ptr<CVar> CFunction::getReturnVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    return node->getReturnVar(compiler, result, shared_from_this(), thisVar);
}


bool CFunction::getHasThis() {
    if (type == FT_Extern) {
        return false;
    }
    
    if (!hasRefCount) {
        return false;
    }
    
    return true;
}

shared_ptr<CType> CFunction::getThisType(Compiler* compiler, CResult& result) {
    if (!thisType && node != nullptr) {
        thisType = make_shared<CType>(name.c_str(), shared_from_this());

    }
 
    return thisType;
}

shared_ptr<vector<Type*>> CFunction::getTypeList(Compiler* compiler, CResult& result) {
    if (!typeList) {
        typeList = make_shared<vector<Type*>>();
        
        if (hasRefCount) {
            indexRefCount = typeList->size();
            typeList->push_back(Type::getInt64Ty(compiler->context));
        }
        
        if (hasParent) {
            indexParent = typeList->size();
            auto parentType = parent.lock()->getThisType(compiler, result);
            auto parentLLVMType = parentType->llvmRefType(compiler, result);
            assert(parentLLVMType);
            typeList->push_back(parentLLVMType);
        }
        
        indexVars = typeList->size();
        for (auto it : thisVars) {
            auto ctype = it->getType(compiler, result);
            if (!ctype) {
                result.addError(it->nassignment->loc, CErrorCode::InvalidType, "cannot determine type for '%s'", it->name.c_str());
                return nullptr;
            }
            auto llvmType = ctype->llvmRefType(compiler, result);
            assert(llvmType);
            typeList->push_back(llvmType);
        }
    }
    return typeList;
}

Type* CFunction::getStructType(Compiler* compiler, CResult& result) {
    if (!getHasThis()) {
        return nullptr;
    }
    
    if (!_structType) {
        _structType = StructType::create(compiler->context, name);
        auto typeList = getTypeList(compiler, result);
        _structType->setBody(ArrayRef<Type *>(*typeList.get()));
    }
    return _structType;
}

Function* CFunction::getFunction(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::Compile);
    
    if (isInGetFunction) {
        result.addError(CLoc::undefined, CErrorCode::TypeLoop, "while trying to determine type a cycle was detected");
        return nullptr;
    }
    
    if (!function) {
        isInGetFunction = true;
        function = node->compileDefinition(compiler, result, shared_from_this(), thisVar);
        isInGetFunction = false;
        
        if (function) {
            returnMustRelease = node->compileBody(compiler, result, shared_from_this(), thisVar, function);
        }
    }
   
    return function;
}

bool CFunction::getReturnMustRelease(Compiler* compiler, CResult& result) {
    assert(function);
    return returnMustRelease;
}

Function* CFunction::getDestructor(Compiler* compiler, CResult& result) {
    if (!destructorFunction) {
        destructorFunction = node->compileDestructorDefinition(compiler, result, shared_from_this());        
        if (destructorFunction) {
            node->compileDestructorBody(compiler, result, shared_from_this(), destructorFunction);
        }
    }
    
    return destructorFunction;
}

Value* CFunction::getThisArgument(Compiler* compiler, CResult& result) {
    assert(getHasThis());
    return (Argument*)function->args().begin();
}

Value* CFunction::getArgumentPointer(Compiler* compiler, CResult& result, bool thisInEntry, Value* thisValue, int index, IRBuilder<>* builder) {
    if (thisInEntry) {
        auto function = getFunctionFromBuilder(builder);
        auto it = argumentPointers[function][thisValue].find(index);
        if (it == argumentPointers[function][thisValue].end()) {
            Value* argValue = nullptr;
            auto entryBuilder = compiler->getEntryBuilder(function);
            if (getHasThis()) {
                assert(thisValue->getType() == thisType->llvmRefType(compiler, result));
                vector<Value*> v;
                v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
                v.push_back(ConstantInt::get(compiler->context, APInt(32, index + getArgStart(compiler, result))));
                argValue = entryBuilder->CreateInBoundsGEP(thisType->llvmAllocType(compiler, result), thisValue, ArrayRef<Value *>(v), "paramPtr");
            } else {
                auto t = (Argument*)std::next(function->args().begin(), index + indexVars);
                auto argType = thisVars[index]->getType(compiler, result);
                argValue = entryBuilder->CreateAlloca(argType->llvmRefType(compiler, result));
                entryBuilder->CreateStore(t, argValue);
            }
            argumentPointers[function][thisValue][index] = argValue;
            return argValue;
        } else {
            return it->second;
        }
    } else {
        assert(getHasThis());
        assert(thisValue->getType() == thisType->llvmRefType(compiler, result));
        vector<Value*> v;
        v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
        v.push_back(ConstantInt::get(compiler->context, APInt(32, index + getArgStart(compiler, result))));
        return builder->CreateInBoundsGEP(thisType->llvmAllocType(compiler, result), thisValue, ArrayRef<Value *>(v), "paramPtr");
    }
}

shared_ptr<CFunction> CFunction::getCFunction(Compiler* compiler, CResult& result, const CLoc& loc, const string& name, shared_ptr<CFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames) {
    auto def = definition.lock();
    auto t = def->funcsByName.find(name);
    if (t != def->funcsByName.end()) {
        auto funcDef = t->second;
        
        vector<shared_ptr<CType>> templateTypes;
        if (templateTypeNames) {
            if (templateTypeNames->size() != funcDef->node->templateTypeNames->size()) {
                result.addError(loc, CErrorCode::InvalidTemplateArg, "size does not match");
                return nullptr;
            }
            
            // Map template type string list to type list
            for (auto templateTypeName : *templateTypeNames) {
                shared_ptr<CType> ctype = nullptr;
                if (callerFunction) {
                    ctype = callerFunction->getVarType(compiler, result, loc, templateTypeName);
                }
                
                if (!ctype) {
                    auto ctype = getVarType(compiler, result, loc, templateTypeName);
                    if (!ctype) {
                        result.addError(loc, CErrorCode::TemplateUnspecified, "cannot find template type: '%s'", templateTypeName->name.c_str());
                        return nullptr;
                    }
                }
                
                templateTypes.push_back(ctype);
            }
        } else {
            if (funcDef->node->templateTypeNames != nullptr) {
                result.addError(loc, CErrorCode::InvalidTemplateArg, "size does not match");
                return nullptr;                
            }
        }
        
        // Get function for type list
        return funcDef->getFunction(compiler, result, loc, templateTypes, shared_from_this());
    }
    return nullptr;
}

shared_ptr<CVar> CFunction::getCVar(Compiler* compiler, CResult& result, const CLoc& loc, const string& name) {
    auto t1 = localVarsByName.find(name);
    if (t1 != localVarsByName.end()) {
        return t1->second;
    }

    auto t2 = thisVarsByName.find(name);
    if (t2 != thisVarsByName.end()) {
        return t2->second.second;
    }
    
    if (!parent.expired()) {
        auto t3 = parent.lock()->getCVar(compiler, result, loc, name);
        if (t3) {
            if (t3->mode == Var_Local) {
                parent.lock()->localVarToThisVar(compiler, static_pointer_cast<CNormalVar>(t3));
            }
            return CParentVar::create(compiler, result, shared_from_this(), t3);
        }
    }
    
    return nullptr;
}

int CFunction::getThisIndex(const string& name) const {
    auto it = thisVarsByName.find(name);
    if (it != thisVarsByName.end()) {
        return it->second.first;
    }
    return -1;
}

void CFunction::localVarToThisVar(Compiler* compiler, shared_ptr<CNormalVar> localVar) {
    assert(compiler->state <= CompilerState::FixVar); // Cannot change vars after type has been created
    assert(localVar->mode == CVarType::Var_Local);
    
    auto pos = localVarsByName.end();
    for (auto it = localVarsByName.begin(); it != localVarsByName.end(); it++) {
        if (it->second == localVar) {
            pos = it;
            break;
        }
    }
    
    if (pos == localVarsByName.end()) {
        assert(false);
        return;
    }
    
    localVar->makeFunctionVar(node, (int)thisVars.size());
    int index = (int)thisVars.size();
    thisVars.push_back(localVar);
    thisVarsByName[pos->first] = pair<int, shared_ptr<CNormalVar>>(index, localVar);
    localVarsByName.erase(pos);
}

string CFunction::fullName(bool includeTemplateTypes) {
    stringstream ss;
    ss << definition.lock()->fullName();
    if (includeTemplateTypes) {
        if (templateTypes.size() > 0) {
            ss << "!";
        }
        
        if (templateTypes.size() > 1) {
            ss << "[";
        }
        
        for (auto it : templateTypes) {
            if (it != templateTypes.front()) {
                ss << ", ";
            }
            
            ss << it->name;
        }
        
        if (templateTypes.size() > 1) {
            ss << "]";
        }
    }
    return ss.str();
}

int CFunction::getArgStart(Compiler* compiler, CResult& result) {
    getThisType(compiler, result);
    return (int)indexVars;
}

bool CFunction::getHasParent(Compiler* compiler, CResult& result) {
    getThisType(compiler, result);
    return hasParent;
}

void CFunction::setHasParent(Compiler* compiler, CResult& result) {
    assert(!_structType);
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

void CFunction::onHasParent(std::function<void(Compiler*, CResult&)> notify) {
    delegateHasParent.push_back(notify);
}

shared_ptr<CType> CFunction::getVarType(Compiler* compiler, CResult& result, const CLoc& loc, shared_ptr<CTypeName> typeName) {
    if (typeName->templateTypeNames == nullptr) {
        auto t = templateTypesByName.find(typeName->name);
        if (t != templateTypesByName.end()) {
            return t->second;
        }
    }
    
    auto t2 = definition.lock()->funcsByName.find(typeName->name);
    if (t2 != definition.lock()->funcsByName.end()) {
        auto templateTypes = vector<shared_ptr<CType>>();
        if (typeName->templateTypeNames) {
            for (auto it : *typeName->templateTypeNames) {
                auto t = getVarType(compiler, result, loc, it);
                if (!t) {
                    return nullptr;
                }
                templateTypes.push_back(t);
            }
        }
        
        auto cfunc = t2->second->getFunction(compiler, result, loc, templateTypes, shared_from_this());
        return cfunc->getThisType(compiler, result);
    }
    
    if (!parent.expired()) {
        return parent.lock()->getVarType(compiler, result, loc, typeName);
    }
    
    return compiler->getType(typeName->name);
}

Value* CFunction::getParentPointer(Compiler* compiler, CResult& result, IRBuilder<>* builder, bool thisInEntry, Value* thisValue) {
    assert(hasParent);
    if (thisInEntry) {
        auto function = getFunctionFromBuilder(builder);
        auto it = parentPointers.find(function);
        if (it == parentPointers.end()) {
            Value* parentValue = nullptr;
            if (getHasThis()) {
                vector<Value*> v;
                v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
                v.push_back(ConstantInt::get(compiler->context, APInt(32, indexParent)));
                parentValue = compiler->getEntryBuilder(function)->CreateInBoundsGEP(thisType->llvmAllocType(compiler, result), thisValue, ArrayRef<Value *>(v), "parent");
            } else {
                auto entryBuilder = compiler->getEntryBuilder(function);
                auto t = (Argument*)std::next(function->args().begin(), indexParent);
                auto argType = parent.lock()->getThisType(compiler, result);
                parentValue = entryBuilder->CreateAlloca(argType->llvmRefType(compiler, result));
                entryBuilder->CreateStore(t, parentValue);
            }
            parentPointers[function] = parentValue;
            return parentValue;
        } else {
            return it->second;
        }
    } else {
        assert(getHasThis());
        vector<Value*> v;
        v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
        v.push_back(ConstantInt::get(compiler->context, APInt(32, indexParent)));
        return builder->CreateInBoundsGEP(thisType->llvmAllocType(compiler, result), thisValue, ArrayRef<Value *>(v), "parent");
    }
}

Value* CFunction::getParentValue(Compiler* compiler, CResult& result, IRBuilder<>* builder, bool thisInEntry, Value* thisValue) {
    assert(hasParent);
    if (thisInEntry) {
        auto function = getFunctionFromBuilder(builder);
        auto it = parentValues.find(function);
        if (it == parentValues.end()) {
            auto parentPointer = getParentPointer(compiler, result, builder, thisInEntry, thisValue);
            auto parentValue = compiler->getEntryBuilder(function)->CreateLoad(parentPointer, "parent");
            parentValues[function] = parentValue;
            return parentValue;
        } else {
            return it->second;
        }
    } else {
        auto parentPointer = getParentPointer(compiler, result, builder, thisInEntry, thisValue);
        return builder->CreateLoad(parentPointer, "parent");
    }
}

Value* CFunction::getRefCount(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
    assert(_structType);
    assert(hasRefCount);
    if (hasRefCount) {
        vector<Value*> v;
        v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
        v.push_back(ConstantInt::get(compiler->context, APInt(32, indexRefCount)));
        return builder->CreateInBoundsGEP(thisType->llvmAllocType(compiler, result), thisValue, ArrayRef<Value *>(v), "refCount");
    }
    return nullptr;
}

void CFunction::setHasRefCount() {
    assert(!_structType);
    hasRefCount = true;
}

void CFunction::initStack(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
    assert(_structType);
    compiler->recordRetain(builder, thisValue, name);
    if (hasRefCount) {
        auto refCount = getRefCount(compiler, result, builder, thisValue);
        assert(refCount);
        builder->CreateStore(ConstantInt::get(compiler->context, APInt(64, STACK_REF_COUNT + 1)), refCount);
    }
}

void CFunction::initHeap(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
    assert(_structType);
    assert(hasRefCount);
    compiler->recordRetain(builder, thisValue, name);

    auto refCount = getRefCount(compiler, result, builder, thisValue);
    assert(refCount);
    builder->CreateStore(ConstantInt::get(compiler->context, APInt(64, 1)), refCount);
}

void CFunction::retainStack(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
    assert(_structType);
    assert(hasRefCount);
    compiler->recordRetain(builder, thisValue, name);

    auto refCount = getRefCount(compiler, result, builder, thisValue);
    assert(refCount);
    auto foo = builder->CreateAdd(refCount, ConstantInt::get(compiler->context, APInt(64, 1)));
    builder->CreateStore(foo, refCount);
}

void CFunction::retainHeap(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
    assert(_structType);
    assert(hasRefCount);
    compiler->recordRetain(builder, thisValue, name);

    auto refCount = getRefCount(compiler, result, builder, thisValue);
    assert(refCount);
    auto load = builder->CreateLoad(refCount);
    auto add = builder->CreateAdd(load, ConstantInt::get(compiler->context, APInt(64, 1)));
    builder->CreateStore(add, refCount);
}

void CFunction::releaseStack(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
    assert(_structType);
    compiler->recordRelease(builder, thisValue, name);
    
#ifdef DEBUG_CALLSTACK
    if (hasRefCount) {
        auto refCount = getRefCount(compiler, result, builder, thisValue);
        auto load = builder->CreateLoad(refCount);
        auto sub = builder->CreateSub(load, ConstantInt::get(compiler->context, APInt(64, 1)));
        builder->CreateStore(sub, refCount);
        
        Function *function = builder->GetInsertBlock()->getParent();
        auto ifBB = BasicBlock::Create(compiler->context);
        auto mergeBB = BasicBlock::Create(compiler->context);
        
        auto c = builder->CreateICmpNE(sub, ConstantInt::get(compiler->context, APInt(64, STACK_REF_COUNT)));
        builder->CreateCondBr(c, ifBB, mergeBB);
        
        // If not at special stack ref count then fail
        function->getBasicBlockList().push_back(ifBB);
        builder->SetInsertPoint(ifBB);
        
        compiler->callDebug(builder, "did not release: " + name, thisValue, nullptr);

        builder->CreateBr(mergeBB);
        
        // Merge block
        function->getBasicBlockList().push_back(mergeBB);
        builder->SetInsertPoint(mergeBB);
    }
#endif

    // Call destructor
    auto destructor = getDestructor(compiler, result);
    if (destructor) {
        auto args = vector<Value*>();
        args.push_back(thisValue);
        builder->CreateCall(destructor, ArrayRef<Value*>(args));
    }
}

void CFunction::releaseHeap(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
    assert(hasRefCount);
    compiler->recordRelease(builder, thisValue, name);

    auto refCount = getRefCount(compiler, result, builder, thisValue);
    auto load = builder->CreateLoad(refCount);
    auto sub = builder->CreateSub(load, ConstantInt::get(compiler->context, APInt(64, 1)));
    builder->CreateStore(sub, refCount);

    Function *function = builder->GetInsertBlock()->getParent();
    auto ifBB = BasicBlock::Create(compiler->context);
    auto mergeBB = BasicBlock::Create(compiler->context);
    
    auto c = builder->CreateICmpSLE(sub, ConstantInt::get(compiler->context, APInt(64, 0)));
    builder->CreateCondBr(c, ifBB, mergeBB);

    // If zero then delete
    function->getBasicBlockList().push_back(ifBB);
    builder->SetInsertPoint(ifBB);
    
    // Call destructor
    auto destructor = getDestructor(compiler, result);
    if (destructor) {
        auto args = vector<Value*>();
        args.push_back(thisValue);
        builder->CreateCall(destructor, ArrayRef<Value*>(args));
    }
    
    // Delete "this"
    auto thisValueAsVoidPtr = builder->CreateBitCast(thisValue, Type::getInt8PtrTy(compiler->context));
    auto args = vector<Value*>();
    args.push_back(thisValueAsVoidPtr);
    auto free = compiler->getFreeFunction();
    builder->CreateCall(free, ArrayRef<Value*>(args));
    
    builder->CreateBr(mergeBB);
    
    // Merge block
    function->getBasicBlockList().push_back(mergeBB);
    builder->SetInsertPoint(mergeBB);
}

shared_ptr<CFunctionDefinition> CFunctionDefinition::create(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> parent, CFunctionType type, const string& name, shared_ptr<NFunction> node) {
    auto c = make_shared<CFunctionDefinition>();
    c->parent = parent;
    c->type = type;
    c->name = name;
    c->node = node;
    
    if (node) {
        for (auto it : node->functions) {
            assert(type != FT_Extern && "Not allowed for extern functions");
            c->funcsByName[it->name] = CFunctionDefinition::create(compiler, result, c, FT_Private, it->name, it);
        }
        
        for (auto it : node->assignments) {
            if (it->var) {
                result.addError(it->loc, CErrorCode::InvalidDot, "cannot use '.' in variable declaration for a function: '%s'", it->name.c_str());
            }
        }
    }
    return c;
}

string CFunctionDefinition::fullName() {
    string n = name;
    auto p = parent;
    while (!p.expired() && !p.lock()->parent.expired() && p.lock()->name != "global") {
        n.insert(0, "_");
        n.insert(0, p.lock()->name);
        p = p.lock()->parent;
    }
    return n;
}

shared_ptr<CFunction> CFunctionDefinition::getFunction(Compiler* compiler, CResult& result, const CLoc& loc, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CFunction> funcParent) {
    shared_ptr<CFunction> func;
    auto it = cfunctions.find(templateTypes);
    if (it != cfunctions.end()) {
        func = it->second;
    } else {
        assert(funcParent.expired() || funcParent.lock()->definition.lock() == parent.lock());
        func = CFunction::create(compiler, result, loc, shared_from_this(), templateTypes, funcParent, type, name, node);
        cfunctions[templateTypes] = func;
    }
    return func;
}

void CFunctionDefinition::dump(Compiler* compiler, CResult& result, int level) {
    // Skip if this is the function around global    
    if (funcsByName.size() > 0) {
        for (auto it : funcsByName) {
            it.second->dump(compiler, result, level);
        }
    }
}

