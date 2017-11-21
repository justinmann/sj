//
//  NIsEmpty.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright � 2016 Mann, Justin. All rights reserved.
//

#ifndef NIsEmpty_h
#define NIsEmpty_h

class CIsEmptyVar : public CVar {
public:
    CIsEmptyVar(CLoc loc, shared_ptr<CBaseFunction> scope, shared_ptr<CVar> var) : CVar(loc, scope, "", false), var(var) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    void transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
private:
    shared_ptr<CVar> var;
};

class NIsEmpty : public NVariableBase {
public:
    NIsEmpty(CLoc loc, shared_ptr<NBase> node) : NVariableBase(NodeType_IsEmpty, loc), node(node) {}
    bool getReturnThis();
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
    shared_ptr<NBase> node;
};

#endif /* NIsEmpty_h */
