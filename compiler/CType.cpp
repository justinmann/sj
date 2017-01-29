//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "Node.h"

CType::CType(const char* name, Type* llvmAllocType, Value* value) : name(name), _llvmAllocType(llvmAllocType), _llvmRefType(llvmAllocType), _value(value) {
}

CType::CType(const char* name, weak_ptr<CFunction> parent) : name(name), parent(parent), _llvmAllocType(nullptr), _llvmRefType(nullptr), _value(nullptr) {
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

shared_ptr<ReturnValue> CType::getDefaultValue(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    if (parent.expired()) {
        return _value ? make_shared<ReturnValue>(_value) : nullptr;
    } else {
        return parent.lock()->getDefaultValue(compiler, result, thisFunction, thisValue, builder, catchBB);
    }
}
