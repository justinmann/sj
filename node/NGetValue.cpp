#include "Node.h"

class CGetValueVar : public CVar {
public:
    CGetValueVar(CLoc loc, shared_ptr<CVar> leftVar, bool isProtectedWithEmptyCheck) : loc(loc), leftVar(leftVar), isProtectedWithEmptyCheck(isProtectedWithEmptyCheck) { }

    shared_ptr<CType> getType(Compiler* compiler, CResult& result, CTypeReturnMode returnMode) {
        auto leftType = leftVar->getType(compiler, result, returnMode);
        if (!leftType) {
            return nullptr;
        }

        if (!leftType->isOption) {
            result.addError(loc, CErrorCode::TypeMismatch, "getValue requires an option type");
            return nullptr;
        }

        return leftType->getValueType();
    }

    shared_ptr<ReturnValue> transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName) {
        auto leftValue = leftVar->transpileGet(compiler, result, thisFunction, thisVar, trOutput, trBlock, returnMode, dotValue, thisName);
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

        return make_shared<ReturnValue>(leftValue->type->getValueType(), line.str());
    }

    void transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) {

    }

    void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, CTypeReturnMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
        ss << "getValue(";
        leftVar->dump(compiler, result, thisFunction, thisVar, returnMode, dotVar, functions, ss, dotSS, level);
        ss << ")";
    }

    CLoc loc;
    shared_ptr<CVar> leftVar;
    bool isProtectedWithEmptyCheck;
};

void NGetValue::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NGetValue::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, CTypeReturnMode returnMode) {
    assert(compiler->state == CompilerState::FixVar);
    auto leftVar = node->getVar(compiler, result, thisFunction, thisVar, returnMode);
    if (!leftVar) {
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler, result, returnMode);
    if (!leftType) {
        return nullptr;
    }

    if (!leftType->isOption) {
        result.addError(loc, CErrorCode::TypeMismatch, "getValue requires an option type");
        return nullptr;
    }

    return make_shared<CGetValueVar>(loc, leftVar, isProtectedWithEmptyCheck);
}
