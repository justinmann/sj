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
class ReturnValue;

class CType {
public:
    CType(const char* name, Type* llvmType, Value* value);
    CType(const char* name, weak_ptr<CFunction> parent);
#ifdef DWARF_ENABLED
    DIType* getDIType();
#endif

    string name;
    weak_ptr<CFunction> parent;
    virtual Type* llvmAllocType(Compiler* compiler, CResult& result);
    virtual Type* llvmRefType(Compiler* compiler, CResult& result);
    virtual shared_ptr<ReturnValue> getDefaultValue(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB);

private:
    Type* _llvmAllocType;
    Type* _llvmRefType;
    Value* _value;
};

#endif /* CType_h */
