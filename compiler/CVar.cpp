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

int CVar::setHeapVar() {
    if (!isHeapVar) {
        isHeapVar = true;
        return 1;
    }
    return 0;
}

shared_ptr<CFunction> CVar::getCFunctionForValue(Compiler* compiler, CResult& result) {
    auto ctype = getType(compiler, result);
    if (ctype && !ctype->parent.expired()) {
        return ctype->parent.lock();
    }
    return nullptr;
}

shared_ptr<CNormalVar> CNormalVar::createLocalVar(const CLoc& loc, const string& name, shared_ptr<CFunction> parent, shared_ptr<NAssignment> nassignment) {
    auto c = make_shared<CNormalVar>();
    c->loc = loc;
    c->mode = CVarType::Local;
    c->name = name;
    c->isMutable = nassignment->isMutable;
    c->nassignment = nassignment;
    c->parent = parent;
    return c;
}

shared_ptr<CNormalVar> CNormalVar::createFunctionVar(const CLoc& loc, const string& name, shared_ptr<CFunction> parent, shared_ptr<NFunction> nfunction, int index, shared_ptr<NAssignment> nassignment, shared_ptr<CType> type) {
    auto c = make_shared<CNormalVar>();
    c->loc = loc;
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

void CNormalVar::makeFunctionVar(shared_ptr<NFunction> nfunction, int index) {
    assert(mode == CVarType::Local);
    mode = CVarType::Public;
    this->nfunction = nfunction;
    this->index = index;
}

shared_ptr<CType> CNormalVar::getType(Compiler* compiler, CResult& result) {
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

Value* CNormalVar::getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    if (mode == Local) {
        auto value = getStoreValue(compiler, result, thisValue, dotValue, builder, catchBB);
        return builder->CreateLoad(value);
    } else {
        return builder->CreateLoad(getStoreValue(compiler, result, thisValue, dotValue, builder, catchBB));
    }
}

Value* CNormalVar::getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    if (mode == Local) {
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
    } else {
        return parent.lock()->getArgumentPointer(compiler, result, dotValue, index, builder);
    }
}


