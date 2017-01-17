//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "Node.h"

shared_ptr<CFunctionVar> CFunctionVar::create(const string& name, shared_ptr<CFunction> parent, shared_ptr<NFunction> nfunction, int index, shared_ptr<NAssignment> nassignment, shared_ptr<CType> type) {
    auto c = make_shared<CFunctionVar>();
    c->mode = CVarType::Public;
    c->name = name;
    c->isMutable = nassignment != nullptr ? nassignment->isMutable : false;
    c->nfunction = nfunction;
    c->index = index;
    c->nassignment = nassignment;
    c->parent = parent;
    c->type = type;
    
    assert(type != nullptr || nassignment != nullptr);
    
    return c;
}

shared_ptr<CType> CFunctionVar::getType(Compiler* compiler, CResult& result) {
    if (isInGetType) {
        result.addError(CLoc::undefined, CErrorCode::TypeLoop, "while trying to determine type a cycle was detected");
        return nullptr;
    }
    
    isInGetType = true;
    if (!type) {
        type = nassignment->getReturnType(compiler, result, parent.lock());
    }
    isInGetType = false;
    return type;
}

Value* CFunctionVar::getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, IRBuilder<>* builder) {
    return builder->CreateLoad(getStoreValue(compiler, result, thisValue, builder));
}

Value* CFunctionVar::getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, IRBuilder<>* builder) {
    return parent.lock()->getArgumentPointer(compiler, result, thisValue, index, builder);
}

shared_ptr<CThisVar> CThisVar::create(shared_ptr<CFunction> parent) {
    auto c = make_shared<CThisVar>();
    c->mode = CVarType::Public;
    c->name = "this";
    c->isMutable = false;
    c->parent = parent;
    return c;
}

shared_ptr<CType> CThisVar::getType(Compiler* compiler, CResult& result) {
    return parent.lock()->getThisType(compiler, result);
}

Value* CThisVar::getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, IRBuilder<>* builder) {
    assert(false);
}

Value* CThisVar::getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, IRBuilder<>* builder) {
    assert(false);
}

shared_ptr<CFunction> CFunction::create(Compiler* compiler, CResult& result, const CLoc& loc, weak_ptr<CFunctionDefinition> definition_, vector<shared_ptr<CType>>& templateTypes_, weak_ptr<CFunction> parent_, CFunctionType type_, const string& name_, shared_ptr<NFunction> node_) {
    auto c = make_shared<CFunction>();
    c->definition = definition_;
    c->templateTypes = templateTypes_;
    c->parent = parent_;
    c->type = type_;
    c->name = name_;
    c->node = node_;
    c->hasParent = false;
    c->_structType = nullptr;
    c->function = nullptr;
    
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
            if (it->names.size() != 1) {
                result.addError(it->loc, CErrorCode::InvalidDot, "cannot use '.' in variable declaration for a function: '%s'", it->fullName.c_str());
            }

            int index = (int)c->thisVars.size();
            auto thisVar = CFunctionVar::create(it->names[0], c, c->node, index, it, nullptr);
            c->thisVarsByName[it->names[0]] = pair<int, shared_ptr<CVar>>(index, thisVar);
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

shared_ptr<CType> CFunction::getThisType(Compiler* compiler, CResult& result) {
    if (type == FT_Extern) {
        return nullptr;
    }

    if (!thisType && node != nullptr) {
        thisType = make_shared<CType>(node->name.c_str(), shared_from_this());

    }
 
    return thisType;
}

Type* CFunction::getStructType(Compiler* compiler, CResult& result) {
    if (!_structType) {
        _structType = StructType::create(compiler->context, name);

        vector<Type*> structMembers;
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
            node->compileBody(compiler, result, shared_from_this(), function);
        }
    }
   
    return function;
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

shared_ptr<CFunction> CFunction::getCFunction(Compiler* compiler, CResult& result, const CLoc& loc, const string& name, shared_ptr<TemplateTypeNames> templateTypeNames) {
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
                auto ctype = getVarType(compiler, result, loc, templateTypeName.first, templateTypeName.second);
                if (!ctype) {
                    result.addError(loc, CErrorCode::TemplateUnspecified, "cannot find template type: '%s'", templateTypeName.first.c_str());
                    return nullptr;
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

shared_ptr<CVar> CFunction::getCVar(const string& name) const {
    auto t1 = localVarsByName.find(name);
    if (t1 != localVarsByName.end()) {
        return t1->second;
    }

    auto t2 = thisVarsByName.find(name);
    if (t2 != thisVarsByName.end()) {
        return t2->second.second;
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

shared_ptr<CFunctionVar> CFunction::localVarToThisVar(Compiler* compiler, shared_ptr<CLocalVar> localVar) {
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
        return nullptr;
    }
    
    
    auto thisVar = CFunctionVar::create(localVar->name, shared_from_this(), node, (int)thisVars.size(), localVar->nassignment, nullptr);
    int index = (int)thisVars.size();
    thisVars.push_back(thisVar);
    thisVarsByName[pos->first] = pair<int, shared_ptr<CFunctionVar>>(index, thisVar);
    localVarsByName.erase(pos);
    
    return thisVar;
}

string CFunction::fullName() {
    return definition.lock()->fullName();
}

int CFunction::getArgStart(Compiler* compiler, CResult& result) {
    getThisType(compiler, result);
    if (hasParent)
        return 1;
    
    return 0;
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
        vector<Value*> v;
        v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
        v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
        return builder->CreateInBoundsGEP(thisType->llvmAllocType(compiler, result), thisValue, ArrayRef<Value *>(v), "parent");
    }
    return nullptr;
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
            if (it->names.size() != 1) {
                result.addError(it->loc, CErrorCode::InvalidDot, "cannot use '.' in variable declaration for a function: '%s'", it->fullName.c_str());
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
        node->fixVarBody(compiler, result, func);
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

