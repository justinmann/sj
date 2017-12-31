//
//  NHash.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NHash_h
#define NHash_h

#include "NBlock.h"

class CHashVar : public CVar {
public:
    CHashVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> createHashVar, shared_ptr<CVar> resizeHashVar, vector<shared_ptr<CVar>> setAtVars, string name) : CVar(loc, scope), createHashVar(createHashVar), resizeHashVar(resizeHashVar), setAtVars(setAtVars), name(name) {}
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
private:
    shared_ptr<CVar> createHashVar;
    shared_ptr<CVar> resizeHashVar;
    vector<shared_ptr<CVar>> setAtVars;
    string name;
};

class NHash : public NVariableBase {
public:
    NHash(CLoc loc, vector<pair<shared_ptr<NBase>, shared_ptr<NBase>>> elements) : NVariableBase(NodeType_Hash, loc), elements(elements) {}
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode);

private:
    vector<pair<shared_ptr<NBase>, shared_ptr<NBase>>> elements;
};

#endif /* NHash_h */
