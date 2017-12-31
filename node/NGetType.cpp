#include <sjc.h>


void NGetType::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
}

void NGetType::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
}

shared_ptr<CVar> NGetType::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
    auto ctype = scope->getVarType(loc, compiler, typeName, CTM_Undefined);
    if (!ctype) {
        compiler->addError(loc, CErrorCode::InvalidType, "type '%s' does not exist", typeName->valueName.c_str());
        return nullptr;
    }

    return make_shared<CConstantVar>(loc, scope, compiler->typeType, to_string(ctype->typeId));
}
