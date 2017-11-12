//
//  NEmpty.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NEmpty_h
#define NEmpty_h

#include "NBlock.h"

class NEmpty : public NBlock {
public:
    NEmpty(CLoc loc, shared_ptr<CTypeName> typeName) : NBlock(loc), typeName(typeName) {}

protected:
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);

private:
    shared_ptr<CTypeName> typeName;

    void initStatements(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
};

#endif /* NEmpty_h */
