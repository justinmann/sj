//
//  NArray.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NArray_h
#define NArray_h

#include "NBlock.h"

class NArray : public NBlock {
public:
    NArray(CLoc loc, shared_ptr<NodeList> elements);
    
protected:
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
    
private:
    shared_ptr<NodeList> elements;

    void initStatements(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
};

#endif /* NArray_h */
