//
//  NCall.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NCall_h
#define NCall_h

#include "NVariable.h"

class NCall;

class CCallVar : public CVar {
public:
    static shared_ptr<CCallVar> create(CLoc loc_, const string& name_, shared_ptr<NodeList> arguments_, shared_ptr<CFunction> thisFunction_, weak_ptr<CVar> dotVar_, shared_ptr<CFunction> callee_);
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    virtual Value* getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    virtual Value* getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    string fullName();
    virtual bool getHeapVar(Compiler* compiler, CResult& result);
    virtual int setHeapVar(Compiler* compiler, CResult& result);

    CLoc loc;
    shared_ptr<NodeList> arguments;
    shared_ptr<CFunction> thisFunction;
    weak_ptr<CVar> dotVar;
    shared_ptr<CFunction> callee;
};

class NCall : public NVariableBase {
public:
    shared_ptr<NBase> thisNode;
    string name;
    shared_ptr<TemplateTypeNames> templateTypeNames;
    shared_ptr<NodeList> arguments;
    
    NCall(CLoc loc, const char* name, shared_ptr<TemplateTypeNames> templateTypeNames, shared_ptr<NodeList> arguments);
    virtual void dump(Compiler* compiler, int level) const;

protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar);
    shared_ptr<CFunction> getCFunction(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar);
    virtual int setHeapVarImpl(Compiler *compiler, CResult &result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar, bool isHeapVar);

private:
    shared_ptr<NCall> shared_from_this() { return static_pointer_cast<NCall>(NBase::shared_from_this()); };
};

#endif /* NCall_h */
