#include <sjc.h>
#include "Node.h"

class CFunctionParameterVar : public CStoreVar {
public:
    CFunctionParameterVar(CLoc loc, shared_ptr<CScope> scope, bool isMutable, shared_ptr<CVar> argVar) : CStoreVar(loc, scope, argVar->name, argVar->name, isMutable), argVar(argVar) { }

    bool getReturnThis() { 
        return false; 
    }

    shared_ptr<CType> getType(Compiler* compiler) { 
        if (this->scope.lock()->function->hasThis) {
            return argVar->getType(compiler);
        }
        else {
            auto type = argVar->getType(compiler);
            if (type->typeMode != CTM_Heap && type->typeMode != CTM_Weak) {
                type = type->getTempType();
            }
            return type;
        }
    }

    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
        shared_ptr<TrValue> value;
        if (this->scope.lock()->function->hasThis) {
            value = make_shared<TrValue>(scope.lock(), getType(compiler), "_this->" + name, false);
        }
        else {
            value = make_shared<TrValue>(scope.lock(), getType(compiler), name, false);
        }
        storeValue->retainValue(compiler, loc, trBlock, value);
    }

    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
        ss << name;
    }

    bool getCanStoreValue() {
        return isMutable;
    }
    
    shared_ptr<TrStoreValue> getStoreValue(Compiler* compiler, shared_ptr<CScope> scope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, AssignOp op) {
        if (isMutable) {
            if (this->scope.lock()->function->hasThis) {
                return make_shared<TrStoreValue>(loc, scope, getType(compiler), "_this->" + argVar->cname, AssignOp::mutableUpdate);
            }
            else {
                return make_shared<TrStoreValue>(loc, scope, getType(compiler), argVar->cname, AssignOp::mutableUpdate);
            }
        }
        return nullptr;
    }

private:
    shared_ptr<CVar> argVar;
};

NFunction::NFunction(CLoc loc, shared_ptr<CTypeName> returnTypeName, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<vector<string>> attributes, shared_ptr<CTypeNameList> interfaceTypeNames, shared_ptr<NodeList> arguments, shared_ptr<NBase> block, shared_ptr<NBase> catchBlock, shared_ptr<NBase> copyBlock, shared_ptr<NBase> destroyBlock) : 
    NBaseFunction(NodeType_Function, loc), returnTypeName(returnTypeName), name(name), templateTypeNames(templateTypeNames), attributes(attributes), 
    interfaceTypeNames(interfaceTypeNames), block(block), catchBlock(catchBlock), copyBlock(copyBlock), destroyBlock(destroyBlock) {
    boost::algorithm::to_lower(this->name);    
    if (arguments) {
        for (auto it : *arguments) {
            if (it->nodeType == NodeType_Assignment) {
                auto nassignment = static_pointer_cast<NAssignment>(it);
                nassignment->inFunctionDeclaration = true;
                assignments.push_back(nassignment);
                
                if (nassignment->nfunction) {
                    functions.push_back(nassignment->nfunction);
                }
            } else if (it->nodeType == NodeType_Function) {
                functions.push_back(static_pointer_cast<NFunction>(it));
            }
            else if (it->nodeType == NodeType_Interface) {
                interfaces.push_back(static_pointer_cast<NInterface>(it));
            }
            else if (it->nodeType == NodeType_Code) {
                ccodes.push_back(static_pointer_cast<NCCode>(it));
            } else {
                invalid.push_back(it);
            }
        }
    }
}

void NFunction::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> parentFunction) {
    assert(compiler->state == CompilerState::Define);
    if (invalid.size() > 0) {
        compiler->addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments, function definitions, or interface definitions");
        return;
    }
    
    auto thisFunction = getFunctionDefinition(compiler, importNamespaces, packageNamespace, static_pointer_cast<CFunctionDefinition>(parentFunction));
    if (!thisFunction) {
        return;
    }

    parentFunction->addChildFunction(compiler, loc, packageNamespace, name, thisFunction);

    for (auto it : interfaces) {
        it->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    }

    for (auto it : functions) {
        it->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    }
        
    for (auto it : assignments) {
        if (!it->op.isFirstAssignment) {
            compiler->addError(loc, CErrorCode::InvalidFunction, "assignment '%s' must be : or :=", it->name.c_str());
        }
        it->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    }

    if (block) {
        block->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    }

    if (copyBlock) {
        copyBlock->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    }

    if (destroyBlock) {
        destroyBlock->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    }

    if (catchBlock) {
        catchBlock->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    }

    if ((copyBlock == nullptr) != (destroyBlock == nullptr)) {
        compiler->addError(loc, CErrorCode::InvalidType, "function '%s' must define a copy and destroy block or neither", name.c_str());
    }
}

void NFunction::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
}

shared_ptr<CFunctionDefinition> NFunction::getFunctionDefinition(Compiler *compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string> packageNamespace, shared_ptr<CFunctionDefinition> parentFunction) {
    auto functionDefinition = make_shared<CFunctionDefinition>();
    functionDefinition->init(compiler, importNamespaces, parentFunction, packageNamespace, name, interfaceTypeNames, shared_from_this());
    return functionDefinition;
}

shared_ptr<CVar> NFunction::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CType> returnType, CTypeMode returnMode) {
    if (invalid.size() > 0) {
        compiler->addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return nullptr;
    }

    return nullptr;
}

CFunction::CFunction(vector<pair<string, vector<string>>>& importNamespaces, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, vector<shared_ptr<NCCode>> ccodes, bool hasHeapThis, bool localThisVarsOkay) :
CBaseFunction(CFT_Function, definition.lock()->name, definition.lock()->safeName, parent, definition, false),
loc(CLoc::undefined),
templateTypes(templateTypes),
interfaces(interfaces),
ccodes(ccodes),
_isInGetType(false),
_returnTypeName(nullptr),
_interfaceTypeNames(nullptr),
_hasInitializedInterfaces(false),
_hasTranspileDefinitions(NOTSTARTED),
_hasTranspileStructDefinitions(NOTSTARTED),
_hasInitArgs(false),
_isReturnThis(false),
hasHeapThis(hasHeapThis),
importNamespaces(importNamespaces),
localThisVarsOkay(localThisVarsOkay)
 { }

CTypeMode functionReturnModes[] = { CTM_Stack, CTM_Heap };

bool CFunction::init(Compiler* compiler, shared_ptr<NFunction> node, CLoc locCaller) {
    this->node = node;

    if (templateTypes.size() == 0) {

    }
    else if (templateTypes.size() == 1) {
        name = name + "!" + templateTypes[0]->shortName;
    }
    else {
        name = name + "![";
        bool isFirst = true;
        for (auto it : templateTypes) {
            if (isFirst) {
                name = name + it->shortName;
                isFirst = false;
            }
            else {
                name = name + ", " + it->shortName;
            }
        }
        name = name + "]";
    }
    
    for (auto it : templateTypes) {
        safeName = safeName + "_" + it->safeName;
    }

    hasParent = !parent.expired() && name != "global" && parent.lock()->name != "global";
    if (hasParent) {
        parent.lock()->setHasThis();
    }
    
    if (node) {
        loc = node->loc;
        _functions = node->functions;
        _returnTypeName = node->returnTypeName;
        _interfaceTypeNames = node->interfaceTypeNames;

        if (node->templateTypeNames) {
            assert(node->templateTypeNames->size() == templateTypes.size());
            auto index = 0;
            for (auto templateTypeName : *node->templateTypeNames) {
                if (templateTypeName->templateTypeNames != nullptr) {
                    compiler->addError(loc, CErrorCode::InvalidType, "cannot use ! in template type name");
                    return nullptr;
                }

                if (templateTypes[index]->typeMode == CTM_Local) {
                    compiler->addError(locCaller, CErrorCode::InvalidType, "template '%s' with type '%s' cannot be local", templateTypeName->valueName.c_str(), templateTypes[index]->fullName.c_str());
                    return false;
                }

                templateTypesByName[templateTypeName->valueName] = templateTypes[index];
                index++;
            }
        }
    }

    return true;
}

void CFunction::initArgs(Compiler* compiler) {
    if (_hasInitArgs) {
        return;
    }

    _hasInitArgs = true;
    if (node) {
        auto index = 0;
        for (auto it : node->assignments) {
            if (it->var) {
                compiler->addError(it->loc, CErrorCode::InvalidDot, "cannot use '.' in variable declaration for a function: '%s'", it->name.c_str());
                return;
            }

            for (auto returnMode : functionReturnModes) {
                auto cvarType = it->name[0] == '_' ? CVarType::Var_Private : CVarType::Var_Public;

                auto calleeScope = getScope(compiler, returnMode);
                auto argType = it->getType(compiler, calleeScope, cvarType, CTM_Undefined);
                if (!argType) {
                    return;
                }

                auto thisArgVar = make_shared<CNormalVar>(node->loc, calleeScope, argType, it->name, it->op.isMutable, cvarType);
                _data[returnMode].thisArgVarsByName[it->name] = pair<int, shared_ptr<CNormalVar>>(index, thisArgVar);
                _data[returnMode].thisArgVars.push_back(thisArgVar);
            }

            FunctionDefaultValue defaultValue;
            defaultValue.op = it->op;
            defaultValue.value = it->rightSide;
            argDefaultValues.push_back(defaultValue);
            index++;
        }
    }
}

