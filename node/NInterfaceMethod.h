//
//  NInterfaceMethod.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NInterfaceMethod_h
#define NInterfaceMethod_h

class NInterfaceMethod : public NBaseFunction {
public:
    string name;
    shared_ptr<CTypeNameList> templateTypeNames;
    vector<shared_ptr<NAssignment>> assignments;
    shared_ptr<CTypeName> returnTypeName;

    NInterfaceMethod(CLoc loc, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<NodeList> arguments, shared_ptr<CTypeName> returnTypeName);
    virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);

protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {}
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) { return nullptr; }
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
    virtual int setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) { return 0; } 
    virtual shared_ptr<ReturnValue> compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB);
};

class CInterfaceMethodReturnVar : public CVar {
public:
    CInterfaceMethodReturnVar(shared_ptr<CType> returnType) : returnType(returnType), isHeapVar(false) { }
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    shared_ptr<ReturnValue> getLoadValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    Value* getStoreValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    bool getHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    int setHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
    shared_ptr<CType> returnType;
    bool isHeapVar;
};

class CInterfaceMethodArgVar : public CVar {
public:
    CInterfaceMethodArgVar(shared_ptr<CType> returnType) : returnType(returnType), isHeapVar(false) { }
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    shared_ptr<ReturnValue> getLoadValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    Value* getStoreValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    bool getHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    int setHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
    shared_ptr<CType> returnType;
    bool isHeapVar;
};

class CInterfaceMethod : public CBaseFunction, public enable_shared_from_this<CInterfaceMethod> {
public:
    shared_ptr<CType> returnType;
    vector<shared_ptr<CType>> argTypes;
    
    CInterfaceMethod(string& name, weak_ptr<CInterface> parent, int structIndex);
    shared_ptr<CInterfaceMethod> init(Compiler* compiler, CResult& result, shared_ptr<NInterfaceMethod> method);
    string fullName(bool includeTemplateTypes);
    
    bool getHasThis();
    shared_ptr<CType> getThisType(Compiler* compiler, CResult& result);
    int getThisIndex(const string& name) const;
    void createThisVar(Compiler* compiler, CResult& result, shared_ptr<CVar>& thisVar);
    Type* getStructType(Compiler* compiler, CResult& result);
    Value* getRefCount(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue);
    
    shared_ptr<CVar> getCVar(Compiler* compiler, CResult& result, const string& name);
    shared_ptr<CBaseFunction> getCFunction(Compiler* compiler, CResult& result, const string& name, shared_ptr<CBaseFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames);
    Value* getParentValue(Compiler* compiler, CResult& result, IRBuilder<>* builder, bool thisInEntry, Value* thisValue);
    shared_ptr<CType> getVarType(Compiler* compiler, CResult& result, shared_ptr<CTypeName> typeName);
    shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    shared_ptr<CVar> getReturnVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    
    shared_ptr<ReturnValue> call(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, shared_ptr<CVar> calleeVar, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters);
    void dumpBody(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    bool getReturnMustRelease(Compiler* compiler, CResult& result);
    Function* getDestructor(Compiler* compiler, CResult& result);
    Type* getFunctionType(Compiler* compiler, CResult& result);
    
private:
    shared_ptr<CInterfaceMethodReturnVar> returnVar;
    Type* functionType;
    int structIndex;
    CLoc loc;
};

#endif /* NInterfaceMethod_h */
