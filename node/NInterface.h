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
    void defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) { return nullptr; }

private:
    shared_ptr<NInterface> shared_from_this();
};

class CInterfaceMethod;

class CInterfaceVar : public CVar {
public:
    CInterfaceVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CInterface> interface);
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
};

class CInterface : public CBaseFunction, public enable_shared_from_this<CInterface> {
public:
    vector<shared_ptr<CInterfaceMethod>> methods;
    map<string, map<CTypeMode, shared_ptr<CInterfaceMethod>>> methodByName;
    map<string, shared_ptr<CType>> templateTypesByName;
    
    CInterface(CLoc loc, weak_ptr<CInterfaceDefinition> definition, weak_ptr<CFunction> parent);
    shared_ptr<CInterface> init(Compiler* compiler, shared_ptr<NInterface> node, vector<shared_ptr<CType>>& templateTypes);
    string fullName(bool includeTemplateTypes);
    
    shared_ptr<CTypes> getThisTypes(Compiler* compiler);
    int getThisIndex(const string& name) const;
    shared_ptr<CVar> getThisVar(Compiler* compiler);
    int getArgStart();

    shared_ptr<CScope> getScope();
    shared_ptr<CVar> getCVar(Compiler* compiler, const string& name, CTypeMode returnMode);
    shared_ptr<CBaseFunction> getCFunction(Compiler* compiler, const string& name, shared_ptr<CScope> callerFunction, shared_ptr<CTypeNameList> templateTypeNames);
    pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>> getFunctionDefinition(string name) { assert(false); return make_pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>>(nullptr, nullptr); }
    shared_ptr<CType> getVarType(CLoc loc, Compiler* compiler, shared_ptr<CTypeName> typeName, CTypeMode defaultMode);
    shared_ptr<CType> getReturnType(Compiler* compiler, CTypeMode returnMode);
    string getCInitFunctionName(CTypeMode returnMode);
    string getCCopyFunctionName();
    string getCDestroyFunctionName();
    string getCCastFunctionName(shared_ptr<CBaseFunction> fromFunction, CTypeMode returnMode);
    string getCBaseName(CTypeMode typeMode);
    string getCStructName(CTypeMode typeMode);
    string getCTypeIdName();
    void transpileCast(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> fromValue, shared_ptr<TrStoreValue> toValue);

    void transpileDefinition(Compiler* compiler, TrOutput* trOutput);
    void transpile(Compiler* compiler, shared_ptr<CScope> callerScope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> parentValue, CLoc& calleeLoc, vector<pair<bool, shared_ptr<NBase>>>& parameters, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue, CTypeMode returnMode);
    void dumpBody(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level, CTypeMode returnMode);
    bool getReturnMustRelease(Compiler* compiler);

private:
    CLoc loc;
    shared_ptr<CTypes> thisTypes;
};

class CInterfaceDefinition : public CBaseFunctionDefinition, public enable_shared_from_this<CInterfaceDefinition> {
public:
    CLoc loc;
    shared_ptr<CTypeName> typeName;
    shared_ptr<NInterface> ninterface;

    CInterfaceDefinition(CLoc loc, string& name);
    string fullName();
    void addChildFunction(string& name, shared_ptr<CBaseFunctionDefinition> childFunction);
    shared_ptr<CInterface> getInterface(Compiler* compiler, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CFunction> funcParent);
    
private:
    map<vector<shared_ptr<CType>>, shared_ptr<CInterface>> cinterfaces;
    vector<shared_ptr<CBaseFunctionDefinition>> methods;
};

#endif /* NInterface_h */
