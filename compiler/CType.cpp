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
    auto localValueType = stackValueType;
    auto localOptionType = stackOptionType;

    stackValueType->isOption = false;
    stackValueType->typeMode = CTM_Value;
    stackValueType->category = CTC_Value;
    stackValueType->name = name_;
    stackValueType->cname = cname;
    stackValueType->safeName = name_;
    stackValueType->_defaultValue = defaultValue;
    stackValueType->stackValueType = stackValueType;
    stackValueType->stackOptionType = stackOptionType;
    stackValueType->localValueType = localValueType;
    stackValueType->localOptionType = localOptionType;

    stackOptionType->isOption = true;
    stackOptionType->typeMode = CTM_Value;
    stackOptionType->category = CTC_Value;
    stackOptionType->name = name_ + "?";
    stackOptionType->cname = cnameOption;
    stackOptionType->safeName = name_ + "_option";
    stackOptionType->_defaultValue = defaultValueOption;
    stackOptionType->stackValueType = stackValueType;
    stackOptionType->stackOptionType = stackOptionType;
    stackOptionType->localValueType = localValueType;
    stackOptionType->localOptionType = localOptionType;

    return make_shared<CTypes>(stackValueType, stackOptionType, nullptr, nullptr, nullptr, nullptr);
}

shared_ptr<CTypes> CType::create(Compiler* compiler, string name_, weak_ptr<CFunction> parent) {
    auto key = parent.lock()->getCStructName(CTM_Stack);
    auto types = compiler->types[key];
    if (types) {
        return types;
    }

    auto stackValueType = make_shared<CType>();
    auto heapValueType = make_shared<CType>();
    auto heapOptionType = make_shared<CType>();
    auto localValueType = make_shared<CType>();
    auto localOptionType = make_shared<CType>();

    stackValueType->isOption = false;
    stackValueType->typeMode = CTM_Stack;
    stackValueType->category = CTC_Value;
    stackValueType->parent = parent;
    stackValueType->name = "stack " + name_;
    stackValueType->cname = parent.lock()->getCStructName(CTM_Stack);
    stackValueType->safeName = name_;
    stackValueType->heapValueType = heapValueType;
    stackValueType->heapOptionType = heapOptionType;
    stackValueType->stackValueType = stackValueType;
    stackValueType->localValueType = localValueType;
    stackValueType->localOptionType = localOptionType;

    heapValueType->isOption = false;
    heapValueType->typeMode = CTM_Heap;
    heapValueType->category = CTC_Value;
    heapValueType->parent = parent;
    heapValueType->name = "heap " + name_;
    heapValueType->cname = parent.lock()->getCStructName(CTM_Heap) + "*";
    heapValueType->safeName = "heap_" + name_;
    heapValueType->heapValueType = heapValueType;
    heapValueType->heapOptionType = heapOptionType;
    heapValueType->stackValueType = stackValueType;
    heapValueType->localValueType = localValueType;
    heapValueType->localOptionType = localOptionType;

    heapOptionType->isOption = true;
    heapOptionType->typeMode = CTM_Heap;
    heapOptionType->category = CTC_Value;
    heapOptionType->parent = parent;
    heapOptionType->name = "heap " + name_ + "?";
    heapOptionType->cname = parent.lock()->getCStructName(CTM_Heap) + "*";
    heapOptionType->safeName = "heap_" + name_ + "_option";
    heapOptionType->heapValueType = heapValueType;
    heapOptionType->heapOptionType = heapOptionType;
    heapOptionType->stackValueType = stackValueType;
    heapOptionType->localValueType = localValueType;
    heapOptionType->localOptionType = localOptionType;

    localValueType->isOption = false;
    localValueType->typeMode = CTM_Local;
    localValueType->category = CTC_Value;
    localValueType->parent = parent;
    localValueType->name = "local " + name_;
    localValueType->cname = parent.lock()->getCStructName(CTM_Stack) + "*";
    localValueType->safeName = "local_" + name_;
    localValueType->heapValueType = heapValueType;
    localValueType->heapOptionType = heapOptionType;
    localValueType->localValueType = localValueType;
    localValueType->localOptionType = localOptionType;
    localValueType->stackValueType = stackValueType;
    
    localOptionType->isOption = true;
    localOptionType->typeMode = CTM_Local;
    localOptionType->category = CTC_Value;
    localOptionType->parent = parent;
    localOptionType->name = "local " + name_ + "?";
    localOptionType->cname = parent.lock()->getCStructName(CTM_Stack) + "*";
    localOptionType->safeName = "local_" + name_ + "_option";
    localOptionType->heapValueType = heapValueType;
    localOptionType->heapOptionType = heapOptionType;
    localOptionType->localValueType = localValueType;
    localOptionType->localOptionType = localOptionType;
    localOptionType->stackValueType = stackValueType;
    
    compiler->types[key] = make_shared<CTypes>(stackValueType, nullptr, heapValueType, heapOptionType, localValueType, localOptionType);
    return compiler->types[key];
}

