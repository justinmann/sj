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
    virtual Value* getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, IRBuilder<>* builder);
    virtual Value* getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, IRBuilder<>* builder);
    
    bool isInGetType;
    shared_ptr<NFunction> nfunction;
    int index;
    shared_ptr<CType> type;
    Value* value;
};

class CThisVar : public CVar {
public:
    static shared_ptr<CThisVar> create(shared_ptr<CFunction> parent);
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    virtual Value* getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, IRBuilder<>* builder);
    virtual Value* getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, IRBuilder<>* builder);
};

enum CFunctionType {
    FT_Private,
    FT_Public,
    FT_Extern
};

class CFunction : public enable_shared_from_this<CFunction> {
public:
    weak_ptr<CFunction> parent;
    CFunctionType type;
    string name;
    shared_ptr<NFunction> node;
    vector<shared_ptr<CFunctionVar>> thisVars;
    map<string, pair<int, shared_ptr<CFunctionVar>>> thisVarsByName;
    map<string, shared_ptr<CVar>> localVarsByName;
    map<string, shared_ptr<CFunction>> funcsByName;
    BasicBlock* basicBlock;
    
    static shared_ptr<CFunction> create(Compiler* compiler, CResult& result, shared_ptr<CFunction> parent, CFunctionType type, const string& name, shared_ptr<NFunction> node);
    shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result);
    shared_ptr<CType> getThisType(Compiler* compiler, CResult& result);
    Function* getFunction(Compiler* compiler, CResult& result);
    Value* getArgumentValue(Compiler* compiler, CResult& result, Value* thisValue, int index, IRBuilder<>* builder);
    Value* getThisArgument(Compiler* compiler, CResult& result);
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
    Function* function;
    Value* thisValue;
};

#endif /* CFunction_h */
