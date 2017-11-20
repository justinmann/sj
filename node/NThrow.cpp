#include "Node.h"

shared_ptr<CType> CThrowVar::getType(Compiler* compiler, CResult& result) {
    return compiler->typeVoid;
}

void CThrowVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    assert(false);
}

void CThrowVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "throw";
}

void NThrow::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NThrow::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode) {
    auto var = node->getVar(compiler, result, thisFunction, thisVar, CTM_Undefined);
    if (!var) {
        return nullptr;
    }
    return make_shared<CThrowVar>(loc, nullptr, var);
}

