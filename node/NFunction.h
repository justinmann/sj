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
    const string type;
    string name;
    NodeList invalid;
    vector<shared_ptr<NAssignment>> assignments;
    vector<shared_ptr<NFunction>> functions;
    const shared_ptr<NBlock> block;
    const shared_ptr<NBlock> catchBlock;
    
    NFunction(CLoc loc, const char* type, const char* name, NodeList arguments, shared_ptr<NBlock> block, shared_ptr<NBlock> catchBlock);
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result, shared_ptr<CFunction> parentFunction);
    virtual void fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> parentFunction);
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> parentFunction) const;
    virtual shared_ptr<CType> getBlockType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const;
    virtual Value* compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> parentFunction, Value* parentValue, IRBuilder<>* builder, BasicBlock* catchBB) const;
    virtual void dump(Compiler* compiler, int level) const;
    
private:
    shared_ptr<NFunction> shared_from_this() { return static_pointer_cast<NFunction>(NBase::shared_from_this()); };
    
    static int counter;
};

#endif /* NFunction_h */
