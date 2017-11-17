#include "Node.h"

void NThrow::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NThrow::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar) {
    node->getVar(compiler, result, thisFunction, thisVar);
    return nullptr;
}

shared_ptr<CType> NThrow::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeReturnMode returnMode) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeVoid;
}

shared_ptr<ReturnValue> NThrow::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, const char* thisName) {
	assert(false);
	return nullptr;
}

void NThrow::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeReturnMode returnMode, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "throw";
}
