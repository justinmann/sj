#include "Node.h"

void NTuple::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    for (auto element : *elements) {
        element->define(compiler, result, thisFunction);
    }
}


shared_ptr<CVar> NTuple::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    if (elements->size() == 0) {
        result.addError(loc, CErrorCode::TypeMismatch, "tuple must have at least 1 value");
        return nullptr;
    }

    if (elements->size() > 4) {
        result.addError(loc, CErrorCode::TypeMismatch, "tuple must have 4 or less value4");
        return nullptr;
    }

    auto typeNameList = make_shared<CTypeNameList>();
    for (auto element : *elements) {
        auto elementVar = element->getVar(compiler, result, thisFunction, thisVar, CTM_Undefined);
        auto ctype = elementVar->getType(compiler, result);
        typeNameList->push_back(make_shared<CTypeName>(ctype));
    }

    // create and store Tuple value
    auto createTuple = make_shared<NCall>(loc, (string("tuple") + to_string(elements->size())).c_str(), typeNameList, elements);
    return createTuple->getVar(compiler, result, thisFunction, thisVar, dotVar, returnMode);
}

