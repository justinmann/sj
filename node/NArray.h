//
//  NArray.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NArray_h
#define NArray_h

#include "NBase.h"
#include "NFunction.h"

class NCall;
class NInteger;

class NArray : public NBase {
public:
    shared_ptr<NodeList> elements;
    shared_ptr<NCall> createCall;
    shared_ptr<CType> itemType;
    
    NArray(CLoc loc, shared_ptr<NodeList> elements) : elements(elements), isHeapVar(false), NBase(NodeType_Array, loc) { }
    virtual void dump(Compiler* compiler, int level) const;

protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual int setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, bool isHeapVar);
    virtual Value* compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB);
    
private:
    bool isHeapVar;
};

class NList : public NBase {
public:
    shared_ptr<NCall> createCall;
    shared_ptr<NArray> array;
    
    NList(CLoc loc, shared_ptr<NodeList> elements);
    virtual void dump(Compiler* compiler, int level) const;

protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual int setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, bool isHeapVar);
    virtual Value* compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB);
};

class NArrayGetFunction : public NFunction {
public:
    NArrayGetFunction() : NFunction(CLoc::undefined, FT_Private, "item", "get", nullptr, make_shared<NodeList>(
                                                                                                              make_shared<NAssignment>(CLoc::undefined, nullptr, "int", "index", nullptr, false)
                                                                                                              ), nullptr, nullptr) { }
    
    virtual shared_ptr<CType> getBlockType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual Value* call(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, shared_ptr<CFunction> callee, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters);
};

class NArraySetFunction : public NFunction {
public:
    NArraySetFunction() : NFunction(CLoc::undefined, FT_Private, "void", "set", nullptr, make_shared<NodeList>(
                                                                                                              make_shared<NAssignment>(CLoc::undefined, nullptr, "int", "index", nullptr, false),
                                                                                                              make_shared<NAssignment>(CLoc::undefined, nullptr, "item", "item", nullptr, false)
                                                                                                              ), nullptr, nullptr) { }
    
    virtual shared_ptr<CType> getBlockType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual Value* call(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, shared_ptr<CFunction> callee, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters);
};

class NArrayCreateFunction : public NFunction {
public:
    NArrayCreateFunction() : NFunction(CLoc::undefined, FT_Private, "", "array", make_shared<TemplateTypeNames>("item"), make_shared<NodeList>(
                                                                                                                                              make_shared<NAssignment>(CLoc::undefined, nullptr, "", "size", make_shared<NInteger>(CLoc::undefined, "0"), false),
                                                                                                                                              make_shared<NArrayGetFunction>(),
                                                                                                                                              make_shared<NArraySetFunction>()
                                                                                                                                              ), nullptr, nullptr) { }
    
    virtual shared_ptr<CType> getBlockType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction);
    virtual Value* call(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, shared_ptr<CFunction> callee, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters);
};


#endif /* NArray_h */
