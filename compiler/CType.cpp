//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include <sjc.h>
#include "../node/Node.h"

AssignOp AssignOp::create(bool isFirstAssignment, bool isMutable, bool isCopy, CTypeMode typeMode) {
    AssignOp op;
    op.isFirstAssignment = isFirstAssignment;
    op.isMutable = isMutable;
    op.isCopy = isCopy;
    op.typeMode = typeMode;
    return op;
}

AssignOp AssignOp::immutableCreate = AssignOp::create(true, false, false, CTM_Undefined);
AssignOp AssignOp::mutableCreate = AssignOp::create(true, true, false, CTM_Undefined);
AssignOp AssignOp::mutableUpdate = AssignOp::create(false, true, false, CTM_Undefined);
int CType_typeId = 0;

CTypes::CTypes(shared_ptr<CType> stackValueType, shared_ptr<CType> stackOptionType, shared_ptr<CType> heapValueType, shared_ptr<CType> heapOptionType, shared_ptr<CType> localValueType, shared_ptr<CType> localOptionType, shared_ptr<CType> weakType) : 
    stackValueType(stackValueType), 
    stackOptionType(stackOptionType),
    heapValueType(heapValueType), 
    heapOptionType(heapOptionType), 
    localValueType(localValueType), 
    localOptionType(localOptionType), 
    weakType(weakType) {

    CType_typeId++;

    if (stackValueType) {
        stackValueType->typeId = CType_typeId;
        stackValueType->heapValueType = heapValueType;
        stackValueType->heapOptionType = heapOptionType;
        stackValueType->stackValueType = stackValueType;
        stackValueType->stackOptionType = stackOptionType;
        stackValueType->localValueType = localValueType;
        stackValueType->localOptionType = localOptionType;
        stackValueType->weakType = weakType;
    }

    if (stackOptionType) {
        stackOptionType->typeId = CType_typeId;
        stackOptionType->heapValueType = heapValueType;
        stackOptionType->heapOptionType = heapOptionType;
        stackOptionType->stackValueType = stackValueType;
        stackOptionType->stackOptionType = stackOptionType;
        stackOptionType->localValueType = localValueType;
        stackOptionType->localOptionType = localOptionType;
        stackOptionType->weakType = weakType;
    }

    if (heapValueType) {
        heapValueType->typeId = CType_typeId;
        heapValueType->heapValueType = heapValueType;
        heapValueType->heapOptionType = heapOptionType;
        heapValueType->stackValueType = stackValueType;
        heapValueType->stackOptionType = stackOptionType;
        heapValueType->localValueType = localValueType;
        heapValueType->localOptionType = localOptionType;
        heapValueType->weakType = weakType;
    }

    if (heapOptionType) {
        heapOptionType->typeId = CType_typeId;
        heapOptionType->heapValueType = heapValueType;
        heapOptionType->heapOptionType = heapOptionType;
        heapOptionType->stackValueType = stackValueType;
        heapOptionType->stackOptionType = stackOptionType;
        heapOptionType->localValueType = localValueType;
        heapOptionType->localOptionType = localOptionType;
        heapOptionType->weakType = weakType;
    }

    if (localValueType) {
        localValueType->typeId = CType_typeId;
        localValueType->heapValueType = heapValueType;
        localValueType->heapOptionType = heapOptionType;
        localValueType->stackValueType = stackValueType;
        localValueType->stackOptionType = stackOptionType;
        localValueType->localValueType = localValueType;
        localValueType->localOptionType = localOptionType;
        localValueType->weakType = weakType;
    }

    if (localOptionType) {
        localOptionType->typeId = CType_typeId;
        localOptionType->heapValueType = heapValueType;
        localOptionType->heapOptionType = heapOptionType;
        localOptionType->stackValueType = stackValueType;
        localOptionType->stackOptionType = stackOptionType;
        localOptionType->localValueType = localValueType;
        localOptionType->localOptionType = localOptionType;
        localOptionType->weakType = weakType;
    }

    if (weakType) {
        weakType->typeId = CType_typeId;
        weakType->heapValueType = heapValueType;
        weakType->heapOptionType = heapOptionType;
        weakType->stackValueType = stackValueType;
        weakType->stackOptionType = stackOptionType;
        weakType->localValueType = localValueType;
        weakType->localOptionType = localOptionType;
        weakType->weakType = weakType;
    }
}


