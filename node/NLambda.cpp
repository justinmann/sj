#include "Node.h"

void NLambda::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) { 
    auto lambdaName = TrBlock::nextVarName("lambda");

    // Create invoke
    auto invokeFunction = make_shared<NFunction>(loc, nullptr, "invoke", nullptr, nullptr, nullptr, arguments, block, nullptr, nullptr, nullptr);

    // Create class
    auto lambdaArguments = make_shared<NodeList>();
    lambdaArguments->push_back(invokeFunction);
    auto classFunction = make_shared<NFunction>(loc, nullptr, lambdaName.c_str(), nullptr, nullptr, nullptr, lambdaArguments, make_shared<NThis>(loc), nullptr, nullptr, nullptr);
    classFunction->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);

    // Init class
    auto initArguments = make_shared<NodeList>();
    auto initFunction = make_shared<NCall>(loc, lambdaName, nullptr, initArguments);

    // Get callback
    auto getInvokeCallback = make_shared<NVariable>(loc, "invoke", nullptr);
    result = make_shared<NDot>(loc, initFunction, getInvokeCallback);

    result->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
}

void NLambda::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    result->initVars(compiler, scope, returnMode);
}

shared_ptr<CVar> NLambda::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    return result->getVar(compiler, scope, returnMode);
}
