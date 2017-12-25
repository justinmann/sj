//
//  NNot.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NNot_h
#define NNot_h

class CNotVar : public CVar {
public:
    CNotVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> var, bool isLogicalNot) : CVar(loc, scope), var(var), isLogicalNot(isLogicalNot) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
private:
    shared_ptr<CVar> var;
    bool isLogicalNot;
};

class NNot : public NVariableBase {
public:
    const shared_ptr<NBase> node;
    bool isLogicalNot;
    
    NNot(CLoc loc, shared_ptr<NBase> node, bool isLogicalNot) : NVariableBase(NodeType_Not, loc), node(node), isLogicalNot(isLogicalNot) { }
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode);
};

#endif /* NNot_h */
