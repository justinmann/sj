//
//  NCompare.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NCompare_h
#define NCompare_h

enum NCompareOp {
    EQ,
    NE,
    GT,
    GE,
    LT,
    LE
};

class NCompare : public NBase {
public:
    NCompareOp op;
    const shared_ptr<NBase> leftSide;
    const shared_ptr<NBase> rightSide;
    
    NCompare(CLoc loc, shared_ptr<NBase> leftSide, NCompareOp op, shared_ptr<NBase> rightSide) : leftSide(leftSide), rightSide(rightSide), op(op), NBase(loc) { }
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result);
    virtual void fixVar(Compiler* compiler, CResult& result);
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result) const;
    virtual Value* compile(Compiler* compiler, CResult& result) const;
};

#endif /* NCompare_h */
