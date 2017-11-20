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
class TrValue;
class TrOutput;
class TrBlock;
class NBase;

enum CVarType {
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
    CVar(CLoc loc, shared_ptr<CBaseFunction> scope, string name, bool isMutable) : loc(loc), scope(scope), name(name), isMutable(isMutable) { }
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result) = 0;
    virtual void transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) = 0;
    virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) = 0;
    
    CLoc loc;
    weak_ptr<CBaseFunction> scope;
    string name;
    bool isMutable;
};

class CStoreVar : public CVar {
public:
    CStoreVar(CLoc loc, shared_ptr<CBaseFunction> scope, string name, bool isMutable) : CVar(loc, scope, name, isMutable) { }
    virtual shared_ptr<TrStoreValue> getStoreValue(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, AssignOp op, bool isFirstAssignment) = 0;
};

class NFunction;

class CNormalVar : public CStoreVar {
public:
    CNormalVar(CLoc loc, shared_ptr<CBaseFunction> scope, shared_ptr<CType> type, string name, bool isMutable, CVarType mode) : CStoreVar(loc, scope, name, isMutable), mode(mode), type(type) {}
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    void transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    shared_ptr<TrStoreValue> getStoreValue(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, AssignOp op, bool isFirstAssignment);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);

    CVarType mode;
    shared_ptr<NBase> source;

private:
    shared_ptr<CType> type;
};

#endif /* CVar_h */
