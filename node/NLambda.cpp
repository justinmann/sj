#include "Node.h"

NLambdaInvokeFunction::NLambdaInvokeFunction(CLoc loc, shared_ptr<CTypeName> returnTypeName, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<vector<string>> attributes, shared_ptr<CTypeNameList> interfaceTypeNames, shared_ptr<NodeList> arguments, shared_ptr<NBase> block, shared_ptr<NBase> catchBlock, shared_ptr<NBase> copyBlock, shared_ptr<NBase> destroyBlock) :
    NFunction(loc, returnTypeName, name, templateTypeNames, attributes, interfaceTypeNames, arguments, block, catchBlock, copyBlock, destroyBlock) { }

shared_ptr<CFunctionDefinition> NLambdaInvokeFunction::getFunctionDefinition(Compiler *compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string> packageNamespace, shared_ptr<CFunctionDefinition> parentFunction) {
    auto functionDefinition = make_shared<CLambdaInvokeFunctionDefinition>();
    functionDefinition->init(compiler, importNamespaces, parentFunction, packageNamespace, name, nullptr, shared_from_this());
    return functionDefinition;
}

shared_ptr<CFunction> CLambdaInvokeFunctionDefinition::createFunction(vector<pair<string, vector<string>>>& importNamespaces, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, vector<shared_ptr<NCCode>> ccodes, bool hasHeapThis) {
    return make_shared<CLambdaInvokeFunction>(importNamespaces, shared_from_this(), templateTypes, parent, interfaces, ccodes, hasHeapThis);
}

CLambdaInvokeFunction::CLambdaInvokeFunction(vector<pair<string, vector<string>>>& importNamespaces, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, vector<shared_ptr<NCCode>> ccodes, bool hasHeapThis) :
    CFunction(importNamespaces, definition, templateTypes, parent, interfaces, ccodes, hasHeapThis, false) {}

shared_ptr<CVar> CLambdaInvokeFunction::getCVar(Compiler* compiler, shared_ptr<CScope> callerScope, vector<shared_ptr<LocalVarScope>> localVarScopes, vector<string> ns, shared_ptr<CVar> dotVar, const string& name, VarScanMode scanMode, CTypeMode returnMode) {
    return CFunction::getCVar(compiler, callerScope, localVarScopes, ns, dotVar, name, scanMode, returnMode);
}

NLambdaClassFunction::NLambdaClassFunction(CLoc loc, shared_ptr<CTypeName> returnTypeName, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<vector<string>> attributes, shared_ptr<CTypeNameList> interfaceTypeNames, shared_ptr<NodeList> arguments, shared_ptr<NBase> block, shared_ptr<NBase> catchBlock, shared_ptr<NBase> copyBlock, shared_ptr<NBase> destroyBlock) :
    NFunction(loc, returnTypeName, name, templateTypeNames, attributes, interfaceTypeNames, arguments, block, catchBlock, copyBlock, destroyBlock), returnMode(CTM_Undefined) { }

shared_ptr<CFunctionDefinition> NLambdaClassFunction::getFunctionDefinition(Compiler *compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string> packageNamespace, shared_ptr<CFunctionDefinition> parentFunction) {
    auto functionDefinition = make_shared<CLambdaClassFunctionDefinition>();
    functionDefinition->init(compiler, importNamespaces, parentFunction, packageNamespace, name, nullptr, shared_from_this());
    return functionDefinition;
}

shared_ptr<CFunction> CLambdaClassFunctionDefinition::createFunction(vector<pair<string, vector<string>>>& importNamespaces, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, vector<shared_ptr<NCCode>> ccodes, bool hasHeapThis) {
    return make_shared<CLambdaClassFunction>(importNamespaces, shared_from_this(), templateTypes, parent, interfaces, ccodes, hasHeapThis);
}

CLambdaClassFunction::CLambdaClassFunction(vector<pair<string, vector<string>>>& importNamespaces, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, vector<shared_ptr<NCCode>> ccodes, bool hasHeapThis) :
    CFunction(importNamespaces, definition, templateTypes, parent, interfaces, ccodes, hasHeapThis, true) {}

