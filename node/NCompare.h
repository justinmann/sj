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
    
    NCompare(CLoc loc, shared_ptr<NBase> leftSide, NCompareOp op, shared_ptr<NBase> rightSide) : leftSide(leftSide), rightSide(rightSide), op(op), NBase(NodeType_Compare, loc) { }
    virtual void dump(Compiler* compiler, int level) const;

protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual int setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, bool isHeapVar);
    virtual Value* compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, bool isReturnRetained);
};

#endif /* NCompare_h */
