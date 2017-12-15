#include "Node.h"

bool CThrowVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CThrowVar::getType(Compiler* compiler) {
    return compiler->typeVoid;
}

void CThrowVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    assert(false);
}

void CThrowVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "throw";
}

void NThrow::defineImpl(Compiler* compiler, vector<vector<string>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    node->define(compiler, importNamespaces, packageNamespace, thisFunction);
}

shared_ptr<CVar> NThrow::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    auto var = node->getVar(compiler, scope, CTM_Undefined);
    if (!var) {
        return nullptr;
    }
    return make_shared<CThrowVar>(loc, nullptr, var);
}

