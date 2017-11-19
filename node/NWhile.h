//
//  NWhile.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NWhile_h
#define NWhile_h

class CWhileVar : public CVar {
public:
    CWhileVar(CLoc loc, shared_ptr<CVar> condVar, shared_ptr<CVar> bodyVar) : CVar(loc, "", false), condVar(condVar), bodyVar(bodyVar) { }
    shared_ptr<CType> getType(Compiler* compiler, CResult& result, CTypeMode returnMode);
    shared_ptr<ReturnValue> transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName);
    void transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
private:
    shared_ptr<CVar> condVar;
    shared_ptr<CVar> bodyVar;
};

class NWhile : public NBase {
public:
    shared_ptr<NBase> cond;
    shared_ptr<NBase> body;
    
    NWhile(CLoc loc, shared_ptr<NBase> cond, shared_ptr<NBase> body) : NBase(NodeType_While, loc), cond(cond), body(body) { }
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar);
};

#endif /* NWhile_h */
