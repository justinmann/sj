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
    stackValueType->typeMode = CTM_Value;
    stackValueType->category = CTC_Value;
    stackValueType->name = name_;
    stackValueType->nameValue = cname;
    stackValueType->nameRef = cname;
    stackValueType->_defaultValue = defaultValue;
    stackValueType->stackValueType = stackValueType;
    stackValueType->stackOptionType = stackOptionType;

    stackOptionType->isOption = true;
    stackOptionType->typeMode = CTM_Value;
    stackOptionType->category = CTC_Value;
    stackOptionType->name = name_ + "?";
    stackOptionType->nameValue = cnameOption;
    stackOptionType->nameRef = cnameOption;
    stackOptionType->_defaultValue = defaultValueOption;
    stackOptionType->stackValueType = stackValueType;
    stackOptionType->stackOptionType = stackOptionType;

    return make_shared<CTypes>(stackValueType, stackOptionType, nullptr, nullptr, nullptr, nullptr);
}

shared_ptr<CTypes> CType::create(string name_, weak_ptr<CFunction> parent) {
    auto stackValueType = make_shared<CType>();
    auto stackOptionType = make_shared<CType>();
    auto heapValueType = make_shared<CType>();
    auto heapOptionType = make_shared<CType>();
    auto localValueType = make_shared<CType>();
    auto localOptionType = make_shared<CType>();

    stackValueType->isOption = false;
    stackValueType->typeMode = CTM_Stack;
    stackValueType->category = CTC_Value;
    stackValueType->parent = parent;
    stackValueType->name = "stack " + name_;
    stackValueType->nameValue = parent.lock()->getStructName(CTM_Stack);
    stackValueType->nameRef = parent.lock()->getStructName(CTM_Stack) + "*";
    stackValueType->heapValueType = heapValueType;
    stackValueType->heapOptionType = heapOptionType;
    stackValueType->stackValueType = stackValueType;
    stackValueType->stackOptionType = stackOptionType;
    stackValueType->localValueType = localValueType;
    stackValueType->localOptionType = localOptionType;

    stackOptionType->isOption = true;
    stackOptionType->typeMode = CTM_Stack;
    stackOptionType->category = CTC_Value;
    stackOptionType->parent = parent;
    stackOptionType->name = "stack " + name_ + "?";
    stackOptionType->nameValue = parent.lock()->getStructName(CTM_Stack);
    stackOptionType->nameRef = parent.lock()->getStructName(CTM_Stack) + "*";
    stackOptionType->heapValueType = heapValueType;
    stackOptionType->heapOptionType = heapOptionType;
    stackOptionType->stackValueType = stackValueType;
    stackOptionType->stackOptionType = stackOptionType;
    stackOptionType->localValueType = localValueType;
    stackOptionType->localOptionType = localOptionType;

    heapValueType->isOption = false;
    heapValueType->typeMode = CTM_Heap;
    heapValueType->category = CTC_Value;
    heapValueType->parent = parent;
    heapValueType->name = "heap " + name_;
    heapValueType->nameValue = parent.lock()->getStructName(CTM_Heap);
    heapValueType->nameRef = parent.lock()->getStructName(CTM_Heap) + "*";
    heapValueType->heapValueType = heapValueType;
    heapValueType->heapOptionType = heapOptionType;
    heapValueType->stackValueType = stackValueType;
    heapValueType->stackOptionType = stackOptionType;
    heapValueType->localValueType = localValueType;
    heapValueType->localOptionType = localOptionType;

    heapOptionType->isOption = true;
    heapOptionType->typeMode = CTM_Heap;
    heapOptionType->category = CTC_Value;
    heapOptionType->parent = parent;
    heapOptionType->name = "heap " + name_ + "?";
    heapOptionType->nameValue = parent.lock()->getStructName(CTM_Heap);
    heapOptionType->nameRef = parent.lock()->getStructName(CTM_Heap) + "*";
    heapOptionType->heapValueType = heapValueType;
    heapOptionType->heapOptionType = heapOptionType;
    heapOptionType->stackValueType = stackValueType;
    heapOptionType->stackOptionType = stackOptionType;
    heapOptionType->localValueType = localValueType;
    heapOptionType->localOptionType = localOptionType;

    localValueType->isOption = false;
    localValueType->typeMode = CTM_Local;
    localValueType->category = CTC_Value;
    localValueType->parent = parent;
    localValueType->name = "local " + name_;
    localValueType->nameValue = parent.lock()->getStructName(CTM_Stack);
    localValueType->nameRef = parent.lock()->getStructName(CTM_Stack) + "*";
    localValueType->heapValueType = heapValueType;
    localValueType->heapOptionType = heapOptionType;
    localValueType->localValueType = localValueType;
    localValueType->localOptionType = localOptionType;
    localValueType->stackValueType = stackValueType;
    localValueType->stackOptionType = stackOptionType;
    
    localOptionType->isOption = true;
    localOptionType->typeMode = CTM_Local;
    localOptionType->category = CTC_Value;
    localOptionType->parent = parent;
    localOptionType->name = "local " + name_ + "?";
    localOptionType->nameValue = parent.lock()->getStructName(CTM_Stack);
    localOptionType->nameRef = parent.lock()->getStructName(CTM_Stack) + "*";
    localOptionType->heapValueType = heapValueType;
    localOptionType->heapOptionType = heapOptionType;
    localOptionType->localValueType = localValueType;
    localOptionType->localOptionType = localOptionType;
    localOptionType->stackValueType = stackValueType;
    localOptionType->stackOptionType = stackOptionType;
    
    return make_shared<CTypes>(stackValueType, stackOptionType, heapValueType, heapOptionType, localValueType, localOptionType);
}

