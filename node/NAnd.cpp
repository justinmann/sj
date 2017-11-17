#include "Node.h"

void NAnd::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    left->define(compiler, result, thisFunction);
    right->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NAnd::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, CTypeReturnMode returnMode) {
    assert(compiler->state == CompilerState::FixVar);
    left->getVar(compiler, result, thisFunction, thisVar, nullptr, returnMode);
    right->getVar(compiler, result, thisFunction, thisVar, nullptr, returnMode);
    return nullptr;
}

shared_ptr<CType> NAnd::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, CTypeReturnMode returnMode) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeBool;
}

shared_ptr<ReturnValue> NAnd::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, const char* thisName) {
	assert(false);
	return nullptr;
}

void NAnd::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, CTypeReturnMode returnMode, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    left->dump(compiler, result, thisFunction, thisVar, returnMode, functions, ss, level);
    ss << " && ";
    right->dump(compiler, result, thisFunction, thisVar, returnMode, functions, ss, level);
}
