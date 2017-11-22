//
//  NArrayAssignment.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright � 2016 Mann, Justin. All rights reserved.
//

#ifndef NTupleAssignment_h
#define NTupleAssignment_h

#include "NBase.h"
#include "NVariable.h"

class NTupleAssignmentArg {
public:
    NTupleAssignmentArg(CLoc loc, shared_ptr<NVariableBase> var, shared_ptr<CTypeName> typeName, const char* name, bool isMutable) : loc(loc), var(var), typeName(typeName), name(name), assignOp(isMutable ? ASSIGN_Mutable : ASSIGN_Immutable) {}

    CLoc loc;
    shared_ptr<NVariableBase> var;
    shared_ptr<CTypeName> typeName;
    string name;
    AssignOp assignOp;
};

typedef vector<shared_ptr<NTupleAssignmentArg>> NTupleAssignmentArgList;

class NTupleAssignment : public NVariableBase {
public:
    NTupleAssignment(CLoc loc, shared_ptr<NTupleAssignmentArgList> args, shared_ptr<NVariableBase> rightSide) : NVariableBase(NodeType_TupleAssignment, loc), args(args), rightSide(rightSide) {}
    void defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
    shared_ptr<NTupleAssignmentArgList> args;
    shared_ptr<NVariableBase> rightSide;
};

#endif /* NAssignment_h */
