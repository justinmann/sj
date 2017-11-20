#include "Node.h"

shared_ptr<CType> CIsEmptyVar::getType(Compiler* compiler, CResult& result) {
    return compiler->typeBool;
}

shared_ptr<ReturnValue> CIsEmptyVar::transpileGet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    auto leftValue = var->transpileGet(compiler, result, trOutput, trBlock, nullptr, thisName);
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

void CIsEmptyVar::transpileSet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName, AssignOp op, bool isFirstAssignment) {
    assert(false);
}

void CIsEmptyVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "isEmpty(";
    var->dump(compiler, result, nullptr, functions, ss, dotSS, level);
    ss << ")";
}


void NIsEmpty::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NIsEmpty::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = node->getVar(compiler, result, thisFunction, thisVar, CTM_Undefined);
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

    return make_shared<CIsEmptyVar>(loc, thisFunction, leftVar);
}
