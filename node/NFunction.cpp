#include "Node.h"

NFunction::NFunction(CLoc loc, CFunctionType type, shared_ptr<CTypeName> returnTypeName, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<CTypeNameList> interfaceTypeNames, shared_ptr<NodeList> arguments, shared_ptr<NBase> block, shared_ptr<NBase> catchBlock, shared_ptr<NBase> destroyBlock) : NBaseFunction(NodeType_Function, loc), type(type), returnTypeName(returnTypeName), name(name), templateTypeNames(templateTypeNames), interfaceTypeNames(interfaceTypeNames), block(block), catchBlock(catchBlock), destroyBlock(destroyBlock) {
    if (this->name == "^") {
        this->name = TrBlock::nextVarName("anon");
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

shared_ptr<CVar> NFunction::getVarImpl(Compiler *compiler, CResult& result, shared_ptr<CBaseFunction> parentFunction, shared_ptr<CVar> parentVar) {
    return nullptr;
}

shared_ptr<CType> NFunction::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> parentFunction, shared_ptr<CVar> parentVar) {
    assert(compiler->state >= CompilerState::FixVar);
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return nullptr;
    }
    
    return compiler->typeVoid;
}

shared_ptr<ReturnValue> NFunction::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, const char* thisName) {
	return nullptr;
}

//shared_ptr<ReturnValue> NFunction::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> parentFunction, shared_ptr<CVar> parentVar, Value* parentValue, IRBuilder<>* builder, BasicBlock* parentCatchBB, ReturnRefType returnRefType) {
//    return nullptr;
//}

shared_ptr<CFunction> NFunction::createCFunction(Compiler* compiler, CResult& result, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, CFunctionType type, const string& name, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, shared_ptr<CInterfaceMethod> interfaceMethod) {
    auto fun = make_shared<CFunction>(definition, type, templateTypes, parent, interfaces);
    return fun->init(compiler, result, shared_from_this(), interfaceMethod);
}

CFunction::CFunction(weak_ptr<CBaseFunctionDefinition> definition, CFunctionType type, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces) :
CBaseFunction(CFT_Function, definition.lock()->name, parent, definition),
loc(CLoc::undefined),
type(type),
templateTypes(templateTypes),
interfaces(interfaces),
isInGetType(false),
returnMustRelease(false),
block(nullptr),
catchBlock(nullptr),
destroyBlock(nullptr),
returnTypeName(nullptr),
interfaceTypeNames(nullptr),
_hasInitializedInterfaces(false)
 {}


shared_ptr<CFunction> CFunction::init(Compiler* compiler, CResult& result, shared_ptr<NFunction> node, shared_ptr<CInterfaceMethod> interfaceMethod_) {
    interfaceMethod = interfaceMethod_;
    
    if (interfaceMethod) {
        interfaceMethod->implementations.push_back(shared_from_this());
    }
    
    for (auto it : templateTypes) {
        name = name + "_" + it->name;
    }
    
    if (node) {
        loc = node->loc;
        functions = node->functions;
        block = node->block;
        catchBlock = node->catchBlock;
        destroyBlock = node->destroyBlock;
        returnTypeName = node->returnTypeName;
        interfaceTypeNames = node->interfaceTypeNames;
        
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
            auto interfaceMethodArgVar = interfaceMethod ? interfaceMethod->argVars[index] : nullptr;
            auto thisVar = CNormalVar::createFunctionVar(node->loc, it->name, shared_from_this(), index, it, nullptr, interfaceMethodArgVar);
            thisVarsByName[it->name] = pair<int, shared_ptr<CVar>>(index, thisVar);
            thisVars.push_back(thisVar);
            argVars.push_back(thisVar);
            argDefaultValues.push_back(it->rightSide);
        }
    }
    
    return shared_from_this();
}

void CFunction::getVarBody(Compiler *compiler, CResult& result, shared_ptr<CVar> thisVar, CTypeReturnMode returnMode) {
    assert(compiler->state == CompilerState::FixVar);   
    for (auto it : functions) {
        it->getVar(compiler, result, shared_from_this(), thisVar, CTRM_NoPref);
    }

    for (auto it : argDefaultValues) {
        if (it) {
            it->getVar(compiler, result, shared_from_this(), thisVar, returnMode);
        }
    }
    
    if (block) {
        block->getVar(compiler, result, shared_from_this(), thisVar, returnMode);
    }
    
    if (catchBlock) {
        catchBlock->getVar(compiler, result, shared_from_this(), thisVar, returnMode);
    }
    
    if (destroyBlock) {
        destroyBlock->getVar(compiler, result, shared_from_this(), thisVar, CTRM_NoPref);
    }
    
    getReturnType(compiler, result, returnMode);
}

