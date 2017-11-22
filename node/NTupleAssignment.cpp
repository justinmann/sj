#include "Node.h"

void NTupleAssignment::defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    rightSide->define(compiler, thisFunction);
    for (auto arg : *args) {
        if (arg->var == nullptr) {
            compiler->addError(loc, CErrorCode::InvalidVariable, "left side of tuple assignment is missing a variable");
            return;
        }
        arg->var->define(compiler, thisFunction);
    }
}

shared_ptr<CVar> NTupleAssignment::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto rightVar = rightSide->getVar(compiler, scope, nullptr, CTM_Undefined);
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
    statements.push_back(NAssignment(loc, nullptr, nullptr, tempVarName.c_str(), rightSide, ASSIGN_Immutable).getVar(compiler, scope, CTM_Undefined));

    auto argIndex = 0;
    for (auto arg : *args) {
        auto rightArg = rightFunction->getArgVar(argIndex, rightType->typeMode);
        auto getValue = make_shared<NDot>(loc, make_shared<NVariable>(loc, tempVarName.c_str()), make_shared<NVariable>(loc, rightArg->name.c_str()));
        statements.push_back(NAssignment(loc, arg->var, arg->typeName, arg->name.c_str(), getValue, arg->assignOp).getVar(compiler, scope, CTM_Undefined));
        argIndex++;
    }

    return make_shared<CBlockVar>(loc, scope, statements);
}
