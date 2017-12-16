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


class NEnum : public NVariableBase {
public:
    NEnum(CLoc loc, string name, shared_ptr<EnumArgs> enumArgs) : NVariableBase(NodeType_Enum, loc), name(name), enumArgs(enumArgs) { }
    void defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
    string name;
    shared_ptr<EnumArgs> enumArgs;
};

#endif /* NEnum_h */
