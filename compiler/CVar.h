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
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result) = 0;
    virtual Value* getValue(Compiler* compiler, CResult& result, Value* thisValue) = 0;
    
    weak_ptr<CFunction> parent;
};

class CLocalVar : public CVar {
public:
    static shared_ptr<CLocalVar> create(shared_ptr<CFunction> parent, shared_ptr<NAssignment> node);
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    virtual Value* getValue(Compiler* compiler, CResult& result, Value* thisValue);
    
private:
    bool isInGetType;
    shared_ptr<NAssignment> node;
    shared_ptr<CType> type;
    AllocaInst* value;
};

#endif /* CVar_h */
