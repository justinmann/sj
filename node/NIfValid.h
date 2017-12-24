//
//  NIfValid.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NIfValid_h
#define NIfValid_h

class CIfParameter {
public:
    shared_ptr<CVar> isValidVar;
    shared_ptr<CVar> getValueVar;
    shared_ptr<CStoreVar> storeVar;
};

class CIfValidVar : public CVar {
public:
    CIfValidVar(CLoc loc, shared_ptr<CScope> scope, vector<CIfParameter> optionalVars, shared_ptr<CVar> ifVar, shared_ptr<LocalVarScope> ifLocalVarScope, shared_ptr<CVar> elseVar, shared_ptr<LocalVarScope> elseLocalVarScope) : CVar(loc, scope), optionalVars(optionalVars), ifVar(ifVar), ifLocalVarScope(ifLocalVarScope), elseVar(elseVar), elseLocalVarScope(elseLocalVarScope) { assert(ifVar); }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);

private:
    vector<CIfParameter> optionalVars;
    shared_ptr<CVar> ifVar;
    shared_ptr<LocalVarScope> ifLocalVarScope;
    shared_ptr<CVar> elseVar;
    shared_ptr<LocalVarScope> elseLocalVarScope;
};

class NIfValid : public NVariableBase {
public:
    NIfValid(CLoc loc, shared_ptr<NodeList> vars, shared_ptr<NBase> ifBlock, shared_ptr<NBase> elseBlock) : NVariableBase(NodeType_If, loc), vars(vars), ifBlock(ifBlock), elseBlock(elseBlock) { }
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);
    
private:
    shared_ptr<NodeList> vars;
    shared_ptr<NBase> ifBlock;
    shared_ptr<NBase> elseBlock;
};

#endif /* NIf_h */
