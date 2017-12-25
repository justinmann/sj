//
//  NWhile.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NWhile_h
#define NWhile_h

class CWhileVar : public CVar {
public:
    CWhileVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> condVar, shared_ptr<CVar> bodyVar) : CVar(loc, scope), condVar(condVar), bodyVar(bodyVar) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
private:
    shared_ptr<CVar> condVar;
    shared_ptr<CVar> bodyVar;
};

class NWhile : public NBase {
public:
    shared_ptr<NBase> cond;
    shared_ptr<NBase> body;
    
    NWhile(CLoc loc, shared_ptr<NBase> cond, shared_ptr<NBase> body) : NBase(NodeType_While, loc), cond(cond), body(body) { }
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CType> returnType, CTypeMode returnMode);
};

#endif /* NWhile_h */
