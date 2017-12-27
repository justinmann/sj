#include <sjc.h>
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
    
    auto destCallback = storeValue->type->callback.lock();
    if (!destCallback) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "right must be a callback");
        return;
    }

    if (destCallback->argTypes.size() != callback->argTypes.size()) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "right arg count %d does not match left arg count %d", destCallback->argTypes.size(), callback->argTypes.size());
        return;
    }

    for (auto i = 0; i < (int)destCallback->argTypes.size(); i++) {
        if (!CType::isSameExceptMode(destCallback->argTypes[i], callback->argTypes[i])) {
            compiler->addError(loc, CErrorCode::TypeMismatch, "right arg %d type '%s' does not match left arg type '%s'", i, destCallback->argTypes[i]->fullName.c_str(), callback->argTypes[i]->fullName.c_str());
            return;
        }
    }

    if (!storeValue->op.isFirstAssignment) {
        assert(storeValue->type->typeMode != CTM_Stack);
        storeValue->getValue()->addReleaseToStatements(compiler, trBlock);
    }

    string name = storeValue->getName(trBlock);
    if (storeValue->type->typeMode == CTM_Heap) {
        name += ".inner";
    }

    auto destStackReturnType = storeValue->type->callback.lock()->stackReturnType;
    auto destHeapReturnType = storeValue->type->callback.lock()->heapReturnType;

    if (function->classType == CFT_InterfaceMethod) {
        if (!dotVar) {
            compiler->addError(loc, CErrorCode::TypeMismatch, "missing dot value");
            return;
        }

        auto dotValue = trBlock->createTempStoreVariable(loc, scope.lock(), dotVar->getType(compiler), "cbdot");
        dotVar->transpile(compiler, trOutput, trBlock, thisValue, dotValue);

        trBlock->statements.push_back(TrStatement(loc, name + "._parent = " + dotValue->getName(trBlock) + "._parent"));
        if (storeValue->type->typeMode == CTM_Heap) {
            stringstream retainStream;
            retainStream << "if (" << name << "._parent != 0) { " << name << "._parent->_refCount++;";
            if (compiler->outputDebugLeaks) {
                retainStream << "_object_retain((sjs_object*)" << name << "._parent" << ", \"" << trBlock->getFunctionName() << "\");";
            }
            retainStream << "}";
            trBlock->statements.push_back(TrStatement(loc, retainStream.str()));
        }
        else if (storeValue->type->typeMode == CTM_Weak) {
            auto cbName = TrBlock::nextVarName("weakptrcb");

            stringstream cbStream;
            cbStream << "delete_cb " << cbName << " = { &" << name << "._parent, weakptr_clear };";
            trBlock->statements.push_back(TrStatement(CLoc::undefined, cbStream.str()));

            stringstream lineStream;
            lineStream << "if (" << name << "._parent != 0) { weakptr_cb_add(" << name << "._parent, " << cbName << "); }";
            trBlock->statements.push_back(TrStatement(CLoc::undefined, lineStream.str()));
        }

        auto interfaceMethodStack = function->parent.lock()->getCFunction(compiler, CLoc::undefined, function->name, nullptr, nullptr, CTM_Stack);
        auto interfaceMethodHeap = function->parent.lock()->getCFunction(compiler, CLoc::undefined, function->name, nullptr, nullptr, CTM_Heap);
        if (destStackReturnType) {
            if (destStackReturnType == interfaceMethodStack->getReturnType(compiler, CTM_Stack)) {
                trBlock->statements.push_back(TrStatement(loc, name + "._cb = " + dotValue->getName(trBlock) + "._vtbl->" + interfaceMethodStack->name));
            }
            else if (destStackReturnType == interfaceMethodHeap->getReturnType(compiler, CTM_Heap)) {
                trBlock->statements.push_back(TrStatement(loc, name + "._cb = " + dotValue->getName(trBlock) + "._vtbl->" + interfaceMethodHeap->name + "_heap"));
            }
            else {
                compiler->addError(loc, CErrorCode::TypeMismatch, "return type '%s' does not match '%s'", destStackReturnType->fullName.c_str(), interfaceMethodStack->getReturnType(compiler, CTM_Stack)->fullName.c_str());
                return;
            }
        }

        if (destHeapReturnType) {
            if (destHeapReturnType == interfaceMethodStack->getReturnType(compiler, CTM_Stack)) {
                trBlock->statements.push_back(TrStatement(loc, name + "._cb_heap = " + dotValue->getName(trBlock) + "._vtbl->" + interfaceMethodStack->name));
            }
            else if (destHeapReturnType == interfaceMethodHeap->getReturnType(compiler, CTM_Heap)) {
                trBlock->statements.push_back(TrStatement(loc, name + "._cb_heap = " + dotValue->getName(trBlock) + "._vtbl->" + interfaceMethodHeap->name + "_heap"));
            }
            else {
                compiler->addError(loc, CErrorCode::TypeMismatch, "return type '%s' does not match '%s'", destHeapReturnType->fullName.c_str(), interfaceMethodStack->getReturnType(compiler, CTM_Stack)->fullName.c_str());
                return;
            }
        }
    }
    else {
        if (dotVar) {
            if (storeValue->type->typeMode == CTM_Heap) {
                auto parentValue = make_shared<TrStoreValue>(loc, scope.lock(), dotVar->getType(compiler)->getHeapType(), name + "._parent", AssignOp::immutableCreate);
                parentValue->isObjectCast = true;
                dotVar->transpile(compiler, trOutput, trBlock, thisValue, parentValue);

                auto dotType = dotVar->getType(compiler);
                trBlock->statements.push_back(TrStatement(loc, storeValue->getName(trBlock) + "._destroy = (void(*)(sjs_object*))" + dotType->parent.lock()->getCDestroyFunctionName()));
            }
            else if (storeValue->type->typeMode == CTM_Weak) {
                auto parentValue = make_shared<TrStoreValue>(loc, scope.lock(), dotVar->getType(compiler)->getWeakType(), name + "._parent", AssignOp::immutableCreate);
                parentValue->isObjectCast = true;
                dotVar->transpile(compiler, trOutput, trBlock, thisValue, parentValue);
            }
            else {
                auto parentValue = make_shared<TrStoreValue>(loc, scope.lock(), dotVar->getType(compiler)->getTempType(), name + "._parent", AssignOp::immutableCreate);
                parentValue->isObjectCast = true;
                dotVar->transpile(compiler, trOutput, trBlock, thisValue, parentValue);
            }
        }
        else {
            trBlock->statements.push_back(TrStatement(loc, name + "._parent = (sjs_object*)1"));
        }

        if (destStackReturnType) {
            if (destStackReturnType == callback->stackReturnType) {
                string functionName = function->getCCallbackFunctionName(compiler, trOutput, CTM_Stack);
                trBlock->statements.push_back(TrStatement(loc, name + "._cb = (" + callback->getCBName(compiler, false, CTM_Stack) + ")" + functionName));
            }
            else if (destStackReturnType == callback->heapReturnType) {
                string functionName = function->getCCallbackFunctionName(compiler, trOutput, CTM_Heap);
                trBlock->statements.push_back(TrStatement(loc, name + "._cb = (" + callback->getCBName(compiler, false, CTM_Heap) + ")" + functionName));
            }
            else {
                compiler->addError(loc, CErrorCode::TypeMismatch, "return type '%s' does not match '%s'", destStackReturnType->fullName.c_str(), callback->stackReturnType->fullName.c_str());
                return;
            }
        }

        if (destHeapReturnType) {
            if (destHeapReturnType == callback->stackReturnType) {
                string functionName = function->getCCallbackFunctionName(compiler, trOutput, CTM_Stack);
                trBlock->statements.push_back(TrStatement(loc, name + "._cb_heap = (" + callback->getCBName(compiler, false, CTM_Stack) + ")" + functionName));
            }
            else if (destHeapReturnType == callback->heapReturnType) {
                string functionName = function->getCCallbackFunctionName(compiler, trOutput, CTM_Heap);
                trBlock->statements.push_back(TrStatement(loc, name + "._cb_heap = (" + callback->getCBName(compiler, false, CTM_Heap) + ")" + functionName));
            }
            else {
                compiler->addError(loc, CErrorCode::TypeMismatch, "return type '%s' does not match '%s'", destHeapReturnType->fullName.c_str(), callback->heapReturnType ? callback->heapReturnType->fullName.c_str() : "UNKNOWN");
                return;
            }
        }
    }

    storeValue->hasSetValue = true;
}

void CCallbackVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {

}

CCallbackFunction::CCallbackFunction(shared_ptr<CCallback> callback, shared_ptr<CVar> callbackVar) : CBaseFunction(CFT_Callback, "INVALID", "INVALID", weak_ptr<CBaseFunction>(), weak_ptr<CBaseFunctionDefinition>(), false), callback(callback), callbackVar(callbackVar) {
    auto argIndex = 0;
    for (auto argType : callback->argTypes) {
        stringstream argName;
        argName << "param" << argIndex;
        auto argVar = make_shared<CNormalVar>(CLoc::undefined, nullptr, argType, argName.str(), false, CVarType::Var_Public);
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

shared_ptr<CVar> CCallbackFunction::getCVar(Compiler* compiler, vector<shared_ptr<LocalVarScope>> localVarScopes, const string& name, VarScanMode scanMode, CTypeMode returnMode) {
    assert(false);
    return nullptr;
}

shared_ptr<CBaseFunction> CCallbackFunction::getCFunction(Compiler* compiler, CLoc locCaller, const string& name, shared_ptr<CScope> callerScope, shared_ptr<CTypeNameList> templateTypeNames, CTypeMode returnMode) {
    assert(false);
    return nullptr;
}

shared_ptr<CType> CCallbackFunction::getVarType(CLoc loc, Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, shared_ptr<CTypeName> typeName, CTypeMode defaultMode) {
    assert(false);
    return nullptr;
}

string CCallbackFunction::getCFunctionName(Compiler* compiler, TrOutput* trOutput, CTypeMode returnMode) {
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

pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>> CCallbackFunction::getFunctionDefinition(vector<string> packageNamespace, string name) {
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
        return callbackVar->getType(compiler)->typeMode == CTM_Weak ? callback->heapReturnType->getOptionType() : callback->heapReturnType;
    }
    else {
        return callbackVar->getType(compiler)->typeMode == CTM_Weak ? callback->stackReturnType->getOptionType() : callback->stackReturnType;
    }
}

void CCallbackFunction::transpileStructDefinition(Compiler* compiler, TrOutput* trOutput) {
    assert(false);
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

    bool isWeak = callbackVar->getType(compiler)->typeMode == CTM_Weak;
    shared_ptr<TrStoreValue> weakReturnValue;
    if (isWeak) {
        trBlock->statements.push_back(TrStatement(CLoc::undefined, "if (" + callbackValue->getName(trBlock) + "._parent != 0) {"));

        auto normalReturnType = returnMode == CTM_Heap ? callback->heapReturnType : callback->stackReturnType;
        if (normalReturnType != getReturnType(compiler, returnMode)) {
            weakReturnValue = storeValue;
            storeValue = trBlock->createTempStoreVariable(storeValue->loc, storeValue->scope, normalReturnType, "callbackreturn");
        }
    }

    stringstream line;
    line << callbackValue->getName(trBlock) << ".";
    if (returnMode == CTM_Heap) {
        line << "_cb_heap";
    }
    else {
        line << "_cb";
    }
    line << "(";

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
        auto argStoreValue = trBlock->createTempStoreVariable(calleeLoc, callerScope, argType->typeMode == CTM_Heap ? argType : argType->getTempType(), "functionParam");
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

    if (isWeak) {
        if (weakReturnValue) {
            weakReturnValue->retainValue(compiler, CLoc::undefined, trBlock, storeValue->getValue());
        }

        trBlock->statements.push_back(TrStatement(CLoc::undefined, "}"));
        if (!storeValue->isVoid) {
            trBlock->statements.push_back(TrStatement(CLoc::undefined, "else {"));
            getReturnType(compiler, returnMode)->transpileDefaultValue(compiler, CLoc::undefined, trBlock, weakReturnValue ? weakReturnValue : storeValue);
            trBlock->statements.push_back(TrStatement(CLoc::undefined, "}"));
        }
    }
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
    shared_ptr<CType> stackReturnType;
    shared_ptr<CType> heapReturnType;

    if (function->classType == CFT_InterfaceMethod) {
        auto interfaceMethodStack = function->parent.lock()->getCFunction(compiler, CLoc::undefined, function->name, nullptr, nullptr, CTM_Stack);
        auto interfaceMethodHeap = function->parent.lock()->getCFunction(compiler, CLoc::undefined, function->name, nullptr, nullptr, CTM_Heap);

        stackReturnType = interfaceMethodStack->getReturnType(compiler, CTM_Stack);
        if (stackReturnType->typeMode == CTM_Heap) {
            stackReturnType = nullptr;
        }

        heapReturnType = interfaceMethodHeap->getReturnType(compiler, CTM_Heap);
        if (heapReturnType->typeMode != CTM_Heap) {
            heapReturnType = nullptr;
        }
    }
    else {
        stackReturnType = function->getReturnType(compiler, CTM_Stack);
        if (stackReturnType->typeMode == CTM_Heap) {
            stackReturnType = nullptr;
        }

        heapReturnType = function->getReturnType(compiler, CTM_Heap);
        if (heapReturnType->typeMode != CTM_Heap) {
            heapReturnType = nullptr;
        }
    }

    auto cfunc = dynamic_pointer_cast<CFunction>(function);
    if (cfunc) {
        cfunc->initArgs(compiler);
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

void CCallback::transpileStructDefinition(Compiler* compiler, TrOutput* trOutput) {
    string stackStructName = getCName(CTM_Local, false);
    if (trOutput->structs.find(stackStructName) == trOutput->structs.end()) {
        trOutput->structs[stackStructName].push_back("sjs_object* _parent");
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
        trOutput->structs[heapStructName].push_back("void (*_destroy)(sjs_object*)");
        trOutput->structOrder.push_back(heapStructName);
    }
}

void CCallback::transpileDefinition(Compiler* compiler, TrOutput* trOutput) {
    transpileStructDefinition(compiler, trOutput);
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
    ss << ")(sjs_object*";
    if (includeNames) {
        ss << " _parent";
    }
    for (auto argType : argTypes) {
        ss << ",";
        if (includeNames) {
            ss << " ";
        }
        ss << argType->getTempType()->cname;
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

void CCallback::writeCopy(Compiler* compiler, TrBlock* trBlock, string from, string to, bool isHeap) {
    if (isHeap) {
        trBlock->statements.push_back(TrStatement(CLoc::undefined, to + ".inner._parent = " + from + ".inner._parent"));

        stringstream retainStream;
        retainStream << to << ".inner._parent->_refCount++";
        if (compiler->outputDebugLeaks) {
            retainStream << "; _object_retain((sjs_object*)" << to << ".inner._parent" << ", \"" << trBlock->getFunctionName() << "\");";
        }

        trBlock->statements.push_back(TrStatement(CLoc::undefined, retainStream.str()));
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
