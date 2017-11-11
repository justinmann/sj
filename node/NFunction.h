//
//  NFunction.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NFunction_h
#define NFunction_h

#include "NBlock.h"
#include "NBaseFunction.h"

enum CFunctionType {
    FT_Private,
    FT_Public,
    FT_Extern
};

class CFunctionDefinition;
class CInterfaceMethod;

class NFunction : public NBaseFunction {
public:
    CFunctionType type;
    const string externName;
    shared_ptr<CTypeName> returnTypeName;
    string name;
    shared_ptr<CTypeNameList> templateTypeNames;
    shared_ptr<CTypeNameList> interfaceTypeNames;
    NodeList invalid;
    vector<shared_ptr<NAssignment>> assignments;
    vector<shared_ptr<NFunction>> functions;
    const shared_ptr<NBase> block;
    const shared_ptr<NBase> catchBlock;
    const shared_ptr<NBase> destroyBlock;
    
    // For normal
    NFunction(CLoc loc, CFunctionType type, shared_ptr<CTypeName> returnTypeName, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<CTypeNameList> interfaceTypeNames, shared_ptr<NodeList> arguments, shared_ptr<NBase> block, shared_ptr<NBase> catchBlock, shared_ptr<NBase> destroyBlock);

    // For extern
    NFunction(CLoc loc, CFunctionType type, const char* externName, shared_ptr<CTypeName> returnTypeName, const char* name, shared_ptr<NodeList> arguments);
    shared_ptr<CFunctionDefinition> getFunctionDefinition(Compiler *compiler, CResult& result, shared_ptr<CFunctionDefinition> parentFunction);
	virtual shared_ptr<ReturnValue> transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue);
	virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) { }
    
protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> parentFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> parentFunction, shared_ptr<CVar> parentVar);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> parentFunction, shared_ptr<CVar> parentVar);
    virtual int setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) { return 0; }
    //virtual shared_ptr<ReturnValue> compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> parentFunction, shared_ptr<CVar> parentVar, Value* parentValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType);
    virtual shared_ptr<CFunction> createCFunction(Compiler* compiler, CResult& result, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, CFunctionType type, const string& name, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, shared_ptr<CInterfaceMethod> interfaceMethod);
    shared_ptr<NFunction> shared_from_this() { return static_pointer_cast<NFunction>(NBase::shared_from_this()); };
    
private:    
    bool isInGetType;
    
    friend class CFunctionDefinition;
};

class CInterfaceMethod;
class CInterfaceMethodReturnVar;

class CFunctionReturnVar : public CVar, public enable_shared_from_this<CFunctionReturnVar> {
public:
    CFunctionReturnVar(shared_ptr<CVar> returnVar, shared_ptr<CInterfaceMethodReturnVar> interfaceMethodReturnVar);
    void init(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    //shared_ptr<ReturnValue> getLoadValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType);
    //Value* getStoreValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB);
    bool getHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    int setHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    virtual shared_ptr<ReturnValue> transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue, shared_ptr<ReturnValue> dotValue);
    virtual void transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
    shared_ptr<CVar> returnVar;
    shared_ptr<CInterfaceMethodReturnVar> interfaceMethodReturnVar;
};

class CFunction : public CBaseFunction, public enable_shared_from_this<CFunction> {
public:
    CFunction(weak_ptr<CBaseFunctionDefinition> definition, CFunctionType type, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces);
    shared_ptr<CFunction> init(Compiler* compiler, CResult& result, shared_ptr<NFunction> node, shared_ptr<CInterfaceMethod> interfaceMethod);
    