bool CFunction::initBlocks(Compiler* compiler, shared_ptr<NFunction> node) {
    if (node) {
        for (auto returnMode : functionReturnModes) {
            auto calleeScope = getScope(compiler, returnMode);

            for (auto it : node->interfaces) {
                it->initVars(compiler, calleeScope, returnMode);
            }

            for (auto it : node->functions) {
                it->initVars(compiler, calleeScope, returnMode);
            }

            for (auto it : node->assignments) {
                if (!it->op.isFirstAssignment) {
                    compiler->addError(loc, CErrorCode::InvalidFunction, "assignment '%s' must be : or :=", it->name.c_str());
                }
                it->initVars(compiler, calleeScope, returnMode);
            }

            if (node->block) {
                node->block->initVars(compiler, calleeScope, returnMode);
            }

            if (node->copyBlock) {
                node->copyBlock->initVars(compiler, calleeScope, returnMode);
            }

            if (node->destroyBlock) {
                node->destroyBlock->initVars(compiler, calleeScope, returnMode);
            }

            if (node->catchBlock) {
                node->catchBlock->initVars(compiler, calleeScope, returnMode);
            }
        }

        for (auto returnMode : functionReturnModes) {
            auto calleeScope = getScope(compiler, returnMode);

            _data[returnMode].blockVar = node->block->getVar(compiler, calleeScope, nullptr, returnMode);
            if (!_data[returnMode].blockVar) {
                return false;
            }

            if (node->copyBlock) {
                _data[returnMode].copyVar = node->copyBlock->getVar(compiler, calleeScope, nullptr, CTM_Undefined);
                if (!_data[returnMode].copyVar) {
                    return false;
                }
            }

            if (node->catchBlock) {
                _data[returnMode].catchVar = node->catchBlock->getVar(compiler, calleeScope, nullptr, returnMode);
                if (!_data[returnMode].catchVar) {
                    return false;
                }
            }

            if (node->destroyBlock) {
                _data[returnMode].destroyVar = node->destroyBlock->getVar(compiler, calleeScope, nullptr, CTM_Undefined);
                if (!_data[returnMode].destroyVar) {
                    return false;
                }
            }
        }
    }
    
    return true;
}

void CFunction::transpileStructDefinition(Compiler* compiler, TrOutput* trOutput) {
    if (_hasTranspileStructDefinitions == DONE) {
        return;
    }
    else if (_hasTranspileStructDefinitions == STARTED) {
        compiler->addError(loc, CErrorCode::TypeLoop, "an argument in this function depends on this function which creates an impossible loop");
        return;
    }

    _hasTranspileStructDefinitions = STARTED;

    if (hasThis) {
        auto returnMode = hasHeapThis ? CTM_Heap : CTM_Stack;
        auto calleeScope = getScope(compiler, returnMode);

        // Create struct
        string stackStructName = getCStructName(returnMode);
        if (trOutput->structs.find(stackStructName) == trOutput->structs.end()) {
            trOutput->structs[stackStructName].push_back("int _refCount");

            bool hasValues = false;
            auto argTypes = getCTypeList(compiler, returnMode);
            if (!argTypes) {
                compiler->addError(loc, CErrorCode::InvalidType, "something bad");
                return;
            }

            for (auto argType : *argTypes) {
                hasValues = true;
                stringstream ss;
                ss << argType.second->cname;

                // C requires that inline structs be defined before use
                if (!argType.second->parent.expired()) {
                    argType.second->parent.lock()->transpileStructDefinition(compiler, trOutput);
                }
                else if (!argType.second->callback.expired()) {
                    argType.second->callback.lock()->transpileStructDefinition(compiler, trOutput);
                }

                if (argType.second->typeMode == CTM_Stack) {
                }
                else if (!localThisVarsOkay && argType.second->typeMode != CTM_Heap && argType.second->typeMode != CTM_Weak && argType.second->typeMode != CTM_Value && argType.first.compare("_parent") != 0) {
                    compiler->addError(loc, CErrorCode::InvalidType, "var '%s' is local which is not allowed", argType.first.c_str());
                }
                ss << " " << argType.first;
                trOutput->structs[stackStructName].push_back(ss.str());
            }

            for (auto ccode : ccodes) {
                ccode->addToStruct(compiler, calleeScope, trOutput->structs[stackStructName]);
            }

            trOutput->structOrder.push_back(make_pair(stackStructName, _thisTypes->localValueType->typeId));
        }
    }

    _hasTranspileStructDefinitions = DONE;
}

