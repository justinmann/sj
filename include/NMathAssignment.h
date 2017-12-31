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
    NMathAssignment(CLoc loc, shared_ptr<NVariableBase> leftSide, NMathAssignmentOp op, shared_ptr<NVariableBase> numberSide);
    
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CType> returnType, CTypeMode returnMode);

private:
    NMathAssignmentOp op;
    shared_ptr<NVariableBase> leftSide;
    shared_ptr<NVariableBase> numberSide;

    shared_ptr<NAssignment> shared_from_this() { return static_pointer_cast<NAssignment>(NBase::shared_from_this()); }
};

#endif /* NAssignment_h */
