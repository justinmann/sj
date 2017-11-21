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

class CConstantVar : public CVar {
public:
    CConstantVar(CLoc loc, shared_ptr<CBaseFunction> scope, shared_ptr<CType> type, string value) : CVar(loc, scope, "", false), type(type), value(value) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    void transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
private:
    shared_ptr<CType> type;
    string value;
};

class NInteger : public NVariableBase {
public:
    NInteger(CLoc loc, const char* value);
    NInteger(CLoc loc, const int32_t value) : NVariableBase(NodeType_Integer, loc), type(NIT_I32), value(value), hasValue(true) { }
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) { }
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
    NIT type;
    string strValue;
    int32_t value;
    bool hasValue;
};

#endif /* NInteger_h */
