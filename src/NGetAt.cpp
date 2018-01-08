#include <sjc.h>

void NGetAt::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    left->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    index->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
}

void NGetAt::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    left->initVars(compiler, scope, returnMode);
    index->initVars(compiler, scope, returnMode);
}

shared_ptr<CVar> NGetAt::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
    auto leftVar = left->getVar(compiler, scope, nullptr, returnType, CTM_Undefined);
    if (!leftVar) {
        return nullptr;
    }

    auto leftType = leftVar->getType(compiler);
    if (!leftType) {
        return nullptr;
    }

    if (!leftType->isOption) {
        auto temp = NDot(loc, left, make_shared<NCall>(loc, "getAt", nullptr, make_shared<NodeList>(index)));
        return temp.getVar(compiler, scope, nullptr, returnType, returnMode);
    } else {
        auto temp = NOptionDot(loc, left, make_shared<NCall>(loc, "getAt", nullptr, make_shared<NodeList>(index)));
        return temp.getVar(compiler, scope, nullptr, returnType, returnMode);        
    }
}
