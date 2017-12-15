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
    CArrayVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> createArrayVar, vector<shared_ptr<CVar>> initAtVars, string name) : CVar(loc, scope), createArrayVar(createArrayVar), initAtVars(initAtVars), name(name) {}
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
private:
    shared_ptr<CVar> createArrayVar;
    vector<shared_ptr<CVar>> initAtVars;
    string name;
};

class CTempVar : public CVar {
public:
    CTempVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type, string name) : CVar(loc, scope), type(type), name(name) {}
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);

private:
    shared_ptr<CType> type;
    string name;
};

class NArray : public NVariableBase {
public:
    NArray(CLoc loc, shared_ptr<NodeList> elements) : NVariableBase(NodeType_Array, loc), elements(elements) {}    
    void defineImpl(Compiler* compiler, vector<vector<string>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
    shared_ptr<NodeList> elements;
};

#endif /* NArray_h */