void CFunction::transpileDefinition(Compiler* compiler, TrOutput* trOutput) {
    if (_hasTranspileDefinitions != NOTSTARTED) {
        return;
    }
    
    _hasTranspileDefinitions = STARTED;

    for (auto t : templateTypes) {
        if (!t->parent.expired()) {
            t->parent.lock()->transpileDefinition(compiler, trOutput);
        }
        else if (!t->callback.expired()) {
            t->callback.lock()->transpileDefinition(compiler, trOutput);
        }
    }

    initArgs(compiler);
    transpileStructDefinition(compiler, trOutput);
    
    for (auto returnMode : functionReturnModes) {
        auto returnType = getReturnType(compiler, returnMode);        
        if (_data[returnMode].isInvalid) {
            continue;
        }

        auto calleeVar = getThisVar(compiler, returnMode);
        auto calleeScope = getScope(compiler, returnMode);

        if (!hasThis) {
            // Create function body
            auto functionName = getCFunctionName(compiler, trOutput, returnMode);
            auto functionBody = trOutput->functions.find(functionName);
            if (functionBody == trOutput->functions.end()) {
                auto trFunctionBlock = make_shared<TrBlock>(functionName);
                trFunctionBlock->hasThis = false;
                trOutput->functions[functionName] = trFunctionBlock;

                auto bodyReturnValue = (returnType == compiler->typeVoid) ? trFunctionBlock->createVoidStoreVariable(loc, returnType) : trFunctionBlock->createReturnStoreVariable(loc, nullptr, returnType);
                _data[returnMode].blockVar->transpile(compiler, trOutput, trFunctionBlock.get(), nullptr, bodyReturnValue);

                stringstream functionDefinition;
                functionDefinition << "void " << functionName << "(";
                auto isFirstArg = true;
                auto argTypes = getCTypeList(compiler, returnMode);

                if (hasParent) {
                    isFirstArg = false;
                    functionDefinition << parent.lock()->getThisTypes(compiler)->localValueType->cname << " _parent";
                }

                for (auto argType : *argTypes) {
                    if (isFirstArg) {
                        isFirstArg = false;
                    }
                    else {
                        functionDefinition << ", ";
                    }
                    
                    if (!argType.second->parent.expired()) {
                        argType.second->parent.lock()->transpileDefinition(compiler, trOutput);
                    }
                    else if (!argType.second->callback.expired()) {
                        argType.second->callback.lock()->transpileDefinition(compiler, trOutput);
                    }

                    functionDefinition << argType.second->cname << " " << argType.first;
                }

                if (returnType != compiler->typeVoid) {
                    if (isFirstArg) {
                        isFirstArg = false;
                    }
                    else {
                        functionDefinition << ", ";
                    }
                    functionDefinition << returnType->cname << "* _return";
                }

                if (isFirstArg) {
                    functionDefinition << "void";
                }
                functionDefinition << ")";
                trFunctionBlock->definition = functionDefinition.str();
            }
        }
        else {
            // Create init function body
            auto functionName = getCFunctionName(compiler, trOutput, returnMode);
            auto functionBody = trOutput->functions.find(functionName);
            if (functionBody == trOutput->functions.end()) {
                auto returnType = getReturnType(compiler, returnMode);
                auto trFunctionBlock = make_shared<TrBlock>(functionName);
                trFunctionBlock->hasThis = true;
                trOutput->functions[functionName] = trFunctionBlock;

                _isReturnThis = _data[returnMode].blockVar->getReturnThis();
                auto bodyReturnValue = (returnType != compiler->typeVoid && !_isReturnThis) ? trFunctionBlock->createReturnStoreVariable(loc, nullptr, returnType) : trFunctionBlock->createVoidStoreVariable(loc, returnType);
                _data[returnMode].blockVar->transpile(compiler, trOutput, trFunctionBlock.get(), make_shared<TrValue>(nullptr, calleeVar->getType(compiler)->getTempType(), "_this", false), bodyReturnValue);

                string structName = getCStructName(calleeVar->getTypeMode());
                stringstream functionDefinition;
                functionDefinition << "void " << functionName << "(" << structName << "* _this";
                if (hasParent) {
                    functionDefinition << ", " << parent.lock()->getThisTypes(compiler)->localValueType->cname << " _parent";
                }
                if (returnType != compiler->typeVoid && !_isReturnThis) {
                    functionDefinition << ", " << returnType->cname << "* _return";
                }
                functionDefinition << ")";
                trFunctionBlock->definition = functionDefinition.str();
            }

            // Create copy function body
            string stackStructName = getCStructName(CTM_Stack);
            string functionCopyName = getCCopyFunctionName();
            if (trOutput->functions.find(functionCopyName) == trOutput->functions.end()) {
                auto trCopyBlock = make_shared<TrBlock>(functionCopyName);
                trCopyBlock->hasThis = true;
                trOutput->functions[functionCopyName] = trCopyBlock;

                stringstream functionDefinition;
                functionDefinition << "void " << functionCopyName << "(" << stackStructName << "* _this, " << stackStructName << "* _from)";
                trCopyBlock->definition = functionDefinition.str();

                for (auto argVar : _data[returnMode].thisArgVars) {
                    auto argType = argVar->getType(compiler);

                    if (!argType->parent.expired()) {
                        argType->parent.lock()->transpileDefinition(compiler, trOutput);
                    }
                    else if (!argType->callback.expired()) {
                        argType->callback.lock()->transpileDefinition(compiler, trOutput);
                    }

                    auto isCopy = (argType->typeMode == CTM_Stack);
                    if (argType->typeMode == CTM_Local && !localThisVarsOkay) {
                        compiler->addError(argVar->loc, CErrorCode::InvalidType, "function argument '%s' cannot be local type", argVar->name.c_str());
                    }
                    assert(argType->typeMode != CTM_Undefined);
                    TrStoreValue(argVar->loc, calleeScope, argType, "_this->" + argVar->name, AssignOp::create(true, true, isCopy, CTM_Undefined)).retainValue(compiler, argVar->loc, trCopyBlock.get(), make_shared<TrValue>(calleeScope, argType, "_from->" + argVar->name, false));
                }

                if (_data[returnMode].copyVar) {
                    auto copyType = _data[returnMode].copyVar->getType(compiler);
                    _data[returnMode].copyVar->transpile(compiler, trOutput, trCopyBlock.get(), make_shared<TrValue>(nullptr, calleeVar->getType(compiler), "_this", false), trCopyBlock->createVoidStoreVariable(loc, copyType));
                }
            }

            // Create destroy function body
            string functionDestroyName = getCDestroyFunctionName();
            if (trOutput->functions.find(functionDestroyName) == trOutput->functions.end()) {
                auto trDestroyBlock = make_shared<TrBlock>(functionDestroyName);
                trDestroyBlock->hasThis = true;
                trOutput->functions[functionDestroyName] = trDestroyBlock;

                stringstream functionDefinition;
                functionDefinition << "void " << functionDestroyName << "(" << stackStructName << "* _this)";
                trDestroyBlock->definition = functionDefinition.str();

                if (_data[returnMode].destroyVar) {
                    auto destroyType = _data[returnMode].destroyVar->getType(compiler);
                    _data[returnMode].destroyVar->transpile(compiler, trOutput, trDestroyBlock.get(), make_shared<TrValue>(nullptr, calleeVar->getType(compiler), "_this", false), trDestroyBlock->createVoidStoreVariable(loc, destroyType));
                }

                for (auto argVar : _data[returnMode].thisArgVars) {
                    TrValue(calleeScope, argVar->getType(compiler), "_this->" + argVar->name, false).addReleaseToStatements(compiler, trDestroyBlock.get());
                }

                for (auto argVar : _data[returnMode].thisArgVars) {
                    TrValue(calleeScope, argVar->getType(compiler), "_this->" + argVar->name, false).addDestroyToStatements(compiler, trDestroyBlock.get());
                }
            }

            // Create interfaces
            if (interfaces != nullptr) {
                for (auto interfaceVal : *interfaces) {
                    interfaceVal->transpileDefinition(compiler, trOutput);

                    // Create explict cast
                    auto vtblName = getCStructName(CTM_Stack) + "_" + interfaceVal->name + "_vtbl";
                    auto vtblBody = trOutput->vtbls.find(vtblName);
                    if (vtblBody == trOutput->vtbls.end()) {
                        auto vtbl = make_shared<TrVtbl>();
                        vtbl->ctype = interfaceVal->getCVtblName();
                        trOutput->vtbls[vtblName] = vtbl;

                        vtbl->functions.push_back(make_pair("destroy", "(void(*)(void*))" + getCDestroyFunctionName()));
                        vtbl->functions.push_back(make_pair("asinterface", "(void(*)(sjs_object*,int,sjs_interface*))" + getCAsInterfaceFunctionName(compiler, trOutput, CTM_Stack)));
                        vtbl->functions.push_back(make_pair("getclasstype", "(void(*)(sjs_object*,int*))" + getCGetClassTypeFunctionName(compiler, trOutput, CTM_Stack)));

                        for (auto interfaceMethod : interfaceVal->methods) {
                            if (interfaceMethod->isSpecial) {
                                continue;
                            }

                            auto implementation = static_pointer_cast<CFunction>(getCFunction(compiler, loc, interfaceMethod->name, nullptr, nullptr, CTM_Undefined));
                            if (!implementation) {
                                compiler->addError(loc, CErrorCode::InterfaceMethodDoesNotExist, "cannot find interface method '%s'", interfaceMethod->name.c_str());
                            }
                            else {
                                auto interfaceReturnType = interfaceMethod->getReturnType(compiler, interfaceMethod->returnMode);
                                auto implementationReturnType = implementation->getReturnType(compiler, interfaceMethod->returnMode);
                                if (interfaceReturnType != implementationReturnType) {
                                    compiler->addError(implementation->loc, CErrorCode::InterfaceMethodTypeMismatch, "return type '%s' does not match '%s'", implementationReturnType->fullName.c_str(), interfaceReturnType->fullName.c_str());
                                }

                                implementation->transpileDefinition(compiler, trOutput);

                                if (implementation->_data[interfaceMethod->returnMode].isInvalid) {
                                    compiler->addError(implementation->loc, CErrorCode::InterfaceMethodDoesNotExist, "method '%s' does not support %s return mode", implementation->name.c_str(), interfaceMethod->returnMode == CTM_Heap ? "heap" : "stack");
                                    continue;
                                }

                                if (interfaceMethod->getArgCount(interfaceMethod->returnMode) != implementation->getArgCount(interfaceMethod->returnMode)) {
                                    compiler->addError(implementation->loc, CErrorCode::InterfaceMethodTypeMismatch, "method '%s' has wrong argument count", implementation->name.c_str());
                                    continue;
                                }

                                for (auto argIndex = 0; argIndex < interfaceMethod->getArgCount(interfaceMethod->returnMode); argIndex++) {
                                    auto leftArg = interfaceMethod->getArgVar(argIndex, interfaceMethod->returnMode);
                                    auto leftType = leftArg->getType(compiler);

                                    auto rightArg = implementation->getArgVar(argIndex, interfaceMethod->returnMode);
                                    auto rightType = rightArg->getType(compiler);

                                    if (leftType != rightType) {
                                        compiler->addError(implementation->loc, CErrorCode::InterfaceMethodTypeMismatch, "method '%s' arg %d type '%s' does not match '%s'", implementation->name.c_str(), argIndex, rightType->fullName.c_str(), leftType->fullName.c_str());
                                        continue;
                                    }
                                }

                                stringstream initStream;
                                initStream << "(" << interfaceMethod->getCTypeName(compiler, false) << ")" << implementation->getCFunctionName(compiler, trOutput, interfaceMethod->returnMode);
                                vtbl->functions.push_back(make_pair(interfaceMethod->name + (interfaceMethod->returnMode == CTM_Heap ? "_heap" : ""), initStream.str()));
                            }
                        }
                    }

                    auto castFunctionName = interfaceVal->getCCastFunctionName(compiler, trOutput, shared_from_this(), CTM_Stack);
                    auto functionBody = trOutput->functions.find(castFunctionName);
                    if (functionBody == trOutput->functions.end()) {
                        auto trFunctionBlock = make_shared<TrBlock>(castFunctionName);
                        trFunctionBlock->hasThis = true;
                        trOutput->functions[castFunctionName] = trFunctionBlock;

                        string structName = getCStructName(calleeVar->getTypeMode());
                        auto interfaceType = interfaceVal->getThisTypes(compiler)->localValueType;
                        stringstream functionDefinition;
                        functionDefinition << "void " << castFunctionName << "(" << structName << "* _this, " + interfaceType->cname + "* _return)";
                        trFunctionBlock->definition = functionDefinition.str();
                        trFunctionBlock->statements.push_back(TrStatement(CLoc::undefined, string("_return->_parent = (sjs_object*)_this")));
                        trFunctionBlock->statements.push_back(TrStatement(CLoc::undefined, string("_return->_vtbl = &" + vtblName)));
                    }
                }

                string asInterfaceFunctionName = getCAsInterfaceFunctionName(compiler, trOutput, CTM_Stack);
                auto asInterfaceFunctionBody = trOutput->functions.find(asInterfaceFunctionName);
                if (asInterfaceFunctionBody == trOutput->functions.end()) {
                    auto trFunctionBlock = make_shared<TrBlock>(asInterfaceFunctionName);
                    trFunctionBlock->hasThis = true;
                    trOutput->functions[asInterfaceFunctionName] = trFunctionBlock;

                    string structName = getCStructName(calleeVar->getTypeMode());
                    stringstream functionDefinition;
                    functionDefinition << "void " << asInterfaceFunctionName << "(" << structName << "* _this, int typeId, sjs_interface* _return)";
                    trFunctionBlock->definition = functionDefinition.str();

                    auto switchBlock = make_shared<TrBlock>(trFunctionBlock.get());
                    trFunctionBlock->statements.push_back(TrStatement(CLoc::undefined, "switch (typeId)", switchBlock));
                    for (auto interfaceVal : *interfaces) {
                        auto caseBlock = make_shared<TrBlock>(switchBlock.get());
                        caseBlock->statements.push_back(TrStatement(CLoc::undefined, interfaceVal->getCCastFunctionName(compiler, trOutput, shared_from_this(), CTM_Stack) + "(_this, (" + interfaceVal->getCStructName(CTM_Undefined) + "*)_return)"));
                        caseBlock->statements.push_back(TrStatement(CLoc::undefined, "break"));
                        switchBlock->statements.push_back(TrStatement(CLoc::undefined, string("case ") + interfaceVal->getCTypeIdName() + ": ", caseBlock));
                    }

                    auto caseBlock = make_shared<TrBlock>(switchBlock.get());
                    caseBlock->statements.push_back(TrStatement(CLoc::undefined, "_return->_parent = 0"));
                    caseBlock->statements.push_back(TrStatement(CLoc::undefined, "break"));
                    switchBlock->statements.push_back(TrStatement(CLoc::undefined, string("default:"), caseBlock));
                }

                auto getClassTypeFunctionName = getCGetClassTypeFunctionName(compiler, trOutput, CTM_Stack);
                functionBody = trOutput->functions.find(getClassTypeFunctionName);
                if (functionBody == trOutput->functions.end()) {
                    auto trFunctionBlock = make_shared<TrBlock>(getClassTypeFunctionName);
                    trFunctionBlock->hasThis = true;
                    trOutput->functions[getClassTypeFunctionName] = trFunctionBlock;

                    string structName = getCStructName(calleeVar->getTypeMode());
                    stringstream functionDefinition;
                    functionDefinition << "void " << getClassTypeFunctionName << "(sjs_object* _this, int* _return)";
                    trFunctionBlock->definition = functionDefinition.str();
                    trFunctionBlock->statements.push_back(TrStatement(CLoc::undefined, "*_return = " + to_string(_thisTypes->localValueType->typeId)));
                }
            }
        }
    }

    _hasTranspileDefinitions = DONE;
}

