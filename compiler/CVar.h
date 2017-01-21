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
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result) = 0;
    virtual Value* getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) = 0;
    virtual Value* getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) = 0;
    string fullName();
    shared_ptr<CFunction> getCFunctionForValue(Compiler* compiler, CResult& result);

    string name;
    CVarType mode;
    bool isMutable;
    weak_ptr<CFunction> parent;
    shared_ptr<NAssignment> nassignment;
};

class CLocalVar : public CVar {
public:
    static shared_ptr<CLocalVar> create(const CLoc& loc, const string& name, shared_ptr<CFunction> parent, shared_ptr<NAssignment> nassignment);
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    virtual Value* getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    virtual Value* getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    
private:
    CLoc loc;
    bool isInGetType;
    shared_ptr<CType> type;
    AllocaInst* value;
};

#endif /* CVar_h */
