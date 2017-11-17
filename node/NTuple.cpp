#include "Node.h"

NTuple::NTuple(CLoc loc, shared_ptr<NodeList> elements_) : NBlock(loc), elements(elements_) {
}

void NTuple::initStatements(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, CTypeReturnMode returnMode) {
    if (statements.size() == 0) {
        if (elements->size() == 0) {
            result.addError(loc, CErrorCode::TypeMismatch, "tuple must have at least 1 value");
            return;
        }

        if (elements->size() > 4) {
            result.addError(loc, CErrorCode::TypeMismatch, "tuple must have 4 or less value4");
            return;
        }

        auto typeNameList = make_shared<CTypeNameList>();
        for (auto element : *elements) {
            auto ctype = element->getType(compiler, result, thisFunction, thisVar, returnMode);
            typeNameList->push_back(make_shared<CTypeName>(ctype));
        }

        // create and store Tuple value
        auto createTuple = make_shared<NCall>(loc, (string("tuple") + to_string(elements->size())).c_str(), typeNameList, elements);
        statements.push_back(createTuple);
    }
}

shared_ptr<CVar> NTuple::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, CTypeReturnMode returnMode) {
    initStatements(compiler, result, thisFunction, thisVar, returnMode);
    return NBlock::getVarImpl(compiler, result, thisFunction, thisVar, dotVar, returnMode);
}

shared_ptr<CType> NTuple::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, CTypeReturnMode returnMode) {
    initStatements(compiler, result, thisFunction, thisVar, returnMode);
    return NBlock::getTypeImpl(compiler, result, thisFunction, thisVar, returnMode);
}

