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
    NMAO_Sub,
    NMAO_Mul,
    NMAO_Div
};

class NMathAssignment : public NBase {
public:
    NMathAssignment(CLoc loc, shared_ptr<NVariableBase> leftSide, NMathAssignmentOp op, shared_ptr<NVariableBase> rightSide);
	virtual shared_ptr<ReturnValue> transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue, const char* thisName);
	virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
    NMathAssignmentOp op;
    shared_ptr<NVariableBase> leftSide;
    shared_ptr<NVariableBase> rightSide;

protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
    virtual int setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar);
    //virtual shared_ptr<ReturnValue> compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType);

private:
    shared_ptr<NAssignment> shared_from_this() { return static_pointer_cast<NAssignment>(NBase::shared_from_this()); }

    shared_ptr<NBase> operatorOverloadNode;
};

#endif /* NAssignment_h */
