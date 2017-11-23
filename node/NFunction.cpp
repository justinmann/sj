#include "Node.h"

NFunction::NFunction(CLoc loc, CFunctionType type, shared_ptr<CTypeName> returnTypeName, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<CTypeNameList> interfaceTypeNames, shared_ptr<NodeList> arguments, shared_ptr<NBase> block, shared_ptr<NBase> catchBlock, shared_ptr<NBase> copyBlock, shared_ptr<NBase> destroyBlock) : NBaseFunction(NodeType_Function, loc), type(type), returnTypeName(returnTypeName), name(name), templateTypeNames(templateTypeNames), interfaceTypeNames(interfaceTypeNames), block(block), catchBlock(catchBlock), copyBlock(copyBlock), destroyBlock(destroyBlock) {
    if (this->name == "^") {
        this->name = TrBlock::nextVarName("anon");
        isAnonymous = true;
    }
    else {
        isAnonymous = false;
    }
    
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
            } else {
                invalid.push_back(it);
            }
        }
    }
}

void NFunction::defineImpl(Compiler *compiler, shared_ptr<CBaseFunctionDefinition> parentFunction) {
    assert(compiler->state == CompilerState::Define);
    if (invalid.size() > 0) {
        compiler->addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments, function definitions, or interface definitions");
        return;
    }
    
    auto thisFunction = getFunctionDefinition(compiler, static_pointer_cast<CFunctionDefinition>(parentFunction));
    if (!thisFunction) {
        return;
    }

    parentFunction->addChildFunction(name, thisFunction);

    for (auto it : interfaces) {
        it->define(compiler, thisFunction);
    }

    for (auto it : functions) {
        it->define(compiler, thisFunction);
    }
        
    for (auto it : assignments) {
        it->define(compiler, thisFunction);
    }

    if (block) {
        block->define(compiler, thisFunction);
    }
}

shared_ptr<CFunctionDefinition> NFunction::getFunctionDefinition(Compiler *compiler, shared_ptr<CFunctionDefinition> parentFunction) {
    return CFunctionDefinition::create(compiler, parentFunction, type, name, interfaceTypeNames, shared_from_this());
}

shared_ptr<CVar> NFunction::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    if (invalid.size() > 0) {
        compiler->addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return nullptr;
    }

    return nullptr;
}

shared_ptr<CFunction> NFunction::createCFunction(Compiler* compiler, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, CFunctionType type, const string& name, shared_ptr<vector<shared_ptr<CInterface>>> interfaces) {
    auto fun = make_shared<CFunction>(definition, type, templateTypes, parent, interfaces);
    return fun->init(compiler, shared_from_this());
}

CFunction::CFunction(weak_ptr<CBaseFunctionDefinition> definition, CFunctionType type, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces) :
CBaseFunction(CFT_Function, definition.lock()->name, parent, definition),
loc(CLoc::undefined),
type(type),
templateTypes(templateTypes),
interfaces(interfaces),
_isInGetType(false),
_block(nullptr),
_catchBlock(nullptr),
_destroyBlock(nullptr),
_returnTypeName(nullptr),
_interfaceTypeNames(nullptr),
_hasInitializedInterfaces(false),
_hasTranspileDefinitions(false),
_isReturnThis(false)
 {}

CTypeMode functionReturnModes[] = { CTM_Stack, CTM_Heap };

shared_ptr<CFunction> CFunction::init(Compiler* compiler, shared_ptr<NFunction> node) {
    for (auto it : templateTypes) {
        name = name + "_" + it->safeName;
    }
    
    if (node) {
        loc = node->loc;
        _functions = node->functions;
        _block = node->block;
        _catchBlock = node->catchBlock;
        _destroyBlock = node->destroyBlock;
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
                templateTypesByName[templateTypeName->valueName] = templateTypes[index];
                index++;
            }
        }
        
        auto index = 0;
        for (auto it : node->assignments) {
            if (it->var) {
                compiler->addError(it->loc, CErrorCode::InvalidDot, "cannot use '.' in variable declaration for a function: '%s'", it->name.c_str());
                return nullptr;
            }
            
            for (auto returnMode : functionReturnModes) {
                auto calleeScope = getScope(compiler, returnMode);
                auto argType = it->getType(compiler, calleeScope, CVarType::Var_Public, CTM_Undefined);
                if (!argType) {
                    return nullptr;
                }

                auto thisArgVar = make_shared<CNormalVar>(node->loc, calleeScope, argType, it->name, it->op == ASSIGN_Mutable || it->op == ASSIGN_MutableCopy, CVarType::Var_Public);
                _data[returnMode].thisArgVarsByName[it->name] = pair<int, shared_ptr<CVar>>(index, thisArgVar);
                _data[returnMode].thisArgVars.push_back(thisArgVar);
            }
            
            argDefaultValues.push_back(it->rightSide);
            index++;
        }
    }
    
    return shared_from_this();
}

