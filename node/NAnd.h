//
//  NAnd.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NAnd_h
#define NAnd_h

#include "NBase.h"

class NAnd : public NBase {
public:
    const shared_ptr<NBase> left;
    const shared_ptr<NBase> right;
    
    NAnd(CLoc loc, shared_ptr<NBase> left, shared_ptr<NBase> right) : left(left), right(right), NBase(NodeType_And, loc) { }
    virtual void dump(Compiler* compiler, int level) const;
    
protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual int setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, bool isHeapVar);
    virtual Value* compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, bool isReturnRetained);
};

#endif /* NOr_h */
