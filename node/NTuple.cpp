#include "Node.h"

void NTuple::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    for (auto element : *elements) {
        element->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    }
}

void NTuple::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    for (auto element : *elements) {
        element->initVars(compiler, scope, returnMode);
    }
}

shared_ptr<CVar> NTuple::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
    if (elements->size() == 0) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "tuple must have at least 1 value");
        return nullptr;
    }

    if (elements->size() > 4) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "tuple must have 4 or less value4");
        return nullptr;
    }

    auto typeNameList = make_shared<CTypeNameList>();
    for (auto element : *elements) {
        auto elementVar = element->getVar(compiler, scope, nullptr, CTM_Undefined);
        auto ctype = elementVar->getType(compiler);
        typeNameList->push_back(make_shared<CTypeName>(ctype));
    }

    // create and store Tuple value
    auto createTuple = make_shared<NCall>(loc, (string("tuple") + to_string(elements->size())).c_str(), typeNameList, elements);
    return createTuple->getVar(compiler, scope, dotVar, nullptr, returnMode);
}

