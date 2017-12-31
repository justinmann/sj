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
class CScope;

enum CVarType {
    Var_Local,
    Var_Private,
    Var_Public,
};

class CVar {
public:
    CVar(CLoc loc, shared_ptr<CScope> scope) : loc(loc), scope(scope), name("INVALID"), cname("INVALID"), isMutable(false) { }
    CVar(CLoc loc, shared_ptr<CScope> scope, string name, string cname, bool isMutable) : loc(loc), scope(scope), name(name), cname(cname), isMutable(isMutable) { }
    virtual bool getReturnThis() = 0;
    virtual shared_ptr<CType> getType(Compiler* compiler) = 0;
    virtual void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) = 0;
    virtual void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) = 0;
    
    CLoc loc;
    weak_ptr<CScope> scope;
    string name;
    string cname;
    bool isMutable;
};

class CStoreVar : public CVar {
public:
    CStoreVar(CLoc loc, shared_ptr<CScope> scope, string name, string cname, bool isMutable) : CVar(loc, scope, name, cname, isMutable) { }
    virtual bool getCanStoreValue() = 0;
    virtual shared_ptr<TrStoreValue> getStoreValue(Compiler* compiler, shared_ptr<CScope> scope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, AssignOp op) = 0;
};

class NFunction;

class CNormalVar : public CStoreVar {
public:
    CNormalVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type, string name, bool isMutable, CVarType mode) : CStoreVar(loc, scope, name, mode == Var_Local ? "sjv_" + name : name, isMutable), mode(mode), type(type) {}
    CNormalVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type, string name, string cname, bool isMutable, CVarType mode, shared_ptr<CVar> dotVar) : CStoreVar(loc, scope, name, cname, isMutable), mode(mode), type(type), dotVar(dotVar) {}
    shared_ptr<CNormalVar> createForDot(shared_ptr<CVar> dotVar);
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    bool getCanStoreValue();
    shared_ptr<TrStoreValue> getStoreValue(Compiler* compiler, shared_ptr<CScope> scope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, AssignOp op);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);

    CVarType mode;
    shared_ptr<CVar> dotVar;

private:
    shared_ptr<CType> type;
};

#endif /* CVar_h */