shared_ptr<CTypes> CType::create(vector<string>& packageNamespace, string valueName, string cname, string defaultValue, string cnameOption, string defaultValueOption) {
    assert(valueName.find("stack ") != 0);
    assert(valueName.find("heap ") != 0);
    assert(valueName.find("local ") != 0);
    assert(valueName.find("#") == string::npos);
    assert(valueName.back() != '?');

    auto stackValueType = make_shared<CType>();
    auto stackOptionType = make_shared<CType>();
    auto localValueType = make_shared<CType>();
    auto localOptionType = make_shared<CType>();

    stackValueType->isOption = false;
    stackValueType->typeMode = CTM_Value;
    stackValueType->category = CTC_Value;
    stackValueType->packageNamespace = packageNamespace;
    stackValueType->valueName = valueName;
    stackValueType->shortName = valueName;
    stackValueType->fullName = valueName;
    stackValueType->cname = cname;
    stackValueType->safeName = valueName;
    stackValueType->_defaultValue = defaultValue;

    stackOptionType->isOption = true;
    stackOptionType->typeMode = CTM_Value;
    stackOptionType->category = CTC_Value;
    stackOptionType->packageNamespace = packageNamespace;
    stackOptionType->valueName = valueName;
    stackOptionType->shortName = valueName + "?";
    stackOptionType->fullName = valueName + "?";
    stackOptionType->cname = cnameOption;
    stackOptionType->safeName = valueName + "_option";
    stackOptionType->_defaultValue = defaultValueOption;

    localValueType->isOption = false;
    localValueType->typeMode = CTM_ValuePtr;
    localValueType->category = CTC_Value;
    localValueType->packageNamespace = packageNamespace;
    localValueType->valueName = valueName;
    localValueType->shortName = valueName;
    localValueType->fullName = "local " + valueName;
    localValueType->cname = cname + "*";
    localValueType->safeName = valueName;
    localValueType->_defaultValue = defaultValue;

    localOptionType->isOption = true;
    localOptionType->typeMode = CTM_ValuePtr;
    localOptionType->category = CTC_Value;
    localOptionType->packageNamespace = packageNamespace;
    localOptionType->valueName = valueName;
    localOptionType->shortName = valueName + "?";
    localOptionType->fullName = "local " + valueName + "?";
    localOptionType->cname = cnameOption + "*";
    localOptionType->safeName = valueName + "_option";
    localOptionType->_defaultValue = defaultValueOption;

    return make_shared<CTypes>(stackValueType, stackOptionType, nullptr, nullptr, localValueType, localOptionType, nullptr);
}

