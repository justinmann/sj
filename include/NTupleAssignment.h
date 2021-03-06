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
    NTupleAssignmentArg(CLoc loc, shared_ptr<NVariableBase> var, shared_ptr<CTypeName> typeName, const char* name, AssignOp op) : loc(loc), var(var), typeName(typeName), name(name), op(op) {}

    CLoc loc;
    shared_ptr<NVariableBase> var;
    shared_ptr<CTypeName> typeName;
    string name;
    AssignOp op;
};

typedef vector<shared_ptr<NTupleAssignmentArg>> NTupleAssignmentArgList;

class NTupleAssignment : public NVariableBase {
public:
    NTupleAssignment(CLoc loc, shared_ptr<NTupleAssignmentArgList> args, shared_ptr<NBase> rightSide) : NVariableBase(NodeType_TupleAssignment, loc), args(args), rightSide(rightSide) {}
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode);

private:
    shared_ptr<NTupleAssignmentArgList> args;
    shared_ptr<NBase> rightSide;
};

#endif /* NAssignment_h */
