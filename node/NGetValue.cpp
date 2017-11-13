#include "Node.h"

void NGetValue::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NGetValue::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar) {
    assert(compiler->state == CompilerState::FixVar);
    auto leftVar = node->getVar(compiler, result, thisFunction, thisVar);
    if (!leftVar) {
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler, result);
    if (!leftType) {
        return nullptr;
    }

    if (!leftType->isOption) {
        result.addError(loc, CErrorCode::TypeMismatch, "getValue requires an option type");
        return nullptr;
    }

    return nullptr;
}

shared_ptr<CType> NGetValue::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    auto leftType = node->getType(compiler, result, thisFunction, thisVar);
    if (!leftType) {
        return nullptr;
    }

    if (!leftType->isOption) {
        result.addError(loc, CErrorCode::TypeMismatch, "getValue requires an option type");
        return nullptr;
    }

    return leftType->getNotOptionType();
}

int NGetValue::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, bool isHeapVar) {
    return node->setHeapVar(compiler, result, thisFunction, thisVar, isHeapVar);
}

shared_ptr<ReturnValue> NGetValue::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue) {
    auto leftValue = node->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, false);
    if (!leftValue) {
        return nullptr;
    }

    if (!leftValue->type->isOption) {
        result.addError(loc, CErrorCode::TypeMismatch, "getValue requires an option type");
        return nullptr;
    }

    stringstream line;
    if (leftValue->type->parent.expired()) {
        if (!isProtectedWithEmptyCheck) {
            stringstream emptyCheck;
            emptyCheck << "if (" << leftValue->name << ".isEmpty) { exit(-1); }";
            trBlock->statements.push_back(emptyCheck.str());
        }
        line << leftValue->name << ".value";
    }
    else {
        if (!isProtectedWithEmptyCheck) {
            stringstream emptyCheck;
            emptyCheck << "if (" << leftValue->name << " == 0) { exit(-1); }";
            trBlock->statements.push_back(emptyCheck.str());
        }
        line << leftValue->name;
    }

    return make_shared<ReturnValue>(leftValue->type->getNotOptionType(), true, RVR_Ignore, line.str());
}

void NGetValue::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "isEmpty(";
    node->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
    ss << ")";
}