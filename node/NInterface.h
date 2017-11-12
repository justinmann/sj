//
//  NInterface.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NInterface_h
#define NInterface_h

class NInterfaceMethod;

class NInterface : public NBaseFunction {
public:
    string name;
    shared_ptr<CTypeNameList> templateTypeNames;
    vector<shared_ptr<NInterfaceMethod>> methodList;

    NInterface(CLoc loc, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<NodeList> methodList);
	virtual shared_ptr<ReturnValue> transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue);
	virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);

protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) { return nullptr; }
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
    virtual int setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) { return 0; } 
    //virtual shared_ptr<ReturnValue> compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType);

private:
    shared_ptr<NInterface> shared_from_this();
};

class CInterfaceMethod;

class CInterfaceVar : public CVar {
public:
    CInterfaceVar(shared_ptr<CInterface> interface);
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    //shared_ptr<ReturnValue> getLoadValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType);
    //Value* getStoreValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    bool getHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    int setHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    virtual shared_ptr<ReturnValue> transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue, shared_ptr<ReturnValue> dotValue);
    virtual void transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
    bool isHeapVar;
};

class CInterface : public CBaseFunction, public enable_shared_from_this<CInterface> {
public:
    vector<shared_ptr<CInterfaceMethod>> methods;
    map<string, shared_ptr<CInterfaceMethod>> methodByName;
    map<string, shared_ptr<CType>> templateTypesByName;
    
    CInterface(weak_ptr<CInterfaceDefinition> definition, weak_ptr<CFunction> parent);
    shared_ptr<CInterface> init(Compiler* compiler, CResult& result, shared_ptr<NInterface> node, vector<shared_ptr<CType>>& templateTypes);
    string fullName(bool includeTemplateTypes);
    
    bool getHasThis();
    shared_ptr<CType> getThisType(Compiler* compiler, CResult& result, bool isOption);
    int getThisIndex(const string& name) const;
    shared_ptr<CVar> getThisVar(Compiler* compiler, CResult& result);
    //Type* getStructType(Compiler* compiler, CResult& result);
    //Value* getRefCount(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue);
    int getArgStart();

    shared_ptr<CVar> getCVar(Compiler* compiler, CResult& result, const string& name);
    shared_ptr<CBaseFunction> getCFunction(Compiler* compiler, CResult& result, const string& name, shared_ptr<CBaseFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames);
    //Value* getParentValue(Compiler* compiler, CResult& result, IRBuilder<>* builder, bool thisInEntry, Value* thisValue);
    pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>> getFunctionDefinition(string name) { assert(false); return make_pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>>(nullptr, nullptr); }
    shared_ptr<CType> getVarType(Compiler* compiler, CResult& result, shared_ptr<CTypeName> typeName);
    shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    shared_ptr<CVar> getReturnVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    string getCInitFunctionName();
    string getCDestroyFunctionName();
    string getCastFunctionName(shared_ptr<CBaseFunction> fromFunction);
    string getBaseName();
    string getStructName();
    string getTypeIdName();
    string transpileCast(shared_ptr<CBaseFunction> fromFunction, string varName);

    //shared_ptr<ReturnValue> call(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, shared_ptr<CVar> calleeVar, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters, ReturnRefType returnRefType);
    void transpileDefinition(Compiler* compiler, CResult& result, TrOutput* trOutput);
    shared_ptr<ReturnValue> transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue, shared_ptr<ReturnValue> calleeValue, shared_ptr<CVar> calleeVar, CLoc& calleeLoc, vector<pair<bool, shared_ptr<NBase>>>& parameters);
    void dumpBody(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    bool getReturnMustRelease(Compiler* compiler, CResult& result);
    //Function* getDestructor(Compiler* compiler, CResult& result);
    //shared_ptr<ReturnValue> cast(Compiler* compiler, CResult& result, IRBuilder<>* builder, shared_ptr<ReturnValue> fromValue, bool isHeap, vector<Function*>& interfaceMethodValues);

private:
    shared_ptr<CType> thisType;
    shared_ptr<CType> thisOptionType;
    //StructType* _structType;
};

class CInterfaceDefinition : public CBaseFunctionDefinition, public enable_shared_from_this<CInterfaceDefinition> {
public:
    shared_ptr<CTypeName> typeName;
    shared_ptr<NInterface> ninterface;

    CInterfaceDefinition(string& name);
    string fullName();
    void addChildFunction(string& name, shared_ptr<CBaseFunctionDefinition> childFunction);
    shared_ptr<CInterface> getInterface(Compiler* compiler, CResult& result, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CFunction> funcParent);
    
private:
    map<vector<shared_ptr<CType>>, shared_ptr<CInterface>> cinterfaces;
    vector<shared_ptr<CBaseFunctionDefinition>> methods;
};

#endif /* NInterface_h */
