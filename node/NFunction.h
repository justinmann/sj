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
    
    NFunction(CLoc loc, CFunctionType type, const char* typeName, const char* name, shared_ptr<TemplateTypeNames> templateTypeNames, NodeList arguments, shared_ptr<NBase> block, shared_ptr<NBase> catchBlock);
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> parentFunction);
    virtual void fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> parentFunction);
    void fixVarBody(Compiler *compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> parentFunction) const;
    virtual shared_ptr<CType> getBlockType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const;
    virtual Value* compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> parentFunction, Value* parentValue, IRBuilder<>* builder, BasicBlock* catchBB) const;
    Function* compileDefinition(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const;
    void compileBody(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Function* function) const;
    virtual void dump(Compiler* compiler, int level) const;
    
private:
    shared_ptr<NFunction> shared_from_this() { return static_pointer_cast<NFunction>(NBase::shared_from_this()); };
    
    static int counter;
};

#endif /* NFunction_h */
