//
//  NDouble.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NDouble_h
#define NDouble_h

class NDouble : public NBase {
public:
    string value;
    
    NDouble(CLoc loc, const char* value) : value(value), NBase(loc) { }
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result) {}
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result) const;
    virtual Value* compile(Compiler* compiler, CResult& result) const;
};

#endif /* NDouble_h */
