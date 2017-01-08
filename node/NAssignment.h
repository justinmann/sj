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
    virtual void define(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual void fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const;
    virtual Value* compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const;
    virtual void dump(Compiler* compiler, int level) const;
    
    const string typeName;
    const string name;
    bool inFunctionDeclaration;
    shared_ptr<NBase> rightSide;
    shared_ptr<NFunction> nfunction;
    bool isMutable;

private:
    shared_ptr<NAssignment> shared_from_this() { return static_pointer_cast<NAssignment>(NBase::shared_from_this()); }
};

#endif /* NAssignment_h */
