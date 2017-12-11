#include "Node.h"

CCallbackVar::CCallbackVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type, shared_ptr<CVar> dotVar, shared_ptr<CCallback> callback, shared_ptr<CBaseFunction> function, CTypeMode returnMode) : 
    CVar(loc, scope), type(type), dotVar(dotVar), callback(callback), function(function), returnMode(returnMode) { 
}

bool CCallbackVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CCallbackVar::getType(Compiler* compiler) {
    return type;
}

void CCallbackVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    callback->transpileDefinition(compiler, trOutput);
    function->transpileDefinition(compiler, trOutput);
    
    if (!CType::isSameExceptMode(storeValue->type, type)) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "right type '%s' does not match left type '%s'", storeValue->type->fullName.c_str(), type->fullName.c_str());
        return;
    }

    string name = storeValue->getName(trBlock);
    if (storeValue->type->typeMode == CTM_Heap) {
        name += ".inner";
    }

    if (dotVar) {
        if (storeValue->type->typeMode == CTM_Heap) {
            auto tempName = TrBlock::nextVarName("callback");
            auto dotType = dotVar->getType(compiler)->getHeapType();
            trBlock->statements.push_back(TrStatement(loc, dotType->cname + " " + tempName));
            auto parentValue = make_shared<TrStoreValue>(loc, scope.lock(), dotType, tempName, AssignOp::immutableCreate);
            dotVar->transpile(compiler, trOutput, trBlock, thisValue, parentValue);
            trBlock->statements.push_back(TrStatement(loc, name + "._parent = (void*)" + TrValue::convertToLocalName(dotType, tempName, false)));
            trBlock->statements.push_back(TrStatement(loc, storeValue->getName(trBlock) + "._destroy = (void(*)(void*))" + dotType->parent.lock()->getCDestroyFunctionName()));
        }
        else {
            auto parentValue = make_shared<TrStoreValue>(loc, scope.lock(), dotVar->getType(compiler)->getLocalType(), name + "._parent", AssignOp::immutableCreate);
            dotVar->transpile(compiler, trOutput, trBlock, thisValue, parentValue);
        }
    }
    else {
        trBlock->statements.push_back(TrStatement(loc, name + "._parent = (void*)1"));
    }

    if (callback->stackReturnType) {
        string functionName = function->getCCallbackFunctionName(compiler, trOutput, CTM_Stack);
        trBlock->statements.push_back(TrStatement(loc, name + "._cb = (" + callback->getCBName(compiler, false, CTM_Stack) + ")" + functionName));
    }
    if (callback->heapReturnType) {
        string functionName = function->getCCallbackFunctionName(compiler, trOutput, CTM_Heap);
        trBlock->statements.push_back(TrStatement(loc, name + "._cb_heap = (" + callback->getCBName(compiler, false, CTM_Heap) + ")" + functionName));
    }

    storeValue->hasSetValue = true;
}

void CCallbackVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {

}

CCallbackFunction::CCallbackFunction(shared_ptr<CCallback> callback, shared_ptr<CVar> callbackVar) : CBaseFunction(CFT_Callback, string("INVALID"), weak_ptr<CBaseFunction>(), weak_ptr<CBaseFunctionDefinition>(), false), callback(callback), callbackVar(callbackVar) {
    auto argIndex = 0;
    for (auto argType : callback->argTypes) {
        string argName = "param" + argIndex;
        auto argVar = make_shared<CNormalVar>(CLoc::undefined, nullptr, argType, argName, false, CVarType::Var_Public);
        argVars.push_back(argVar);
        argIndex++;
    }
}

int CCallbackFunction::getArgIndex(const string& name, CTypeMode returnMode) {
    return -1;
}

int CCallbackFunction::getArgCount(CTypeMode returnMode) {
    return (int)callback->argTypes.size();
}

shared_ptr<CVar> CCallbackFunction::getArgVar(int index, CTypeMode returnMode) {
    return argVars[index];
}

string CCallbackFunction::fullName(bool includeTemplateTypes) {
    return callbackVar->name;
}

shared_ptr<CTypes> CCallbackFunction::getThisTypes(Compiler* compiler) {
    assert(false);
    return nullptr;
}

