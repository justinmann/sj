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
    Mod,
    Xor,
    Or,
    And,
    ShiftLeft,
    ShiftRight
};

class CMathVar : public CVar {
public:
    CMathVar(CLoc loc, shared_ptr<CScope> scope, NMathOp op, shared_ptr<CVar> leftVar, shared_ptr<CVar> rightVar) : CVar(loc, scope), op(op), leftVar(leftVar), rightVar(rightVar) { assert(leftVar); assert(rightVar); }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
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
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode);

    shared_ptr<NBase> operatorOverloadNode;
};

#endif /* NMath_h */
