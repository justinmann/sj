#include "Node.h"

NodeType NMath::getNodeType() const {
    return NodeType_Math;
}

void NMath::define(Compiler* compiler, CResult& result) {
    assert(compiler->state == CompilerState::Define);
    leftSide->define(compiler, result);
    rightSide->define(compiler, result);
}

void NMath::fixVar(Compiler* compiler, CResult& result) {
    assert(compiler->state == CompilerState::FixVar);
    leftSide->fixVar(compiler, result);
    rightSide->fixVar(compiler, result);
}

shared_ptr<CType> NMath::getReturnType(Compiler* compiler, CResult& result) const {
    assert(compiler->state >= CompilerState::FixVar);
    return leftSide->getReturnType(compiler, result);
}

Value* NMath::compile(Compiler* compiler, CResult& result) const {
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
    
    if (L->getType()->isIntegerTy()) {
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
    } else if (L->getType()->isDoubleTy()) {
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

void NMath::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NMath'");
    dumpf(level, "op: %d", op);
    
    dumpf(level, "leftSide: {");
    leftSide->dump(compiler, level + 1);
    dumpf(level, "}");
    
    dumpf(level, "rightSide: {");
    rightSide->dump(compiler, level + 1);
    dumpf(level, "}");
}
