#include "Node.h"

NArray::NArray(CLoc loc, shared_ptr<NodeList> elements_) : NBlock(loc), elements(elements_) {
}

void NArray::initStatements(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    if (statements.size() == 0) {
        auto firstElement = elements->front();
        if (firstElement != nullptr) {
            auto arrayName = "_array";
            
            // create and store array value
            auto elementType = firstElement->getType(compiler, result, thisFunction, thisVar);
            auto createArray = make_shared<NCall>(loc, "array", make_shared<CTypeNameList>(CTC_Value, elementType->name), make_shared<NodeList>(make_shared<NInteger>(loc, elements->size())));
            auto storeArray = make_shared<NAssignment>(loc, nullptr, nullptr, arrayName, createArray, false);
            statements.push_back(storeArray);
            
            auto index = 0;
            for (auto element : *elements) {
                auto setAtItem = make_shared<NDot>(loc,
                                                   make_shared<NVariable>(loc, arrayName),
                                                   make_shared<NCall>(loc,
                                                                      "setAt",
                                                                      nullptr,
                                                                      make_shared<NodeList>(make_shared<NInteger>(loc, index), element)));
                statements.push_back(setAtItem);
                index++;
            }
            
            // return return array value
            auto arrayVar = make_shared<NVariable>(loc, arrayName);
            statements.push_back(arrayVar);
        }
    }
}

shared_ptr<CVar> NArray::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    initStatements(compiler, result, thisFunction, thisVar);
    return NBlock::getVarImpl(compiler, result, thisFunction, thisVar);
}

shared_ptr<CType> NArray::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    initStatements(compiler, result, thisFunction, thisVar);
    return NBlock::getTypeImpl(compiler, result, thisFunction, thisVar);
}

