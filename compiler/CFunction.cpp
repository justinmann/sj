//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "Node.h"
#define STACK_REF_COUNT         1000000000000

class CThisVar : public CVar {
public:
    static shared_ptr<CThisVar> create(shared_ptr<CFunction> parent);
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    virtual shared_ptr<ReturnValue> getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    virtual Value* getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    
    CLoc loc;
};

shared_ptr<CThisVar> CThisVar::create(shared_ptr<CFunction> parent) {
    auto c = make_shared<CThisVar>();
    c->mode = CVarType::Public;
    c->name = "this";
    c->isMutable = false;
    c->loc = CLoc::undefined;
    c->parent = parent;
    return c;
}

shared_ptr<CType> CThisVar::getType(Compiler* compiler, CResult& result) {
    return parent.lock()->getThisType(compiler, result);
}

shared_ptr<ReturnValue> CThisVar::getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    return make_shared<ReturnValue>(parent.lock(), false, RVT_HEAP, thisValue);
}

Value* CThisVar::getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    result.addError(loc, CErrorCode::ImmutableAssignment, "cannot assign to this");
    return nullptr;
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
                if (templateTypeName.second != nullptr) {
                    result.addError(loc, CErrorCode::InvalidType, "cannot use ! in template type name");
                    return nullptr;
                }
                c->templateTypesByName[templateTypeName.first] = templateTypes_[index];
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

shared_ptr<CType> CFunction::getReturnType(Compiler* compiler, CResult& result) {
    if (isInGetType) {
        result.addError(CLoc::undefined, CErrorCode::TypeLoop, "while trying to determine type a cycle was detected");
        return nullptr;
    }
    
    isInGetType = true;
    
    if (!returnType) {
        returnType = node->getBlockType(compiler, result, shared_from_this());
    }
    
    isInGetType = false;
    return returnType;
}

shared_ptr<CVar> CFunction::getReturnVar(Compiler* compiler, CResult& result) {
    return node->getReturnVar(compiler, result, shared_from_this());
}

shared_ptr<CType> CFunction::getThisType(Compiler* compiler, CResult& result) {
    if (type == FT_Extern) {
        return nullptr;
    }

    if (!thisType && node != nullptr) {
        thisType = make_shared<CType>(name.c_str(), shared_from_this());

    }
 
    return thisType;
}

Type* CFunction::getStructType(Compiler* compiler, CResult& result) {
    if (!_structType) {
        _structType = StructType::create(compiler->context, name);
        
        vector<Type*> structMembers;

        structMembers.push_back(Type::getInt64Ty(compiler->context));
        hasRefCount = true;

        if (!parent.expired()) {
            auto parentType = parent.lock()->getThisType(compiler, result);
            if (parentType) {
                structMembers.push_back(parentType->llvmRefType(compiler, result));
                hasParent = true;
            }
        }
        
        for (auto it : thisVars) {
            auto ctype = it->getType(compiler, result);
            if (!ctype) {
                result.addError(it->nassignment->loc, CErrorCode::InvalidType, "cannot determine type for '%s'", it->name.c_str());
                return nullptr;
            }
            structMembers.push_back(ctype->llvmRefType(compiler, result));
        }
        
        _structType->setBody(ArrayRef<Type *>(structMembers));
    }
    return _structType;
}

Function* CFunction::getFunction(Compiler* compiler, CResult& result) {
    assert(compiler->state == CompilerState::Compile);
    
    if (isInGetFunction) {
        result.addError(CLoc::undefined, CErrorCode::TypeLoop, "while trying to determine type a cycle was detected");
        return nullptr;
    }
    
    if (!function) {
        isInGetFunction = true;
        function = node->compileDefinition(compiler, result, shared_from_this());
        isInGetFunction = false;
        
        if (function) {
            returnMustRelease = node->compileBody(compiler, result, shared_from_this(), function);
        }
    }
   
    return function;
}

bool CFunction::getReturnMustRelease(Compiler* compiler, CResult& result) {
    getFunction(compiler, result);
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
    auto function = getFunction(compiler, result);
    return (Argument*)function->args().begin();
}

Value* CFunction::getArgumentPointer(Compiler* compiler, CResult& result, Value* thisValue, int index, IRBuilder<>* builder) {
    auto thisType = getThisType(compiler, result);
    assert(thisValue->getType() == thisType->llvmRefType(compiler, result));
    vector<Value*> v;
    v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
    v.push_back(ConstantInt::get(compiler->context, APInt(32, index + getArgStart(compiler, result))));
    auto paramPtr = builder->CreateInBoundsGEP(thisType->llvmAllocType(compiler, result), thisValue, ArrayRef<Value *>(v), "paramPtr");
    return paramPtr;
}

