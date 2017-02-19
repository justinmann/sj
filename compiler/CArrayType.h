//
//  CArrayType.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef CArrayType_h
#define CArrayType_h

class CArrayType : public CType {
public:
    CArrayType(const char* name, weak_ptr<CBaseFunction> parent) : CType(name, parent) { }
    
    virtual Type* llvmAllocType(Compiler* compiler, CResult& result);
    virtual Type* llvmRefType(Compiler* compiler, CResult& result);
};

#endif /* CArrayType_h */
