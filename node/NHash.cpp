#include "Node.h"

bool CHashVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CHashVar::getType(Compiler* compiler) {
    return createHashVar->getType(compiler);
}

void CHashVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    createHashVar->transpile(compiler, trOutput, trBlock, thisValue, storeValue);

    trBlock->statements.push_back(TrStatement(loc, storeValue->type->getTempType()->cname + " " + name));
    auto arrayTemp = make_shared<TrStoreValue>(loc, scope.lock(), storeValue->type->getTempType(), name, AssignOp::immutableCreate);
    arrayTemp->retainValue(compiler, loc, trBlock, storeValue->getValue());

    auto returnType = resizeHashVar->getType(compiler);
    resizeHashVar->transpile(compiler, trOutput, trBlock, thisValue, trBlock->createVoidStoreVariable(loc, returnType));

    for (auto setAtVar : setAtVars) {
        returnType = setAtVar->getType(compiler);
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

void NHash::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    for (auto element : elements) {
        element.first->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
        element.second->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    }
}

void NHash::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    for (auto element : elements) {
        element.first->initVars(compiler, scope, returnMode);
        element.second->initVars(compiler, scope, returnMode);
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

    auto createHashParameters = CCallVar::getParameters(compiler, loc, scope, createHashCallee, CallArgument::emptyList, false, nullptr, returnMode);
    auto createHashVar = make_shared<CCallVar>(loc, scope, nullptr, createHashParameters, createHashCallee, returnMode);
    if (!createHashVar) {
        return nullptr;
    }

    auto resizeCallee = createHashCallee->getCFunction(compiler, loc, "resize", scope, nullptr, CTM_Undefined);
    if (!resizeCallee) {
        return nullptr;
    }

    auto tempVar = make_shared<CTempVar>(loc, scope, createHashCallee->getReturnType(compiler, returnMode)->getTempType(), tempName);

    int buckets = (int)(((double)elements.size() - 0.5) / 0.77);
    auto resizeHashParameters = CCallVar::getParameters(compiler, loc, scope, resizeCallee, CallArgument::createList(make_shared<CConstantVar>(loc, scope, compiler->typeI32, to_string(buckets))), false, nullptr, CTM_Stack);
    auto resizeHashVar = make_shared<CCallVar>(loc, scope, tempVar, resizeHashParameters, resizeCallee, CTM_Stack);
    if (!resizeHashVar) {
        return nullptr;
    }

    auto setAtCallee = createHashCallee->getCFunction(compiler, loc, "setat", scope, nullptr, CTM_Undefined);
    if (!setAtCallee) {
        return nullptr;
    }
    
    auto index = 0;
    vector<shared_ptr<CVar>> setAtVars;
    for (auto element : elements) {
        auto setAtParameters = CCallVar::getParameters(compiler, loc, scope, setAtCallee, CallArgument::createList(element.first->getVar(compiler, scope, CTM_Undefined), element.second->getVar(compiler, scope, CTM_Undefined)), false, nullptr, CTM_Stack);
        auto setAtVar = make_shared<CCallVar>(loc, scope, tempVar, setAtParameters, setAtCallee, CTM_Stack);
        if (!setAtVar) {
            return nullptr;
        }

        setAtVars.push_back(setAtVar);
        index++;
    }

    return make_shared<CHashVar>(loc, scope, createHashVar, resizeHashVar, setAtVars, tempName);
}
