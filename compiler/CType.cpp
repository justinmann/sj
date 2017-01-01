//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "Node.h"

CType::CType(const char* name, Type* type) : name(name), llvmAllocType(type), llvmRefType(type) { }

CType::CType(Compiler* compiler, const char* name, vector<pair<string, shared_ptr<CType>>> members_) {
    auto structType = StructType::create(compiler->context, name);
    
    vector<Type*> structMembers;
    auto index = 0;
    for (auto it : members_) {
        membersByName[it.first] = pair<int, shared_ptr<CType>>(index, it.second);
        members.push_back(it.second);
        structMembers.push_back(it.second->llvmRefType);
        index++;
    }
    
    structType->setBody(ArrayRef<Type *>(structMembers));
    
    llvmAllocType = structType;
    llvmRefType = llvmAllocType->getPointerTo();
}