void CFunction::transpileDefinition(Compiler* compiler, CResult& result, TrOutput* trOutput, CTypeReturnMode typeReturnMode) {
    auto vars = getReturnVar(compiler, result, thisVar, typeReturnMode);
    auto returnVar = vars.first;
    auto thisVar = vars.second;
    auto returnType = returnVar->getType(compiler, result);
    auto functionName = getCInitFunctionName(returnType->typeMode);

    if (!getHasThis()) {
        auto functionName = getCInitFunctionName(returnType->typeMode);

        // Create function body
        auto functionBody = trOutput->functions.find(functionName);
        if (functionBody == trOutput->functions.end()) {
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
                functionDefinition << argType.second->nameRef << " " << argType.first;
            }

            if (returnType != compiler->typeVoid) {
                if (isFirstArg) {
                    isFirstArg = false;
                }
                else {
                    functionDefinition << ", ";
                }
                functionDefinition << returnType->nameRef << "* _return";
            }

            if (isFirstArg) {
                functionDefinition << "void";
            }
            functionDefinition << ")";
            trFunctionBlock->definition = functionDefinition.str();

            auto bodyReturnValue = block->transpile(compiler, result, shared_from_this(), nullptr, trOutput, trFunctionBlock.get(), typeReturnMode, nullptr);
            if (bodyReturnValue && bodyReturnValue->type != compiler->typeVoid) {
                assert(bodyReturnValue->type == returnType);
                /* TODO: if (bodyReturnValue->release == RVR_MustRetain && !bodyReturnValue->type->parent.expired()) {
                    ReturnValue::addRetainToStatements(trFunctionBlock.get(), bodyReturnValue->name, bodyReturnValue->type);
                }*/
                trFunctionBlock->returnLine = bodyReturnValue->name;
            }
        }
    }
    else {
        auto thisVar = getThisVar(compiler, result);

        // Create struct
        string structName = getStructName(typeMode);
        if (trOutput->structs.find(structName) == trOutput->structs.end()) {
            trOutput->structs[structName].push_back("int _refCount");

            auto argTypes = getCTypeList(compiler, result);
            for (auto argType : *argTypes) {
                if (argType.first.compare("_this") == 0)
                    continue;

                stringstream ss;
                ss << argType.second->nameRef << " " << argType.first;
                trOutput->structs[structName].push_back(ss.str());
            }
        }

        // Create init function body
        auto functionBody = trOutput->functions.find(functionName);
        if (functionBody == trOutput->functions.end()) {
            auto trFunctionBlock = make_shared<TrBlock>();
            trFunctionBlock->parent = nullptr;
            trFunctionBlock->hasThis = true;
            trOutput->functions[functionName] = trFunctionBlock;

            stringstream functionDefinition;
            functionDefinition << "void " << functionName << "(" << structName << "* _this";
            if (returnType != compiler->typeVoid) {
                functionDefinition << ", " << returnType->nameRef << "* _return";
            }
            functionDefinition << ")";
            trFunctionBlock->definition = functionDefinition.str();

            auto thisVar = getThisVar(compiler, result, typeMode);
            auto bodyReturnValue = block->transpile(compiler, result, shared_from_this(), thisVar, trOutput, trFunctionBlock.get(), true, "_this");
            if (bodyReturnValue && bodyReturnValue->type && bodyReturnValue->type != compiler->typeVoid) {
                assert(bodyReturnValue->type == returnType);
                /* TODO: if (bodyReturnValue->release == RVR_MustRetain && !bodyReturnValue->type->parent.expired()) {
                    ReturnValue::addRetainToStatements(trFunctionBlock.get(), bodyReturnValue->name, bodyReturnValue->type);
                }*/

                trFunctionBlock->returnLine = bodyReturnValue->name;
            }
        }

        // Create destroy function body
        string functionDestroyName = getCDestroyFunctionName(typeMode);
        if (trOutput->functions.find(functionDestroyName) == trOutput->functions.end()) {
            auto trDestroyBlock = make_shared<TrBlock>();
            trDestroyBlock->parent = nullptr;
            trDestroyBlock->hasThis = true;
            trOutput->functions[functionDestroyName] = trDestroyBlock;

            stringstream functionDefinition;
            functionDefinition << "void " << functionDestroyName << "(" << structName << "* _this)";
            trDestroyBlock->definition = functionDefinition.str();

            if (destroyBlock) {
                auto thisVar = getThisVar(compiler, result, typeMode);
                destroyBlock->transpile(compiler, result, shared_from_this(), thisVar, trOutput, trDestroyBlock.get(), false, "_this");
            }

            for (auto argVar : argVars) {
                auto argFunction = argVar->getCFunctionForValue(compiler, result);
                if (argFunction) {
                    assert(false);
//                    ReturnValue::addReleaseToStatements(trDestroyBlock.get(), "_this->" + argVar->name, argVar->getType(compiler, result));
//                    if (argHeapVar) {
//                    }
//                    else {
//                        stringstream destroyStream;
//                        destroyStream << argFunction->getCDestroyFunctionName() << "(" << "_this->" << argVar->name << ")";
//                        trDestroyBlock->statements.push_back(destroyStream.str());
//                    }
                }
            }
        }

        // Create interfaces
        if (interfaces != nullptr) {
            for (auto interfaceVal : *interfaces) {
                interfaceVal->transpileDefinition(compiler, result, trOutput, typeMode);

                for (auto interfaceMethod : interfaceVal->methods) {
                    auto function = getCFunction(compiler, result, interfaceMethod->name, nullptr, nullptr);
                    if (function) {
                        function->transpileDefinition(compiler, result, trOutput);
                    }
                }

                // Create explict cast
                auto castFunctionName = interfaceVal->getCastFunctionName(typeMode, shared_from_this(), typeMode);
                auto functionBody = trOutput->functions.find(castFunctionName);
                if (functionBody == trOutput->functions.end()) {
                    auto trFunctionBlock = make_shared<TrBlock>();
                    trFunctionBlock->parent = nullptr;
                    trFunctionBlock->hasThis = true;
                    trOutput->functions[castFunctionName] = trFunctionBlock;

                    auto interfaceType = interfaceVal->getThisTypes(compiler, result)->heapValueType;
                    stringstream functionDefinition;
                    functionDefinition << interfaceType->nameRef << " " << castFunctionName << "(" << structName << "* _this" << ")";
                    trFunctionBlock->definition = functionDefinition.str();

                    stringstream allocStream;
                    allocStream << interfaceType->nameRef << " _interface = (" << interfaceType->nameRef << ")malloc(sizeof(" << interfaceType->nameValue << "))";
                    trFunctionBlock->statements.push_back(allocStream.str());

                    trFunctionBlock->statements.push_back(string("_interface->_refCount = 1"));
                    trFunctionBlock->statements.push_back(string("_interface->_parent = (sjs_object*)_this"));
                    trFunctionBlock->statements.push_back(string("_interface->_parent->_refCount++"));
                    trFunctionBlock->statements.push_back(string("_interface->destroy = (void(*)(sjs_object*))" + getCDestroyFunctionName(typeMode)));
                    trFunctionBlock->statements.push_back(string("_interface->asInterface = (sjs_object*(*)(sjs_object*,int))" + getCAsInterfaceFunctionName(typeMode)));

                    for (auto interfaceMethod : interfaceVal->methods) {
                        auto function = getCFunction(compiler, result, interfaceMethod->name, nullptr, nullptr);
                        if (function) {
                            stringstream initStream;
                            initStream << "_interface->" << interfaceMethod->name << " = (" << interfaceMethod->getCTypeName(compiler, result, false) << ")" << function->getCInitFunctionName(typeMode);
                            trFunctionBlock->statements.push_back(initStream.str());
                        }
                    }

                    trFunctionBlock->statements.push_back(string("return _interface"));
                }
            }

            string asInterfaceFunctionName = getCAsInterfaceFunctionName(typeMode);
            auto asInterfaceFunctionBody = trOutput->functions.find(asInterfaceFunctionName);
            if (asInterfaceFunctionBody == trOutput->functions.end()) {
                auto trFunctionBlock = make_shared<TrBlock>();
                trFunctionBlock->parent = nullptr;
                trFunctionBlock->hasThis = true;
                trOutput->functions[asInterfaceFunctionName] = trFunctionBlock;

                stringstream functionDefinition;
                functionDefinition << "sjs_object* " << asInterfaceFunctionName << "(" << structName << "* _this, int typeId)";
                trFunctionBlock->definition = functionDefinition.str();

                auto switchBlock = make_shared<TrBlock>();
                trFunctionBlock->statements.push_back(TrStatement("switch (typeId)", switchBlock));
                for (auto interfaceVal : *interfaces) {
                    switchBlock->statements.push_back(string("case ") + interfaceVal->getTypeIdName(typeMode) + ": return (sjs_object*)" + interfaceVal->getCastFunctionName(typeMode, shared_from_this(), typeMode) +"(_this)");
                }

                trFunctionBlock->statements.push_back(string("return 0"));
            }
        }
    }
}

