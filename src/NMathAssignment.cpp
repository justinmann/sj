#include <sjc.h>


NMathAssignment::NMathAssignment(CLoc loc, shared_ptr<NVariableBase> leftSide, NMathAssignmentOp op, shared_ptr<NVariableBase> numberSide) : NBase(NodeType_MathAssignment, loc), op(op), leftSide(leftSide), numberSide(numberSide) {
}

void NMathAssignment::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    if (leftSide) {
        leftSide->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    }

    if (numberSide) {
        numberSide->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    }
}

void NMathAssignment::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    if (leftSide) {
        leftSide->initVars(compiler, scope, returnMode);
    }

    if (numberSide) {
        numberSide->initVars(compiler, scope, returnMode);
    }
}

shared_ptr<CVar> NMathAssignment::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CType> returnType, CTypeMode returnMode) {
    auto leftVar = leftSide->getVar(compiler, scope, nullptr, nullptr, CTM_Undefined);
    if (!leftVar) {
        compiler->addError(loc, CErrorCode::InvalidVariable, "left side is empty");
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler);
    if (!leftType) {
        compiler->addError(loc, CErrorCode::InvalidType, "left type is empty");
        return nullptr;
    }

    if (!leftVar->isMutable) {
        compiler->addError(loc, CErrorCode::InvalidType, "left type is immutable");
        return nullptr;        
    }

    // Check to see if we have operator overloading
    shared_ptr<CVar> rightVar;
    if (!leftType->parent.expired()) {
        string rightTypeName;
        if (numberSide) {
            auto numberVar = numberSide->getVar(compiler, scope, nullptr, nullptr, CTM_Undefined);
            auto numberType = numberVar->getType(compiler);
            if (!CType::isSameExceptMode(leftType, numberType)) {
                rightTypeName = numberType->valueName;
            }
        }

        shared_ptr<NDot> operatorOverloadNode;
        switch (op) {
        case NMathAssignmentOp::NMAO_Inc:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "increment", nullptr, nullptr));
            rightVar = operatorOverloadNode->getVar(compiler, scope, nullptr, nullptr, returnMode);
            break;
        case NMathAssignmentOp::NMAO_Dec:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "decrement", nullptr, nullptr));
            rightVar = operatorOverloadNode->getVar(compiler, scope, nullptr, nullptr, returnMode);
            break;
        case NMathAssignmentOp::NMAO_Add:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "add" + rightTypeName, nullptr, make_shared<NodeList>(numberSide)));
            rightVar = operatorOverloadNode->getVar(compiler, scope, nullptr, nullptr, returnMode);
            break;
        case NMathAssignmentOp::NMAO_Sub:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "subtract" + rightTypeName, nullptr, make_shared<NodeList>(numberSide)));
            rightVar = operatorOverloadNode->getVar(compiler, scope, nullptr, nullptr, returnMode);
            break;
        case NMathAssignmentOp::NMAO_Mul:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "multiply" + rightTypeName, nullptr, make_shared<NodeList>(numberSide)));
            rightVar = operatorOverloadNode->getVar(compiler, scope, nullptr, nullptr, returnMode);
            break;
        case NMathAssignmentOp::NMAO_Div:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "divide" + rightTypeName, nullptr, make_shared<NodeList>(numberSide)));
            rightVar = operatorOverloadNode->getVar(compiler, scope, nullptr, nullptr, returnMode);
            break;
        default:
            assert(false);
            break;
        }
    }
    else {
        shared_ptr<CVar> numberVar;
        if (numberSide) {
            numberVar = numberSide->getVar(compiler, scope, nullptr, nullptr, CTM_Undefined);
            if (!numberVar) {
                return nullptr;
            }
            
            auto numberType = numberVar->getType(compiler);
            if (!numberType) {
                return nullptr;
            }
            
            if (leftType != numberType) {
                compiler->addError(loc, CErrorCode::TypeMismatch, "left type '%s' does not match right type '%s'", leftType->fullName.c_str(), numberType->fullName.c_str());
                return nullptr;
            }
        } else {
            numberVar = make_shared<CConstantVar>(loc, scope, leftType, "1");
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
                return nullptr;
        }
        
        rightVar = make_shared<CMathVar>(loc, scope, mathOp, leftVar, numberVar);
    }

    auto leftStoreVar = dynamic_pointer_cast<CStoreVar>(leftVar);
    if (!leftStoreVar) {
        assert(false);
    }
    return make_shared<CAssignVar>(loc, scope, AssignOp::mutableUpdate, leftStoreVar, rightVar);
}
