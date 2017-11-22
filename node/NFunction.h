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
    NFunction(CLoc loc, CFunctionType type, shared_ptr<CTypeName> returnTypeName, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<CTypeNameList> interfaceTypeNames, shared_ptr<NodeList> arguments, shared_ptr<NBase> block, shared_ptr<NBase> catchBlock, shared_ptr<NBase> copyBlock, shared_ptr<NBase> destroyBlock);
    shared_ptr<CFunctionDefinition> getFunctionDefinition(Compiler *compiler, shared_ptr<CFunctionDefinition> parentFunction);
    void defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> parentFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CFunction> createCFunction(Compiler* compiler, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, CFunctionType type, const string& name, shared_ptr<vector<shared_ptr<CInterface>>> interfaces);
    shared_ptr<NFunction> shared_from_this() { return static_pointer_cast<NFunction>(NBase::shared_from_this()); };
    
    string name;

private:    
    CFunctionType type;
    shared_ptr<CTypeName> returnTypeName;
    shared_ptr<CTypeNameList> templateTypeNames;
    shared_ptr<CTypeNameList> interfaceTypeNames;
    NodeList invalid;
    vector<shared_ptr<NAssignment>> assignments;
    vector<shared_ptr<NFunction>> functions;
    vector<shared_ptr<NInterface>> interfaces;
    shared_ptr<NBase> block;
    shared_ptr<NBase> copyBlock;
    shared_ptr<NBase> catchBlock;
    shared_ptr<NBase> destroyBlock;
    bool isAnonymous;

    friend class CFunctionDefinition;
    friend class CFunction;
};

class CInterfaceMethod;

class CFunctionData {
public:
    map<string, shared_ptr<CVar>> localVarsByName;
    CTypeMode returnMode;
    shared_ptr<CType> returnType;
    vector<shared_ptr<CVar>> thisArgVars;
    map<string, pair<int, shared_ptr<CVar>>> thisArgVarsByName;
    shared_ptr<vector<pair<string, shared_ptr<CType>>>> ctypeList;
    shared_ptr<CThisVar> thisVar;
};

class CScope {
public:
    CScope(shared_ptr<CFunction> function, shared_ptr<CThisVar> thisVar, CTypeMode returnMode) : function(function), thisVar(thisVar), returnMode(returnMode) {}
    shared_ptr<CVar> findLocalVar(Compiler* compiler, string name);
    void addOrUpdateLocalVar(Compiler* compiler, string name, shared_ptr<CVar> var);
    void pushLocalVar(Compiler* compiler, CLoc loc, shared_ptr<CVar> var);
    void popLocalVar(Compiler* compiler, shared_ptr<CVar> var);
    shared_ptr<CType> getVarType(CLoc loc, Compiler* compiler, shared_ptr<CTypeName> typeName, CTypeMode defaultMode);
    shared_ptr<CVar> getCVar(Compiler* compiler, const string& name);
    static shared_ptr<CScope> getScopeForType(shared_ptr<CType> type);
    shared_ptr<CScope> getParentScope();
    
    shared_ptr<CThisVar> thisVar;
    shared_ptr<CFunction> function;

private:
    CTypeMode returnMode;
};

class CFunction : public CBaseFunction, public enable_shared_from_this<CFunction> {
public:
    CFunction(weak_ptr<CBaseFunctionDefinition> definition, CFunctionType type, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces);
    shared_ptr<CFunction> init(Compiler* compiler, shared_ptr<NFunction> node);
    
