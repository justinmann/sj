#include "Node.h"

void NEnum::defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    // create a new type
    auto ctypes = CType::create(name, "int32_t", "(int32_t)0", "int32_option", "int32_empty");
    compiler->types[name] = ctypes;
}

shared_ptr<CVar> NEnum::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto ctypes = compiler->types[name];

    // create constants in a package namespace
    vector<string> enumNamespace;
    vector<shared_ptr<CVar>> statementVars;
    enumNamespace.push_back(name);
    scope->pushNamespace(compiler, enumNamespace);
    auto index = 0;
    for (auto enumArg : *enumArgs) {
        auto leftVar = scope->getCVar(compiler, nullptr, enumArg->name, VSM_LocalThisParent);
        if (leftVar) {
            compiler->addError(loc, CErrorCode::ImmutableAssignment, "var '%s' already exists", name.c_str());
            return nullptr;
        }

        string nameNS;
        bool isFirst = true;
        for (auto ns : scope->dotNamespace) {
            if (isFirst) {
                isFirst = false;
            }
            else {
                nameNS += "_";
            }
            nameNS += ns;
        }
        if (!isFirst) {
            nameNS += "_";
        }
        nameNS += enumArg->name;

        auto leftStoreVar = make_shared<CNormalVar>(loc, scope, ctypes->stackValueType, nameNS, false, CVarType::Var_Local);
        scope->addOrUpdateLocalVar(compiler, enumArg->name, leftStoreVar);
        stringstream t;
        t << index;
        auto rightVar = make_shared<CConstantVar>(loc, scope, ctypes->stackValueType, enumArg->hasValue ? enumArg->value : t.str());
        auto assignVar = make_shared<CAssignVar>(loc, scope, AssignOp::immutableCreate, leftStoreVar, rightVar);
        statementVars.push_back(assignVar);
        index++;
    }
    scope->popNamespace(compiler, enumNamespace);

    return make_shared<CBlockVar>(loc, scope, statementVars);
}

