#include "Node.h"

void NCompare::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    leftSide->define(compiler, result, thisFunction);
    rightSide->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NCompare::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar) {
    assert(compiler->state == CompilerState::FixVar);
    auto leftVar = leftSide->getVar(compiler, result, thisFunction, thisVar, nullptr);
    auto rightVar = rightSide->getVar(compiler, result, thisFunction, thisVar, nullptr);
    
    if (!leftVar || !rightVar) {
        return nullptr;
    }
    
    auto leftType = leftVar->getType(compiler, result);
    auto rightType = rightVar->getType(compiler, result);
    if (leftType != rightType) {
        result.addError(loc, CErrorCode::TypeMismatch, "left type '%s' does not match right type '%s'", leftType->name.c_str(), rightType->name.c_str());
        return nullptr;
    }

    // Check to see if we have operator overloading
    if (!leftType->parent.expired()) {
        switch (op) {
            case NCompareOp::EQ:
                comparisonNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "isEqual", nullptr, make_shared<NodeList>(rightSide)));
                return comparisonNode->getVar(compiler, result, thisFunction, thisVar);
                break;
            case NCompareOp::NE:
                comparisonNode =  make_shared<NNot>(loc, make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "isEqual", nullptr, make_shared<NodeList>(rightSide))));
                return comparisonNode->getVar(compiler, result, thisFunction, thisVar);
                break;
            case NCompareOp::LT:
                comparisonNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "isLess", nullptr, make_shared<NodeList>(rightSide)));
                return comparisonNode->getVar(compiler, result, thisFunction, thisVar);
                break;
            case NCompareOp::LE:
                comparisonNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "isLessOrEqual", nullptr, make_shared<NodeList>(rightSide)));
                return comparisonNode->getVar(compiler, result, thisFunction, thisVar);
                break;
            case NCompareOp::GT:
                comparisonNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "isGreater", nullptr, make_shared<NodeList>(rightSide)));
                return comparisonNode->getVar(compiler, result, thisFunction, thisVar);
                break;
            case NCompareOp::GE:
                comparisonNode = make_shared<NDot>(loc, leftSide, make_shared<NCall>(loc, "isGreaterOrEqual", nullptr, make_shared<NodeList>(rightSide)));
                return comparisonNode->getVar(compiler, result, thisFunction, thisVar);
                break;
            case NCompareOp::PEQ:
            case NCompareOp::PNE:
                return nullptr; // These operator cannot be overriden, this is reserved for pointer comparison
        }
    }
    
    return nullptr;
}

shared_ptr<CType> NCompare::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    if (comparisonNode) {
        auto ctype = comparisonNode->getType(compiler, result, thisFunction, thisVar);
        if (ctype != compiler->typeBool) {
            result.addError(loc, CErrorCode::TypeMismatch, "operator overload must return bool");
            return nullptr;
        }
    }
    return compiler->typeBool;
}

int NCompare::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, bool isHeapVar) {
    if (comparisonNode) {
        return comparisonNode->setHeapVar(compiler, result, thisFunction, thisVar, false);
    } else {
        auto count = leftSide->setHeapVar(compiler, result, thisFunction, thisVar, nullptr, false);
        count += rightSide->setHeapVar(compiler, result, thisFunction, thisVar, nullptr, false);
        return count;
    }
}

shared_ptr<ReturnValue> NCompare::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue) {
    if (comparisonNode) {
        return comparisonNode->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, isReturnValue);
    } else {
        auto leftValue = leftSide->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, false);
        auto rightValue = rightSide->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, false);

        if (!leftValue || !rightValue) {
            assert(false);
            return nullptr;
        }
        
        if (leftValue->type != rightValue->type) {
            result.addError(loc, CErrorCode::TypeMismatch, "left type '%s' does not match right type '%s'", leftValue->type->name.c_str(), rightValue->type->name.c_str());
            return nullptr;
        }

        auto resultValue = trBlock->createTempVariable("result", compiler->typeBool, false, RVR_MustRetain);
        stringstream line;
        line << resultValue->name << " = " << leftValue->name;
        switch (op) {
        case NCompareOp::EQ:
        case NCompareOp::PEQ:
            line << " == ";
            break;
        case NCompareOp::NE:
        case NCompareOp::PNE:
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
