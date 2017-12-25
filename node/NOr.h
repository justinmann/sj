//
//  NOr.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NOr_h
#define NOr_h

class COrVar : public CVar {
public:
    COrVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> leftVar, shared_ptr<CVar> rightVar) : CVar(loc, scope), leftVar(leftVar), rightVar(rightVar) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);

private:
    shared_ptr<CVar> leftVar;
    shared_ptr<CVar> rightVar;
}; 

class NOr : public NVariableBase {
public:
    const shared_ptr<NVariableBase> left;
    const shared_ptr<NVariableBase> right;
    
    NOr(CLoc loc, shared_ptr<NVariableBase> left, shared_ptr<NVariableBase> right) : NVariableBase(NodeType_Or, loc), left(left), right(right) { }
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode);
};

#endif /* NOr_h */
