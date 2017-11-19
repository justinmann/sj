//
//  NIsEmpty.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright � 2016 Mann, Justin. All rights reserved.
//

#ifndef NIsEmpty_h
#define NIsEmpty_h

class CIsEmptyVar : public CVar {
public:
    CIsEmptyVar(CLoc loc, shared_ptr<CVar> var) : CVar(loc, "", false), var(var) { }
    shared_ptr<CType> getType(Compiler* compiler, CResult& result, CTypeMode returnMode);
    shared_ptr<ReturnValue> transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName);
    void transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
private:
    shared_ptr<CVar> var;
};

class NIsEmpty : public NVariableBase {
public:
    NIsEmpty(CLoc loc, shared_ptr<NBase> node) : NVariableBase(NodeType_IsEmpty, loc), node(node) {}
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar);

private:
    shared_ptr<NBase> node;
};

#endif /* NIsEmpty_h */
