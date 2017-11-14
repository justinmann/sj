#include "Node.h"

NMathAssignment::NMathAssignment(CLoc loc, shared_ptr<NVariableBase> leftSide, NMathAssignmentOp op, shared_ptr<NVariableBase> rightSide) : NBase(NodeType_MathAssignment, loc), op(op), leftSide(leftSide), rightSide(rightSide) {
}

void NMathAssignment::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    if (rightSide) {
        rightSide->define(compiler, result, thisFunction);
    }
}

shared_ptr<CVar> NMathAssignment::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);
    auto leftVar = leftSide->getVar(compiler, result, thisFunction, thisVar, nullptr);

    if (!leftVar) {
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler, result);
    if (!leftType) {
        return nullptr;
    }

    if (rightSide) {
        auto rightVar = rightSide->getVar(compiler, result, thisFunction, thisVar, nullptr);
        if (!rightVar) {
            return nullptr;
        }

        auto rightType = rightVar->getType(compiler, result);
        if (!rightType) {
            return nullptr;
        }

        if (leftType != rightType) {
            result.addError(loc, CErrorCode::TypeMismatch, "left type '%s' does not match right type '%s'", leftType->name.c_str(), rightType->name.c_str());
            return nullptr;
        }
    }

    // Check to see if we have operator overloading
    if (!leftType->parent.expired()) {
        switch (op) {
        case NMathAssignmentOp::NMAO_Inc:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "increment", nullptr, nullptr));
            return operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar);
            break;
        case NMathAssignmentOp::NMAO_Dec:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "decrement", nullptr, nullptr));
            return operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar);
            break;
        case NMathAssignmentOp::NMAO_Add:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "add", nullptr, make_shared<NodeList>(rightSide)));
            return operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar);
            break;
        case NMathAssignmentOp::NMAO_Sub:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "subtract", nullptr, make_shared<NodeList>(rightSide)));
            return operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar);
            break;
        case NMathAssignmentOp::NMAO_Mul:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "multiply", nullptr, make_shared<NodeList>(rightSide)));
            return operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar);
            break;
        case NMathAssignmentOp::NMAO_Div:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "divide", nullptr, make_shared<NodeList>(rightSide)));
            return operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar);
            break;
        }
    }

    return nullptr;
}

shared_ptr<CType> NMathAssignment::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    if (operatorOverloadNode) {
        return operatorOverloadNode->getType(compiler, result, thisFunction, thisVar);
    }
    else {
        auto cvar = leftSide->getVar(compiler, result, thisFunction, thisVar, nullptr);
        auto ctype = cvar->getType(compiler, result);
        if (ctype != compiler->typeI32 && ctype != compiler->typeI64 && ctype != compiler->typeU32 && ctype != compiler->typeU64) {
            result.addError(loc, CErrorCode::TypeMismatch, "operation only valid on int");
            return nullptr;
        }
        return ctype;
    }
}

int NMathAssignment::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    if (operatorOverloadNode) {
        return operatorOverloadNode->setHeapVar(compiler, result, thisFunction, thisVar, false);
    }
    else {
        auto count = leftSide->setHeapVar(compiler, result, thisFunction, thisVar, nullptr, false);
        if (rightSide) {
            count += rightSide->setHeapVar(compiler, result, thisFunction, thisVar, nullptr, false);
        }
        return count;
    }
}

shared_ptr<ReturnValue> NMathAssignment::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue) {
    shared_ptr<ReturnValue> mathReturnValue;
    if (operatorOverloadNode) {
        mathReturnValue = operatorOverloadNode->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, isReturnValue);
    }
    else {
        auto cvar = leftSide->getVar(compiler, result, thisFunction, thisVar, nullptr);
        if (!cvar) {
            return nullptr;
        }

        if (!cvar->isMutable) {
            result.addError(loc, CErrorCode::ImmutableAssignment, "invalid on immutable variable");
            return nullptr;
        }

        shared_ptr<ReturnValue> leftReturn = leftSide->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, false);
        shared_ptr<ReturnValue> rightReturn;
        if (rightSide) {
            rightReturn = rightSide->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, false);
            if (leftReturn->type != rightReturn->type) {
                result.addError(loc, CErrorCode::TypeMismatch, "left and right values are not the same type");
                return nullptr;
            }
        }

        mathReturnValue = trBlock->createTempVariable("result", leftReturn->type, false, RVR_MustRetain);

        stringstream lineStream;
        switch (op) {
        case NMAO_Add:
            lineStream << mathReturnValue->name << " = " << leftReturn->name << " + " << rightReturn->name;
            break;
        case NMAO_Sub:
            lineStream << mathReturnValue->name << " = " << leftReturn->name << " - " << rightReturn->name;
            break;
        case NMAO_Mul:
            lineStream << mathReturnValue->name << " = " << leftReturn->name << " * " << rightReturn->name;
            break;
        case NMAO_Div:
            lineStream << mathReturnValue->name << " = " << leftReturn->name << " / " << rightReturn->name;
            break;
        case NMAO_Inc:
            lineStream << mathReturnValue->name << " = " << leftReturn->name << " + 1";
            break;
        case NMAO_Dec:
            lineStream << mathReturnValue->name << " = " << leftReturn->name << " - 1";
            break;
        }
        trBlock->statements.push_back(lineStream.str());
    }

    leftSide->transpileSet(compiler, result, thisFunction, thisVar, trOutput, trBlock, mathReturnValue);

    return mathReturnValue;
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
    leftSide->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
    
    if (operatorOverloadNode) {
        ss << " = ";
        operatorOverloadNode->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
    }
    else {
        switch (op) {
        case NMAO_Add:
            ss << " += ";
            break;
        case NMAO_Sub:
            ss << " -= ";
            break;
        case NMAO_Mul:
            ss << " *= ";
            break;
        case NMAO_Div:
            ss << " /= ";
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
}
