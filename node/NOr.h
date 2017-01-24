//
//  NOr.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NOr_h
#define NOr_h

class NOr : public NBase {
public:
    const shared_ptr<NBase> left;
    const shared_ptr<NBase> right;
    
    NOr(CLoc loc, shared_ptr<NBase> left, shared_ptr<NBase> right) : left(left), right(right), NBase(NodeType_Or, loc) { }
    virtual void dump(Compiler* compiler, int level) const;

protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual Value* compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB);
};

#endif /* NOr_h */
