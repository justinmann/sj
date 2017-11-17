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

class NTuple : public NBlock {
public:
    NTuple(CLoc loc, shared_ptr<NodeList> elements);

    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, CTypeReturnMode returnMode);

private:
    shared_ptr<NodeList> elements;
};

#endif /* NTuple_h */
