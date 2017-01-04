//
//  NInteger.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NInteger_h
#define NInteger_h

class NInteger : public NBase {
public:
    string value;
    
    NInteger(CLoc loc, const char* value) : value(value), NBase(loc) { }
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result) { }
    virtual void fixVar(Compiler* compiler, CResult& result) { }
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result) const;
    virtual Value* compile(Compiler* compiler, CResult& result) const;
    virtual void dump(Compiler* compiler, int level) const;
};

#endif /* NInteger_h */
