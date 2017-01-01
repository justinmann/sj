//
//  CFunction.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef CFunction_h
#define CFunction_h

class NFunction;

class CFunctionVar : CVar {
public:
    CFunctionVar(CFunction* parent, const NFunction* nfunction, const int index, const NAssignment* nassignment) : nfunction(nfunction), index(index), nassignment(nassignment), CVar(parent), type(nullptr), value(nullptr), isInGetType(false) { }
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    virtual Value* getValue(Compiler* compiler, CResult& result);
    
private:
    bool isInGetType;
    const NFunction* nfunction;
    const NAssignment* nassignment;
    const int index;
    shared_ptr<CType> type;
    Value* value;
};

class CFunction {
public:
    CFunction* parent;
    const NFunction* node;
    map<string, shared_ptr<CVar>> vars;
    map<string, shared_ptr<CFunction>> funcs;
    
    CFunction(CFunction* parent, const NFunction* node);
    shared_ptr<CType> getReturnType(Compiler* compiler, CResult& result);
    shared_ptr<CType> getThisType(Compiler* compiler, CResult& result);
    Function* getFunction(Compiler* compiler, CResult& result);
    BasicBlock* getBasicBlock();
    Value* getArgumentValue(int index, Compiler* compiler);
    Argument* getThis();
    CFunction* getCFunction(const string& name) const;
    CVar* getCVariable(const string& name) const;
    int getThisIndex(const string& name) const;
    
private:
    bool isInGetType;
    bool isInGetFunction;
    shared_ptr<CType> returnType;
    shared_ptr<CType> thisType;
    Function* func;
    BasicBlock* basicBlock;
    Value* thisValue;
};

#endif /* CFunction_h */
