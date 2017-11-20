//
//  NCast.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NCast_h
#define NCast_h

class CCastVar : public CVar {
public:
    CCastVar(CLoc& loc, shared_ptr<CBaseFunction> scope, shared_ptr<CType> typeTo, shared_ptr<CVar> var) : CVar(loc, scope, "", false), typeTo(typeTo), var(var) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    void transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
private:
    shared_ptr<CType> typeTo;
    shared_ptr<CVar> var;
};

class NCast : public NVariableBase {
public:
    NCast(CLoc& loc, shared_ptr<CTypeName> typeName, shared_ptr<NVariableBase> node) : NVariableBase(NodeType_Cast, loc), typeName(typeName), node(node) { }
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode);
    
private:
    const shared_ptr<CTypeName> typeName;
    const shared_ptr<NVariableBase> node;    
    shared_ptr<CVar> interfaceVar;
};

#endif /* NCast_h */
