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
    shared_ptr<CFunctionDefinition> getFunctionDefinition(Compiler *compiler, CResult& result, shared_ptr<CFunctionDefinition> parentFunction);
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> parentFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar);
    shared_ptr<CFunction> createCFunction(Compiler* compiler, CResult& result, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, CFunctionType type, const string& name, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, shared_ptr<CInterfaceMethod> interfaceMethod);
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

    friend class CFunctionDefinition;
    friend class CFunction;
};

class CInterfaceMethod;

class CFunction : public CBaseFunction, public enable_shared_from_this<CFunction> {
public:
    CFunction(weak_ptr<CBaseFunctionDefinition> definition, CFunctionType type, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces);
    shared_ptr<CFunction> init(Compiler* compiler, CResult& result, shared_ptr<NFunction> node, shared_ptr<CInterfaceMethod> interfaceMethod);
    
    shared_ptr<CThisVar> getThisVar(Compiler* compiler, CResult& result, CTypeMode typeMode);
    shared_ptr<CBaseFunction> getCFunction(Compiler* compiler, CResult& result, const string& name, shared_ptr<CBaseFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames);
    shared_ptr<CInterface> getCInterface(Compiler* compiler, CResult& result, const string& name, shared_ptr<CBaseFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames);
    shared_ptr<CVar> getCVar(Compiler* compiler, CResult& result, const string& name);
    shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, CTypeMode returnMode);
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
    shared_ptr<CType> getVarType(Compiler* compiler, CResult& result, shared_ptr<CTypeName> typeName, CTypeMode returnMode);
    pair<shared_ptr<CVar>, shared_ptr<CThisVar>> getReturnVars(Compiler* compiler, CResult& result, CTypeMode returnMode);
    void getVarBody(Compiler *compiler, CResult& result, shared_ptr<CThisVar> thisVar, CTypeMode returnMode);
    void transpileDefinition(Compiler* compiler, CResult& result, TrOutput* trOutput, CTypeMode typeMode);
    shared_ptr<ReturnValue> transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> calleeValue, CLoc& calleeLoc, vector<pair<bool, shared_ptr<NBase>>>& parameters, const char* thisName, CTypeMode typeMode);
    void dumpBody(Compiler* compiler, CResult& result, CTypeMode returnTypeMode, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    string getCBaseName(CTypeMode typeMode);
    string getCStructName(CTypeMode typeMode);
    string getCInitFunctionName(CTypeMode returnMode);
    string getCCopyFunctionName();
    string getCDestroyFunctionName();
    string getCAsInterfaceFunctionName(CTypeMode typeMode);

    CLoc loc;
    CFunctionType type;
    vector<shared_ptr<CType>> templateTypes;
    map<string, shared_ptr<CType>> templateTypesByName;
    shared_ptr<vector<shared_ptr<CInterface>>> interfaces;
    map<string, shared_ptr<CVar>> localVarsByName;

private:
    size_t _indexRefCount;
    size_t _indexParent;
    size_t _indexVars;
    bool _isInGetType;
    map<CTypeMode, shared_ptr<CType>> _returnType;
    shared_ptr<CTypes> _thisTypes;
    vector<shared_ptr<NFunction>> _functions;
    shared_ptr<NBase> _block;
    shared_ptr<NBase> _catchBlock;
    shared_ptr<NBase> _copyBlock;
    shared_ptr<NBase> _destroyBlock;
    shared_ptr<CTypeName> _returnTypeName;
    shared_ptr<CTypeNameList> _interfaceTypeNames;
    vector<shared_ptr<CVar>> _thisArgVars;
    map<string, pair<int, shared_ptr<CVar>>> _thisArgVarsByName;
    shared_ptr<CInterfaceMethod> _interfaceMethod;
    shared_ptr<vector<pair<string, shared_ptr<CType>>>> _ctypeList;
    bool _hasInitializedInterfaces;
    map<CTypeMode, shared_ptr<CThisVar>> _thisVar;
    bool _isReturnThis;
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
    shared_ptr<CInterfaceDefinition> createDefinedInterfaceDefinition(CLoc loc, string& name);
    shared_ptr<vector<pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>>> getImplementedInterfaceDefintions(Compiler* compiler, CResult& result);
    
private:
    map<CFunction*, map<vector<shared_ptr<CType>>, shared_ptr<CFunction>>> _cfunctions;
    map<string, shared_ptr<CInterfaceDefinition>> _definedInterfaceDefinitions;
    shared_ptr<vector<pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>>> _implementedInterfaceDefinitions;
};

#endif /* NFunction_h */
