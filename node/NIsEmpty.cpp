#include "Node.h"

void NIsEmpty::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NIsEmpty::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar) {
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
        result.addError(loc, CErrorCode::TypeMismatch, "isEmpty requires an option type");
        return nullptr;
    }

    return nullptr;
}

shared_ptr<CType> NIsEmpty::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeBool;
}

int NIsEmpty::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, bool isHeapVar) {
    return 0;
}

shared_ptr<ReturnValue> NIsEmpty::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue) {
    auto leftValue = node->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, false);
    if (!leftValue) {
        return nullptr;
    }

    if (!leftValue->type->isOption) {
        result.addError(loc, CErrorCode::TypeMismatch, "isEmpty requires an option type");
        return nullptr;
    }

    stringstream line;
    if (leftValue->type->parent.expired()) {
        line << leftValue->name << ".isEmpty";
    }
    else {
        line << "(" << leftValue->name << " == 0)";
    }
    return make_shared<ReturnValue>(compiler->typeBool, true, RVR_Ignore, line.str());
}

void NIsEmpty::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "isEmpty(";
    node->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
    ss << ")";
}