shared_ptr<CTypes> CType::create(string name_, weak_ptr<CInterface> parent) {
    auto stackValueType = make_shared<CType>();
    auto stackOptionType = make_shared<CType>();
    auto heapValueType = make_shared<CType>();
    auto heapOptionType = make_shared<CType>();
    auto localValueType = make_shared<CType>();
    auto localOptionType = make_shared<CType>();

    assert(name_[0] == '#');

    stackValueType->isOption = false;
    stackValueType->typeMode = CTM_Stack;
    stackValueType->category = CTC_Interface;
    stackValueType->parent = parent;
    stackValueType->name = "stack " + name_;
    stackValueType->nameValue = parent.lock()->getStructName(CTM_Stack);
    stackValueType->nameRef = parent.lock()->getStructName(CTM_Stack) + "*";
    stackValueType->heapValueType = heapValueType;
    stackValueType->heapOptionType = heapOptionType;
    stackValueType->stackValueType = stackValueType;
    stackValueType->stackOptionType = stackOptionType;
    stackValueType->localValueType = localValueType;
    stackValueType->localOptionType = localOptionType;

    stackOptionType->isOption = true;
    stackOptionType->typeMode = CTM_Stack;
    stackOptionType->category = CTC_Interface;
    stackOptionType->parent = parent;
    stackOptionType->name = "stack " + name_ + "?";
    stackOptionType->nameValue = parent.lock()->getStructName(CTM_Stack);
    stackOptionType->nameRef = parent.lock()->getStructName(CTM_Stack) + "*";
    stackOptionType->heapValueType = heapValueType;
    stackOptionType->heapOptionType = heapOptionType;
    stackOptionType->stackValueType = stackValueType;
    stackOptionType->stackOptionType = stackOptionType;
    stackOptionType->localValueType = localValueType;
    stackOptionType->localOptionType = localOptionType;

    heapValueType->isOption = false;
    heapValueType->typeMode = CTM_Heap;
    heapValueType->category = CTC_Interface;
    heapValueType->parent = parent;
    heapValueType->name = "heap " + name_;
    heapValueType->nameValue = parent.lock()->getStructName(CTM_Heap);
    heapValueType->nameRef = parent.lock()->getStructName(CTM_Heap) + "*";
    heapValueType->heapValueType = heapValueType;
    heapValueType->heapOptionType = heapOptionType;
    heapValueType->stackValueType = stackValueType;
    heapValueType->stackOptionType = stackOptionType;
    heapValueType->localValueType = localValueType;
    heapValueType->localOptionType = localOptionType;

    heapOptionType->isOption = true;
    heapOptionType->typeMode = CTM_Heap;
    heapOptionType->category = CTC_Interface;
    heapOptionType->parent = parent;
    heapOptionType->name = "heap " + name_ + "?";
    heapOptionType->nameValue = parent.lock()->getStructName(CTM_Heap);
    heapOptionType->nameRef = parent.lock()->getStructName(CTM_Heap) + "*";
    heapOptionType->heapValueType = heapValueType;
    heapOptionType->heapOptionType = heapOptionType;
    heapOptionType->stackValueType = stackValueType;
    heapOptionType->stackOptionType = stackOptionType;
    heapOptionType->localValueType = localValueType;
    heapOptionType->localOptionType = localOptionType;

    localValueType->isOption = false;
    localValueType->typeMode = CTM_Local;
    localValueType->category = CTC_Interface;
    localValueType->parent = parent;
    localValueType->name = "local " + name_;
    localValueType->nameValue = parent.lock()->getStructName(CTM_Stack);
    localValueType->nameRef = parent.lock()->getStructName(CTM_Stack) + "*";
    localValueType->heapValueType = heapValueType;
    localValueType->heapOptionType = heapOptionType;
    localValueType->stackValueType = stackValueType;
    localValueType->stackOptionType = stackOptionType;
    localValueType->localValueType = localValueType;
    localValueType->localOptionType = localOptionType;

    localOptionType->isOption = true;
    localOptionType->typeMode = CTM_Local;
    localOptionType->category = CTC_Interface;
    localOptionType->parent = parent;
    localOptionType->name = "local " + name_ + "?";
    localOptionType->nameValue = parent.lock()->getStructName(CTM_Stack);
    localOptionType->nameRef = parent.lock()->getStructName(CTM_Stack) + "*";
    localOptionType->heapValueType = heapValueType;
    localOptionType->heapOptionType = heapOptionType;
    localOptionType->stackValueType = stackValueType;
    localOptionType->stackOptionType = stackOptionType;
    localOptionType->localValueType = localValueType;
    localOptionType->localOptionType = localOptionType;

    return make_shared<CTypes>(stackValueType, stackOptionType, heapValueType, heapOptionType, localValueType, localOptionType);
}

shared_ptr<ReturnValue> CType::transpileDefaultValue(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    if (parent.expired()) {
        return make_shared<ReturnValue>(shared_from_this(), _defaultValue);
    }
    else if (isOption) {
        return make_shared<ReturnValue>(shared_from_this(), "0");
    }
    else {
        assert(false);
        return nullptr;
    }
}

shared_ptr<CType> CType::getValueType() {
    assert(isOption);
    return (heapOptionType.lock().get() == this) ? heapValueType.lock() : ((stackOptionType.lock().get() == this) ? stackValueType.lock() : localValueType.lock());
}

shared_ptr<CType> CType::getOptionType() {
    assert(!isOption);
    return (heapValueType.lock().get() == this) ? heapOptionType.lock() : ((stackValueType.lock().get() == this) ? stackOptionType.lock() : localOptionType.lock());
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

shared_ptr<CType> CType::getLocalValueType() {
    assert(localValueType.lock().get() != this);
    return localValueType.lock();
}

shared_ptr<CType> CType::getLocalOptionType() {
    assert(localOptionType.lock().get() != this);
    return localOptionType.lock();
}


