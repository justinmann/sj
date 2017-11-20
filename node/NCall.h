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
    CCallVar(CLoc loc, shared_ptr<CBaseFunction> scope) : CVar(loc, scope, "", false) {}
    bool getReturnThis();
    static shared_ptr<CCallVar> create(Compiler* compiler, CResult& result, CLoc loc_, const string& name_, shared_ptr<NodeList> arguments_, shared_ptr<CBaseFunction> thisFunction_, shared_ptr<CThisVar> thisVar, weak_ptr<CVar> dotVar_, shared_ptr<CBaseFunction> callee_);
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    bool getParameters(Compiler* compiler, CResult& result, vector<pair<bool, shared_ptr<NBase>>>& parameters);
    virtual void transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);

    shared_ptr<NodeList> arguments;
    shared_ptr<CBaseFunction> thisFunction;
    shared_ptr<CThisVar> thisVar;
    weak_ptr<CVar> dotVar;
    shared_ptr<CBaseFunction> callee;
};

class NCall : public NVariableBase {
public:
    shared_ptr<NBase> thisNode;
    string name;
    shared_ptr<CTypeNameList> templateTypeNames;
    shared_ptr<NodeList> arguments;
    
    NCall(CLoc loc, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<NodeList> arguments);

    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode);
    shared_ptr<CBaseFunction> getCFunction(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
    shared_ptr<NCall> shared_from_this() { return static_pointer_cast<NCall>(NBase::shared_from_this()); };
    
    shared_ptr<CCallVar> _callVar;
};

#endif /* NCall_h */
