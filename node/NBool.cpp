#include "Node.h"

shared_ptr<CVar> NBool::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, CTypeReturnMode returnMode) {
    return make_shared<CConstantVar>(loc, compiler->typeBool, bool_to_str(value));
}
