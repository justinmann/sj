#include "Node.h"

void dumpf(stringstream& ss, int level) {
    for (int i = 0; i < level; i++) {
        ss << "  ";
    }
}

const char* alloc_mode(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, shared_ptr<CVar> var) {
    if (var == nullptr) {
        return "";
    } else if (var->getHeapVar(compiler, result, thisVar)) {
        return "[heap]";
    } else {
        return "[stack]";
    }
}

//bool isSimpleType(Type* type) {
//    if (!type->isPointerTy()) {
//        return true;
//    }
//    
//    auto elemType = type->getPointerElementType();
//    if (elemType->isStructTy()) {
//        return false;
//    }
//    
//    return true;
//}

//void ReturnValue::retainIfNeeded(Compiler* compiler, CResult& result, IRBuilder<>* builder) {
//    if (releaseMode == RVR_MustRetain) {
//        valueFunction->retainHeap(compiler, result, builder, value);
//    }
//}
//
//void ReturnValue::releaseIfNeeded(Compiler* compiler, CResult& result, IRBuilder<>* builder) {
//    if (releaseMode == RVR_MustRelease) {
//        valueFunction->releaseHeap(compiler, result, builder, value);
//    }
//}

void NBase::define(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    if (!_hasDefined) {
        _hasDefined = true;
        defineImpl(compiler, result, thisFunction);
    }
}

shared_ptr<CVar> NBase::getVar(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    if (!_hasGetVar) {
        assert(compiler->state == CompilerState::FixVar);
        _var = getVarImpl(compiler, result, thisFunction, thisVar);
        _hasGetVar = true;
    }
    return _var;
}

shared_ptr<CType> NBase::getType(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    if (!_hasGetType) {
        _type = getTypeImpl(compiler, result, thisFunction, thisVar);
        _hasGetType = true;
    }
    return _type;
}

int NBase::setHeapVar(Compiler *compiler, CResult &result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    return setHeapVarImpl(compiler, result, thisFunction, thisVar, isHeapVar);
}

//shared_ptr<ReturnValue> NBase::compile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    assert(compiler->state == CompilerState::Compile);
//    return compileImpl(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, returnRefType);
//}

