//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "Node.h"

string CVar::fullName() {
    return strprintf("%s.%s", parent.lock()->fullName().c_str(), name.c_str());
}

shared_ptr<CFunction> CVar::getCFunctionForValue(Compiler* compiler, CResult& result) {
    auto ctype = getType(compiler, result);
    if (ctype && !ctype->parent.expired()) {
        return ctype->parent.lock();
    }
    return nullptr;
}

shared_ptr<CLocalVar> CLocalVar::create(const CLoc& loc, const string& name, shared_ptr<CFunction> parent, shared_ptr<NAssignment> nassignment) {
    auto c = make_shared<CLocalVar>();
    c->loc = loc;
    c->mode = CVarType::Local;
    c->name = name;
    c->isMutable = nassignment->isMutable;
    c->nassignment = nassignment;
    c->parent = parent;
    return c;
}

shared_ptr<CType> CLocalVar::getType(Compiler* compiler, CResult& result) {
    if (isInGetType) {
        result.addError(CLoc::undefined, CErrorCode::TypeLoop, "while trying to determine type a cycle was detected");
        return nullptr;
    }
    
    isInGetType = true;
    if (!type) {
        type = nassignment->getType(compiler, result, parent.lock());
    }
    isInGetType = false;
    return type;
}

Value* CLocalVar::getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    auto value = getStoreValue(compiler, result, thisValue, dotValue, builder, catchBB);
    return builder->CreateLoad(value);
}

Value* CLocalVar::getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    if (!value) {
        IRBuilder<> entryBuilder = getEntryBuilder(builder);
        auto valueType = getType(compiler, result)->llvmRefType(compiler, result);
        if (valueType->isVoidTy()) {
            result.addError(loc, CErrorCode::StoringVoid, "cannot save a void value");
            return nullptr;
        }
        value = entryBuilder.CreateAlloca(valueType, 0, name.c_str());
    }
    return value;
}
