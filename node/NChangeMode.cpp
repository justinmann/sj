#include <sjc.h>
#include "Node.h"

bool CChangeModeVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CChangeModeVar::getType(Compiler* compiler) {
    auto varType = var->getType(compiler);
    if (!varType) {
        return nullptr;
    }

    if (varType->typeMode != typeMode) {
        shared_ptr<CType> changeType = varType;
        switch (typeMode) {
        case CTM_Local:
            return varType->getTempType();
        case CTM_Weak:
            return varType->getWeakType();
        case CTM_Stack:
            return varType->getStackType();
        case CTM_Heap:
            if (varType->typeMode == CTM_Weak) {
                return varType->getHeapType();
            }
            else {
                compiler->addError(loc, CErrorCode::InvalidType, "cannot change type to heap");
            }
            return nullptr;
        case CTM_Value:
            compiler->addError(loc, CErrorCode::InvalidType, "cannot change type to value");
            return nullptr;
        }
    }
    return varType;
}

void CChangeModeVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto varType = var->getType(compiler);
    var->transpile(compiler, trOutput, trBlock, thisValue, storeValue);
}

void CChangeModeVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    switch (typeMode) {
        case CTM_Heap:
            ss << "heap ";
            break;
        case CTM_Stack:
            ss << "stack ";
            break;
        case CTM_Local:
            ss << "local ";
            break;
        case CTM_Weak:
            ss << "weak ";
            break;
        default:
            break;
    }
    var->dump(compiler, functions, ss, level);
}


void NChangeMode::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
}

void NChangeMode::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    node->initVars(compiler, scope, returnMode);
}

shared_ptr<CVar> NChangeMode::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
    auto var = node->getVar(compiler, scope, returnType, typeMode);
    if (!var) {
        return nullptr;
    }

    return make_shared<CChangeModeVar>(loc, scope, typeMode, var);
}

