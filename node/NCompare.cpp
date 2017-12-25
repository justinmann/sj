#include "Node.h"

bool CCompareVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CCompareVar::getType(Compiler* compiler) {
    return compiler->typeBool;
}

void CCompareVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto varType = leftVar->getType(compiler);
    if (!varType->parent.expired() && (op == NCompareOp::PEQ || op == NCompareOp::PNE)) {
        varType = varType->getTempType();
    }
    auto leftValue = trBlock->createTempStoreVariable(loc, nullptr, varType, "compare");
    auto rightValue = trBlock->createTempStoreVariable(loc, nullptr, varType, "compare");
    leftVar->transpile(compiler, trOutput, trBlock, thisValue, leftValue);
    rightVar->transpile(compiler, trOutput, trBlock, thisValue, rightValue);

    stringstream line;
    line << leftValue->getName(trBlock);
    if (varType->category == CTC_Interface && (op == NCompareOp::PEQ || op == NCompareOp::PNE)) {
        line << "._parent";
    }
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
    line << rightValue->getName(trBlock);
    if (varType->category == CTC_Interface && (op == NCompareOp::PEQ || op == NCompareOp::PNE)) {
        line << "._parent";
    }

    auto resultValue = make_shared<TrValue>(nullptr, compiler->typeBool, line.str(), false);
    storeValue->retainValue(compiler, loc, trBlock, resultValue);
}

void CCompareVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    leftVar->dump(compiler, functions, ss, level);
    switch (op) {
        case NCompareOp::EQ:
            ss << " == ";
            break;
        case NCompareOp::PEQ:
            ss << " === ";
            break;
        case NCompareOp::NE:
            ss << " != ";
            break;
        case NCompareOp::PNE:
            ss << " !== ";
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
    rightVar->dump(compiler, functions, ss, level);
}

void NCompare::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    leftSide->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    rightSide->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
}

void NCompare::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    leftSide->initVars(compiler, scope, returnMode);
    rightSide->initVars(compiler, scope, returnMode);
}

shared_ptr<CVar> NCompare::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
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

    if (!CType::isSameExceptMode(leftType, rightType)) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "left type '%s' does not match right type '%s'", leftType->fullName.c_str(), rightType->fullName.c_str());
        return nullptr;
    }

    // Check to see if we have operator overloading
    if (!leftType->parent.expired() && op != NCompareOp::PEQ && op != NCompareOp::PNE) {
        auto leftNVar = make_shared<NVariableStub>(leftSide);
        switch (op) {
            case NCompareOp::EQ:
                operatorOverloadNode = make_shared<NDot>(loc, leftNVar, make_shared<NCall>(loc, "isEqual", nullptr, make_shared<NodeList>(rightSide)));
                return operatorOverloadNode->getVar(compiler, scope, nullptr, returnMode);
                break;
            case NCompareOp::NE:
                operatorOverloadNode =  make_shared<NNot>(loc, make_shared<NDot>(loc, leftNVar, make_shared<NCall>(loc, "isEqual", nullptr, make_shared<NodeList>(rightSide))), true);
                return operatorOverloadNode->getVar(compiler, scope, nullptr, returnMode);
                break;
            case NCompareOp::LT:
                operatorOverloadNode = make_shared<NDot>(loc, leftNVar, make_shared<NCall>(loc, "isLess", nullptr, make_shared<NodeList>(rightSide)));
                return operatorOverloadNode->getVar(compiler, scope, nullptr, returnMode);
                break;
            case NCompareOp::LE:
                operatorOverloadNode = make_shared<NDot>(loc, leftNVar, make_shared<NCall>(loc, "isLessOrEqual", nullptr, make_shared<NodeList>(rightSide)));
                return operatorOverloadNode->getVar(compiler, scope, nullptr, returnMode);
                break;
            case NCompareOp::GT:
                operatorOverloadNode = make_shared<NDot>(loc, leftNVar, make_shared<NCall>(loc, "isGreater", nullptr, make_shared<NodeList>(rightSide)));
                return operatorOverloadNode->getVar(compiler, scope, nullptr, returnMode);
                break;
            case NCompareOp::GE:
                operatorOverloadNode = make_shared<NDot>(loc, leftNVar, make_shared<NCall>(loc, "isGreaterOrEqual", nullptr, make_shared<NodeList>(rightSide)));
                return operatorOverloadNode->getVar(compiler, scope, nullptr, returnMode);
                break;
            default:
                assert(false);
                return nullptr; // These operator cannot be overriden, this is reserved for pointer comparison
        }
    }
    
    return make_shared<CCompareVar>(loc, scope, op, leftVar, rightVar);
}
