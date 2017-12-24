//
//  NNullPtr.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NNullPtr_h
#define NNullPtr_h

class NNullPtr : public NVariableBase {
public:
    NNullPtr(CLoc loc) : NVariableBase(NodeType_NullPtr, loc) { }

    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) { }
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {}
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);
};

#endif /* NNullPtr_h */
