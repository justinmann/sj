#include "Node.h"

class CGetValueVar : public CVar {
public:
    CGetValueVar(CLoc& loc, shared_ptr<CBaseFunction> scope, shared_ptr<CVar> leftVar, bool isProtectedWithEmptyCheck) : CVar(loc, scope, "", false), leftVar(leftVar), isProtectedWithEmptyCheck(isProtectedWithEmptyCheck) { }

    bool getReturnThis() {
        return false;
    }
    
    shared_ptr<CType> getType(Compiler* compiler, CResult& result) {
        auto leftType = leftVar->getType(compiler, result);
        if (!leftType) {
            return nullptr;
        }

        if (!leftType->isOption) {
            result.addError(loc, CErrorCode::TypeMismatch, "getValue requires an option type");
            return nullptr;
        }

        return leftType->getValueType();
    }

    void transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
        auto leftValue = trBlock->createTempStoreVariable(loc, leftVar->scope.lock(), leftVar->getType(compiler, result), "temp");
        leftVar->transpile(compiler, result, trOutput, trBlock, dotValue, thisValue, leftValue);
        if (!leftValue) {
            return;
        }

        if (!leftValue->type->isOption) {
            result.addError(loc, CErrorCode::TypeMismatch, "getValue requires an option type");
            return;
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

        storeValue->setValue(compiler, result, trBlock, make_shared<TrValue>(scope.lock(), leftValue->type->getValueType(), line.str()));
    }

    void dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
        ss << "getValue(";
        leftVar->dump(compiler, result, dotVar, functions, ss, dotSS, level);
        ss << ")";
    }

private:
    shared_ptr<CVar> leftVar;
    bool isProtectedWithEmptyCheck;
};

void NGetValue::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NGetValue::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = node->getVar(compiler, result, thisFunction, thisVar, CTM_Undefined);
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

    return make_shared<CGetValueVar>(loc, leftVar->scope.lock(), leftVar, isProtectedWithEmptyCheck);
}
