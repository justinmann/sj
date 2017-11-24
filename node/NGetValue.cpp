#include "Node.h"

class CGetValueVar : public CVar {
public:
    CGetValueVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> leftVar, bool isProtectedWithEmptyCheck) : CVar(loc, scope, "", false), leftVar(leftVar), isProtectedWithEmptyCheck(isProtectedWithEmptyCheck) { }

    bool getReturnThis() {
        return false;
    }
    
    shared_ptr<CType> getType(Compiler* compiler) {
        auto leftType = leftVar->getType(compiler);
        if (!leftType) {
            return nullptr;
        }

        if (!leftType->isOption) {
            compiler->addError(loc, CErrorCode::TypeMismatch, "getValue requires an option type");
            return nullptr;
        }

        return leftType->getValueType();
    }

    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
        auto leftValue = trBlock->createTempStoreVariable(loc, leftVar->scope.lock(), leftVar->getType(compiler), "getValue");
        leftVar->transpile(compiler, trOutput, trBlock, dotValue, thisValue, leftValue);
        if (!leftValue) {
            return;
        }

        if (!leftValue->type->isOption) {
            compiler->addError(loc, CErrorCode::TypeMismatch, "getValue requires an option type");
            return;
        }

        stringstream line;
        if (leftValue->type->parent.expired()) {
            if (!isProtectedWithEmptyCheck) {
                stringstream emptyCheck;
                emptyCheck << "if (" << leftValue->getName(trBlock) << ".isEmpty) { exit(-1); }";
                trBlock->statements.push_back(emptyCheck.str());
            }
            line << leftValue->getName(trBlock) << ".value";
        }
        else {
            if (!isProtectedWithEmptyCheck) {
                stringstream emptyCheck;
                emptyCheck << "if (" << leftValue->getName(trBlock) << " == 0) { exit(-1); }";
                trBlock->statements.push_back(emptyCheck.str());
            }
            line << leftValue->getName(trBlock);
        }

        storeValue->retainValue(compiler, loc, trBlock, make_shared<TrValue>(scope.lock(), leftValue->type->getValueType(), line.str(), false));
    }

    void dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
        ss << "getValue(";
        leftVar->dump(compiler, dotVar, functions, ss, dotSS, level);
        ss << ")";
    }

private:
    shared_ptr<CVar> leftVar;
    bool isProtectedWithEmptyCheck;
};

void NGetValue::defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, thisFunction);
}

shared_ptr<CVar> NGetValue::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = node->getVar(compiler, scope, CTM_Undefined);
    if (!leftVar) {
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler);
    if (!leftType) {
        return nullptr;
    }

    if (!leftType->isOption) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "getValue requires an option type");
        return nullptr;
    }

    return make_shared<CGetValueVar>(loc, leftVar->scope.lock(), leftVar, isProtectedWithEmptyCheck);
}
