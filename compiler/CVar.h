//
//  CVar.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef CVar_h
#define CVar_h

class CFunction;
class NAssignment;
class CResult;

class CVar {
public:
    CVar(CFunction* parent) : parent(parent) { assert(parent != nullptr); }
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result) = 0;
    virtual Value* getValue(Compiler* compiler, CResult& result) = 0;
    
    CFunction* parent;
};

class CLocalVar : CVar {
public:
    CLocalVar(CFunction* parent, const NAssignment* node) : node(node), CVar(parent), value(nullptr), isInGetType(false) { }
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    virtual Value* getValue(Compiler* compiler, CResult& result);
    
private:
    bool isInGetType;
    const NAssignment* node;
    shared_ptr<CType> type;
    AllocaInst* value;
};

#endif /* CVar_h */
