#include "Node.h"

void NOptionDot::initStatements(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    if (statements.size() == 0) {
        assert(false);
    }
}

shared_ptr<CVar> NOptionDot::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar) {
    initStatements(compiler, result, thisFunction, thisVar);
    return NBlock::getVarImpl(compiler, result, thisFunction, thisVar, dotVar);
}

shared_ptr<CType> NOptionDot::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    initStatements(compiler, result, thisFunction, thisVar);
    return NBlock::getTypeImpl(compiler, result, thisFunction, thisVar);
}