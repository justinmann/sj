//
//  NIsEmptyOrValid.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright � 2016 Mann, Justin. All rights reserved.
//

#ifndef NIsEmptyOrValid_h
#define NIsEmptyOrValid_h

class CIsEmptyOrValidVar : public CVar {
public:
    CIsEmptyOrValidVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> var, bool isEmpty) : CVar(loc, scope), var(var), isEmpty(isEmpty){ }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
private:
    shared_ptr<CVar> var;
    bool isEmpty;
};

class NIsEmptyOrValid : public NVariableBase {
public:
    NIsEmptyOrValid(CLoc loc, shared_ptr<NBase> node, bool isEmpty) : NVariableBase(NodeType_IsEmptyOrValid, loc), node(node), isEmpty(isEmpty) {}
    bool getReturnThis();
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode);

private:
    shared_ptr<NBase> node;
    bool isEmpty;
};

#endif /* NIsEmpty_h */
