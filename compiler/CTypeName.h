//
//  CTypeName.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef CTypeName_h
#define CTypeName_h

#include "CType.h"

class NFunction;

class CTypeName;

class CTypeNameList : public vector<shared_ptr<CTypeName>> {
public:
    CTypeNameList() { }
    CTypeNameList(CTypeCategory category, const string& name, bool isOption);
};

class CTypeName {
public:
    CTypeCategory category;
    CTypeImmutability mutability;
    string name;
    shared_ptr<CTypeNameList> templateTypeNames;
    shared_ptr<CTypeNameList> argTypeNames;
    shared_ptr<CTypeName> returnTypeName;
    bool isOption;

    CTypeName(CTypeCategory category, const string& name, bool isOption) : category(category), mutability(CTM_Undefined), name(name), isOption(isOption) {
        assert((category == CTC_Interface) == (name[0] == '#')); 
        assert(name[1] != '#'); 
        assert(category != CTC_Function);
    }

    CTypeName(CTypeCategory category, const string& name, shared_ptr<CTypeNameList> templateTypeNames, bool isOption) : category(category), mutability(CTM_Undefined), name(name), templateTypeNames(templateTypeNames), isOption(isOption) {
        assert((category == CTC_Interface) == (name[0] == '#')); 
        assert(name[1] != '#'); 
        assert(category != CTC_Function);
    }

    CTypeName(shared_ptr<CTypeNameList> argTypeNames, shared_ptr<CTypeName> returnTypeName) : category(CTC_Function), mutability(CTM_Undefined), argTypeNames(argTypeNames), returnTypeName(returnTypeName), isOption(false) {
        assert(false);
    }

    CTypeName(shared_ptr<CType> ctype);
    
    static shared_ptr<CTypeName> parse(string name);
    
    string getName();
};

#endif /* CTypeName_h */
