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
    vector<string> dotNames;
    string functionName;
    const NodeList arguments;
    
    NCall(CLoc loc, const char* name, NodeList arguments);
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual void fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const;
    virtual Value* compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const;
    shared_ptr<CFunction> getCFunction(Compiler *compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder) const;
    virtual void dump(Compiler* compiler, int level) const;
};

#endif /* NCall_h */