shared_ptr<CTypes> CType::create(Compiler* compiler, vector<string>& packageNamespace, string valueName, string safeName, weak_ptr<CFunction> parent) {
    assert(valueName.find("stack ") != 0);
    assert(valueName.find("heap ") != 0);
    assert(valueName.find("local ") != 0);

    auto key = parent.lock()->getCStructName(CTM_Stack);
    auto types = compiler->types[key];
    if (types) {
        return types;
    }

    auto stackValueType = make_shared<CType>();
    auto stackOptionType = make_shared<CType>();
    auto heapValueType = make_shared<CType>();
    auto heapOptionType = make_shared<CType>();
    auto localValueType = make_shared<CType>();
    auto localOptionType = make_shared<CType>();
    auto weakType = make_shared<CType>();

    stackValueType->isOption = false;
    stackValueType->typeMode = CTM_Stack;
    stackValueType->category = CTC_Value;
    stackValueType->parent = parent;
    stackValueType->packageNamespace = packageNamespace;
    stackValueType->valueName = valueName;
    stackValueType->shortName = valueName;
    stackValueType->fullName = "stack " + valueName;
    stackValueType->cname = parent.lock()->getCStructName(CTM_Stack);
    stackValueType->safeName = safeName;

    stackOptionType->isOption = true;
    stackOptionType->typeMode = CTM_Stack;
    stackOptionType->category = CTC_Value;
    stackOptionType->parent = parent;
    stackOptionType->packageNamespace = packageNamespace;
    stackOptionType->valueName = valueName;
    stackOptionType->shortName = valueName + "?";
    stackOptionType->fullName = "stack " + valueName + "?";
    stackOptionType->cname = parent.lock()->getCStructName(CTM_Stack);
    stackOptionType->safeName = safeName + "_option";

    heapValueType->isOption = false;
    heapValueType->typeMode = CTM_Heap;
    heapValueType->category = CTC_Value;
    heapValueType->parent = parent;
    heapValueType->packageNamespace = packageNamespace;
    heapValueType->valueName = valueName;
    heapValueType->shortName = valueName;
    heapValueType->fullName = "heap " + valueName;
    heapValueType->cname = parent.lock()->getCStructName(CTM_Heap) + "*";
    heapValueType->safeName = "heap_" + safeName;

    heapOptionType->isOption = true;
    heapOptionType->typeMode = CTM_Heap;
    heapOptionType->category = CTC_Value;
    heapOptionType->parent = parent;
    heapOptionType->packageNamespace = packageNamespace;
    heapOptionType->valueName = valueName;
    heapOptionType->shortName = valueName + "?";
    heapOptionType->fullName = "heap " + valueName + "?";
    heapOptionType->cname = parent.lock()->getCStructName(CTM_Heap) + "*";
    heapOptionType->safeName = "heap_" + safeName + "_option";

    localValueType->isOption = false;
    localValueType->typeMode = CTM_Local;
    localValueType->category = CTC_Value;
    localValueType->parent = parent;
    localValueType->packageNamespace = packageNamespace;
    localValueType->valueName = valueName;
    localValueType->shortName = valueName;
    localValueType->fullName = "local " + valueName;
    localValueType->cname = parent.lock()->getCStructName(CTM_Stack) + "*";
    localValueType->safeName = "local_" + safeName;

    localOptionType->isOption = true;
    localOptionType->typeMode = CTM_Local;
    localOptionType->category = CTC_Value;
    localOptionType->parent = parent;
    localOptionType->packageNamespace = packageNamespace;
    localOptionType->valueName = valueName;
    localOptionType->fullName = "local " + valueName + "?";
    localOptionType->cname = parent.lock()->getCStructName(CTM_Stack) + "*";
    localOptionType->safeName = "local_" + safeName + "_option";

    weakType->isOption = true;
    weakType->typeMode = CTM_Weak;
    weakType->category = CTC_Value;
    weakType->parent = parent;
    weakType->packageNamespace = packageNamespace;
    weakType->valueName = valueName;
    weakType->shortName = valueName + "?";
    weakType->fullName = "weak " + valueName;
    weakType->cname = parent.lock()->getCStructName(CTM_Stack) + "*";
    weakType->safeName = "weak_" + valueName;
    
    compiler->types[key] = make_shared<CTypes>(stackValueType, stackOptionType, heapValueType, heapOptionType, localValueType, localOptionType, weakType);
    return compiler->types[key];
}

