#include "Node.h"

bool CMathVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CMathVar::getType(Compiler* compiler, CResult& result) {
    return leftVar->getType(compiler, result);
}

void CMathVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto leftValue = trBlock->createTempStoreVariable(loc, nullptr, leftVar->getType(compiler, result), "math");
    auto rightValue = trBlock->createTempStoreVariable(loc, nullptr, leftVar->getType(compiler, result), "math");
    leftVar->transpile(compiler, result, trOutput, trBlock, nullptr, thisValue, leftValue);
    rightVar->transpile(compiler, result, trOutput, trBlock, nullptr, thisValue, rightValue);

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
    storeValue->retainValue(compiler, result, trBlock, resultValue);
}

void CMathVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    leftVar->dump(compiler, result, nullptr, functions, ss, dotSS, level);
    
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
    
    rightVar->dump(compiler, result, nullptr, functions, ss, dotSS, level);
}

void NMath::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    leftSide->define(compiler, result, thisFunction);
    rightSide->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NMath::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = leftSide->getVar(compiler, result, thisFunction, thisVar, nullptr, CTM_Undefined);
    auto rightVar = rightSide->getVar(compiler, result, thisFunction, thisVar, nullptr, CTM_Undefined);

    if (!leftVar || !rightVar) {
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler, result);
    auto rightType = rightVar->getType(compiler, result);
    if (!leftType || !rightType) {
        return nullptr;
    }

    if (leftType != rightType) {
        result.addError(loc, CErrorCode::TypeMismatch, "left type '%s' does not match right type '%s'", leftType->name.c_str(), rightType->name.c_str());
        return nullptr;
    }

    // Check to see if we have operator overloading
    if (!leftType->parent.expired()) {
        switch (op) {
        case NMathOp::Add:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "add", nullptr, make_shared<NodeList>(rightSide)));
            return operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar, returnMode);
            break;
        case NMathOp::Sub:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "subtract", nullptr, make_shared<NodeList>(rightSide)));
            return operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar, returnMode);
            break;
        case NMathOp::Div:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "divide", nullptr, make_shared<NodeList>(rightSide)));
            return operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar, returnMode);
            break;
        case NMathOp::Mul:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "multiply", nullptr, make_shared<NodeList>(rightSide)));
            return operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar, returnMode);
            break;
        case NMathOp::Mod:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "modulus", nullptr, make_shared<NodeList>(rightSide)));
            return operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar, returnMode);
            break;
        default:
            assert(false);
            return nullptr;
        }
    } else {
        return make_shared<CMathVar>(loc, thisFunction, op, leftVar, rightVar);
    }
}
