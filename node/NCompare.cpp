#include "Node.h"

void NCompare::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    leftSide->define(compiler, result, thisFunction);
    rightSide->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NCompare::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    leftSide->getVar(compiler, result, thisFunction);
    rightSide->getVar(compiler, result, thisFunction);
    return nullptr;
}

shared_ptr<CType> NCompare::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeBool;
}

Value* NCompare::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    Value *L = leftSide->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    Value *R = rightSide->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    if (!L || !R)
        return nullptr;
    
    if (L->getType() != R->getType()) {
        result.addError(loc, CErrorCode::TypeMismatch, "left type '%s' does not match right type '%s'", Type_print(L->getType()).c_str(), Type_print(R->getType()).c_str());
        return nullptr;
    }
    
    if ((L->getType()->isIntegerTy(64) || L->getType()->isIntegerTy(8)) && L->getType()->getScalarSizeInBits() == R->getType()->getScalarSizeInBits()) {
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