shared_ptr<CTypes> CType::create(Compiler* compiler, vector<string>& packageNamespace, string valueName, string safeName, weak_ptr<CInterface> parent) {
    assert(valueName.find("stack ") != 0);
    assert(valueName.find("heap ") != 0);
    assert(valueName.find("local ") != 0);
    assert(valueName.find("#") == string::npos);
    assert(valueName.back() != '?');

    auto key = parent.lock()->getCStructName(CTM_Stack);
    auto types = compiler->types[key];
    if (types) {
        return types;
    }

    auto heapValueType = make_shared<CType>();
    auto heapOptionType = make_shared<CType>();
    auto localValueType = make_shared<CType>();
    auto localOptionType = make_shared<CType>();
    auto weakType = make_shared<CType>();

    heapValueType->isOption = false;
    heapValueType->typeMode = CTM_Heap;
    heapValueType->category = CTC_Interface;
    heapValueType->parent = parent;
    heapValueType->packageNamespace = packageNamespace;
    heapValueType->valueName = valueName;
    heapValueType->shortName = "#" + valueName;
    heapValueType->fullName = "heap #" + valueName;
    heapValueType->cname = parent.lock()->getCStructName(CTM_Heap);
    heapValueType->safeName = "heap_" + safeName;

    heapOptionType->isOption = true;
    heapOptionType->typeMode = CTM_Heap;
    heapOptionType->category = CTC_Interface;
    heapOptionType->parent = parent;
    heapOptionType->packageNamespace = packageNamespace;
    heapOptionType->valueName = valueName;
    heapOptionType->shortName = "#" + valueName + "?";
    heapOptionType->fullName = "heap #" + valueName + "?";
    heapOptionType->cname = parent.lock()->getCStructName(CTM_Heap);
    heapOptionType->safeName = "heap_" + safeName + "_option";

    localValueType->isOption = false;
    localValueType->typeMode = CTM_Local;
    localValueType->category = CTC_Interface;
    localValueType->parent = parent;
    localValueType->packageNamespace = packageNamespace;
    localValueType->valueName = valueName;
    localValueType->shortName = "#" + valueName;
    localValueType->fullName = "local #" + valueName;
    localValueType->cname = parent.lock()->getCStructName(CTM_Stack);
    localValueType->safeName = "local_" + safeName;

    localOptionType->isOption = true;
    localOptionType->typeMode = CTM_Local;
    localOptionType->category = CTC_Interface;
    localOptionType->parent = parent;
    localOptionType->packageNamespace = packageNamespace;
    localOptionType->valueName = valueName;
    localOptionType->shortName = "#" + valueName + "?";
    localOptionType->fullName = "local #" + valueName + "?";
    localOptionType->cname = parent.lock()->getCStructName(CTM_Stack);
    localOptionType->safeName = "local_" + safeName + "_option";

    weakType->isOption = true;
    weakType->typeMode = CTM_Weak;
    weakType->category = CTC_Interface;
    weakType->parent = parent;
    weakType->packageNamespace = packageNamespace;
    weakType->valueName = valueName;
    weakType->shortName = "#" + valueName + "?";
    weakType->fullName = "weak #" + valueName;
    weakType->cname = parent.lock()->getCStructName(CTM_Stack);
    weakType->safeName = "weak_" + safeName;

    compiler->types[key] = make_shared<CTypes>(nullptr, nullptr, heapValueType, heapOptionType, localValueType, localOptionType, weakType);
    return compiler->types[key];
}

