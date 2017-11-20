#include "Node.h"

NFunction::NFunction(CLoc& loc, CFunctionType type, shared_ptr<CTypeName> returnTypeName, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<CTypeNameList> interfaceTypeNames, shared_ptr<NodeList> arguments, shared_ptr<NBase> block, shared_ptr<NBase> catchBlock, shared_ptr<NBase> copyBlock, shared_ptr<NBase> destroyBlock) : NBaseFunction(NodeType_Function, loc), type(type), returnTypeName(returnTypeName), name(name), templateTypeNames(templateTypeNames), interfaceTypeNames(interfaceTypeNames), block(block), catchBlock(catchBlock), copyBlock(copyBlock), destroyBlock(destroyBlock) {
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

void NFunction::defineImpl(Compiler *compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> parentFunction) {
    assert(compiler->state == CompilerState::Define);
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments, function definitions, or interface definitions");
        return;
    }
    
    auto thisFunction = getFunctionDefinition(compiler, result, static_pointer_cast<CFunctionDefinition>(parentFunction));
    if (!thisFunction) {
        return;
    }

    parentFunction->addChildFunction(name, thisFunction);

    for (auto it : interfaces) {
        it->define(compiler, result, thisFunction);
    }

    for (auto it : functions) {
        it->define(compiler, result, thisFunction);
    }
        
    for (auto it : assignments) {
        it->define(compiler, result, thisFunction);
    }

    if (block) {
        block->define(compiler, result, thisFunction);
    }
}

shared_ptr<CFunctionDefinition> NFunction::getFunctionDefinition(Compiler *compiler, CResult& result, shared_ptr<CFunctionDefinition> parentFunction) {
    return CFunctionDefinition::create(compiler, result, parentFunction, type, name, interfaceTypeNames, shared_from_this());
}

shared_ptr<CVar> NFunction::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode) {
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return nullptr;
    }

    return nullptr;
}

shared_ptr<CFunction> NFunction::createCFunction(Compiler* compiler, CResult& result, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, CFunctionType type, const string& name, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, shared_ptr<CInterfaceMethod> interfaceMethod, CTypeMode returnMode) {
    auto fun = make_shared<CFunction>(definition, type, templateTypes, parent, interfaces, returnMode);
    return fun->init(compiler, result, shared_from_this(), interfaceMethod);
}

CFunction::CFunction(weak_ptr<CBaseFunctionDefinition> definition, CFunctionType type, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, CTypeMode returnMode) :
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
_isReturnThis(false),
_returnMode(returnMode)
 {}


shared_ptr<CFunction> CFunction::init(Compiler* compiler, CResult& result, shared_ptr<NFunction> node, shared_ptr<CInterfaceMethod> interfaceMethod_) {
    _interfaceMethod = interfaceMethod_;
    
    if (_interfaceMethod) {
        _interfaceMethod->implementations.push_back(shared_from_this());
    }
    
    for (auto it : templateTypes) {
        name = name + "_" + it->name;
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
                    result.addError(loc, CErrorCode::InvalidType, "cannot use ! in template type name");
                    return nullptr;
                }
                templateTypesByName[templateTypeName->name] = templateTypes[index];
                index++;
            }
        }
        
        for (auto it : node->assignments) {
            if (it->var) {
                result.addError(it->loc, CErrorCode::InvalidDot, "cannot use '.' in variable declaration for a function: '%s'", it->name.c_str());
                return nullptr;
            }
            
            int index = (int)argVars.size();
            auto interfaceMethodArgVar = _interfaceMethod ? _interfaceMethod->argVars[index] : nullptr;
            auto calleeVar = getThisVar(compiler, result);            
            auto argType = it->getType(compiler, result, shared_from_this(), calleeVar, CTM_Undefined);
            if (!argType) {
                return nullptr;
            }
            auto thisArgVar = make_shared<CNormalVar>(node->loc, shared_from_this(), argType, it->name, it->op == ASSIGN_Mutable || it->op == ASSIGN_MutableCopy, CVarType::Var_Public);
            _thisArgVarsByName[it->name] = pair<int, shared_ptr<CVar>>(index, thisArgVar);
            _thisArgVars.push_back(thisArgVar);
            argVars.push_back(thisArgVar);
            argDefaultValues.push_back(it->rightSide);
        }
    }
    
    return shared_from_this();
}