void CFunction::transpileDefinition(Compiler* compiler, TrOutput* trOutput) {
    if (_hasTranspileDefinitions)
        return;
    
    _hasTranspileDefinitions = true;
    
    for (auto returnMode : functionReturnModes) {
        auto calleeVar = getThisVar(compiler, returnMode);
        auto calleeScope = getScope(compiler, returnMode);
        auto returnType = getReturnType(compiler, returnMode);
        
        // If we attempt to return stack and can only generate a heap return then the stack return mode is invalid
        if (returnMode == CTM_Stack && returnType->typeMode == CTM_Heap) {
            _data[returnMode].isInvalid = true;
            continue;
        }

        // If we attempt to return heap and cannot generate a heap return then the heap return mode is invalid, value types are handled by the stack return mode
        if (returnMode == CTM_Heap && returnType->typeMode != CTM_Heap) {
            _data[returnMode].isInvalid = true;
            continue;
        }

        if (!hasThis) {
            // Create function body
            auto functionName = getCInitFunctionName(returnMode);
            auto functionBody = trOutput->functions.find(functionName);
            if (functionBody == trOutput->functions.end()) {
                auto trFunctionBlock = make_shared<TrBlock>();
                trFunctionBlock->parent = nullptr;
                trFunctionBlock->hasThis = false;
                trOutput->functions[functionName] = trFunctionBlock;

                stringstream functionDefinition;
                functionDefinition << "void " << functionName << "(";
                auto isFirstArg = true;
                auto argTypes = getCTypeList(compiler, returnMode);
                for (auto argType : *argTypes) {
                    if (isFirstArg) {
                        isFirstArg = false;
                    }
                    else {
                        functionDefinition << ", ";
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

                auto blockVar = _block->getVar(compiler, calleeScope, returnMode);
                auto bodyReturnValue = (returnType == compiler->typeVoid) ? trFunctionBlock->createVoidStoreVariable(loc, returnType) : trFunctionBlock->createReturnStoreVariable(loc, nullptr, returnType);
                blockVar->transpile(compiler, trOutput, trFunctionBlock.get(), nullptr, nullptr, bodyReturnValue);
            }
        }
        else {
            // Create init function body
            auto functionName = getCInitFunctionName(returnMode);
            auto functionBody = trOutput->functions.find(functionName);
            if (functionBody == trOutput->functions.end()) {
                auto returnType = getReturnType(compiler, returnMode);
                auto trFunctionBlock = make_shared<TrBlock>();
                trFunctionBlock->parent = nullptr;
                trFunctionBlock->hasThis = true;
                trOutput->functions[functionName] = trFunctionBlock;

                auto blockVar = _block->getVar(compiler, calleeScope, returnType->typeMode);
                _isReturnThis = blockVar->getReturnThis();
                auto bodyReturnValue = (returnType != compiler->typeVoid && !_isReturnThis) ? trFunctionBlock->createReturnStoreVariable(loc, nullptr, returnType) : trFunctionBlock->createVoidStoreVariable(loc, returnType);
                blockVar->transpile(compiler, trOutput, trFunctionBlock.get(), nullptr, make_shared<TrValue>(nullptr, calleeVar->getType(compiler), "_this", false), bodyReturnValue);

                string structName = getCStructName(calleeVar->getTypeMode());
                stringstream functionDefinition;
                functionDefinition << "void " << functionName << "(" << structName << "* _this";
                if (returnType != compiler->typeVoid && !_isReturnThis) {
                    functionDefinition << ", " << returnType->cname << "* _return";
                }
                functionDefinition << ")";
                trFunctionBlock->definition = functionDefinition.str();
            }

            // Create struct
            string stackStructName = getCStructName(CTM_Stack);
            if (trOutput->structs.find(stackStructName) == trOutput->structs.end()) {
                bool hasValues = false;
                auto argTypes = getCTypeList(compiler, returnMode);
                for (auto argType : *argTypes) {
                    if (argType.first.compare("_this") == 0)
                        continue;

                    hasValues = true;
                    stringstream ss;
                    ss << argType.second->cname;
                    if (argType.second->typeMode == CTM_Stack) {
                        // C requires that inline structs be defined before use
                        argType.second->parent.lock()->transpileDefinition(compiler, trOutput);
                    }
                    ss << " " << argType.first;
                    trOutput->structs[stackStructName].push_back(ss.str());
                }

                if (!hasValues) {
                    trOutput->structs[stackStructName].push_back("int structsNeedAValue");
                }

                trOutput->structOrder.push_back(stackStructName);
            }

            if (calleeVar->getTypeMode() == CTM_Heap) {
                string heapStructName = getCStructName(CTM_Heap);
                if (trOutput->structs.find(heapStructName) == trOutput->structs.end()) {
                    trOutput->structs[heapStructName].push_back("int _refCount");

                    auto argTypes = getCTypeList(compiler, returnMode);
                    for (auto argType : *argTypes) {
                        if (argType.first.compare("_this") == 0)
                            continue;

                        stringstream ss;
                        if (argType.second->typeMode == CTM_Stack) {
                            ss << argType.second->cname;

                            // C requires that inline structs be defined before use
                            argType.second->parent.lock()->transpileDefinition(compiler, trOutput);
                        }
                        else if (argType.second->typeMode == CTM_Heap || argType.second->typeMode == CTM_Value) {
                            ss << argType.second->cname;
                        }
                        else {
                            compiler->addError(loc, CErrorCode::InvalidType, "var '%s' is local which is not allowed", argType.first.c_str());
                        }
                        ss << " " << argType.first;
                        trOutput->structs[heapStructName].push_back(ss.str());
                    }

                    trOutput->structOrder.push_back(heapStructName);
                }
            }

            // Create copy function body
            string functionCopyName = getCCopyFunctionName();
            if (trOutput->functions.find(functionCopyName) == trOutput->functions.end()) {
                auto trCopyBlock = make_shared<TrBlock>();
                trCopyBlock->parent = nullptr;
                trCopyBlock->hasThis = true;
                trOutput->functions[functionCopyName] = trCopyBlock;

                stringstream functionDefinition;
                functionDefinition << "void " << functionCopyName << "(" << stackStructName << "* _this, " << stackStructName << "* to)";
                trCopyBlock->definition = functionDefinition.str();

                for (auto argVar : _data[returnMode].thisArgVars) {
                    auto argType = argVar->getType(compiler);
                    TrStoreValue(argVar->loc, calleeScope, argType, "_this->" + argVar->name, ASSIGN_ImmutableCopy, true).retainValue(compiler, trCopyBlock.get(), make_shared<TrValue>(calleeScope, argType, "to->" + argVar->name, false));
                }

                if (_copyBlock) {
                    auto copyBlockVar = _copyBlock->getVar(compiler, calleeScope, CTM_Undefined);
                    if (copyBlockVar) {
                        auto copyType = copyBlockVar->getType(compiler);
                        copyBlockVar->transpile(compiler, trOutput, trCopyBlock.get(), nullptr, make_shared<TrValue>(nullptr, calleeVar->getType(compiler), "_this", false), trCopyBlock->createVoidStoreVariable(loc, copyType));
                    }
                }
            }

            // Create destroy function body
            string functionDestroyName = getCDestroyFunctionName();
            if (trOutput->functions.find(functionDestroyName) == trOutput->functions.end()) {
                auto trDestroyBlock = make_shared<TrBlock>();
                trDestroyBlock->parent = nullptr;
                trDestroyBlock->hasThis = true;
                trOutput->functions[functionDestroyName] = trDestroyBlock;

                stringstream functionDefinition;
                functionDefinition << "void " << functionDestroyName << "(" << stackStructName << "* _this)";
                trDestroyBlock->definition = functionDefinition.str();

                if (_destroyBlock) {
                    auto destroyBlockVar = _destroyBlock->getVar(compiler, calleeScope, CTM_Undefined);
                    if (destroyBlockVar) {
                        auto destroyType = destroyBlockVar->getType(compiler);
                        destroyBlockVar->transpile(compiler, trOutput, trDestroyBlock.get(), nullptr, make_shared<TrValue>(nullptr, calleeVar->getType(compiler), "_this", false), trDestroyBlock->createVoidStoreVariable(loc, destroyType));
                    }
                }

                for (auto argVar : _data[returnMode].thisArgVars) {
                    TrValue(calleeScope, argVar->getType(compiler), "_this->" + argVar->name, false).addReleaseToStatements(trDestroyBlock.get());
                }
            }

            // Create interfaces
            if (interfaces != nullptr) {
                for (auto interfaceVal : *interfaces) {
                    interfaceVal->transpileDefinition(compiler, trOutput);

                    // Create explict cast
                    auto castFunctionName = interfaceVal->getCCastFunctionName(shared_from_this(), returnMode);
                    auto functionBody = trOutput->functions.find(castFunctionName);
                    if (functionBody == trOutput->functions.end()) {
                        auto trFunctionBlock = make_shared<TrBlock>();
                        trFunctionBlock->parent = nullptr;
                        trFunctionBlock->hasThis = true;
                        trOutput->functions[castFunctionName] = trFunctionBlock;

                        string structName = getCStructName(calleeVar->getTypeMode());
                        auto interfaceType = interfaceVal->getThisTypes(compiler)->localValueType;
                        stringstream functionDefinition;
                        functionDefinition << interfaceType->cname << " " << castFunctionName << "(" << structName << "* _this)";
                        trFunctionBlock->definition = functionDefinition.str();
                        auto interfaceValue = make_shared<TrValue>(calleeScope, interfaceVal->getThisTypes(compiler)->heapValueType, "_interface", false);
                        trFunctionBlock->statements.push_back(interfaceValue->type->cname + " _interface");
                        interfaceValue->addInitToStatements(trFunctionBlock.get());
                        trFunctionBlock->statements.push_back(string("_interface->_parent = (sjs_object*)_this"));
                        trFunctionBlock->statements.push_back(string("_interface->_parent->_refCount++"));
                        trFunctionBlock->statements.push_back(string("_interface->destroy = (void(*)(void*))" + getCDestroyFunctionName()));
                        trFunctionBlock->statements.push_back(string("_interface->asInterface = (sjs_object*(*)(sjs_object*,int))" + getCAsInterfaceFunctionName(returnMode)));

                        for (auto interfaceMethod : interfaceVal->methods) {
                            auto implementation = static_pointer_cast<CFunction>(getCFunction(compiler, loc, interfaceMethod->name, nullptr, nullptr, CTM_Undefined));
                            if (implementation) {
                                implementation->transpileDefinition(compiler, trOutput);

                                if (implementation->_data[interfaceMethod->returnMode].isInvalid) {
                                    compiler->addError(loc, CErrorCode::InterfaceMethodDoesNotExist, "method '%s' does not support %s return mode", implementation->name.c_str(), interfaceMethod->returnMode == CTM_Heap ? "heap" : "stack");
                                    continue;
                                }
                                
                                stringstream initStream;
                                initStream << "_interface->" << interfaceMethod->name;
                                if (interfaceMethod->returnMode == CTM_Heap) {
                                    initStream << "_heap";
                                }
                                initStream << " = (" << interfaceMethod->getCTypeName(compiler, false) << ")" << implementation->getCInitFunctionName(interfaceMethod->returnMode);
                                trFunctionBlock->statements.push_back(initStream.str());
                            }
                        }

                        trFunctionBlock->returnLine = "_interface";
                    }
                }

                string asInterfaceFunctionName = getCAsInterfaceFunctionName(returnMode);
                auto asInterfaceFunctionBody = trOutput->functions.find(asInterfaceFunctionName);
                if (asInterfaceFunctionBody == trOutput->functions.end()) {
                    auto trFunctionBlock = make_shared<TrBlock>();
                    trFunctionBlock->parent = nullptr;
                    trFunctionBlock->hasThis = true;
                    trOutput->functions[asInterfaceFunctionName] = trFunctionBlock;

                    string structName = getCStructName(calleeVar->getTypeMode());
                    stringstream functionDefinition;
                    functionDefinition << "sjs_object* " << asInterfaceFunctionName << "(" << structName << "* _this, int typeId)";
                    trFunctionBlock->definition = functionDefinition.str();

                    auto switchBlock = make_shared<TrBlock>();
                    trFunctionBlock->statements.push_back(TrStatement("switch (typeId)", switchBlock));
                    for (auto interfaceVal : *interfaces) {
                        auto caseBlock = make_shared<TrBlock>();
                        caseBlock->statements.push_back(string("return (sjs_object*)") + interfaceVal->getCCastFunctionName(shared_from_this(), returnMode) + "(_this)");
                        switchBlock->statements.push_back(TrStatement(string("case ") + interfaceVal->getCTypeIdName() + ": ", caseBlock));
                    }

                    trFunctionBlock->returnLine = "0";
                }
            }
        }
    }
}

void CFunction::transpile(Compiler* compiler, shared_ptr<CScope> callerScope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> parentValue, CLoc& calleeLoc, vector<pair<bool, shared_ptr<NBase>>>& parameters, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue, CTypeMode returnMode) {
    transpileDefinition(compiler, trOutput);

    assert(compiler->state == CompilerState::Compile);
    assert(returnMode == CTM_Stack || returnMode == CTM_Heap);
    
    if (_data[returnMode].isInvalid) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "funnction '%s' cannot return '%s'", name.c_str(), returnMode == CTM_Heap ? "heap" : "stack");
        return;
    }
    
    auto returnType = getReturnType(compiler, returnMode);
    if (!returnType) {
        return;
    }
    
    assert(returnType == storeValue->type);
    auto calleeVar = getThisVar(compiler, returnMode);
    auto calleeScope = getScope(compiler, returnMode);

    if (!hasThis) {
        auto functionName = getCInitFunctionName(returnMode);
        stringstream line;
        line << functionName << "(";
        bool isFirstParameter = true;

        // Add "parent" to "this"
        auto hasParent = getHasParent(compiler);
        shared_ptr<TrValue> dotTrValue;
        if (hasParent) {
            if (isFirstParameter) {
                isFirstParameter = false;
            }
            else {
                line << ", ";
            }
            if (!parentValue) {
                line << (trBlock->hasThis ? "_this" : "_parent");
            }
            else {
                line << parentValue->name;
            }
        }

        auto argTypes = getCTypeList(compiler, returnMode);
        auto argIndex = 0;
        // Fill in "this" with normal arguments
        for (auto defaultAssignment : argDefaultValues) {
            auto argVar = _data[returnMode].thisArgVars[argIndex];
            auto argType = argVar->getType(compiler);
            auto isDefaultAssignment = parameters[argIndex].second == defaultAssignment;
            assert(isDefaultAssignment == parameters[argIndex].first);

            stringstream argStream;
            auto parameterVar = parameters[argIndex].second->getVar(compiler, isDefaultAssignment ? calleeScope : callerScope, CTM_Undefined);
            if (!parameterVar) {
                assert(compiler->errors.size() > 0);
                return;
            }
            auto argStoreValue = trBlock->createTempStoreVariable(loc, callerScope, argType->typeMode == CTM_Heap ? argType : argType->getLocalValueType(), "functionParam");
            parameterVar->transpile(compiler, trOutput, trBlock, nullptr, isDefaultAssignment ? nullptr : thisValue, argStoreValue);

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
            if (isFirstParameter) {
                isFirstParameter = false;
            }
            else {
                line << ", ";
            }
            line << "&" << storeValue->getName(trBlock);
            storeValue->hasSetValue = true;
        }
        line << ")";
        trBlock->statements.push_back(line.str());
    } else {
        auto functionName = getCInitFunctionName(returnMode);

        // Initialize "this"
        shared_ptr<TrValue> calleeThisValue;
        if (_isReturnThis && storeValue->type != nullptr) {
            // TODO: need to figure how to handle the various types of assignment
            calleeThisValue = make_shared<TrValue>(storeValue->scope, storeValue->type, storeValue->getName(trBlock), storeValue->isReturnValue);
            calleeThisValue->addInitToStatements(trBlock);
        }
        else {
            calleeThisValue = trBlock->createTempVariable(callerScope, calleeVar->getType(compiler), "object");
            calleeThisValue->addInitToStatements(trBlock);
        }

        if (hasParent) {
            stringstream parentLine;
            if (!parentValue) {
                if (parent.lock() == callerScope->function) {
                    if (thisValue != nullptr) {
                        parentLine << calleeThisValue->getDotName("_parent") << " = " << thisValue->getDotName("_parent");
                    }
                }
                else if (parent.lock() == callerScope->function->parent.lock()) {
                    parentLine << calleeThisValue->getDotName("_parent") << " = ";
                    if (callerScope->function->hasThis) {
                        parentLine << thisValue->getDotName("_parent") << "->";
                    }
                    else {
                        parentLine << "_parent";
                    }
                }
                else if (parent.lock() == callerScope->function->parent.lock()->parent.lock()) {
                    parentLine << calleeThisValue->getDotName("_parent") << " = ";
                    if (callerScope->function->hasThis) {
                        parentLine << thisValue->getDotName("_parent->_parent");
                    }
                    else {
                        parentLine << "_parent->_parent";
                    }
                }
                else {
                    assert(false);
                }
            }
            else {
                parentLine << calleeThisValue->getDotName("_parent") << " = " << parentValue->name;
            }
            trBlock->statements.push_back(parentLine.str());
        }

        auto argTypes = getCTypeList(compiler, returnMode);
        auto argIndex = 0;
        // Fill in "this" with normal arguments
        for (auto defaultAssignment : argDefaultValues) {
            auto argVar = _data[returnMode].thisArgVars[argIndex];
            auto argType = argVar->getType(compiler);
            auto isDefaultAssignment = parameters[argIndex].second == defaultAssignment;
            assert(isDefaultAssignment == parameters[argIndex].first);

            stringstream argStream;
            auto parameterVar = parameters[argIndex].second->getVar(compiler, isDefaultAssignment ? calleeScope : callerScope, CTM_Undefined);
            if (!parameterVar) {
                assert(compiler->errors.size() > 0);
                return;
            }

            auto argStoreValue = make_shared<TrStoreValue>(loc, calleeScope, argType, calleeThisValue->getDotName(argVar->name), ASSIGN_Immutable, true);
            parameterVar->transpile(compiler, trOutput, trBlock, nullptr, isDefaultAssignment ? calleeThisValue : thisValue, argStoreValue);

            if (!argStoreValue->hasSetValue) {
                compiler->addError(calleeLoc, CErrorCode::TypeMismatch, "parameter '%s' has no value", argVar->name.c_str());
                return;
            }
            argIndex++;
        }

        // Call function
        stringstream line;
        line << functionName << "(" << calleeThisValue->getPointerName();
        if (returnType != compiler->typeVoid && !_isReturnThis) {
            line << ", &" << storeValue->getName(trBlock);
        }
        line << ")";
        trBlock->statements.push_back(line.str());
        storeValue->hasSetValue = true;
    }
}

