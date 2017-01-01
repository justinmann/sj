//
//  NIf.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NIf_h
#define NIf_h

class NIf : public NBase {
public:
    shared_ptr<NBase> condition;
    shared_ptr<NBase> ifBlock;
    shared_ptr<NBase> elseBlock;
    
    NIf(CLoc loc, shared_ptr<NBase> condition, shared_ptr<NBase> ifBlock, shared_ptr<NBase> elseBlock) : condition(condition), ifBlock(ifBlock), elseBlock(elseBlock), NBase(loc) { }
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result) {}
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result) const;
    virtual Value* compile(Compiler* compiler, CResult& result) const;
};

#endif /* NIf_h */
