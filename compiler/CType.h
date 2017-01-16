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
    CType(const char* name, Type* llvmType);
    CType(const char* name, weak_ptr<CFunction> parent);
#ifdef DWARF_ENABLED
    DIType* getDIType();
#endif

    string name;
    weak_ptr<CFunction> parent;
    Type* llvmAllocType(Compiler* compiler, CResult& result);
    Type* llvmRefType(Compiler* compiler, CResult& result);
    
private:
    Type* _llvmAllocType;
    Type* _llvmRefType;
};

#endif /* CType_h */
