#include "Node.h"

void NMath::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    leftSide->define(compiler, result, thisFunction);
    rightSide->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NMath::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);
    leftSide->getVar(compiler, result, thisFunction, thisVar);
    rightSide->getVar(compiler, result, thisFunction, thisVar);
    return nullptr;
}

shared_ptr<CType> NMath::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return leftSide->getType(compiler, result, thisFunction, thisVar);
}

int NMath::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    auto count = leftSide->setHeapVar(compiler, result, thisFunction, thisVar, false);
    count += rightSide->setHeapVar(compiler, result, thisFunction, thisVar, false);
    return count;
}

shared_ptr<ReturnValue> NMath::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(builder, this);
    
    auto L = leftSide->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB);
    auto R = rightSide->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB);
    if (!L || !R)
        return nullptr;
    
    if (L->value->getType() != R->value->getType()) {
        result.addError(loc, CErrorCode::TypeMismatch, "left and right values are not the same type");
        return nullptr;
    }
    
    assert(L->type == RVT_SIMPLE);
    assert(R->type == RVT_SIMPLE);
    
    if (L->value->getType()->isIntegerTy()) {
        switch (op) {
            case NMathOp::Add:
                return make_shared<ReturnValue>(builder->CreateAdd(L->value, R->value, "addtmp"));
            case NMathOp::Sub:
                return make_shared<ReturnValue>(builder->CreateSub(L->value, R->value, "subtmp"));
            case NMathOp::Mul:
                return make_shared<ReturnValue>(builder->CreateMul(L->value, R->value, "multmp"));
            case NMathOp::Div:
                return make_shared<ReturnValue>(builder->CreateSDiv(L->value, R->value, "divtmp"));
            case NMathOp::Mod:
                return make_shared<ReturnValue>(builder->CreateSRem(L->value, R->value, "modetmp"));
            default:
                result.addError(loc, CErrorCode::Internal, "unknown math type");
                return nullptr;
        }
    } else if (L->value->getType()->isDoubleTy()) {
        switch (op) {
            case NMathOp::Add:
                return make_shared<ReturnValue>(builder->CreateFAdd(L->value, R->value, "addtmp"));
            case NMathOp::Sub:
                return make_shared<ReturnValue>(builder->CreateFSub(L->value, R->value, "subtmp"));
            case NMathOp::Mul:
                return make_shared<ReturnValue>(builder->CreateFMul(L->value, R->value, "multmp"));
            case NMathOp::Div:
                return make_shared<ReturnValue>(builder->CreateFDiv(L->value, R->value, "divtmp"));
            case NMathOp::Mod:
                result.addError(loc, CErrorCode::InvalidType, "mod operation are not supported on this type");
                return nullptr;
            default:
                result.addError(loc, CErrorCode::Internal, "unknown math type");
                return nullptr;
        }
    } else {
        result.addError(loc, CErrorCode::InvalidType, "math operations are not supported on this type");
    }
    
    return NULL;
}

void NMath::dump(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CFunction>, string>& functions, stringstream& ss, int level) {
    leftSide->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
    
    switch (op) {
        case NMathOp::Add:
            ss << " + ";
            break;
        case NMathOp::Sub:
            ss << " - ";
            break;
        case NMathOp::Mul:
            ss << " * ";
            break;
        case NMathOp::Div:
            ss << " / ";
            break;
        case NMathOp::Mod:
            ss << " %% ";
            break;
    }
    
    rightSide->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
}