string CFunction::getCBaseName(CTypeMode returnMode) {
    assert(returnMode == CTM_Stack || returnMode == CTM_Heap);
    assert(!_data[returnMode].isInvalid);

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
    return string("sjs_") + getCBaseName(returnMode);
}

string CFunction::getCInitFunctionName(CTypeMode returnMode) {
    return string("sjf_") + getCBaseName(returnMode);
}

string CFunction::getCCopyFunctionName() {
    return string("sjf_") + getCBaseName(CTM_Stack) + "_copy";
}

string CFunction::getCDestroyFunctionName() {
    return string("sjf_") + getCBaseName(CTM_Stack) + "_destroy";
}

string CFunction::getCAsInterfaceFunctionName(CTypeMode returnMode) {
    return getCInitFunctionName(returnMode) + "_asInterface";
}

void CFunction::dumpBody(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level, CTypeMode returnMode) {
    assert(returnMode == CTM_Stack || returnMode == CTM_Heap);
    assert(!_data[returnMode].isInvalid);

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

    if (_block) {
        ss << " ";
        
        stringstream dotSS;
        auto calleeVar = getThisVar(compiler, returnMode);
        auto calleeScope = getScope(compiler, returnMode);
        auto blockVar = _block->getVar(compiler, calleeScope, returnMode);
        blockVar->dump(compiler, nullptr, functions, ss, dotSS, level);
    }
}