void CFunction::transpile(Compiler* compiler, shared_ptr<CScope> callerScope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<CVar> parentVar, CLoc& calleeLoc, shared_ptr<vector<FunctionParameter>> parameters, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue, CTypeMode returnMode) {
    transpileDefinition(compiler, trOutput);
    initArgs(compiler);

    assert(compiler->state == CompilerState::Compile);
    assert(returnMode == CTM_Stack || returnMode == CTM_Heap);

    if (_data[returnMode].isInvalid) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "function '%s' cannot return '%s'", name.c_str(), returnMode == CTM_Heap ? "heap" : "stack");
        return;
    }
    
    auto returnType = getReturnType(compiler, returnMode);
    if (!returnType) {
        return;
    }
    
    if (storeValue->type != returnType) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "function '%s' cannot store return type '%s' in type '%s'", name.c_str(),  returnType->valueName.c_str(), storeValue->type->valueName.c_str());
        return;
    }
    
    shared_ptr<TrStoreValue> previousReturnValue;
    if (!storeValue->op.isFirstAssignment) {
        previousReturnValue = storeValue;
        storeValue = trBlock->createTempStoreVariable(loc, callerScope, storeValue->type, "funcold");
        storeValue->retainValue(compiler, loc, trBlock, previousReturnValue->getValue());
    }

    assert(returnType == storeValue->type);
    auto calleeVar = getThisVar(compiler, returnMode);
    auto calleeScope = getScope(compiler, returnMode);

    string parentName;
    if (hasParent) {
        stringstream parentLine;
        if (!parentVar) {
            if (parent.lock() == callerScope->function) {
                if (thisValue != nullptr) {
                    parentName = TrValue::convertToLocalName(thisValue->type, thisValue->name, false);
                }
                else {
                    assert(false);
                }
            }
            else if (parent.lock() == callerScope->function->parent.lock()) {
                parentName = "_parent";
            }
            else {
                assert(false);
            }
        }
        else {
            auto parentStoreValue = trBlock->createTempStoreVariable(loc, nullptr, static_pointer_cast<CFunction>(parent.lock())->hasHeapThis ? parentVar->getType(compiler)->getHeapType() : parentVar->getType(compiler)->getTempType(), "parent");
            parentVar->transpile(compiler, trOutput, trBlock, thisValue, parentStoreValue);
            auto parentValue = parentStoreValue->getValue();
            parentName = TrValue::convertToLocalName(parentValue->type, parentValue->name, false);
        }
    }
    
    if (!hasThis) {
        auto functionName = getCFunctionName(compiler, trOutput, returnMode);
        stringstream line;
        line << functionName << "(";
        bool isFirstParameter = true;

        // Add "parent" to "this"
        shared_ptr<TrValue> dotTrValue;
        if (hasParent) {
            if (isFirstParameter) {
                isFirstParameter = false;
            }
            else {
                line << ", ";
            }
            line << parentName;
        }

        auto argTypes = getCTypeList(compiler, returnMode);
        auto argIndex = 0;
        // Fill in "this" with normal arguments
        for (auto defaultAssignment : argDefaultValues) {
            auto argVar = _data[returnMode].thisArgVars[argIndex];
            auto argType = argVar->getType(compiler);
            auto isDefaultAssignment = (*parameters)[argIndex].isDefaultValue;

            stringstream argStream;
            auto parameterVar = (*parameters)[argIndex].var;
            if (!parameterVar) {
                assert(compiler->errors.size() > 0);
                return;
            }
            auto argStoreValue = trBlock->createTempStoreVariable(calleeLoc, callerScope, (argType->typeMode == CTM_Heap || argType->typeMode == CTM_Weak) ? argType : argType->getTempType(), "functionParam");
            parameterVar->transpile(compiler, trOutput, trBlock, isDefaultAssignment ? nullptr : thisValue, argStoreValue);

            if (!argStoreValue->hasSetValue) {
                compiler->addError(calleeLoc, CErrorCode::TypeMismatch, "parameter '%s' has no value", argVar->name.c_str());
                return;
            }

            if (isFirstParameter) {
                isFirstParameter = false;
            }
            else {
                line << ", ";
            }
            line << argStoreValue->getName(trBlock);
            argIndex++;
        }

        // Call function
        if (returnType != compiler->typeVoid) {
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
    } else {
        auto functionName = getCFunctionName(compiler, trOutput, returnMode);

        // Initialize "this"
        shared_ptr<TrValue> calleeThisValue;
        if (_isReturnThis && storeValue->type != nullptr) {
            calleeThisValue = make_shared<TrValue>(storeValue->scope, storeValue->type, storeValue->getName(trBlock), storeValue->isReturnValue);
            calleeThisValue->addInitToStatements(compiler, trBlock);
        }
        else {
            calleeThisValue = trBlock->createTempVariable(callerScope, calleeVar->getType(compiler), "object");
            calleeThisValue->addInitToStatements(compiler, trBlock);
        }

        if (hasHeapThis && calleeThisValue->type->typeMode != CTM_Heap) {
            compiler->addError(loc, CErrorCode::TypeMismatch, "function requires a heap this");
            return;
        }

        auto argTypes = getCTypeList(compiler, returnMode);
        auto argIndex = 0;
        // Fill in "this" with normal arguments
        for (auto parameter : *parameters) {
            auto argVar = _data[returnMode].thisArgVars[argIndex];
            auto argType = argVar->getType(compiler);
            auto isDefaultAssignment = parameter.isDefaultValue;

            stringstream argStream;
            auto parameterVar = parameter.var;
            if (!parameterVar) {
                assert(compiler->errors.size() > 0);
                return;
            }

            auto parameterOp = parameter.op;
            auto argStoreValue = make_shared<TrStoreValue>(isDefaultAssignment ? loc : calleeLoc, calleeScope, argType, calleeThisValue->getDotName(argVar->name), parameterOp);
            parameterVar->transpile(compiler, trOutput, trBlock, isDefaultAssignment ? nullptr : thisValue, argStoreValue);

            if (!argStoreValue->hasSetValue) {
                compiler->addError(calleeLoc, CErrorCode::TypeMismatch, "parameter '%s' has no value", argVar->name.c_str());
                return;
            }
            argIndex++;
        }

        // Call function
        stringstream line;
        line << functionName << "(" << calleeThisValue->getPointerName();
        if (hasParent) {
            line << ", " << parentName;
        }
        if (returnType != compiler->typeVoid && !_isReturnThis) {
            line << ", ";
            if (storeValue->isReturnValue) {
                line << "_return";
            }
            else {
                line << "&" << storeValue->getName(trBlock);
            }
        }
        line << ")";
        trBlock->statements.push_back(TrStatement(CLoc::undefined, line.str()));
        storeValue->hasSetValue = true;
    }

    if (previousReturnValue) {
        previousReturnValue->retainValue(compiler, loc, trBlock, storeValue->getValue());
    }
}

string CFunction::getCBaseName(CTypeMode returnMode) {
    assert(returnMode == CTM_Stack || returnMode == CTM_Heap);
    
    string functionName = getCFullName(true);
    if (!parent.expired()) {
        auto tempType = parent.lock();
        while (tempType != nullptr && tempType->name.compare("global") != 0 && tempType->name.size() > 0) {
            functionName.insert(0, "_");
            assert(tempType->classType == CFT_Function);
            functionName.insert(0, static_pointer_cast<CFunction>(tempType)->getCFullName(true));
            tempType = tempType->parent.lock();
        }
    }
    
    switch (returnMode) {
    case CTM_Stack:
        break;
    case CTM_Heap:
        functionName += "_heap";
        break;
    default:
        assert(false);
        break;
    }
    
    return functionName;
}

string CFunction::getCStructName(CTypeMode returnMode) {
    return string("sjs_") + getCBaseName(CTM_Stack);
}

string CFunction::getCFunctionName(Compiler* compiler, TrOutput* trOutput, CTypeMode returnMode) {
    return string("sjf_") + getCBaseName(returnMode);
}

string CFunction::getCCallbackFunctionName(Compiler* compiler, TrOutput* trOutput, CTypeMode returnMode) {
    if (hasParent && !hasThis) {
        return getCFunctionName(compiler, trOutput, returnMode);
    }
    else {
        string functionName = getCFunctionName(compiler, trOutput, returnMode) + "_callback";

        auto functionBody = trOutput->functions.find(functionName);
        if (functionBody == trOutput->functions.end()) {
            auto trFunctionBlock = make_shared<TrBlock>(functionName);
            trFunctionBlock->hasThis = false;
            trOutput->functions[functionName] = trFunctionBlock;

            auto returnType = getReturnType(compiler, returnMode);
            auto argTypes = getCTypeList(compiler, returnMode);

            stringstream callStream;
            callStream << getCFunctionName(compiler, trOutput, returnMode) << "(";
            bool isFirstArg = true;
            if (hasParent) {
                callStream << "_parent";
                isFirstArg = false;
            }

            for (auto argType : *argTypes) {
                if (isFirstArg) {
                    isFirstArg = false;
                }
                else {
                    callStream << ", ";
                }

                callStream << argType.first;
            }

            if (returnType != compiler->typeVoid) {
                if (isFirstArg) {
                    isFirstArg = false;
                }
                else {
                    callStream << ", ";
                }
                callStream << "_return";
            }
            callStream << ")";
            trFunctionBlock->statements.push_back(TrStatement(CLoc::undefined, callStream.str()));

            stringstream functionDefinition;
            functionDefinition << "void " << functionName << "(";

            if (hasParent) {
                functionDefinition << parent.lock()->getThisTypes(compiler)->localValueType->cname << " _parent";
            }
            else {
                functionDefinition << "void * _parent";
            }

            for (auto argType : *argTypes) {
                functionDefinition << ", ";

                if (!argType.second->parent.expired()) {
                    argType.second->parent.lock()->transpileDefinition(compiler, trOutput);
                }

                functionDefinition << argType.second->cname << " " << argType.first;
            }

            if (returnType != compiler->typeVoid) {
                functionDefinition << ", ";
                functionDefinition << returnType->cname << "* _return";
            }

            functionDefinition << ")";
            trFunctionBlock->definition = functionDefinition.str();
        }

        return functionName;
    }
}

string CFunction::getCCopyFunctionName() {
    return string("sjf_") + getCBaseName(CTM_Stack) + "_copy";
}

string CFunction::getCDestroyFunctionName() {
    return string("sjf_") + getCBaseName(CTM_Stack) + "_destroy";
}

string CFunction::getCAsInterfaceFunctionName(Compiler* compiler, TrOutput* trOutput, CTypeMode returnMode) {
    return getCFunctionName(compiler, trOutput, returnMode) + "_asinterface";
}

string CFunction::getCGetClassTypeFunctionName(Compiler* compiler, TrOutput* trOutput, CTypeMode returnMode) {
    return getCFunctionName(compiler, trOutput, returnMode) + "_getclasstype";
}