shared_ptr<CVar> CCallbackFunction::getCVar(Compiler* compiler, vector<shared_ptr<FunctionBlock>> functionBlocks, const string& name, VarScanMode scanMode, CTypeMode returnMode) {
    assert(false);
    return nullptr;
}

shared_ptr<CBaseFunction> CCallbackFunction::getCFunction(Compiler* compiler, CLoc locCaller, const string& name, shared_ptr<CScope> callerScope, shared_ptr<CTypeNameList> templateTypeNames, CTypeMode returnMode) {
    assert(false);
    return nullptr;
}

shared_ptr<CType> CCallbackFunction::getVarType(CLoc loc, Compiler* compiler, shared_ptr<CTypeName> typeName, CTypeMode defaultMode) {
    assert(false);
    return nullptr;
}

string CCallbackFunction::getCFunctionName(CTypeMode returnMode) {
    assert(false);
    return "INVALID";
}

string CCallbackFunction::getCCallbackFunctionName(Compiler* compiler, TrOutput* trOutput, CTypeMode returnMode) {
    assert(false);
    return "INVALID";
}

string CCallbackFunction::getCCopyFunctionName() {
    assert(false);
    return "INVALID";
}

string CCallbackFunction::getCDestroyFunctionName() {
    assert(false);
    return "INVALID";
}

string CCallbackFunction::getCStructName(CTypeMode typeMode) {
    assert(false);
    return "INVALID";
}

pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>> CCallbackFunction::getFunctionDefinition(string name) {
    assert(false);
    return make_pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>>(nullptr, nullptr);
}

bool CCallbackFunction::getIsReturnModeValid(Compiler* compiler, CTypeMode returnMode) {
    if (returnMode == CTM_Heap) {
        return callback->heapReturnType != nullptr;
    }
    else {
        return callback->stackReturnType != nullptr;
    }
}

shared_ptr<CType> CCallbackFunction::getReturnType(Compiler* compiler, CTypeMode returnMode) {
    if (returnMode == CTM_Heap) {
        return callback->heapReturnType;
    }
    else {
        return callback->stackReturnType;
    }
}

void CCallbackFunction::transpileDefinition(Compiler* compiler, TrOutput* trOutput) {
    assert(false);
}

void CCallbackFunction::transpile(Compiler* compiler, shared_ptr<CScope> callerScope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<CVar> parentVar, CLoc& calleeLoc, shared_ptr<vector<FunctionParameter>> parameters, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue, CTypeMode returnMode) {
    if (returnMode == CTM_Heap) {
        if (!callback->heapReturnType) {
            returnMode = CTM_Stack;
        }
    }
    else {
        if (!callback->stackReturnType) {
            compiler->addError(calleeLoc, CErrorCode::InvalidType, "no stack return available");
        }
    }

    auto callbackValue = trBlock->createTempStoreVariable(calleeLoc, callerScope, callback->types->localValueType, "callback");
    callbackVar->transpile(compiler, trOutput, trBlock, thisValue, callbackValue);
    
    stringstream line;
    line << callbackValue->getName(trBlock) << ".";
    if (returnMode == CTM_Heap) {
        line << "_cb_heap";
    }
    else {
        line << "_cb";
    }
    line << "(";
    bool isFirstParameter = true;

    // Add "parent" to "this"
    line << callbackValue->getName(trBlock) << "._parent";

    // Fill in "this" with normal arguments
    for (auto parameter : *parameters) {
        stringstream argStream;
        auto parameterVar = parameter.var;
        if (!parameterVar) {
            assert(compiler->errors.size() > 0);
            return;
        }

        auto argType = parameter.var->getType(compiler);
        auto argStoreValue = trBlock->createTempStoreVariable(calleeLoc, callerScope, argType->typeMode == CTM_Heap ? argType : argType->getLocalValueType(), "functionParam");
        parameterVar->transpile(compiler, trOutput, trBlock, thisValue, argStoreValue);

        if (!argStoreValue->hasSetValue) {
            compiler->addError(calleeLoc, CErrorCode::TypeMismatch, "parameter '%s' has no value", parameterVar->name.c_str());
            return;
        }

        line << ", ";
        line << argStoreValue->getName(trBlock);
    }

    // Call function
    auto returnType = (returnMode == CTM_Heap) ? callback->heapReturnType : callback->stackReturnType;
    if (returnType != compiler->typeVoid) {
        line << ", ";
        if (storeValue->isReturnValue) {
            line << "_return";
        }
        else {
            line << "&" << storeValue->getName(trBlock);
        }
        storeValue->hasSetValue = true;
    }
    line << ")";
    trBlock->statements.push_back(TrStatement(CLoc::undefined, line.str()));
}

