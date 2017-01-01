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
    const shared_ptr<NodeList> statements;
    
    NBlock(CLoc loc) : NBase(loc), statements(make_shared<NodeList>()) { }
    NBlock(CLoc loc, shared_ptr<NodeList> statements) : statements(statements), NBase(loc) { }
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result);
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result) const;
    virtual Value* compile(Compiler* compiler, CResult& result) const;
};

#endif /* NBlock_h */
