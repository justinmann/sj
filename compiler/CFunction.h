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

class CTypeName;

enum CTypeImmutability {
    CTM_Undefined,
    CTM_Mutable,
    CTM_Immutable,
};

enum CTypeCategory {
    CTC_Value,
    CTC_Interface,
    CTC_Function
};

class CTypeNameList : public vector<shared_ptr<CTypeName>> {
public:
    CTypeNameList() { }
    CTypeNameList(CTypeCategory category, const string& name);
};

class CTypeName {
public:
    CTypeCategory category;
    CTypeImmutability mutability;
    string name;
    shared_ptr<CTypeNameList> templateTypeNames;
    shared_ptr<CTypeNameList> argTypeNames;
    shared_ptr<CTypeName> returnTypeName;

    CTypeName(CTypeCategory category, const string& name) : category(category), mutability(CTM_Undefined), name(name) { }
    CTypeName(CTypeCategory category, const string& name, shared_ptr<CTypeNameList> templateTypeNames) : category(category), mutability(CTM_Undefined), name(name), templateTypeNames(templateTypeNames) { }
    CTypeName(shared_ptr<CTypeNameList> argTypeNames, shared_ptr<CTypeName> returnTypeName) : category(CTC_Function), mutability(CTM_Undefined), argTypeNames(argTypeNames), returnTypeName(returnTypeName) { }
    
    string getName();
};

enum CFunctionType {
    FT_Private,
    FT_Public,
    FT_Extern
};

class CFunctionDefinition;

class CFunction : public enable_shared_from_this<CFunction> {
public:
    static shared_ptr<CFunction> create(Compiler* compiler, CResult& result, const CLoc& loc, weak_ptr<CFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CFunction> parent, CFunctionType type, const string& name, shared_ptr<NFunction> node);
    void createThisVar(Compiler* compiler, CResult& result, shared_ptr<CVar>& thisVar);
    shared_ptr<CFunction> getCFunction(Compiler* compiler, CResult& result, const CLoc& loc, const string& name, shared_ptr<CFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames);
    shared_ptr<CVar> getCVar(Compiler* compiler, CResult& result, const CLoc& loc, const string& name);
    shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    shared_ptr<CVar> getReturnVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    bool getHasThis();
    int getThisIndex(const string& name) const;
    shared_ptr<CType> getThisType(Compiler* compiler, CResult& result);
    shared_ptr<vector<Type*>> getTypeList(Compiler* compiler, CResult& result);
    Type* getStructType(Compiler* compiler, CResult& result);
    Function* getFunction(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar);
    Function* getDestructor(Compiler* compiler, CResult& result);
    bool getReturnMustRelease(Compiler* compiler, CResult& result);
    Value* getThisArgument(Compiler* compiler, CResult& result);
    void localVarToThisVar(Compiler* compiler, shared_ptr<CNormalVar> cvar);
    int getArgStart(Compiler* compiler, CResult& result);
    bool getHasParent(Compiler* compiler, CResult& result);
    void setHasParent(Compiler* compiler, CResult& result);
    void onHasParent(std::function<void(Compiler*, CResult&)> notify);
    Value* getArgumentPointer(Compiler* compiler, CResult& result, bool thisInEntry, Value* thisValue, int index, IRBuilder<>* builder);
    Value* getParentPointer(Compiler* compiler, CResult& result, IRBuilder<>* builder, bool thisInEntry, Value* thisValue);
    Value* getParentValue(Compiler* compiler, CResult& result, IRBuilder<>* builder, bool thisInEntry, Value* thisValue);
    string fullName(bool includeTemplateTypes);
    shared_ptr<CType> getVarType(Compiler* compiler, CResult& result, const CLoc& loc, shared_ptr<CTypeName> typeName);
    
    Value* getRefCount(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue);
    void setHasRefCount();

    void initStack(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue);
    void initHeap(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue);
    void retainStack(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue);
    void retainHeap(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue);
    void releaseStack(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue);
    void releaseHeap(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue);

    CFunctionType type;
    string name;
    weak_ptr<CFunction> parent;
    weak_ptr<CFunctionDefinition> definition;
    vector<shared_ptr<CType>> templateTypes;
    map<string, shared_ptr<CType>> templateTypesByName;
    shared_ptr<NFunction> node;
    vector<shared_ptr<CVar>> thisVars;
    map<string, pair<int, shared_ptr<CVar>>> thisVarsByName;
    map<string, shared_ptr<CVar>> localVarsByName;

private:
    bool hasRefCount;
    size_t indexRefCount;
    bool hasParent;
    size_t indexParent;
    size_t indexVars;
    bool isInGetType;
    bool isInGetFunction;
    bool returnMustRelease;
    Function* function;
    Function* destructorFunction;
    llvm::StructType* _structType;
    shared_ptr<CType> returnType;
    shared_ptr<CType> thisType;
    shared_ptr<CVar> thisVar;
    shared_ptr<vector<Type*>> typeList;
    vector<std::function<void(Compiler*, CResult&)>> delegateHasParent;
    map<Function*, Value*> parentPointers;
    map<Function*, Value*> parentValues;
    map<Function*, map<Value*, map<int, Value*>>> argumentPointers;
};

class CFunctionDefinition : public enable_shared_from_this<CFunctionDefinition> {
public:
    CFunctionType type;
    string name;
    shared_ptr<NFunction> node;
    weak_ptr<CFunctionDefinition> parent;
    map<string, shared_ptr<CFunctionDefinition>> funcsByName;
    
    static shared_ptr<CFunctionDefinition> create(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> parent, CFunctionType type, const string& name, shared_ptr<NFunction> node);
    string fullName();
    void dump(Compiler* compiler, CResult& result, int level);
    shared_ptr<CFunction> getFunction(Compiler* compiler, CResult& result, const CLoc& loc, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CFunction> funcParent);
    
private:
    map<vector<shared_ptr<CType>>, shared_ptr<CFunction>> cfunctions;
};

#endif /* CFunction_h */
