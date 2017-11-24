#include "Node.h"

bool CChangeModeVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CChangeModeVar::getType(Compiler* compiler) {
    return var->getType(compiler);
}

void CChangeModeVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    var->transpile(compiler, trOutput, trBlock, dotValue, thisValue, storeValue);
}

void CChangeModeVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
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
        default:
            break;
    }
    var->dump(compiler, nullptr, functions, ss, dotSS, level);
}


void NChangeMode::defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, thisFunction);
}

shared_ptr<CVar> NChangeMode::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto var = node->getVar(compiler, scope, typeMode);
    if (!var) {
        return nullptr;
    }

    return make_shared<CChangeModeVar>(loc, scope, typeMode, var);
}

