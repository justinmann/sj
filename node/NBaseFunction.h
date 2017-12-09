//
//  NBaseFunction.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NBaseFunction_h
#define NBaseFunction_h

class NBaseFunction : public NBase {
public:
    NBaseFunction(const NodeType nodeType, CLoc loc) : NBase(nodeType, loc) { }
};

class CBaseFunctionDefinition;

class ArgData {
public:
    ArgData(shared_ptr<CVar> var_, shared_ptr<TrStoreValue> value_) : var(var_), value(value_) { }

    shared_ptr<CVar> var;
    shared_ptr<TrStoreValue> value;
};

enum CClassFunctionType {
    CFT_Function,
    CFT_Interface,
    CFT_InterfaceMethod,
    CFT_Callback
};

enum VarScanMode {
    VSM_LocalOnly,
    VSM_ThisOnly,
    VSM_FromChild,
    VSM_LocalThisParent
};

class FunctionParameter {
public:
    static FunctionParameter create(bool isDefaultValue, AssignOp op, shared_ptr<CVar> var);

    bool isDefaultValue;
    AssignOp op;
    shared_ptr<CVar> var;
};

class FunctionDefaultValue {
public:
    AssignOp op;
    shared_ptr<NBase> value;
};

class CBaseFunction {
public:
    CClassFunctionType classType;
    string name;
    bool hasParent;
    bool hasThis;
    weak_ptr<CBaseFunction> parent;
    weak_ptr<CBaseFunctionDefinition> definition;
    vector<FunctionDefaultValue> argDefaultValues;
    
    CBaseFunction(CClassFunctionType classType, string& name, weak_ptr<CBaseFunction> parent, weak_ptr<CBaseFunctionDefinition> definition, bool hasParent) : classType(classType), name(name), hasParent(hasParent), hasThis(false), parent(parent), definition(definition) { }
    virtual void setHasThis();

    virtual int getArgIndex(const string& name, CTypeMode returnMode) = 0;
    virtual int getArgCount(CTypeMode returnMode) = 0;
    virtual shared_ptr<CVar> getArgVar(int index, CTypeMode returnMode) = 0;
    virtual string fullName(bool includeTemplateTypes) = 0;
    virtual shared_ptr<CTypes> getThisTypes(Compiler* compiler) = 0;
    virtual shared_ptr<CVar> getCVar(Compiler* compiler, const string& name, VarScanMode scanMode, CTypeMode returnMode) = 0;
    virtual shared_ptr<CBaseFunction> getCFunction(Compiler* compiler, CLoc locCaller, const string& name, shared_ptr<CScope> callerScope, shared_ptr<CTypeNameList> templateTypeNames, CTypeMode returnMode) = 0;
    virtual shared_ptr<CType> getVarType(CLoc loc, Compiler* compiler, shared_ptr<CTypeName> typeName, CTypeMode defaultMode) = 0;
    virtual string getCFunctionName(CTypeMode returnMode) = 0;
    virtual string getCCallbackFunctionName(Compiler* compiler, TrOutput* trOutput, CTypeMode returnMode) = 0;
    virtual string getCCopyFunctionName() = 0;
    virtual string getCDestroyFunctionName() = 0;
    virtual string getCStructName(CTypeMode typeMode) = 0;
    virtual pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>> getFunctionDefinition(string name) = 0;
    virtual bool getIsReturnModeValid(Compiler* compiler, CTypeMode returnMode) = 0;
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CTypeMode returnMode) = 0;
    virtual void transpileDefinition(Compiler* compiler, TrOutput* trOutput) = 0;
    virtual void transpile(Compiler* compiler, shared_ptr<CScope> callerScope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> parentValue, CLoc& calleeLoc, shared_ptr<vector<FunctionParameter>> parameters, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue, CTypeMode returnMode) = 0;
    virtual void dumpBody(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level, CTypeMode returnMode) = 0;
};

class CBaseFunctionDefinition {
public:
    CClassFunctionType classType;
    string name;
    weak_ptr<CBaseFunctionDefinition> parent;

    CBaseFunctionDefinition(CClassFunctionType classType) : classType(classType) { }
    virtual string fullName() = 0;
    virtual void addChildFunction(string& name, shared_ptr<CBaseFunctionDefinition> childFunction) = 0;
};

#endif /* NFunction_h */
