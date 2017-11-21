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
    PEQ,
    PNE,
    GT,
    GE,
    LT,
    LE
};

class CCompareVar : public CVar {
public:
    CCompareVar(CLoc loc, shared_ptr<CBaseFunction> scope, NCompareOp op, shared_ptr<CVar> leftVar, shared_ptr<CVar> rightVar) : CVar(loc, scope, "", false), op(op), leftVar(leftVar), rightVar(rightVar) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    void transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
private:
    NCompareOp op;
    shared_ptr<CVar> leftVar;
    shared_ptr<CVar> rightVar;
};


class NCompare : public NVariableBase {
public:
    NCompare(CLoc loc, shared_ptr<NVariableBase> leftSide, NCompareOp op, shared_ptr<NVariableBase> rightSide) : NVariableBase(NodeType_Compare, loc), op(op), leftSide(leftSide), rightSide(rightSide) { }
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode);
    
private:
    NCompareOp op;
    const shared_ptr<NVariableBase> leftSide;
    const shared_ptr<NVariableBase> rightSide;
    shared_ptr<NBase> operatorOverloadNode;
};

#endif /* NCompare_h */
