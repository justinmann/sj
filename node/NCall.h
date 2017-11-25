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
    CCallVar(CLoc loc, shared_ptr<CScope> scope, CTypeMode returnMode) : CVar(loc, scope, "", false), returnMode(returnMode) {}
    bool getReturnThis();
    static shared_ptr<CCallVar> create(Compiler* compiler, CLoc loc_, const string& name_, shared_ptr<NodeList> arguments_, shared_ptr<CScope> scope, weak_ptr<CVar> dotVar_, shared_ptr<CBaseFunction> callee_, CTypeMode returnMode);
    shared_ptr<CType> getType(Compiler* compiler);
    bool getParameters(Compiler* compiler, vector<FunctionParameter>& parameters);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);

    CTypeMode returnMode;
    shared_ptr<NodeList> arguments;
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

    virtual void defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);
    shared_ptr<CBaseFunction> getCFunction(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
    shared_ptr<NCall> shared_from_this() { return static_pointer_cast<NCall>(NBase::shared_from_this()); };
};

#endif /* NCall_h */
