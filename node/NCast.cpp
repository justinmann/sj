#include "Node.h"

void NCast::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NCast::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    node->getVar(compiler, result, thisFunction);
    return nullptr;
}

shared_ptr<CType> NCast::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    auto t = compiler->getType(type.c_str());
    if (!t) {
        result.addError(loc, CErrorCode::InvalidType, "type does not exist");
    }
    return t;
}

int NCast::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, bool isHeapVar) {
    return node->setHeapVar(compiler, result, thisFunction, false);
}

shared_ptr<ReturnValue> NCast::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    auto v = node->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    if (!v)
        return nullptr;
    
    assert(v->type == RVT_SIMPLE);
    
    auto fromType = node->getType(compiler, result, thisFunction);
    auto toType = compiler->getType(type.c_str());
    
    if (!toType) {
        result.addError(loc, CErrorCode::InvalidType, "type does not exist");
    }

    if (fromType == toType) {
        return v;
    }
    
    if (fromType == compiler->typeInt && toType == compiler->typeFloat) {
        return make_shared<ReturnValue>(builder->CreateSIToFP(v->value, toType->llvmRefType(compiler, result)));
    }

    if (fromType == compiler->typeFloat && toType == compiler->typeInt) {
        return make_shared<ReturnValue>(builder->CreateFPToSI(v->value, toType->llvmRefType(compiler, result)));
    }
    
    result.addError(loc, CErrorCode::InvalidCast, "cannot cast");
    
    return NULL;
}

void NCast::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NCast'");
    dumpf(level, "typeName: '%s'", type.c_str());
    dumpf(level, "node: {");
    node->dump(compiler, level + 1);
    dumpf(level, "}", type.c_str());
}