    shared_ptr<CVar> getThisVar(Compiler* compiler, CResult& result);
    shared_ptr<CBaseFunction> getCFunction(Compiler* compiler, CResult& result, const string& name, shared_ptr<CBaseFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames);
    shared_ptr<CInterface> getCInterface(Compiler* compiler, CResult& result, const string& name, shared_ptr<CBaseFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames);
    shared_ptr<CVar> getCVar(Compiler* compiler, CResult& result, const string& name);
    shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    shared_ptr<CVar> getReturnVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    shared_ptr<vector<shared_ptr<CVar>>> getArgVars(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    bool getHasThis();
    int getThisIndex(const string& name) const;
    shared_ptr<CType> getThisType(Compiler* compiler, CResult& result);
    shared_ptr<vector<pair<string, shared_ptr<CType>>>> getCTypeList(Compiler* compiler, CResult& result);
    //shared_ptr<vector<Type*>> getTypeList(Compiler* compiler, CResult& result);
    //Type* getStructType(Compiler* compiler, CResult& result);
    //Function* getFunction(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    //Function* getDestructor(Compiler* compiler, CResult& result);
    bool getReturnMustRelease(Compiler* compiler, CResult& result);
    //Value* getThisArgument(Compiler* compiler, CResult& result);
    void localVarToThisVar(Compiler* compiler, shared_ptr<CNormalVar> cvar);
    int getArgStart(Compiler* compiler, CResult& result);
    //Value* getArgumentPointer(Compiler* compiler, CResult& result, bool thisInEntry, Value* thisValue, int index, IRBuilder<>* builder);
    //Value* getParentPointer(Compiler* compiler, CResult& result, IRBuilder<>* builder, bool thisInEntry, Value* thisValue);
    //Value* getParentValue(Compiler* compiler, CResult& result, IRBuilder<>* builder, bool thisInEntry, Value* thisValue);
    string fullName(bool includeTemplateTypes);
    pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>> getFunctionDefinition(string name);
    shared_ptr<CType> getVarType(Compiler* compiler, CResult& result, string name);
    shared_ptr<CType> getVarType(Compiler* compiler, CResult& result, shared_ptr<CTypeName> typeName);
    //Value* getRefCount(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue);
    
    //virtual shared_ptr<ReturnValue> call(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, shared_ptr<CVar> calleeVar, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters, ReturnRefType returnRefType);
    virtual void getVarBody(Compiler *compiler, CResult& result, shared_ptr<CVar> thisVar);
    virtual int setHeapVarBody(Compiler *compiler, CResult& result, shared_ptr<CVar> thisVar);
    void transpileDefinition(Compiler* compiler, CResult& result, TrOutput* trOutput);
    shared_ptr<ReturnValue> transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue, shared_ptr<ReturnValue> calleeValue, shared_ptr<CVar> calleeVar, CLoc& calleeLoc, vector<shared_ptr<NBase>>& parameters);
    //Function* compileDefinition(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    //virtual bool compileBody(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Function* function);
    //virtual Function* compileDestructorDefinition(Compiler* compiler, CResult& result);
    //virtual void compileDestructorBody(Compiler* compiler, CResult& result, Function* function);
    virtual void dumpBody(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    //shared_ptr<ReturnValue> cast(Compiler* compiler, CResult& result, IRBuilder<>* builder, shared_ptr<ReturnValue> fromValue, bool isHeap, shared_ptr<CInterface> interface);
    virtual string getCInitFunctionName();
    virtual string getCDestroyFunctionName();
    string getCAsInterfaceFunctionName();

    CLoc loc;
    CFunctionType type;
    vector<shared_ptr<CType>> templateTypes;
    map<string, shared_ptr<CType>> templateTypesByName;
    shared_ptr<vector<shared_ptr<CInterface>>> interfaces;
    map<string, shared_ptr<CVar>> localVarsByName;

private:
    size_t indexRefCount;
    size_t indexParent;
    size_t indexVars;
    bool isInGetType;
    bool isInGetFunction;
    bool returnMustRelease;
    //Function* function;
    //Function* destructorFunction;
    //llvm::StructType* _structType;
    shared_ptr<CType> returnType;
    shared_ptr<CType> thisType;
    shared_ptr<CVar> thisVar;
    //shared_ptr<vector<Type*>> typeList;
    //map<Function*, Value*> parentPointers;
    //map<Function*, Value*> parentValues;
    //map<Function*, map<Value*, map<int, Value*>>> argumentPointers;
    vector<shared_ptr<NFunction>> functions;
    shared_ptr<NBase> block;
    shared_ptr<NBase> catchBlock;
    shared_ptr<NBase> destroyBlock;
    shared_ptr<CTypeName> returnTypeName;
    string externName;
    shared_ptr<CTypeNameList> interfaceTypeNames;
    vector<shared_ptr<CVar>> thisVars;
    map<string, pair<int, shared_ptr<CVar>>> thisVarsByName;
    shared_ptr<CInterfaceMethod> interfaceMethod;
    shared_ptr<CFunctionReturnVar> functionReturnVar;
    shared_ptr<vector<pair<string, shared_ptr<CType>>>> ctypeList;
    shared_ptr<CVar> _thisVar;
};

class CFunctionDefinition : public CBaseFunctionDefinition, public enable_shared_from_this<CFunctionDefinition> {
public:
    CFunctionType type;
    shared_ptr<vector<pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>>> interfaceDefinitions;
    shared_ptr<NFunction> node;
    map<string, shared_ptr<CFunctionDefinition>> funcsByName;
    map<string, shared_ptr<CInterfaceDefinition>> interfacesByName;
    
    static shared_ptr<CFunctionDefinition> create(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> parent, CFunctionType type, const string& name, shared_ptr<vector<pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>>> interfaceDefinitions, shared_ptr<NFunction> node);
    string fullName();
    void addChildFunction(string& name, shared_ptr<CBaseFunctionDefinition> childFunction);
    void dump(Compiler* compiler, CResult& result, int level);
    shared_ptr<CFunction> getFunction(Compiler* compiler, CResult& result, CLoc& loc, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CFunction> funcParent);
    
private:
    map<vector<shared_ptr<CType>>, shared_ptr<CFunction>> cfunctions;
};

#endif /* NFunction_h */
