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

class TemplateTypeNames : public vector<pair<string, shared_ptr<TemplateTypeNames>>> {
public:
    TemplateTypeNames() : vector<pair<string, shared_ptr<TemplateTypeNames>>>() {
        
    }
    
    TemplateTypeNames(const string& name) : vector<pair<string, shared_ptr<TemplateTypeNames>>>() {
        push_back(pair<string, shared_ptr<TemplateTypeNames>>(name, nullptr));
    }
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
    shared_ptr<CFunction> getCFunction(Compiler* compiler, CResult& result, const CLoc& loc, const string& name, shared_ptr<CFunction> callerFunction, shared_ptr<TemplateTypeNames> templateTypeNames);
    shared_ptr<CVar> getCVar(Compiler* compiler, CResult& result, const CLoc& loc, const string& name);
    shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result);
    shared_ptr<CVar> getReturnVar(Compiler* compiler, CResult& result);
    int getThisIndex(const string& name) const;
    shared_ptr<CType> getThisType(Compiler* compiler, CResult& result);
    Type* getStructType(Compiler* compiler, CResult& result);
    Function* getFunction(Compiler* compiler, CResult& result);
    Value* getThisArgument(Compiler* compiler, CResult& result);
    void localVarToThisVar(Compiler* compiler, shared_ptr<CNormalVar> cvar);
    int getArgStart(Compiler* compiler, CResult& result);
    bool getHasParent(Compiler* compiler, CResult& result);
    Value* getArgumentPointer(Compiler* compiler, CResult& result, Value* thisValue, int index, IRBuilder<>* builder);
    Value* getParentPointer(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue);
    string fullName();
    shared_ptr<CType> getVarType(Compiler* compiler, CResult& result, const CLoc& loc, const string& name, shared_ptr<TemplateTypeNames> subTypeNames);
    Value* getDefaultValue(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB);
    shared_ptr<CVar> getThisVar();

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
    bool hasParent;
    bool isInGetType;
    bool isInGetFunction;
    Function* function;
    llvm::StructType* _structType;
    shared_ptr<CType> returnType;
    shared_ptr<CType> thisType;
    shared_ptr<CVar> thisVar;
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
