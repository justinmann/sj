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

enum CVarType {
    Local,
    Private,
    Public
};

class CVar {
public:
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result) = 0;
    virtual Value* getValue(Compiler* compiler, CResult& result, Value* thisValue, IRBuilder<>* builder) = 0;
    string fullName();

    string name;
    CVarType mode;
    weak_ptr<CFunction> parent;
    shared_ptr<NAssignment> nassignment;
};

class CLocalVar : public CVar {
public:
    static shared_ptr<CLocalVar> create(const string& name, shared_ptr<CFunction> parent, shared_ptr<NAssignment> nassignment);
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    virtual Value* getValue(Compiler* compiler, CResult& result, Value* thisValue, IRBuilder<>* builder);
    
private:
    bool isInGetType;
    shared_ptr<CType> type;
    AllocaInst* value;
};

#endif /* CVar_h */
