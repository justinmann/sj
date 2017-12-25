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
    CIfElseVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> condVar, shared_ptr<CVar> ifVar, shared_ptr<LocalVarScope> ifLocalVarScope, shared_ptr<CVar> elseVar, shared_ptr<LocalVarScope> elseLocalVarScope) : CVar(loc, scope), condVar(condVar), ifVar(ifVar), ifLocalVarScope(ifLocalVarScope), elseVar(elseVar), elseLocalVarScope(elseLocalVarScope) { assert(condVar); assert(ifVar); }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);

private:
    shared_ptr<CVar> condVar;
    shared_ptr<CVar> ifVar;
    shared_ptr<LocalVarScope> ifLocalVarScope;
    shared_ptr<CVar> elseVar;
    shared_ptr<LocalVarScope> elseLocalVarScope;
};

class NIf : public NVariableBase {
public:
    NIf(CLoc loc, shared_ptr<NBase> condition, shared_ptr<NBase> ifBlock, shared_ptr<NBase> elseBlock, bool useLocalVarScope = true) : NVariableBase(NodeType_If, loc), condition(condition), ifBlock(ifBlock), elseBlock(elseBlock), useLocalVarScope(useLocalVarScope) { }
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode);
    
private:
    shared_ptr<NBase> condition;
    shared_ptr<NBase> ifBlock;
    shared_ptr<NBase> elseBlock;
    bool useLocalVarScope;
};

#endif /* NIf_h */
