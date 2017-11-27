//
//  NChangeMode.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NChangeMode_h
#define NChangeMode_h

class CChangeModeVar : public CVar {
public:
    CChangeModeVar(CLoc loc, shared_ptr<CScope> scope, CTypeMode typeMode, shared_ptr<CVar> var) : CVar(loc, scope), typeMode(typeMode), var(var) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
private:
    CTypeMode typeMode;
    shared_ptr<CVar> var;
};

class NChangeMode : public NVariableBase {
public:
    NChangeMode(CLoc loc, CTypeMode typeMode, shared_ptr<NBase> node) : NVariableBase(NodeType_ChangeMode, loc), typeMode(typeMode), node(node) { }
    void defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);
    
private:
    CTypeMode typeMode;
    const shared_ptr<NBase> node;    
};

#endif /* NCast_h */
