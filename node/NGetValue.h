//
//  NGetValue.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NGetValue_h
#define NGetValue_h

#include "NBlock.h"

class NGetValue : public NBlock {
public:
    NGetValue(CLoc loc, shared_ptr<NBase> node) : NBlock(loc), node(node) {}

protected:
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);

private:
    shared_ptr<NBase> node;

    void initStatements(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
};

#endif /* NGetValue_h */
