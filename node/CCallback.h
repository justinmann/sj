#pragma once

#include "Node.h"

class CCallbackVar : public CVar {
public:
    CCallbackVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type, shared_ptr<CVar> dotVar, shared_ptr<CBaseFunction> function, shared_ptr<CCallback> callback) : CVar(loc, scope), type(type), dotVar(dotVar), function(function), callback(callback) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);

private:
    shared_ptr<CType> type;
    shared_ptr<CVar> dotVar;
    shared_ptr<CBaseFunction> function;
    shared_ptr<CCallback> callback;
}; 

class CCallbackFunction : public CBaseFunction {
public:
    CCallbackFunction(shared_ptr<CCallback> callback, shared_ptr<CVar> callbackVar);
    int getArgIndex(const string& name, CTypeMode returnMode);
    int getArgCount(CTypeMode returnMode);
    shared_ptr<CVar> getArgVar(int index, CTypeMode returnMode);
    string fullName(bool includeTemplateTypes);
    shared_ptr<CTypes> getThisTypes(Compiler* compiler);
    shared_ptr<CVar> getCVar(Compiler* compiler, const string& name, VarScanMode scanMode, CTypeMode returnMode);
    shared_ptr<CBaseFunction> getCFunction(Compiler* compiler, CLoc locCaller, const string& name, shared_ptr<CScope> callerScope, shared_ptr<CTypeNameList> templateTypeNames, CTypeMode returnMode);
    shared_ptr<CType> getVarType(CLoc loc, Compiler* compiler, shared_ptr<CTypeName> typeName, CTypeMode defaultMode);
    string getCInitFunctionName(CTypeMode returnMode);
    string getCCopyFunctionName();
    string getCDestroyFunctionName();
    string getCStructName(CTypeMode typeMode);
    pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>> getFunctionDefinition(string name);
    bool getIsReturnModeValid(Compiler* compiler, CTypeMode returnMode);
    shared_ptr<CType> getReturnType(Compiler* compiler, CTypeMode returnMode);
    void transpileDefinition(Compiler* compiler, TrOutput* trOutput);
    void transpile(Compiler* compiler, shared_ptr<CScope> callerScope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> parentValue, CLoc& calleeLoc, shared_ptr<vector<FunctionParameter>> parameters, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue, CTypeMode returnMode);
    void dumpBody(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level, CTypeMode returnMode);

private:
    shared_ptr<CCallback> callback;
    shared_ptr<CVar> callbackVar;
};

class CCallback : public enable_shared_from_this<CCallback> {
public:
    CCallback(vector<shared_ptr<CType>> argTypes, shared_ptr<CType> returnType);
    static shared_ptr<CCallback> getCallback(vector<shared_ptr<CType>> argTypes, shared_ptr<CType> returnType);
    static shared_ptr<CType> getType(vector<shared_ptr<CType>> argTypes, shared_ptr<CType> returnType, CTypeMode defaultMode, bool isOption);
    static shared_ptr<CVar> getVar(Compiler* compiler, shared_ptr<CScope> scope, CLoc loc, shared_ptr<CVar> dotVar, shared_ptr<CBaseFunction> function, CTypeMode returnMode);
    shared_ptr<CBaseFunction> getFunction(Compiler* compiler, shared_ptr<CVar> callbackVar);
    void transpileDefinition(Compiler* compiler, TrOutput* trOutput);
    string getCBName(Compiler* compiler, bool includeNames);
    string getCName(CTypeMode typeMode, bool isOption);

    shared_ptr<CTypes> types;
    vector<shared_ptr<CType>> argTypes;
    shared_ptr<CType> returnType;

private:
    static map<vector<shared_ptr<CType>>, shared_ptr<CCallback>> _callbacks;
};