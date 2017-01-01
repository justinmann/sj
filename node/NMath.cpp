#include "Node.h"

NodeType NMath::getNodeType() const {
    return NodeType_Math;
}

void NMath::define(Compiler* compiler, CResult& result) {
    leftSide->define(compiler, result);
    rightSide->define(compiler, result);
}

shared_ptr<CType> NMath::getReturnType(Compiler* compiler, CResult& result) const {
    return leftSide->getReturnType(compiler, result);
}

Value* NMath::compile(Compiler* compiler, CResult& result) const {
    compiler->emitLocation(this);
    
    Value *L = leftSide->compile(compiler, result);
    Value *R = rightSide->compile(compiler, result);
    if (!L || !R)
        return nullptr;
    
    if (L->getType() != R->getType()) {
        result.errors.push_back(CError(loc, CErrorCode::TypeMismatch, "left and right values are not the same type"));
        return nullptr;
    }
    
    if (L->getType() == compiler->typeInt->llvmRefType) {
        switch (op) {
            case NMathOp::Add:
                return compiler->builder.CreateAdd(L, R, "addtmp");
            case NMathOp::Sub:
                return compiler->builder.CreateSub(L, R, "subtmp");
            case NMathOp::Mul:
                return compiler->builder.CreateMul(L, R, "multmp");
            case NMathOp::Div:
                return compiler->builder.CreateSDiv(L, R, "divtmp");
            default:
                result.errors.push_back(CError(loc, CErrorCode::Internal, "unknown math type"));
                return nullptr;
        }
    } else if (L->getType() == compiler->typeFloat->llvmRefType) {
        switch (op) {
            case NMathOp::Add:
                return compiler->builder.CreateFAdd(L, R, "addtmp");
            case NMathOp::Sub:
                return compiler->builder.CreateFSub(L, R, "subtmp");
            case NMathOp::Mul:
                return compiler->builder.CreateFMul(L, R, "multmp");
            case NMathOp::Div:
                return compiler->builder.CreateFDiv(L, R, "divtmp");
            default:
                result.errors.push_back(CError(loc, CErrorCode::Internal, "unknown math type"));
                return nullptr;
        }
    } else {
        result.errors.push_back(CError(loc, CErrorCode::InvalidType, "math operations are not supported on this type"));
    }
    
    return NULL;
}
