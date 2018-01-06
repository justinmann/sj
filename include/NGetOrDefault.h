//
//  NGetOrDefault.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright � 2016 Mann, Justin. All rights reserved.
//

#ifndef NGetOrDefault_h
#define NGetOrDefault_h

class NGetOrDefault : public NVariableBase {
public:
    NGetOrDefault(CLoc loc, shared_ptr<NVariableBase> left) : NVariableBase(NodeType_GetOrDefault, loc), left(left) {}

    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode);

private:
    shared_ptr<NVariableBase> left;
};

#endif /* NGetOrDefault_h */
