//
//  NVoid.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NVoid_h
#define NVoid_h

class NVoid : public NBase {
public:
    NVoid(CLoc loc) : NBase(loc) { }
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result) {}
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result) const;
    virtual Value* compile(Compiler* compiler, CResult& result) const;
};

#endif /* NVoid_h */
