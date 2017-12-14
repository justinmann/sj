//
//  NTuple.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright � 2016 Mann, Justin. All rights reserved.
//

#ifndef NTuple_h
#define NTuple_h

#include "NBlock.h"

class NTuple : public NVariableBase {
public:
    NTuple(CLoc loc, shared_ptr<NodeList> elements) : NVariableBase(NodeType_Tuple, loc), elements(elements) { }
    void defineImpl(Compiler* compiler, vector<vector<string>>& namespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
    shared_ptr<NodeList> elements;
};

#endif /* NTuple_h */
