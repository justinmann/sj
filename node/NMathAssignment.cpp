#include "Node.h"

NMathAssignment::NMathAssignment(CLoc loc, shared_ptr<NVariableBase> var, NMathAssignmentOp op, shared_ptr<NBase> rightSide) : var(var), op(op), rightSide(rightSide), NBase(NodeType_MathAssignment, loc) {
}

void NMathAssignment::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    if (rightSide) {
        rightSide->define(compiler, result, thisFunction);
    }
}

shared_ptr<CVar> NMathAssignment::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    if (rightSide) {
        rightSide->getVar(compiler, result, thisFunction);
    }
    return nullptr;
}

shared_ptr<CType> NMathAssignment::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    auto cvar = var->getVar(compiler, result, thisFunction, nullptr);
    auto ctype = cvar->getType(compiler, result);
    if (ctype != compiler->typeInt) {
        result.addError(loc, CErrorCode::TypeMismatch, "operation only valid on int");
        return nullptr;
    }
    return ctype;
}

int NMathAssignment::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, bool isHeapVar) {
    auto count = var->setHeapVar(compiler, result, thisFunction, nullptr, false);
    if (rightSide) {
        count += rightSide->setHeapVar(compiler, result, thisFunction, false);
    }
    return count;
}

Value* NMathAssignment::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    auto cvar = var->getVar(compiler, result, thisFunction, nullptr);
    if (!cvar) {
        return nullptr;
    }
    
    if (!cvar->isMutable) {
        result.addError(loc, CErrorCode::ImmutableAssignment, "invalid on immutable variable");
        return nullptr;
    }
    
    auto leftValue = cvar->getLoadValue(compiler, result, thisValue, thisValue, builder, catchBB);
    
    // Compute value
    Value *rightValue = nullptr;
    if (rightSide) {
        rightValue = rightSide->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    }

    Value* resultValue = nullptr;
    switch (op) {
        case NMAO_Add:
            if (!rightValue) {
                result.addError(loc, CErrorCode::ExpressionEmpty, "add by an empty value");
                return nullptr;
            }
            
            if (!rightValue->getType()->isIntegerTy(64)) {
                result.addError(loc, CErrorCode::TypeMismatch, "can only add by int");
                return nullptr;
            }
            
            resultValue = builder->CreateAdd(leftValue, rightValue);
            break;
        case NMAO_Sub:
            if (!rightValue) {
                result.addError(loc, CErrorCode::ExpressionEmpty, "add by an empty value");
                return nullptr;
            }
            
            if (!rightValue->getType()->isIntegerTy(64)) {
                result.addError(loc, CErrorCode::TypeMismatch, "can only add by int");
                return nullptr;
            }
            
            resultValue = builder->CreateSub(leftValue, rightValue);
            break;
        case NMAO_Inc:
            resultValue = builder->CreateAdd(leftValue, ConstantInt::get(compiler->context, APInt(64, 1)));
            break;
        case NMAO_Dec:
            resultValue = builder->CreateSub(leftValue, ConstantInt::get(compiler->context, APInt(64, 1)));
            break;
    }

    // Store value
    Value* destValue = cvar->getStoreValue(compiler, result, thisValue, thisValue, builder, catchBB);
    builder->CreateStore(resultValue, destValue);
    return resultValue;
}

void NMathAssignment::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NMathAssignment'");
    dumpf(level, "op: %d", op);
    
    if (rightSide) {
        dumpf(level, "rightSide: {");
        rightSide->dump(compiler, level + 1);
        dumpf(level, "}");
    }
}
