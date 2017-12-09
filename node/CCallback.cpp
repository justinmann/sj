#include "Node.h"

bool CCallbackVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CCallbackVar::getType(Compiler* compiler) {
    return type;
}

void CCallbackVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    callback->transpileDefinition(compiler, trOutput);
    function->transpileDefinition(compiler, trOutput);

    auto rightValue = trBlock->createTempVariable(scope.lock(), type, "callback");    

    if (dotValue) {
        assert(dotValue->type->typeMode == CTM_Local);
        assert(type->typeMode == CTM_Local);
        trBlock->statements.push_back(TrStatement(loc, rightValue->name + "._parent = (void*)" + dotValue->name));
    }
    else {
        trBlock->statements.push_back(TrStatement(loc, rightValue->name + "._parent = (void*)0"));
    }

    string functionName = function->getCCallbackFunctionName(compiler, trOutput, returnMode);
    trBlock->statements.push_back(TrStatement(loc, rightValue->name + "._cb = " + functionName));

    storeValue->retainValue(compiler, loc, trBlock, rightValue);
}

void CCallbackVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {

}

CCallbackFunction::CCallbackFunction(shared_ptr<CCallback> callback, shared_ptr<CVar> callbackVar) : CBaseFunction(CFT_Callback, string("INVALID"), weak_ptr<CBaseFunction>(), weak_ptr<CBaseFunctionDefinition>(), false), callback(callback), callbackVar(callbackVar) {
}

int CCallbackFunction::getArgIndex(const string& name, CTypeMode returnMode) {
    assert(false);
    return -1;
}

int CCallbackFunction::getArgCount(CTypeMode returnMode) {
    assert(false);
    return 0;
}

shared_ptr<CVar> CCallbackFunction::getArgVar(int index, CTypeMode returnMode) {
    assert(false);
    return nullptr;
}

string CCallbackFunction::fullName(bool includeTemplateTypes) {
    return callbackVar->name;
}

shared_ptr<CTypes> CCallbackFunction::getThisTypes(Compiler* compiler) {
    assert(false);
    return nullptr;
}

shared_ptr<CVar> CCallbackFunction::getCVar(Compiler* compiler, const string& name, VarScanMode scanMode, CTypeMode returnMode) {
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
        return callback->returnType->typeMode == CTM_Heap;
    }
    else {
        return callback->returnType->typeMode != CTM_Heap;
    }
}

shared_ptr<CType> CCallbackFunction::getReturnType(Compiler* compiler, CTypeMode returnMode) {
    return callback->returnType;
}

void CCallbackFunction::transpileDefinition(Compiler* compiler, TrOutput* trOutput) {
    assert(false);
}

