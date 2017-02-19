#include "Node.h"

void NCast::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NCast::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);
    node->getVar(compiler, result, thisFunction, thisVar);
    return nullptr;
}

shared_ptr<CType> NCast::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    auto t = compiler->getType(type.c_str());
    if (!t) {
        result.addError(loc, CErrorCode::InvalidType, "type does not exist");
    }
    return t;
}

int NCast::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    return node->setHeapVar(compiler, result, thisFunction, thisVar, false);
}

shared_ptr<ReturnValue> NCast::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(builder, this);
    
    auto v = node->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB);
    if (!v)
        return nullptr;
    
    assert(v->type == RVT_SIMPLE);
    
    auto fromType = node->getType(compiler, result, thisFunction, thisVar);
    auto toType = compiler->getType(type.c_str());
    
    if (!toType) {
        result.addError(loc, CErrorCode::InvalidType, "type does not exist");
    }

    if (fromType == toType) {
        return v;
    }
    
    if (fromType == compiler->typeInt && toType == compiler->typeFloat) {
        return make_shared<ReturnValue>(false, builder->CreateSIToFP(v->value, toType->llvmRefType(compiler, result)));
    }

    if (fromType == compiler->typeFloat && toType == compiler->typeInt) {
        return make_shared<ReturnValue>(false, builder->CreateFPToSI(v->value, toType->llvmRefType(compiler, result)));
    }
    
    result.addError(loc, CErrorCode::InvalidCast, "cannot cast");
    
    return NULL;
}

void NCast::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    node->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
    ss << " as " << type;
}
