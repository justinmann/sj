//
//  CInterface.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef CInterface_h
#define CInterface_h

class CInterfaceMethod;

class CInterfaceMethodList : public vector<shared_ptr<CInterfaceMethod>> {
public:
    CInterfaceMethodList() { }
};

class CInterfaceMethod {
public:
    string name;
    shared_ptr<CTypeName> methodTypeName;
    
    CInterfaceMethod(const string& name, shared_ptr<CTypeName> methodTypeName) : name(name), methodTypeName(methodTypeName) { }
};


#endif /* CInterface */
