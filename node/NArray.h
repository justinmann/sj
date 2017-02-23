//
//  NArray.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NArray_h
#define NArray_h

#include "NBase.h"
#include "NFunction.h"

class NCall;
class NInteger;

class NArray : public NBase {
public:
    shared_ptr<NodeList> elements;
    shared_ptr<NCall> createCall;
    shared_ptr<CType> itemType;
    
    NArray(CLoc loc, shared_ptr<NodeList> elements) : elements(elements), isHeapVar(false), NBase(NodeType_Array, loc) { }
    virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);

protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
    virtual int setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar);
    virtual shared_ptr<ReturnValue> compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType);
    
private:
    bool isHeapVar;
};

class NList : public NBase {
public:
    shared_ptr<NCall> createCall;
    shared_ptr<NArray> array;
    
    NList(CLoc loc, shared_ptr<NodeList> elements);
    virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);

protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
    virtual int setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar);
    virtual shared_ptr<ReturnValue> compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType);
};

class NArrayGetFunction : public NFunction {
public:
    NArrayGetFunction();
    virtual shared_ptr<CFunction> createCFunction(Compiler* compiler, CResult& result, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, CFunctionType type, const string& name, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, shared_ptr<CInterfaceMethod> interfaceMethod);
};

class NArraySetFunction : public NFunction {
public:
    NArraySetFunction();
    virtual shared_ptr<CFunction> createCFunction(Compiler* compiler, CResult& result, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, CFunctionType type, const string& name, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, shared_ptr<CInterfaceMethod> interfaceMethod);
};

class NArrayGrowFunction : public NFunction {
public:
    NArrayGrowFunction();
    virtual shared_ptr<CFunction> createCFunction(Compiler* compiler, CResult& result, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, CFunctionType type, const string& name, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, shared_ptr<CInterfaceMethod> interfaceMethod);
};

class NArrayDeleteFunction : public NFunction {
public:
    NArrayDeleteFunction();
    virtual shared_ptr<CFunction> createCFunction(Compiler* compiler, CResult& result, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, CFunctionType type, const string& name, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, shared_ptr<CInterfaceMethod> interfaceMethod);
};

class NArrayCreateFunction : public NFunction {
public:
    NArrayCreateFunction();
    virtual shared_ptr<CFunction> createCFunction(Compiler* compiler, CResult& result, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, CFunctionType type, const string& name, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, shared_ptr<CInterfaceMethod> interfaceMethod);
};


#endif /* NArray_h */
