#include "Node.h"

NodeType NCompare::getNodeType() const {
    return NodeType_Compare;
}

void NCompare::define(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    leftSide->define(compiler, result, thisFunction);
    rightSide->define(compiler, result, thisFunction);
}

void NCompare::fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    leftSide->fixVar(compiler, result, thisFunction);
    rightSide->fixVar(compiler, result, thisFunction);
}

shared_ptr<CType> NCompare::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeBool;
}

Value* NCompare::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    Value *L = leftSide->compile(compiler, result, thisFunction, thisValue, builder);
    Value *R = rightSide->compile(compiler, result, thisFunction, thisValue, builder);
    if (!L || !R)
        return nullptr;
    
    if (L->getType() != R->getType()) {
        result.addError(loc, CErrorCode::TypeMismatch, "left and right values are not the same type");
        return nullptr;
    }
    
    if (L->getType()->isIntegerTy() && L->getType()->getScalarSizeInBits() == 64) {
        switch (op) {
            case NCompareOp::EQ:
                return builder->CreateICmpEQ(L, R, "eqtmp");
            case NCompareOp::NE:
                return builder->CreateICmpNE(L, R, "netmp");
            case NCompareOp::LT:
                return builder->CreateICmpSLT(L, R, "lttmp");
            case NCompareOp::LE:
                return builder->CreateICmpSLE(L, R, "letmp");
            case NCompareOp::GT:
                return builder->CreateICmpSGT(L, R, "gttmp");
            case NCompareOp::GE:
                return builder->CreateICmpSGE(L, R, "getmp");
            default:
                result.addError(loc, CErrorCode::Internal, "unknown comparison type");
                return nullptr;
        }
    } else if (L->getType()->isDoubleTy()) {
        switch (op) {
            case NCompareOp::EQ:
                return builder->CreateFCmpOEQ(L, R, "eqtmp");
            case NCompareOp::NE:
                return builder->CreateFCmpONE(L, R, "netmp");
            case NCompareOp::LT:
                return builder->CreateFCmpOLT(L, R, "lttmp");
            case NCompareOp::LE:
                return builder->CreateFCmpOLE(L, R, "letmp");
            case NCompareOp::GT:
                return builder->CreateFCmpOGT(L, R, "gttmp");
            case NCompareOp::GE:
                return builder->CreateFCmpOGE(L, R, "getmp");
            default:
                result.addError(loc, CErrorCode::Internal, "unknown comparison type");
                return nullptr;
        }
    } else {
        result.addError(loc, CErrorCode::InvalidType, "comparison is not supported on this type");
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