shared_ptr<CVar> CLambdaClassFunction::getCVar(Compiler* compiler, shared_ptr<CScope> callerScope, vector<shared_ptr<LocalVarScope>> localVarScopes, vector<string> ns, shared_ptr<CVar> dotVar, const string& name, VarScanMode scanMode, CTypeMode returnMode) {
    auto r = CFunction::getCVar(compiler, callerScope, localVarScopes, ns, dotVar, name, scanMode, returnMode);
    if (!r) {
        auto lambdaFunction = static_pointer_cast<NLambdaClassFunction>(node);
        assert(lambdaFunction->returnMode != CTM_Undefined);
        auto callerVar = lambdaFunction->callerScope->getCVar(compiler, callerScope, dotVar, name, VSM_LocalThisParent);
        if (callerVar) {
            auto lambdaArgVar = vars[CTM_Stack][callerVar];
            if (!lambdaArgVar) {
                auto paramName = TrBlock::nextVarName("lambdaparam");
                auto calleeScope = getScope(compiler, returnMode);
                auto lambdaArgType = callerVar->getType(compiler);
                if (lambdaFunction->returnMode == CTM_Stack) {
                    lambdaArgType = lambdaArgType->getLocalType();
                }
                else {
                    assert(lambdaArgType->typeMode != CTM_Local);
                }
                lambdaArgVar = make_shared<CNormalVar>(loc, calleeScope, lambdaArgType, paramName, callerVar->isMutable, CVarType::Var_Public);
                vars[CTM_Stack][callerVar] = lambdaArgVar;
                _data[CTM_Stack].thisArgVarsByName[lambdaArgVar->name] = pair<int, shared_ptr<CNormalVar>>(_data[CTM_Stack].thisArgVars.size(), lambdaArgVar);
                _data[CTM_Stack].thisArgVars.push_back(lambdaArgVar);
                vars[CTM_Heap][callerVar] = lambdaArgVar;
                _data[CTM_Heap].thisArgVarsByName[lambdaArgVar->name] = pair<int, shared_ptr<CNormalVar>>(_data[CTM_Heap].thisArgVars.size(), lambdaArgVar);
                _data[CTM_Heap].thisArgVars.push_back(lambdaArgVar);
            }

            auto parentFunction = static_pointer_cast<CFunction>(callerScope->function->parent.lock());
            auto parentVar = make_shared<CParentVar>(loc, callerScope, nullptr, parentFunction);
            return lambdaArgVar->createForDot(parentVar);
        }
    }
    return r;
}

void CLambdaClassFunction::transpileStructDefinition(Compiler* compiler, TrOutput* trOutput) {
    CFunction::transpileStructDefinition(compiler, trOutput);
}

CLambdaCallVar::CLambdaCallVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<vector<FunctionParameter>> parameters, shared_ptr<CBaseFunction> callee, CTypeMode returnMode) :
    CCallVar(loc, scope, dotVar, parameters, callee, returnMode){ }

void CLambdaCallVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto cfunc = dynamic_pointer_cast<CFunction>(callee);
    if (cfunc) {
        cfunc->initArgs(compiler);
    }

    auto lambdaClassFunction = static_pointer_cast<CLambdaClassFunction>(callee);
    parameters = make_shared<vector<FunctionParameter>>(callee->getArgCount(returnMode));
    for (auto it : lambdaClassFunction->vars[returnMode]) {
        auto index = callee->getArgIndex(it.second->name, returnMode);
        if (index < 0) {
            compiler->addError(loc, CErrorCode::ParameterDoesNotExist, "cannot find parameter '%s'", it.second->name.c_str());
            return;
        }

        if ((*parameters)[index].var != nullptr) {
            compiler->addError(loc, CErrorCode::ParameterRedefined, "defined parameter '%s' twice", it.second->name.c_str());
            return;
        }

        bool isCopy = false;
        if (it.second->getType(compiler)->typeMode == CTM_Stack && it.first->getType(compiler)->typeMode == CTM_Stack) {
            // If lambda arg is stack then we need to copy the data
            // the arg will only be stack because the lambda callback is being stored heap
            isCopy = true;
        }

        (*parameters)[index].isDefaultValue = false;
        (*parameters)[index].op = AssignOp::create(true, false, isCopy, CTM_Undefined);
        (*parameters)[index].var = it.first;
    }

    CCallVar::transpile(compiler, trOutput, trBlock, thisValue, storeValue);
}

NLambdaCall::NLambdaCall(CLoc loc, string name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<NodeList> arguments, shared_ptr<NLambdaClassFunction> lambdaClassFunction) :
    NCall(loc, name, templateTypeNames, arguments), lambdaClassFunction(lambdaClassFunction) {}

