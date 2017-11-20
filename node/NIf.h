//
//  NIf.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NIf_h
#define NIf_h

class CIfElseVar : public CVar {
public:
    CIfElseVar(CLoc& loc, shared_ptr<CBaseFunction> scope, shared_ptr<CVar> condVar, shared_ptr<CVar> ifVar, shared_ptr<CVar> elseVar) : CVar(loc, scope, "", false), condVar(condVar), ifVar(ifVar), elseVar(elseVar) { assert(condVar); assert(ifVar); }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    void transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);

private:
    shared_ptr<CVar> condVar;
    shared_ptr<CVar> ifVar;
    shared_ptr<CVar> elseVar;
};

class NIf : public NVariableBase {
public:
    NIf(CLoc& loc, shared_ptr<NBase> condition, shared_ptr<NBase> ifBlock, shared_ptr<NBase> elseBlock) : NVariableBase(NodeType_If, loc), condition(condition), ifBlock(ifBlock), elseBlock(elseBlock) { }
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode);
    
private:
    shared_ptr<NBase> condition;
    shared_ptr<NBase> ifBlock;
    shared_ptr<NBase> elseBlock;
};

#endif /* NIf_h */
