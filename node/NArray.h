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

class NArray : public NVariableBase {
public:
    NArray(CLoc loc, shared_ptr<NodeList> elements) : NVariableBase(NodeType_Array, loc), elements(elements) {}    
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, CTypeReturnMode returnMode);
    
private:
    shared_ptr<NodeList> elements;
};

#endif /* NArray_h */