void CFunction::dumpBody(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level, CTypeMode returnMode) {
    assert(returnMode == CTM_Stack || returnMode == CTM_Heap);
    assert(!_data[returnMode].isInvalid);
    initArgs(compiler);

    ss << fullName(true);
    if (_interfaceTypeNames) {
        ss << " ";
        for (auto it : *_interfaceTypeNames) {
            if (it != _interfaceTypeNames->front()) {
                ss << ", ";
            }
            ss << it->getFullName();
        }
        ss << " ";
    }
    ss << "(";
    
    if (argDefaultValues.size() > 0) {
        for (auto it : _data[returnMode].thisArgVars) {
            if (it != _data[returnMode].thisArgVars.front()) {
                ss << ", ";
            }
            ss << it->name;
            auto ctype = it->getType(compiler);
            ss << "'" << (ctype != nullptr ? ctype->fullName : "ERROR");
            ss << (it->isMutable ? "=" : ":");
        }
    }
    
    ss << ")";
    auto returnType = getReturnType(compiler, returnMode);
    ss << "'" << (returnType ? returnType->fullName : "void");

    if (_data[returnMode].blockVar) {
        ss << " ";        
        auto calleeVar = getThisVar(compiler, returnMode);
        auto calleeScope = getScope(compiler, returnMode);
        _data[returnMode].blockVar->dump(compiler, functions, ss, level);
    }
}

shared_ptr<CThisVar> CFunction::getThisVar(Compiler* compiler, CTypeMode returnMode) {
    assert(returnMode == CTM_Stack || returnMode == CTM_Heap);

    if (_data[returnMode].isInvalid) {
        return nullptr;
    }

    if (!_hasInitializedInterfaces) {
        _hasInitializedInterfaces = true;
        if (interfaces) {
            // Make all functions used by an interface are defined
            for (auto interface : *interfaces) {
                for (auto interfaceMethod : interface->methods) {
                    if (interfaceMethod->isSpecial) {
                        continue;
                    }

                    auto cfunc = static_pointer_cast<CFunction>(getCFunction(compiler, loc, interfaceMethod->name, nullptr, nullptr, CTM_Undefined));
                    if (!cfunc) {
                        compiler->addError(loc, CErrorCode::InterfaceMethodDoesNotExist, "cannot find interface method: '%s'", interfaceMethod->name.c_str());
                        return nullptr;
                    }

                    auto functionReturnType = cfunc->getReturnType(compiler, interfaceMethod->returnMode);
                    auto interfaceMethodReturnType = interfaceMethod->getReturnType(compiler, CTM_Undefined);
                    if (functionReturnType != interfaceMethodReturnType) {
                        compiler->addError(cfunc->loc, CErrorCode::TypeMismatch, "function '%s' return type '%s' does not match interface method return type '%s'", cfunc->name.c_str(), functionReturnType->fullName.c_str(), interfaceMethodReturnType->fullName.c_str());
                    }

                    auto interfaceMethodArgVars = interfaceMethod->argVars;
                    cfunc->initArgs(compiler);
                    if (cfunc->getArgCount(interfaceMethod->returnMode) != interfaceMethodArgVars.size()) {
                        compiler->addError(cfunc->loc, CErrorCode::InterfaceMethodTypeMismatch, "function '%s' has %d arguments does not match interface method arguments %d", cfunc->name.c_str(), cfunc->getArgCount(interfaceMethod->returnMode), interfaceMethodArgVars.size());
                    }
                    else {
                        for (auto i = (size_t)0; i < interfaceMethodArgVars.size(); i++) {
                            auto aType = cfunc->getArgVar((int)i, interfaceMethod->returnMode)->getType(compiler);
                            auto bType = interfaceMethodArgVars[i]->getType(compiler);
                            if (aType != bType) {
                                compiler->addError(cfunc->loc, CErrorCode::TypeMismatch, "function '%s' parameter %d type '%s' does not match interface method parameter type '%s'", cfunc->name.c_str(), i + 1, aType ? aType->fullName.c_str() : "Unknown", bType ? bType->fullName.c_str() : "Unknown");
                            }
                        }
                    }

                    assert(!cfunc->hasThis);
                    assert(cfunc->hasParent);
                }
            }
        }
    }

    if (!_data[returnMode].thisVar) {
        auto defaultTypeMode = CTM_Undefined;
        if (_returnTypeName) {
            shared_ptr<CType> valueType = getVarType(loc, compiler, importNamespaces, _returnTypeName, CTM_Undefined);
            if (!valueType) {
                compiler->addError(loc, CErrorCode::InvalidType, "explicit type '%s' does not exist", _returnTypeName->getFullName().c_str());
                return nullptr;
            }
            defaultTypeMode = valueType->typeMode;
        }

        if (hasHeapThis) {
            defaultTypeMode = CTM_Heap;
        }

        auto thisTypes = getThisTypes(compiler);
        _data[returnMode].thisVar = make_shared<CThisVar>(loc, nullptr, thisTypes, defaultTypeMode);
    }
    return _data[returnMode].thisVar;
}

bool CFunction::getIsReturnModeValid(Compiler* compiler, CTypeMode returnMode) {
    assert(returnMode == CTM_Stack || returnMode == CTM_Heap);
    getReturnType(compiler, returnMode);
    return !_data[returnMode].isInvalid;
}

shared_ptr<CType> CFunction::getReturnType(Compiler* compiler, CTypeMode returnMode) {
    assert(returnMode == CTM_Stack || returnMode == CTM_Heap);

    if (_isInGetType) {
        compiler->addError(loc, CErrorCode::TypeLoop, "while trying to determine type a cycle was detected");
        return nullptr;
    }
    
    _isInGetType = true;    
    if (!_data[returnMode].returnType) {
        auto getReturnTypeFromBlock = true;
        if (_returnTypeName) {
            shared_ptr<CType> valueType = getVarType(loc, compiler, importNamespaces, _returnTypeName, CTM_Undefined);
            if (!valueType) {
                compiler->addError(loc, CErrorCode::InvalidType, "explicit type '%s' does not exist", _returnTypeName->getFullName().c_str());
                _data[returnMode].returnType = nullptr;
            }
            _data[returnMode].returnType = valueType;
            
            getReturnTypeFromBlock = _returnTypeName->typeMode == CTM_Undefined;
        }
        
        if (_data[returnMode].blockVar && getReturnTypeFromBlock) {
            auto calleeVar = getThisVar(compiler, returnMode);
            auto calleeScope = getScope(compiler, returnMode);
            auto type = _data[returnMode].blockVar->getType(compiler);

            if (type) {
                if (type->typeMode == CTM_ValuePtr) {
                    type = type->getStackType();
                }

                if (!type->parent.expired() && type->typeMode != CTM_Weak) {
                    if (returnMode == CTM_Heap || type->category != CTC_Value || hasHeapThis) {
                        type = type->getHeapType();
                    }
                    else {
                        type = type->getStackType();
                        assert(type != nullptr);
                    }
                }
            }

            _data[returnMode].returnType = type;
        }
        
        if (_data[returnMode].returnType == nullptr) {
            _data[returnMode].returnType = compiler->typeVoid;
        }
        
        if (_data[returnMode].returnType->typeMode == CTM_Local) {
            compiler->addError(loc, CErrorCode::InvalidType, "cannot return local mode");
            _data[returnMode].isInvalid = true;
        }
        
        // If we attempt to return stack and can only generate a heap return then the stack return mode is invalid
        if (returnMode == CTM_Stack && _data[returnMode].returnType->typeMode == CTM_Heap) {
            _data[returnMode].isInvalid = true;
        }
        
        // If we attempt to return heap and cannot generate a heap return then the heap return mode is invalid, value types are handled by the stack return mode
        if (returnMode == CTM_Heap && _data[returnMode].returnType->typeMode != CTM_Heap) {
            _data[returnMode].isInvalid = true;
        }
    }
    
    _isInGetType = false;
    return _data[returnMode].returnType;
}

shared_ptr<CTypes> CFunction::getThisTypes(Compiler* compiler) {
    if (!_thisTypes) {
        _thisTypes = CType::create(compiler, static_pointer_cast<CFunctionDefinition>(definition.lock())->packageNamespace, name, safeName, shared_from_this());
    }
    return _thisTypes;
}

shared_ptr<CScope> CFunction::getScope(Compiler* compiler, CTypeMode returnMode) {
    assert(returnMode == CTM_Stack || returnMode == CTM_Heap);
    if (_data[returnMode].scope == nullptr) {
        auto calleeVar = getThisVar(compiler, returnMode);
        _data[returnMode].scope = make_shared<CScope>(shared_from_this(), calleeVar, returnMode);
    }
    return _data[returnMode].scope;
}

int CFunction::getArgIndex(const string& name, CTypeMode returnMode) {
    assert(returnMode == CTM_Stack || returnMode == CTM_Heap);
    assert(_hasInitArgs);
    if (_data[returnMode].thisArgVarsByName.find(name) != _data[returnMode].thisArgVarsByName.end()) {
        return _data[returnMode].thisArgVarsByName[name].first;
    }
    return -1;
}

shared_ptr<CVar> CFunction::getArgVar(int index, CTypeMode returnMode) {
    assert(returnMode == CTM_Stack || returnMode == CTM_Heap);
    assert(_hasInitArgs);
    return _data[returnMode].thisArgVars[index];
}

int CFunction::getArgCount(CTypeMode returnMode) {
    assert(returnMode == CTM_Stack || returnMode == CTM_Heap);
    assert(_hasInitArgs);
    return (int)_data[returnMode].thisArgVars.size();
}

shared_ptr<vector<pair<string, shared_ptr<CType>>>> CFunction::getCTypeList(Compiler* compiler, CTypeMode returnMode) {
    assert(returnMode == CTM_Stack || returnMode == CTM_Heap);
    assert(_hasTranspileStructDefinitions != NOTSTARTED);
    assert(_hasInitArgs);

    if (_data[returnMode].isInvalid) {
        return nullptr;
    }

    if (!_data[returnMode].ctypeList) {
        _data[returnMode].ctypeList = make_shared<vector<pair<string, shared_ptr<CType>>>>();

        for (auto it : _data[returnMode].thisArgVars) {
            auto ctype = it->getType(compiler);
            if (!ctype) {
                compiler->addError(it->loc, CErrorCode::InvalidType, "cannot determine type for '%s'", it->name.c_str());
                return nullptr;
            }

            if (!hasThis) {
                if (ctype->typeMode == CTM_Stack) {
                    ctype = ctype->getTempType();
                }
            }

            _data[returnMode].ctypeList->push_back(make_pair(it->name, ctype));
        }
    }
    return _data[returnMode].ctypeList;
}

