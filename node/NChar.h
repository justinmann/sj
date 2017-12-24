//
//  NChar.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NChar_h
#define NChar_h

class NChar : public NVariableBase {
public:
    string value;
    
    NChar(CLoc loc, const char* value) : NVariableBase(NodeType_Char, loc), value(value) { }
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) { }
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {}
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);
};

#endif /* NChar_h */
