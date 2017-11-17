//
//  CVar.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef CVar_h
#define CVar_h

class CFunction;
class CBaseFunction;
class NAssignment;
class CResult;
class ReturnValue;
class TrOutput;
class TrBlock;

enum CVarType {
    Var_This,
    Var_Local,
    Var_Private,
    Var_Public
};

enum ReturnRefType {
    RRT_Auto,
    RRT_MustRelease,
    RRT_MustRetain
};

class CVar {
public:
    CVar() { }

    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result) = 0;
    virtual shared_ptr<ReturnValue> transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName) = 0;
    virtual void transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) = 0;
    virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeReturnMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) = 0;
};

class NFunction;

class CNormalVar : public CVar {
public:
    static shared_ptr<CNormalVar> createLocalVar(const CLoc& loc, const string& name, shared_ptr<CBaseFunction> parent, shared_ptr<NAssignment> nassignment);
    static shared_ptr<CNormalVar> createFunctionVar(const CLoc& loc, const string& name, shared_ptr<CBaseFunction> parent, int index, shared_ptr<NAssignment> nassignment, shared_ptr<CType> type, shared_ptr<CVar> interfaceMethodArgVar_);
    
    //string fullName();
    //shared_ptr<CBaseFunction> getCFunctionForValue(Compiler* compiler, CResult& result);
    void makeFunctionVar(int index);

    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    shared_ptr<ReturnValue> transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName);
    void transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeReturnMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
    string name;

private:
    CLoc loc;
    bool isInGetType;
    int index;
    shared_ptr<CType> type;
    shared_ptr<CVar> interfaceMethodArgVar;
    CVarType mode;
    bool isMutable;
    weak_ptr<CBaseFunction> parent;
    shared_ptr<NAssignment> nassignment;
};

#endif /* CVar_h */
