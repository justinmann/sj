#include "Node.h"

void NPackage::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces_, vector<string>& packageNamespace_, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    vector<string> newPackageNamespace = packageNamespace_;
    for (auto t : packageNamespace) {
        newPackageNamespace.push_back(t);
        compiler->namespaces[newPackageNamespace] = true;
    }
    
    vector<pair<string, vector<string>>> newImportNamespaces = importNamespaces_;
    newImportNamespaces.push_back(make_pair(string(), newPackageNamespace));

    node->initFunctions(compiler, newImportNamespaces, newPackageNamespace, thisFunction);
}

void NPackage::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    node->initVars(compiler, scope, returnMode);
}

shared_ptr<CVar> NPackage::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    auto importScope = make_shared<ImportScope>();
    importScope->importNamespaces.push_back(make_pair(string(""), packageNamespace));
    scope->pushImportScope(importScope);

    auto var = node->getVar(compiler, scope, returnMode);

    scope->popImportScope(importScope);

    return make_shared<CImportVar>(loc, scope, var, importScope);;
}

