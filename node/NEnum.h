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
    EnumArg(string name) : name(name), hasValue(false) { }
    EnumArg(string name, string value) : name(name), hasValue(true), value(value) { }
    
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

/*
class CConstantVar : public CVar {
public:
    CConstantVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type, string value) : CVar(loc, scope), type(type), value(value) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
private:
    shared_ptr<CType> type;
    string value;
};

*/

class NEnum : public NVariableBase {
public:
    NEnum(CLoc loc, shared_ptr<EnumArgs> args) : NVariableBase(NodeType_Enum, loc), args(args) { }
    void defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) { }
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
    shared_ptr<EnumArgs> args;
};

#endif /* NEnum_h */
