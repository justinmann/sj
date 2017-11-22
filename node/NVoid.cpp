#include "Node.h"

bool CVoidVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CVoidVar::getType(Compiler* compiler) {
    return compiler->typeVoid;
}

void CVoidVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
}

void CVoidVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "void";
}

shared_ptr<CVar> NVoid::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    return make_shared<CVoidVar>(loc, nullptr);
}

