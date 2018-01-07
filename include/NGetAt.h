//
//  NGetAt.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright � 2016 Mann, Justin. All rights reserved.
//

#ifndef NGetAt_h
#define NGetAt_h

class NGetAt : public NVariableBase {
public:
    NGetAt(CLoc loc, shared_ptr<NVariableBase> left, shared_ptr<NBase> index) : NVariableBase(NodeType_GetAt, loc), left(left), index(index) {}

    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode);

private:
    shared_ptr<NVariableBase> left;
    shared_ptr<NBase> index;
};

#endif /* NGetAt_h */
