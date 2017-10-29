//
//  NIf.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NIf_h
#define NIf_h

class NIf;

class CIfElseVar : public CVar {
public:
    static shared_ptr<CIfElseVar> create(const CLoc& loc, shared_ptr<NIf> nif, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<NBase> condition, shared_ptr<NBase> ifBlock, shared_ptr<NBase> elseBlock);
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    //virtual shared_ptr<ReturnValue> getLoadValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType);
    //virtual Value* getStoreValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    string fullName();
    virtual bool getHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    virtual int setHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
    CLoc loc;
    shared_ptr<NIf> nif;
    shared_ptr<CBaseFunction> thisFunction;
    shared_ptr<CVar> thisVar;
    shared_ptr<NBase> condition;
    shared_ptr<NBase> ifBlock;
    shared_ptr<NBase> elseBlock;
};

class NIf : public NVariableBase {
public:
    shared_ptr<NBase> condition;
    shared_ptr<NBase> ifBlock;
    shared_ptr<NBase> elseBlock;
    
    NIf(CLoc loc, shared_ptr<NBase> condition, shared_ptr<NBase> ifBlock, shared_ptr<NBase> elseBlock) : NVariableBase(NodeType_If, loc), condition(condition), ifBlock(ifBlock), elseBlock(elseBlock) { }
    shared_ptr<NIf> shared_from_this();

protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar);
    virtual int setHeapVarImpl(Compiler *compiler, CResult &result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, bool isHeapVar);
};

#endif /* NIf_h */
