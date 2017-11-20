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
    CThisVar(CLoc loc, shared_ptr<CBaseFunction> scope, shared_ptr<CTypes> types, CTypeMode typeMode) : CVar(loc, scope, "", false), types(types), typeMode(typeMode) { }
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    void transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
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
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) { }
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode);
};

#endif /* NThis_h */
