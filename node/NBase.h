//
//  NBase.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NBase_h
#define NBase_h

#include "../transpile/TrOutput.h"

void dumpf(stringstream& ss, int level);

#define bool_to_str(x) ((x) ? "true" : "false")

class NVariableBase;
class CBaseFunctionDefinition;
class CFunction;

class NBase : public enable_shared_from_this<NBase> {
public:
    NBase(const NodeType nodeType, CLoc loc) : nodeType(nodeType), loc(loc), _hasDefined(false) { }
    void define(Compiler* compiler, vector<vector<string>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVar(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);

    virtual void defineImpl(Compiler* compiler, vector<vector<string>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) = 0;
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) = 0;
    
    const NodeType nodeType;
    CLoc loc;

private:
    bool _hasDefined;
    map<CScope*, shared_ptr<CVar>> _var;

    friend class NVariableBase;
};

#endif /* NBase_h */