void CCallbackFunction::dumpBody(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level, CTypeMode returnMode) {

}

CCallback::CCallback(vector<shared_ptr<CType>> argTypes, shared_ptr<CType> stackReturnType, shared_ptr<CType> heapReturnType) : argTypes(argTypes), stackReturnType(stackReturnType), heapReturnType(heapReturnType) {
}

shared_ptr<CCallback> CCallback::getCallback(vector<shared_ptr<CType>> argTypes, shared_ptr<CType> stackReturnType, shared_ptr<CType> heapReturnType) {
    assert(stackReturnType != heapReturnType);
    assert(stackReturnType == nullptr || stackReturnType->typeMode != CTM_Heap);
    assert(heapReturnType == nullptr || heapReturnType->typeMode == CTM_Heap);

    vector<shared_ptr<CType>> allTypes = argTypes;
    if (stackReturnType) {
        allTypes.push_back(stackReturnType);
    }
    if (heapReturnType) {
        allTypes.push_back(heapReturnType);
    }

    if (_callbacks[allTypes] == nullptr) {
        _callbacks[allTypes] = make_shared<CCallback>(argTypes, stackReturnType, heapReturnType);
        _callbacks[allTypes]->types = CType::create(argTypes, stackReturnType, heapReturnType, _callbacks[allTypes]);
    }

    return _callbacks[allTypes];
}

shared_ptr<CType> CCallback::getType(vector<shared_ptr<CType>> argTypes, shared_ptr<CType> stackReturnType, shared_ptr<CType> heapReturnType, CTypeMode returnMode, bool isOption) {
    auto cb = getCallback(argTypes, stackReturnType, heapReturnType);
    switch (returnMode) {
    case CTM_Heap:
        return isOption ? cb->types->heapOptionType : cb->types->heapValueType;
    default:
        return isOption ? cb->types->localOptionType : cb->types->localValueType;
    }
}

shared_ptr<CVar> CCallback::getVar(Compiler* compiler, shared_ptr<CScope> scope, CLoc loc, shared_ptr<CVar> dotVar, shared_ptr<CBaseFunction> function, CTypeMode returnMode) {
    auto stackReturnType = function->getReturnType(compiler, CTM_Stack);
    if (stackReturnType->typeMode == CTM_Heap) {
        stackReturnType = nullptr;
    }

    auto heapReturnType = function->getReturnType(compiler, CTM_Heap);
    if (heapReturnType->typeMode != CTM_Heap) {
        heapReturnType = nullptr;
    }

    vector<shared_ptr<CType>> argTypes;
    for (auto i = 0; i < function->getArgCount(CTM_Stack); i++) {
        auto argVar = function->getArgVar(i, CTM_Stack);
        auto argType = argVar->getType(compiler);
        argTypes.push_back(argType);
    }

    auto cb = getCallback(argTypes, stackReturnType, heapReturnType);
    auto isHeap = false;
    if (dotVar) {
        isHeap = dotVar->getType(compiler)->typeMode == CTM_Heap;

        if (returnMode == CTM_Heap && !isHeap) {
            compiler->addError(loc, CErrorCode::InvalidType, "left value must be heap to create a heap callback");
            return nullptr;
        }
    }

    return make_shared<CCallbackVar>(loc, scope, isHeap ? cb->types->heapValueType : cb->types->localValueType, dotVar, cb, function, returnMode);
}

