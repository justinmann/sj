//
//  NAnd.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NAnd_h
#define NAnd_h

#include "NVariable.h"

class CAndVar : public CVar {
public:
    CAndVar(CLoc loc, shared_ptr<CBaseFunction> scope, shared_ptr<CVar> leftVar, shared_ptr<CVar> rightVar) : CVar(loc, scope, "", false), leftVar(leftVar), rightVar(rightVar) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    void transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);

private:
    shared_ptr<CVar> leftVar;
    shared_ptr<CVar> rightVar;
}; 

class NAnd : public NVariableBase {
public:
    NAnd(CLoc loc, shared_ptr<NVariableBase> left, shared_ptr<NVariableBase> right) : NVariableBase(NodeType_And, loc), left(left), right(right) { }
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
    const shared_ptr<NVariableBase> left;
    const shared_ptr<NVariableBase> right;
};

#endif /* NOr_h */
