//
//  NGetValue.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright � 2016 Mann, Justin. All rights reserved.
//

#ifndef NGetValue_h
#define NGetValue_h

class CGetValueVar : public CVar {
public:
    CGetValueVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> leftVar, bool isProtectedWithEmptyCheck) : CVar(loc, scope), leftVar(leftVar), isProtectedWithEmptyCheck(isProtectedWithEmptyCheck) { }
    
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
private:
    shared_ptr<CVar> leftVar;
    bool isProtectedWithEmptyCheck;
};

class NGetValue : public NVariableBase {
public:
    NGetValue(CLoc loc, shared_ptr<NBase> node, bool isProtectedWithEmptyCheck) : NVariableBase(NodeType_GetValue, loc), node(node), isProtectedWithEmptyCheck(isProtectedWithEmptyCheck) {}

    virtual void defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
    shared_ptr<NBase> node;
    bool isProtectedWithEmptyCheck;
};

#endif /* NGetValue_h */
