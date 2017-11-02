//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "../node/Node.h"

CType::CType(const char* name, const char* defaultValue) : category(CTC_Value), name(name), nameValue(name), nameRef(name), _defaultValue(defaultValue) {
}

CType::CType(const char* name, weak_ptr<CFunction> parent) : category(CTC_Function), name(name), nameValue(string("sjs_") + name), nameRef(string("sjs_") + name + "*"), parent(parent) {
}

CType::CType(const char* name, weak_ptr<CInterface> parent) : category(CTC_Interface), name(name), nameValue(string("sjs_") + name), nameRef(string("sjs_") + name + "*"), parent(parent) {
}

void CType::transpileDefaultValue(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, stringstream& line) {
    if (parent.expired()) {
        line << _defaultValue;
    } else {
        assert(false);
    }
}
