//
//  NOptionCast.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NOptionCast_h
#define NOptionCast_h

#include "NBlock.h"

class NOptionCast : public NBlock {
public:
    NOptionCast(CLoc loc, shared_ptr<CTypeName> typeName, shared_ptr<NVariableBase> node) : NBlock(loc), typeName(typeName), node(node) {}

protected:
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);

private:
    shared_ptr<CTypeName> typeName;
    shared_ptr<NVariableBase> node;

    void initStatements(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
};

#endif /* NOptionCast_h */