shared_ptr<CThisVar> CFunction::getThisVar(Compiler* compiler, CTypeMode returnMode) {
    assert(returnMode == CTM_Stack || returnMode == CTM_Heap);
    assert(!_data[returnMode].isInvalid);

    if (!_hasInitializedInterfaces) {
        _hasInitializedInterfaces = true;
        if (interfaces) {
            // Make all functions used by an interface are defined
            for (auto interface : *interfaces) {
                for (auto interfaceMethod : interface->methods) {
                    auto cfunc = static_pointer_cast<CFunction>(getCFunction(compiler, loc, interfaceMethod->name, nullptr, nullptr, CTM_Undefined));
                    if (!cfunc) {
                        compiler->addError(loc, CErrorCode::InterfaceMethodDoesNotExist, "cannot find interface method: '%s'", interfaceMethod->name.c_str());
                        return nullptr;
                    }

                    auto functionReturnType = cfunc->getReturnType(compiler, interfaceMethod->returnMode);
                    auto interfaceMethodReturnType = interfaceMethod->getReturnType(compiler, CTM_Undefined);
                    if (functionReturnType != interfaceMethodReturnType) {
                        compiler->addError(loc, CErrorCode::TypeMismatch, "function return type '%s' does not match interface method return type '%s'", functionReturnType->fullName.c_str(), interfaceMethodReturnType->fullName.c_str());
                    }

                    auto functionArgVars = cfunc->getArgVars(compiler, interfaceMethod->returnMode);
                    auto interfaceMethodArgVars = interfaceMethod->argVars;
                    if (functionArgVars->size() != interfaceMethodArgVars.size()) {
                        compiler->addError(loc, CErrorCode::InterfaceMethodTypeMismatch, "function has %d arguments does not match interface method arguments %d", functionArgVars->size(), interfaceMethodArgVars.size());
                    }
                    else {
                        for (auto i = (size_t)0; i < functionArgVars->size(); i++) {
                            auto aType = (*functionArgVars)[i]->getType(compiler);
                            auto bType = interfaceMethodArgVars[i]->getType(compiler);
                            if (aType != bType) {
                                compiler->addError(loc, CErrorCode::TypeMismatch, "function parameter %d type '%s' does not match interface method parameter type '%s'", i + 1, aType ? aType->fullName.c_str() : "Unknown", bType ? bType->fullName.c_str() : "Unknown");
                            }
                        }
                    }

                    assert(!cfunc->hasThis);
                    cfunc->setHasParent(compiler); // All interface methods must take the parent has first pointer even if they don't need it
                }
            }
        }
    }

    if (!_data[returnMode].thisVar) {
        auto defaultTypeMode = CTM_Undefined;
        if (_returnTypeName) {
            shared_ptr<CType> valueType = getVarType(loc, compiler, _returnTypeName, CTM_Undefined);
            if (!valueType) {
                compiler->addError(loc, CErrorCode::InvalidType, "explicit type '%s' does not exist", _returnTypeName->getFullName().c_str());
                return nullptr;
            }
            defaultTypeMode = valueType->typeMode;
        }

        auto thisTypes = getThisTypes(compiler);
        _data[returnMode].thisVar = make_shared<CThisVar>(loc, nullptr, thisTypes, defaultTypeMode);
    }
    return _data[returnMode].thisVar;
}

