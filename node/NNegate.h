//
//  NNegate.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NNegate_h
#define NNegate_h

class CNegateVar : public CVar {
public:
    CNegateVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> var) : CVar(loc, scope), var(var) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
private:
    shared_ptr<CVar> var;
};

class NNegate : public NVariableBase {
public:
    const shared_ptr<NBase> node;
    
    NNegate(CLoc loc, shared_ptr<NBase> node) : NVariableBase(NodeType_Negate, loc), node(node) { }
    void defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);
};

#endif /* NNegate_h */
