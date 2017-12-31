#include <sjc.h>


bool CVoidVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CVoidVar::getType(Compiler* compiler) {
    return compiler->typeVoid;
}

void CVoidVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
}

void CVoidVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "void";
}

shared_ptr<CVar> NVoid::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CType> returnType, CTypeMode returnMode) {
    return make_shared<CVoidVar>(loc, nullptr);
}

