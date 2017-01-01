//
//  NCall.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NCall_h
#define NCall_h

class NCall : public NBase {
public:
    const string name;
    const NodeList arguments;
    
    NCall(CLoc loc, const char* name, NodeList arguments) : name(name), arguments(arguments), NBase(loc) { }
    NCall(CLoc loc, const char* name) : name(name), NBase(loc) { }
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result) { }
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result) const;
    virtual Value* compile(Compiler* compiler, CResult& result) const;
};

#endif /* NCall_h */
