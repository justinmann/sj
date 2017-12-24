//
//  NDot.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NDot_h
#define NDot_h

#include "NVariable.h"

class NDot : public NVariableBase {
public:
    shared_ptr<NVariableBase> left;
    shared_ptr<NVariableBase> right;
    
    NDot(CLoc loc, shared_ptr<NVariableBase> left, shared_ptr<NVariableBase> right) : NVariableBase(NodeType_Dot, loc), left(left), right(right) {}

    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);
};

#endif /* NDot_h */
