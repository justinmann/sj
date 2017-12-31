#include <sjc.h>


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

void NThrow::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    node->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
}

void NThrow::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    node->initVars(compiler, scope, returnMode);
}

shared_ptr<CVar> NThrow::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CType> returnType, CTypeMode returnMode) {
    auto var = node->getVar(compiler, scope, nullptr, CTM_Undefined);
    if (!var) {
        return nullptr;
    }
    return make_shared<CThrowVar>(loc, nullptr, var);
}

