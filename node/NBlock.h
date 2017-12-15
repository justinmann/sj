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
    CBlockVar(CLoc loc, shared_ptr<CScope> scope, vector<shared_ptr<CVar>> statements);
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
private:
    vector<shared_ptr<CVar>> statements;
};

class NBlock : public NVariableBase {
public:
    NBlock(CLoc loc) : NVariableBase(NodeType_Block, loc) { }
    NBlock(CLoc loc, NodeList statements) : NVariableBase(NodeType_Block, loc), statements(statements) { }
    void defineImpl(Compiler* compiler, vector<vector<string>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);
    
    NodeList statements;
};

#endif /* NBlock_h */