bool getTemplateTypes(Compiler* compiler, CLoc loc, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CScope> callerScope, shared_ptr<CTypeNameList> calleeTemplateTypeNames, shared_ptr<CTypeNameList> funcTemplateTypeNames, vector<shared_ptr<CType>>& templateTypes) {
    if (calleeTemplateTypeNames) {
        if (calleeTemplateTypeNames->size() != funcTemplateTypeNames->size()) {
            compiler->addError(loc, CErrorCode::InvalidTemplateArg, "size does not match");
            return false;
        }
        
        // Map template type string list to type list
        for (auto templateTypeName : *calleeTemplateTypeNames) {
            shared_ptr<CType> ctype = nullptr;
            if (callerScope) {
                ctype = callerScope->getVarType(loc, compiler, templateTypeName, CTM_Undefined);
            }
            
            if (!ctype) {
                vector<pair<string, vector<string>>> allNamespaces;
                if (callerScope) {
                    allNamespaces = callerScope->getImportNamespacesWithRenames();
                }
                else {
                    allNamespaces.push_back(make_pair(string(""), vector<string>()));
                }

                ctype = thisFunction->getVarType(loc, compiler, allNamespaces, templateTypeName, CTM_Undefined);
                if (!ctype) {
                    compiler->addError(loc, CErrorCode::TemplateUnspecified, "cannot find template type: '%s'", templateTypeName->getFullName().c_str());
                    return false;
                }
            }
            
            templateTypes.push_back(ctype);
        }
    } else {
        if (funcTemplateTypeNames != nullptr) {
            compiler->addError(loc, CErrorCode::InvalidTemplateArg, "size does not match");
            return false;
        }
    }
    return true;
}


shared_ptr<CBaseFunction> CFunction::getCFunction(Compiler* compiler, CLoc locCaller, const string& name, shared_ptr<CScope> callerScope, shared_ptr<CTypeNameList> templateTypeNames, CTypeMode returnMode) {
    auto def = static_pointer_cast<CFunctionDefinition>(definition.lock());

    vector<vector<string>> allNamespaces;
    if (callerScope) {
        allNamespaces = callerScope->getImportNamespaces();
    }
    else {
        allNamespaces.push_back(vector<string>());
        if (def->packageNamespace.size() > 0) {
            allNamespaces.push_back(def->packageNamespace);
        }
    }

    for (auto ns : allNamespaces) {
        auto t = def->funcsByName[ns].find(name);
        if (t != def->funcsByName[ns].end()) {
            auto funcDef = t->second;

            vector<shared_ptr<CType>> templateTypes;
            if (!getTemplateTypes(compiler, locCaller, shared_from_this(), callerScope, templateTypeNames, funcDef->node->templateTypeNames, templateTypes)) {
                return nullptr;
            }

            if (funcDef->isPrivate) {
                auto fun = callerScope->function;
                if (fun.get() != this && (fun->parent.expired() || fun->parent.lock().get() != this)) {
                    // private functions are accessible from "this" or "parent" scope
                    return nullptr;
                }
            }

            return funcDef->getFunction(compiler, locCaller, templateTypes, shared_from_this());
        }
    }

    auto tt = templateTypesByName.find(name);
    if (tt != templateTypesByName.end()) {
        if (!tt->second->parent.expired()) {
            return tt->second->parent.lock();
        }
    }
    
    if (!parent.expired()) {
        return parent.lock()->getCFunction(compiler, locCaller, name, callerScope, templateTypeNames, returnMode);
    }
    return nullptr;
}

shared_ptr<CInterface> CFunction::getCInterface(Compiler* compiler, vector<string>& packageNamespace, const string& name, shared_ptr<CScope> callerScope, shared_ptr<CTypeNameList> templateTypeNames) {
    if (name.find('.') != string::npos) {
        vector<string> names;
        istringstream f(name);
        string s;
        while (getline(f, s, '.')) {
            names.push_back(s);
        }

        auto cfunc = shared_from_this();
        for (auto name : names) {
            if (name == names.back()) {
                return cfunc->getCInterface(compiler, packageNamespace, name, callerScope, templateTypeNames);
            }
            else {
                auto var = cfunc->getCVar(compiler, callerScope, vector<shared_ptr<LocalVarScope>>(), vector<string>(), nullptr, name, VSM_LocalOnly, CTM_Stack);
                if (!var) {
                    return nullptr;
                }
                auto ctype = var->getType(compiler);
                if (!ctype || ctype->parent.expired()) {
                    return nullptr;
                }
                assert(ctype->parent.expired() || ctype->parent.lock()->classType == CFT_Function);
                cfunc = static_pointer_cast<CFunction>(ctype->parent.lock());
            }
        }
        return nullptr;
    }
    else {
        auto def = static_pointer_cast<CFunctionDefinition>(definition.lock());
        auto interfaceDef = def->getDefinedInterfaceDefinition(packageNamespace, name);
        if (!interfaceDef) {
            return nullptr;
        }
        
        vector<shared_ptr<CType>> templateTypes;
        if (!getTemplateTypes(compiler, loc, shared_from_this(), callerScope, templateTypeNames, interfaceDef->ninterface->templateTypeNames, templateTypes)) {
            return nullptr;
        }
        
        return interfaceDef->getInterface(compiler, templateTypes, shared_from_this());

        return nullptr;
    }
}

shared_ptr<CVar> CFunction::getCVar(Compiler* compiler, shared_ptr<CScope> callerScope, vector<shared_ptr<LocalVarScope>> localVarScopes, vector<string> ns, shared_ptr<CVar> dotVar, const string& name, VarScanMode scanMode, CTypeMode returnMode) {
    if (returnMode == CTM_Undefined) {
        if (!_data[CTM_Stack].isInvalid) {
            auto result = getCVar(compiler, callerScope, localVarScopes, ns, dotVar, name, scanMode, CTM_Stack);
            if (result) {
                return result;
            }
        }

        if (!_data[CTM_Heap].isInvalid) {
            auto result = getCVar(compiler, callerScope, localVarScopes, ns, dotVar, name, scanMode, CTM_Heap);
            if (result) {
                return result;
            }
        }
    }
    else {       
        assert(returnMode == CTM_Stack || returnMode == CTM_Heap);
        assert(!_data[returnMode].isInvalid);

        if (scanMode == VSM_LocalOnly || scanMode == VSM_LocalThisParent) {
            for (auto fb = localVarScopes.rbegin(); fb != localVarScopes.rend(); ++fb) {
                auto t1 = _data[returnMode].localVarsByName[*fb][ns].find(name);
                if (t1 != _data[returnMode].localVarsByName[*fb][ns].end()) {
                    return t1->second;
                }
            }

            auto t1 = _data[returnMode].localVarsByName[nullptr][ns].find(name);
            if (t1 != _data[returnMode].localVarsByName[nullptr][ns].end()) {
                return t1->second;
            }
        }
        
        if (scanMode == VSM_ThisOnly || scanMode == VSM_LocalThisParent || scanMode == VSM_FromChild) {
            auto isPrivateOkay = false;
            if (scanMode == VSM_FromChild) {
                isPrivateOkay = true;
            }
            else {
                if (callerScope->function.get() == this) {
                    isPrivateOkay = true;
                }
            }

            initArgs(compiler);
            auto t2 = _data[returnMode].thisArgVarsByName.find(name);
            if (t2 != _data[returnMode].thisArgVarsByName.end()) {
                auto thisArgVar = t2->second.second;

                if (thisArgVar->mode == Var_Private && !isPrivateOkay) {
                    return nullptr;
                }

                if (!hasThis && scanMode != VSM_FromChild) {
                    auto argVarType = thisArgVar->getType(compiler);
                    if (!argVarType->parent.expired()) {
                        if (argVarType->typeMode == CTM_Stack) {
                            argVarType = argVarType->getTempType();
                        }
                    }
                    return make_shared<CFunctionParameterVar>(loc, thisArgVar->scope.lock(), thisArgVar->isMutable, thisArgVar);
                }
                else {
                    if (dotVar) {
                        return thisArgVar->createForDot(dotVar);
                    }
                    else {
                        return thisArgVar;
                    }
                }
            }
        }

        if (scanMode == VSM_LocalThisParent && !parent.expired()) {
            shared_ptr<CFunction> parentCheck = dynamic_pointer_cast<CFunction>(parent.lock());
            auto cvar = parentCheck->getCVar(compiler, callerScope, vector<shared_ptr<LocalVarScope>>(), ns, make_shared<CParentVar>(loc, callerScope, dotVar, parentCheck), name, VSM_FromChild, CTM_Undefined);
            if (cvar) {
                return cvar;
            }

            shared_ptr<CFunction> globalFunction = dynamic_pointer_cast<CFunction>(parent.lock());
            while (globalFunction != nullptr && globalFunction->name != "global") {
                globalFunction = dynamic_pointer_cast<CFunction>(globalFunction->parent.lock());
            }

            if (globalFunction) {
                cvar = globalFunction->getCVar(compiler, callerScope, vector<shared_ptr<LocalVarScope>>(), ns, nullptr, name, VSM_LocalOnly, CTM_Undefined);
                return cvar;
            }
        }
    }
    return nullptr;
}

string CFunction::fullName(bool includeTemplateTypes) {
    stringstream ss;
    ss << definition.lock()->fullName();
    if (includeTemplateTypes) {
        if (templateTypes.size() > 0) {
            ss << "!";
        }
        
        if (templateTypes.size() > 1) {
            ss << "[";
        }
        
        for (auto it : templateTypes) {
            if (it != templateTypes.front()) {
                ss << ", ";
            }
            
            ss << it->fullName;
        }
        
        if (templateTypes.size() > 1) {
            ss << "]";
        }
    }
    return ss.str();
}

string CFunction::getCFullName(bool includeTemplateTypes) {
    stringstream ss;
    for (auto ns : static_pointer_cast<CFunctionDefinition>(definition.lock())->packageNamespace) {
        ss << ns << "_";
    }
    
    ss << definition.lock()->safeName;
    if (includeTemplateTypes) {
        if (templateTypes.size() > 0) {
            ss << "_";
        }

        for (auto it : templateTypes) {
            if (it != templateTypes.front()) {
                ss << "_";
            }

            ss << it->safeName;
        }
    }
    return ss.str();
}

pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>> CFunction::getFunctionDefinition(vector<string> packageNamespace, string name) {
    auto functionDefinition = static_pointer_cast<CFunctionDefinition>(definition.lock());
    auto t2 = functionDefinition->funcsByName[packageNamespace].find(name);
    if (t2 != functionDefinition->funcsByName[packageNamespace].end()) {
        return make_pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>>(shared_from_this(), t2->second);
    }

    if (!parent.expired()) {
        return parent.lock()->getFunctionDefinition(packageNamespace, name);
    }

    return make_pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>>(nullptr, nullptr);
}

shared_ptr<CType> CFunction::getVarType(Compiler* compiler, string name, bool isOption) {
    auto t = templateTypesByName.find(name);
    if (t != templateTypesByName.end()) {
        return isOption ? t->second->getOptionType() : t->second;
    }

    if (!parent.expired()) {
        return static_pointer_cast<CFunction>(parent.lock())->getVarType(compiler, name, isOption);
    }
    
    return compiler->getType(name, isOption);
}

shared_ptr<CType> CFunction::getVarType(CLoc loc, Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, shared_ptr<CTypeName> typeName, CTypeMode defaultMode) {
    if (typeName->ctype) {
        return typeName->ctype;
    }
    
    auto typeMode = defaultMode;
    if (typeName->typeMode != CTM_Undefined) {
        typeMode = typeName->typeMode;
    }

    if (typeName->category == CTC_Interface) {
        auto interface = getCInterface(compiler, typeName->packageNamespace, typeName->valueName, nullptr, typeName->templateTypeNames);
        if (interface) {
            auto thisTypes = interface->getThisTypes(compiler);
            switch (typeMode) {
            case CTM_Heap:
                return typeName->isOption ? thisTypes->heapOptionType : thisTypes->heapValueType;
            case CTM_Undefined:
            case CTM_Stack:
            case CTM_Local:
                return typeName->isOption ? thisTypes->localOptionType : thisTypes->localValueType;
            case CTM_Weak:
                return thisTypes->weakType;
            default:
                return nullptr;
            }
        }
    }
    else if (typeName->category == CTC_Function) {
        auto stackReturnType = getVarType(loc, compiler, importNamespaces, typeName->returnTypeName, CTM_Undefined);
        if (stackReturnType == nullptr) {
            compiler->addError(loc, CErrorCode::InvalidType, "cannot find type '%s'", typeName->returnTypeName->valueName.c_str());
        }
        if (stackReturnType->typeMode == CTM_Heap) {
            stackReturnType = nullptr;
        }

        auto heapReturnType = getVarType(loc, compiler, importNamespaces, typeName->returnTypeName, CTM_Heap);
        if (heapReturnType->typeMode != CTM_Heap) {
            heapReturnType = nullptr;
        }

        vector<shared_ptr<CType>> argTypes;
        if (typeName->argTypeNames) {
            for (auto argTypeName : *typeName->argTypeNames) {
                auto argType = getVarType(loc, compiler, importNamespaces, argTypeName, CTM_Undefined);
                if (argType == nullptr) {
                    compiler->addError(loc, CErrorCode::InvalidType, "cannot find type '%s'", argTypeName->valueName.c_str());
                }
                argTypes.push_back(argType);
            }
        }
        return CCallback::getType(compiler, argTypes, stackReturnType, heapReturnType, typeMode, typeName->isOption);
    } else {
        assert(typeName->category == CTC_Value);
        if (typeName->templateTypeNames == nullptr) {
            auto ctype = getVarType(compiler, typeName->valueName, typeName->isOption);
            if (ctype) {
                return ctype;
            }
        }
        
        auto baseFunctionDefinition = getFunctionDefinition(typeName->packageNamespace, typeName->valueName);
        if (baseFunctionDefinition.second != nullptr) {
            auto templateTypes = vector<shared_ptr<CType>>();
            if (typeName->templateTypeNames) {
                for (auto it : *typeName->templateTypeNames) {
                    auto t = getVarType(loc, compiler, importNamespaces, it, CTM_Undefined);
                    if (!t) {
                        return nullptr;
                    }
                    templateTypes.push_back(t);
                }
            }
            
            auto functionDefinition = static_pointer_cast<CFunctionDefinition>(baseFunctionDefinition.second);
            auto cfunc = functionDefinition->getFunction(compiler, loc, templateTypes, baseFunctionDefinition.first);
            if (!cfunc) {
                return nullptr;
            }
            auto thisTypes = cfunc->getThisTypes(compiler);
            switch (typeMode) {
                case CTM_Heap:
                    return typeName->isOption ? thisTypes->heapOptionType : thisTypes->heapValueType;
                case CTM_Undefined:
                case CTM_Stack:
                    return typeName->isOption ? thisTypes->stackOptionType : thisTypes->stackValueType;
                case CTM_Local:
                    return typeName->isOption ? thisTypes->localOptionType : thisTypes->localValueType;
                case CTM_Weak:
                    return thisTypes->weakType;
                default:
                    assert(false);
                    return nullptr;
            }
        }
    }
    return nullptr;
}

void CFunctionDefinition::init(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, shared_ptr<CFunctionDefinition> parent, vector<string> packageNamespace, const string& name, shared_ptr<CTypeNameList> implementedInterfaceTypeNames, shared_ptr<NFunction> node) {
    this->parent = parent;
    this->name = name;
    this->safeName = name;
    this->implementedInterfaceTypeNames = implementedInterfaceTypeNames;
    this->node = node;
    this->importNamespaces = importNamespaces;
    this->packageNamespace = packageNamespace;
    this->isPrivate = name[0] == '_';

    boost::replace_all(this->safeName, "#", "_hash_");
    boost::replace_all(this->safeName, "!", "_bang_");
    boost::replace_all(this->safeName, ",", "_");
    boost::replace_all(this->safeName, " ", "");
    boost::replace_all(this->safeName, "[", "");
    boost::replace_all(this->safeName, "]", "");

    if (this->implementedInterfaceTypeNames) {
        for (auto it : *this->implementedInterfaceTypeNames) {
            if (it->packageNamespace.size() == 0) {
                it->packageNamespace = packageNamespace;
            }
        }
    }
    
    if (node) {
        this->ccodes = node->ccodes;

        for (auto it : node->interfaces) {
            it->initFunctions(compiler, importNamespaces, packageNamespace, shared_from_this());
        }

        for (auto it : node->assignments) {
            if (it->var) {
                compiler->addError(it->loc, CErrorCode::InvalidDot, "cannot use '.' in variable declaration for a function: '%s'", it->name.c_str());
            }
        }
    }
}

string CFunctionDefinition::fullName() {
    string n = name;
    auto p = parent;
    while (!p.expired() && !p.lock()->parent.expired() && p.lock()->name != "global") {
        n.insert(0, "_");
        n.insert(0, p.lock()->name);
        p = p.lock()->parent;
    }
    return n;
}

void CFunctionDefinition::addChildFunction(Compiler* compiler, CLoc loc, vector<string> packageNamespace, string& name, shared_ptr<CBaseFunctionDefinition> childFunction) {
    if (funcsByName[packageNamespace][name] != nullptr) {
        compiler->addError(loc, CErrorCode::InvalidFunction, "function '%s' is already defined", name.c_str());
        return;
    }
    funcsByName[packageNamespace][name] = static_pointer_cast<CFunctionDefinition>(childFunction);
}

shared_ptr<CFunction> CFunctionDefinition::createFunction(vector<pair<string, vector<string>>>& importNamespaces, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, vector<shared_ptr<NCCode>> ccodes, bool hasHeapThis) {
    return make_shared<CFunction>(importNamespaces, shared_from_this(), templateTypes, parent, interfaces, ccodes, hasHeapThis, false);
}

shared_ptr<CFunction> CFunctionDefinition::getFunction(Compiler* compiler, CLoc loc, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CFunction> funcParent) {
    if (!funcParent.expired() && funcParent.lock()->definition.lock() != parent.lock()) {
        if (parent.lock()->name == "global") {
            // This function has been forced into the global section
            auto t = funcParent.lock();
            while (t->definition.lock() != parent.lock()) {
                t = static_pointer_cast<CFunction>(t->parent.lock());
            }
            funcParent = t;
        }
    }

    shared_ptr<CFunction> func;
    auto funcParentPtr = funcParent.lock().get();
    auto it = _cfunctions[funcParentPtr].find(templateTypes);
    if (it != _cfunctions[funcParentPtr].end()) {
        func = it->second;
        if (func) {
            assert(func && func->parent.lock() == funcParent.lock());
        }
    } else {
        assert(funcParent.expired() || funcParent.lock()->definition.lock() == parent.lock());
        
        auto implementedInterfaceDefintions = getImplementedInterfaceDefintions(compiler);

        shared_ptr<vector<shared_ptr<CInterface>>> interfaces;
        if (implementedInterfaceDefintions) {
            interfaces = make_shared<vector<shared_ptr<CInterface>>>();
        }

        int targetTemplateTypeCount = node->templateTypeNames ? (int)node->templateTypeNames->size() : 0;
        if (templateTypes.size() != targetTemplateTypeCount) {
            compiler->addError(loc, CErrorCode::InvalidType, "template type count does not match");
            return nullptr;
        }

        bool isHeapThis = false;
        if (node->attributes) {
            if (std::find(node->attributes->begin(), node->attributes->end(), "heap") != node->attributes->end()) {
                isHeapThis = true;
            }
        }
        
        func = createFunction(importNamespaces, shared_from_this(), templateTypes, funcParent, interfaces, ccodes, isHeapThis);
        if (func == nullptr) {
            return nullptr;
        }

        if (!func->init(compiler, node, loc)) {
            return nullptr;
        }

        if (implementedInterfaceDefintions) {
            for (auto it : *implementedInterfaceDefintions) {
                vector<shared_ptr<CType>> interfaceTemplateTypes;
                if (!it.first->ninterface) {
                    compiler->addError(loc, CErrorCode::InterfaceDoesNotExist, "cannot find interface '%s'", it.first->name.c_str());
                    return nullptr;
                }
                
                if (it.first->ninterface->templateTypeNames) {
                    if (!getTemplateTypes(compiler, loc, func, nullptr, it.second, it.first->ninterface->templateTypeNames, interfaceTemplateTypes)) {
                        compiler->addError(loc, CErrorCode::InterfaceDoesNotExist, "cannot find interface '%s'", it.first->name.c_str());
                        return nullptr;
                    }
                }
                
                auto interface = it.first->getInterface(compiler, interfaceTemplateTypes, funcParent);
                if (!interface) {
                    compiler->addError(loc, CErrorCode::InterfaceDoesNotExist, "cannot find interface '%s'", it.first->name.c_str());
                    return nullptr;
                }
                interfaces->push_back(interface);
            }
        }
        
        _cfunctions[funcParentPtr][templateTypes] = func;

        if (!func->initBlocks(compiler, node)) {
            _cfunctions[funcParentPtr][templateTypes] = nullptr;
            return nullptr;
        }
    }
    return func;
}

