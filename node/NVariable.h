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
    NVariableBase(CLoc loc) : NBase(loc) { }
    
    virtual void fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
        fixVar(compiler, result, thisFunction, nullptr);
    }
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
        auto var = getVar(compiler, result, thisFunction, nullptr);
        return var->getType(compiler, result);
    }
    
    virtual Value* compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const {
        auto var = getVar(compiler, result, thisFunction, nullptr);
        return var->getLoadValue(compiler, result, thisValue, thisValue, builder, catchBB);
    }
    
    virtual string getName() const = 0;
    virtual void fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar) const = 0;
    virtual shared_ptr<CVar> getVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar) const = 0;
};

class CParentVar : public CVar {
public:
    static shared_ptr<CParentVar> create(shared_ptr<CFunction> parentFunction_, shared_ptr<CVar> childVar_);
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    virtual Value* getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    virtual Value* getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    string fullName();
    
    shared_ptr<CFunction> parentFunction;
    shared_ptr<CVar> childVar;
};

class NVariable : public NVariableBase {
public:
    string name;
    
    NVariable(CLoc loc, const char* name);
    virtual string getName() const;
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) { }
    virtual void fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar) const;
    virtual shared_ptr<CVar> getVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar) const;
    virtual void dump(Compiler* compiler, int level) const;
};

#endif /* NVariable_h */
