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

class CallArgument {
public:
    CallArgument(string name, AssignOp op, shared_ptr<CVar> var) : name(name), op(op), var(var) {}
    CallArgument(shared_ptr<CVar> var) : name(name), op(AssignOp::immutableCreate), var(var) {}

    static vector<CallArgument> createList(shared_ptr<CVar> var1);
    static vector<CallArgument> createList(shared_ptr<CVar> var1, shared_ptr<CVar> var2);
    static vector<CallArgument> createList(shared_ptr<CVar> var1, shared_ptr<CVar> var2, shared_ptr<CVar> var3);
    static vector<CallArgument> createList(shared_ptr<CVar> var1, shared_ptr<CVar> var2, shared_ptr<CVar> var3, shared_ptr<CVar> var4);
    static vector<CallArgument> emptyList;

    string name;
    AssignOp op;
    shared_ptr<CVar> var;
};

class CCallVar : public CVar {
public:
    CCallVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<vector<FunctionParameter>> parameters, shared_ptr<CBaseFunction> callee, CTypeMode returnMode) : CVar(loc, scope), dotVar(dotVar), parameters(parameters), callee(callee), returnMode(returnMode) {}
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    virtual void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    static shared_ptr<vector<FunctionParameter>> getParameters(Compiler* compiler, CLoc loc, shared_ptr<CScope> callerScope, shared_ptr<CBaseFunction> callee, vector<CallArgument> arguments, bool isHelperFunction, shared_ptr<CVar> dotVar, CTypeMode returnMode);

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
    
    NCall(CLoc loc, string name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<NodeList> arguments);

    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);
    static shared_ptr<CBaseFunction> getCFunction(Compiler* compiler, CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, string name, shared_ptr<CTypeNameList> templateTypeNames, CTypeMode returnMode, bool* pisHelperFunction);

protected:
    virtual shared_ptr<CCallVar> createCallVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<vector<FunctionParameter>> parameters, shared_ptr<CBaseFunction> callee, CTypeMode returnMode);

private:
    shared_ptr<NCall> shared_from_this() { return static_pointer_cast<NCall>(NBase::shared_from_this()); };
};

#endif /* NCall_h */
