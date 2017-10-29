//
//  NBase.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef NBase_h
#define NBase_h

void dumpf(stringstream& ss, int level);
const char* alloc_mode(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, shared_ptr<CVar> var);

#define bool_to_str(x) ((x) ? "true" : "false")

class NVariableBase;
class CBaseFunctionDefinition;
class CFunction;

enum ReturnValueType {
    RVT_SIMPLE,
    RVT_HEAP
};

enum ReturnValueRelease {
    RVR_MustRelease,
    RVR_MustRetain,
    RVR_Value
};

//bool isSimpleType(Type* type);

class ReturnValue {
public:
    shared_ptr<CBaseFunction> valueFunction;
    bool inEntry;
    ReturnValueRelease releaseMode;
    ReturnValueType type;
    //Value* value;
    
    //ReturnValue(bool inEntry, Value* value) : inEntry(inEntry), valueFunction(nullptr), releaseMode(RVR_Value), type(RVT_SIMPLE), value(value) {
    //    assert(value);
    //    assert(isSimpleType(value->getType()));
    //}
    
    //ReturnValue(shared_ptr<CBaseFunction> valueFunction, ReturnValueRelease releaseMode, ReturnValueType type, bool inEntry, Value* value) : inEntry(inEntry), valueFunction(valueFunction), releaseMode(releaseMode), type(type), value(value) {
    //    assert(value);
    //    if (isSimpleType(value->getType())) {
    //        this->type = RVT_SIMPLE;
    //        this->releaseMode = RVR_Value;
    //    } else {
    //        assert(releaseMode != RVR_Value);
    //        assert(valueFunction);
    //    }
    //}
    //
    //void retainIfNeeded(Compiler* compiler, CResult& result, IRBuilder<>* builder);
    //void releaseIfNeeded(Compiler* compiler, CResult& result, IRBuilder<>* builder);
};

class NBase : public enable_shared_from_this<NBase> {
public:
    const NodeType nodeType;
    const CLoc loc;
    
    NBase(const NodeType nodeType, const CLoc loc) : nodeType(nodeType), loc(loc), _hasDefined(false), _hasGetVar(false), _hasGetType(false) { }
    void define(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    shared_ptr<CVar> getVar(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
    shared_ptr<CType> getType(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
    int setHeapVar(Compiler *compiler, CResult &result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar);
    //shared_ptr<ReturnValue> compile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType);
    virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level = 0) = 0;
    
protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) = 0;
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) = 0;
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) = 0;
    virtual int setHeapVarImpl(Compiler *compiler, CResult &result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) = 0;
    //virtual shared_ptr<ReturnValue> compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) = 0;
    
private:
    bool _hasDefined;
    bool _hasGetVar;
    bool _hasGetType;
    shared_ptr<CVar> _var;
    shared_ptr<CType> _type;
    
    friend class NVariableBase;
};

#endif /* NBase_h */
