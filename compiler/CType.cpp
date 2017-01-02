//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "Node.h"

CType::CType(const char* name, Type* type) : name(name), llvmAllocType(type), llvmRefType(type) { }

CType::CType(Compiler* compiler, const char* name, CFunction* cfunction, vector<pair<string, shared_ptr<CType>>> members_) : name(name), cfunction(cfunction) {
    auto structType = StructType::create(compiler->context, name);
    
    vector<Type*> structMembers;
    auto index = 0;
    for (auto it : members_) {
        membersByName[it.first] = pair<int, shared_ptr<CType>>(index, it.second);
        members.push_back(it.second);
        structMembers.push_back(it.second->llvmRefType);
        index++;
    }
    
    // if we have a parent then we get a parent pointer
    if (cfunction->parent) {
        CResult result;
        auto parentType = cfunction->parent->getThisType(compiler, result);
        if (parentType) {
            membersByName["parent"] = pair<int, shared_ptr<CType>>(index, parentType);
            members.push_back(parentType);
            structMembers.push_back(parentType->llvmRefType);
            index++;
        }
    }
    
    structType->setBody(ArrayRef<Type *>(structMembers));
    
    llvmAllocType = structType;
    llvmRefType = llvmAllocType->getPointerTo();
}