shared_ptr<CInterfaceDefinition> CFunctionDefinition::getDefinedInterfaceDefinition(vector<string>& packageNamespace, const string& name) {
    auto it = _definedInterfaceDefinitions[packageNamespace].find(name);
    if (it == _definedInterfaceDefinitions[packageNamespace].end()) {
        if (!parent.expired()) {
            auto t = static_pointer_cast<CFunctionDefinition>(parent.lock());
            return t->getDefinedInterfaceDefinition(packageNamespace, name);
        }
        else {
            return nullptr;
        }
    }
    else {
        return it->second;
    }
}

shared_ptr<CInterfaceDefinition> CFunctionDefinition::createDefinedInterfaceDefinition(Compiler* compiler, CLoc loc, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, string& name) {
    if (_definedInterfaceDefinitions[packageNamespace][name] != nullptr) {
        compiler->addError(loc, CErrorCode::InvalidFunction, "interface '%s' is already defined", name.c_str());
        return nullptr;
    }

    auto result = make_shared<CInterfaceDefinition>(loc, importNamespaces, packageNamespace, name);
    _definedInterfaceDefinitions[packageNamespace][name] = result;
    return result;
}

shared_ptr<vector<pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>>> CFunctionDefinition::getImplementedInterfaceDefintions(Compiler* compiler) {
    if (!_implementedInterfaceDefinitions) {
        if (implementedInterfaceTypeNames) {
            _implementedInterfaceDefinitions = make_shared<vector<pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>>>();
            for (auto it : *implementedInterfaceTypeNames) {
                auto interface = getDefinedInterfaceDefinition(it->packageNamespace, it->valueName);
                if (interface == nullptr) {
                    compiler->addError(loc, CErrorCode::InterfaceDoesNotExist, "cannot find interface '%s'", it->valueName.c_str());
                    _implementedInterfaceDefinitions = nullptr;
                    return nullptr;
                }
                _implementedInterfaceDefinitions->push_back(pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>(interface, it->templateTypeNames));
            }
        }
    }
    return _implementedInterfaceDefinitions;
}

void CFunctionDefinition::dump(Compiler* compiler, int level) {
    // Skip if this is the function around global
    if (funcsByName[vector<string>()].size() > 0) {
        for (auto it : funcsByName) {
            for (auto it2 : it.second) {
                it2.second->dump(compiler, level);
            }
        }
    }
}

void CScope::addOrUpdateLocalVar(Compiler* compiler, vector<string>& packageNamespace, shared_ptr<CVar> var) {
    auto currentBlock = localVarScopes.size() > 0 ? localVarScopes.back() : nullptr;
    function->_data[returnMode].localVarsByName[currentBlock][packageNamespace][var->name] = var;
}

void CScope::pushLocalVarScope(shared_ptr<LocalVarScope> localVarScope) {
    localVarScopes.push_back(localVarScope);
}

void CScope::popLocalVarScope(shared_ptr<LocalVarScope> localVarScope) {
    assert(localVarScopes.back() == localVarScope);
    localVarScopes.erase(localVarScopes.end() - 1);
}

void CScope::pushImportScope(shared_ptr<ImportScope> importScope) {
    importScopes.push_back(importScope);
}

void CScope::popImportScope(shared_ptr<ImportScope> importScope) {
    assert(importScopes.back() == importScope);
    importScopes.erase(importScopes.end() - 1);
}

void CScope::setLocalVar(Compiler* compiler, CLoc loc, shared_ptr<CVar> var, bool overwrite) {
    if (!overwrite) {
        auto existingVar = function->getCVar(compiler, shared_from_this(), localVarScopes, dotNamespace, nullptr, var->name, VSM_LocalThisParent, returnMode);
        if (existingVar) {
            compiler->addError(loc, CErrorCode::InvalidVariable, "var '%s' already exists within function, must have a unique name", var->name.c_str());
        }
    }
    
    auto currentBlock = localVarScopes.size() > 0 ? localVarScopes.back() : nullptr;
    function->_data[returnMode].localVarsByName[currentBlock][dotNamespace][var->name] = var;
}

shared_ptr<CBaseFunction> CScope::getCFunction(Compiler* compiler, CLoc locCaller, const string& name, shared_ptr<CScope> callerScope, shared_ptr<CTypeNameList> templateTypeNames, CTypeMode returnMode) {
    if (function) {
        return function->getCFunction(compiler, locCaller, name, callerScope, templateTypeNames, returnMode);
    }
    else if (cinterface) {
        return cinterface->getCFunction(compiler, locCaller, name, callerScope, templateTypeNames, returnMode);
    }
    return nullptr;
}

shared_ptr<CType> CScope::getVarType(CLoc loc, Compiler* compiler, shared_ptr<CTypeName> typeName, CTypeMode defaultMode) {
    auto allNamespaces = getImportNamespacesWithRenames();
    if (function) {
        return function->getVarType(loc, compiler, allNamespaces, typeName, defaultMode);
    }
    else if (cinterface) {
        return cinterface->getVarType(loc, compiler, allNamespaces, typeName, defaultMode);
    }
    else {
        assert(false);
        return nullptr;
    }
}

shared_ptr<CVar> CScope::getCVar(Compiler* compiler, shared_ptr<CScope> callerScope, shared_ptr<CVar> dotVar, const string& name, VarScanMode scanMode) {
    if (function) {
        for (auto ns : getImportNamespaces()) {
            auto cvar = function->getCVar(compiler, callerScope == nullptr ? shared_from_this() : callerScope, localVarScopes, ns, dotVar, name, scanMode, returnMode);
            if (cvar) {
                return cvar;
            }
        }
    }
    return nullptr;
}

shared_ptr<CScope> CScope::getScopeForType(Compiler* compiler, shared_ptr<CType> type) {
    auto baseFunction = type->parent.lock();
    if (!baseFunction) {
        return nullptr;
    }
    
    if (baseFunction->classType == CFT_Function) {
        auto function = static_pointer_cast<CFunction>(baseFunction);
        auto returnMode = type->typeMode;
        if (returnMode == CTM_Local) {
            if (!function->_data[CTM_Stack].isInvalid) {
                return function->getScope(compiler, CTM_Stack);
            }
            else {
                return function->getScope(compiler, CTM_Heap);
            }
        }
        else {
            return function->getScope(compiler, returnMode);
        }
    }
    else if (baseFunction->classType == CFT_Interface) {
        auto cinterface = static_pointer_cast<CInterface>(baseFunction);
        return cinterface->getScope();
    }
    else {
        assert(false);
        return nullptr;
    }
}

vector<string> CScope::getNamespace(Compiler* compiler, string name) {
    vector<string> nsTest = dotNamespace;
    nsTest.push_back(name);
    if (compiler->namespaces.find(nsTest) != compiler->namespaces.end()) {
        vector<string> nsChild;
        nsChild.push_back(name);
        return nsChild;
    } else {
        if (function) {
            for (auto importNamespace : function->importNamespaces) {
                if (importNamespace.first == name) {
                    return importNamespace.second;
                }
            }
        }

        for (auto importScope : importScopes) {
            for (auto importNamespace : importScope->importNamespaces) {
                if (importNamespace.first == name) {
                    return importNamespace.second;
                }
            }
        }

        return vector<string>();
    }
}

void CScope::pushNamespace(Compiler* compiler, vector<string> nsChild) {
    for (auto nsTemp : nsChild) {
        dotNamespace.push_back(nsTemp);
        compiler->namespaces[dotNamespace] = true;
    }
}

void CScope::popNamespace(Compiler* compiler, vector<string> nsChild) {
    for (auto nsTemp = nsChild.rbegin(); nsTemp != nsChild.rend(); nsTemp++) {
        assert(dotNamespace.back() == *nsTemp);
        assert(dotNamespace.size() > 0);
        dotNamespace.erase(dotNamespace.end() - 1);
    }
}

void CScope::pushUnderscore(shared_ptr<CVar> underscoreVar) {
    underscoreVars.push_back(underscoreVar);
}

void CScope::popUnderscore(shared_ptr<CVar> underscoreVar) {
    assert(underscoreVars.back() == underscoreVar);
    underscoreVars.pop_back();
}

shared_ptr<CVar> CScope::getUnderscore(Compiler* compiler, shared_ptr<CScope> callerScope) {
    if (underscoreVars.size() > 0) {
        return underscoreVars.back();
    }
    else {
        return getCVar(compiler, callerScope, nullptr, "_1", VSM_LocalThisParent);
    }
}

vector<vector<string>> CScope::getImportNamespaces() {
    vector<vector<string>> allNamespaces;
    allNamespaces.push_back(vector<string>());
    
    if (function) {
        for (auto importNamespace : function->importNamespaces) {
            if (importNamespace.first.size() == 0) {
                allNamespaces.push_back(importNamespace.second);
            }
        }
    }

    for (auto importScope : importScopes) {
        for (auto importNamespace : importScope->importNamespaces) {
            if (importNamespace.first.size() == 0) {
                allNamespaces.push_back(importNamespace.second);
            }
        }
    }
    
    if (dotNamespace.size() > 0) {
        allNamespaces.push_back(dotNamespace);
    }
    
    return allNamespaces;
}

vector<pair<string, vector<string>>> CScope::getImportNamespacesWithRenames() {
    vector<pair<string, vector<string>>> allNamespaces;
    allNamespaces.push_back(make_pair(string(""), vector<string>()));

    if (function) {
        for (auto importNamespace : function->importNamespaces) {
            allNamespaces.push_back(importNamespace);
        }
    }

    for (auto importScope : importScopes) {
        for (auto importNamespace : importScope->importNamespaces) {
            allNamespaces.push_back(importNamespace);
        }
    }

    if (dotNamespace.size() > 0) {
        allNamespaces.push_back(make_pair(string(""), dotNamespace));
    }

    return allNamespaces;
}
