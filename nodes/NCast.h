//
//  NCast.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NCast_h
#define NCast_h

class NCast : public NBase {
public:
    const string type;
    const shared_ptr<NBase> node;
    
    NCast(CLoc loc, const char* type, shared_ptr<NBase> node) : type(type), node(node), NBase(loc) { }
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result);
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result) const;
    virtual Value* compile(Compiler* compiler, CResult& result) const;
};

#endif /* NCast_h */
