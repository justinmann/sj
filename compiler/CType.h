//
//  CType.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef CType_h
#define CType_h

class Compiler;
class CBaseFunction;
class CFunction;
class CInterface;
class CResult;
class TrValue;
class TrStoreValue;
class TrBlock;
class CVar;
class CThisVar;
class CBaseFunctionDefinition;
class CCallback;

enum CTypeImmutability {
    CTI_Undefined,
    CTI_Mutable,
    CTI_Immutable,
};

enum CTypeCategory {
    CTC_Value,
    CTC_Interface,
    CTC_Function
};

enum CTypeMode {
    CTM_Undefined,
    CTM_Stack,
    CTM_Heap,
    CTM_Weak,
    CTM_Local,
    CTM_Value
};

class AssignOp {
public:
    bool isFirstAssignment;
    bool isMutable;
    bool isCopy;
    CTypeMode typeMode;

    static AssignOp create(bool isFirstAssignment, bool isMutable, bool isCopy, CTypeMode typeMode);
    static AssignOp immutableCreate;
    static AssignOp mutableCreate;
    static AssignOp mutableUpdate;
};

class CType;

class CTypes {
public:
    CTypes(shared_ptr<CType> stackValueType, shared_ptr<CType> stackOptionType, shared_ptr<CType> heapValueType, shared_ptr<CType> heapOptionType, shared_ptr<CType> localValueType, shared_ptr<CType> localOptionType, shared_ptr<CType> weakType);
    shared_ptr<CType> stackValueType;
    shared_ptr<CType> stackOptionType;
    shared_ptr<CType> heapValueType;
    shared_ptr<CType> heapOptionType;
    shared_ptr<CType> localValueType;
    shared_ptr<CType> localOptionType;
    shared_ptr<CType> weakType;
};

class CType : public enable_shared_from_this<CType> {
public:
    static shared_ptr<CTypes> create(vector<string>& packageNamespace, string valueName, string cname, string defaultValue, string cnameOption, string defaultValueOption);
    static shared_ptr<CTypes> create(Compiler* compiler, vector<string>& packageNamespace, string valueName, weak_ptr<CFunction> parent);
    static shared_ptr<CTypes> create(Compiler* compiler, vector<string>& packageNamespace, string valueName, weak_ptr<CInterface> parent);
    static shared_ptr<CTypes> create(vector<shared_ptr<CType>> argTypes, shared_ptr<CType> stackReturnType, shared_ptr<CType> heapReturnType, weak_ptr<CCallback> callback);

    CTypeCategory category;
    CTypeMode typeMode;
    string fullName;
    vector<string> packageNamespace;
    string valueName;
    string cname;
    string safeName;
    weak_ptr<CBaseFunction> parent;
    bool isOption;
    weak_ptr<CCallback> callback;
    vector<shared_ptr<CType>> argTypes;
    shared_ptr<CType> stackReturnType;
    shared_ptr<CType> heapReturnType;

    void transpileDefaultValue(Compiler* compiler, CLoc loc, TrBlock* trBlock, shared_ptr<TrStoreValue> storeValue);
    static bool isSameExceptMode(shared_ptr<CType> l, shared_ptr<CType> r);
    shared_ptr<CType> getValueType();
    shared_ptr<CType> getOptionType();
    shared_ptr<CType> getHeapType();
    shared_ptr<CType> getHeapValueType();
    shared_ptr<CType> getHeapOptionType();
    shared_ptr<CType> getStackType();
    shared_ptr<CType> getStackValueType();
    shared_ptr<CType> getLocalType();
    shared_ptr<CType> getLocalValueType();
    shared_ptr<CType> getLocalOptionType();
    shared_ptr<CType> getWeakType();

private:
    string _defaultValue;
    weak_ptr<CType> stackValueType;
    weak_ptr<CType> stackOptionType;
    weak_ptr<CType> heapValueType;
    weak_ptr<CType> heapOptionType;
    weak_ptr<CType> localValueType;
    weak_ptr<CType> localOptionType;
    weak_ptr<CType> weakType;

    friend class CTypes;
};

#endif /* CType_h */
