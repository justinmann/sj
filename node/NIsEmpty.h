//
//  NIsEmpty.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NIsEmpty_h
#define NIsEmpty_h

#include "NBlock.h"

class NIsEmpty : public NBlock {
public:
    NIsEmpty(CLoc loc, shared_ptr<NBase> node) : NBlock(loc), node(node) {}

protected:
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);

private:
    shared_ptr<NBase> node;

    void initStatements(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
};

#endif /* NIsEmpty_h */
