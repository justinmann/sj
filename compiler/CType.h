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

class CType {
public:
    string name;
    Type* llvmAllocType;
    Type* llvmRefType;
    vector<shared_ptr<CType>> members;
    map<string, pair<int, shared_ptr<CType>>> membersByName;
    
    CType(const char* name, Type* type);
    CType(Compiler* compiler, const char* name, vector<pair<string, shared_ptr<CType>>> members_);
#ifdef DWARF_ENABLED
    DIType* getDIType();
#endif
};

#endif /* CType_h */
