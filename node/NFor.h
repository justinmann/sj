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
    CForIndexVar(CLoc loc, shared_ptr<CScope> scope, string name) : CVar(loc, scope, name, "sjt_" + name, false) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
};

class CForLoopVar : public CVar {
public:
    CForLoopVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CForIndexVar> indexVar, shared_ptr<CVar> startVar, shared_ptr<CVar> endVar, shared_ptr<CVar> bodyVar, shared_ptr<FunctionBlock> forBlock, bool isAscending) : CVar(loc, scope), indexVar(indexVar), startVar(startVar), endVar(endVar), bodyVar(bodyVar), forBlock(forBlock), isAscending(isAscending) {
        assert(indexVar);
        assert(startVar);
        assert(endVar);
        assert(bodyVar);
    }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
private:
    shared_ptr<CForIndexVar> indexVar;
    shared_ptr<CVar> startVar;
    shared_ptr<CVar> endVar;
    shared_ptr<CVar> bodyVar;
    shared_ptr<FunctionBlock> forBlock; 
    bool isAscending;
};

class NFor : public NBase {
public:
    NFor(CLoc loc, const char* varName, shared_ptr<NBase> start, shared_ptr<NBase> end, shared_ptr<NBase> body, bool isAscending) : NBase(NodeType_For, loc), varName(varName), start(start), end(end), body(body), isAscending(isAscending) { }
    void defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);

    string varName;
    shared_ptr<NBase> start;
    shared_ptr<NBase> end;
    shared_ptr<NBase> body;    
    bool isAscending;
};

#endif /* NFor_h */
