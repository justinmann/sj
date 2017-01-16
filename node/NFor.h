//
//  NFor.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NFor_h
#define NFor_h

class NFor : public NBase {
public:
    string varName;
    shared_ptr<NBase> start;
    shared_ptr<NBase> end;
    shared_ptr<NBase> body;
    
    NFor(CLoc loc, const char* varName, shared_ptr<NBase> start, shared_ptr<NBase> end, shared_ptr<NBase> body) : varName(varName), start(start), end(end), body(body), NBase(loc) { }
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction);
    virtual void fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const;
    virtual Value* compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const;
    virtual void dump(Compiler* compiler, int level) const;
};

#endif /* NFor_h */
