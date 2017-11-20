//
//  NBlock.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NBlock_h
#define NBlock_h

#include "NVariable.h"

class CBlockVar : public CVar {
public:
    CBlockVar(CLoc loc, shared_ptr<CBaseFunction> scope, vector<shared_ptr<CVar>> statements) : CVar(loc, scope, "", false), statements(statements) { }
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    shared_ptr<ReturnValue> transpileGet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, const char* thisName);
    void transpileSet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName, AssignOp op, bool isFirstAssignment);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
private:
    vector<shared_ptr<CVar>> statements;
};

class NBlock : public NVariableBase {
public:
    NBlock(CLoc loc) : NVariableBase(NodeType_Block, loc) { }
    NBlock(CLoc loc, NodeList statements) : NVariableBase(NodeType_Block, loc), statements(statements) { }
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode);
    
    NodeList statements;
};

#endif /* NBlock_h */
