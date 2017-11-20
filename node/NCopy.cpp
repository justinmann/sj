#include "Node.h"

shared_ptr<CType> CCopyVar::getType(Compiler* compiler, CResult& result) {
    auto type = var->getType(compiler, result);
    if (!type) {
        return nullptr;
    }

    if (type->isOption) {
        result.addError(loc, CErrorCode::TypeMismatch, "copy cannot take an option type");
        return nullptr;
    }

    return type->getOptionType();
}

shared_ptr<ReturnValue> CCopyVar::transpileGet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    auto rightValue = var->transpileGet(compiler, result, trOutput, trBlock, nullptr, thisName);
    
    // figure out type
    shared_ptr<CType> leftType;
    switch (returnMode) {
    case CTM_Local:
    case CTM_Undefined:
    case CTM_Stack:
        leftType = rightValue->type->getStackValueType();
        break;
    case CTM_Heap:
        leftType = rightValue->type->getHeapValueType();
        break;
    }

    // create temp variable
    auto resultValue = trBlock->createTempVariable(leftType, "copy");

    // init temp variable
    resultValue->addInitToStatements(trBlock);

    // copy
    auto copyName = leftType->parent.lock()->getCCopyFunctionName();
    stringstream ss;
    ss << copyName << "(" << rightValue->name << ", " << resultValue->name << ")";
    trBlock->statements.push_back(ss.str());

    return resultValue;
}

void CCopyVar::transpileSet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) {
    assert(false);
}

void CCopyVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "copy(";
    var->dump(compiler, result, returnMode, nullptr, functions, ss, dotSS, level);
    ss << ")";

}

void NCopy::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NCopy::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = node->getVar(compiler, result, thisFunction, thisVar);
    if (!leftVar) {
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler, result, CTM_Undefined);
    if (!leftType) {
        return nullptr;
    }

    if (leftType->isOption) {
        result.addError(loc, CErrorCode::TypeMismatch, "value cannot take an option type");
        return nullptr;
    }

    return make_shared<CCopyVar>(loc, leftVar);
}
