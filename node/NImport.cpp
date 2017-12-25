#include "Node.h"

bool CImportVar::getReturnThis() {
    return var->getReturnThis();
}

shared_ptr<CType> CImportVar::getType(Compiler* compiler) {
    return var->getType(compiler);
}

void CImportVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    scope.lock()->pushImportScope(importScope);
    var->transpile(compiler, trOutput, trBlock, thisValue, storeValue);
    scope.lock()->popImportScope(importScope);
}

void CImportVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "import ";
    if (var) {
        ss << " ";
        scope.lock()->pushImportScope(importScope);
        var->dump(compiler, functions, ss, level);
        scope.lock()->popImportScope(importScope);
    }
}

void NImport::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);

    vector<pair<string, vector<string>>> newImportNamespaces = importNamespaces;
    for (auto importNamespace : importNamespaces) {
        newImportNamespaces.push_back(importNamespace);
    }
    node->initFunctions(compiler, newImportNamespaces, packageNamespace, thisFunction);
}

void NImport::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    node->initVars(compiler, scope, returnMode);
}

shared_ptr<CVar> NImport::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CType> returnType, CTypeMode returnMode) {
    auto importScope = make_shared<ImportScope>();
    importScope->importNamespaces = importNamespaces;
    scope->pushImportScope(importScope);
    auto var = node->getVar(compiler, scope, returnType, returnMode);
    scope->popImportScope(importScope);
    return make_shared<CImportVar>(loc, scope, var, importScope);
}