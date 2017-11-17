#include "Node.h"

shared_ptr<CType> CEmptyVar::getType(Compiler* compiler, CResult& result, CTypeReturnMode returnMode) {
    return type;
}

shared_ptr<ReturnValue> CEmptyVar::transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    return type->transpileDefaultValue(compiler, result, thisFunction, thisVar);
}

void CEmptyVar::transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) {
    assert(false);
}

void CEmptyVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, CTypeReturnMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "empty'" << type->name;
}


NEmpty::NEmpty(CLoc loc, shared_ptr<CTypeName> typeName_) : NVariableBase(NodeType_Empty, loc), typeName(typeName_) {
    if (!typeName->isOption) {
        typeName->isOption = true;
        typeName->name = typeName->name + "?";
    }
}

shared_ptr<CVar> NEmpty::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, CTypeReturnMode returnMode) {
    auto ctype = thisFunction->getVarType(compiler, result, typeName);
    if (!ctype) {
        result.addError(loc, CErrorCode::InvalidType, "cannot find type '%s'", typeName->getName().c_str());
        return nullptr;
    }
    
    return make_shared<CEmptyVar>(loc, ctype);
}

