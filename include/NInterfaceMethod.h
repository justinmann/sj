//
//  NInterfaceMethod.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NInterfaceMethod_h
#define NInterfaceMethod_h

class NInterfaceMethod : public NBaseFunction {
public:
    string name;
    shared_ptr<CTypeNameList> templateTypeNames;
    vector<shared_ptr<NAssignment>> assignments;
    shared_ptr<CTypeName> returnTypeName;

    NInterfaceMethod(CLoc loc, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<vector<string>> attributes, shared_ptr<NodeList> arguments, shared_ptr<CTypeName> returnTypeName);
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {}
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {}
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CType> returnType, CTypeMode returnMode) { return nullptr; }
};

class CInterfaceMethodReturnVar : public CVar {
public:
    CInterfaceMethodReturnVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> returnType) : CVar(loc, scope), returnType(returnType) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
    shared_ptr<CType> returnType;
    vector<shared_ptr<CVar>> returnVars;
};

class CInterfaceMethodArgVar : public CVar {
public:
    CInterfaceMethodArgVar(CLoc loc, shared_ptr<CInterfaceMethod> interfaceMethod, shared_ptr<CType> returnType, string name) : CVar(loc, nullptr, name, name, false), returnType(returnType) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    virtual void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
    shared_ptr<CType> returnType;
    vector<shared_ptr<CVar>> functionVars;
};

class CInterfaceMethod : public CBaseFunction, public enable_shared_from_this<CInterfaceMethod> {
public:
    bool isSpecial;
    shared_ptr<CType> returnType;
    vector<shared_ptr<CType>> argTypes;
    vector<shared_ptr<CVar>> argVars;

    CInterfaceMethod(string name, weak_ptr<CInterface> parent, int methodIndex, CTypeMode returnMode, bool isSpecial);
    shared_ptr<CInterfaceMethod> init(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, shared_ptr<NInterfaceMethod> method, shared_ptr<CBaseFunction> thisFunction);
    string fullName(bool includeTemplateTypes);
    
    shared_ptr<CTypes> getThisTypes(Compiler* compiler);
    int getArgIndex(const string& name, CTypeMode returnMode);
    int getArgCount(CTypeMode returnMode);
    shared_ptr<CVar> getArgVar(int index, CTypeMode returnMode);
    shared_ptr<CVar> getThisVar(Compiler* compiler);
    
    shared_ptr<CBaseFunction> getCFunction(Compiler* compiler, CLoc locCaller, const string& name, shared_ptr<CScope> callerScope, shared_ptr<CTypeNameList> templateTypeNames, CTypeMode returnMode) { assert(false); return nullptr; }
    pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>> getFunctionDefinition(vector<string> packageNamespace, string name) { assert(false); return make_pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>>(nullptr, nullptr); }
    shared_ptr<CType> getVarType(CLoc loc, Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, shared_ptr<CTypeName> typeName, CTypeMode defaultMode);
    bool getIsReturnModeValid(Compiler* compiler, CTypeMode returnMode);
    shared_ptr<CType> getReturnType(Compiler* compiler, CTypeMode returnMode);
    string getCTypeName(Compiler* compiler, bool includeNames);
    string getCStructName(CTypeMode typeMode) { assert(false); return ""; }
    string getCFunctionName(Compiler* compiler, TrOutput* trOutput, CTypeMode returnMode);
    string getCCallbackFunctionName(Compiler* compiler, TrOutput* trOutput, CTypeMode returnMode);
    string getCCopyFunctionName();
    string getCDestroyFunctionName();

    void transpileStructDefinition(Compiler* compiler, TrOutput* trOutput);
    void transpileDefinition(Compiler* compiler, TrOutput* trOutput);
    void transpile(Compiler* compiler, shared_ptr<CScope> callerScope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<CVar> parentVar, CLoc& calleeLoc, shared_ptr<vector<FunctionParameter>> parameters, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue, CTypeMode returnMode);
    void dumpBody(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level, CTypeMode returnMode);
    bool getReturnMustRelease(Compiler* compiler);

    CTypeMode returnMode;
    
private:
    shared_ptr<CInterfaceMethodReturnVar> returnVar;
    CLoc loc;
    map<string, int> argIndex;
};

#endif /* NInterfaceMethod_h */