shared_ptr<ReturnValue> CFunction::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, shared_ptr<ReturnValue> calleeValue, shared_ptr<CVar> calleeVar, CLoc& calleeLoc, vector<pair<bool, shared_ptr<NBase>>>& parameters, const char* thisName, CTypeMode typeMode) {
    assert(compiler->state == CompilerState::Compile);
    auto returnType = getReturnType(compiler, result, thisVar);
    if (!returnType) {
        return nullptr;
    }

    CTypeReturnMode returnModeThis = false;
    shared_ptr<ReturnValue> returnValue;
    if (returnType != compiler->typeVoid) {
        auto returnVar = block->getVar(compiler, result, shared_from_this(), calleeVar);
        if (returnVar == calleeVar) {
            isReturnValueThis = true;
        } else {
            assert(false);
//            if (returnVar == nullptr || returnVar->getHeapVar(compiler, result, calleeVar)) {
//                returnValue = trBlock->createTempVariable("result", returnType, true, RVR_MustRelease);
//                stringstream initReturnStream;
//                initReturnStream << returnValue->name << " = 0";
//                trBlock->statements.push_back(initReturnStream.str());
//            }
//            else if (!returnType->parent.expired()) {
//                returnValue = trBlock->createTempVariable("result", returnType, true, RVR_MustRelease);
//                stringstream initReturnStream;
//                initReturnStream << returnValue->name << " = 0";
//                trBlock->statements.push_back(initReturnStream.str());
//            }
//            else {
//                returnValue = trBlock->createTempVariable("result", returnType, true, RVR_MustRelease);
//            }
        }
    }

    auto functionName = getCInitFunctionName(typeMode);
    string calleeThisName = "INVALID";
    transpileDefinition(compiler, result, trOutput, typeMode);
    vector<ArgData> argValues;

    if (!getHasThis()) {
        // Add "parent" to "this"
        auto hasParent = getHasParent(compiler, result);
        shared_ptr<ReturnValue> dotReturnValue;
        if (hasParent) {
            if (!calleeValue) {
                argValues.insert(argValues.begin(), ArgData(nullptr, trBlock->hasThis ? "_this" : "_parent"));
            }
            else {
                argValues.insert(argValues.begin(), ArgData(nullptr, calleeValue));
            }
        }
    } else {
        string structName = getStructName(typeMode);
        assert(false);
        // Initialize "this"
        shared_ptr<ReturnValue> objectRef;
//        if (objectHeapVar) {
//            objectRef = trBlock->createTempVariable("sjv_temp", thisType);
//            stringstream initLine;
//            initLine << objectRef->name << " = (" << structName << "*)malloc(sizeof(" << structName << "))";
//            trBlock->statements.push_back(TrStatement(initLine.str()));
//        } else {
//            if (isReturnValue) {
//                objectRef = trBlock->createTempVariable("sjv_temp", thisType);
//                stringstream initLine;
//                initLine << objectRef->name << " = (*_return != 0) ? *_return : (" << structName << "*)malloc(sizeof(" << structName << "))";
//                trBlock->statements.push_back(TrStatement(initLine.str()));
//            }
//            else {
//                objectRef = trBlock->createTempVariable("sjv_temp", thisType);
//                auto objectVal = trBlock->createStackValue("sjd_temp", thisType);
//                stringstream initLine;
//                initLine << objectRef->name << " = &" << objectVal;
//                trBlock->statements.push_back(TrStatement(initLine.str()));
//            }
//        }
        
        calleeThisName = objectRef->name;
        
        if (hasParent) {
            stringstream parentLine;
            if (!calleeValue) {
                if (parent.lock() == thisFunction) {
                    parentLine << calleeThisName << "->_parent = " << thisName;
                }
                else if (parent.lock() == thisFunction->parent.lock()) {
                    parentLine << calleeThisName << "->_parent = ";
                    if (thisFunction->getHasThis()) {
                        parentLine << thisName << "->";
                    }
                    parentLine << "_parent";
                }
                else if (parent.lock() == thisFunction->parent.lock()->parent.lock()) {
                    parentLine << calleeThisName << "->_parent = ";
                    if (thisFunction->getHasThis()) {
                        parentLine << thisName << "->";
                    }
                    parentLine << "_parent->_parent";
                }
                else {
                    assert(false);
                }
            }
            else {
                parentLine << calleeThisName << "->_parent = " << calleeValue->name;
            }
            trBlock->statements.push_back(parentLine.str());
        }

        if (isReturnValueThis) {
            returnValue = objectRef;
        }
        
        objectRef->addInitToStatements(trBlock);
    }

    auto argTypes = getCTypeList(compiler, result);
    auto argIndex = 0;
    // Fill in "this" with normal arguments
    for (auto defaultAssignment : argDefaultValues) {
        auto argVar = argVars[argIndex];
        auto argType = argVar->getType(compiler, result);
        auto isDefaultAssignment = parameters[argIndex].second == defaultAssignment;
        assert(isDefaultAssignment == parameters[argIndex].first);
        shared_ptr<ReturnValue> argReturnValue;
        
        stringstream argStream;
        auto paramVar = parameters[argIndex].second->getVar(compiler, result, isDefaultAssignment ? shared_from_this() : thisFunction, isDefaultAssignment ? calleeVar : thisVar);
        argReturnValue = parameters[argIndex].second->transpile(compiler, result, isDefaultAssignment ? shared_from_this() : thisFunction, isDefaultAssignment ? calleeVar : thisVar, trOutput, trBlock, false, isDefaultAssignment ? calleeThisName.c_str() : thisName);
        
        if (argReturnValue == nullptr) {
            result.addError(calleeLoc, CErrorCode::TypeMismatch, "parameter '%s' has no value", argVar->name.c_str());
            return nullptr;
        }
        
        if (argType == nullptr) {
            result.addError(calleeLoc, CErrorCode::TypeMismatch, "parameter '%s' type is undefined", argVar->name.c_str());
            return nullptr;
        }
        
        if (argReturnValue->type != argType) {
            result.addError(calleeLoc, CErrorCode::TypeMismatch, "parameter '%s' type '%s' does not match '%s'", argVar->name.c_str(), argReturnValue->type->name.c_str(), argType->name.c_str());
            return nullptr;
        }
        
        argValues.push_back(ArgData(argVar, argReturnValue));
        argIndex++;
    }
    
    if (!getHasThis()) {
        // Call function
        stringstream line;
        line << functionName << "(";
        bool isFirstParameter = true;
        for (auto argValue : argValues) {
            if (isFirstParameter) {
                isFirstParameter = false;
            } else {
                line << ", ";
            }
            
            line << argValue.name;
        }
        if (returnValue) {
            if (isFirstParameter) {
                isFirstParameter = false;
            } else {
                line << ", ";
            }
            line << "&" << returnValue->name;
        }
        line << ")";
        trBlock->statements.push_back(line.str());
    } else {
        for (auto argValue : argValues) {
            stringstream argAssignLine;
            argAssignLine << calleeThisName << "->" << argValue.var->name << " = " << argValue.name;
            trBlock->statements.push_back(TrStatement(argAssignLine.str()));
            assert(false);
//            if (argValue.value->release == RVR_MustRetain && !argValue.value->type->parent.expired()) {
//                ReturnValue::addRetainToStatements(trBlock, calleeThisName + "->" + argValue.var->name, argValue.value->type);
//            }
        }

        // Call function
        stringstream line;
        line << functionName << "(" << calleeThisName;
        if (returnValue) {
            line << ", &" << returnValue->name;
        }
        line << ")";
        trBlock->statements.push_back(line.str());
    }    

    return returnValue;
}

