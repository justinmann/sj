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
    NBaseFunction(const NodeType nodeType, const CLoc loc) : NBase(nodeType, loc) { }
};

class CBaseFunctionDefinition;

class ArgData {
public:
    ArgData(shared_ptr<CVar> var_, shared_ptr<ReturnValue> value_) : var(var_), name(value_->name), value(value_) { }
    ArgData(shared_ptr<CVar> var_, string name_) : var(var_), name(name_), value(nullptr) { }

    shared_ptr<CVar> var;
    string name;
    shared_ptr<ReturnValue> value;
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
    bool hasRefCount;
    weak_ptr<CBaseFunction> parent;
    weak_ptr<CBaseFunctionDefinition> definition;
    vector<shared_ptr<CVar>> argVars;
    vector<shared_ptr<NBase>> argDefaultValues;
    
    CBaseFunction(CClassFunctionType classType, string& name, weak_ptr<CBaseFunction> parent, weak_ptr<CBaseFunctionDefinition> definition) : classType(classType), name(name), hasParent(false), hasRefCount(false), parent(parent), definition(definition) { }
    virtual string fullName(bool includeTemplateTypes) = 0;
    
    virtual bool getHasThis() = 0;
    virtual shared_ptr<CType> getThisType(Compiler* compiler, CResult& result, bool isOption) = 0;
    virtual int getThisIndex(const string& name) const = 0;
    virtual shared_ptr<CVar> getThisVar(Compiler* compiler, CResult& result) = 0;
    //virtual Type* getStructType(Compiler* compiler, CResult& result) = 0;

    virtual void setHasRefCount();
    virtual bool getHasParent(Compiler* compiler, CResult& result);
    virtual void setHasParent(Compiler* compiler, CResult& result);
    virtual void onHasParent(std::function<void(Compiler*, CResult&)> notify);
    //virtual Value* getRefCount(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) = 0;

    virtual shared_ptr<CVar> getCVar(Compiler* compiler, CResult& result, const string& name) = 0;
    virtual shared_ptr<CBaseFunction> getCFunction(Compiler* compiler, CResult& result, const string& name, shared_ptr<CBaseFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames) = 0;
    //virtual Value* getParentValue(Compiler* compiler, CResult& result, IRBuilder<>* builder, bool thisInEntry, Value* thisValue) = 0;
    virtual pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>> getFunctionDefinition(string name) = 0;
    virtual shared_ptr<CType> getVarType(Compiler* compiler, CResult& result, shared_ptr<CTypeName> typeName) = 0;
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) = 0;
    virtual shared_ptr<CVar> getReturnVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) = 0;
    virtual string getCInitFunctionName() = 0;
    virtual string getCDestroyFunctionName() = 0;

    //virtual void initStack(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue);
    //virtual void initHeap(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue);
    //virtual void retainStack(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue);
    //virtual void retainHeap(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue);
    //virtual void releaseStack(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue);
    //virtual void releaseHeap(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue);

    //virtual shared_ptr<ReturnValue> call(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, shared_ptr<CVar> calleeVar, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters, ReturnRefType returnRefType) = 0;
    virtual void transpileDefinition(Compiler* compiler, CResult& result, TrOutput* trOutput) = 0;
    virtual shared_ptr<ReturnValue> transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue, shared_ptr<ReturnValue> calleeValue, shared_ptr<CVar> calleeVar, CLoc& calleeLoc, vector<pair<bool, shared_ptr<NBase>>>& parameters, const char* thisName) = 0;
    virtual void dumpBody(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) = 0;
    virtual bool getReturnMustRelease(Compiler* compiler, CResult& result) = 0;
    //virtual Function* getDestructor(Compiler* compiler, CResult& result) = 0;
    
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
