//
//  NVariable.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NVariable_h
#define NVariable_h

#include "NBase.h"

enum ValueType {
    VT_STORE,
    VT_LOAD
};

class NVariableBase : public NBase {
public:
    NVariableBase(NodeType nodeType, CLoc loc) : NBase(nodeType, loc) { }
    shared_ptr<CVar> getVar(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
        return getVarImpl(compiler, scope, nullptr, returnMode);
    }

    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) = 0;
};
/*
class CParentDotVar : public CStoreVar {
public:
    CParentDotVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CFunction> parentFunction, shared_ptr<CVar> childVar, shared_ptr<CVar> dotVar) : CStoreVar(loc, scope, "INVALID", "INVALID", false), parentFunction(parentFunction), childVar(childVar), dotVar(dotVar) {}
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    bool getCanStoreValue();
    shared_ptr<TrStoreValue> getStoreValue(Compiler* compiler, shared_ptr<CScope> scope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, AssignOp op);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
    shared_ptr<CFunction> parentFunction;
    shared_ptr<CVar> childVar;
    shared_ptr<CVar> dotVar;
};
*/
class NVariable : public NVariableBase {
public:
    NVariable(CLoc loc, const char* name, shared_ptr<CTypeNameList> templateTypeNames);
    void defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) { }
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode);

private:
    string name;
    shared_ptr<CTypeNameList> templateTypeNames;
};

#endif /* NVariable_h */
