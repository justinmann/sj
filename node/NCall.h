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
    CCallVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) : CVar(loc, scope), dotVar(dotVar), returnMode(returnMode) {}
    bool getReturnThis();
    static shared_ptr<CCallVar> create(Compiler* compiler, CLoc loc_, const string& name_, shared_ptr<CVar> dotVar, shared_ptr<vector<FunctionParameter>> parameters, shared_ptr<CScope> scope, shared_ptr<CBaseFunction> callee_, CTypeMode returnMode);
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    static shared_ptr<vector<FunctionParameter>> getParameters(Compiler* compiler, CLoc loc, shared_ptr<CScope> callerScope, shared_ptr<CBaseFunction> callee, shared_ptr<NodeList> arguments, bool isHelperFunction, shared_ptr<CVar> dotVar, CTypeMode returnMode);

    CTypeMode returnMode;
    shared_ptr<CVar> dotVar;
    shared_ptr<vector<FunctionParameter>> parameters;
    shared_ptr<CBaseFunction> callee;
};

class NCall : public NVariableBase {
public:
    shared_ptr<NBase> thisNode;
    string name;
    shared_ptr<CTypeNameList> templateTypeNames;
    shared_ptr<NodeList> arguments;
    
    NCall(CLoc loc, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<NodeList> arguments);

    virtual void defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);
    shared_ptr<CBaseFunction> getCFunction(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode, bool* pisHelperFunction);

private:
    shared_ptr<NCall> shared_from_this() { return static_pointer_cast<NCall>(NBase::shared_from_this()); };
};

#endif /* NCall_h */
