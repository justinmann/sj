//
//  CVar.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef CVar_h
#define CVar_h

class CFunction;
class NAssignment;
class CResult;

enum CVarType {
    Local,
    Private,
    Public
};

class CFunction;

class CVar {
public:
    CVar() : isHeapVar(false) { }
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result) = 0;
    virtual Value* getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) = 0;
    virtual Value* getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) = 0;
    string fullName();
    shared_ptr<CFunction> getCFunctionForValue(Compiler* compiler, CResult& result);
    virtual bool getHeapVar(Compiler* compiler, CResult& result);
    virtual int setHeapVar(Compiler* compiler, CResult& result);

    string name;
    CVarType mode;
    bool isMutable;
    weak_ptr<CFunction> parent;
    shared_ptr<NAssignment> nassignment;
    
protected:
    bool isHeapVar;
};

class NFunction;

class CNormalVar : public CVar {
public:
    static shared_ptr<CNormalVar> createLocalVar(const CLoc& loc, const string& name, shared_ptr<CFunction> parent, shared_ptr<NAssignment> nassignment);
    static shared_ptr<CNormalVar> createFunctionVar(const CLoc& loc, const string& name, shared_ptr<CFunction> parent, shared_ptr<NFunction> nfunction, int index, shared_ptr<NAssignment> nassignment, shared_ptr<CType> type);
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    virtual Value* getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    virtual Value* getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    void makeFunctionVar(shared_ptr<NFunction> nfunction, int index);
    
private:
    CLoc loc;
    bool isInGetType;
    shared_ptr<NFunction> nfunction;
    int index;
    shared_ptr<CType> type;
    Value* value;
};

#endif /* CVar_h */
