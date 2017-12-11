#include "Node.h"
#include <sstream>

void NDot::defineImpl(Compiler *compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    left->define(compiler, thisFunction);
    right->define(compiler, thisFunction);
}

shared_ptr<CVar> NDot::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto leftVar = left->getVar(compiler, scope, dotVar, CTM_Undefined);
    if (!leftVar) {
        compiler->addError(loc, CErrorCode::InvalidDot, "left side of dot has no value");
        return nullptr;
    }

    auto rightVar = right->getVar(compiler, scope, leftVar, returnMode);
    if (!rightVar) {
        compiler->addError(loc, CErrorCode::InvalidDot, "right side of dot has no value");
        return nullptr;
    }

    return rightVar;
}
