//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "Node.h"

shared_ptr<CType> CLocalVar::getType(Compiler* compiler, CResult& result) {
    if (isInGetType) {
        result.errors.push_back(CError(CLoc::undefined, CErrorCode::TypeLoop));
        return nullptr;
    }
    
    isInGetType = true;
    if (!type) {
        type = shared_ptr<CType>(node->getReturnType(compiler, result));
    }
    isInGetType = false;
    return type;
}

Value* CLocalVar::getValue(Compiler* compiler, CResult& result) {
    if (!value) {
        Function* f = parent->getFunction(compiler, result);
        IRBuilder<> builder(&f->getEntryBlock(), f->getEntryBlock().begin());
        value = builder.CreateAlloca(getType(compiler, result)->llvmRefType, 0, node->name.c_str());
    }
    return value;
}