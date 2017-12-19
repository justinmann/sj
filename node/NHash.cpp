#include "Node.h"

bool CHashVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CHashVar::getType(Compiler* compiler) {
    return createHashVar->getType(compiler);
}

void CHashVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    createHashVar->transpile(compiler, trOutput, trBlock, thisValue, storeValue);

    trBlock->statements.push_back(TrStatement(loc, storeValue->type->getLocalType()->cname + " " + name));
    auto arrayTemp = make_shared<TrStoreValue>(loc, scope.lock(), storeValue->type->getLocalType(), name, AssignOp::immutableCreate);
    arrayTemp->retainValue(compiler, loc, trBlock, storeValue->getValue());

    for (auto setAtVar : setAtVars) {
        auto returnType = setAtVar->getType(compiler);
        setAtVar->transpile(compiler, trOutput, trBlock, thisValue, trBlock->createVoidStoreVariable(loc, returnType));
    }
}


void CHashVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "{";
    auto isFirst = true;
    for (auto setAtVar : setAtVars) {
        if (isFirst) {
            isFirst = false;
        } else {
            ss << ", ";
        }
        setAtVar->dump(compiler, functions, ss, level);
    }
    ss << "}";
}

void NHash::defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    for (auto element : elements) {
        element.first->define(compiler, importNamespaces, packageNamespace, thisFunction);
        element.second->define(compiler, importNamespaces, packageNamespace, thisFunction);
    }
}

shared_ptr<CVar> NHash::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    if (returnMode != CTM_Heap) {
        returnMode = CTM_Stack;
    }

    if (elements.size() == 0) {
        compiler->addError(loc, CErrorCode::InvalidType, "cannot determine type of first element");
        return nullptr;
    }

    auto firstPair = elements.front();
    // create and store array value
    auto keyVar = firstPair.first->getVar(compiler, scope, CTM_Undefined);
    if (!keyVar) {
        compiler->addError(loc, CErrorCode::InvalidType, "cannot determine type of first key element");
        return nullptr;
    }
    
    auto keyType = keyVar->getType(compiler);
    if (!keyType) {
        return nullptr;
    }

    auto valueVar = firstPair.second->getVar(compiler, scope, CTM_Undefined);
    if (!valueVar) {
        compiler->addError(loc, CErrorCode::InvalidType, "cannot determine type of first value element");
        return nullptr;
    }

    auto valueType = valueVar->getType(compiler);
    if (!valueType) {
        return nullptr;
    }

    auto tempName = TrBlock::nextVarName("hash");

    auto typeNameList = make_shared<CTypeNameList>();
    typeNameList->push_back(make_shared<CTypeName>(keyType->category, keyType->typeMode, keyType->packageNamespace, keyType->valueName, keyType->isOption));
    typeNameList->push_back(make_shared<CTypeName>(valueType->category, valueType->typeMode, valueType->packageNamespace, valueType->valueName, valueType->isOption));

    auto createHashCallee = scope->function->getCFunction(compiler, loc, "hash", scope, typeNameList, returnMode);
    if (!createHashCallee) {
        return nullptr;
    }

    auto createHashParameters = CCallVar::getParameters(compiler, loc, scope, createHashCallee, make_shared<NodeList>(/*make_shared<NInteger>(loc, elements->size())*/), false, nullptr, returnMode);
    auto createHashVar = CCallVar::create(compiler, loc, "hash", nullptr, createHashParameters, scope, createHashCallee, returnMode);
    if (!createHashVar) {
        return nullptr;
    }

    auto tempVar = make_shared<CTempVar>(loc, scope, createHashCallee->getReturnType(compiler, returnMode)->getLocalType(), tempName);
    
    auto setAtCallee = createHashCallee->getCFunction(compiler, loc, "setat", scope, nullptr, CTM_Undefined);
    if (!setAtCallee) {
        return nullptr;
    }
    
    auto index = 0;
    vector<shared_ptr<CVar>> setAtVars;
    for (auto element : elements) {
        auto setAtParameters = CCallVar::getParameters(compiler, loc, scope, setAtCallee, make_shared<NodeList>(element.first, element.second), false, nullptr, CTM_Stack);
        auto setAtVar = CCallVar::create(compiler, loc, "initat", tempVar, setAtParameters, scope, setAtCallee, CTM_Stack);
        if (!setAtVar) {
            return nullptr;
        }

        setAtVars.push_back(setAtVar);
        index++;
    }

    return make_shared<CHashVar>(loc, scope, createHashVar, setAtVars, tempName);
}
