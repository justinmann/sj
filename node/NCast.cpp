#include "Node.h"
#include "parser.hpp"

NodeType NCast::getNodeType() const {
    return NodeType_Cast;
}

void NCast::define(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result, thisFunction);
}

void NCast::fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    node->fixVar(compiler, result, thisFunction);
}

shared_ptr<CType> NCast::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    auto t = compiler->getType(type.c_str());
    if (!t) {
        result.addError(loc, CErrorCode::InvalidType, "type does not exist");
    }
    return t;
}

Value* NCast::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    Value *v = node->compile(compiler, result, thisFunction, thisValue, builder);
    if (!v)
        return nullptr;
    
    auto fromType = node->getReturnType(compiler, result, thisFunction);
    auto toType = compiler->getType(type.c_str());
    
    if (!toType) {
        result.addError(loc, CErrorCode::InvalidType, "type does not exist");
    }

    if (fromType == toType) {
        return v;
    }
    
    if (fromType == compiler->typeInt && toType == compiler->typeFloat) {
        return builder->CreateSIToFP(v, toType->llvmRefType(compiler, result));
    }

    if (fromType == compiler->typeFloat && toType == compiler->typeInt) {
        return builder->CreateFPToSI(v, toType->llvmRefType(compiler, result));
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