shared_ptr<CFunction> CFunction::getCFunction(Compiler* compiler, CResult& result, const CLoc& loc, const string& name, shared_ptr<CFunction> callerFunction, shared_ptr<TemplateTypeNames> templateTypeNames) {
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
                    ctype = callerFunction->getVarType(compiler, result, loc, templateTypeName.first, templateTypeName.second);
                }
                
                if (!ctype) {
                    auto ctype = getVarType(compiler, result, loc, templateTypeName.first, templateTypeName.second);
                    if (!ctype) {
                        result.addError(loc, CErrorCode::TemplateUnspecified, "cannot find template type: '%s'", templateTypeName.first.c_str());
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
            if (t3->mode == Local) {
                parent.lock()->localVarToThisVar(compiler, static_pointer_cast<CNormalVar>(t3));
            }
            return CParentVar::create(shared_from_this(), t3);
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
    assert(localVar->mode == CVarType::Local);
    
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

string CFunction::fullName() {
    return definition.lock()->fullName();
}

int CFunction::getArgStart(Compiler* compiler, CResult& result) {
    getThisType(compiler, result);
    
    int argStart = 0;
    
    if (hasRefCount)
        argStart++;
    
    if (hasParent)
        argStart++;
    
    return argStart;
}

bool CFunction::getHasParent(Compiler* compiler, CResult& result) {
    getThisType(compiler, result);
    return hasParent;
}

shared_ptr<CType> CFunction::getVarType(Compiler* compiler, CResult& result, const CLoc& loc, const string& name, shared_ptr<TemplateTypeNames> subTypeNames) {
    if (subTypeNames == nullptr) {
        auto t = templateTypesByName.find(name);
        if (t != templateTypesByName.end()) {
            return t->second;
        }
    }
    
    auto t2 = definition.lock()->funcsByName.find(name);
    if (t2 != definition.lock()->funcsByName.end()) {
        auto templateTypes = vector<shared_ptr<CType>>();
        if (subTypeNames) {
            for (auto it : *subTypeNames) {
                auto t = getVarType(compiler, result, loc, it.first, it.second);
                if (!t) {
                    return nullptr;
                }
                templateTypes.push_back(t);
            }
        }
        
        auto cfunc = t2->second->getFunction(compiler, result, loc, templateTypes, shared_from_this());
        return cfunc->getThisType(compiler, result);
    }
    
    if (subTypeNames == nullptr && !parent.expired()) {
        return parent.lock()->getVarType(compiler, result, loc, name, subTypeNames);
    }
    
    return compiler->getType(name);
}

Value* CFunction::getParentPointer(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
    if (hasParent) {
        assert(hasRefCount);
        vector<Value*> v;
        v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
        v.push_back(ConstantInt::get(compiler->context, APInt(32, 1)));
        return builder->CreateInBoundsGEP(thisType->llvmAllocType(compiler, result), thisValue, ArrayRef<Value *>(v), "parent");
    }
    return nullptr;
}

shared_ptr<ReturnValue> CFunction::getDefaultValue(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    auto parameters = vector<shared_ptr<NBase>>();
    for (auto defaultAssignment : node->assignments) {
        parameters.push_back(defaultAssignment->rightSide);
    }
    return node->call(compiler, result, thisFunction, thisValue, shared_from_this(), nullptr, builder, catchBB, parameters);
}

shared_ptr<CVar> CFunction::getThisVar() {
    if (!thisVar) {
        thisVar = CThisVar::create(shared_from_this());
    }
    return thisVar;
}

Value* CFunction::getRefCount(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
    if (hasRefCount) {
        vector<Value*> v;
        v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
        v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
        return builder->CreateInBoundsGEP(thisType->llvmAllocType(compiler, result), thisValue, ArrayRef<Value *>(v), "refCount");
    }
    return nullptr;
}

void CFunction::initStack(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
    auto refCount = getRefCount(compiler, result, builder, thisValue);
    assert(refCount);
    builder->CreateStore(ConstantInt::get(compiler->context, APInt(64, STACK_REF_COUNT)), refCount);
}

void CFunction::initHeap(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
    auto refCount = getRefCount(compiler, result, builder, thisValue);
    assert(refCount);
    builder->CreateStore(ConstantInt::get(compiler->context, APInt(64, 1)), refCount);
}

void CFunction::retainStack(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
    auto refCount = getRefCount(compiler, result, builder, thisValue);
    assert(refCount);
    auto foo = builder->CreateAdd(refCount, ConstantInt::get(compiler->context, APInt(64, 1)));
    builder->CreateStore(foo, refCount);
}

void CFunction::retainHeap(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
    auto refCount = getRefCount(compiler, result, builder, thisValue);
    assert(refCount);
    auto load = builder->CreateLoad(refCount);
    auto add = builder->CreateAdd(load, ConstantInt::get(compiler->context, APInt(64, 1)));
    builder->CreateStore(add, refCount);
}

void CFunction::releaseStack(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
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
    // TODO: debug output failure, stack object is still being used
    builder->CreateBr(mergeBB);
    
    // Merge block
    function->getBasicBlockList().push_back(mergeBB);
    builder->SetInsertPoint(mergeBB);

    // Call destructor
    auto destructor = getDestructor(compiler, result);
    if (destructor) {
        auto args = vector<Value*>();
        args.push_back(thisValue);
        builder->CreateCall(destructor, ArrayRef<Value*>(args));
    }
}

void CFunction::releaseHeap(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
    auto refCount = getRefCount(compiler, result, builder, thisValue);
    auto load = builder->CreateLoad(refCount);
    auto sub = builder->CreateSub(load, ConstantInt::get(compiler->context, APInt(64, 1)));
    builder->CreateStore(sub, refCount);

    Function *function = builder->GetInsertBlock()->getParent();
    auto ifBB = BasicBlock::Create(compiler->context);
    auto mergeBB = BasicBlock::Create(compiler->context);
    
    auto c = builder->CreateICmpEQ(sub, ConstantInt::get(compiler->context, APInt(64, 0)));
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
    while (!p.expired() && !p.lock()->parent.expired()) {
        n.insert(0, ".");
        n.insert(0, p.lock()->name);
        p = p.lock()->parent;
    }
    return n;
}

shared_ptr<CFunction> CFunctionDefinition::getFunction(Compiler* compiler, CResult& result, const CLoc& loc, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CFunction> funcParent) {
    auto it = cfunctions.find(templateTypes);
    if (it != cfunctions.end()) {
        return it->second;
    }
    
    assert(funcParent.expired() || funcParent.lock()->definition.lock() == parent.lock());
    auto func = CFunction::create(compiler, result, loc, shared_from_this(), templateTypes, funcParent, type, name, node);
    cfunctions[templateTypes] = func;

    if (node) {
        node->getVarBody(compiler, result, func);
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

