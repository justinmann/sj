//
//  NEnum.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NEnum_h
#define NEnum_h

class EnumArg {
public:
    EnumArg(string name);
    EnumArg(string name, string value);
    
    string name;
    bool hasValue;
    string value;
};

class EnumArgs : public vector<shared_ptr<EnumArg>> {
public:
    EnumArgs() : vector<shared_ptr<EnumArg>>() { }
    
    EnumArgs(shared_ptr<EnumArg> i0) : vector<shared_ptr<EnumArg>>() {
        push_back(i0);
    }
};


class CInitBlockVar : public CVar {
public:
    CInitBlockVar(CLoc loc, shared_ptr<CScope> scope, vector<shared_ptr<CVar>> statements);
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);

private:
    vector<shared_ptr<CVar>> statements;
}; 

class NEnum : public NVariableBase {
public:
    NEnum(CLoc loc, string name, shared_ptr<EnumArgs> enumArgs);
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode);

private:
    string name;
    shared_ptr<EnumArgs> enumArgs;
    vector<string> packageNamespace;
    vector<shared_ptr<CNormalVar>> enumVars;
    shared_ptr<NFunction> asStringFunction;
};

#endif /* NEnum_h */
