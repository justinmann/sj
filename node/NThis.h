//
//  NThis.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NThis_h
#define NThis_h

class CThisVar : public CVar {
public:
    CThisVar(CLoc loc, shared_ptr<CTypes> types, CTypeMode typeMode) : CVar(loc, "", false), types(types), typeMode(typeMode) { }
    shared_ptr<CType> getType(Compiler* compiler, CResult& result, CTypeMode returnMode);
    shared_ptr<ReturnValue> transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName);
    void transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    void setHasRefCount();
    CTypeMode getTypeMode();

private:
    shared_ptr<CTypes> types;
    CTypeMode typeMode;
};

class NThis : public NVariableBase {
public:
    NThis(CLoc loc) : NVariableBase(NodeType_This, loc) {}
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) { }
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar);
};

#endif /* NThis_h */
