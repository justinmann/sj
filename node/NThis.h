//
//  NThis.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NThis_h
#define NThis_h

class NThis : public NVariableBase {
public:
    NThis(CLoc loc);
    virtual NodeType getNodeType() const;
    virtual void define(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) { }
    virtual void fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar) const;
    virtual string getName() const;
    virtual shared_ptr<CVar> getVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar) const;
    virtual void dump(Compiler* compiler, int level) const;
};

#endif /* NThis_h */
