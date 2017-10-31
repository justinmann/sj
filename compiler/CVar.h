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
class CBaseFunction;
class NAssignment;
class CResult;
class ReturnValue;
class TrOutput;
class TrFunction;

enum CVarType {
    Var_This,
    Var_Local,
    Var_Private,
    Var_Public
};

enum ReturnRefType {
    RRT_Auto,
    RRT_MustRelease,
    RRT_MustRetain
};

class CVar {
public:
    CVar() { }
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result) = 0;
    //virtual shared_ptr<ReturnValue> getLoadValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) = 0;
    //virtual Value* getStoreValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) = 0;
    string fullName();
    shared_ptr<CBaseFunction> getCFunctionForValue(Compiler* compiler, CResult& result);
    virtual bool getHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) = 0;
    virtual int setHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) = 0;
    virtual shared_ptr<CType> transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* output, TrFunction* function, stringstream& line) = 0;
    virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) = 0;

    string name;
    CVarType mode;
    bool isMutable;
    weak_ptr<CBaseFunction> parent;
    shared_ptr<NAssignment> nassignment;
};

class NFunction;

class CNormalVar : public CVar {
public:
    static shared_ptr<CNormalVar> createThisVar(const CLoc& loc, shared_ptr<CBaseFunction> parent, shared_ptr<CType> type);
    
    static shared_ptr<CNormalVar> createLocalVar(const CLoc& loc, const string& name, shared_ptr<CBaseFunction> parent, shared_ptr<NAssignment> nassignment);
    static shared_ptr<CNormalVar> createFunctionVar(const CLoc& loc, const string& name, shared_ptr<CBaseFunction> parent, int index, shared_ptr<NAssignment> nassignment, shared_ptr<CType> type, shared_ptr<CVar> interfaceMethodArgVar_);
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    //virtual shared_ptr<ReturnValue> getLoadValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType);
    //virtual Value* getStoreValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    void makeFunctionVar(int index);
    virtual bool getHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    virtual int setHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    virtual shared_ptr<CType> transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* output, TrFunction* function, stringstream& line);
    virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
private:
    CLoc loc;
    bool isInGetType;
    int index;
    shared_ptr<CType> type;
    //Value* value;
    bool isHeapVar;
    shared_ptr<CVar> interfaceMethodArgVar;
};

#endif /* CVar_h */
