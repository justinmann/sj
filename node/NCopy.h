//
//  NCopy.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright � 2016 Mann, Justin. All rights reserved.
//

#ifndef NCopy_h
#define NCopy_h

class CCopyVar : public CVar {
public:
    CCopyVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> var, CTypeMode returnMode) : CVar(loc, scope), var(var), returnMode(returnMode) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);

private:
    shared_ptr<CVar> var;
    CTypeMode returnMode;
}; 

class NCopy : public NVariableBase {
public:
    NCopy(CLoc loc, shared_ptr<NBase> node) : NVariableBase(NodeType_Copy, loc), node(node) {}
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
    shared_ptr<NBase> node;
};

#endif /* NCopy_h */
