#include "Node.h"

bool CArrayVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CArrayVar::getType(Compiler* compiler) {
    return createArrayVar->getType(compiler);
}

void CArrayVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    createArrayVar->transpile(compiler, trOutput, trBlock, nullptr, thisValue, storeValue);
    auto arrayValue = storeValue->getValue();
    for (auto initAtVar : initAtVars) {
        auto returnType = initAtVar->getType(compiler);
        initAtVar->transpile(compiler, trOutput, trBlock, arrayValue, thisValue, trBlock->createVoidStoreVariable(loc, returnType));
    }
}


void CArrayVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "[";
    auto isFirst = true;
    for (auto initAtVar : initAtVars) {
        if (isFirst) {
            isFirst = false;
        } else {
            ss << ", ";
        }
        initAtVar->dump(compiler, dotVar, functions, ss, dotSS, level);
    }
    ss << "]";
}

void NArray::defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    for (auto element : *elements) {
        element->define(compiler, thisFunction);
    }
}

shared_ptr<CVar> NArray::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    if (returnMode != CTM_Heap) {
        returnMode = CTM_Stack;
    }

    auto firstElement = elements->front();
    if (firstElement == nullptr) {
        return nullptr;
    }

    // create and store array value
    auto elementVar = firstElement->getVar(compiler, scope, CTM_Undefined);
    if (!elementVar) {
        compiler->addError(loc, CErrorCode::InvalidType, "cannot determine type of first element");
        return nullptr;
    }
    
    auto elementType = elementVar->getType(compiler);
    if (!elementType) {
        return nullptr;
    }

    auto createArrayCallee = scope->function->getCFunction(compiler, loc, "array", scope, make_shared<CTypeNameList>(elementType->category, elementType->typeMode, elementType->valueName, elementType->isOption), returnMode);
    if (!createArrayCallee) {
        return nullptr;
    }

    auto createArrayParameters = CCallVar::getParameters(compiler, loc, scope, createArrayCallee, make_shared<NodeList>(make_shared<NInteger>(loc, elements->size())), returnMode);
    auto createArrayVar = CCallVar::create(compiler, loc, "array", createArrayParameters, scope, shared_ptr<CVar>(nullptr), createArrayCallee, returnMode);
    if (!createArrayVar) {
        return nullptr;
    }
    
    auto initAtCallee = createArrayCallee->getCFunction(compiler, loc, "initAt", scope, nullptr, CTM_Undefined);
    if (!initAtCallee) {
        return nullptr;
    }
    
    auto index = 0;
    vector<shared_ptr<CVar>> initAtVars;
    for (auto element : *elements) {
        auto initAtParameters = CCallVar::getParameters(compiler, loc, scope, initAtCallee, make_shared<NodeList>(make_shared<NInteger>(loc, index), element), returnMode);
        auto initAtVar = CCallVar::create(compiler, loc, "initAt", initAtParameters, scope, nullptr, initAtCallee, CTM_Stack);
        if (!initAtVar) {
            return nullptr;
        }

        initAtVars.push_back(initAtVar);
        index++;
    }

    return make_shared<CArrayVar>(loc, scope, createArrayVar, initAtVars);
}
