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

    NInterfaceMethod(CLoc loc, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<NodeList> arguments, shared_ptr<CTypeName> returnTypeName);
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {}
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar) { return nullptr; }
};

class CInterfaceMethodReturnVar : public CVar {
public:
    CInterfaceMethodReturnVar(CLoc loc, shared_ptr<CType> returnType) : CVar(loc, "", false), returnType(returnType) { }
    shared_ptr<CType> getType(Compiler* compiler, CResult& result, CTypeMode returnMode);
    virtual shared_ptr<ReturnValue> transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName);
    virtual void transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
    shared_ptr<CType> returnType;
    vector<shared_ptr<CVar>> returnVars;
};

class CInterfaceMethodArgVar : public CVar {
public:
    CInterfaceMethodArgVar(CLoc loc, shared_ptr<CType> returnType) : CVar(loc, "", false), returnType(returnType) { }
    shared_ptr<CType> getType(Compiler* compiler, CResult& result, CTypeMode returnMode);
    virtual shared_ptr<ReturnValue> transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName);
    virtual void transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
    shared_ptr<CType> returnType;
    vector<shared_ptr<CVar>> functionVars;
};

class CInterfaceMethod : public CBaseFunction, public enable_shared_from_this<CInterfaceMethod> {
public:
    shared_ptr<CType> returnType;
    vector<shared_ptr<CType>> argTypes;
    vector<shared_ptr<CBaseFunction>> implementations;
    
    CInterfaceMethod(string& name, weak_ptr<CInterface> parent, int methodIndex);
    shared_ptr<CInterfaceMethod> init(Compiler* compiler, CResult& result, shared_ptr<NInterfaceMethod> method, shared_ptr<CBaseFunction> thisFunction);
    string fullName(bool includeTemplateTypes);
    
    bool getHasThis();
    shared_ptr<CTypes> getThisTypes(Compiler* compiler, CResult& result);
    int getThisIndex(const string& name) const;
    shared_ptr<CVar> getThisVar(Compiler* compiler, CResult& result, CTypeMode typeMode);
    
    shared_ptr<CVar> getCVar(Compiler* compiler, CResult& result, const string& name);
    shared_ptr<CBaseFunction> getCFunction(Compiler* compiler, CResult& result, const string& name, shared_ptr<CBaseFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames);
    pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>> getFunctionDefinition(string name) { assert(false); return make_pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>>(nullptr, nullptr); }
    shared_ptr<CType> getVarType(Compiler* compiler, CResult& result, shared_ptr<CTypeName> typeName, CTypeMode returnMode);
    shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, CTypeMode returnMode);
    string getCTypeName(Compiler* compiler, CResult& result, bool includeNames);
    string getCStructName(CTypeMode typeMode) { assert(false); return ""; }
    string getCInitFunctionName(CTypeMode returnMode);
    string getCCopyFunctionName();
    string getCDestroyFunctionName();

    void transpileDefinition(Compiler* compiler, CResult& result, TrOutput* trOutput);
    shared_ptr<ReturnValue> transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> calleeValue, CLoc& calleeLoc, vector<pair<bool, shared_ptr<NBase>>>& parameters, const char* thisName, CTypeMode typeMode);
    void dumpBody(Compiler* compiler, CResult& result, CTypeMode returnTypeMode, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    bool getReturnMustRelease(Compiler* compiler, CResult& result);
    
private:
    shared_ptr<CInterfaceMethodReturnVar> returnVar;
    CLoc loc;
};

#endif /* NInterfaceMethod_h */
