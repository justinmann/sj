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

class CFunctionName {
public:
    CFunctionName(string name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<vector<string>> attributes) : name(name), templateTypeNames(templateTypeNames), attributes(attributes) {}

    string name;
    shared_ptr<CTypeNameList> templateTypeNames;
    shared_ptr<vector<string>> attributes;
};

class CFunctionDefinition;
class CInterfaceMethod;
class NInterface;
class CFunction;
class CThisVar;

class NFunction : public NBaseFunction {
public:
    NFunction(CLoc loc, CFunctionType type, shared_ptr<CTypeName> returnTypeName, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<vector<string>> attributes, shared_ptr<CTypeNameList> interfaceTypeNames, shared_ptr<NodeList> arguments, shared_ptr<NBase> block, shared_ptr<NBase> catchBlock, shared_ptr<NBase> copyBlock, shared_ptr<NBase> destroyBlock);
    shared_ptr<CFunctionDefinition> getFunctionDefinition(Compiler *compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string> packageNamespace, shared_ptr<CFunctionDefinition> parentFunction);
    void defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& namespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> parentFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
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
    vector<shared_ptr<NCCode>> ccodes;
    shared_ptr<NBase> block;
    shared_ptr<NBase> copyBlock;
    shared_ptr<NBase> catchBlock;
    shared_ptr<NBase> destroyBlock;
    bool isAnonymous;
    shared_ptr<vector<string>> attributes;

    friend class CFunctionDefinition;
    friend class CFunction;
};

class CInterfaceMethod;

class LocalVarScope {

};

class ImportScope {
public:
    vector<pair<string, vector<string>>> importNamespaces;
};

class CFunctionData {
public:
    CFunctionData() : isInvalid(false) {}
    
    bool isInvalid;
    shared_ptr<CScope> scope;
    map<shared_ptr<LocalVarScope>, map<vector<string>, map<string, shared_ptr<CVar>>>> localVarsByName;
    CTypeMode returnMode;
    shared_ptr<CType> returnType;
    vector<shared_ptr<CVar>> thisArgVars;
    map<string, pair<int, shared_ptr<CNormalVar>>> thisArgVarsByName;
    shared_ptr<vector<pair<string, shared_ptr<CType>>>> ctypeList;
    shared_ptr<CThisVar> thisVar;
    shared_ptr<CVar> blockVar;
    shared_ptr<CVar> catchVar;
    shared_ptr<CVar> copyVar;
    shared_ptr<CVar> destroyVar;
};

class CScope : public enable_shared_from_this<CScope> {
public:
    CScope(shared_ptr<CFunction> function, shared_ptr<CThisVar> thisVar, CTypeMode returnMode) : function(function), thisVar(thisVar), returnMode(returnMode) {}
    CScope(shared_ptr<CInterface> cinterface) : cinterface(cinterface) {}
    void addOrUpdateLocalVar(Compiler* compiler, vector<string>& packageNamespace, shared_ptr<CVar> var);
    void pushLocalVarScope(shared_ptr<LocalVarScope> localVarScope);
    void popLocalVarScope(shared_ptr<LocalVarScope> localVarScope);
    void pushImportScope(shared_ptr<ImportScope> importScope);
    void popImportScope(shared_ptr<ImportScope> importScope);
    void setLocalVar(Compiler* compiler, CLoc loc, shared_ptr<CVar> var, bool overwrite);
    shared_ptr<CType> getVarType(CLoc loc, Compiler* compiler, shared_ptr<CTypeName> typeName, CTypeMode defaultMode);
    shared_ptr<CVar> getCVar(Compiler* compiler, shared_ptr<CVar> dotVar, const string& name, VarScanMode scanMode);
    static shared_ptr<CScope> getScopeForType(Compiler* compiler, shared_ptr<CType> type);
    vector<string> getNamespace(Compiler* compiler, string name);
    void pushNamespace(Compiler* compiler, vector<string> nsChild);
    void popNamespace(Compiler* compiler, vector<string> nsChild);
    void pushUnderscore(shared_ptr<CVar> underscoreVar);
    void popUnderscore(shared_ptr<CVar> underscoreVar);
    shared_ptr<CVar> getUnderscore();
    vector<vector<string>> getImportNamespaces();
    vector<pair<string, vector<string>>> getImportNamespacesWithRenames();

    shared_ptr<CThisVar> thisVar;
    shared_ptr<CFunction> function;
    shared_ptr<CInterface> cinterface;
    vector<string> dotNamespace;
    CTypeMode returnMode;
    vector<shared_ptr<LocalVarScope>> localVarScopes;
    vector<shared_ptr<ImportScope>> importScopes;
    vector<shared_ptr<CVar>> underscoreVars;
};

enum FunctionState {
    NOTSTARTED,
    STARTED,
    DONE
};

class CFunction : public CBaseFunction, public enable_shared_from_this<CFunction> {
public:
    CFunction(vector<pair<string, vector<string>>>& importNamespaces, weak_ptr<CBaseFunctionDefinition> definition, CFunctionType type, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, vector<shared_ptr<NCCode>> ccodes, bool hasHeapThis);
    bool init(Compiler* compiler, shared_ptr<NFunction> node);
    bool initBlocks(Compiler* compiler, shared_ptr<NFunction> node);

