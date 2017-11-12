#include "Node.h"

void NTupleAssignment::initStatements(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    if (statements.size() == 0) {
        auto rightType = rightSide->getType(compiler, result, thisFunction, thisVar);
        if (!rightType) {
            return;
        }

        if (rightType->parent.expired()) {
            result.addError(loc, CErrorCode::TypeMismatch, "right side must be a function");
            return;
        }

        auto rightFunction = static_pointer_cast<CFunction>(rightType->parent.lock());
        if (args->size() > rightFunction->argVars.size()) {
            result.addError(loc, CErrorCode::TypeMismatch, "right side has '%d' variables, but left side requires '%d'", rightFunction->argVars.size(), args->size());
            return;
        }

        auto tempVarName = TrBlock::nextVarName("tupleResult");
        statements.push_back(make_shared<NAssignment>(loc, nullptr, nullptr, tempVarName.c_str(), rightSide, false));

        auto argIndex = 0;
        for (auto arg : *args) {
            auto rightArg = rightFunction->argVars[argIndex];
            auto getValue = make_shared<NDot>(loc, make_shared<NVariable>(loc, tempVarName.c_str()), make_shared<NVariable>(loc, rightArg->name.c_str()));
            statements.push_back(make_shared<NAssignment>(loc, arg->var, arg->typeName, arg->name.c_str(), getValue, arg->isMutable));
            argIndex++;
        }
    }
}

shared_ptr<CVar> NTupleAssignment::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar) {
    initStatements(compiler, result, thisFunction, thisVar);
    return NBlock::getVarImpl(compiler, result, thisFunction, thisVar, dotVar);
}

shared_ptr<CType> NTupleAssignment::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    initStatements(compiler, result, thisFunction, thisVar);
    return NBlock::getTypeImpl(compiler, result, thisFunction, thisVar);
}