shared_ptr<CVar> NLambdaCall::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    bool isHelperFunction = false;
    auto callee = getCFunction(compiler, loc, scope, dotVar, name, templateTypeNames, returnMode, &isHelperFunction);
    if (!callee) {
        compiler->addError(loc, CErrorCode::UnknownFunction, "function '%s' does not exist", name.c_str());
        return nullptr;
    }

    auto cfunc = dynamic_pointer_cast<CFunction>(callee);
    if (cfunc) {
        cfunc->initArgs(compiler);
    }

    if (returnMode != CTM_Heap) {
        if (callee->getIsReturnModeValid(compiler, CTM_Stack)) {
            returnMode = CTM_Stack;
        }
        else {
            returnMode = CTM_Heap;
        }
    }

    if ((int)arguments->size() + (isHelperFunction ? 1 : 0) > callee->getArgCount(returnMode)) {
        compiler->addError(loc, CErrorCode::TooManyParameters, "passing %d, but expecting max of %d", arguments->size() + (isHelperFunction ? 1 : 0), callee->getArgCount(returnMode));
        return nullptr;
    }

    assert(lambdaClassFunction->returnMode == CTM_Undefined || lambdaClassFunction->returnMode == returnMode);
    lambdaClassFunction->returnMode = returnMode;

    return createCallVar(loc, scope, isHelperFunction ? nullptr : dotVar, nullptr, callee, returnMode);
}

shared_ptr<CCallVar> NLambdaCall::createCallVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<vector<FunctionParameter>> parameters, shared_ptr<CBaseFunction> callee, CTypeMode returnMode) {
    return make_shared<CLambdaCallVar>(loc, scope, dotVar, parameters, callee, returnMode);
}

bool CTempStoreVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CTempStoreVar::getType(Compiler* compiler) {
    return type;
}

void CTempStoreVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    assert(false);
}

void CTempStoreVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {

}

bool CTempStoreVar::getCanStoreValue() {
    return true;
}

shared_ptr<TrStoreValue> CTempStoreVar::getStoreValue(Compiler* compiler, shared_ptr<CScope> scope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, AssignOp op) {
    trBlock->statements.push_back(TrStatement(loc, type->getTempType()->cname + " " + name));
    return make_shared<TrStoreValue>(loc, scope, type->getTempType(), name, AssignOp::immutableCreate);
}


void NLambda::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    auto lambdaName = TrBlock::nextVarName("lambda");

    // Create invoke
    auto lambdaInvokeFunction = make_shared<NLambdaInvokeFunction>(loc, nullptr, "invoke", nullptr, nullptr, nullptr, arguments, block, nullptr, nullptr, nullptr);

    // Create class
    auto lambdaArguments = make_shared<NodeList>();
    lambdaArguments->push_back(lambdaInvokeFunction);
    lambdaClassFunction = make_shared<NLambdaClassFunction>(loc, nullptr, lambdaName.c_str(), nullptr, nullptr, nullptr, lambdaArguments, make_shared<NThis>(loc), nullptr, nullptr, nullptr);
    lambdaClassFunction->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);

    // Init class
    auto initArguments = make_shared<NodeList>();
    initFunction = make_shared<NLambdaCall>(loc, lambdaName, nullptr, initArguments, lambdaClassFunction);
    initFunction->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
}

void NLambda::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    initFunction->initVars(compiler, scope, returnMode);
}

shared_ptr<CVar> NLambda::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    lambdaClassFunction->callerScope = scope;

    vector<shared_ptr<CVar>> statementVars;
    auto tempName = TrBlock::nextVarName("lambainit");
    auto initVar = initFunction->getVar(compiler, scope, returnMode);
    auto initType = initVar->getType(compiler);
    auto tempStoreVar = make_shared<CTempStoreVar>(loc, scope, initType, tempName);
    auto assignVar = make_shared<CAssignVar>(loc, scope, AssignOp::immutableCreate, tempStoreVar, initVar);
    statementVars.push_back(assignVar);

    auto tempVar = make_shared<CTempVar>(loc, scope, initType->typeMode == CTM_Heap ? initType : initType->getTempType(), tempName);
    auto getInvokeCallback = make_shared<NVariable>(loc, "invoke", nullptr);
    auto rightVar = getInvokeCallback->getVar(compiler, scope, tempVar, returnMode);
    statementVars.push_back(rightVar);

    return  make_shared<CBlockVar>(loc, scope, statementVars);
}
