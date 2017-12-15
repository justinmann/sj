#pragma once

#include "Node.h"

class CCallbackVar : public CVar {
public:
    CCallbackVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type, shared_ptr<CVar> dotVar, shared_ptr<CCallback> callback, shared_ptr<CBaseFunction> function, CTypeMode returnMode);
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);

private:
    shared_ptr<CType> type;
    shared_ptr<CVar> dotVar;
    shared_ptr<CCallback> callback;
    shared_ptr<CBaseFunction> function;
    CTypeMode returnMode;
}; 

class CCallbackFunction : public CBaseFunction {
public:
    CCallbackFunction(shared_ptr<CCallback> callback, shared_ptr<CVar> callbackVar);
    int getArgIndex(const string& name, CTypeMode returnMode);
    int getArgCount(CTypeMode returnMode);
    shared_ptr<CVar> getArgVar(int index, CTypeMode returnMode);
    string fullName(bool includeTemplateTypes);
    shared_ptr<CTypes> getThisTypes(Compiler* compiler);
    shared_ptr<CVar> getCVar(Compiler* compiler, vector<shared_ptr<LocalVarScope>> localVarScopes, const string& name, VarScanMode scanMode, CTypeMode returnMode);
    shared_ptr<CBaseFunction> getCFunction(Compiler* compiler, CLoc locCaller, const string& name, shared_ptr<CScope> callerScope, shared_ptr<CTypeNameList> templateTypeNames, CTypeMode returnMode);
    shared_ptr<CType> getVarType(CLoc loc, Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, shared_ptr<CTypeName> typeName, CTypeMode defaultMode);
    string getCFunctionName(CTypeMode returnMode);
    string getCCallbackFunctionName(Compiler* compiler, TrOutput* trOutput, CTypeMode returnMode);
    string getCCopyFunctionName();
    string getCDestroyFunctionName();
    string getCStructName(CTypeMode typeMode);
    pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>> getFunctionDefinition(vector<string> packageNamespace, string name);
    bool getIsReturnModeValid(Compiler* compiler, CTypeMode returnMode);
    shared_ptr<CType> getReturnType(Compiler* compiler, CTypeMode returnMode);
    void transpileDefinition(Compiler* compiler, TrOutput* trOutput);
    void transpile(Compiler* compiler, shared_ptr<CScope> callerScope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<CVar> parentVar, CLoc& calleeLoc, shared_ptr<vector<FunctionParameter>> parameters, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue, CTypeMode returnMode);
    void dumpBody(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level, CTypeMode returnMode);

private:
    shared_ptr<CCallback> callback;
    shared_ptr<CVar> callbackVar;
    vector<shared_ptr<CVar>> argVars;
};

class CCallback : public enable_shared_from_this<CCallback> {
public:
    CCallback(vector<shared_ptr<CType>> argTypes, shared_ptr<CType> stackReturnType, shared_ptr<CType> heapReturnType);
    static shared_ptr<CCallback> getCallback(vector<shared_ptr<CType>> argTypes, shared_ptr<CType> stackReturnType, shared_ptr<CType> heapReturnType);
    static shared_ptr<CType> getType(vector<shared_ptr<CType>> argTypes, shared_ptr<CType> stackReturnType, shared_ptr<CType> heapReturnType, CTypeMode returnMode, bool isOption);
    static shared_ptr<CVar> getVar(Compiler* compiler, shared_ptr<CScope> scope, CLoc loc, shared_ptr<CVar> dotVar, shared_ptr<CBaseFunction> function, CTypeMode returnMode);
    shared_ptr<CBaseFunction> getFunction(Compiler* compiler, shared_ptr<CVar> callbackVar);
    void transpileDefinition(Compiler* compiler, TrOutput* trOutput);
    string getCBName(Compiler* compiler, bool includeNames, CTypeMode returnMode);
    string getCName(CTypeMode typeMode, bool isOption);
    void writeCopy(TrBlock* trBlock, string from, string to, bool refCount);

    shared_ptr<CTypes> types;
    vector<shared_ptr<CType>> argTypes;
    shared_ptr<CType> stackReturnType;
    shared_ptr<CType> heapReturnType;

private:
    static map<vector<shared_ptr<CType>>, shared_ptr<CCallback>> _callbacks;
};