    int getThisIndex(const string& name) const;
    shared_ptr<CThisVar> getThisVar(Compiler* compiler, CTypeMode returnMode);
    shared_ptr<CBaseFunction> getCFunction(Compiler* compiler, const string& name, shared_ptr<CScope> callerScope, shared_ptr<CTypeNameList> templateTypeNames);
    shared_ptr<CInterface> getCInterface(Compiler* compiler, const string& name, shared_ptr<CScope> callerScope, shared_ptr<CTypeNameList> templateTypeNames, CTypeMode returnMode);
    shared_ptr<CVar> getCVar(Compiler* compiler, const string& name, CTypeMode returnMode);
    shared_ptr<CType> getReturnType(Compiler* compiler, CTypeMode returnMode);
    shared_ptr<vector<shared_ptr<CVar>>> getArgVars(Compiler* compiler, CTypeMode returnMode);
    shared_ptr<CTypes> getThisTypes(Compiler* compiler);
    shared_ptr<vector<pair<string, shared_ptr<CType>>>> getCTypeList(Compiler* compiler, CTypeMode returnMode);
    string fullName(bool includeTemplateTypes);
    string getCFullName(bool includeTemplateTypes);
    pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>> getFunctionDefinition(string name);
    shared_ptr<CType> getVarType(Compiler* compiler, string name);
    shared_ptr<CType> getVarType(CLoc loc, Compiler* compiler, shared_ptr<CTypeName> typeName, CTypeMode defaultMode);
    void transpileDefinition(Compiler* compiler, TrOutput* trOutput);
    void transpile(Compiler* compiler, shared_ptr<CScope> callerScope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> parentValue, CLoc& calleeLoc, vector<pair<bool, shared_ptr<NBase>>>& parameters, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue, CTypeMode returnMode);
    void dumpBody(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level, CTypeMode returnMode);
    string getCBaseName(CTypeMode typeMode);
    string getCStructName(CTypeMode typeMode);
    string getCInitFunctionName(CTypeMode returnMode);
    string getCCopyFunctionName();
    string getCDestroyFunctionName();
    string getCAsInterfaceFunctionName(CTypeMode returnMode);

    CLoc loc;
    CFunctionType type;
    vector<shared_ptr<CType>> templateTypes;
    map<string, shared_ptr<CType>> templateTypesByName;
    shared_ptr<vector<shared_ptr<CInterface>>> interfaces;

private:
    bool _isInGetType;
    vector<shared_ptr<NFunction>> _functions;
    shared_ptr<NBase> _block;
    shared_ptr<NBase> _catchBlock;
    shared_ptr<NBase> _copyBlock;
    shared_ptr<NBase> _destroyBlock;
    shared_ptr<CTypeName> _returnTypeName;
    shared_ptr<CTypeNameList> _interfaceTypeNames;
    bool _hasInitializedInterfaces;
    bool _isReturnThis;
    shared_ptr<CTypes> _thisTypes;
    map<CTypeMode, CFunctionData> _data;
    
    friend class CScope;
};

class CFunctionDefinition : public CBaseFunctionDefinition, public enable_shared_from_this<CFunctionDefinition> {
public:
    CLoc loc;
    CFunctionType type;
    shared_ptr<NFunction> node;
    map<string, shared_ptr<CFunctionDefinition>> funcsByName;
    shared_ptr<CTypeNameList> implementedInterfaceTypeNames;
    
    CFunctionDefinition() : CBaseFunctionDefinition(CFT_Function) {}
    static shared_ptr<CFunctionDefinition> create(Compiler* compiler, shared_ptr<CFunctionDefinition> parent, CFunctionType type, const string& name, shared_ptr<CTypeNameList> implementedInterfaceTypeNames, shared_ptr<NFunction> node);
    string fullName();
    void addChildFunction(string& name, shared_ptr<CBaseFunctionDefinition> childFunction);
    void dump(Compiler* compiler, int level);
    shared_ptr<CFunction> getFunction(Compiler* compiler, CLoc loc, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CFunction> funcParent);
    shared_ptr<CInterfaceDefinition> getDefinedInterfaceDefinition(const string& name);
    shared_ptr<CInterfaceDefinition> createDefinedInterfaceDefinition(CLoc loc, string& name);
    shared_ptr<vector<pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>>> getImplementedInterfaceDefintions(Compiler* compiler);
    
private:
    map<CFunction*, map<vector<shared_ptr<CType>>, shared_ptr<CFunction>>> _cfunctions;
    map<string, shared_ptr<CInterfaceDefinition>> _definedInterfaceDefinitions;
    shared_ptr<vector<pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>>> _implementedInterfaceDefinitions;
};

#endif /* NFunction_h */
