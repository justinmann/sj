//
//  NSwitch.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NSwitch_h
#define NSwitch_h

class CSwitchClause {
public:
    CSwitchClause(shared_ptr<CVar> condVar, shared_ptr<CVar> blockVar, shared_ptr<LocalVarScope> localVarScope) : condVar(condVar), blockVar(blockVar), localVarScope(localVarScope) {}

    shared_ptr<CVar> condVar;
    shared_ptr<CVar> blockVar;
    shared_ptr<LocalVarScope> localVarScope;
};

class CSwitchVar : public CVar {
public:
    CSwitchVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> valueVar, vector<CSwitchClause> clauseVars, shared_ptr<CSwitchClause> defaultClauseVar) : CVar(loc, scope), valueVar(valueVar), clauseVars(clauseVars), defaultClauseVar(defaultClauseVar) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);

private:
    shared_ptr<CVar> valueVar;
    vector<CSwitchClause> clauseVars;
    shared_ptr<CSwitchClause> defaultClauseVar;
};

class NSwitchClause : public NBase {
public:
    NSwitchClause(CLoc loc, shared_ptr<NBase> condition, shared_ptr<NBase> block) : NBase(NodeType_SwitchClause, loc), condition(condition), block(block) { }
    void defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);

    shared_ptr<NBase> condition;
    shared_ptr<NBase> block;
};

class NSwitch : public NBase {
public:
    NSwitch(CLoc loc, shared_ptr<NBase> value, vector<shared_ptr<NSwitchClause>> clauses) : NBase(NodeType_Switch, loc), value(value), clauses(clauses) { }
    void defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    
private:
    shared_ptr<NBase> value;
    vector<shared_ptr<NSwitchClause>> clauses;
};

#endif /* NSwitch_h */
