#include "Node.h"

shared_ptr<CVar> NArray::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar) {
    vector<shared_ptr<CVar>> statementVars;
    auto firstElement = elements->front();
    if (firstElement != nullptr) {
        auto arrayName = TrBlock::nextVarName("sjv_array");
        
        // create and store array value
        auto elementVar = firstElement->getVar(compiler, result, thisFunction, thisVar);
        auto elementType = elementVar->getType(compiler, result);
        if (elementType->typeMode != CTM_Heap) {
            result.addError(loc, CErrorCode::TypeMismatch, "arrays only support heap types");
            return nullptr;
        }
        
        auto createArray = make_shared<NCall>(loc, "array", make_shared<CTypeNameList>(elementType->category, elementType->typeMode, elementType->name, elementType->isOption), make_shared<NodeList>(make_shared<NInteger>(loc, elements->size())));
        auto storeArray = make_shared<NAssignment>(loc, nullptr, nullptr, arrayName.c_str(), createArray, false);
        statementVars.push_back(storeArray->getVar(compiler, result, thisFunction, thisVar));
        
        auto index = 0;
        for (auto element : *elements) {
            auto setAtItem = make_shared<NDot>(loc,
                                               make_shared<NVariable>(loc, arrayName.c_str()),
                                               make_shared<NCall>(loc,
                                                                  "setAt",
                                                                  nullptr,
                                                                  make_shared<NodeList>(make_shared<NInteger>(loc, index), element)));
            statementVars.push_back(setAtItem->getVar(compiler, result, thisFunction, thisVar, nullptr));
            index++;
        }
        
        // return return array value
        auto arrayVar = make_shared<NVariable>(loc, arrayName.c_str());
        statementVars.push_back(arrayVar->getVar(compiler, result, thisFunction, thisVar, nullptr));
    }
    return make_shared<CBlockVar>(loc, statementVars);
}
