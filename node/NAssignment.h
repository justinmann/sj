//
//  NAssignment.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NAssignment_h
#define NAssignment_h

#include "NBase.h"
#include "NVariable.h"

class CCallVar;

class NAssignment : public NBase {
public:
    NAssignment(CLoc loc, shared_ptr<NVariableBase> var, shared_ptr<CTypeName> typeName, const char* name, shared_ptr<NBase> rightSide, bool isMutable);
	virtual shared_ptr<ReturnValue> transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue);
	virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
    shared_ptr<NVariableBase> var;
    shared_ptr<CTypeName> typeName;
    string name;
    bool inFunctionDeclaration;
    shared_ptr<NBase> rightSide;
    shared_ptr<NFunction> nfunction;
    bool isMutable;

protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
    virtual int setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar);
    //virtual shared_ptr<ReturnValue> compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType);

private:
    bool _isFirstAssignment;
    shared_ptr<CVar> _assignVar;
    shared_ptr<NAssignment> shared_from_this();
    shared_ptr<CCallVar> _callVar;
};

#endif /* NAssignment_h */
