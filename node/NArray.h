//
//  NArray.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NArray_h
#define NArray_h

#include "NBlock.h"

class CArrayVar : public CVar {
public:
    CArrayVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> createArrayVar, vector<shared_ptr<CVar>> initAtVars) : CVar(loc, scope, "", false), createArrayVar(createArrayVar), initAtVars(initAtVars) {}
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
private:
    shared_ptr<CVar> createArrayVar;
    vector<shared_ptr<CVar>> initAtVars;
};

class NArray : public NVariableBase {
public:
    NArray(CLoc loc, shared_ptr<NodeList> elements) : NVariableBase(NodeType_Array, loc), elements(elements) {}    
    void defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
    shared_ptr<NodeList> elements;
};

#endif /* NArray_h */
