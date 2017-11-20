#include "Node.h"

shared_ptr<CType> CVoidVar::getType(Compiler* compiler, CResult& result) {
    return compiler->typeVoid;
}

void CVoidVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
}

void CVoidVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "void";
}

shared_ptr<CVar> NVoid::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode) {
    return make_shared<CVoidVar>(loc, nullptr);
}

