//
//  NAssignment.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NAssignment_h
#define NAssignment_h

#include "NBase.h"

class NCall;

class NAssignment : public NBase {
public:
    NAssignment(CLoc loc, const char* typeName, const char* name, shared_ptr<NBase> rightSide, bool isMutable);
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result);
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result) const;
    virtual Value* compile(Compiler* compiler, CResult& result) const;
    
    shared_ptr<CVar> var;
    const string typeName;
    const string name;
    const shared_ptr<NBase> rightSide;
    shared_ptr<NCall> call;
    bool isMutable;
};

#endif /* NAssignment_h */