shared_ptr<CType> CFunction::getReturnType(Compiler* compiler, CTypeMode returnMode) {
    assert(returnMode == CTM_Stack || returnMode == CTM_Heap);

    if (_isInGetType) {
        compiler->addError(loc, CErrorCode::TypeLoop, "while trying to determine type a cycle was detected");
        return nullptr;
    }
    
    _isInGetType = true;    
    if (!_data[returnMode].returnType) {
        if (_returnTypeName) {
            shared_ptr<CType> valueType = getVarType(loc, compiler, _returnTypeName, CTM_Undefined);
            if (!valueType) {
                compiler->addError(loc, CErrorCode::InvalidType, "explicit type '%s' does not exist", _returnTypeName->getFullName().c_str());
                _data[returnMode].returnType = nullptr;
            }
            _data[returnMode].returnType = valueType;
        }
        
        if (_block) {
            auto calleeVar = getThisVar(compiler, returnMode);
            auto calleeScope = getScope(compiler, returnMode);
            auto blockVar = _block->getVar(compiler, calleeScope, _data[returnMode].returnType ? _data[returnMode].returnType->typeMode : returnMode);
            auto type = blockVar->getType(compiler);
            if (!_data[returnMode].returnType) {
                _data[returnMode].returnType = type;
            }
        }
        
        if (_data[returnMode].returnType == nullptr) {
            _data[returnMode].returnType = compiler->typeVoid;
        }
    }
    
    _isInGetType = false;
    return _data[returnMode].returnType;
}

