//
//  NGetOrElse.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright � 2016 Mann, Justin. All rights reserved.
//

#ifndef NGetOrElse_h
#define NGetOrElse_h

class NGetOrElse : public NVariableBase {
public:
    NGetOrElse(CLoc loc, shared_ptr<NVariableBase> left, shared_ptr<NBase> right) : NVariableBase(NodeType_GetOrElse, loc), left(left), right(right) {}

    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode);

private:
    shared_ptr<NVariableBase> left;
    shared_ptr<NBase> right;
};

#endif /* NGetOrElse_h */
