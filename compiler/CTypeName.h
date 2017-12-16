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

extern vector<string> emptyNamespace;

class CTypeNameList : public vector<shared_ptr<CTypeName>> {
public:
    CTypeNameList() { }
    CTypeNameList(CTypeCategory category, CTypeMode typeMode, vector<string> packageNamespace, const string& name, bool isOption);
};

class CTypeNameParts {
public:
    bool isHash;
    string name;
    vector<string> packageNamespace;
};

class CTypeName {
public:
    CTypeCategory category;
    CTypeImmutability mutability;
    CTypeMode typeMode;
    vector<string> packageNamespace;
    string valueName;
    shared_ptr<CTypeNameList> templateTypeNames;
    shared_ptr<CTypeNameList> argTypeNames;
    shared_ptr<CTypeName> returnTypeName;
    bool isOption;

    CTypeName(CTypeCategory category, CTypeMode typeMode, vector<string> packageNamespace, const string& valueName, bool isOption) : category(category), mutability(CTI_Undefined), typeMode(typeMode), packageNamespace(packageNamespace), valueName(valueName), isOption(isOption) {
        assert(valueName.find("stack ") != 0);
        assert(valueName.find("heap ") != 0);
        assert(valueName.find("local ") != 0);
        assert(valueName.find("#") == string::npos);
        assert(valueName.back() != '?');
        assert(category != CTC_Function);

        boost::algorithm::to_lower(this->valueName);
    }

    CTypeName(CTypeCategory category, CTypeMode typeMode, vector<string> packageNamespace, const string& valueName, shared_ptr<CTypeNameList> templateTypeNames, bool isOption) : category(category), mutability(CTI_Undefined), typeMode(typeMode), packageNamespace(packageNamespace), valueName(valueName), templateTypeNames(templateTypeNames), isOption(isOption) {
        assert(valueName.find("stack ") != 0);
        assert(valueName.find("heap ") != 0);
        assert(valueName.find("local ") != 0);
        assert(valueName.find("#") == string::npos);
        assert(valueName.back() != '?');
        assert(category != CTC_Function);

        boost::algorithm::to_lower(this->valueName);
    }

    CTypeName(CTypeMode typeMode, shared_ptr<CTypeNameList> argTypeNames, shared_ptr<CTypeName> returnTypeName) : category(CTC_Function), mutability(CTI_Undefined), typeMode(typeMode), argTypeNames(argTypeNames), returnTypeName(returnTypeName), isOption(false) {
    }

    CTypeName(shared_ptr<CType> ctype);
    
    static shared_ptr<CTypeName> parse(string fullName);
    
    string getFullName();
};

#endif /* CTypeName_h */
