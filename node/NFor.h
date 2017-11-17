//
//  NFor.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NFor_h
#define NFor_h

class CForIndexVar : public CVar {
public:
    CForIndexVar(CLoc loc, string name) : loc(loc), name(name) { }
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    shared_ptr<ReturnValue> transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName);
    void transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeReturnMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
    string name;

private:
    CLoc loc;
};

class CForLoopVar : public CVar {
public:
    CForLoopVar(CLoc loc, shared_ptr<CForIndexVar> indexVar, shared_ptr<CVar> startVar, shared_ptr<CVar> endVar, shared_ptr<CVar> bodyVar) : loc(loc), indexVar(indexVar), startVar(startVar), endVar(endVar), bodyVar(bodyVar) { }
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    shared_ptr<ReturnValue> transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName);
    void transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeReturnMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
private:
    CLoc loc;
    shared_ptr<CForIndexVar> indexVar;
    shared_ptr<CVar> startVar;
    shared_ptr<CVar> endVar;
    shared_ptr<CVar> bodyVar;
};

class NFor : public NBase {
public:
    NFor(CLoc loc, const char* varName, shared_ptr<NBase> start, shared_ptr<NBase> end, shared_ptr<NBase> body) : NBase(NodeType_For, loc), varName(varName), start(start), end(end), body(body) { }
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar);

    string varName;
    shared_ptr<NBase> start;
    shared_ptr<NBase> end;
    shared_ptr<NBase> body;    
};

#endif /* NFor_h */
