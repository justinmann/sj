#include "Node.h"

bool CEmptyVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CEmptyVar::getType(Compiler* compiler) {
    return type;
}

void CEmptyVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto type = getType(compiler);
    type->transpileDefaultValue(compiler, loc, trBlock, storeValue);
}

void CEmptyVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    auto type = getType(compiler);
    ss << "empty'" << type->fullName;
}


NEmpty::NEmpty(CLoc loc, shared_ptr<CTypeName> typeName_) : NVariableBase(NodeType_Empty, loc), typeName(typeName_) {
    if (!typeName->isOption) {
        typeName->isOption = true;
    }
}

shared_ptr<CVar> NEmpty::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
    auto type = scope->getVarType(loc, compiler, typeName, returnMode);
    if (!type) {
        compiler->addError(loc, CErrorCode::InvalidType, "cannot find type '%s'", typeName->getFullName().c_str());
        return nullptr;
    }

    if (!type->isOption) {
        type = type->getOptionType();
    }

    return make_shared<CEmptyVar>(loc, type, scope);
}

