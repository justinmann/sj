#include "Node.h"

void NMath::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    leftSide->define(compiler, result, thisFunction);
    rightSide->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NMath::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);
    leftSide->getVar(compiler, result, thisFunction, thisVar);
    rightSide->getVar(compiler, result, thisFunction, thisVar);
    return nullptr;
}

shared_ptr<CType> NMath::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return leftSide->getType(compiler, result, thisFunction, thisVar);
}

int NMath::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    auto count = leftSide->setHeapVar(compiler, result, thisFunction, thisVar, false);
    count += rightSide->setHeapVar(compiler, result, thisFunction, thisVar, false);
    return count;
}

//shared_ptr<ReturnValue> NMath::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    assert(compiler->state == CompilerState::Compile);
//    compiler->emitLocation(builder, &this->loc);
//    
//    auto L = leftSide->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, RRT_Auto);
//    auto R = rightSide->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, RRT_Auto);
//    if (!L || !R)
//        return nullptr;
//    
//    if (L->value->getType() != R->value->getType()) {
//        result.addError(loc, CErrorCode::TypeMismatch, "left and right values are not the same type");
//        return nullptr;
//    }
//    
//    assert(L->type == RVT_SIMPLE);
//    assert(R->type == RVT_SIMPLE);
//    
//    if (L->value->getType()->isIntegerTy()) {
//        switch (op) {
//            case NMathOp::Add:
//                return make_shared<ReturnValue>(false, builder->CreateAdd(L->value, R->value, "addtmp"));
//            case NMathOp::Sub:
//                return make_shared<ReturnValue>(false, builder->CreateSub(L->value, R->value, "subtmp"));
//            case NMathOp::Mul:
//                return make_shared<ReturnValue>(false, builder->CreateMul(L->value, R->value, "multmp"));
//            case NMathOp::Div:
//                return make_shared<ReturnValue>(false, builder->CreateSDiv(L->value, R->value, "divtmp"));
//            case NMathOp::Mod:
//                return make_shared<ReturnValue>(false, builder->CreateSRem(L->value, R->value, "modetmp"));
//            default:
//                result.addError(loc, CErrorCode::Internal, "unknown math type");
//                return nullptr;
//        }
//    } else if (L->value->getType()->isDoubleTy()) {
//        switch (op) {
//            case NMathOp::Add:
//                return make_shared<ReturnValue>(false, builder->CreateFAdd(L->value, R->value, "addtmp"));
//            case NMathOp::Sub:
//                return make_shared<ReturnValue>(false, builder->CreateFSub(L->value, R->value, "subtmp"));
//            case NMathOp::Mul:
//                return make_shared<ReturnValue>(false, builder->CreateFMul(L->value, R->value, "multmp"));
//            case NMathOp::Div:
//                return make_shared<ReturnValue>(false, builder->CreateFDiv(L->value, R->value, "divtmp"));
//            case NMathOp::Mod:
//                result.addError(loc, CErrorCode::InvalidType, "mod operation are not supported on this type");
//                return nullptr;
//            default:
//                result.addError(loc, CErrorCode::Internal, "unknown math type");
//                return nullptr;
//        }
//    } else {
//        result.addError(loc, CErrorCode::InvalidType, "math operations are not supported on this type");
//    }
//    
//    return NULL;
//}

shared_ptr<ReturnValue> NMath::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, stringstream& trLine) {
	trLine << "(";
	auto leftType = leftSide->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, trLine);
	trLine << ")";
	switch (op) {
	case NMathOp::Add:
		trLine << " + ";
		break;
	case NMathOp::Sub:
		trLine << " - ";
		break;
	case NMathOp::Mul:
		trLine << " * ";
		break;
	case NMathOp::Div:
		trLine << " / ";
		break;
	case NMathOp::Mod:
		trLine << " %% ";
		break;
	}
	trLine << "(";
	auto rightType = rightSide->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, trLine);
	trLine << ")";

	if (leftType->type != rightType->type) {
		result.addError(loc, CErrorCode::TypeMismatch, "left and right values are not the same type");
		return nullptr;
	}
	
	return leftType;
}

void NMath::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
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
