#include "Node.h"

void NTupleAssignment::defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    rightSide->define(compiler, importNamespaces, packageNamespace, thisFunction);
    for (auto arg : *args) {
        if (arg->var) {
            arg->var->define(compiler, importNamespaces, packageNamespace, thisFunction);
        }
    }
}

shared_ptr<CVar> NTupleAssignment::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto rightVar = rightSide->getVar(compiler, scope, CTM_Undefined);
    if (!rightVar) {
        return nullptr;
    }

    auto rightType = rightVar->getType(compiler);
    if (!rightType) {
        return nullptr;
    }

    if (rightType->parent.expired()) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "right side must be a function");
        return nullptr;
    }

    auto rightFunction = static_pointer_cast<CFunction>(rightType->parent.lock());
    if ((int)args->size() > rightFunction->getArgCount(rightType->typeMode)) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "right side has '%d' variables, but left side requires '%d'", rightFunction->getArgCount(rightType->typeMode), args->size());
        return nullptr;
    }

    auto tempVarName = TrBlock::nextVarName("tupleResult");
    vector<shared_ptr<CVar>> statements;
    auto getTupleVar = NAssignment(loc, nullptr, nullptr, tempVarName.c_str(), rightSide, AssignOp::immutableCreate).getVar(compiler, scope, CTM_Undefined);
    if (!getTupleVar) {
        return nullptr;
    }
    statements.push_back(getTupleVar);

    auto argIndex = 0;
    for (auto arg : *args) {
        auto rightArg = rightFunction->getArgVar(argIndex, rightType->typeMode);
        auto getValue = make_shared<NDot>(loc, make_shared<NVariable>(loc, tempVarName.c_str(), nullptr), make_shared<NVariable>(loc, rightArg->name.c_str(), nullptr));
        auto setValueVar = NAssignment(loc, arg->var, arg->typeName, arg->name.c_str(), getValue, arg->op).getVar(compiler, scope, CTM_Undefined);
        if (!setValueVar) {
            return nullptr;
        }
        statements.push_back(setValueVar);
        argIndex++;
    }

    return make_shared<CBlockVar>(loc, scope, statements);
}
