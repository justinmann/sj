#include "Node.h"

NodeType NCompare::getNodeType() const {
    return NodeType_Compare;
}

void NCompare::define(Compiler* compiler, CResult& result) {
    assert(compiler->state == CompilerState::Define);
    leftSide->define(compiler, result);
    rightSide->define(compiler, result);
}

void NCompare::fixVar(Compiler* compiler, CResult& result) {
    assert(compiler->state == CompilerState::FixVar);
    leftSide->fixVar(compiler, result);
    rightSide->fixVar(compiler, result);
}

shared_ptr<CType> NCompare::getReturnType(Compiler* compiler, CResult& result) const {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeBool;
}

Value* NCompare::compile(Compiler* compiler, CResult& result) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    Value *L = leftSide->compile(compiler, result);
    Value *R = rightSide->compile(compiler, result);
    if (!L || !R)
        return nullptr;
    
    if (L->getType() != R->getType()) {
        result.errors.push_back(CError(loc, CErrorCode::TypeMismatch, "left and right values are not the same type"));
        return nullptr;
    }
    
    if (L->getType()->isIntegerTy() && L->getType()->getScalarSizeInBits() == 64) {
        switch (op) {
            case NCompareOp::EQ:
                return compiler->builder.CreateICmpEQ(L, R, "eqtmp");
            case NCompareOp::NE:
                return compiler->builder.CreateICmpNE(L, R, "netmp");
            case NCompareOp::LT:
                return compiler->builder.CreateICmpSLT(L, R, "lttmp");
            case NCompareOp::LE:
                return compiler->builder.CreateICmpSLE(L, R, "letmp");
            case NCompareOp::GT:
                return compiler->builder.CreateICmpSGT(L, R, "gttmp");
            case NCompareOp::GE:
                return compiler->builder.CreateICmpSGE(L, R, "getmp");
            default:
                result.errors.push_back(CError(loc, CErrorCode::Internal, "unknown comparison type"));
                return nullptr;
        }
    } else if (L->getType()->isDoubleTy()) {
        switch (op) {
            case NCompareOp::EQ:
                return compiler->builder.CreateFCmpOEQ(L, R, "eqtmp");
            case NCompareOp::NE:
                return compiler->builder.CreateFCmpONE(L, R, "netmp");
            case NCompareOp::LT:
                return compiler->builder.CreateFCmpOLT(L, R, "lttmp");
            case NCompareOp::LE:
                return compiler->builder.CreateFCmpOLE(L, R, "letmp");
            case NCompareOp::GT:
                return compiler->builder.CreateFCmpOGT(L, R, "gttmp");
            case NCompareOp::GE:
                return compiler->builder.CreateFCmpOGE(L, R, "getmp");
            default:
                result.errors.push_back(CError(loc, CErrorCode::Internal, "unknown comparison type"));
                return nullptr;
        }
    } else {
        result.errors.push_back(CError(loc, CErrorCode::InvalidType, "comparison is not supported on this type"));
    }
    
    return NULL;
}

void NCompare::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NCompare'");
    dumpf(level, "op: %d", op);
    
    dumpf(level, "leftSide: {");
    leftSide->dump(compiler, level + 1);
    dumpf(level, "}");
    
    dumpf(level, "rightSide: {");
    rightSide->dump(compiler, level + 1);
    dumpf(level, "}");
}
