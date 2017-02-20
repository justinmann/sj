//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "Node.h"

shared_ptr<CInterfaceMethod> CInterfaceMethod::create(Compiler* compiler, CResult& result, weak_ptr<CInterface> parent_, shared_ptr<NInterfaceMethod> ninterfaceMethod_) {
    auto c = make_shared<CInterfaceMethod>();
    c->name = ninterfaceMethod_->name;
    c->parent = parent_;
    c->ninterfaceMethod = ninterfaceMethod_;
/* TODO:
    for (auto it : templateTypes_) {
        c->name = c->name + "_" + it->name;
    }
    
    if (c->ninterfaceMethod) {
        if (c->ninterfaceMethod->templateTypeNames) {
            assert(c->ninterfaceMethod->templateTypeNames->size() == templateTypes_.size());
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
        
        for (auto it : c->ninterfaceMethod->assignments) {
            if (it->var) {
                result.addError(it->loc, CErrorCode::InvalidDot, "cannot use '.' in variable declaration for a function: '%s'", it->name.c_str());
            }
            
            int index = (int)c->argVars.size();
            auto argVar = CNormalVar::createFunctionVar(c->ninterfaceMethod->loc, it->name, nullptr, c->ninterfaceMethod, index, it, nullptr);
            c->argVars.push_back(argVar);
        }
    }*/
    
    return c;
}

shared_ptr<CType> CInterfaceMethod::getReturnType(Compiler* compiler, CResult& result) {
    return ninterfaceMethod->getBlockType(compiler, result, shared_from_this());
}

shared_ptr<CType> CInterfaceMethod::getVarType(Compiler* compiler, CResult& result, shared_ptr<CTypeName> typeName) {
    if (typeName->templateTypeNames == nullptr) {
        auto t = templateTypesByName.find(typeName->name);
        if (t != templateTypesByName.end()) {
            return t->second;
        }
    }
    
    if (!parent.expired()) {
        return parent.lock()->getVarType(compiler, result, typeName);
    }
    
    return compiler->getType(typeName->name);
}
