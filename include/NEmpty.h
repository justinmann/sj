//
//  NEmpty.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright � 2016 Mann, Justin. All rights reserved.
//

#ifndef NEmpty_h
#define NEmpty_h

#include "NBlock.h"

class CEmptyVar : public CVar {
public:
    CEmptyVar(CLoc loc, shared_ptr<CType> type, shared_ptr<CScope> scope) : CVar(loc, scope), type(type) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
private:
    shared_ptr<CType> type;
};

class NEmpty : public NVariableBase {
public:
    NEmpty(CLoc loc, shared_ptr<CTypeName> typeName);
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) { }
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {}
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode);

private:
    shared_ptr<CType> ctype;
    shared_ptr<CTypeName> typeName;
};

#endif /* NEmpty_h */
