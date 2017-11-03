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

class CType {
public:
    CType(const char* name, const char* cname, const char* defaultValue);
    CType(const char* name, weak_ptr<CFunction> parent);
    CType(const char* name, weak_ptr<CInterface> parent);

    CTypeCategory category;
    string name;
    string nameValue;
	string nameRef;
    weak_ptr<CBaseFunction> parent;
    void transpileDefaultValue(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, stringstream& line);

private:
    string _defaultValue;
};

#endif /* CType_h */
