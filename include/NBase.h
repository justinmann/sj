//
//  NBase.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NBase_h
#define NBase_h

#include "TrOutput.h"

void dumpf(stringstream& ss, int level);

#define bool_to_str(x) ((x) ? "true" : "false")

class NVariableBase;
class CBaseFunctionDefinition;
class CFunction;

class NBase : public enable_shared_from_this<NBase> {
public:
    NBase(const NodeType nodeType, CLoc loc) : nodeType(nodeType), loc(loc), _hasInitFunctions(false) { }
    void initFunctions(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVars(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVar(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CType> leftType, CTypeMode returnMode);

    virtual void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) = 0;
    virtual void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) = 0;
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CType> returnType, CTypeMode returnMode) = 0;
    
    const NodeType nodeType;
    CLoc loc;

private:
    bool _hasInitFunctions;
    map<CScope*, bool> _hasInitVars;
    map<CScope*, shared_ptr<CVar>> _var;

    friend class NVariableBase;
};

#endif /* NBase_h */
