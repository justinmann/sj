//
//  NInteger.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NInteger_h
#define NInteger_h

enum NIT {
    NIT_I32,
    NIT_I64,
    NIT_U32,
    NIT_U64,
};

class NInteger : public NVariableBase {
public:
    NInteger(CLoc loc, const char* value);
    NInteger(CLoc loc, const char* value, shared_ptr<CType> overrideType);
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) { }
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {}
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode);

private:
    shared_ptr<CType> overrideType;
    NIT type;
    string strValue;
    int strBase;
    int32_t value;
    bool hasValue;
};

#endif /* NInteger_h */