string CFunction::getBaseName(CTypeMode typeMode) {
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
    
    if (typeMode == CTM_Stack) {
        
    }
    else if (typeMode == CTM_Heap) {
        functionName += "_heap";
    }
    else {
        assert(false);
    }
    
    return functionName;
}

string CFunction::getStructName(CTypeMode typeMode) {
    return string("sjs_") + getBaseName(typeMode);
}

string CFunction::getCInitFunctionName(CTypeMode typeMode) {
    return string("sjf_") + getBaseName(typeMode);
}

string CFunction::getCDestroyFunctionName(CTypeMode typeMode) {
    return getCInitFunctionName(typeMode) + "_destroy";
}

string CFunction::getCAsInterfaceFunctionName(CTypeMode typeMode) {
    return getCInitFunctionName(typeMode) + "_asInterface";
}

void CFunction::dumpBody(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << fullName(true);
    if (interfaceTypeNames) {
        ss << " ";
        for (auto it : *interfaceTypeNames) {
            if (it != interfaceTypeNames->front()) {
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
    auto returnType = getReturnType(compiler, result, thisVar);
    ss << "'" << (returnType ? returnType->name : "void");

    if (block) {
        ss << " ";
        block->dump(compiler, result, shared_from_this(), thisVar, functions, ss, level);
    }
}

shared_ptr<CVar> CFunction::getThisVar(Compiler* compiler, CResult& result, CTypeMode typeMode) {
    if (!_thisVar) {
        assert(false); // TODO: get either stack or heap thisvar
        _thisVar = CNormalVar::createThisVar(loc, shared_from_this(), getThisTypes(compiler, result)->heapValueType);
        getVarBody(compiler, result, _thisVar);

        if (_hasInitializedInterfaces) {
            _hasInitializedInterfaces = true;
            if (interfaces) {
                // Make all functions used by an interface are defined
                for (auto interface : *interfaces) {
                    for (auto interfaceMethod : interface->methods) {
                        auto cfunc = static_pointer_cast<CFunction>(getCFunction(compiler, result, interfaceMethod->name, nullptr, nullptr));
                        if (!cfunc) {
                            result.addError(loc, CErrorCode::InterfaceMethodDoesNotExist, "cannot find interface method: '%s'", interfaceMethod->name.c_str());
                            return nullptr;
                        }

                        auto functionReturnType = cfunc->getReturnType(compiler, result, cfunc->getThisVar(compiler, result, typeMode));
                        auto interfaceMethodReturnType = interfaceMethod->getReturnType(compiler, result, nullptr);
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

                        assert(!cfunc->getHasThis());
                        cfunc->setHasParent(compiler, result); // All interface methods must take the parent has first pointer even if they don't need it
                        cfunc->getVarBody(compiler, result, nullptr);
                    }
                }
            }
        }
    }
    return _thisVar;
}

shared_ptr<CType> CFunction::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    if (isInGetType) {
        result.addError(loc, CErrorCode::TypeLoop, "while trying to determine type a cycle was detected");
        return nullptr;
    }
    
    isInGetType = true;
    
    if (!returnType) {
        assert(compiler->state >= CompilerState::FixVar);
        
        if (returnTypeName) {
            shared_ptr<CType> valueType = getVarType(compiler, result, returnTypeName);
            if (!valueType) {
                result.addError(loc, CErrorCode::InvalidType, "explicit type '%s' does not exist", returnTypeName->name.c_str());
                returnType = nullptr;
            }
            returnType = valueType;
        }
        
        if (returnType == nullptr && block) {
            auto type = block->getType(compiler, result, shared_from_this(), thisVar);
            returnType = type;
        }
        
        if (returnType == nullptr) {
            returnType = compiler->typeVoid;
        }
    }
    
    isInGetType = false;
    return returnType;
}

shared_ptr<vector<shared_ptr<CVar>>> CFunction::getArgVars(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    auto args = make_shared<vector<shared_ptr<CVar>>>();
    for (auto it : argDefaultValues) {
        auto var = it->getVar(compiler, result, shared_from_this(), thisVar);
        assert(var);
        args->push_back(var);
    }
    return args;
}

bool CFunction::getHasThis() {
    if (!hasRefCount) {
        return false;
    }
    
    return true;
}

shared_ptr<CTypes> CFunction::getThisTypes(Compiler* compiler, CResult& result) {
    if (!thisTypes) {
        thisTypes = CType::create(name.c_str(), shared_from_this());
    }
    return thisTypes;
}

shared_ptr<vector<pair<string, shared_ptr<CType>>>> CFunction::getCTypeList(Compiler* compiler, CResult& result) {
    if (!ctypeList) {
        ctypeList = make_shared<vector<pair<string, shared_ptr<CType>>>>();

        if (hasRefCount) {
            indexRefCount = ctypeList->size();
            ctypeList->push_back(make_pair("_this", compiler->typePtr));
        }

        if (hasParent) {
            indexParent = ctypeList->size();
            auto parentType = parent.lock()->getThisTypes(compiler, result);
            ctypeList->push_back(make_pair("_parent", parentType->localValueType));
        }

        indexVars = ctypeList->size();
        for (auto it : thisVars) {
            auto ctype = it->getType(compiler, result);
            if (!ctype) {
                result.addError(it->nassignment->loc, CErrorCode::InvalidType, "cannot determine type for '%s'", it->name.c_str());
                return nullptr;
            }
            ctypeList->push_back(make_pair(it->name, ctype));
        }
    }
    return ctypeList;
}

bool CFunction::getReturnMustRelease(Compiler* compiler, CResult& result) {
    assert(false);
    return returnMustRelease;
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
                ctype = callerFunction->getVarType(compiler, result, templateTypeName);
            }
            
            if (!ctype) {
                ctype = thisFunction->getVarType(compiler, result, templateTypeName);
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


shared_ptr<CBaseFunction> CFunction::getCFunction(Compiler* compiler, CResult& result, const string& name, shared_ptr<CBaseFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames) {
    auto def = static_pointer_cast<CFunctionDefinition>(definition.lock());
    auto t = def->funcsByName.find(name);
    if (t != def->funcsByName.end()) {
        auto funcDef = t->second;
        
        vector<shared_ptr<CType>> templateTypes;
        if (!getTemplateTypes(compiler, result, loc, shared_from_this(), callerFunction, templateTypeNames, funcDef->node->templateTypeNames, templateTypes)) {
            return nullptr;
        }
        
        return funcDef->getFunction(compiler, result, loc, templateTypes, shared_from_this());
    }
    return nullptr;
}

shared_ptr<CInterface> CFunction::getCInterface(Compiler* compiler, CResult& result, const string& name, shared_ptr<CBaseFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames) {
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
                return cfunc->getCInterface(compiler, result, "#" + name, callerFunction, templateTypeNames);
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
        
        return interfaceDef->getInterface(compiler, result, templateTypes, shared_from_this());

        return nullptr;
    }
}

shared_ptr<CVar> CFunction::getCVar(Compiler* compiler, CResult& result, const string& name) {
    auto t1 = localVarsByName.find(name);
    if (t1 != localVarsByName.end()) {
        return t1->second;
    }
    
    auto t2 = thisVarsByName.find(name);
    if (t2 != thisVarsByName.end()) {
        return t2->second.second;
    }
    
    if (!parent.expired()) {
        auto parentFunction = static_pointer_cast<CFunction>(parent.lock());
        auto t3 = parentFunction->getCVar(compiler, result, name);
        if (t3) {
            if (t3->mode == Var_Local) {
                parentFunction->localVarToThisVar(compiler, static_pointer_cast<CNormalVar>(t3));
            }
            return CParentVar::create(compiler, result, shared_from_this(), t3);
        }
    }
    
    return nullptr;
}

int CFunction::getThisIndex(const string& name) const {
    auto it = thisVarsByName.find(name);
    if (it != thisVarsByName.end()) {
        return it->second.first;
    }
    return -1;
}

void CFunction::localVarToThisVar(Compiler* compiler, shared_ptr<CNormalVar> localVar) {
    assert(compiler->state <= CompilerState::FixVar); // Cannot change vars after type has been created
    assert(localVar->mode == CVarType::Var_Local);
    
    auto pos = localVarsByName.end();
    for (auto it = localVarsByName.begin(); it != localVarsByName.end(); it++) {
        if (it->second == localVar) {
            pos = it;
            break;
        }
    }
    
    if (pos == localVarsByName.end()) {
        assert(false);
        return;
    }
    
    localVar->makeFunctionVar((int)thisVars.size());
    int index = (int)thisVars.size();
    thisVars.push_back(localVar);
    thisVarsByName[pos->first] = pair<int, shared_ptr<CNormalVar>>(index, localVar);
    localVarsByName.erase(pos);
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

            ss << it->nameValue;
        }
    }
    return ss.str();
}

