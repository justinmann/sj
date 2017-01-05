//
//  CFunction.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef CFunction_h
#define CFunction_h

class NFunction;

class CFunctionVar : public CVar {
public:
    static shared_ptr<CFunctionVar> create(const string& name, shared_ptr<CFunction> parent, shared_ptr<NFunction> nfunction, int index, shared_ptr<NAssignment> nassignment, shared_ptr<CType> type);
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    virtual Value* getValue(Compiler* compiler, CResult& result, Value* thisValue);
    shared_ptr<CFunction> getParentCFunction(Compiler* compiler, CResult& result);
    
    bool isInGetType;
    shared_ptr<NFunction> nfunction;
    int index;
    shared_ptr<CType> type;
    Value* value;
};

class CFunction : public enable_shared_from_this<CFunction> {
public:
    weak_ptr<CFunction> parent;
    string name;
    shared_ptr<NFunction> node;
    vector<shared_ptr<CFunctionVar>> thisVars;
    map<string, pair<int, shared_ptr<CFunctionVar>>> thisVarsByName;
    map<string, shared_ptr<CLocalVar>> localVarsByName;
    map<string, shared_ptr<CFunction>> funcsByName;
    
    static shared_ptr<CFunction> create(Compiler* compiler, CResult& result, shared_ptr<CFunction> parent, const string& name, shared_ptr<NFunction> node);
    shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result);
    shared_ptr<CType> getThisType(Compiler* compiler, CResult& result);
    Function* getFunction(Compiler* compiler, CResult& result);
    BasicBlock* getBasicBlock();
    Value* getArgumentValue(Compiler* compiler, CResult& result, Value* thisValue, int index);
    Argument* getThis();
    shared_ptr<CFunction> getCFunction(const string& name) const;
    shared_ptr<CVar> getCVar(const string& name) const;
    int getThisIndex(const string& name) const;
    shared_ptr<CFunctionVar> localVarToThisVar(Compiler* compiler, shared_ptr<CLocalVar> cvar);
    string fullName();
    void dump(Compiler* compiler, CResult& result, int level);
    
private:
    bool isInGetType;
    bool isInGetFunction;
    shared_ptr<CType> returnType;
    shared_ptr<CType> thisType;
    Function* func;
    BasicBlock* basicBlock;
    Value* thisValue;
};

#endif /* CFunction_h */
