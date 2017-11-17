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
    FT_Public
};

class CFunctionDefinition;
class CInterfaceMethod;
class NInterface;
class CFunction;
class CThisVar;

class NFunction : public NBaseFunction {
public:
    NFunction(CLoc loc, CFunctionType type, shared_ptr<CTypeName> returnTypeName, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<CTypeNameList> interfaceTypeNames, shared_ptr<NodeList> arguments, shared_ptr<NBase> block, shared_ptr<NBase> catchBlock, shared_ptr<NBase> destroyBlock);
    shared_ptr<CFunctionDefinition> getFunctionDefinition(Compiler *compiler, CResult& result, shared_ptr<CFunctionDefinition> parentFunction);
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> parentFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar);
    shared_ptr<CFunction> createCFunction(Compiler* compiler, CResult& result, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, CFunctionType type, const string& name, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, shared_ptr<CInterfaceMethod> interfaceMethod);
    shared_ptr<NFunction> shared_from_this() { return static_pointer_cast<NFunction>(NBase::shared_from_this()); };
    
private:    
    CFunctionType type;
    shared_ptr<CTypeName> returnTypeName;
    string name;
    shared_ptr<CTypeNameList> templateTypeNames;
    shared_ptr<CTypeNameList> interfaceTypeNames;
    NodeList invalid;
    vector<shared_ptr<NAssignment>> assignments;
    vector<shared_ptr<NFunction>> functions;
    vector<shared_ptr<NInterface>> interfaces;
    shared_ptr<NBase> block;
    shared_ptr<NBase> catchBlock;
    shared_ptr<NBase> destroyBlock;

    friend class CFunctionDefinition;
    friend class CFunction;
};

class CInterfaceMethod;

class CFunction : public CBaseFunction, public enable_shared_from_this<CFunction> {
public:
    CFunction(weak_ptr<CBaseFunctionDefinition> definition, CFunctionType type, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces);
    shared_ptr<CFunction> init(Compiler* compiler, CResult& result, shared_ptr<NFunction> node, shared_ptr<CInterfaceMethod> interfaceMethod);
    
    shared_ptr<CThisVar> getThisVar(Compiler* compiler, CResult& result, CTypeMode typeMode);
    shared_ptr<CFunction> getCFunction(Compiler* compiler, CResult& result, const string& name, shared_ptr<CFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames);
    shared_ptr<CInterface> getCInterface(Compiler* compiler, CResult& result, const string& name, shared_ptr<CFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames);
    shared_ptr<CVar> getCVar(Compiler* compiler, CResult& result, const string& name);
    shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, CTypeReturnMode returnMode);
    shared_ptr<vector<shared_ptr<CVar>>> getArgVars(Compiler* compiler, CResult& result, shared_ptr<CThisVar> thisVar);
    bool getHasThis();
    int getThisIndex(const string& name) const;
    shared_ptr<CTypes> getThisTypes(Compiler* compiler, CResult& result);
    shared_ptr<vector<pair<string, shared_ptr<CType>>>> getCTypeList(Compiler* compiler, CResult& result);
    void localVarToThisVar(Compiler* compiler, shared_ptr<CNormalVar> cvar);
    int getArgStart(Compiler* compiler, CResult& result);
    string fullName(bool includeTemplateTypes);
    string getCFullName(bool includeTemplateTypes);
    pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>> getFunctionDefinition(string name);
    shared_ptr<CType> getVarType(Compiler* compiler, CResult& result, string name);
    shared_ptr<CType> getVarType(Compiler* compiler, CResult& result, shared_ptr<CTypeName> typeName);
    pair<shared_ptr<CVar>, shared_ptr<CThisVar>> getReturnVars(Compiler* compiler, CResult& result, CTypeReturnMode returnMode);
    void getVarBody(Compiler *compiler, CResult& result, shared_ptr<CThisVar> thisVar, CTypeReturnMode returnMode);
    void transpileDefinition(Compiler* compiler, CResult& result, TrOutput* trOutput, CTypeMode typeMode);
    shared_ptr<ReturnValue> transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> calleeValue, CLoc& calleeLoc, vector<pair<bool, shared_ptr<NBase>>>& parameters, const char* thisName, CTypeMode typeMode);
    void dumpBody(Compiler* compiler, CResult& result, shared_ptr<CThisVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    string getBaseName(CTypeMode typeMode);
    string getStructName(CTypeMode typeMode);
    string getCInitFunctionName(CTypeMode typeMode);
    string getCDestroyFunctionName(CTypeMode typeMode);
    string getCAsInterfaceFunctionName(CTypeMode typeMode);

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
    bool returnMustRelease;
    shared_ptr<CType> returnType;
    shared_ptr<CTypes> thisTypes;
    shared_ptr<CVar> thisStackVar;
    shared_ptr<CVar> thisHeapVar;
    vector<shared_ptr<NFunction>> functions;
    shared_ptr<NBase> block;
    shared_ptr<NBase> catchBlock;
    shared_ptr<NBase> destroyBlock;
    shared_ptr<CTypeName> returnTypeName;
    shared_ptr<CTypeNameList> interfaceTypeNames;
    vector<shared_ptr<CVar>> thisVars;
    map<string, pair<int, shared_ptr<CVar>>> thisVarsByName;
    shared_ptr<CInterfaceMethod> interfaceMethod;
    shared_ptr<vector<pair<string, shared_ptr<CType>>>> ctypeList;
    bool _hasInitializedInterfaces;
    map<CTypeMode, shared_ptr<CThisVar>> _thisVar;
};

class CFunctionDefinition : public CBaseFunctionDefinition, public enable_shared_from_this<CFunctionDefinition> {
public:
    CLoc loc;
    CFunctionType type;
    shared_ptr<NFunction> node;
    map<string, shared_ptr<CFunctionDefinition>> funcsByName;
    shared_ptr<CTypeNameList> implementedInterfaceTypeNames;
    
    CFunctionDefinition() : CBaseFunctionDefinition(CFT_Function) {}
    static shared_ptr<CFunctionDefinition> create(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> parent, CFunctionType type, const string& name, shared_ptr<CTypeNameList> implementedInterfaceTypeNames, shared_ptr<NFunction> node);
    string fullName();
    void addChildFunction(string& name, shared_ptr<CBaseFunctionDefinition> childFunction);
    void dump(Compiler* compiler, CResult& result, int level);
    shared_ptr<CFunction> getFunction(Compiler* compiler, CResult& result, CLoc& loc, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CFunction> funcParent);
    shared_ptr<CInterfaceDefinition> getDefinedInterfaceDefinition(const string& name);
    shared_ptr<CInterfaceDefinition> createDefinedInterfaceDefinition(string& name);
    shared_ptr<vector<pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>>> getImplementedInterfaceDefintions(Compiler* compiler, CResult& result);
    
private:
    map<CFunction*, map<vector<shared_ptr<CType>>, shared_ptr<CFunction>>> _cfunctions;
    map<string, shared_ptr<CInterfaceDefinition>> _definedInterfaceDefinitions;
    shared_ptr<vector<pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>>> _implementedInterfaceDefinitions;
};

#endif /* NFunction_h */
