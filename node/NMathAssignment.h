//
//  NAssignment.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NMathAssignment_h
#define NMathAssignment_h

enum NMathAssignmentOp {
    NMAO_Inc,
    NMAO_Dec,
    NMAO_Add,
    NMAO_Sub
};

class NMathAssignment : public NBase {
public:
    NMathAssignment(CLoc loc, const char* name, NMathAssignmentOp op, shared_ptr<NBase> rightSide);
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual void fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const;
    virtual Value* compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const;
    virtual void dump(Compiler* compiler, int level) const;
    
    string fullName;
    vector<string> names;
    NMathAssignmentOp op;
    shared_ptr<NBase> rightSide;

private:
    shared_ptr<NAssignment> shared_from_this() { return static_pointer_cast<NAssignment>(NBase::shared_from_this()); }
};

#endif /* NAssignment_h */
