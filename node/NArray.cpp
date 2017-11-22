#include "Node.h"

void NArray::defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    for (auto element : *elements) {
        element->define(compiler, thisFunction);
    }
}

shared_ptr<CVar> NArray::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    vector<shared_ptr<CVar>> statementVars;
    auto firstElement = elements->front();
    if (firstElement != nullptr) {
        auto arrayName = TrBlock::nextVarName("sjv_array");
        
        // create and store array value
        auto elementVar = firstElement->getVar(compiler, scope, CTM_Heap);
        auto elementType = elementVar->getType(compiler);
        if (elementType->typeMode != CTM_Heap) {
            compiler->addError(loc, CErrorCode::TypeMismatch, "arrays only support heap types");
            return nullptr;
        }
        
        auto createArray = make_shared<NCall>(loc, "array", make_shared<CTypeNameList>(elementType->category, elementType->typeMode, elementType->name, elementType->isOption), make_shared<NodeList>(make_shared<NInteger>(loc, elements->size())));
        auto storeArray = make_shared<NAssignment>(loc, nullptr, nullptr, arrayName.c_str(), createArray, ASSIGN_Immutable);
        statementVars.push_back(storeArray->getVar(compiler, scope, returnMode));
        
        auto index = 0;
        for (auto element : *elements) {
            auto setAtItem = make_shared<NDot>(loc,
                                               make_shared<NVariable>(loc, arrayName.c_str()),
                                               make_shared<NCall>(loc,
                                                                  "setAt",
                                                                  nullptr,
                                                                  make_shared<NodeList>(make_shared<NInteger>(loc, index), element)));
            statementVars.push_back(setAtItem->getVar(compiler, scope, nullptr, CTM_Heap));
            index++;
        }
        
        // return return array value
        auto arrayVar = make_shared<NVariable>(loc, arrayName.c_str());
        statementVars.push_back(arrayVar->getVar(compiler, scope, nullptr, returnMode));
    }
    return make_shared<CBlockVar>(loc, scope, statementVars);
}
