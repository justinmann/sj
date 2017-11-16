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
class ReturnValue;
class CVar;

enum CTypeImmutability {
    CTM_Undefined,
    CTM_Mutable,
    CTM_Immutable,
};

enum CTypeCategory {
    CTC_Value,
    CTC_Interface,
    CTC_Function
};

enum CTypeMode {
    CTM_Stack,
    CTM_Heap,
    CTM_MatchReturn
};

class CTypes {
public:
    CTypes(shared_ptr<CType> stackValueType, shared_ptr<CType> stackOptionType, shared_ptr<CType> heapValueType, shared_ptr<CType> heapOptionType) : stackValueType(stackValueType), stackOptionType(stackOptionType), heapValueType(heapValueType), heapOptionType(heapOptionType) {}
    shared_ptr<CType> stackValueType;
    shared_ptr<CType> stackOptionType;
    shared_ptr<CType> heapValueType;
    shared_ptr<CType> heapOptionType;
};

class CType : public enable_shared_from_this<CType> {
public:
    static shared_ptr<CTypes> create(string name, string cname, string defaultValue, string cnameOption, string defaultValueOption);
    static shared_ptr<CTypes> create(string name, weak_ptr<CFunction> parent);
    static shared_ptr<CTypes> create(string name, weak_ptr<CInterface> parent);

    CTypeCategory category;
    CTypeMode typeMode;
    string name;
    string nameValue;
	string nameRef;
    weak_ptr<CBaseFunction> parent;
    bool isOption;

    shared_ptr<ReturnValue> transpileDefaultValue(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
    shared_ptr<CType> getValueType();
    shared_ptr<CType> getOptionType();
    shared_ptr<CType> getHeapValueType();
    shared_ptr<CType> getHeapOptionType();
    shared_ptr<CType> getStackValueType();
    shared_ptr<CType> getStackOptionType();

private:
    string _defaultValue;
    weak_ptr<CType> stackValueType;
    weak_ptr<CType> stackOptionType;
    weak_ptr<CType> heapValueType;
    weak_ptr<CType> heapOptionType;

};

#endif /* CType_h */
