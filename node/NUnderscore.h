//
//  NUnderscore.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NUnderscore_h
#define NUnderscore_h

class NUnderscore : public NVariableBase {
public:
    NUnderscore(CLoc loc) : NVariableBase(NodeType_Underscore, loc) {}
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) { }
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {}
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);
};

#endif /* NUnderscore_h */
