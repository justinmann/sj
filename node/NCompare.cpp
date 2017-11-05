#include "Node.h"

void NCompare::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    leftSide->define(compiler, result, thisFunction);
    rightSide->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NCompare::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);
    leftSide->getVar(compiler, result, thisFunction, thisVar);
    rightSide->getVar(compiler, result, thisFunction, thisVar);
    return nullptr;
}

shared_ptr<CType> NCompare::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeBool;
}

int NCompare::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    auto count = leftSide->setHeapVar(compiler, result, thisFunction, thisVar, false);
    count += rightSide->setHeapVar(compiler, result, thisFunction, thisVar, false);
    return count;
}

//shared_ptr<ReturnValue> NCompare::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    assert(compiler->state == CompilerState::Compile);
//    compiler->emitLocation(builder, &this->loc);
//    
//    auto L = leftSide->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, RRT_Auto);
//    auto R = rightSide->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, RRT_Auto);
//    if (!L || !R)
//        return nullptr;
//    
//    assert(L->type == RVT_SIMPLE);
//    assert(R->type == RVT_SIMPLE);
//    
//    if (L->value->getType() != R->value->getType()) {
//        result.addError(loc, CErrorCode::TypeMismatch, "left type '%s' does not match right type '%s'", Type_print(L->value->getType()).c_str(), Type_print(R->value->getType()).c_str());
//        return nullptr;
//    }
//    
//    if ((L->value->getType()->isIntegerTy(64) || L->value->getType()->isIntegerTy(8)) && L->value->getType()->getScalarSizeInBits() == R->value->getType()->getScalarSizeInBits()) {
//        switch (op) {
//            case NCompareOp::EQ:
//                return make_shared<ReturnValue>(false, builder->CreateICmpEQ(L->value, R->value, "eqtmp"));
//            case NCompareOp::NE:
//                return make_shared<ReturnValue>(false, builder->CreateICmpNE(L->value, R->value, "netmp"));
//            case NCompareOp::LT:
//                return make_shared<ReturnValue>(false, builder->CreateICmpSLT(L->value, R->value, "lttmp"));
//            case NCompareOp::LE:
//                return make_shared<ReturnValue>(false, builder->CreateICmpSLE(L->value, R->value, "letmp"));
//            case NCompareOp::GT:
//                return make_shared<ReturnValue>(false, builder->CreateICmpSGT(L->value, R->value, "gttmp"));
//            case NCompareOp::GE:
//                return make_shared<ReturnValue>(false, builder->CreateICmpSGE(L->value, R->value, "getmp"));
//            default:
//                result.addError(loc, CErrorCode::Internal, "unknown comparison type");
//                return nullptr;
//        }
//    } else if (L->value->getType()->isDoubleTy()) {
//        switch (op) {
//            case NCompareOp::EQ:
//                return make_shared<ReturnValue>(false, builder->CreateFCmpOEQ(L->value, R->value, "eqtmp"));
//            case NCompareOp::NE:
//                return make_shared<ReturnValue>(false, builder->CreateFCmpONE(L->value, R->value, "netmp"));
//            case NCompareOp::LT:
//                return make_shared<ReturnValue>(false, builder->CreateFCmpOLT(L->value, R->value, "lttmp"));
//            case NCompareOp::LE:
//                return make_shared<ReturnValue>(false, builder->CreateFCmpOLE(L->value, R->value, "letmp"));
//            case NCompareOp::GT:
//                return make_shared<ReturnValue>(false, builder->CreateFCmpOGT(L->value, R->value, "gttmp"));
//            case NCompareOp::GE:
//                return make_shared<ReturnValue>(false, builder->CreateFCmpOGE(L->value, R->value, "getmp"));
//            default:
//                result.addError(loc, CErrorCode::Internal, "unknown comparison type");
//                return nullptr;
//        }
//    } else {
//        result.addError(loc, CErrorCode::InvalidType, "comparison is not supported on this type");
//    }
//    
//    return nullptr;
//}

shared_ptr<ReturnValue> NCompare::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue) {
    auto leftValue = leftSide->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, false);
    auto rightValue = rightSide->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, false);

    if (!leftValue || !rightValue) {
        assert(false);
        return nullptr;
    }

    auto resultValue = trBlock->createTempVariable("result", compiler->typeBool, false, RVR_MustRetain);
    stringstream line;
    line << resultValue->name << " = " << leftValue->name;
	switch (op) {
	case NCompareOp::EQ:
        line << " == ";
		break;
	case NCompareOp::NE:
        line << " != ";
		break;
	case NCompareOp::LT:
        line << " < ";
		break;
	case NCompareOp::LE:
        line << " <= ";
		break;
	case NCompareOp::GT:
        line << " > ";
		break;
	case NCompareOp::GE:
        line << " >= ";
		break;
	}
    line << rightValue->name;
    trBlock->statements.push_back(line.str());

	return resultValue;
}

void NCompare::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    leftSide->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
    switch (op) {
        case NCompareOp::EQ:
            ss << " == ";
            break;
        case NCompareOp::NE:
            ss << " != ";
            break;
        case NCompareOp::LT:
            ss << " < ";
            break;
        case NCompareOp::LE:
            ss << " <= ";
            break;
        case NCompareOp::GT:
            ss << " > ";
            break;
        case NCompareOp::GE:
            ss << " >= ";
            break;
    }
    rightSide->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
}
