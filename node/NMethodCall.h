//
//  NMethodCall.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NMethodCall_h
#define NMethodCall_h

class NMethodCall : public NBase {
public:
    const string name;
    const shared_ptr<NodeList> arguments;
    
    NMethodCall(CLoc loc, const char* name, shared_ptr<NodeList> arguments) : name(name), arguments(arguments), NBase(loc) { }
    NMethodCall(CLoc loc, const char* name) : name(name), arguments(nullptr), NBase(loc) { }
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result) { }
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result) const;
    virtual Value* compile(Compiler* compiler, CResult& result) const;
};

#endif /* NMethodCall_h */
