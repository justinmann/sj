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
    CEmptyVar(CLoc& loc, shared_ptr<CType> type, shared_ptr<CBaseFunction> thisFunction) : CVar(loc, thisFunction, "", false), type(type), thisFunction(thisFunction) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    void transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
private:
    shared_ptr<CType> type;
    shared_ptr<CBaseFunction> thisFunction;
};

class NEmpty : public NVariableBase {
public:
    NEmpty(CLoc& loc, shared_ptr<CTypeName> typeName);
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) { }
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
    shared_ptr<CTypeName> typeName;
};

#endif /* NEmpty_h */