void CCallbackFunction::transpile(Compiler* compiler, shared_ptr<CScope> callerScope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> parentValue, CLoc& calleeLoc, shared_ptr<vector<FunctionParameter>> parameters, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue, CTypeMode returnMode) {
    stringstream line;
    line << callbackVar->cname << "._cb(";
    bool isFirstParameter = true;

    // Add "parent" to "this"
    line << callbackVar->cname << "._parent";

    // Fill in "this" with normal arguments
    for (auto parameter : *parameters) {
        auto argType = parameter.var->getType(compiler);

        stringstream argStream;
        auto parameterVar = parameter.var;
        if (!parameterVar) {
            assert(compiler->errors.size() > 0);
            return;
        }
        auto argStoreValue = trBlock->createTempStoreVariable(calleeLoc, callerScope, argType->typeMode == CTM_Heap ? argType : argType->getLocalValueType(), "functionParam");
        parameterVar->transpile(compiler, trOutput, trBlock, nullptr, thisValue, argStoreValue);

        if (!argStoreValue->hasSetValue) {
            compiler->addError(calleeLoc, CErrorCode::TypeMismatch, "parameter '%s' has no value", parameterVar->name.c_str());
            return;
        }

        line << ", ";
        line << argStoreValue->getName(trBlock);
    }

    // Call function
    if (callback->returnType != compiler->typeVoid) {
        if (!isFirstParameter) {
            line << ", ";
        }
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

CCallback::CCallback(vector<shared_ptr<CType>> argTypes, shared_ptr<CType> returnType) : argTypes(argTypes), returnType(returnType) {
}

shared_ptr<CCallback> CCallback::getCallback(vector<shared_ptr<CType>> argTypes, shared_ptr<CType> returnType) {
    assert(returnType->typeMode != CTM_Undefined);
    vector<shared_ptr<CType>> allTypes = argTypes;
    allTypes.push_back(returnType);

    if (_callbacks[allTypes] == nullptr) {
        _callbacks[allTypes] = make_shared<CCallback>(argTypes, returnType);
        _callbacks[allTypes]->types = CType::create(argTypes, returnType, _callbacks[allTypes]);
    }

    return _callbacks[allTypes];
}

shared_ptr<CType> CCallback::getType(vector<shared_ptr<CType>> argTypes, shared_ptr<CType> returnType, CTypeMode defaultMode, bool isOption) {
    auto cb = getCallback(argTypes, returnType);
    switch (defaultMode) {
    case CTM_Heap:
        return isOption ? cb->types->heapOptionType : cb->types->heapValueType;
    default:
        return isOption ? cb->types->localOptionType : cb->types->localValueType;
    }
}

shared_ptr<CVar> CCallback::getVar(Compiler* compiler, shared_ptr<CScope> scope, CLoc loc, shared_ptr<CVar> dotVar, shared_ptr<CBaseFunction> function, CTypeMode returnMode) {
    if (returnMode != CTM_Heap) {
        returnMode = CTM_Stack;
    }

    auto returnType = function->getReturnType(compiler, returnMode);
    vector<shared_ptr<CType>> argTypes;
    for (auto i = 0; i < function->getArgCount(returnMode); i++) {
        auto argVar = function->getArgVar(i, returnMode);
        auto argType = argVar->getType(compiler);
        argTypes.push_back(argType);
    }

    auto cb = getCallback(argTypes, returnType);
    auto isHeap = false;
    if (dotVar) {
        isHeap = dotVar->getType(compiler)->typeMode == CTM_Heap;
    }

    auto functionName = function->getCFunctionName(returnMode);

    return make_shared<CCallbackVar>(loc, scope, isHeap ? cb->types->heapValueType : cb->types->localValueType, dotVar, cb, function, returnMode);
}

shared_ptr<CBaseFunction> CCallback::getFunction(Compiler* compiler, shared_ptr<CVar> callbackVar) {
    return make_shared<CCallbackFunction>(shared_from_this(), callbackVar);
}

void CCallback::transpileDefinition(Compiler* compiler, TrOutput* trOutput) {
    string stackStructName = getCName(CTM_Local, false);
    if (trOutput->structs.find(stackStructName) == trOutput->structs.end()) {
        trOutput->structs[stackStructName].push_back("void* _parent");
        trOutput->structs[stackStructName].push_back(getCBName(compiler, true));
        trOutput->structOrder.push_back(stackStructName);
    }

    string heapStructName = getCName(CTM_Heap, false);
    if (trOutput->structs.find(heapStructName) == trOutput->structs.end()) {
        trOutput->structs[heapStructName].push_back("sjs_object* _parent");
        trOutput->structs[heapStructName].push_back(getCBName(compiler, true));
        trOutput->structOrder.push_back(heapStructName);
    }
}

string CCallback::getCBName(Compiler* compiler, bool includeNames) {
    stringstream ss;
    ss << "void";
    if (includeNames) {
        ss << " ";
    }
    ss << "(*";
    if (includeNames) {
        ss << "_cb";
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
    bool isFirst = true;
    for (auto argType : argTypes) {
        if (isFirst) {
            isFirst = false;
        }
        else {
            safeStream << "_";
        }
        safeStream << argType->safeName;
    }
    safeStream << "_";
    safeStream << returnType->safeName;
    if (typeMode == CTM_Heap) {
        safeStream << "_heap";
    }
    return safeStream.str();
}

map<vector<shared_ptr<CType>>, shared_ptr<CCallback>> CCallback::_callbacks;