shared_ptr<CTypes> CType::create(Compiler* compiler, vector<shared_ptr<CType>> argTypes, shared_ptr<CType> stackReturnType, shared_ptr<CType> heapReturnType, weak_ptr<CCallback> callback) {
    auto heapValueType = make_shared<CType>();
    auto heapOptionType = make_shared<CType>();
    auto localValueType = make_shared<CType>();
    auto localOptionType = make_shared<CType>();
    auto weakType = make_shared<CType>();

    stringstream valueStream;
    stringstream safeStream;

    safeStream << "cb";
    bool isFirst = true;
    valueStream << "(";
    for (auto argType : argTypes) {
        safeStream << "_";
        if (isFirst) {
            isFirst = false;
        }
        else {
            valueStream << ", ";
        }
        valueStream << ":" << argType->fullName;
        safeStream << argType->safeName;
    }
    valueStream << ")";
    if (stackReturnType) {
        valueStream << stackReturnType->fullName;
    }
    else if (heapReturnType) {
        valueStream << heapReturnType->fullName;
    }
    if (stackReturnType) {
        safeStream << "_";
        safeStream << stackReturnType->safeName;
    }
    if (heapReturnType) {
        safeStream << "_";
        safeStream << heapReturnType->safeName;
    }

    auto valueName = valueStream.str();
    auto safeName = safeStream.str();
    auto key = safeName;

    heapValueType->isOption = false;
    heapValueType->typeMode = CTM_Heap;
    heapValueType->category = CTC_Function;
    heapValueType->callback = callback;
    heapValueType->argTypes = argTypes;
    heapValueType->stackReturnType = stackReturnType;
    heapValueType->heapReturnType = heapReturnType;
    heapValueType->valueName = valueName;
    heapValueType->shortName = valueName;
    heapValueType->fullName = "heap " + valueName;
    heapValueType->cname = callback.lock()->getCName(CTM_Heap, false);
    heapValueType->safeName = "heap_" + safeName;

    heapOptionType->isOption = true;
    heapOptionType->typeMode = CTM_Heap;
    heapOptionType->category = CTC_Function;
    heapOptionType->callback = callback;
    heapOptionType->argTypes = argTypes;
    heapOptionType->stackReturnType = stackReturnType;
    heapOptionType->heapReturnType = heapReturnType;
    heapOptionType->valueName = valueName;
    heapOptionType->shortName = valueName + "?";
    heapOptionType->fullName = "heap " + valueName + "?";
    heapOptionType->cname = callback.lock()->getCName(CTM_Heap, true);
    heapOptionType->safeName = "heap_" + safeName + "_option";

    localValueType->isOption = false;
    localValueType->typeMode = CTM_Local;
    localValueType->category = CTC_Function;
    localValueType->callback = callback;
    localValueType->argTypes = argTypes;
    localValueType->stackReturnType = stackReturnType;
    localValueType->heapReturnType = heapReturnType;
    localValueType->valueName = valueName;
    localValueType->shortName = valueName;
    localValueType->fullName = "local " + valueName;
    localValueType->cname = callback.lock()->getCName(CTM_Local, false);
    localValueType->safeName = "local_" + safeName;

    localOptionType->isOption = true;
    localOptionType->typeMode = CTM_Local;
    localOptionType->category = CTC_Function;
    localOptionType->callback = callback;
    localOptionType->argTypes = argTypes;
    localOptionType->stackReturnType = stackReturnType;
    localOptionType->heapReturnType = heapReturnType;
    localOptionType->valueName = valueName;
    localOptionType->shortName = valueName + "?";
    localOptionType->fullName = "local " + valueName + "?";
    localOptionType->cname = callback.lock()->getCName(CTM_Local, true);
    localOptionType->safeName = "local_" + safeName + "_option";

    weakType->isOption = true;
    weakType->typeMode = CTM_Weak;
    weakType->category = CTC_Function;
    weakType->callback = callback;
    weakType->argTypes = argTypes;
    weakType->stackReturnType = stackReturnType;
    weakType->heapReturnType = heapReturnType;
    weakType->valueName = valueName;
    weakType->shortName = valueName + "?";
    weakType->fullName = "weak " + valueName;
    weakType->cname = callback.lock()->getCName(CTM_Local, true);
    weakType->safeName = "weak_" + safeName;

    compiler->types[key] = make_shared<CTypes>(nullptr, nullptr, heapValueType, heapOptionType, localValueType, localOptionType, weakType);
    return compiler->types[key];
}

