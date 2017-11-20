#include "Node.h"

shared_ptr<CType> CValueVar::getType(Compiler* compiler, CResult& result) {
    assert(compiler->state >= CompilerState::FixVar);
    auto leftType = var->getType(compiler, result);
    if (!leftType) {
        return nullptr;
    }

    if (leftType->isOption) {
        result.addError(loc, CErrorCode::TypeMismatch, "value cannot take an option type");
        return nullptr;
    }

    return leftType->getOptionType();
}

shared_ptr<ReturnValue> CValueVar::transpileGet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    auto leftValue = var->transpileGet(compiler, result, trOutput, trBlock, nullptr, thisName);
    if (!leftValue) {
        return nullptr;
    }

    if (leftValue->type->isOption) {
        result.addError(loc, CErrorCode::TypeMismatch, "value cannot take an option type");
        return nullptr;
    }

    if (leftValue->type->parent.expired()) {
        auto returnValue = trBlock->createTempVariable(leftValue->type->getOptionType(), "value");
        stringstream line1;
        line1 << returnValue->name << ".isEmpty = false";
        trBlock->statements.push_back(line1.str());

        stringstream line2;
        line2 << returnValue->name << ".value = " << leftValue->name;
        trBlock->statements.push_back(line2.str());

        return returnValue;
    }
    else {
        return make_shared<ReturnValue>(leftValue->type->getOptionType(), leftValue->name);
    }
}

void CValueVar::transpileSet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName, AssignOp op, bool isFirstAssignment) {
    assert(false);
}

void CValueVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "value(";
    var->dump(compiler, result, nullptr, functions, ss, dotSS, level);
    ss << ")";

}

void NValue::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NValue::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = node->getVar(compiler, result, thisFunction, thisVar, CTM_Heap);
    if (!leftVar) {
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler, result);
    if (!leftType) {
        return nullptr;
    }

    if (leftType->isOption) {
        result.addError(loc, CErrorCode::TypeMismatch, "value cannot take an option type");
        return nullptr;
    }

    if (leftType->typeMode != CTM_Heap && leftType->typeMode != CTM_Value) {
        result.addError(loc, CErrorCode::TypeMismatch, "value can only work on heap or value objects");
        return nullptr;
    }

    return make_shared<CValueVar>(loc, leftVar->scope.lock(), leftVar);
}