shared_ptr<vector<shared_ptr<CVar>>> CFunction::getArgVars(Compiler* compiler, CTypeMode returnMode) {
    assert(returnMode == CTM_Stack || returnMode == CTM_Heap);
    assert(!_data[returnMode].isInvalid);

    auto calleeVar = getThisVar(compiler, returnMode);
    auto calleeScope = getScope(compiler, returnMode);
    auto args = make_shared<vector<shared_ptr<CVar>>>();
    for (auto it : argDefaultValues) {
        auto var = it->getVar(compiler, calleeScope, CTM_Undefined);
        assert(var);
        args->push_back(var);
    }
    return args;
}

shared_ptr<CTypes> CFunction::getThisTypes(Compiler* compiler) {
    if (!_thisTypes) {
        _thisTypes = CType::create(compiler, name.c_str(), shared_from_this());
    }
    return _thisTypes;
}

shared_ptr<CScope> CFunction::getScope(Compiler* compiler, CTypeMode returnMode) {
    if (_data[returnMode].scope == nullptr) {
        auto calleeVar = getThisVar(compiler, returnMode);
        _data[returnMode].scope = make_shared<CScope>(shared_from_this(), calleeVar, returnMode);
    }
    return _data[returnMode].scope;
}

int CFunction::getArgIndex(const string& name, CTypeMode returnMode) {
    if (_data[returnMode].thisArgVarsByName.find(name) != _data[returnMode].thisArgVarsByName.end()) {
        return _data[returnMode].thisArgVarsByName[name].first;
    }
    return -1;
}

shared_ptr<CVar> CFunction::getArgVar(int index, CTypeMode returnMode) {
    return _data[returnMode].thisArgVars[index];
}

int CFunction::getArgCount(CTypeMode returnMode) {
    return (int)_data[returnMode].thisArgVars.size();
}

