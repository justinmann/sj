//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "../node/Node.h"

shared_ptr<CTypes> CType::create(string name_, string cname, string defaultValue, string cnameOption, string defaultValueOption) {
    auto stackValueType = make_shared<CType>();
    auto stackOptionType = make_shared<CType>();

    stackValueType->isOption = false;
    stackValueType->typeMode = CTM_Stack;
    stackValueType->category = CTC_Value;
    stackValueType->name = name_;
    stackValueType->nameValue = cname;
    stackValueType->nameRef = cname;
    stackValueType->_defaultValue = defaultValue;
    stackValueType->stackValueType = stackValueType;
    stackValueType->stackOptionType = stackOptionType;

    stackOptionType->isOption = true;
    stackOptionType->typeMode = CTM_Stack;
    stackOptionType->category = CTC_Value;
    stackOptionType->name = name_ + "?";
    stackOptionType->nameValue = cnameOption;
    stackOptionType->nameRef = cnameOption;
    stackOptionType->_defaultValue = defaultValueOption;
    stackOptionType->stackValueType = stackValueType;
    stackOptionType->stackOptionType = stackOptionType;

    return make_shared<CTypes>(stackValueType, stackOptionType, nullptr, nullptr);
}

shared_ptr<CTypes> CType::create(string name_, weak_ptr<CFunction> parent) {
    auto stackValueType = make_shared<CType>();
    auto stackOptionType = make_shared<CType>();
    auto heapValueType = make_shared<CType>();
    auto heapOptionType = make_shared<CType>();

    stackValueType->isOption = false;
    stackValueType->typeMode = CTM_Stack;
    stackValueType->category = CTC_Value;
    stackValueType->parent = parent;
    stackValueType->name = "stack " + name_;
    stackValueType->nameValue = parent.lock()->getStructName();
    stackValueType->nameRef = parent.lock()->getStructName() + "*";
    stackValueType->heapValueType = heapValueType;
    stackValueType->heapOptionType = heapOptionType;
    stackValueType->stackValueType = stackValueType;
    stackValueType->stackOptionType = stackOptionType;

    stackOptionType->isOption = true;
    stackOptionType->typeMode = CTM_Stack;
    stackOptionType->category = CTC_Value;
    stackOptionType->parent = parent;
    stackOptionType->name = "stack " + name_ + "?";
    stackOptionType->nameValue = parent.lock()->getStructName();
    stackOptionType->nameRef = parent.lock()->getStructName() + "*";
    stackOptionType->heapValueType = heapValueType;
    stackOptionType->heapOptionType = heapOptionType;
    stackOptionType->stackValueType = stackValueType;
    stackOptionType->stackOptionType = stackOptionType;

    heapValueType->isOption = false;
    heapValueType->typeMode = CTM_Heap;
    heapValueType->category = CTC_Value;
    heapValueType->parent = parent;
    heapValueType->name = "heap " + name_;
    heapValueType->nameValue = parent.lock()->getStructName();
    heapValueType->nameRef = parent.lock()->getStructName() + "*";
    heapValueType->heapValueType = heapValueType;
    heapValueType->heapOptionType = heapOptionType;
    heapValueType->stackValueType = stackValueType;
    heapValueType->stackOptionType = stackOptionType;

    heapOptionType->isOption = true;
    heapOptionType->typeMode = CTM_Heap;
    heapOptionType->category = CTC_Value;
    heapOptionType->parent = parent;
    heapOptionType->name = "heap " + name_ + "?";
    heapOptionType->nameValue = parent.lock()->getStructName();
    heapOptionType->nameRef = parent.lock()->getStructName() + "*";
    heapOptionType->heapValueType = heapValueType;
    heapOptionType->heapOptionType = heapOptionType;
    heapOptionType->stackValueType = stackValueType;
    heapOptionType->stackOptionType = stackOptionType;

    return make_shared<CTypes>(stackValueType, stackOptionType, heapValueType, heapOptionType);
}

shared_ptr<CTypes> CType::create(string name_, weak_ptr<CInterface> parent) {
    auto stackValueType = make_shared<CType>();
    auto stackOptionType = make_shared<CType>();
    auto heapValueType = make_shared<CType>();
    auto heapOptionType = make_shared<CType>();

    assert(name_[0] == '#');

    stackValueType->isOption = false;
    stackValueType->typeMode = CTM_Stack;
    stackValueType->category = CTC_Interface;
    stackValueType->parent = parent;
    stackValueType->name = "stack " + name_;
    stackValueType->nameValue = parent.lock()->getStructName();
    stackValueType->nameRef = parent.lock()->getStructName() + "*";
    stackValueType->heapValueType = heapValueType;
    stackValueType->heapOptionType = heapOptionType;
    stackValueType->stackValueType = stackValueType;
    stackValueType->stackOptionType = stackOptionType;

    stackOptionType->isOption = true;
    stackOptionType->typeMode = CTM_Stack;
    stackOptionType->category = CTC_Interface;
    stackOptionType->parent = parent;
    stackOptionType->name = "stack " + name_ + "?";
    stackOptionType->nameValue = parent.lock()->getStructName();
    stackOptionType->nameRef = parent.lock()->getStructName() + "*";
    stackOptionType->heapValueType = heapValueType;
    stackOptionType->heapOptionType = heapOptionType;
    stackOptionType->stackValueType = stackValueType;
    stackOptionType->stackOptionType = stackOptionType;

    heapValueType->isOption = false;
    heapValueType->typeMode = CTM_Heap;
    heapValueType->category = CTC_Interface;
    heapValueType->parent = parent;
    heapValueType->name = "heap " + name_;
    heapValueType->nameValue = parent.lock()->getStructName();
    heapValueType->nameRef = parent.lock()->getStructName() + "*";
    heapValueType->heapValueType = heapValueType;
    heapValueType->heapOptionType = heapOptionType;
    heapValueType->stackValueType = stackValueType;
    heapValueType->stackOptionType = stackOptionType;

    heapOptionType->isOption = true;
    heapOptionType->typeMode = CTM_Heap;
    heapOptionType->category = CTC_Interface;
    heapOptionType->parent = parent;
    heapOptionType->name = "heap " + name_ + "?";
    heapOptionType->nameValue = parent.lock()->getStructName();
    heapOptionType->nameRef = parent.lock()->getStructName() + "*";
    heapOptionType->heapValueType = heapValueType;
    heapOptionType->heapOptionType = heapOptionType;
    heapOptionType->stackValueType = stackValueType;
    heapOptionType->stackOptionType = stackOptionType;

    return make_shared<CTypes>(stackValueType, stackOptionType, heapValueType, heapOptionType);
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

shared_ptr<CType> CType::getValueType() {
    assert(isOption);
    return (heapOptionType.lock().get() == this) ? heapValueType.lock() : stackValueType.lock();
}

shared_ptr<CType> CType::getOptionType() {
    assert(!isOption);
    return (heapValueType.lock().get() == this) ? heapOptionType.lock() : stackOptionType.lock();
}

shared_ptr<CType> CType::getHeapValueType() {
    assert(heapValueType.lock().get() != this);
    return heapValueType.lock();
}

shared_ptr<CType> CType::getHeapOptionType() {
    assert(heapOptionType.lock().get() != this);
    return heapOptionType.lock();
}

shared_ptr<CType> CType::getStackValueType() {
    assert(stackValueType.lock().get() != this);
    return stackValueType.lock();
}

shared_ptr<CType> CType::getStackOptionType() {
    assert(stackOptionType.lock().get() != this);
    return stackOptionType.lock();
}
