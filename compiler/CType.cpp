//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "Node.h"

CType::CType(const char* name, Type* type) : name(name), _llvmAllocType(type), _llvmRefType(type) { }

CType::CType(Compiler* compiler, const char* name, shared_ptr<CFunction> cfunction_) : name(name), cfunction(cfunction_), _llvmAllocType(nullptr), _llvmRefType(nullptr) {
}

Type* CType::llvmAllocType(Compiler* compiler, CResult& result) {
    assert(compiler->state == CompilerState::Compile);
    if (!_llvmAllocType) {
        auto structType = StructType::create(compiler->context, name);
        _llvmAllocType = structType;

        vector<Type*> structMembers;
        auto index = 0;
        for (auto it : cfunction.lock()->thisVars) {
            auto ctype = it->getType(compiler, result);
            if (!ctype) {
                result.addError(it->nassignment->loc, CErrorCode::InvalidType, "cannot determine type for '%s'", it->name.c_str());
                return nullptr;
            }

            membersByName[it->name] = pair<int, shared_ptr<CType>>(index, ctype);
            members.push_back(ctype);
            structMembers.push_back(ctype->llvmRefType(compiler, result));
            index++;
        }

        structType->setBody(ArrayRef<Type *>(structMembers));        
    }
    return _llvmAllocType;
}

Type* CType::llvmRefType(Compiler *compiler, CResult& result) {
    if (!_llvmRefType) {
        _llvmRefType = llvmAllocType(compiler, result)->getPointerTo();
    }
    return _llvmRefType;
}


