#include "Node.h"

shared_ptr<CType> NCCode::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    return compiler->typeVoid;
}

shared_ptr<ReturnValue> NCCode::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, stringstream& trLine) {
    trLine << code;
    return make_shared<ReturnValue>(compiler->typeVoid, RVR_MustRetain);
}

void NCCode::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << code;
}

