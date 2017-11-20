//
//  NValue.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright � 2016 Mann, Justin. All rights reserved.
//

#ifndef NValue_h
#define NValue_h

class CValueVar : public CVar {
public:
    CValueVar(CLoc loc, shared_ptr<CBaseFunction> scope, shared_ptr<CVar> var) : CVar(loc, scope, "", false), var(var) { }
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    void transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);

private:
    shared_ptr<CVar> var;
}; 

class NValue : public NVariableBase {
public:
    NValue(CLoc loc, shared_ptr<NBase> node) : NVariableBase(NodeType_GetValue, loc), node(node) {}
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
    shared_ptr<NBase> node;
};

#endif /* NValue_h */
