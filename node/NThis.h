//
//  NThis.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NThis_h
#define NThis_h

class NThis;

class CThisVar : public CVar {
public:
    CThisVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CTypes> types, CTypeMode typeMode) : CVar(loc, scope), types(types), typeMode(typeMode) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    void setHasThis();
    CTypeMode getTypeMode();

private:
    shared_ptr<CTypes> types;
    CTypeMode typeMode;

    friend class NThis;
};

class NThis : public NVariableBase {
public:
    NThis(CLoc loc) : NVariableBase(NodeType_This, loc) {}
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) { }
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {}
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
};

#endif /* NThis_h */