void CFunction::transpileDefinition(Compiler* compiler, CResult& result, TrOutput* trOutput) {
    if (!hasThis) {
        // Create function body
        auto functionName = getCInitFunctionName();
        auto functionBody = trOutput->functions.find(functionName);
        if (functionBody == trOutput->functions.end()) {
            auto returnType = getReturnType(compiler, result);
            auto trFunctionBlock = make_shared<TrBlock>();
            trFunctionBlock->parent = nullptr;
            trFunctionBlock->hasThis = false;
            trOutput->functions[functionName] = trFunctionBlock;

            stringstream functionDefinition;
            functionDefinition << "void " << functionName << "(";
            auto isFirstArg = true;
            auto argTypes = getCTypeList(compiler, result);
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

            auto blockVar = _block->getVar(compiler, result, shared_from_this(), getThisVar(compiler, result), _returnMode);
            auto bodyReturnValue = (returnType == compiler->typeVoid) ? trFunctionBlock->createVoidStoreVariable(loc) : trFunctionBlock->createReturnStoreVariable(loc, shared_from_this(), returnType);
            blockVar->transpile(compiler, result, trOutput, trFunctionBlock.get(), nullptr, nullptr, bodyReturnValue);
        }
    }
    else {
        auto thisVar = getThisVar(compiler, result);

        // Create init function body
        auto functionName = getCInitFunctionName();
        auto functionBody = trOutput->functions.find(functionName);
        if (functionBody == trOutput->functions.end()) {
            auto returnType = getReturnType(compiler, result);
            auto trFunctionBlock = make_shared<TrBlock>();
            trFunctionBlock->parent = nullptr;
            trFunctionBlock->hasThis = true;
            trOutput->functions[functionName] = trFunctionBlock;

            auto blockVar = _block->getVar(compiler, result, shared_from_this(), thisVar, returnType->typeMode);
            _isReturnThis = blockVar->getReturnThis();
            auto bodyReturnValue = (returnType != compiler->typeVoid && !_isReturnThis) ? trFunctionBlock->createReturnStoreVariable(loc, shared_from_this(), returnType) : trFunctionBlock->createVoidStoreVariable(loc);
            blockVar->transpile(compiler, result, trOutput, trFunctionBlock.get(), nullptr, make_shared<TrValue>(nullptr, thisVar->getType(compiler, result), "_this"), bodyReturnValue);

            string structName = getCStructName(thisVar->getTypeMode());
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
            auto argTypes = getCTypeList(compiler, result);
            for (auto argType : *argTypes) {
                if (argType.first.compare("_this") == 0)
                    continue;

                hasValues = true;
                stringstream ss;
                ss << argType.second->cname;
                if (argType.second->typeMode == CTM_Stack) {
                    // C requires that inline structs be defined before use
                    argType.second->parent.lock()->transpileDefinition(compiler, result, trOutput);
                }
                ss << " " << argType.first;
                trOutput->structs[stackStructName].push_back(ss.str());
            }

            if (!hasValues) {
                trOutput->structs[stackStructName].push_back("int structsNeedAValue");
            }

            trOutput->structOrder.push_back(stackStructName);
        }

        if (thisVar->getTypeMode() == CTM_Heap) {
            string heapStructName = getCStructName(CTM_Heap);
            if (trOutput->structs.find(heapStructName) == trOutput->structs.end()) {
                trOutput->structs[heapStructName].push_back("int _refCount");

                auto argTypes = getCTypeList(compiler, result);
                for (auto argType : *argTypes) {
                    if (argType.first.compare("_this") == 0)
                        continue;

                    stringstream ss;
                    if (argType.second->typeMode == CTM_Stack) {
                        ss << argType.second->cname;

                        // C requires that inline structs be defined before use
                        argType.second->parent.lock()->transpileDefinition(compiler, result, trOutput);
                    }
                    else if (argType.second->typeMode == CTM_Heap || argType.second->typeMode == CTM_Value) {
                        ss << argType.second->cname;
                    }
                    else {
                        assert(false);
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

            for (auto argVar : argVars) {
                auto argType = argVar->getType(compiler, result);
                TrStoreValue(argVar->loc, shared_from_this(), argType, "_this->" + argVar->name, ASSIGN_ImmutableCopy, true).setValue(compiler, result, trCopyBlock.get(), make_shared<TrValue>(shared_from_this(), argType, "to->" + argVar->name));
            }

            if (_copyBlock) {
                auto copyBlockVar = _copyBlock->getVar(compiler, result, shared_from_this(), thisVar, CTM_Undefined);
                if (copyBlockVar) {
                    copyBlockVar->transpile(compiler, result, trOutput, trCopyBlock.get(), nullptr, make_shared<TrValue>(nullptr, thisVar->getType(compiler, result), "_this"), trCopyBlock->createVoidStoreVariable(loc));
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
                auto destroyBlockVar = _destroyBlock->getVar(compiler, result, shared_from_this(), thisVar, CTM_Undefined);
                if (destroyBlockVar) {
                    destroyBlockVar->transpile(compiler, result, trOutput, trDestroyBlock.get(), nullptr, make_shared<TrValue>(nullptr, thisVar->getType(compiler, result), "_this"), trDestroyBlock->createVoidStoreVariable(loc));
                }
            }

            for (auto argVar : argVars) {
                TrValue(shared_from_this(), argVar->getType(compiler, result), "_this->" + argVar->name).addReleaseToStatements(trDestroyBlock.get());
            }
        }

        // TODO: all of the typemods are wrong for interfaces
        // Create interfaces
        if (interfaces != nullptr) {
            for (auto interfaceVal : *interfaces) {
                interfaceVal->transpileDefinition(compiler, result, trOutput);

                for (auto interfaceMethod : interfaceVal->methods) {
                    auto functionStack = static_pointer_cast<CFunction>(getCFunction(compiler, result, interfaceMethod->name, nullptr, nullptr, CTM_Stack));
                    if (functionStack) {
                        functionStack->transpileDefinition(compiler, result, trOutput);
                    }

                    auto functionHeap = static_pointer_cast<CFunction>(getCFunction(compiler, result, interfaceMethod->name, nullptr, nullptr, CTM_Heap));
                    if (functionHeap) {
                        functionHeap->transpileDefinition(compiler, result, trOutput);
                    }
                }

                // Create explict cast
                auto castFunctionName = interfaceVal->getCCastFunctionName(_returnMode, shared_from_this());
                auto functionBody = trOutput->functions.find(castFunctionName);
                if (functionBody == trOutput->functions.end()) {
                    auto trFunctionBlock = make_shared<TrBlock>();
                    trFunctionBlock->parent = nullptr;
                    trFunctionBlock->hasThis = true;
                    trOutput->functions[castFunctionName] = trFunctionBlock;

                    string structName = getCStructName(thisVar->getTypeMode());
                    auto interfaceType = interfaceVal->getThisTypes(compiler, result)->heapValueType;
                    stringstream functionDefinition;
                    functionDefinition << interfaceType->cname << " " << castFunctionName << "(" << structName << "* _this" << ")";
                    trFunctionBlock->definition = functionDefinition.str();

                    stringstream allocStream;
                    string interfaceStructName = interfaceType->parent.lock()->getCStructName(interfaceType->typeMode);
                    allocStream << interfaceType->cname << " _interface = (" << interfaceType->cname << ")malloc(sizeof(" << interfaceStructName << "))";
                    trFunctionBlock->statements.push_back(allocStream.str());

                    trFunctionBlock->statements.push_back(string("_interface->_refCount = 1"));
                    trFunctionBlock->statements.push_back(string("_interface->_parent = (sjs_object*)_this"));
                    trFunctionBlock->statements.push_back(string("_interface->_parent->_refCount++"));
                    trFunctionBlock->statements.push_back(string("_interface->destroy = (void(*)(void*))" + getCDestroyFunctionName()));
                    trFunctionBlock->statements.push_back(string("_interface->asInterface = (sjs_object*(*)(sjs_object*,int))" + getCAsInterfaceFunctionName()));

                    for (auto interfaceMethod : interfaceVal->methods) {
                        auto functionStack = static_pointer_cast<CFunction>(getCFunction(compiler, result, interfaceMethod->name, nullptr, nullptr, CTM_Stack));
                        if (functionStack) {
                            stringstream initStream;
                            initStream << "_interface->" << interfaceMethod->name << " = (" << interfaceMethod->getCTypeName(compiler, result, false) << ")" << functionStack->getCInitFunctionName();
                            trFunctionBlock->statements.push_back(initStream.str());
                        }

                        auto functionHeap = static_pointer_cast<CFunction>(getCFunction(compiler, result, interfaceMethod->name, nullptr, nullptr, CTM_Stack));
                        if (functionHeap) {
                            stringstream initStream;
                            initStream << "_interface->" << interfaceMethod->name << " = (" << interfaceMethod->getCTypeName(compiler, result, false) << ")" << functionHeap->getCInitFunctionName();
                            trFunctionBlock->statements.push_back(initStream.str());
                        }
                    }

                    trFunctionBlock->statements.push_back(string("return _interface"));
                }
            }

            string asInterfaceFunctionName = getCAsInterfaceFunctionName();
            auto asInterfaceFunctionBody = trOutput->functions.find(asInterfaceFunctionName);
            if (asInterfaceFunctionBody == trOutput->functions.end()) {
                auto trFunctionBlock = make_shared<TrBlock>();
                trFunctionBlock->parent = nullptr;
                trFunctionBlock->hasThis = true;
                trOutput->functions[asInterfaceFunctionName] = trFunctionBlock;

                string structName = getCStructName(thisVar->getTypeMode());
                stringstream functionDefinition;
                functionDefinition << "sjs_object* " << asInterfaceFunctionName << "(" << structName << "* _this, int typeId)";
                trFunctionBlock->definition = functionDefinition.str();

                auto switchBlock = make_shared<TrBlock>();
                trFunctionBlock->statements.push_back(TrStatement("switch (typeId)", switchBlock));
                for (auto interfaceVal : *interfaces) {
                    switchBlock->statements.push_back(string("case ") + interfaceVal->getCTypeIdName() + ": return (sjs_object*)" + interfaceVal->getCCastFunctionName(_returnMode, shared_from_this()) +"(_this)");
                }

                trFunctionBlock->statements.push_back(string("return 0"));
            }
        }
    }
}

void CFunction::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> parentValue, CLoc& calleeLoc, vector<pair<bool, shared_ptr<NBase>>>& parameters, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    assert(compiler->state == CompilerState::Compile);

    auto returnType = getReturnType(compiler, result);
    if (!returnType) {
        return;
    }

    transpileDefinition(compiler, result, trOutput);
    
    if (!hasThis) {
        auto functionName = getCInitFunctionName();
        stringstream line;
        line << functionName << "(";
        bool isFirstParameter = true;

        // Add "parent" to "this"
        auto hasParent = getHasParent(compiler, result);
        shared_ptr<TrValue> dotTrValue;
        if (hasParent) {
            if (isFirstParameter) {
                isFirstParameter = false;
            }
            else {
                line << ", ";
            }
            if (!parentValue) {
                line << trBlock->hasThis ? "_this" : "_parent";
            }
            else {
                line << parentValue->name;
            }
        }

        auto argTypes = getCTypeList(compiler, result);
        auto argIndex = 0;
        // Fill in "this" with normal arguments
        for (auto defaultAssignment : argDefaultValues) {
            auto argVar = argVars[argIndex];
            auto argType = argVar->getType(compiler, result);
            auto isDefaultAssignment = parameters[argIndex].second == defaultAssignment;
            assert(isDefaultAssignment == parameters[argIndex].first);

            stringstream argStream;
            auto parameterVar = parameters[argIndex].second->getVar(compiler, result, isDefaultAssignment ? shared_from_this() : thisFunction, isDefaultAssignment ? nullptr : thisVar, CTM_Undefined);
            if (!parameterVar) {
                assert(result.errors.size() > 0);
                return;
            }
            auto argStoreValue = trBlock->createTempStoreVariable(loc, thisFunction, argType->typeMode == CTM_Heap ? argType : argType->getLocalValueType(), "param");
            parameterVar->transpile(compiler, result, trOutput, trBlock, nullptr, isDefaultAssignment ? nullptr : thisValue, argStoreValue);

            if (!argStoreValue->hasSetValue) {
                result.addError(calleeLoc, CErrorCode::TypeMismatch, "parameter '%s' has no value", argVar->name.c_str());
                return;
            }

            if (isFirstParameter) {
                isFirstParameter = false;
            }
            else {
                line << ", ";
            }
            line << argStoreValue->name;
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
            line << "&" << storeValue->name;
            storeValue->hasSetValue = true;
        }
        line << ")";
        trBlock->statements.push_back(line.str());
    } else {
        auto calleeVar = getThisVar(compiler, result);
        auto functionName = getCInitFunctionName();

        // Initialize "this"
        shared_ptr<TrValue> calleeThisValue;
        if (_isReturnThis && storeValue->type != nullptr) {
            // TODO: need to figure how to handle the various types of assignment
            calleeThisValue = make_shared<TrValue>(storeValue->scope, storeValue->type, storeValue->name);
            calleeThisValue->addInitToStatements(trBlock);
        }
        else {
            calleeThisValue = trBlock->createTempVariable(thisFunction, calleeVar->getType(compiler, result), "object");
            calleeThisValue->addInitToStatements(trBlock);
        }

        if (hasParent) {
            stringstream parentLine;
            if (!parentValue) {
                if (parent.lock() == thisFunction) {
                    parentLine << calleeThisValue->getDotName("_parent") << " = " << thisValue->getDotName("_parent");
                }
                else if (parent.lock() == thisFunction->parent.lock()) {
                    parentLine << calleeThisValue->getDotName("_parent") << " = ";
                    if (thisFunction->hasThis) {
                        parentLine << thisValue->getDotName("_parent") << "->";
                    }
                    else {
                        parentLine << "_parent";
                    }
                }
                else if (parent.lock() == thisFunction->parent.lock()->parent.lock()) {
                    parentLine << calleeThisValue->getDotName("_parent") << " = ";
                    if (thisFunction->hasThis) {
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

        auto argTypes = getCTypeList(compiler, result);
        auto argIndex = 0;
        // Fill in "this" with normal arguments
        for (auto defaultAssignment : argDefaultValues) {
            auto argVar = argVars[argIndex];
            auto argType = argVar->getType(compiler, result);
            auto isDefaultAssignment = parameters[argIndex].second == defaultAssignment;
            assert(isDefaultAssignment == parameters[argIndex].first);

            stringstream argStream;
            auto parameterVar = parameters[argIndex].second->getVar(compiler, result, isDefaultAssignment ? shared_from_this() : thisFunction, isDefaultAssignment ? calleeVar : thisVar, CTM_Undefined);
            if (!parameterVar) {
                assert(result.errors.size() > 0);
                return;
            }

            auto argStoreValue = make_shared<TrStoreValue>(loc, shared_from_this(), argType, calleeThisValue->getDotName(argVar->name), ASSIGN_Immutable, true);
            parameterVar->transpile(compiler, result, trOutput, trBlock, nullptr, isDefaultAssignment ? calleeThisValue : thisValue, argStoreValue);

            if (!argStoreValue->hasSetValue) {
                result.addError(calleeLoc, CErrorCode::TypeMismatch, "parameter '%s' has no value", argVar->name.c_str());
                return;
            }
            argIndex++;
        }

        // Call function
        stringstream line;
        line << functionName << "(" << calleeThisValue->getPointerName();
        if (returnType != compiler->typeVoid && !_isReturnThis) {
            line << ", &" << storeValue->name;
        }
        line << ")";
        trBlock->statements.push_back(line.str());
        storeValue->hasSetValue = true;
    }
}

string CFunction::getCBaseName(CTypeMode typeMode) {
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
    
    switch (typeMode) {
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

string CFunction::getCStructName(CTypeMode typeMode) {
    return string("sjs_") + getCBaseName(typeMode);
}

string CFunction::getCInitFunctionName() {
    return string("sjf_") + getCBaseName(_returnMode);
}

string CFunction::getCCopyFunctionName() {
    return string("sjf_") + getCBaseName(CTM_Stack) + "_copy";
}

string CFunction::getCDestroyFunctionName() {
    return string("sjf_") + getCBaseName(CTM_Stack) + "_destroy";
}

string CFunction::getCAsInterfaceFunctionName() {
    return getCInitFunctionName() + "_asInterface";
}

void CFunction::dumpBody(Compiler* compiler, CResult& result, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << fullName(true);
    if (_interfaceTypeNames) {
        ss << " ";
        for (auto it : *_interfaceTypeNames) {
            if (it != _interfaceTypeNames->front()) {
                ss << ", ";
            }
            ss << "#" << it->getName();
        }
        ss << " ";
    }
    ss << "(";
    
    if (argDefaultValues.size() > 0) {
        for (auto it : argVars) {
            if (it != argVars.front()) {
                ss << ", ";
            }
            ss << it->name;
            auto ctype = it->getType(compiler, result);
            ss << "'" << (ctype != nullptr ? ctype->name : "ERROR");
            ss << (it->isMutable ? "=" : ":");
        }
    }
    
    ss << ")";
    auto returnType = getReturnType(compiler, result);
    ss << "'" << (returnType ? returnType->name : "void");

    if (_block) {
        ss << " ";
        
        stringstream dotSS;
        auto thisVar = getThisVar(compiler, result);
        auto blockVar = _block->getVar(compiler, result, shared_from_this(), thisVar, returnType->typeMode);
        blockVar->dump(compiler, result, nullptr, functions, ss, dotSS, level);
    }
}

shared_ptr<CThisVar> CFunction::getThisVar(Compiler* compiler, CResult& result) {
    if (_hasInitializedInterfaces) {
        _hasInitializedInterfaces = true;
        if (interfaces) {
            // Make all functions used by an interface are defined
            for (auto interface : *interfaces) {
                for (auto interfaceMethod : interface->methods) {
                    auto cfunc = static_pointer_cast<CFunction>(getCFunction(compiler, result, interfaceMethod->name, nullptr, nullptr, interfaceMethod->returnMode));
                    if (!cfunc) {
                        result.addError(loc, CErrorCode::InterfaceMethodDoesNotExist, "cannot find interface method: '%s'", interfaceMethod->name.c_str());
                        return nullptr;
                    }

                    auto functionReturnType = cfunc->getReturnType(compiler, result);
                    auto interfaceMethodReturnType = interfaceMethod->getReturnType(compiler, result);
                    if (functionReturnType != interfaceMethodReturnType) {
                        result.addError(loc, CErrorCode::TypeMismatch, "function return type '%s' does not match interface method return type '%s'", functionReturnType->name.c_str(), interfaceMethodReturnType->name.c_str());
                    }

                    auto functionArgVars = cfunc->argVars;
                    auto interfaceMethodArgVars = interfaceMethod->argVars;
                    if (functionArgVars.size() != interfaceMethodArgVars.size()) {
                        result.addError(loc, CErrorCode::InterfaceMethodTypeMismatch, "function has %d arguments does not match interface method arguments %d", functionArgVars.size(), interfaceMethodArgVars.size());
                    }
                    else {
                        for (auto i = (size_t)0; i < functionArgVars.size(); i++) {
                            auto aType = functionArgVars[i]->getType(compiler, result);
                            auto bType = interfaceMethodArgVars[i]->getType(compiler, result);
                            if (aType != bType) {
                                result.addError(loc, CErrorCode::TypeMismatch, "function parameter %d type '%s' does not match interface method parameter type '%s'", i + 1, aType ? aType->name.c_str() : "Unknown", bType ? bType->name.c_str() : "Unknown");
                            }
                        }
                    }

                    assert(!cfunc->hasThis);
                    cfunc->setHasParent(compiler, result); // All interface methods must take the parent has first pointer even if they don't need it
                }
            }
        }
    }

    if (!_thisVar) {
        auto defaultTypeMode = CTM_Undefined;
        if (_returnTypeName) {
            shared_ptr<CType> valueType = getVarType(loc, compiler, result, _returnTypeName, CTM_Undefined);
            if (!valueType) {
                result.addError(loc, CErrorCode::InvalidType, "explicit type '%s' does not exist", _returnTypeName->name.c_str());
                return nullptr;
            }
            defaultTypeMode = valueType->typeMode;
        }

        auto thisTypes = getThisTypes(compiler, result);
        _thisVar = make_shared<CThisVar>(loc, nullptr, thisTypes, defaultTypeMode);
    }
    return _thisVar;
}

shared_ptr<CType> CFunction::getReturnType(Compiler* compiler, CResult& result) {
    if (_isInGetType) {
        result.addError(loc, CErrorCode::TypeLoop, "while trying to determine type a cycle was detected");
        return nullptr;
    }
    
    _isInGetType = true;    
    if (!_returnType) {
        if (_returnTypeName) {
            shared_ptr<CType> valueType = getVarType(loc, compiler, result, _returnTypeName, CTM_Undefined);
            if (!valueType) {
                result.addError(loc, CErrorCode::InvalidType, "explicit type '%s' does not exist", _returnTypeName->name.c_str());
                _returnType = nullptr;
            }
            _returnType = valueType;
        }
        
        if (_block) {
            auto thisVar = getThisVar(compiler, result);
            auto blockVar = _block->getVar(compiler, result, shared_from_this(), thisVar, _returnType ? _returnType->typeMode : _returnMode);
            auto type = blockVar->getType(compiler, result);
            if (!_returnType) {
                _returnType = type;
            }
        }
        
        if (_returnType == nullptr) {
            _returnType = compiler->typeVoid;
        }
    }
    
    _isInGetType = false;
    return _returnType;
}

shared_ptr<vector<shared_ptr<CVar>>> CFunction::getArgVars(Compiler* compiler, CResult& result, shared_ptr<CThisVar> thisVar) {
    auto args = make_shared<vector<shared_ptr<CVar>>>();
    for (auto it : argDefaultValues) {
        auto var = it->getVar(compiler, result, shared_from_this(), thisVar, CTM_Undefined);
        assert(var);
        args->push_back(var);
    }
    return args;
}

shared_ptr<CTypes> CFunction::getThisTypes(Compiler* compiler, CResult& result) {
    if (!_thisTypes) {
        _thisTypes = CType::create(name.c_str(), shared_from_this());
    }
    return _thisTypes;
}

shared_ptr<vector<pair<string, shared_ptr<CType>>>> CFunction::getCTypeList(Compiler* compiler, CResult& result) {
    if (!_ctypeList) {
        _ctypeList = make_shared<vector<pair<string, shared_ptr<CType>>>>();

        if (hasThis) {
            _indexRefCount = _ctypeList->size();
            _ctypeList->push_back(make_pair("_this", compiler->typePtr));
        }

        if (hasParent) {
            _indexParent = _ctypeList->size();
            auto parentType = parent.lock()->getThisTypes(compiler, result);
            _ctypeList->push_back(make_pair("_parent", parentType->localValueType));
        }

        _indexVars = _ctypeList->size();
        for (auto it : _thisArgVars) {
            auto ctype = it->getType(compiler, result);
            if (!ctype) {
                result.addError(it->loc, CErrorCode::InvalidType, "cannot determine type for '%s'", it->name.c_str());
                return nullptr;
            }
            _ctypeList->push_back(make_pair(it->name, ctype));
        }
    }
    return _ctypeList;
}

bool getTemplateTypes(Compiler* compiler, CResult& result, CLoc& loc, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CBaseFunction> callerFunction, shared_ptr<CTypeNameList> calleeTemplateTypeNames, shared_ptr<CTypeNameList> funcTemplateTypeNames, vector<shared_ptr<CType>>& templateTypes) {
    if (calleeTemplateTypeNames) {
        if (calleeTemplateTypeNames->size() != funcTemplateTypeNames->size()) {
            result.addError(loc, CErrorCode::InvalidTemplateArg, "size does not match");
            return false;
        }
        
        // Map template type string list to type list
        for (auto templateTypeName : *calleeTemplateTypeNames) {
            shared_ptr<CType> ctype = nullptr;
            if (callerFunction) {
                ctype = callerFunction->getVarType(loc, compiler, result, templateTypeName, CTM_Undefined);
            }
            
            if (!ctype) {
                ctype = thisFunction->getVarType(loc, compiler, result, templateTypeName, CTM_Undefined);
                if (!ctype) {
                    result.addError(loc, CErrorCode::TemplateUnspecified, "cannot find template type: '%s'", templateTypeName->name.c_str());
                    return false;
                }
            }
            
            templateTypes.push_back(ctype);
        }
    } else {
        if (funcTemplateTypeNames != nullptr) {
            result.addError(loc, CErrorCode::InvalidTemplateArg, "size does not match");
            return false;
        }
    }
    return true;
}


shared_ptr<CBaseFunction> CFunction::getCFunction(Compiler* compiler, CResult& result, const string& name, shared_ptr<CBaseFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames, CTypeMode returnMode) {
    auto def = static_pointer_cast<CFunctionDefinition>(definition.lock());
    auto t = def->funcsByName.find(name);
    if (t != def->funcsByName.end()) {
        auto funcDef = t->second;
        
        vector<shared_ptr<CType>> templateTypes;
        if (!getTemplateTypes(compiler, result, loc, shared_from_this(), callerFunction, templateTypeNames, funcDef->node->templateTypeNames, templateTypes)) {
            return nullptr;
        }
        
        return funcDef->getFunction(compiler, result, loc, templateTypes, shared_from_this(), returnMode);
    }
    return nullptr;
}

shared_ptr<CInterface> CFunction::getCInterface(Compiler* compiler, CResult& result, const string& name, shared_ptr<CBaseFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames, CTypeMode returnMode) {
    assert(name[0] == '#');

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
                return cfunc->getCInterface(compiler, result, "#" + name, callerFunction, templateTypeNames, returnMode);
            }
            else {
                auto var = cfunc->getCVar(compiler, result, name);
                if (!var) {
                    return nullptr;
                }
                auto ctype = var->getType(compiler, result);
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
            assert(false);
            return nullptr;
        }
        
        vector<shared_ptr<CType>> templateTypes;
        if (!getTemplateTypes(compiler, result, loc, shared_from_this(), callerFunction, templateTypeNames, interfaceDef->ninterface->templateTypeNames, templateTypes)) {
            return nullptr;
        }
        
        return interfaceDef->getInterface(compiler, result, templateTypes, shared_from_this(), returnMode);

        return nullptr;
    }
}

shared_ptr<CVar> CFunction::getCVar(Compiler* compiler, CResult& result, const string& name) {
    auto t1 = localVarsByName.find(name);
    if (t1 != localVarsByName.end()) {
        return t1->second;
    }
    
    auto t2 = _thisArgVarsByName.find(name);
    if (t2 != _thisArgVarsByName.end()) {
        return t2->second.second;
    }
    
    return nullptr;
}

int CFunction::getThisIndex(const string& name) const {
    auto it = _thisArgVarsByName.find(name);
    if (it != _thisArgVarsByName.end()) {
        return it->second.first;
    }
    return -1;
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
            
            ss << it->name;
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

int CFunction::getArgStart(Compiler* compiler, CResult& result) {
    getThisTypes(compiler, result);
    return (int)_indexVars;
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

shared_ptr<CType> CFunction::getVarType(Compiler* compiler, CResult& result, string name) {
    auto t = templateTypesByName.find(name);
    if (t != templateTypesByName.end()) {
        return t->second;
    }

    if (!parent.expired()) {
        return static_pointer_cast<CFunction>(parent.lock())->getVarType(compiler, result, name);
    }
    
    return compiler->getType(name);
}

shared_ptr<CType> CFunction::getVarType(CLoc& loc, Compiler* compiler, CResult& result, shared_ptr<CTypeName> typeName, CTypeMode defaultMode) {
    auto typeMode = defaultMode;
    if (typeName->typeMode != CTM_Undefined) {
        typeMode = typeName->typeMode;
    }

    if (typeName->category == CTC_Interface) {
        auto nameWithoutQuestion = typeName->isOption ? typeName->name.substr(0, typeName->name.size() - 1) : typeName->name;
        auto interface = getCInterface(compiler, result, nameWithoutQuestion, nullptr, typeName->templateTypeNames, typeName->typeMode);
        if (interface) {
            auto thisTypes = interface->getThisTypes(compiler, result);
            switch (typeMode) {
                case CTM_Heap:
                    return typeName->isOption ? thisTypes->heapOptionType : thisTypes->heapValueType;
                case CTM_Stack:
                    if (typeName->isOption) {
                        result.addError(loc, CErrorCode::InvalidType, "option type cannot be stack, stack x? is invalid use heap x?");
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
    } else {
        assert(typeName->category == CTC_Value);
        if (typeName->templateTypeNames == nullptr) {
            auto ctype = getVarType(compiler, result, typeName->name);
            if (ctype) {
                return ctype;
            }
        }
        
        auto nameWithoutQuestion = typeName->isOption ? typeName->name.substr(0, typeName->name.size() - 1) : typeName->name;
        auto baseFunctionDefinition = getFunctionDefinition(nameWithoutQuestion);
        if (baseFunctionDefinition.second != nullptr) {
            auto templateTypes = vector<shared_ptr<CType>>();
            if (typeName->templateTypeNames) {
                for (auto it : *typeName->templateTypeNames) {
                    auto t = getVarType(loc, compiler, result, it, CTM_Undefined);
                    if (!t) {
                        return nullptr;
                    }
                    templateTypes.push_back(t);
                }
            }
            
            auto functionDefinition = static_pointer_cast<CFunctionDefinition>(baseFunctionDefinition.second);
            auto cfunc = functionDefinition->getFunction(compiler, result, loc, templateTypes, baseFunctionDefinition.first, typeName->typeMode);
            if (!cfunc) {
                return nullptr;
            }
            auto thisTypes = cfunc->getThisTypes(compiler, result);
            switch (typeMode) {
                case CTM_Heap:
                    return typeName->isOption ? thisTypes->heapOptionType : thisTypes->heapValueType;
                case CTM_Stack:
                    if (typeName->isOption) {
                        result.addError(loc, CErrorCode::InvalidType, "option type cannot be stack, stack x? is invalid use heap x?");
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

shared_ptr<CFunctionDefinition> CFunctionDefinition::create(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> parent, CFunctionType type, const string& name, shared_ptr<CTypeNameList> implementedInterfaceTypeNames, shared_ptr<NFunction> node) {
    auto c = make_shared<CFunctionDefinition>();
    c->parent = parent;
    c->type = type;
    c->name = name;
    c->implementedInterfaceTypeNames = implementedInterfaceTypeNames;
    c->node = node;
    
    if (node) {
        for (auto it : node->interfaces) {
            it->define(compiler, result, c);
        }

        for (auto it : node->functions) {
            c->funcsByName[it->name] = it->getFunctionDefinition(compiler, result, c);
        }
        
        for (auto it : node->assignments) {
            if (it->var) {
                result.addError(it->loc, CErrorCode::InvalidDot, "cannot use '.' in variable declaration for a function: '%s'", it->name.c_str());
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

shared_ptr<CFunction> CFunctionDefinition::getFunction(Compiler* compiler, CResult& result, CLoc& loc, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CFunction> funcParent, CTypeMode returnMode) {
    if (returnMode == CTM_Local || returnMode == CTM_Undefined) {
        returnMode = CTM_Stack;
    }
    assert(returnMode == CTM_Stack || returnMode == CTM_Heap);
    shared_ptr<CFunction> func;
    auto funcParentPtr = funcParent.lock().get();
    auto it = _cfunctions[returnMode][funcParentPtr].find(templateTypes);
    if (it != _cfunctions[returnMode][funcParentPtr].end()) {
        func = it->second;
        assert(func->parent.lock() == funcParent.lock());
    } else {
        assert(funcParent.expired() || funcParent.lock()->definition.lock() == parent.lock());
        
        shared_ptr<vector<shared_ptr<CInterface>>> interfaces;
        if (getImplementedInterfaceDefintions(compiler, result)) {
            interfaces = make_shared<vector<shared_ptr<CInterface>>>();
        }
        
        shared_ptr<CInterfaceMethod> interfaceMethod;
        if (!funcParent.expired()) {
            if (funcParent.lock()->interfaces) {
                for (auto it : *funcParent.lock()->interfaces) {
                    auto t = it->methodByName.find(name);
                    if (t != it->methodByName.end()) {
                        if (interfaceMethod) {
                            result.addError(loc, CErrorCode::InterfaceMethodConflict, "two interfaces on this class want to use method: '%s'", name.c_str());
                            return nullptr;
                        }
                        interfaceMethod = t->second;
                    }
                }
            }
        }
        
        func = node->createCFunction(compiler, result, shared_from_this(), templateTypes, funcParent, type, name, interfaces, interfaceMethod, returnMode);
        if (func == nullptr) {
            return nullptr;
        }

        if (getImplementedInterfaceDefintions(compiler, result)) {
            for (auto it : *getImplementedInterfaceDefintions(compiler, result)) {
                vector<shared_ptr<CType>> interfaceTemplateTypes;
                if (!it.first->ninterface) {
                    result.addError(loc, CErrorCode::InterfaceDoesNotExist, "cannot find interface '%s'", it.first->name.c_str());
                    return nullptr;
                }
                
                if (it.first->ninterface->templateTypeNames) {
                    if (!getTemplateTypes(compiler, result, loc, func, nullptr, it.second, it.first->ninterface->templateTypeNames, interfaceTemplateTypes)) {
                        result.addError(loc, CErrorCode::InterfaceDoesNotExist, "cannot find interface '%s'", it.first->name.c_str());
                        return nullptr;
                    }
                }
                
                auto interface = it.first->getInterface(compiler, result, interfaceTemplateTypes, funcParent, returnMode);
                if (!interface) {
                    result.addError(loc, CErrorCode::InterfaceDoesNotExist, "cannot find interface '%s'", it.first->name.c_str());
                    return nullptr;
                }
                interfaces->push_back(interface);
            }
        }
        
        _cfunctions[returnMode][funcParentPtr][templateTypes] = func;
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

shared_ptr<CInterfaceDefinition> CFunctionDefinition::createDefinedInterfaceDefinition(CLoc& loc, string& name) {
    auto result = make_shared<CInterfaceDefinition>(loc, name);
    _definedInterfaceDefinitions[name] = result;
    return result;
}

shared_ptr<vector<pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>>> CFunctionDefinition::getImplementedInterfaceDefintions(Compiler* compiler, CResult& result) {
    if (!_implementedInterfaceDefinitions) {
        if (implementedInterfaceTypeNames) {
            _implementedInterfaceDefinitions = make_shared<vector<pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>>>();
            for (auto it : *implementedInterfaceTypeNames) {
                auto interface = getDefinedInterfaceDefinition(it->name);
                if (interface == nullptr) {
                    result.addError(loc, CErrorCode::InterfaceDoesNotExist, "cannot find interface '%s'", it->name.c_str());
                    return nullptr;
                }
                _implementedInterfaceDefinitions->push_back(pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>(interface, it->templateTypeNames));
            }
        }
    }
    return _implementedInterfaceDefinitions;
}

void CFunctionDefinition::dump(Compiler* compiler, CResult& result, int level) {
    // Skip if this is the function around global
    if (funcsByName.size() > 0) {
        for (auto it : funcsByName) {
            it.second->dump(compiler, result, level);
        }
    }
}
