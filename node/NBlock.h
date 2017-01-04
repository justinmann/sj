//
//  NBlock.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NBlock_h
#define NBlock_h

class NBlock : public NBase {
public:
    NodeList statements;
    
    NBlock(CLoc loc) : NBase(loc) { }
    NBlock(CLoc loc, NodeList statements) : statements(statements), NBase(loc) { }
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result);
    virtual void fixVar(Compiler* compiler, CResult& result);
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result) const;
    virtual Value* compile(Compiler* compiler, CResult& result) const;
    virtual void dump(Compiler* compiler, int level) const;
};

#endif /* NBlock_h */
