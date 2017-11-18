#include "Node.h"

shared_ptr<CType> CIsEmptyVar::getType(Compiler* compiler, CResult& result) {
    return compiler->typeBool;
}

shared_ptr<ReturnValue> CIsEmptyVar::transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    auto leftValue = var->transpileGet(compiler, result, thisFunction, thisVar, trOutput, trBlock, returnMode, nullptr, thisName);
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
    return make_shared<ReturnValue>(compiler->typeBool, line.str());
}

void CIsEmptyVar::transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) {
    assert(false);
}

void CIsEmptyVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "isEmpty(";
    var->dump(compiler, result, thisFunction, thisVar, returnMode, nullptr, functions, ss, dotSS, level);
    ss << ")";
}


void NIsEmpty::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NIsEmpty::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar) {
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

    return make_shared<CIsEmptyVar>(loc, leftVar);
}
