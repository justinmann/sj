#include "Node.h"

shared_ptr<CVar> NChar::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    return make_shared<CConstantVar>(loc, thisFunction, compiler->typeChar, "'" + value + "'");
}
