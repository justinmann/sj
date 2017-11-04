#include "Node.h"

NMathAssignment::NMathAssignment(CLoc loc, shared_ptr<NVariableBase> var, NMathAssignmentOp op, shared_ptr<NBase> rightSide) : NBase(NodeType_MathAssignment, loc), var(var), op(op), rightSide(rightSide) {
}

void NMathAssignment::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    if (rightSide) {
        rightSide->define(compiler, result, thisFunction);
    }
}

shared_ptr<CVar> NMathAssignment::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);
    if (rightSide) {
        rightSide->getVar(compiler, result, thisFunction, thisVar);
    }
    return nullptr;
}

shared_ptr<CType> NMathAssignment::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    auto cvar = var->getVar(compiler, result, thisFunction, thisVar, nullptr);
    auto ctype = cvar->getType(compiler, result);
    if (ctype != compiler->typeI32 && ctype != compiler->typeI64 && ctype != compiler->typeU32 && ctype != compiler->typeU64) {
        result.addError(loc, CErrorCode::TypeMismatch, "operation only valid on int");
        return nullptr;
    }
    return ctype;
}

int NMathAssignment::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    auto count = var->setHeapVar(compiler, result, thisFunction, thisVar, nullptr, false);
    if (rightSide) {
        count += rightSide->setHeapVar(compiler, result, thisFunction, thisVar, false);
    }
    return count;
}

shared_ptr<ReturnValue> NMathAssignment::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, stringstream& trLine) {
	auto cvar = var->getVar(compiler, result, thisFunction, thisVar, nullptr);
	if (!cvar) {
		return nullptr;
	}
	    
	if (!cvar->isMutable) {
	    result.addError(loc, CErrorCode::ImmutableAssignment, "invalid on immutable variable");
		return nullptr;
	}

	auto leftType = var->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, trLine);

	switch (op) {
	case NMAO_Add:
		trLine << " += ";
		break;
	case NMAO_Sub:
		trLine << " -= ";
		break;
	case NMAO_Inc:
		trLine << "++";
		break;
	case NMAO_Dec:
		trLine << "--";
		break;
	}

	if (rightSide) {
		auto rightType = rightSide->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, trLine);
		if (leftType->type != rightType->type) {
			result.addError(loc, CErrorCode::TypeMismatch, "left and right values are not the same type");
			return nullptr;
		}
	}

	return leftType;
}

//shared_ptr<ReturnValue> NMathAssignment::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    assert(compiler->state == CompilerState::Compile);
//    compiler->emitLocation(builder, &this->loc);
//    
//    auto cvar = var->getVar(compiler, result, thisFunction, thisVar, nullptr);
//    if (!cvar) {
//        return nullptr;
//    }
//    
//    if (!cvar->isMutable) {
//        result.addError(loc, CErrorCode::ImmutableAssignment, "invalid on immutable variable");
//        return nullptr;
//    }
//    
//    auto leftValue = cvar->getLoadValue(compiler, result, thisVar, thisValue, true, thisValue, builder, catchBB, RRT_Auto);
//    
//    // Compute value
//    shared_ptr<ReturnValue> rightValue = nullptr;
//    if (rightSide) {
//        rightValue = rightSide->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, RRT_Auto);
//    }
//
//    Value* resultValue = nullptr;
//    switch (op) {
//        case NMAO_Add:
//            if (!rightValue) {
//                result.addError(loc, CErrorCode::ExpressionEmpty, "add by an empty value");
//                return nullptr;
//            }
//            
//            if (!rightValue->value->getType()->isIntegerTy(64)) {
//                result.addError(loc, CErrorCode::TypeMismatch, "can only add by int");
//                return nullptr;
//            }
//            
//            resultValue = builder->CreateAdd(leftValue->value, rightValue->value);
//            break;
//        case NMAO_Sub:
//            if (!rightValue) {
//                result.addError(loc, CErrorCode::ExpressionEmpty, "add by an empty value");
//                return nullptr;
//            }
//            
//            if (!rightValue->value->getType()->isIntegerTy(64)) {
//                result.addError(loc, CErrorCode::TypeMismatch, "can only add by int");
//                return nullptr;
//            }
//            
//            resultValue = builder->CreateSub(leftValue->value, rightValue->value);
//            break;
//        case NMAO_Inc:
//            resultValue = builder->CreateAdd(leftValue->value, ConstantInt::get(compiler->context, APInt(64, 1)));
//            break;
//        case NMAO_Dec:
//            resultValue = builder->CreateSub(leftValue->value, ConstantInt::get(compiler->context, APInt(64, 1)));
//            break;
//    }
//    
//    leftValue->releaseIfNeeded(compiler, result, builder);
//    if (rightValue) {
//        rightValue->releaseIfNeeded(compiler, result, builder);
//    }
//
//    // Store value
//    Value* destValue = cvar->getStoreValue(compiler, result, thisVar, thisValue, true, thisValue, builder, catchBB);
//    builder->CreateStore(resultValue, destValue);
//    return make_shared<ReturnValue>(false, resultValue);
//}

void NMathAssignment::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    var->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
    
    switch (op) {
        case NMAO_Add:
            ss << " += ";
            break;
        case NMAO_Sub:
            ss << " -= ";
            break;
        case NMAO_Inc:
            ss << "++";
            break;
        case NMAO_Dec:
            ss << "--";
            break;
    }
    
    if (rightSide) {
        rightSide->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
    }
}
