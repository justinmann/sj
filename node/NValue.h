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
    CValueVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> var) : CVar(loc, scope), var(var) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);

private:
    shared_ptr<CVar> var;
}; 

class NValue : public NVariableBase {
public:
    NValue(CLoc loc, shared_ptr<NBase> node) : NVariableBase(NodeType_GetValue, loc), node(node) {}
    void defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
    shared_ptr<NBase> node;
};

#endif /* NValue_h */
