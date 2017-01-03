#include "Node.h"
#include "parser.hpp"

NodeType NCast::getNodeType() const {
    return NodeType_Cast;
}

void NCast::define(Compiler* compiler, CResult& result) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result);
}

void NCast::fixVar(Compiler* compiler, CResult& result) {
    assert(compiler->state == CompilerState::FixVar);
    node->fixVar(compiler, result);
}

shared_ptr<CType> NCast::getReturnType(Compiler* compiler, CResult& result) const {
    assert(compiler->state >= CompilerState::FixVar);
    auto t = compiler->getType(type.c_str());
    if (!t) {
        result.errors.push_back(CError(loc, CErrorCode::InvalidType, "type does not exist"));
    }
    return t;
}

Value* NCast::compile(Compiler* compiler, CResult& result) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    Value *v = node->compile(compiler, result);
    if (!v)
        return nullptr;
    
    auto fromType = node->getReturnType(compiler, result);
    auto toType = compiler->getType(type.c_str());
    
    if (!toType) {
        result.errors.push_back(CError(loc, CErrorCode::InvalidType, "type does not exist"));
    }

    if (fromType == toType) {
        return v;
    }
    
    if (fromType == compiler->typeInt && toType == compiler->typeFloat) {
        return compiler->builder.CreateSIToFP(v, toType->llvmRefType(compiler, result));
    }

    if (fromType == compiler->typeFloat && toType == compiler->typeInt) {
        return compiler->builder.CreateFPToSI(v, toType->llvmRefType(compiler, result));
    }
    
    result.errors.push_back(CError(loc, CErrorCode::InvalidCast, "cannot cast"));
    
    return NULL;
}