shared_ptr<vector<pair<string, shared_ptr<CType>>>> CFunction::getCTypeList(Compiler* compiler, CTypeMode returnMode) {
    assert(returnMode == CTM_Stack || returnMode == CTM_Heap);
    assert(!_data[returnMode].isInvalid);

    if (!_data[returnMode].ctypeList) {
        _data[returnMode].ctypeList = make_shared<vector<pair<string, shared_ptr<CType>>>>();

        if (hasThis) {
            _data[returnMode].ctypeList->push_back(make_pair("_this", compiler->typePtr));
        }

        if (hasParent) {
            auto parentType = parent.lock()->getThisTypes(compiler);
            _data[returnMode].ctypeList->push_back(make_pair("_parent", parentType->localValueType));
        }

        for (auto it : _data[returnMode].thisArgVars) {
            auto ctype = it->getType(compiler);
            if (!ctype) {
                compiler->addError(it->loc, CErrorCode::InvalidType, "cannot determine type for '%s'", it->name.c_str());
                return nullptr;
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
                ctype = thisFunction->getVarType(loc, compiler, templateTypeName, CTM_Undefined);
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
    auto t = def->funcsByName.find(name);
    if (t != def->funcsByName.end()) {
        auto funcDef = t->second;
        
        vector<shared_ptr<CType>> templateTypes;
        if (!getTemplateTypes(compiler, locCaller, shared_from_this(), callerScope, templateTypeNames, funcDef->node->templateTypeNames, templateTypes)) {
            return nullptr;
        }
        
        return funcDef->getFunction(compiler, locCaller, templateTypes, shared_from_this());
    }
    return nullptr;
}

shared_ptr<CInterface> CFunction::getCInterface(Compiler* compiler, const string& name, shared_ptr<CScope> callerScope, shared_ptr<CTypeNameList> templateTypeNames) {
    if (name.find('.') != string::npos) {
        vector<string> names;
        istringstream f(name.substr(1, name.size() - 1));
        string s;
        while (getline(f, s, '.')) {
            names.push_back(s);
        }

        auto cfunc = shared_from_this();
        for (auto name : names) {
            if (name == names.back()) {
                return cfunc->getCInterface(compiler, "#" + name, callerScope, templateTypeNames);
            }
            else {
                auto var = cfunc->getCVar(compiler, name, CTM_Stack);
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
        auto interfaceDef = def->getDefinedInterfaceDefinition(name);
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

shared_ptr<CVar> CFunction::getCVar(Compiler* compiler, const string& name, CTypeMode returnMode) {
    if (returnMode == CTM_Undefined) {
        if (!_data[CTM_Stack].isInvalid) {
            auto result = getCVar(compiler, name, CTM_Stack);
            if (result) {
                return result;
            }
        }

        if (!_data[CTM_Heap].isInvalid) {
            auto result = getCVar(compiler, name, CTM_Heap);
            if (result) {
                return result;
            }
        }
    }
    else {
        assert(returnMode == CTM_Stack || returnMode == CTM_Heap);
        assert(!_data[returnMode].isInvalid);

        auto t1 = _data[returnMode].localVarsByName.find(name);
        if (t1 != _data[returnMode].localVarsByName.end()) {
            return t1->second;
        }
        
        auto t2 = _data[returnMode].thisArgVarsByName.find(name);
        if (t2 != _data[returnMode].thisArgVarsByName.end()) {
            return t2->second.second;
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
    ss << definition.lock()->name;
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

pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>> CFunction::getFunctionDefinition(string name) {
    auto functionDefinition = static_pointer_cast<CFunctionDefinition>(definition.lock());
    auto t2 = functionDefinition->funcsByName.find(name);
    if (t2 != functionDefinition->funcsByName.end()) {
        return make_pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>>(shared_from_this(), t2->second);
    }
    
    if (!parent.expired()) {
        return parent.lock()->getFunctionDefinition(name);
    }

    return make_pair<shared_ptr<CFunction>, shared_ptr<CBaseFunctionDefinition>>(nullptr, nullptr);
}

shared_ptr<CType> CFunction::getVarType(Compiler* compiler, string name) {
    auto t = templateTypesByName.find(name);
    if (t != templateTypesByName.end()) {
        return t->second;
    }

    if (!parent.expired()) {
        return static_pointer_cast<CFunction>(parent.lock())->getVarType(compiler, name);
    }
    
    return compiler->getType(name);
}

shared_ptr<CType> CFunction::getVarType(CLoc loc, Compiler* compiler, shared_ptr<CTypeName> typeName, CTypeMode defaultMode) {
    auto typeMode = defaultMode;
    if (typeName->typeMode != CTM_Undefined) {
        typeMode = typeName->typeMode;
    }

    if (typeName->category == CTC_Interface) {
        auto interface = getCInterface(compiler, typeName->valueName, nullptr, typeName->templateTypeNames);
        if (interface) {
            auto thisTypes = interface->getThisTypes(compiler);
            return typeName->isOption ? thisTypes->heapOptionType : thisTypes->heapValueType;
        }
    } else {
        assert(typeName->category == CTC_Value);
        if (typeName->templateTypeNames == nullptr) {
            auto ctype = getVarType(compiler, typeName->valueName);
            if (ctype) {
                return ctype;
            }
        }
        
        auto baseFunctionDefinition = getFunctionDefinition(typeName->valueName);
        if (baseFunctionDefinition.second != nullptr) {
            auto templateTypes = vector<shared_ptr<CType>>();
            if (typeName->templateTypeNames) {
                for (auto it : *typeName->templateTypeNames) {
                    auto t = getVarType(loc, compiler, it, CTM_Undefined);
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
                case CTM_Stack:
                    if (typeName->isOption) {
                        compiler->addError(loc, CErrorCode::InvalidType, "option type cannot be stack, stack x? is invalid use heap x?");
                        return nullptr;
                    }
                    else {
                        return thisTypes->stackValueType;
                    }
                case CTM_Local:
                    return typeName->isOption ? thisTypes->localOptionType : thisTypes->localValueType;
                default:
                    return typeName->isOption ? thisTypes->heapOptionType : thisTypes->stackValueType;
            }
        }
    }
    return nullptr;
}

shared_ptr<CFunctionDefinition> CFunctionDefinition::create(Compiler* compiler, shared_ptr<CFunctionDefinition> parent, CFunctionType type, const string& name, shared_ptr<CTypeNameList> implementedInterfaceTypeNames, shared_ptr<NFunction> node) {
    auto c = make_shared<CFunctionDefinition>();
    c->parent = parent;
    c->type = type;
    c->name = name;
    c->implementedInterfaceTypeNames = implementedInterfaceTypeNames;
    c->node = node;
    
    if (node) {
        for (auto it : node->interfaces) {
            it->define(compiler, c);
        }

        for (auto it : node->functions) {
            c->funcsByName[it->name] = it->getFunctionDefinition(compiler, c);
        }
        
        for (auto it : node->assignments) {
            if (it->var) {
                compiler->addError(it->loc, CErrorCode::InvalidDot, "cannot use '.' in variable declaration for a function: '%s'", it->name.c_str());
            }
        }
    }
    return c;
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

void CFunctionDefinition::addChildFunction(string& name, shared_ptr<CBaseFunctionDefinition> childFunction) {
    funcsByName[name] = static_pointer_cast<CFunctionDefinition>(childFunction);
}

shared_ptr<CFunction> CFunctionDefinition::getFunction(Compiler* compiler, CLoc loc, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CFunction> funcParent) {
    shared_ptr<CFunction> func;
    auto funcParentPtr = funcParent.lock().get();
    auto it = _cfunctions[funcParentPtr].find(templateTypes);
    if (it != _cfunctions[funcParentPtr].end()) {
        func = it->second;
        assert(func->parent.lock() == funcParent.lock());
    } else {
        assert(funcParent.expired() || funcParent.lock()->definition.lock() == parent.lock());
        
        shared_ptr<vector<shared_ptr<CInterface>>> interfaces;
        if (getImplementedInterfaceDefintions(compiler)) {
            interfaces = make_shared<vector<shared_ptr<CInterface>>>();
        }
        
        func = node->createCFunction(compiler, shared_from_this(), templateTypes, funcParent, type, name, interfaces);
        if (func == nullptr) {
            return nullptr;
        }

        if (getImplementedInterfaceDefintions(compiler)) {
            for (auto it : *getImplementedInterfaceDefintions(compiler)) {
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
    }
    return func;
}

shared_ptr<CInterfaceDefinition> CFunctionDefinition::getDefinedInterfaceDefinition(const string& name) {
    auto it = _definedInterfaceDefinitions.find(name);
    if (it == _definedInterfaceDefinitions.end()) {
        if (!parent.expired()) {
            auto t = static_pointer_cast<CFunctionDefinition>(parent.lock());
            return t->getDefinedInterfaceDefinition(name);
        }
        else {
            return nullptr;
        }
    }
    else {
        return it->second;
    }
}

shared_ptr<CInterfaceDefinition> CFunctionDefinition::createDefinedInterfaceDefinition(CLoc loc, string& name) {
    auto result = make_shared<CInterfaceDefinition>(loc, name);
    _definedInterfaceDefinitions[name] = result;
    return result;
}

shared_ptr<vector<pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>>> CFunctionDefinition::getImplementedInterfaceDefintions(Compiler* compiler) {
    if (!_implementedInterfaceDefinitions) {
        if (implementedInterfaceTypeNames) {
            _implementedInterfaceDefinitions = make_shared<vector<pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>>>();
            for (auto it : *implementedInterfaceTypeNames) {
                auto interface = getDefinedInterfaceDefinition(it->valueName);
                if (interface == nullptr) {
                    compiler->addError(loc, CErrorCode::InterfaceDoesNotExist, "cannot find interface '%s'", it->valueName.c_str());
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
    if (funcsByName.size() > 0) {
        for (auto it : funcsByName) {
            it.second->dump(compiler, level);
        }
    }
}

shared_ptr<CVar> CScope::findLocalVar(Compiler* compiler, string name) {
    auto iter = function->_data[returnMode].localVarsByName.find(name);
    if (iter != function->_data[returnMode].localVarsByName.end()) {
        return iter->second;
    }
    return nullptr;
}

void CScope::addOrUpdateLocalVar(Compiler* compiler, string name, shared_ptr<CVar> var) {
    function->_data[returnMode].localVarsByName[name] = var;
}

void CScope::pushLocalVar(Compiler* compiler, CLoc loc, shared_ptr<CVar> var) {
    if (function->_data[returnMode].localVarsByName.find(var->name) != function->_data[returnMode].localVarsByName.end()) {
        compiler->addError(loc, CErrorCode::InvalidVariable, "var '%s' already exists within function, must have a unique name", var->name.c_str());
    }
    
    function->_data[returnMode].localVarsByName[var->name] = var;
}

void CScope::popLocalVar(Compiler* compiler, shared_ptr<CVar> var) {
    function->_data[returnMode].localVarsByName.erase(var->name);
}

shared_ptr<CType> CScope::getVarType(CLoc loc, Compiler* compiler, shared_ptr<CTypeName> typeName, CTypeMode defaultMode) {
    if (function) {
        return function->getVarType(loc, compiler, typeName, defaultMode);
    }
    else if (cinterface) {
        return cinterface->getVarType(loc, compiler, typeName, defaultMode);
    }
    else {
        assert(false);
        return nullptr;
    }
}

shared_ptr<CVar> CScope::getCVar(Compiler* compiler, const string& name) {
    if (function) {
        return function->getCVar(compiler, name, returnMode);
    }
    else if (cinterface) {
        return cinterface->getCVar(compiler, name, CTM_Heap);
    }
    else {
        assert(false);
        return nullptr;
    }
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
