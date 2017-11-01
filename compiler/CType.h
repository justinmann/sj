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
#ifdef DWARF_ENABLED
    CType(const char* name/*, Type* llvmType, DIType* diType, Value* value*/);
#else
    CType(const char* name/*, Type* llvmType, Value* value*/);
#endif

    CType(const char* name, weak_ptr<CFunction> parent);
    CType(const char* name, weak_ptr<CInterface> parent);
#ifdef DWARF_ENABLED
    //DIType* getDIType(Compiler* compiler, CResult& result);
#endif

    CTypeCategory category;
    string name;
    string nameValue;
	string nameRef;
    weak_ptr<CBaseFunction> parent;
    //virtual Type* llvmAllocType(Compiler* compiler, CResult& result);
    //virtual Type* llvmRefType(Compiler* compiler, CResult& result);
    //virtual shared_ptr<ReturnValue> getDefaultValue(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB);

private:
    //Type* _llvmAllocType;
    //Type* _llvmRefType;
    //Value* _value;
#ifdef DWARF_ENABLED
    //DIType* _diType;
#endif
};

#endif /* CType_h */
