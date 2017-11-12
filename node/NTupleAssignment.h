//
//  NArrayAssignment.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NTupleAssignment_h
#define NTupleAssignment_h

#include "NBase.h"
#include "NVariable.h"

class NTupleAssignmentArg {
public:
    NTupleAssignmentArg(CLoc loc, shared_ptr<NVariableBase> var, shared_ptr<CTypeName> typeName, const char* name, bool isMutable) : loc(loc), var(var), typeName(typeName), name(name), isMutable(isMutable) {}

    CLoc loc;
    shared_ptr<NVariableBase> var;
    shared_ptr<CTypeName> typeName;
    string name;
    bool isMutable;
};

typedef vector<shared_ptr<NTupleAssignmentArg>> NTupleAssignmentArgList;

class NTupleAssignment : public NBlock {
public:
    NTupleAssignment(CLoc loc, shared_ptr<NTupleAssignmentArgList> args, shared_ptr<NVariableBase> rightSide) : NBlock(loc), args(args), rightSide(rightSide) {}

protected:
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);

private:
    shared_ptr<NTupleAssignmentArgList> args;
    shared_ptr<NVariableBase> rightSide;

    void initStatements(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
};

#endif /* NAssignment_h */