    shared_ptr<CScope> getScope(Compiler* compiler, CTypeMode returnMode);
    int getArgIndex(const string& name, CTypeMode returnMode);
    int getArgCount(CTypeMode returnMode);
    shared_ptr<CVar> getArgVar(int index, CTypeMode returnMode);
    shared_ptr<CThisVar> getThisVar(Compiler* compiler, CTypeMode returnMode);
    shared_ptr<CBaseFunction> getCFunction(Compiler* compiler, CLoc locCaller, const string& name, shared_ptr<CScope> callerScope, shared_ptr<CTypeNameList> templateTypeNames, CTypeMode returnMode);
    shared_ptr<CInterface> getCInterface(Compiler* compiler, vector<string>& packageNamespace, const string& name, shared_ptr<CScope> callerScope, shared_ptr<CTypeNameList> templateTypeNames);
    shared_ptr<CVar> getCVar(Compiler* compiler, shared_ptr<CScope> callerScope, vector<shared_ptr<LocalVarScope>> localVarScopes, vector<string> ns, shared_ptr<CVar> dotVar, const string& name, VarScanMode scanMode, CTypeMode returnMode);
    bool getIsReturnModeValid(Compiler* compiler, CTypeMode returnMode);
    shared_ptr<CType> getReturnType(Compiler* compiler, CTypeMode returnMode);
    shared_ptr<vector<shared_ptr<CVar>>> getArgVars(Compiler* compiler, CTypeMode returnMode);
    shared_ptr<CTypes> getThisTypes(Compiler* compiler);
    shared_ptr<vector<pair<string, shared_ptr<CType>>>> getCTypeList(Compiler* compiler, CTypeMode returnMode);
    string fullName(bool includeTemplateTypes);
    string getCFullName(bool includeTemplateTypes);
    pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>> getFunctionDefinition(vector<string> packageNamespace, string name);
    shared_ptr<CType> getVarType(Compiler* compiler, string name, bool isOption);
    shared_ptr<CType> getVarType(CLoc loc, Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, shared_ptr<CTypeName> typeName, CTypeMode defaultMode);
    void transpileStructDefinition(Compiler* compiler, TrOutput* trOutput);
    void transpileDefinition(Compiler* compiler, TrOutput* trOutput);
    void transpile(Compiler* compiler, shared_ptr<CScope> callerScope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<CVar> parentVar, CLoc& calleeLoc, shared_ptr<vector<FunctionParameter>> parameters, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue, CTypeMode returnMode);
    void dumpBody(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level, CTypeMode returnMode);
    string getCBaseName(CTypeMode typeMode);
    string getCStructName(CTypeMode typeMode);
    string getCFunctionName(Compiler* compiler, TrOutput* trOutput, CTypeMode returnMode);
    string getCCallbackFunctionName(Compiler* compiler, TrOutput* trOutput, CTypeMode returnMode);
    string getCCopyFunctionName();
    string getCDestroyFunctionName();
    string getCAsInterfaceFunctionName(Compiler* compiler, TrOutput* trOutput, CTypeMode returnMode);

    CLoc loc;
    CFunctionType type;
    vector<shared_ptr<CType>> templateTypes;
    map<string, shared_ptr<CType>> templateTypesByName;
    shared_ptr<vector<shared_ptr<CInterface>>> interfaces;
    vector<shared_ptr<NCCode>> ccodes;
    bool hasHeapThis;

private:
    bool _isInGetType;
    vector<shared_ptr<NFunction>> _functions;
    shared_ptr<CTypeName> _returnTypeName;
    shared_ptr<CTypeNameList> _interfaceTypeNames;
    bool _hasInitializedInterfaces;
    FunctionState _hasTranspileDefinitions;
    FunctionState _hasTranspileStructDefinitions;
    bool _isReturnThis;
    shared_ptr<CTypes> _thisTypes;
    map<CTypeMode, CFunctionData> _data;
    vector<pair<string, vector<string>>> importNamespaces;

    friend class CScope;
};

class CFunctionDefinition : public CBaseFunctionDefinition, public enable_shared_from_this<CFunctionDefinition> {
public:
    CLoc loc;
    CFunctionType type;
    shared_ptr<NFunction> node;
    map<vector<string>, map<string, shared_ptr<CFunctionDefinition>>> funcsByName;
    shared_ptr<CTypeNameList> implementedInterfaceTypeNames;
    vector<shared_ptr<NCCode>> ccodes;
    vector<pair<string, vector<string>>> importNamespaces;
    vector<string> packageNamespace;

    CFunctionDefinition() : CBaseFunctionDefinition(CFT_Function) {}
    static shared_ptr<CFunctionDefinition> create(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, shared_ptr<CFunctionDefinition> parent, CFunctionType type, vector<string> packageNamespace, const string& name, shared_ptr<CTypeNameList> implementedInterfaceTypeNames, shared_ptr<NFunction> node);
    string fullName();
    void addChildFunction(Compiler* compiler, CLoc loc, vector<string> packageNamespace, string& name, shared_ptr<CBaseFunctionDefinition> childFunction);
    void dump(Compiler* compiler, int level);
    shared_ptr<CFunction> getFunction(Compiler* compiler, CLoc loc, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CFunction> funcParent);
    shared_ptr<CInterfaceDefinition> getDefinedInterfaceDefinition(vector<string>& packageNamespace, const string& name);
    shared_ptr<CInterfaceDefinition> createDefinedInterfaceDefinition(Compiler* compiler, CLoc loc, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, string& name);
    shared_ptr<vector<pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>>> getImplementedInterfaceDefintions(Compiler* compiler);
    
private:
    map<CFunction*, map<vector<shared_ptr<CType>>, shared_ptr<CFunction>>> _cfunctions;
    map<vector<string>, map<string, shared_ptr<CInterfaceDefinition>>> _definedInterfaceDefinitions;
    shared_ptr<vector<pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>>> _implementedInterfaceDefinitions;
};

#endif /* NFunction_h */