shared_ptr<CBaseFunction> CCallback::getFunction(Compiler* compiler, shared_ptr<CVar> callbackVar) {
    return make_shared<CCallbackFunction>(shared_from_this(), callbackVar);
}

void CCallback::transpileDefinition(Compiler* compiler, TrOutput* trOutput) {
    string stackStructName = getCName(CTM_Local, false);
    if (trOutput->structs.find(stackStructName) == trOutput->structs.end()) {
        trOutput->structs[stackStructName].push_back("void* _parent");
        if (stackReturnType) {
            trOutput->structs[stackStructName].push_back(getCBName(compiler, true, CTM_Stack));
        }
        if (heapReturnType) {
            trOutput->structs[stackStructName].push_back(getCBName(compiler, true, CTM_Heap));
        }
        trOutput->structOrder.push_back(stackStructName);
    }

    string heapStructName = getCName(CTM_Heap, false);
    if (trOutput->structs.find(heapStructName) == trOutput->structs.end()) {
        trOutput->structs[heapStructName].push_back(stackStructName + " inner");
        trOutput->structs[heapStructName].push_back("void (*_destroy)(void*)");
        trOutput->structOrder.push_back(heapStructName);
    }
}

string CCallback::getCBName(Compiler* compiler, bool includeNames, CTypeMode returnMode) {
    stringstream ss;
    ss << "void";
    if (includeNames) {
        ss << " ";
    }
    ss << "(*";
    if (includeNames) {
        ss << ((returnMode == CTM_Heap) ? "_cb_heap" : "_cb");
    }
    ss << ")(void*";
    if (includeNames) {
        ss << " _parent";
    }
    for (auto argType : argTypes) {
        ss << ",";
        if (includeNames) {
            ss << " ";
        }
        ss << argType->getLocalType()->cname;
    }

    auto returnType = (returnMode == CTM_Heap) ? heapReturnType : stackReturnType;
    if (returnType != nullptr && returnType != compiler->typeVoid) {
        ss << ", ";
        ss << returnType->cname << "*";
        if (includeNames) {
            ss << " _return";
        }
    }
    ss << ")";
    return ss.str();
}

string CCallback::getCName(CTypeMode typeMode, bool isOption) {
    stringstream safeStream;
    safeStream << "cb";
    for (auto argType : argTypes) {
        safeStream << "_";
        safeStream << argType->safeName;
    }
    if (stackReturnType) {
        safeStream << "_";
        safeStream << stackReturnType->safeName;
    }
    if (heapReturnType) {
        safeStream << "_";
        safeStream << heapReturnType->safeName;
    }
    if (typeMode == CTM_Heap) {
        safeStream << "_heap";
    }
    return safeStream.str();
}

void CCallback::writeCopy(TrBlock* trBlock, string from, string to, bool isHeap) {
    if (isHeap) {
        trBlock->statements.push_back(TrStatement(CLoc::undefined, to + ".inner._parent = " + from + ".inner._parent"));
        trBlock->statements.push_back(TrStatement(CLoc::undefined, "((sjs_object*)((char*)" + to + ".inner._parent - sizeof(intptr_t)))->_refCount++"));
        if (stackReturnType) {
            trBlock->statements.push_back(TrStatement(CLoc::undefined, to + ".inner._cb = " + from + ".inner._cb"));
        }
        if (heapReturnType) {
            trBlock->statements.push_back(TrStatement(CLoc::undefined, to + ".inner._cb_heap = " + from + ".inner._cb_heap"));
        }
        trBlock->statements.push_back(TrStatement(CLoc::undefined, to + "._destroy = " + from + "._destroy"));
    }
    else {
        trBlock->statements.push_back(TrStatement(CLoc::undefined, to + "._parent = " + from + "._parent"));
        if (stackReturnType) {
            trBlock->statements.push_back(TrStatement(CLoc::undefined, to + "._cb = " + from + "._cb"));
        }
        if (heapReturnType) {
            trBlock->statements.push_back(TrStatement(CLoc::undefined, to + "._cb_heap = " + from + "._cb_heap"));
        }
    }
}


map<vector<shared_ptr<CType>>, shared_ptr<CCallback>> CCallback::_callbacks;