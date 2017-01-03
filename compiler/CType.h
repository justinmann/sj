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
class CFunction;
class CResult;

class CType {
public:
    string name;
    weak_ptr<CFunction> cfunction;
    
    CType(const char* name, Type* type);
    CType(Compiler* compiler, const char* name, shared_ptr<CFunction> cfunction);
#ifdef DWARF_ENABLED
    DIType* getDIType();
#endif
    Type* llvmAllocType(Compiler* compiler, CResult& result);
    Type* llvmRefType(Compiler* compiler, CResult& result);
    
private:
    Type* _llvmAllocType;
    Type* _llvmRefType;
    vector<shared_ptr<CType>> members;
    map<string, pair<int, shared_ptr<CType>>> membersByName;
};

#endif /* CType_h */
