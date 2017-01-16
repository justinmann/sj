//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "Node.h"

CType::CType(const char* name, Type* llvmAllocType) : name(name), _llvmAllocType(llvmAllocType), _llvmRefType(llvmAllocType) {
}

CType::CType(const char* name, weak_ptr<CFunction> parent) : name(name), parent(parent), _llvmAllocType(nullptr), _llvmRefType(nullptr) {
}

Type* CType::llvmAllocType(Compiler* compiler, CResult& result) {
    if (!_llvmAllocType) {
        _llvmAllocType = parent.lock()->getStructType(compiler, result);
    }
    return _llvmAllocType;
}

Type* CType::llvmRefType(Compiler* compiler, CResult& result) {
    if (!_llvmRefType) {
        _llvmRefType = llvmAllocType(compiler, result)->getPointerTo();
    }
    return _llvmRefType;
}
