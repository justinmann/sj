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
    CTM_Local,
    CTM_Value
};

class AssignOp {
public:
    bool isMutable;
    bool isCopy;
    CTypeMode typeMode;

    static AssignOp create(bool isMutable, bool isCopy, CTypeMode typeMode);
    static AssignOp immutableOp;
    static AssignOp mutableOp;
};

class CType;

class CTypes {
public:
    CTypes(shared_ptr<CType> stackValueType, shared_ptr<CType> stackOptionType, shared_ptr<CType> heapValueType, shared_ptr<CType> heapOptionType, shared_ptr<CType> localValueType, shared_ptr<CType> localOptionType) : stackValueType(stackValueType), stackOptionType(stackOptionType), heapValueType(heapValueType), heapOptionType(heapOptionType), localValueType(localValueType), localOptionType(localOptionType) {}
    shared_ptr<CType> stackValueType;
    shared_ptr<CType> stackOptionType;
    shared_ptr<CType> heapValueType;
    shared_ptr<CType> heapOptionType;
    shared_ptr<CType> localValueType;
    shared_ptr<CType> localOptionType;
};

class CType : public enable_shared_from_this<CType> {
public:
    static shared_ptr<CTypes> create(string valueName, string cname, string defaultValue, string cnameOption, string defaultValueOption);
    static shared_ptr<CTypes> create(Compiler* compiler, string valueName, weak_ptr<CFunction> parent);
    static shared_ptr<CTypes> create(Compiler* compiler, string valueName, weak_ptr<CInterface> parent);

    CTypeCategory category;
    CTypeMode typeMode;
    string fullName;
    string valueName;
    string cname;
    string safeName;
    weak_ptr<CBaseFunction> parent;
    bool isOption;

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

private:
    string _defaultValue;
    weak_ptr<CType> stackValueType;
    weak_ptr<CType> stackOptionType;
    weak_ptr<CType> heapValueType;
    weak_ptr<CType> heapOptionType;
    weak_ptr<CType> localValueType;
    weak_ptr<CType> localOptionType;
};

#endif /* CType_h */
