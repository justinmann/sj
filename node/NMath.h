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
    Mul,
    Mod
};

class CMathVar : public CVar {
public:
    CMathVar(CLoc loc, shared_ptr<CBaseFunction> scope, NMathOp op, shared_ptr<CVar> leftVar, shared_ptr<CVar> rightVar) : CVar(loc, scope, "", false), op(op), leftVar(leftVar), rightVar(rightVar) { assert(leftVar); assert(rightVar); }
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    void transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
private:
    NMathOp op;
    shared_ptr<CVar> leftVar;
    shared_ptr<CVar> rightVar;
};

class NMath : public NVariableBase {
public:
    NMathOp op;
    const shared_ptr<NVariableBase> leftSide;
    const shared_ptr<NVariableBase> rightSide;
    
    NMath(CLoc loc, shared_ptr<NVariableBase> leftSide, NMathOp op, shared_ptr<NVariableBase> rightSide) : NVariableBase(NodeType_Math, loc), op(op), leftSide(leftSide), rightSide(rightSide) { }
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode);

    shared_ptr<NBase> operatorOverloadNode;
};

#endif /* NMath_h */
