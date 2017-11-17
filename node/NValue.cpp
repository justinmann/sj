#include "Node.h"

void NValue::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NValue::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, CTypeReturnMode returnMode) {
    assert(compiler->state == CompilerState::FixVar);
    auto leftVar = node->getVar(compiler, result, thisFunction, thisVar);
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

    return nullptr;
}

shared_ptr<CType> NValue::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, CTypeReturnMode returnMode) {
    assert(compiler->state >= CompilerState::FixVar);
    auto leftType = node->getType(compiler, result, thisFunction, thisVar);
    if (!leftType) {
        return nullptr;
    }

    if (leftType->isOption) {
        result.addError(loc, CErrorCode::TypeMismatch, "value cannot take an option type");
        return nullptr;
    }

    return leftType->getOptionType();
}

shared_ptr<ReturnValue> NValue::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, const char* thisName) {
    auto leftValue = node->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, false, thisName);
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

void NValue::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, CTypeReturnMode returnMode, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "value(";
    node->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
    ss << ")";
}