shared_ptr<CTypes> CType::create(Compiler* compiler, string name_, weak_ptr<CInterface> parent) {
    auto key = parent.lock()->getCStructName(CTM_Stack);
    auto types = compiler->types[key];
    if (types) {
        return types;
    }

    auto stackValueType = make_shared<CType>();
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
    stackValueType->cname = parent.lock()->getCStructName(CTM_Stack);
    stackValueType->safeName = name_;
    stackValueType->heapValueType = heapValueType;
    stackValueType->heapOptionType = heapOptionType;
    stackValueType->stackValueType = stackValueType;
    stackValueType->localValueType = localValueType;
    stackValueType->localOptionType = localOptionType;

    heapValueType->isOption = false;
    heapValueType->typeMode = CTM_Heap;
    heapValueType->category = CTC_Interface;
    heapValueType->parent = parent;
    heapValueType->name = "heap " + name_;
    heapValueType->cname = parent.lock()->getCStructName(CTM_Heap) + "*";
    heapValueType->safeName = "heap_" + name_;
    heapValueType->heapValueType = heapValueType;
    heapValueType->heapOptionType = heapOptionType;
    heapValueType->stackValueType = stackValueType;
    heapValueType->localValueType = localValueType;
    heapValueType->localOptionType = localOptionType;

    heapOptionType->isOption = true;
    heapOptionType->typeMode = CTM_Heap;
    heapOptionType->category = CTC_Interface;
    heapOptionType->parent = parent;
    heapOptionType->name = "heap " + name_ + "?";
    heapOptionType->cname = parent.lock()->getCStructName(CTM_Heap) + "*";
    heapOptionType->safeName = "heap_" + name_ + "_option";
    heapOptionType->heapValueType = heapValueType;
    heapOptionType->heapOptionType = heapOptionType;
    heapOptionType->stackValueType = stackValueType;
    heapOptionType->localValueType = localValueType;
    heapOptionType->localOptionType = localOptionType;

    localValueType->isOption = false;
    localValueType->typeMode = CTM_Local;
    localValueType->category = CTC_Interface;
    localValueType->parent = parent;
    localValueType->name = "local " + name_;
    localValueType->cname = parent.lock()->getCStructName(CTM_Stack) + "*";
    localValueType->safeName = "local_" + name_;
    localValueType->heapValueType = heapValueType;
    localValueType->heapOptionType = heapOptionType;
    localValueType->stackValueType = stackValueType;
    localValueType->localValueType = localValueType;
    localValueType->localOptionType = localOptionType;

    localOptionType->isOption = true;
    localOptionType->typeMode = CTM_Local;
    localOptionType->category = CTC_Interface;
    localOptionType->parent = parent;
    localOptionType->name = "local " + name_ + "?";
    localOptionType->cname = parent.lock()->getCStructName(CTM_Stack) + "*";
    localOptionType->safeName = "local_" + name_ + "_option";
    localOptionType->heapValueType = heapValueType;
    localOptionType->heapOptionType = heapOptionType;
    localOptionType->stackValueType = stackValueType;
    localOptionType->localValueType = localValueType;
    localOptionType->localOptionType = localOptionType;

    compiler->types[key] = make_shared<CTypes>(stackValueType, nullptr, heapValueType, heapOptionType, localValueType, localOptionType);
    return compiler->types[key];
}

void CType::transpileDefaultValue(Compiler* compiler, CResult& result, CLoc loc, TrBlock* trBlock, shared_ptr<TrStoreValue> storeValue) {
    if (parent.expired()) {
        auto temp = make_shared<TrValue>(nullptr, shared_from_this(), _defaultValue);
        storeValue->retainValue(compiler, result, trBlock, temp);
    }
    else if (isOption) {
        auto temp = make_shared<TrValue>(nullptr, shared_from_this(), "0");
        storeValue->retainValue(compiler, result, trBlock, temp);
    }
    else {
        assert(false);
    }
}

bool CType::isSameExceptMode(shared_ptr<CType> l, shared_ptr<CType> r) {
    return l->category == r->category && l->stackValueType.lock()->cname == r->stackValueType.lock()->cname && l->isOption == r->isOption;
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

shared_ptr<CType> CType::getLocalType() {
    return isOption ? localOptionType.lock() : localValueType.lock();
}

shared_ptr<CType> CType::getLocalValueType() {
    return localValueType.lock();
}

shared_ptr<CType> CType::getLocalOptionType() {
    return localOptionType.lock();
}
