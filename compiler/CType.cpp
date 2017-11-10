//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "../node/Node.h"

CType::CType(const char* name, const char* cname, const char* defaultValue) : category(CTC_Value), name(name), nameValue(cname), nameRef(cname), _defaultValue(defaultValue) {
}

CType::CType(const char* name, weak_ptr<CFunction> parent) : category(CTC_Function), name(name), nameValue(string("sjs_") + name), nameRef(string("sjs_") + name + "*"), parent(parent) {
}

CType::CType(const char* name, weak_ptr<CInterface> parent) : category(CTC_Interface), name(name), nameValue(string("sji_") + name), nameRef(string("sji_") + name + "*"), parent(parent) {
}

shared_ptr<ReturnValue> CType::transpileDefaultValue(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    if (parent.expired()) {
        return make_shared<ReturnValue>(shared_from_this(), false, RVR_MustRetain, _defaultValue);
    } else {
        assert(false);
        return nullptr;
    }
}
