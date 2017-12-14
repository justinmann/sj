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
    CParentVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CFunction> function, bool isHeap) : CVar(loc, scope), dotVar(dotVar), function(function), isHeap(isHeap) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);

private:
    shared_ptr<CVar> dotVar;
    shared_ptr<CFunction> function;
    bool isHeap;
}; 

class NParent : public NVariableBase {
public:
    NParent(CLoc loc, bool isHeap) : NVariableBase(NodeType_Parent, loc), isHeap(isHeap) { }
    void defineImpl(Compiler* compiler, vector<vector<string>>& namespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) { }
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
    bool isHeap;
};

#endif /* NParent_h */
