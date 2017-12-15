#include "Node.h"

bool CImportVar::getReturnThis() {
    return var->getReturnThis();
}

shared_ptr<CType> CImportVar::getType(Compiler* compiler) {
    return var->getType(compiler);
}

void CImportVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    scope.lock()->pushFunctionBlock(functionBlock);
    var->transpile(compiler, trOutput, trBlock, thisValue, storeValue);
    scope.lock()->popFunctionBlock(functionBlock);
}

void CImportVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "import ";
    if (var) {
        ss << " ";
        scope.lock()->pushFunctionBlock(functionBlock);
        var->dump(compiler, functions, ss, level);
        scope.lock()->popFunctionBlock(functionBlock);
    }
}

void NImport::defineImpl(Compiler* compiler, vector<vector<string>>& importNamespaces_, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);

    vector<vector<string>> newNamespaces = importNamespaces_;
    for (auto importNamespace : importNamespaces) {
        newNamespaces.push_back(importNamespace);
    }
    
    node->define(compiler, newNamespaces, packageNamespace, thisFunction);
}

shared_ptr<CVar> NImport::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    auto functionBlock = make_shared<FunctionBlock>();
    functionBlock->importNamespaces = importNamespaces;
    scope->pushFunctionBlock(functionBlock);
    auto var = node->getVar(compiler, scope, returnMode);
    scope->popFunctionBlock(functionBlock);
    return make_shared<CImportVar>(loc, scope, var, functionBlock);
}

