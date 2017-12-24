//
//  NLambda.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NLambda_h
#define NLambda_h

class NLambda : public NBase {
public:
    NLambda(CLoc loc, shared_ptr<NodeList> arguments, shared_ptr<NBase> block) : NBase(NodeType_Lambda, loc), arguments(arguments), block(block) { }

    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);

private:
    shared_ptr<NodeList> arguments;
    shared_ptr<NBase> block;
    shared_ptr<NBase> result;
};

#endif /* NLambda_h */
