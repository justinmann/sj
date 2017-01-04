//
//  NMath.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NMath_h
#define NMath_h

enum NMathOp {
    Add,
    Sub,
    Div,
    Mul
};

class NMath : public NBase {
public:
    NMathOp op;
    const shared_ptr<NBase> leftSide;
    const shared_ptr<NBase> rightSide;
    
    NMath(CLoc loc, shared_ptr<NBase> leftSide, NMathOp op, shared_ptr<NBase> rightSide) : leftSide(leftSide), rightSide(rightSide), op(op), NBase(loc) { }
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result);
    virtual void fixVar(Compiler* compiler, CResult& result);
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result) const;
    virtual Value* compile(Compiler* compiler, CResult& result) const;
    virtual void dump(Compiler* compiler, int level) const;
};

#endif /* NMath_h */
