#include "Node.h"

shared_ptr<CVar> NChar::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    return make_shared<CConstantVar>(loc, scope, compiler->typeChar, "'" + value + "'");
}
