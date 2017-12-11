#include "Node.h"

bool CArrayVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CArrayVar::getType(Compiler* compiler) {
    return createArrayVar->getType(compiler);
}

void CArrayVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    createArrayVar->transpile(compiler, trOutput, trBlock, thisValue, storeValue);

    trBlock->statements.push_back(TrStatement(loc, storeValue->type->getLocalType()->cname + " " + name));
    auto arrayTemp = make_shared<TrStoreValue>(loc, scope.lock(), storeValue->type->getLocalType(), name, AssignOp::immutableCreate);
    arrayTemp->retainValue(compiler, loc, trBlock, storeValue->getValue());

    for (auto initAtVar : initAtVars) {
        auto returnType = initAtVar->getType(compiler);
        initAtVar->transpile(compiler, trOutput, trBlock, thisValue, trBlock->createVoidStoreVariable(loc, returnType));
    }
}


void CArrayVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "[";
    auto isFirst = true;
    for (auto initAtVar : initAtVars) {
        if (isFirst) {
            isFirst = false;
        } else {
            ss << ", ";
        }
        initAtVar->dump(compiler, functions, ss, level);
    }
    ss << "]";
}

bool CTempVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CTempVar::getType(Compiler* compiler) {
    return type;
}

void CTempVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto value = make_shared<TrValue>(scope.lock(), type, name, false);
    storeValue->retainValue(compiler, loc, trBlock, value);
}

void CTempVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
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

    auto tempName = TrBlock::nextVarName("array");

    auto createArrayCallee = scope->function->getCFunction(compiler, loc, "array", scope, make_shared<CTypeNameList>(elementType->category, elementType->typeMode, elementType->valueName, elementType->isOption), returnMode);
    if (!createArrayCallee) {
        return nullptr;
    }

    auto createArrayParameters = CCallVar::getParameters(compiler, loc, scope, createArrayCallee, make_shared<NodeList>(make_shared<NInteger>(loc, elements->size())), false, nullptr, returnMode);
    auto createArrayVar = CCallVar::create(compiler, loc, "array", nullptr, createArrayParameters, scope, createArrayCallee, returnMode);
    if (!createArrayVar) {
        return nullptr;
    }

    auto tempVar = make_shared<CTempVar>(loc, scope, createArrayCallee->getReturnType(compiler, returnMode)->getLocalType(), tempName);
    
    auto initAtCallee = createArrayCallee->getCFunction(compiler, loc, "initAt", scope, nullptr, CTM_Undefined);
    if (!initAtCallee) {
        return nullptr;
    }
    
    auto index = 0;
    vector<shared_ptr<CVar>> initAtVars;
    for (auto element : *elements) {
        auto initAtParameters = CCallVar::getParameters(compiler, loc, scope, initAtCallee, make_shared<NodeList>(make_shared<NInteger>(loc, index), element), false, nullptr, CTM_Stack);
        auto initAtVar = CCallVar::create(compiler, loc, "initAt", tempVar, initAtParameters, scope, initAtCallee, CTM_Stack);
        if (!initAtVar) {
            return nullptr;
        }

        initAtVars.push_back(initAtVar);
        index++;
    }

    return make_shared<CArrayVar>(loc, scope, createArrayVar, initAtVars, tempName);
}
