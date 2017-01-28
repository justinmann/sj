#include "Node.h"

void NMath::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    leftSide->define(compiler, result, thisFunction);
    rightSide->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NMath::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    leftSide->getVar(compiler, result, thisFunction);
    rightSide->getVar(compiler, result, thisFunction);
    return nullptr;
}

shared_ptr<CType> NMath::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    return leftSide->getType(compiler, result, thisFunction);
}

int NMath::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, bool isHeapVar) {
    auto count = leftSide->setHeapVar(compiler, result, thisFunction, false);
    count += rightSide->setHeapVar(compiler, result, thisFunction, false);
    return count;
}

Value* NMath::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, bool isReturnRetained) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    Value *L = leftSide->compile(compiler, result, thisFunction, thisValue, builder, catchBB, false);
    Value *R = rightSide->compile(compiler, result, thisFunction, thisValue, builder, catchBB, false);
    if (!L || !R)
        return nullptr;
    
    if (L->getType() != R->getType()) {
        result.addError(loc, CErrorCode::TypeMismatch, "left and right values are not the same type");
        return nullptr;
    }
    
    if (L->getType()->isIntegerTy()) {
        switch (op) {
            case NMathOp::Add:
                return builder->CreateAdd(L, R, "addtmp");
            case NMathOp::Sub:
                return builder->CreateSub(L, R, "subtmp");
            case NMathOp::Mul:
                return builder->CreateMul(L, R, "multmp");
            case NMathOp::Div:
                return builder->CreateSDiv(L, R, "divtmp");
            default:
                result.addError(loc, CErrorCode::Internal, "unknown math type");
                return nullptr;
        }
    } else if (L->getType()->isDoubleTy()) {
        switch (op) {
            case NMathOp::Add:
                return builder->CreateFAdd(L, R, "addtmp");
            case NMathOp::Sub:
                return builder->CreateFSub(L, R, "subtmp");
            case NMathOp::Mul:
                return builder->CreateFMul(L, R, "multmp");
            case NMathOp::Div:
                return builder->CreateFDiv(L, R, "divtmp");
            default:
                result.addError(loc, CErrorCode::Internal, "unknown math type");
                return nullptr;
        }
    } else {
        result.addError(loc, CErrorCode::InvalidType, "math operations are not supported on this type");
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
