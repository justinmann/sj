#include "Node.h"

shared_ptr<CVar> NUnderscore::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto var = scope->getUnderscore();
    if (!var) {
        compiler->addError(loc, CErrorCode::InvalidVariable, "there is no _ var in this context");
        return nullptr;
    }
    return var;
}
