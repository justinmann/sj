#include "Node.h"

bool CMathVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CMathVar::getType(Compiler* compiler) {
    return leftVar->getType(compiler);
}

void CMathVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto leftValue = trBlock->createTempStoreVariable(loc, nullptr, leftVar->getType(compiler), "math");
    auto rightValue = trBlock->createTempStoreVariable(loc, nullptr, leftVar->getType(compiler), "math");
    leftVar->transpile(compiler, trOutput, trBlock, nullptr, thisValue, leftValue);
    rightVar->transpile(compiler, trOutput, trBlock, nullptr, thisValue, rightValue);

    stringstream line;
    line << leftValue->name;
    switch (op) {
    case NMathOp::Add:
        line << " + ";
        break;
    case NMathOp::Sub:
        line << " - ";
        break;
    case NMathOp::Mul:
        line << " * ";
        break;
    case NMathOp::Div:
        line << " / ";
        break;
    case NMathOp::Mod:
        line << " % ";
        break;
    }
    line << rightValue->name;
    trBlock->statements.push_back(line.str());

    auto resultValue = make_shared<TrValue>(nullptr, compiler->typeBool, line.str());
    storeValue->retainValue(compiler, trBlock, resultValue);
}

void CMathVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    leftVar->dump(compiler, nullptr, functions, ss, dotSS, level);
    
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
    
    rightVar->dump(compiler, nullptr, functions, ss, dotSS, level);
}

void NMath::defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    leftSide->define(compiler, thisFunction);
    rightSide->define(compiler, thisFunction);
}

shared_ptr<CVar> NMath::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = leftSide->getVar(compiler, scope, nullptr, CTM_Undefined);
    auto rightVar = rightSide->getVar(compiler, scope, nullptr, CTM_Undefined);

    if (!leftVar || !rightVar) {
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler);
    auto rightType = rightVar->getType(compiler);
    if (!leftType || !rightType) {
        return nullptr;
    }

    if (leftType != rightType) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "left type '%s' does not match right type '%s'", leftType->name.c_str(), rightType->name.c_str());
        return nullptr;
    }

    // Check to see if we have operator overloading
    if (!leftType->parent.expired()) {
        switch (op) {
        case NMathOp::Add:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "add", nullptr, make_shared<NodeList>(rightSide)));
            return operatorOverloadNode->getVar(compiler, scope, returnMode);
            break;
        case NMathOp::Sub:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "subtract", nullptr, make_shared<NodeList>(rightSide)));
            return operatorOverloadNode->getVar(compiler, scope, returnMode);
            break;
        case NMathOp::Div:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "divide", nullptr, make_shared<NodeList>(rightSide)));
            return operatorOverloadNode->getVar(compiler, scope, returnMode);
            break;
        case NMathOp::Mul:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "multiply", nullptr, make_shared<NodeList>(rightSide)));
            return operatorOverloadNode->getVar(compiler, scope, returnMode);
            break;
        case NMathOp::Mod:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "modulus", nullptr, make_shared<NodeList>(rightSide)));
            return operatorOverloadNode->getVar(compiler, scope, returnMode);
            break;
        default:
            assert(false);
            return nullptr;
        }
    } else {
        return make_shared<CMathVar>(loc, scope, op, leftVar, rightVar);
    }
}
