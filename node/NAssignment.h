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
#include "NVariable.h"

class CCallVar;

class CAssignVar : public CVar {
public:
    CAssignVar(CLoc loc, shared_ptr<CBaseFunction> scope, AssignOp op, bool isFirstAssignment, shared_ptr<CVar> leftVar, shared_ptr<CVar> rightVar) : CVar(loc, scope, "", op == ASSIGN_Mutable || op == ASSIGN_MutableCopy), op(op), isFirstAssignment(isFirstAssignment), leftVar(leftVar), rightVar(rightVar) { }
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    shared_ptr<ReturnValue> transpileGet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, const char* thisName);
    void transpileSet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName, AssignOp op, bool isFirstAssignment);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
private:
    AssignOp op;
    bool isFirstAssignment;
    shared_ptr<CVar> leftVar;
    shared_ptr<CVar> rightVar;
};

class NAssignment : public NBase {
public:
    NAssignment(CLoc loc, shared_ptr<NVariableBase> var, shared_ptr<CTypeName> typeName, const char* name, shared_ptr<NBase> rightSide, AssignOp op);
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode);
    shared_ptr<CType> getType(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode);
    
    shared_ptr<NVariableBase> var;
    shared_ptr<CTypeName> typeName;
    string name;
    bool inFunctionDeclaration;
    shared_ptr<NBase> rightSide;
    shared_ptr<NFunction> nfunction;
    AssignOp op;

private:
    bool _isFirstAssignment;
    shared_ptr<CVar> _assignVar;
    shared_ptr<NAssignment> shared_from_this();
    shared_ptr<CCallVar> _callVar;
};

#endif /* NAssignment_h */
