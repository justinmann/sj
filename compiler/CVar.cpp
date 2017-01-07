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

shared_ptr<CLocalVar> CLocalVar::create(const string& name, shared_ptr<CFunction> parent, shared_ptr<NAssignment> nassignment) {
    auto c = make_shared<CLocalVar>();
    c->mode = CVarType::Local;
    c->name = name;
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
        type = nassignment->getReturnType(compiler, result, parent.lock());
    }
    isInGetType = false;
    return type;
}

Value* CLocalVar::getValue(Compiler* compiler, CResult& result, Value* thisValue, IRBuilder<>* builder) {
    if (!value) {
        IRBuilder<> entryBuilder = getEntryBuilder(builder);
        value = entryBuilder.CreateAlloca(getType(compiler, result)->llvmRefType(compiler, result), 0, name.c_str());
    }
    return value;
}
