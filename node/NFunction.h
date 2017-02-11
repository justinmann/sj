//
//  NFunction.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NFunction_h
#define NFunction_h

#include "NBlock.h"

class NFunction : public NBase {
public:
    CFunctionType type;
    const string externName;
    shared_ptr<CTypeName> returnTypeName;
    string name;
    shared_ptr<CTypeNameList> templateTypeNames;
    NodeList invalid;
    vector<shared_ptr<NAssignment>> assignments;
    vector<shared_ptr<NFunction>> functions;
    const shared_ptr<NBase> block;
    const shared_ptr<NBase> catchBlock;
    const shared_ptr<NBase> destroyBlock;
    
    // For normal
    NFunction(CLoc loc, CFunctionType type, shared_ptr<CTypeName> returnTypeName, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<NodeList> arguments, shared_ptr<NBase> block, shared_ptr<NBase> catchBlock, shared_ptr<NBase> destroyBlock);

    // For extern
    NFunction(CLoc loc, CFunctionType type, const char* externName, shared_ptr<CTypeName> returnTypeName, const char* name, shared_ptr<NodeList> arguments);

    virtual shared_ptr<CType> getBlockType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar);
    virtual shared_ptr<ReturnValue> call(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, shared_ptr<CFunction> callee, shared_ptr<CVar> calleeVar, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters);
    virtual shared_ptr<CVar> getReturnVar(Compiler *compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar);
    virtual void getVarBody(Compiler *compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar);
    virtual int setHeapVarBody(Compiler *compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar);
    Function* compileDefinition(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar);
    virtual bool compileBody(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, Function* function);
    virtual Function* compileDestructorDefinition(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual void compileDestructorBody(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Function* function);
    virtual void dumpBody(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CFunction>, string>& functions, stringstream& ss, int level);
    virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CFunction>, string>& functions, stringstream& ss, int level) { }
    
protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> parentFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> parentFunction, shared_ptr<CVar> parentVar);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> parentFunction, shared_ptr<CVar> parentVar);
    virtual int setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) { return 0; }
    virtual shared_ptr<ReturnValue> compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> parentFunction, shared_ptr<CVar> parentVar, Value* parentValue, IRBuilder<>* builder, BasicBlock* catchBB);

private:
    shared_ptr<NFunction> shared_from_this() { return static_pointer_cast<NFunction>(NBase::shared_from_this()); };
    
    static int counter;
    bool isInGetType;
};

#endif /* NFunction_h */
