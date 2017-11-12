//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "../node/Node.h"

CType::CType(const char* name_, const char* cname, const char* defaultValue, bool isOption) : category(CTC_Value), name(name_), nameValue(cname), nameRef(cname), _defaultValue(defaultValue), isOption(isOption) {
    if (isOption) {
        assert(name.back() == '?');
    }
}

CType::CType(const char* name_, weak_ptr<CFunction> parent, bool isOption) : category(CTC_Value), name(name_), nameValue(parent.lock()->getStructName()), nameRef(parent.lock()->getStructName() + "*"), parent(parent), isOption(isOption) {
    if (isOption) {
        assert(name.back() == '?');
    }
}

CType::CType(const char* name_, weak_ptr<CInterface> parent, bool isOption) : category(CTC_Interface), name(name_), nameValue(parent.lock()->getStructName()), nameRef(parent.lock()->getStructName() + "*"), parent(parent), isOption(isOption) {
    assert(name[0] == '#');
    if (isOption) {
        assert(name.back() == '?');
    }
}

shared_ptr<ReturnValue> CType::transpileDefaultValue(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    if (parent.expired()) {
        return make_shared<ReturnValue>(shared_from_this(), false, RVR_MustRetain, _defaultValue);
    } else {
        assert(false);
        return nullptr;
    }
}
