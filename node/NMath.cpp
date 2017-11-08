#include "Node.h"

void NMath::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    leftSide->define(compiler, result, thisFunction);
    rightSide->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NMath::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar) {
    assert(compiler->state == CompilerState::FixVar);
    auto leftVar = leftSide->getVar(compiler, result, thisFunction, thisVar, nullptr);
    auto rightVar = rightSide->getVar(compiler, result, thisFunction, thisVar, nullptr);

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
            return operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar);
            break;
        case NMathOp::Sub:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "subtract", nullptr, make_shared<NodeList>(rightSide)));
            return operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar);
            break;
        case NMathOp::Div:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "divide", nullptr, make_shared<NodeList>(rightSide)));
            return operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar);
            break;
        case NMathOp::Mul:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "multiply", nullptr, make_shared<NodeList>(rightSide)));
            return operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar);
            break;
        case NMathOp::Mod:
            operatorOverloadNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "modulus", nullptr, make_shared<NodeList>(rightSide)));
            return operatorOverloadNode->getVar(compiler, result, thisFunction, thisVar);
            break;
        }
    }

    return nullptr;
}

shared_ptr<CType> NMath::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    if (operatorOverloadNode) {
        return operatorOverloadNode->getType(compiler, result, thisFunction, thisVar);
    }
    else {
        return leftSide->getType(compiler, result, thisFunction, thisVar);
    }
}

int NMath::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, bool isHeapVar) {
    if (operatorOverloadNode) {
        return operatorOverloadNode->setHeapVar(compiler, result, thisFunction, thisVar, false);
    }
    else {
        auto count = leftSide->setHeapVar(compiler, result, thisFunction, thisVar, nullptr, false);
        count += rightSide->setHeapVar(compiler, result, thisFunction, thisVar, nullptr, false);
        return count;
    }
}

shared_ptr<ReturnValue> NMath::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue) {
    if (operatorOverloadNode) {
        return operatorOverloadNode->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, isReturnValue);
    }
    else {
        auto leftValue = leftSide->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, false);
        auto rightValue = rightSide->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, false);

        if (!leftValue || !rightValue) {
            return nullptr;
        }

        if (leftValue->type != rightValue->type) {
            result.addError(loc, CErrorCode::TypeMismatch, "left and right values are not the same type");
            return nullptr;
        }

        auto resultValue = trBlock->createTempVariable("result", leftValue->type, false, RVR_MustRetain);
        stringstream line;
        line << resultValue->name << " = " << leftValue->name;
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

        return resultValue;
    }
}

void NMath::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    if (operatorOverloadNode) {
        operatorOverloadNode->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
    }
    else {
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
}
