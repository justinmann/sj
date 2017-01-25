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
    const string typeName;
    string name;
    shared_ptr<TemplateTypeNames> templateTypeNames;
    NodeList invalid;
    vector<shared_ptr<NAssignment>> assignments;
    vector<shared_ptr<NFunction>> functions;
    const shared_ptr<NBase> block;
    const shared_ptr<NBase> catchBlock;
    
    NFunction(CLoc loc, CFunctionType type, const char* typeName, const char* name, shared_ptr<TemplateTypeNames> templateTypeNames, shared_ptr<NodeList> arguments, shared_ptr<NBase> block, shared_ptr<NBase> catchBlock);

    virtual shared_ptr<CType> getBlockType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual Value* call(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, shared_ptr<CFunction> callee, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters);
    virtual void getVarBody(Compiler *compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    Function* compileDefinition(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual void compileBody(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Function* function);
    virtual void dump(Compiler* compiler, int level) const;
    
protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> parentFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> parentFunction);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> parentFunction);
    virtual int setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, bool isHeapVar) { return 0; }
    virtual Value* compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> parentFunction, Value* parentValue, IRBuilder<>* builder, BasicBlock* catchBB);

private:
    shared_ptr<NFunction> shared_from_this() { return static_pointer_cast<NFunction>(NBase::shared_from_this()); };
    
    static int counter;
};

#endif /* NFunction_h */
