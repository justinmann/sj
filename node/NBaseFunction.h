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
    ArgData(shared_ptr<CVar> var_, shared_ptr<TrStoreValue> value_) : var(var_), name(value_->name), value(value_) { }
    ArgData(shared_ptr<CVar> var_, string name_) : var(var_), name(name_), value(nullptr) { }

    shared_ptr<CVar> var;
    string name;
    shared_ptr<TrStoreValue> value;
};

enum CClassFunctionType {
    CFT_Function,
    CFT_Interface,
    CFT_InterfaceMethod
};

class CBaseFunction {
public:
    CClassFunctionType classType;
    string name;
    bool hasParent;
    bool hasThis;
    weak_ptr<CBaseFunction> parent;
    weak_ptr<CBaseFunctionDefinition> definition;
    vector<shared_ptr<CVar>> argVars;
    vector<shared_ptr<NBase>> argDefaultValues;
    
    CBaseFunction(CClassFunctionType classType, string& name, weak_ptr<CBaseFunction> parent, weak_ptr<CBaseFunctionDefinition> definition) : classType(classType), name(name), hasParent(false), hasThis(false), parent(parent), definition(definition) { }
    virtual void setHasThis();
    virtual bool getHasParent(Compiler* compiler, CResult& result);
    virtual void setHasParent(Compiler* compiler, CResult& result);
    virtual void onHasParent(std::function<void(Compiler*, CResult&)> notify);

    virtual string fullName(bool includeTemplateTypes) = 0;
    virtual shared_ptr<CTypes> getThisTypes(Compiler* compiler, CResult& result) = 0;
    virtual int getThisIndex(const string& name) const = 0;
    virtual shared_ptr<CVar> getCVar(Compiler* compiler, CResult& result, const string& name) = 0;
    virtual shared_ptr<CBaseFunction> getCFunction(Compiler* compiler, CResult& result, const string& name, shared_ptr<CBaseFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames, CTypeMode returnMode) = 0;
    virtual shared_ptr<CType> getVarType(CLoc loc, Compiler* compiler, CResult& result, shared_ptr<CTypeName> typeName, CTypeMode defaultMode) = 0;
    virtual string getCInitFunctionName() = 0;
    virtual string getCCopyFunctionName() = 0;
    virtual string getCDestroyFunctionName() = 0;
    virtual string getCStructName(CTypeMode typeMode) = 0;
    virtual pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>> getFunctionDefinition(string name) = 0;
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result) = 0;
    virtual void transpileDefinition(Compiler* compiler, CResult& result, TrOutput* trOutput) = 0;
    virtual void transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> parentValue, CLoc& calleeLoc, vector<pair<bool, shared_ptr<NBase>>>& parameters, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) = 0;
    virtual void dumpBody(Compiler* compiler, CResult& result, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) = 0;

private:
    vector<std::function<void(Compiler*, CResult&)>> delegateHasParent;
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
