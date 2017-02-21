//
//  CInterface.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef CInterface_h
#define CInterface_h

class CInterface;
class CInterfaceMethod;
class CTypeName;
class NInterface;
class NInterfaceMethod;

class CInterfaceMethodList : public vector<shared_ptr<CInterfaceMethod>> {
public:
    CInterfaceMethodList() { }
};

class CInterfaceMethod : public enable_shared_from_this<CInterfaceMethod> {
public:
    string name;
    weak_ptr<CInterface> parent;
    shared_ptr<NInterfaceMethod> ninterfaceMethod;
    map<string, shared_ptr<CType>> templateTypesByName;
    vector<shared_ptr<CVar>> argVars;

    static shared_ptr<CInterfaceMethod> create(Compiler* compiler, CResult& result, weak_ptr<CInterface> parent, shared_ptr<NInterfaceMethod> ninterfaceMethod);
    shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result);
    shared_ptr<vector<shared_ptr<CVar>>> getArgVars();
    shared_ptr<CType> getVarType(Compiler* compiler, CResult& result, shared_ptr<CTypeName> typeName);
    Function* getFunction();
};

#endif /* CInterface */
