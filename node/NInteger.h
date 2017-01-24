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
    string strValue;
    int64_t value;
    
    NInteger(CLoc loc, const char* value) : strValue(value), NBase(NodeType_Integer, loc) { }
    NInteger(CLoc loc, const int64_t value) : value(value), NBase(NodeType_Integer, loc) { }
    virtual void dump(Compiler* compiler, int level) const;

protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) { }
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) { return nullptr; }
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual Value* compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB);
};

#endif /* NInteger_h */
