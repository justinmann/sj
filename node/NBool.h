//
//  NBool.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NBool_h
#define NBool_h

class NBool : public NBase {
public:
    bool value;
    
    NBool(CLoc loc, bool value) : value(value), NBase(loc) { }
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) { }
    virtual void fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) { }
    virtual shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const;
    virtual Value* compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const;
    virtual void dump(Compiler* compiler, int level) const;
};

#endif /* NBool_h */
