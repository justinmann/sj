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
    CMathVar(CLoc loc, NMathOp op, shared_ptr<CVar> leftVar, shared_ptr<CVar> rightVar) : loc(loc), op(op), leftVar(leftVar), rightVar(rightVar) { }
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    shared_ptr<ReturnValue> transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName);
    void transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeReturnMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
private:
    CLoc loc;
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
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar);

    shared_ptr<NBase> operatorOverloadNode;
};

#endif /* NMath_h */
