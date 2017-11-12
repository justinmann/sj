//
//  NOptionDot.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NOptionDot_h
#define NOptionDot_h

#include "NBlock.h"

class NOptionDot : public NBlock {
public:
    NOptionDot(CLoc loc, shared_ptr<NVariableBase> left, shared_ptr<NVariableBase> right) : NBlock(loc), left(left), right(right) {}

protected:
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);

private:
    shared_ptr<NVariableBase> left;
    shared_ptr<NVariableBase> right;

    void initStatements(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
};

#endif /* NOptionDot_h */
