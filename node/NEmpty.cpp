#include "Node.h"

shared_ptr<CType> CEmptyVar::getType(Compiler* compiler, CResult& result) {
    return type;
}

void CEmptyVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto type = getType(compiler, result);
    type->transpileDefaultValue(compiler, result, loc, trBlock, storeValue);
}

void CEmptyVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    auto type = getType(compiler, result);
    ss << "empty'" << type->name;
}


NEmpty::NEmpty(CLoc loc, shared_ptr<CTypeName> typeName_) : NVariableBase(NodeType_Empty, loc), typeName(typeName_) {
    if (!typeName->isOption) {
        typeName->isOption = true;
        typeName->name = typeName->name + "?";
    }
}

shared_ptr<CVar> NEmpty::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto type = thisFunction->getVarType(compiler, result, typeName);
    if (!type) {
        result.addError(loc, CErrorCode::InvalidType, "cannot find type '%s'", typeName->getName().c_str());
        return nullptr;
    }

    return make_shared<CEmptyVar>(loc, type, thisFunction);
}

