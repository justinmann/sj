#include "Node.h"

NEmpty::NEmpty(CLoc loc, shared_ptr<CTypeName> typeName_) : NVariableBase(NodeType_Empty, loc), typeName(typeName_) {
    if (!typeName->isOption) {
        typeName->isOption = true;
        typeName->name = typeName->name + "?";
    }
}

shared_ptr<CType> NEmpty::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    auto ctype = thisFunction->getVarType(compiler, result, typeName);
    if (!ctype) {
        result.addError(loc, CErrorCode::InvalidType, "cannot find type '%s'", typeName->getName().c_str());
        return nullptr;
    }
    return ctype;
}

shared_ptr<ReturnValue> NEmpty::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue, const char* thisName) {
    auto ctype = getType(compiler, result, thisFunction, thisVar);
    if (!ctype) {
        result.addError(loc, CErrorCode::InvalidType, "cannot find type '%s'", typeName->getName().c_str());
        return nullptr;
    }

    return ctype->transpileDefaultValue(compiler, result, thisFunction, thisVar);
}

void NEmpty::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "empty'" << typeName->getName();
}