int CFunction::getArgStart(Compiler* compiler, CResult& result) {
    getThisTypes(compiler, result);
    return (int)indexVars;
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

shared_ptr<CType> CFunction::getVarType(Compiler* compiler, CResult& result, shared_ptr<CTypeName> typeName) {
    if (typeName->category == CTC_Interface) {
        auto nameWithoutQuestion = typeName->isOption ? typeName->name.substr(0, typeName->name.size() - 1) : typeName->name;
        auto interface = getCInterface(compiler, result, nameWithoutQuestion, nullptr, typeName->templateTypeNames);
        if (interface) {
            auto thisTypes = interface->getThisTypes(compiler, result);
            switch (typeName->typeMode) {
                case CTM_Heap:
                    return typeName->isOption ? thisTypes->heapOptionType : thisTypes->heapValueType;
                case CTM_Stack:
                    return typeName->isOption ? thisTypes->stackOptionType : thisTypes->stackValueType;
                case CTM_Local:
                    return typeName->isOption ? thisTypes->localOptionType : thisTypes->localValueType;
                default:
                    assert(false);
                    return nullptr;
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
                    auto t = getVarType(compiler, result, it);
                    if (!t) {
                        return nullptr;
                    }
                    templateTypes.push_back(t);
                }
            }
            
            auto functionDefinition = static_pointer_cast<CFunctionDefinition>(baseFunctionDefinition.second);
            auto cfunc = functionDefinition->getFunction(compiler, result, loc, templateTypes, baseFunctionDefinition.first);
            auto thisTypes = cfunc->getThisTypes(compiler, result);
            switch (typeName->typeMode) {
                case CTM_Heap:
                    return typeName->isOption ? thisTypes->heapOptionType : thisTypes->heapValueType;
                case CTM_Stack:
                    return typeName->isOption ? thisTypes->stackOptionType : thisTypes->stackValueType;
                case CTM_Local:
                    return typeName->isOption ? thisTypes->localOptionType : thisTypes->localValueType;
                default:
                    assert(false);
                    return nullptr;
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

shared_ptr<CFunction> CFunctionDefinition::getFunction(Compiler* compiler, CResult& result, CLoc& loc, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CFunction> funcParent) {
    shared_ptr<CFunction> func;
    auto funcParentPtr = funcParent.lock().get();
    auto it = _cfunctions[funcParentPtr].find(templateTypes);
    if (it != _cfunctions[funcParentPtr].end()) {
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
        
        func = node->createCFunction(compiler, result, shared_from_this(), templateTypes, funcParent, type, name, interfaces, interfaceMethod);

        if (getImplementedInterfaceDefintions(compiler, result)) {
            for (auto it : *getImplementedInterfaceDefintions(compiler, result)) {
                vector<shared_ptr<CType>> interfaceTemplateTypes;
                if (!it.first->ninterface) {
                    result.addError(loc, CErrorCode::InterfaceDoesNotExist, "cannot find interface '%s'", it.first->name.c_str());
                    return nullptr;
                }
                
                if (it.first->ninterface->templateTypeNames) {
                    if (!getTemplateTypes(compiler, result, loc, func, nullptr, it.second, it.first->ninterface->templateTypeNames, interfaceTemplateTypes)) {
                        return nullptr;
                    }
                }
                
                auto interface = it.first->getInterface(compiler, result, interfaceTemplateTypes, funcParent);
                if (!interface) {
                    result.addError(loc, CErrorCode::InterfaceDoesNotExist, "cannot find interface '%s'", it.first->name.c_str());
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

shared_ptr<CInterfaceDefinition> CFunctionDefinition::createDefinedInterfaceDefinition(string& name) {
    auto result = make_shared<CInterfaceDefinition>(name);
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
