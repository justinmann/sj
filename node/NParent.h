//
//  NParent.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NParent_h
#define NParent_h

class CParentVar : public CVar {
public:
    CParentVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CFunction> function) : CVar(loc, scope), dotVar(dotVar), function(function) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);

private:
    shared_ptr<CVar> dotVar;
    shared_ptr<CFunction> function;
}; 

class NParent : public NVariableBase {
public:
    NParent(CLoc loc) : NVariableBase(NodeType_Parent, loc) { }
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) { }
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {}
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
};

#endif /* NParent_h */
