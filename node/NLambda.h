//
//  NLambda.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NLambda_h
#define NLambda_h

class NLambdaInvokeFunction : public NFunction {
public:
    NLambdaInvokeFunction(CLoc loc, shared_ptr<CTypeName> returnTypeName, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<vector<string>> attributes, shared_ptr<CTypeNameList> interfaceTypeNames, shared_ptr<NodeList> arguments, shared_ptr<NBase> block, shared_ptr<NBase> catchBlock, shared_ptr<NBase> copyBlock, shared_ptr<NBase> destroyBlock);
    virtual shared_ptr<CFunctionDefinition> getFunctionDefinition(Compiler *compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string> packageNamespace, shared_ptr<CFunctionDefinition> parentFunction);
};

class CLambdaInvokeFunctionDefinition : public CFunctionDefinition {
public:
    CLambdaInvokeFunctionDefinition() : CFunctionDefinition() {}

protected:
    shared_ptr<CFunction> createFunction(vector<pair<string, vector<string>>>& importNamespaces, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, vector<shared_ptr<NCCode>> ccodes, bool hasHeapThis);
};

class CLambdaInvokeFunction : public CFunction {
public:
    CLambdaInvokeFunction(vector<pair<string, vector<string>>>& importNamespaces, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, vector<shared_ptr<NCCode>> ccodes, bool hasHeapThis);
    virtual shared_ptr<CVar> getCVar(Compiler* compiler, shared_ptr<CScope> callerScope, vector<shared_ptr<LocalVarScope>> localVarScopes, vector<string> ns, shared_ptr<CVar> dotVar, const string& name, VarScanMode scanMode, CTypeMode returnMode);
}; 

class NLambdaClassFunction : public NFunction {
public:
    NLambdaClassFunction(CLoc loc, shared_ptr<CTypeName> returnTypeName, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<vector<string>> attributes, shared_ptr<CTypeNameList> interfaceTypeNames, shared_ptr<NodeList> arguments, shared_ptr<NBase> block, shared_ptr<NBase> catchBlock, shared_ptr<NBase> copyBlock, shared_ptr<NBase> destroyBlock);
    virtual shared_ptr<CFunctionDefinition> getFunctionDefinition(Compiler *compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string> packageNamespace, shared_ptr<CFunctionDefinition> parentFunction);

    shared_ptr<CScope> callerScope;
    CTypeMode returnMode;
};

class CLambdaClassFunctionDefinition : public CFunctionDefinition {
public:
    CLambdaClassFunctionDefinition() : CFunctionDefinition() {}

protected:
    shared_ptr<CFunction> createFunction(vector<pair<string, vector<string>>>& importNamespaces, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, vector<shared_ptr<NCCode>> ccodes, bool hasHeapThis);
};

class CLambdaClassFunction : public CFunction {
public:
    CLambdaClassFunction(vector<pair<string, vector<string>>>& importNamespaces, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, vector<shared_ptr<NCCode>> ccodes, bool hasHeapThis);
    virtual shared_ptr<CVar> getCVar(Compiler* compiler, shared_ptr<CScope> callerScope, vector<shared_ptr<LocalVarScope>> localVarScopes, vector<string> ns, shared_ptr<CVar> dotVar, const string& name, VarScanMode scanMode, CTypeMode returnMode);
    virtual void transpileStructDefinition(Compiler* compiler, TrOutput* trOutput);

    map<CTypeMode, map<shared_ptr<CVar>, shared_ptr<CNormalVar>>> vars;
};

class CLambdaCallVar : public CCallVar {
public:
    CLambdaCallVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<vector<FunctionParameter>> parameters, shared_ptr<CBaseFunction> callee, CTypeMode returnMode);
    virtual void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
};

class NLambdaCall : public NCall {
public:
    NLambdaCall(CLoc loc, string name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<NodeList> arguments, shared_ptr<NLambdaClassFunction> lambdaClassFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);

protected:
    virtual shared_ptr<CCallVar> createCallVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<vector<FunctionParameter>> parameters, shared_ptr<CBaseFunction> callee, CTypeMode returnMode);

private:
    shared_ptr<NLambdaClassFunction> lambdaClassFunction;
};

class CTempStoreVar : public CStoreVar {
public:
    CTempStoreVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type, string name) : CStoreVar(loc, scope, "", "", false), type(type), name(name) {}
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    bool getCanStoreValue();
    shared_ptr<TrStoreValue> getStoreValue(Compiler* compiler, shared_ptr<CScope> scope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, AssignOp op);

private:
    shared_ptr<CType> type;
    string name;
}; 

class NLambda : public NBase {
public:
    NLambda(CLoc loc, shared_ptr<NodeList> arguments, shared_ptr<NBase> block) : NBase(NodeType_Lambda, loc), arguments(arguments), block(block) { }

    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);

private:
    shared_ptr<NodeList> arguments;
    shared_ptr<NBase> block;
    shared_ptr<NBase> initFunction;
    shared_ptr<NLambdaClassFunction> lambdaClassFunction;
};

#endif /* NLambda_h */
