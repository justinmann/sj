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

class CType : public enable_shared_from_this<CType> {
public:
    static pair<shared_ptr<CType>, shared_ptr<CType>> create(string name, string cname, string defaultValue, string cnameOption, string defaultValueOption);
    static pair<shared_ptr<CType>, shared_ptr<CType>> create(string name, weak_ptr<CFunction> parent);
    static pair<shared_ptr<CType>, shared_ptr<CType>> create(string name, weak_ptr<CInterface> parent);

    CTypeCategory category;
    string name;
    string nameValue;
	string nameRef;
    weak_ptr<CBaseFunction> parent;
    bool isOption;

    shared_ptr<ReturnValue> transpileDefaultValue(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
    shared_ptr<CType> getOptionType();
    shared_ptr<CType> getNotOptionType();

private:
    string _defaultValue;
    weak_ptr<CType> _otherType;
};

#endif /* CType_h */
