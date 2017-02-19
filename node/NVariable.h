//
//  NVariable.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NVariable_h
#define NVariable_h

enum ValueType {
    VT_STORE,
    VT_LOAD
};

class NVariableBase : public NBase {
public:
    NVariableBase(NodeType nodeType, CLoc loc) : NBase(nodeType, loc) { }
    virtual shared_ptr<CVar> getVar(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar);
    virtual int setHeapVar(Compiler *compiler, CResult &result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, bool isHeapVar);
    virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level = 0) {
        auto var = getVar(compiler, result, thisFunction, thisVar, nullptr);
        stringstream dotSS;
        var->dump(compiler, result, thisFunction, thisVar, nullptr, functions, ss, dotSS, level);
    }
    
protected:
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
        return getVarImpl(compiler, result, thisFunction, thisVar, nullptr);
    }
    
    virtual int setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
        return setHeapVarImpl(compiler, result, thisFunction, thisVar, nullptr, isHeapVar);
    }
    
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
        auto var = getVar(compiler, result, thisFunction, thisVar, nullptr);
        if (!var) {
            return nullptr;
        }
        return var->getType(compiler, result);
    }
    
    virtual shared_ptr<ReturnValue> compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
        auto var = getVar(compiler, result, thisFunction, thisVar, nullptr);
        return var->getLoadValue(compiler, result, thisVar, thisValue, true, thisValue, builder, catchBB);
    }
    
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar) = 0;
    virtual int setHeapVarImpl(Compiler *compiler, CResult &result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, bool isHeapVar) = 0;
};

class CParentVar : public CVar {
public:
    static shared_ptr<CParentVar> create(Compiler *compiler, CResult &result, shared_ptr<CFunction> parentFunction_, shared_ptr<CVar> childVar_);
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    virtual int setHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    virtual bool getHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    virtual shared_ptr<ReturnValue> getLoadValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    virtual Value* getStoreValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    string fullName();
    virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
    shared_ptr<CFunction> parentFunction;
    shared_ptr<CVar> childVar;
};

class NVariable : public NVariableBase {
public:
    string name;
    
    NVariable(CLoc loc, const char* name);
    
protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) { }
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar);
    virtual int setHeapVarImpl(Compiler *compiler, CResult &result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, bool isHeapVar);
};

#endif /* NVariable_h */
