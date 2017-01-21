//
//  NDot.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NDot_h
#define NDot_h

#include "NVariable.h"

class CDotVar : public CVar {
public:
    static shared_ptr<CDotVar> create(shared_ptr<CVar> leftVar_, shared_ptr<CVar> rightVar_);
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    virtual Value* getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    virtual Value* getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    string fullName();
    
    shared_ptr<CVar> leftVar;
    shared_ptr<CVar> rightVar;
};

class NDot : public NVariableBase {
public:
    shared_ptr<NVariableBase> left;
    shared_ptr<NVariableBase> right;
    
    NDot(CLoc loc, shared_ptr<NVariableBase> left, shared_ptr<NVariableBase> right) : left(left), right(right), NVariableBase(loc) {}
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction);
    virtual void fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar) const;
    virtual string getName() const;
    virtual shared_ptr<CVar> getVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar) const;
    virtual void dump(Compiler* compiler, int level) const;
};

#endif /* NDot_h */
