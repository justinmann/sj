#include "Node.h"

void NTupleAssignment::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    rightSide->define(compiler, result, thisFunction);
    for (auto arg : *args) {
        if (arg->var == nullptr) {
            result.addError(loc, CErrorCode::InvalidVariable, "left side of tuple assignment is missing a variable");
            return;
        }
        arg->var->define(compiler, result, thisFunction);
    }
}

shared_ptr<CVar> NTupleAssignment::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar) {
    auto rightVar = rightSide->getVar(compiler, result, thisFunction, thisVar, nullptr);
    if (!rightVar) {
        return nullptr;
    }

    auto rightType = rightVar->getType(compiler, result, CTM_Undefined);
    if (!rightType) {
        return nullptr;
    }

    if (rightType->parent.expired()) {
        result.addError(loc, CErrorCode::TypeMismatch, "right side must be a function");
        return nullptr;
    }

    auto rightFunction = static_pointer_cast<CFunction>(rightType->parent.lock());
    if (args->size() > rightFunction->argVars.size()) {
        result.addError(loc, CErrorCode::TypeMismatch, "right side has '%d' variables, but left side requires '%d'", rightFunction->argVars.size(), args->size());
        return nullptr;
    }

    auto tempVarName = TrBlock::nextVarName("tupleResult");
    vector<shared_ptr<CVar>> statements;
    statements.push_back(NAssignment(loc, nullptr, nullptr, tempVarName.c_str(), rightSide, ASSIGN_Immutable).getVar(compiler, result, thisFunction, thisVar));

    auto argIndex = 0;
    for (auto arg : *args) {
        auto rightArg = rightFunction->argVars[argIndex];
        auto getValue = make_shared<NDot>(loc, make_shared<NVariable>(loc, tempVarName.c_str()), make_shared<NVariable>(loc, rightArg->name.c_str()));
        statements.push_back(NAssignment(loc, arg->var, arg->typeName, arg->name.c_str(), getValue, arg->assignOp).getVar(compiler, result, thisFunction, thisVar));
        argIndex++;
    }

    return make_shared<CBlockVar>(loc, statements);
}
