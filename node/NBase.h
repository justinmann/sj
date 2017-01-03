//
//  NBase.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NBase_h
#define NBase_h

class NBase : public enable_shared_from_this<NBase> {
public:   
    const CLoc loc;
    
    NBase(const CLoc loc) : loc(loc) { }
    virtual ~NBase() { }
    virtual NodeType getNodeType() const = 0;
    virtual void define(Compiler* compiler, CResult& result) = 0;
    virtual void fixVar(Compiler* compiler, CResult& result) = 0;
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result) const = 0;
    virtual Value* compile(Compiler* compiler, CResult& result) const = 0;
};

#endif /* NBase_h */
