#include "Node.h"

NMathAssignment::NMathAssignment(CLoc loc, shared_ptr<NVariableBase> leftSide, NMathAssignmentOp op, shared_ptr<NVariableBase> numberSide) : NBase(NodeType_MathAssignment, loc), op(op), leftSide(leftSide), numberSide(numberSide) {
}

void NMathAssignment::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    if (leftSide) {
        leftSide->define(compiler, result, thisFunction);
    }
    if (numberSide) {
        numberSide->define(compiler, result, thisFunction);
    }
}

shared_ptr<CVar> NMathAssignment::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, CTypeReturnMode returnMode) {
    assert(compiler->state == CompilerState::FixVar);
    auto leftVar = leftSide->getVar(compiler, result, thisFunction, thisVar, nullptr, CTRM_NoPref);

    if (!leftVar) {
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler, result, CTRM_NoPref);
    if (!leftType) {
        return nullptr;
    }

    // Check to see if we have operator overloading
    shared_ptr<CVar> rightVar;
    if (!leftType->parent.expired()) {
        shared_ptr<NDot> operatorOverloadNode;
        switch (op) {
        case NMathAssignmentOp::NMAO_Inc:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "increment", nullptr, nullptr));
            rightVar = operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar, nullptr, returnMode);
            break;
        case NMathAssignmentOp::NMAO_Dec:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "decrement", nullptr, nullptr));
            rightVar = operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar, nullptr, returnMode);
            break;
        case NMathAssignmentOp::NMAO_Add:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "add", nullptr, make_shared<NodeList>(numberSide)));
            rightVar = operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar, nullptr, returnMode);
            break;
        case NMathAssignmentOp::NMAO_Sub:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "subtract", nullptr, make_shared<NodeList>(numberSide)));
            rightVar = operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar, nullptr, returnMode);
            break;
        case NMathAssignmentOp::NMAO_Mul:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "multiply", nullptr, make_shared<NodeList>(numberSide)));
            rightVar = operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar, nullptr, returnMode);
            break;
        case NMathAssignmentOp::NMAO_Div:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "divide", nullptr, make_shared<NodeList>(numberSide)));
            rightVar = operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar, nullptr, returnMode);
            break;
        default:
            assert(false);
            break;
        }
    }
    else {
        shared_ptr<CVar> numberVar;
        if (numberSide) {
            auto numberVar = numberSide->getVar(compiler, result, thisFunction, thisVar, nullptr, CTRM_NoPref);
            if (!numberVar) {
                return nullptr;
            }
            
            auto numberType = rightVar->getType(compiler, result, CTRM_NoPref);
            if (!numberType) {
                return nullptr;
            }
            
            if (leftType != numberType) {
                result.addError(loc, CErrorCode::TypeMismatch, "left type '%s' does not match right type '%s'", leftType->name.c_str(), numberType->name.c_str());
                return nullptr;
            }
        } else {
            numberVar = make_shared<CConstantVar>(loc, leftType, "1");
        }
        
        NMathOp mathOp;
        switch (op) {
            case NMathAssignmentOp::NMAO_Inc:
                mathOp = NMathOp::Add;
                break;
            case NMathAssignmentOp::NMAO_Dec:
                mathOp = NMathOp::Sub;
                break;
            case NMathAssignmentOp::NMAO_Add:
                mathOp = NMathOp::Add;
                break;
            case NMathAssignmentOp::NMAO_Sub:
                mathOp = NMathOp::Sub;
                break;
            case NMathAssignmentOp::NMAO_Mul:
                mathOp = NMathOp::Mul;
                break;
            case NMathAssignmentOp::NMAO_Div:
                mathOp = NMathOp::Div;
                break;
            default:
                assert(false);
                break;
        }
        
        rightVar = make_shared<CMathVar>(loc, mathOp, leftVar, numberVar);
    }
    return make_shared<CAssignVar>(loc, leftVar, rightVar);
}
