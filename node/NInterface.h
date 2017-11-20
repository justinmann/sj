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
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode) { return nullptr; }

private:
    shared_ptr<NInterface> shared_from_this();
};

class CInterfaceMethod;

class CInterfaceVar : public CVar {
public:
    CInterfaceVar(CLoc loc, shared_ptr<CBaseFunction> scope, shared_ptr<CInterface> interface);
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    void transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
};

class CInterface : public CBaseFunction, public enable_shared_from_this<CInterface> {
public:
    vector<shared_ptr<CInterfaceMethod>> methods;
    map<string, shared_ptr<CInterfaceMethod>> methodByName;
    map<string, shared_ptr<CType>> templateTypesByName;
    
    CInterface(CLoc loc, weak_ptr<CInterfaceDefinition> definition, weak_ptr<CFunction> parent, CTypeMode returnMode);
    shared_ptr<CInterface> init(Compiler* compiler, CResult& result, shared_ptr<NInterface> node, vector<shared_ptr<CType>>& templateTypes);
    string fullName(bool includeTemplateTypes);
    
    shared_ptr<CTypes> getThisTypes(Compiler* compiler, CResult& result);
    int getThisIndex(const string& name) const;
    shared_ptr<CVar> getThisVar(Compiler* compiler, CResult& result);
    int getArgStart();

    shared_ptr<CVar> getCVar(Compiler* compiler, CResult& result, const string& name);
    shared_ptr<CBaseFunction> getCFunction(Compiler* compiler, CResult& result, const string& name, shared_ptr<CBaseFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames, CTypeMode returnMode);
    pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>> getFunctionDefinition(string name) { assert(false); return make_pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>>(nullptr, nullptr); }
    shared_ptr<CType> getVarType(Compiler* compiler, CResult& result, shared_ptr<CTypeName> typeName);
    shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result);
    string getCInitFunctionName();
    string getCCopyFunctionName();
    string getCDestroyFunctionName();
    string getCCastFunctionName(CTypeMode toTypeMode, shared_ptr<CBaseFunction> fromFunction);
    string getCBaseName(CTypeMode typeMode);
    string getCStructName(CTypeMode typeMode);
    string getCTypeIdName();
    void transpileCast(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> fromValue, shared_ptr<TrStoreValue> toValue);

    void transpileDefinition(Compiler* compiler, CResult& result, TrOutput* trOutput);
    void transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> parentValue, CLoc& calleeLoc, vector<pair<bool, shared_ptr<NBase>>>& parameters, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dumpBody(Compiler* compiler, CResult& result, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    bool getReturnMustRelease(Compiler* compiler, CResult& result);

private:
    CLoc loc;
    shared_ptr<CTypes> thisTypes;
    CTypeMode _returnMode;
};

class CInterfaceDefinition : public CBaseFunctionDefinition, public enable_shared_from_this<CInterfaceDefinition> {
public:
    CLoc loc;
    shared_ptr<CTypeName> typeName;
    shared_ptr<NInterface> ninterface;

    CInterfaceDefinition(CLoc loc, string& name);
    string fullName();
    void addChildFunction(string& name, shared_ptr<CBaseFunctionDefinition> childFunction);
    shared_ptr<CInterface> getInterface(Compiler* compiler, CResult& result, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CFunction> funcParent, CTypeMode returnMode);
    
private:
    map<vector<shared_ptr<CType>>, shared_ptr<CInterface>> cinterfaces;
    vector<shared_ptr<CBaseFunctionDefinition>> methods;
};

#endif /* NInterface_h */