void CType::transpileDefaultValue(Compiler* compiler, CLoc loc, TrBlock* trBlock, shared_ptr<TrStoreValue> storeValue) {
    if (!storeValue->op.isFirstAssignment) {
        if (storeValue->type->typeMode == CTM_Stack) {
            storeValue->getValue()->addDestroyToStatements(compiler, trBlock);
        }
        else {
            storeValue->getValue()->addReleaseToStatements(compiler, trBlock);
        }
    }

    if (category == CTC_Value && parent.expired()) {
        auto temp = make_shared<TrValue>(nullptr, shared_from_this(), _defaultValue, false);
        storeValue->retainValue(compiler, loc, trBlock, temp);
    }
    else if (isOption) {
        if (category == CTC_Function) {
            if (storeValue->type->typeMode == CTM_Heap) {
                trBlock->statements.push_back(TrStatement(loc, storeValue->getName(trBlock) + ".inner._parent = 0"));
            }
            else {
                trBlock->statements.push_back(TrStatement(loc, storeValue->getName(trBlock) + "._parent = 0"));
            }
            storeValue->hasSetValue = true;
        }
        else if (category == CTC_Interface) {
            trBlock->statements.push_back(TrStatement(loc, storeValue->getName(trBlock) + "._parent = 0"));
            storeValue->hasSetValue = true;
        }
        else if (!parent.expired()) {
            if (storeValue->type->typeMode == CTM_Stack) {
                if (storeValue->isReturnValue) {
                    trBlock->statements.push_back(TrStatement(loc, storeValue->getName(trBlock) + "->_refCount = -1"));
                }
                else {
                    trBlock->statements.push_back(TrStatement(loc, storeValue->getName(trBlock) + "._refCount = -1"));
                }
                storeValue->hasSetValue = true;
            }
            else {
                auto temp = make_shared<TrValue>(nullptr, storeValue->type, "0", false);
                storeValue->retainValue(compiler, loc, trBlock, temp);
            }
        }
    }
    else {
        compiler->addError(loc, CErrorCode::InvalidType, "no default value for type '%s'", valueName.c_str());
    }
}

bool CType::isSameExceptMode(shared_ptr<CType> l, shared_ptr<CType> r) {
    return l->category == r->category && l->localValueType.lock()->cname == r->localValueType.lock()->cname && (l->isOption == r->isOption || l->typeMode == CTM_Weak || r->typeMode == CTM_Weak);
}

bool CType::isSameExceptModeAndOption(shared_ptr<CType> l, shared_ptr<CType> r) {
    return l->category == r->category && l->localValueType.lock()->cname == r->localValueType.lock()->cname;
}

shared_ptr<CType> CType::getValueType() {
    if (!isOption) {
        return shared_from_this();
    }
    return (heapOptionType.lock().get() == this) ? heapValueType.lock() : ((stackOptionType.lock().get() == this) ? stackValueType.lock() : localValueType.lock());
}

shared_ptr<CType> CType::getOptionType() {
    if (isOption) {
        return shared_from_this();
    }
    return (heapValueType.lock().get() == this) ? heapOptionType.lock() : ((stackValueType.lock().get() == this) ? stackOptionType.lock() : localOptionType.lock());
}

shared_ptr<CType> CType::getHeapType() {
    return isOption ? heapOptionType.lock() : heapValueType.lock();
}

shared_ptr<CType> CType::getHeapValueType() {
    assert(heapValueType.lock().get() != this);
    return heapValueType.lock();
}

shared_ptr<CType> CType::getHeapOptionType() {
    assert(heapOptionType.lock().get() != this);
    return heapOptionType.lock();
}

shared_ptr<CType> CType::getStackType() {
    return isOption ? stackOptionType.lock() : stackValueType.lock();
}

shared_ptr<CType> CType::getStackValueType() {
    assert(stackValueType.lock().get() != this);
    return stackValueType.lock();
}

shared_ptr<CType> CType::getTempType() {
    return category == CTC_Value && parent.expired() ? getStackType() : getLocalType();
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

shared_ptr<CType> CType::getWeakType() {
    return weakType.lock();
}
