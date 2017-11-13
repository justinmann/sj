//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "../node/Node.h"

pair<shared_ptr<CType>, shared_ptr<CType>> CType::create(string name_, string cname, string defaultValue, string cnameOption, string defaultValueOption) {
    auto ctypeNotOption = make_shared<CType>();
    auto ctypeOption = make_shared<CType>();

    ctypeNotOption->isOption = false;
    ctypeNotOption->category = CTC_Value;
    ctypeNotOption->name = name_;
    ctypeNotOption->nameValue = cname;
    ctypeNotOption->nameRef = cname;
    ctypeNotOption->_defaultValue = defaultValue;
    ctypeNotOption->_otherType = ctypeOption;

    ctypeOption->isOption = true;
    ctypeOption->category = CTC_Value;
    ctypeOption->name = name_ + "?";
    ctypeOption->nameValue = cname;
    ctypeOption->nameRef = cname;
    ctypeOption->_defaultValue = defaultValue;
    ctypeOption->_otherType = ctypeNotOption;

    return make_pair(ctypeNotOption, ctypeOption);
}

pair<shared_ptr<CType>, shared_ptr<CType>> CType::create(string name_, weak_ptr<CFunction> parent) {
    auto ctypeNotOption = make_shared<CType>();
    auto ctypeOption = make_shared<CType>();

    ctypeNotOption->isOption = false;
    ctypeNotOption->category = CTC_Value;
    ctypeNotOption->parent = parent;
    ctypeNotOption->name = name_;
    ctypeNotOption->nameValue = parent.lock()->getStructName();
    ctypeNotOption->nameRef = parent.lock()->getStructName() + "*";
    ctypeNotOption->_otherType = ctypeOption;

    ctypeOption->isOption = true;
    ctypeOption->category = CTC_Value;
    ctypeOption->parent = parent;
    ctypeOption->name = name_ + "?";
    ctypeOption->nameValue = parent.lock()->getStructName();
    ctypeOption->nameRef = parent.lock()->getStructName() + "*";
    ctypeOption->_otherType = ctypeNotOption;

    return make_pair(ctypeNotOption, ctypeOption);
}

pair<shared_ptr<CType>, shared_ptr<CType>> CType::create(string name_, weak_ptr<CInterface> parent) {
    auto ctypeNotOption = make_shared<CType>();
    auto ctypeOption = make_shared<CType>();

    assert(name_[0] == '#');

    ctypeNotOption->isOption = false;
    ctypeNotOption->category = CTC_Interface;
    ctypeNotOption->parent = parent;
    ctypeNotOption->name = name_;
    ctypeNotOption->nameValue = parent.lock()->getStructName();
    ctypeNotOption->nameRef = parent.lock()->getStructName() + "*";
    ctypeNotOption->_otherType = ctypeOption;

    ctypeOption->isOption = true;
    ctypeOption->category = CTC_Interface;
    ctypeOption->parent = parent;
    ctypeOption->name = name_ + "?";
    ctypeOption->nameValue = parent.lock()->getStructName();
    ctypeOption->nameRef = parent.lock()->getStructName() + "*";
    ctypeOption->_otherType = ctypeNotOption;

    return make_pair(ctypeNotOption, ctypeOption);
}

shared_ptr<ReturnValue> CType::transpileDefaultValue(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    if (parent.expired()) {
        return make_shared<ReturnValue>(shared_from_this(), false, RVR_MustRetain, _defaultValue);
    }
    else if (isOption) {
        return make_shared<ReturnValue>(shared_from_this(), false, RVR_MustRetain, "0");
    }
    else {
        assert(false);
        return nullptr;
    }
}

shared_ptr<CType> CType::getOptionType() {
    assert(!isOption);
    return _otherType.lock();
}

shared_ptr<CType> CType::getNotOptionType() {
    assert(isOption);
    return _otherType.lock();
}

