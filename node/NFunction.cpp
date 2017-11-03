#include "Node.h"

int NFunction::counter = 0;

NFunction::NFunction(CLoc loc, CFunctionType type, shared_ptr<CTypeName> returnTypeName, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<CTypeNameList> interfaceTypeNames, shared_ptr<NodeList> arguments, shared_ptr<NBase> block, shared_ptr<NBase> catchBlock, shared_ptr<NBase> destroyBlock) : NBaseFunction(NodeType_Function, loc), type(type), returnTypeName(returnTypeName), name(name), templateTypeNames(templateTypeNames), interfaceTypeNames(interfaceTypeNames), block(block), catchBlock(catchBlock), destroyBlock(destroyBlock), isInGetType(false) {
    assert(type != FT_Extern);
    
    if (this->name == "^") {
        this->name = strprintf("anon_%d", counter++);
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
            } else {
                invalid.push_back(it);
            }
        }
    }
}

NFunction::NFunction(CLoc loc, CFunctionType type, const char* externName, shared_ptr<CTypeName> returnTypeName, const char* name, shared_ptr<NodeList> arguments): NBaseFunction(NodeType_Function, loc), type(type), externName(externName), returnTypeName(returnTypeName), name(name) {
    assert(type == FT_Extern);
    
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
            } else {
                invalid.push_back(it);
            }
        }
    }
}


void NFunction::defineImpl(Compiler *compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> parentFunction) {
    assert(compiler->state == CompilerState::Define);
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return;
    }
    
    if (type == FT_Extern) {
        // This is an extern function definition
        if (functions.size() > 0) {
            result.addError(loc, CErrorCode::InvalidFunction, "extern function init block can not contain function definitions");
            return;
        }
        
        if (interfaceTypeNames) {
            result.addError(loc, CErrorCode::InvalidType, "extern function cannot have an interface");
            return;
        }
        
        auto thisFunction = CFunctionDefinition::create(compiler, result, static_pointer_cast<CFunctionDefinition>(parentFunction), type, name, nullptr, shared_from_this());
        parentFunction->addChildFunction(name, thisFunction);
        
        for (auto it : assignments) {
            it->define(compiler, result, thisFunction);
        }
        
        if (block) {
            block->define(compiler, result, thisFunction);
        }
    } else {
        auto thisFunction = getFunctionDefinition(compiler, result, static_pointer_cast<CFunctionDefinition>(parentFunction));
        parentFunction->addChildFunction(name, thisFunction);

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
}

shared_ptr<CFunctionDefinition> NFunction::getFunctionDefinition(Compiler *compiler, CResult& result, shared_ptr<CFunctionDefinition> parentFunction) {
    shared_ptr<vector<pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>>> interfaces;
    if (interfaceTypeNames) {
        interfaces = make_shared<vector<pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>>>();
        for (auto it : *interfaceTypeNames) {
            auto interface = compiler->getInterfaceDefinition(it->name);
            interfaces->push_back(pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>(interface, it->templateTypeNames));
        }
    }
    
    return CFunctionDefinition::create(compiler, result, parentFunction, type, name, interfaces, shared_from_this());
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

shared_ptr<CType> NFunction::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, stringstream& trLine) {
	return nullptr;
}

//shared_ptr<ReturnValue> NFunction::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> parentFunction, shared_ptr<CVar> parentVar, Value* parentValue, IRBuilder<>* builder, BasicBlock* parentCatchBB, ReturnRefType returnRefType) {
//    return nullptr;
//}

shared_ptr<CFunction> NFunction::createCFunction(Compiler* compiler, CResult& result, weak_ptr<CBaseFunctionDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, CFunctionType type, const string& name, shared_ptr<vector<shared_ptr<CInterface>>> interfaces, shared_ptr<CInterfaceMethod> interfaceMethod) {
    auto fun = make_shared<CFunction>(definition, type, templateTypes, parent, interfaces);
    return fun->init(compiler, result, shared_from_this(), interfaceMethod);
}

CFunctionReturnVar::CFunctionReturnVar(shared_ptr<CVar> returnVar, shared_ptr<CInterfaceMethodReturnVar> interfaceMethodReturnVar) : returnVar(returnVar), interfaceMethodReturnVar(interfaceMethodReturnVar) {
}

void CFunctionReturnVar::init(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    if (interfaceMethodReturnVar) {
        if (returnVar->getHeapVar(compiler, result, thisVar)) {
            interfaceMethodReturnVar->setHeapVar(compiler, result, nullptr);
        }
        interfaceMethodReturnVar->returnVars.push_back(shared_from_this());
    }
}

shared_ptr<CType> CFunctionReturnVar::getType(Compiler* compiler, CResult& result) {
    return returnVar->getType(compiler, result);
}

//shared_ptr<ReturnValue> CFunctionReturnVar::getLoadValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    return returnVar->getLoadValue(compiler, result, thisVar, thisValue, dotInEntry, dotValue, builder, catchBB, returnRefType);
//}
//
//Value* CFunctionReturnVar::getStoreValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
//    return returnVar->getStoreValue(compiler, result, thisVar, thisValue, dotInEntry, dotValue, builder, catchBB);
//}

bool CFunctionReturnVar::getHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    auto isHeapVar = returnVar->getHeapVar(compiler, result, thisVar);
    if (interfaceMethodReturnVar) {
        assert(isHeapVar == interfaceMethodReturnVar->getHeapVar(compiler, result, nullptr));
    }
    return isHeapVar;
}

int CFunctionReturnVar::setHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    auto count = returnVar->setHeapVar(compiler, result, thisVar);
    if (interfaceMethodReturnVar) {
        count += interfaceMethodReturnVar->setHeapVar(compiler, result, nullptr);
    }
    return count;
}

shared_ptr<CType> CFunctionReturnVar::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, stringstream& trLine, shared_ptr<CVar> dotVar) {
    assert(false);
	return nullptr;
}

void CFunctionReturnVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    returnVar->dump(compiler, result, thisFunction, thisVar, dotVar, functions, ss, dotSS, level);
}

CFunction::CFunction(weak_ptr<CBaseFunctionDefinition> definition, CFunctionType type, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CBaseFunction> parent, shared_ptr<vector<shared_ptr<CInterface>>> interfaces) :
CBaseFunction(definition.lock()->name, parent, definition),
//_structType(nullptr),
//function(nullptr),
loc(CLoc::undefined),
type(type),
templateTypes(templateTypes),
interfaces(interfaces),
isInGetType(false),
isInGetFunction(false),
returnMustRelease(false),
block(nullptr),
catchBlock(nullptr),
destroyBlock(nullptr),
returnTypeName(nullptr),
interfaceTypeNames(nullptr)
//destructorFunction(nullptr),
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
        externName = node->externName;
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

shared_ptr<CVar> CFunction::getReturnVar(Compiler *compiler, CResult& result, shared_ptr<CVar> thisVar) {
    if (!functionReturnVar) {
        if (block) {
            shared_ptr<CInterfaceMethodReturnVar> interfaceMethodReturnVar;
            if (interfaceMethod) {
                interfaceMethodReturnVar = static_pointer_cast<CInterfaceMethodReturnVar>(interfaceMethod->getReturnVar(compiler, result, nullptr));
            }
            
            auto returnVar = block->getVar(compiler, result, shared_from_this(), thisVar);
            if (returnVar) {
                functionReturnVar = make_shared<CFunctionReturnVar>(returnVar, interfaceMethodReturnVar);
                functionReturnVar->init(compiler, result, thisVar);
            }
        }
    }
    return functionReturnVar;
}

void CFunction::getVarBody(Compiler *compiler, CResult& result, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);   
    for (auto it : functions) {
        it->getVar(compiler, result, shared_from_this(), thisVar);
    }

    for (auto it : argDefaultValues) {
        if (it) {
            it->getVar(compiler, result, shared_from_this(), thisVar);
        }
    }
    
    if (block) {
        block->getVar(compiler, result, shared_from_this(), thisVar);
    }
    
    if (catchBlock) {
        catchBlock->getVar(compiler, result, shared_from_this(), thisVar);
    }
    
    if (destroyBlock) {
        destroyBlock->getVar(compiler, result, shared_from_this(), thisVar);
    }
    
    getReturnType(compiler, result, thisVar);
}

int CFunction::setHeapVarBody(Compiler *compiler, CResult& result, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);
    auto count = 0;
    do {
        count = 0;
        for (auto it : functions) {
            count += it->setHeapVar(compiler, result, shared_from_this(), thisVar, false);
        }
        
        for (auto it : argDefaultValues) {
            if (it) {
                count += it->setHeapVar(compiler, result, shared_from_this(), thisVar, false);
            }
        }
        
        if (block) {
            count += block->setHeapVar(compiler, result, shared_from_this(), thisVar, true);
        }
        
        if (catchBlock) {
            count += catchBlock->setHeapVar(compiler, result, shared_from_this(), thisVar, true);
        }
        
        if (destroyBlock) {
            count += destroyBlock->setHeapVar(compiler, result, shared_from_this(), thisVar, true);
        }
    } while (count > 0);
    return 0;
}

class ArgData {
public:
    ArgData(shared_ptr<CVar> var_, string value_) : var(var_), value(value_) { }
    
    shared_ptr<CVar> var;
    string value;
};

shared_ptr<CType> CFunction::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, stringstream& trLine, shared_ptr<CVar> calleeVar, vector<shared_ptr<NBase>>& parameters) {
    assert(compiler->state == CompilerState::Compile);

    auto returnType = getReturnType(compiler, result, thisVar);
    if (!returnType) {
        return nullptr;
    }

    auto argTypes = getCTypeList(compiler, result);

    vector<ArgData> argValues;
    auto argIndex = 0;
    // Fill in "this" with normal arguments
    for (auto defaultAssignment : argDefaultValues) {
        auto argVar = argVars[argIndex];
        // auto argHeapVar = argVar->getHeapVar(compiler, result, thisVar);
        auto argType = argVar->getType(compiler, result);
        auto isDefaultAssignment = parameters[argIndex] == defaultAssignment;
        shared_ptr<CType> argReturnType;
        
        stringstream argStream;
        if (isDefaultAssignment) {
            //                auto paramVar = parameters[argIndex]->getVar(compiler, result, shared_from_this(), calleeVar);
            //                if (paramVar) {
            //                    auto paramHeapVar = paramVar->getHeapVar(compiler, result, thisVar);
            //                    assert(paramHeapVar == argHeapVar);
            //                }
            argReturnType = parameters[argIndex]->transpile(compiler, result, shared_from_this(), calleeVar, trOutput, trBlock, argStream);
        } else {
            //                auto paramVar = parameters[argIndex]->getVar(compiler, result, shared_from_this(), thisVar);
            //                if (paramVar) {
            //                    auto paramHeapVar = paramVar->getHeapVar(compiler, result, thisVar);
            //                    assert(paramHeapVar == argHeapVar);
            //                }
            argReturnType = parameters[argIndex]->transpile(compiler, result, shared_from_this(), thisVar, trOutput, trBlock, argStream);
        }
        
        auto argReturnValue = argStream.str();
        
        if (argReturnValue.size() == 0) {
            result.addError(loc, CErrorCode::TypeMismatch, "value is empty");
            return nullptr;
        }
        
        if (argReturnType != argType) {
            result.addError(loc, CErrorCode::TypeMismatch, "value does not match");
            return nullptr;
        }
        
        argValues.push_back(ArgData(argVar, argReturnValue));
        argIndex++;
    }
    
    string functionName = name;
    if (!parent.expired()) {
        auto tempType = parent.lock();
        while (tempType != nullptr && tempType->name.compare("global") != 0 && tempType->name.size() > 0) {
            functionName.insert(0, "_");
            functionName.insert(0, tempType->name);
            tempType = tempType->parent.lock();
        }
    }
    functionName.insert(0, "sjf_");

    if (!getHasThis()) {
        // Create function body
        if (trOutput->functions.find(functionName) == trOutput->functions.end()) {
            auto trFunctionBlock = make_shared<TrBlock>();
            trFunctionBlock->parent = nullptr;
			trFunctionBlock->hasThis = false;
            trOutput->functions[functionName] = trFunctionBlock;
            
            stringstream definition;
            definition << returnType->nameRef << " " << functionName << "(";
            auto isFirstArg = true;
            for (auto argType : *argTypes) {
                if (isFirstArg) {
                    isFirstArg = false;
                } else {
                    definition << ", ";
                }
                definition << argType.second->nameRef << " " << argType.first;
            }
            definition << ")";
            trFunctionBlock->definition = definition.str();
            
            stringstream returnLine;
            auto returnType = block->transpile(compiler, result, shared_from_this(), nullptr, trOutput, trFunctionBlock.get(), returnLine);
            if (returnLine.str().size() > 0) {
                if (returnType != compiler->typeVoid) {
                    trFunctionBlock->statements.push_back("return " + returnLine.str());
                } else {
                    trFunctionBlock->statements.push_back(returnLine.str());
                }
            }
        }
        
        // Get parent from the current line string
        auto parentValue = trLine.str();
        trLine.str("");
        trLine.clear();

        // Add "parent" to "this"
        auto hasParent = getHasParent(compiler, result);
        shared_ptr<ReturnValue> dotReturnValue;
        if (hasParent) {
            if (parentValue.size() == 0) {
                parentValue = trBlock->hasThis ? "_this" : "_parent";
            }

            argValues.insert(argValues.begin(), ArgData(nullptr, parentValue));
            
            //            Value* parentValue = thisValue;
            //            if (dotVar) {
            //                dotReturnValue = dotVar->getLoadValue(compiler, result, thisVar, thisValue, true, thisValue, builder, catchBB, RRT_Auto);
            //                parentValue = dotReturnValue->value;
            //            } else {
            //                // if recursively calling ourselves then re-use parent
            //                if (shared_from_this() == thisFunction) {
            //                    parentValue = getParentValue(compiler, result, builder, true, parentValue);
            //                } else {
            //                    auto temp = static_pointer_cast<CBaseFunction>(thisFunction);
            //                    while (temp && temp != parent.lock()) {
            //                        parentValue = temp->getParentValue(compiler, result, builder, true, parentValue);
            //                        temp = temp->parent.lock();
            //                    }
            //                }
            //            }
            //
            //            argValues.push_back(parentValue);
        }

        // Call function
        trLine << functionName << "(";
        bool isFirstParameter = true;
        for (auto argValue : argValues) {
            if (isFirstParameter) {
                isFirstParameter = false;
            } else {
                trLine << ", ";
            }
            
            trLine << "(" << argValue.value << ")";
        }
        trLine << ")";
    } else {
        // Create struct
		string structName = "sjs_" + name;
		if (trOutput->structs.find(structName) == trOutput->structs.end()) {
            trOutput->structs[structName].begin();
			for (auto argType : *argTypes) {
                if (argType.first.compare("_this") == 0)
                    continue;
                
				stringstream ss;
				ss << argType.second->nameRef << " " << argType.first;
				trOutput->structs[structName].push_back(ss.str());
			}
		}

        // Create function body
		if (trOutput->functions.find(functionName) == trOutput->functions.end()) {
			auto trFunctionBlock = make_shared<TrBlock>();
            trFunctionBlock->parent = nullptr;
			trFunctionBlock->hasThis = true;
			trOutput->functions[functionName] = trFunctionBlock;

			stringstream functionDefinition;
			functionDefinition << returnType->nameRef << " " << functionName << "(" << structName << "* _this)";
			trFunctionBlock->definition = functionDefinition.str();

			stringstream returnLine;

			auto returnType = block->transpile(compiler, result, shared_from_this(), calleeVar, trOutput, trFunctionBlock.get(), returnLine);
			if (returnLine.str().size() > 0) {
                if (returnType != compiler->typeVoid) {
                    trFunctionBlock->statements.push_back("return " + returnLine.str());
                } else {
                    trFunctionBlock->statements.push_back(returnLine.str());
                }
			}
		}
        
        // Get parent from the current line string
        auto parentValue = trLine.str();
        trLine.str("");
        trLine.clear();

        // Initialize "this"
        auto objectRef = trBlock->createTempVariable("sjv_temp", thisType->nameRef);
        if (calleeVar->getHeapVar(compiler, result, thisVar)) {
            stringstream initLine;
            initLine << objectRef->name << " = (" << structName << "*)malloc(sizeof(" << structName << "))";
            trBlock->statements.push_back(TrStatement(initLine.str()));
        } else {
            auto objectVal = trBlock->createTempVariable("sjd_temp", thisType->nameValue);
            stringstream initLine;
            initLine << objectRef->name << " = &" << objectVal->name;
            trBlock->statements.push_back(TrStatement(initLine.str()));
        }
        
        for (auto argValue : argValues) {
            stringstream argAssignLine;
            argAssignLine << objectRef->name << "->" << argValue.var->name << " = " << argValue.value;
            trBlock->statements.push_back(TrStatement(argAssignLine.str()));
        }
        
        // Call function
		trLine << functionName << "(" << objectRef->name << ")";
	}
    
    return returnType;
}

//Function* CFunction::compileDefinition(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
//    assert(compiler->state == CompilerState::Compile);
//
//    auto returnType = getReturnType(compiler, result, thisVar);
//    if (!returnType) {
//        return nullptr;
//    }
//    
//    if (!getHasThis()) {
//        auto argTypes = getTypeList(compiler, result);
//        auto returnLLVMType = returnType->llvmRefType(compiler, result);
//        assert(returnLLVMType);
//        auto functionType = FunctionType::get(returnLLVMType, ArrayRef<Type*>(*argTypes.get()), false);
//        if (type == FT_Extern) {
//            return Function::Create(functionType, Function::ExternalLinkage, externName.c_str(), compiler->module.get());
//        } else {
//            auto function = Function::Create(functionType, type == FT_Public ? Function::ExternalLinkage : Function::PrivateLinkage, name.c_str(), compiler->module.get());
//            if (catchBlock) {
//                auto personality = compiler->exception->getPersonality();
//                auto folder = ConstantFolder();
//                auto t = folder.CreateCast(Instruction::BitCast, personality, Type::getInt8PtrTy(compiler->context));
//                function->setPersonalityFn(t);
//            }
//            return function;
//        }
//    } else {
//        vector<Type*> argTypes;
//        argTypes.push_back(getThisType(compiler, result)->llvmRefType(compiler, result));
//        auto functionType = FunctionType::get(returnType->llvmRefType(compiler, result), argTypes, false);
//        auto function = Function::Create(functionType, type == FT_Public ? Function::ExternalLinkage : Function::PrivateLinkage, name.c_str(), compiler->module.get());
//        function->args().begin()->setName("this");
//        if (catchBlock) {
//            auto personality = compiler->exception->getPersonality();
//            auto folder = ConstantFolder();
//            auto t = folder.CreateCast(Instruction::BitCast, personality, Type::getInt8PtrTy(compiler->context));
//            function->setPersonalityFn(t);
//        }
//        return function;
//    }
//}
//
//bool CFunction::compileBody(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Function* function) {
//    assert(compiler->state == CompilerState::Compile);
//    
//    if (!block) {
//        return false;
//    }
//    
//    // Create body of function
//    // Create a new basic block to start insertion into.
//    auto entryBuilder = compiler->getEntryBuilder(function);
//    shared_ptr<ReturnValue> returnValue = nullptr;
//    shared_ptr<CVar> returnVar = nullptr;
//    auto returnType = block->getType(compiler, result, shared_from_this(), thisVar);
//    auto returnFunction = returnType->parent.expired() ? nullptr : returnType->parent.lock();
//    auto thisArgument = getHasThis() ? getThisArgument(compiler, result) : nullptr;
//
//#ifdef DWARF_ENABLED
//    SmallVector<Metadata *, 8> EltTys;
//    EltTys.push_back(returnType->getDIType(compiler, result));
//    EltTys.push_back(getThisType(compiler, result)->getDIType(compiler, result));
//    auto ditypes = compiler->DBuilder->createSubroutineType(compiler->DBuilder->getOrCreateTypeArray(EltTys));
//    
//    // Create a subprogram DIE for this function.
//    DIFile *Unit = loc.fileName ? compiler->DBuilder->createFile(*loc.fileName.get(), ".") : compiler->DBuilder->createFile(compiler->TheCU->getFilename(), compiler->TheCU->getDirectory());
//    DIScope *FContext = Unit;
//    unsigned LineNo = loc.line;
//    unsigned ScopeLine = LineNo;
//    DISubprogram *SP = compiler->DBuilder->createFunction(FContext, name.c_str(), StringRef(), Unit, LineNo, ditypes, false /* internal linkage */, true /* definition */, ScopeLine, DINode::FlagPrototyped, false);
//    function->setSubprogram(SP);
//    
//    // Push the current scope.
//    compiler->LexicalBlocks.push_back(SP);
//    
//    // Unset the location for the prologue emission (leading instructions with no
//    // location in a function are considered part of the prologue and the debugger
//    // will run past them when breaking on a function)
//    compiler->emitLocation(entryBuilder.get(), nullptr);
//
//    if (thisArgument) {
//        // Create a debug descriptor for the variable.
//        DILocalVariable *D = compiler->DBuilder->createParameterVariable(SP, "this", 1, Unit, LineNo, getThisType(compiler, result)->getDIType(compiler, result), true);
//        compiler->DBuilder->insertDeclare(thisArgument, D, compiler->DBuilder->createExpression(),
//                                          DebugLoc::get(LineNo, 0, SP),
//                                          entryBuilder->GetInsertBlock());
//    }
//#endif
//    
//    auto bodyBB = BasicBlock::Create(compiler->context, "body", function);
//    IRBuilder<> bodyBuilder(bodyBB);
//    compiler->callPushFunction(&bodyBuilder, name);
//    
//    BasicBlock* catchBB = nullptr;
//    if (catchBlock) {
//        catchBB = BasicBlock::Create(compiler->context, "catch", function);
//    }
//    
//    returnVar = block->getVar(compiler, result, shared_from_this(), thisVar);
//    returnValue = block->compile(compiler, result, shared_from_this(), thisVar, thisArgument, &bodyBuilder, catchBB, interfaceMethod ? RRT_MustRelease : RRT_Auto);
//
//    compiler->callPopFunction(&bodyBuilder);
//    
//    if (function->getReturnType()->isVoidTy()) {
//        bodyBuilder.CreateRetVoid();
//    } else {
//        if (!returnValue) {
//            result.addError(loc, CErrorCode::TypeMismatch, "no return for non-void function");
//            goto error;
//        }
//        
//        if (function->getReturnType() != returnValue->value->getType()) {
//            result.addError(loc, CErrorCode::TypeMismatch, "return type '%s' does not match return value type '%s'", Type_print(function->getReturnType()).c_str(), Type_print(returnValue->value->getType()).c_str());
//            goto error;
//        }
//        
//        // Release all of the local vars
//        for (auto it : localVarsByName) {
//            auto type = it.second->getType(compiler, result);
//            if (!type->parent.expired()) {
//                auto localValue = it.second->getLoadValue(compiler, result, thisVar, thisArgument, true, nullptr, &bodyBuilder, catchBB, RRT_Auto);
//                if (localValue->type == RVT_HEAP) {
//                    assert(localValue->releaseMode == RVR_MustRetain);
//                    if (it.second->getHeapVar(compiler, result, thisVar)) {
//                        type->parent.lock()->releaseHeap(compiler, result, &bodyBuilder, localValue->value);
//                    } else {
//                        type->parent.lock()->releaseStack(compiler, result, &bodyBuilder, localValue->value);
//                    }
//                }
//            }
//        }
//        
//        bodyBuilder.CreateRet(returnValue->value);
//    }
//    
//    if (catchBB) {
//   
//        IRBuilder<> catchBuilder(catchBB);
//        
//        llvm::Type *caughtResultFieldTypes[] = {
//            catchBuilder.getInt8PtrTy(),
//            catchBuilder.getInt32Ty()
//        };
//        auto caughtResultType = llvm::StructType::get(compiler->context, ArrayRef<Type*>(caughtResultFieldTypes));
//        
//        auto caughtResult = catchBuilder.CreateLandingPad(caughtResultType, 1);
//        auto t = compiler->module->getGlobalVariable("_ZTIPv");
//        auto j = catchBuilder.CreateBitCast(t, Type::getInt8PtrTy(compiler->context));
//        caughtResult->addClause((Constant*)j);
//
//#ifdef EXCEPTION_OUTPUT
//        Value *unwindException = catchBuilder.CreateExtractValue(caughtResult, 0);
//        Value *retTypeInfoIndex = catchBuilder.CreateExtractValue(caughtResult, 1);
//#endif
//
//        if (catchBlock) {
//#ifdef EXCEPTION_OUTPUT
//            auto exceptionValue = catchBuilder.CreateCall(compiler->exception->getBeginCatch(), unwindException);
//            Value *i64 = catchBuilder.CreateIntCast(retTypeInfoIndex, Type::getInt64Ty(compiler->context), true);
//            compiler->callDebug(&catchBuilder, strprintf("CAUGHT EXCEPTION %s", name.c_str()), exceptionValue, i64);
//#endif
//        
//            returnVar = catchBlock->getVar(compiler, result, shared_from_this(), thisVar);
//            auto catchReturnValue = catchBlock->compile(compiler, result, shared_from_this(), thisVar, thisArgument, &catchBuilder, nullptr, returnValue && returnValue->releaseMode == RVR_MustRelease ? RRT_MustRelease : RRT_MustRetain);
//
//            catchBuilder.CreateCall(compiler->exception->getEndCatch());
//
//            if (function->getReturnType()->isVoidTy()) {
//                catchBuilder.CreateRetVoid();
//            } else {
//                if (!catchReturnValue) {
//                    result.addError(loc, CErrorCode::TypeMismatch, "no return for non-void function");
//                    goto error;
//                }
//                
//                if (function->getReturnType() != catchReturnValue->value->getType()) {
//                    result.addError(loc, CErrorCode::TypeMismatch, "return type '%s' does not match return value type '%s'", Type_print(function->getReturnType()).c_str(), Type_print(catchReturnValue->value->getType()).c_str());
//                    goto error;
//                }
//                
//                assert(catchReturnValue->type == returnValue->type);
//                assert(catchReturnValue->releaseMode == returnValue->releaseMode);
//                catchBuilder.CreateRet(catchReturnValue->value);
//            }            
//        } else {
//#ifdef EXCEPTION_OUTPUT
//            Value *i64 = catchBuilder.CreateIntCast(retTypeInfoIndex, Type::getInt64Ty(compiler->context), true);
//            compiler->callDebug(&catchBuilder, strprintf("RESUME EXCEPTION %s", name.c_str()), unwindException, i64);
//#endif
//            catchBuilder.CreateResume(caughtResult);
//            // catchBuilder.CreateUnreachable();
//        }
//    }
//    entryBuilder->CreateBr(bodyBB);
//    
//error:
//    if (catchBB) {
//        function->getBasicBlockList().remove(catchBB);
//        function->getBasicBlockList().push_back(catchBB);
//    }
//    
//#ifdef DWARF_ENABLED
//    compiler->LexicalBlocks.pop_back();
//#endif
//    
//#ifndef DWARF_ENABLED
//    // Validate the generated code, checking for consistency.
//    if (result.errors.size() == 0 && verifyFunction(*function)) {
//        compiler->module->dump();
//        printf("---------\n");
//        function->dump();
//        auto output = new raw_os_ostream(std::cout);
//        verifyFunction(*function, output);
//        output->flush();
//        assert(false);
//    }
//#endif
//
//    assert(!returnValue || returnValue->type == RVT_SIMPLE || returnValue->type == RVT_HEAP);
//    return returnValue ? returnValue->releaseMode == RVR_MustRelease : false;
//}
//
//Function* CFunction::compileDestructorDefinition(Compiler* compiler, CResult& result) {
//    assert(compiler->state == CompilerState::Compile);
//
//    if (type == FT_Extern) {
//        return nullptr;
//    }
//    
//    auto hasDestructor = destroyBlock != nullptr;
//    for (auto it : thisVars) {
//        if (!it->getType(compiler, result)->parent.expired()) {
//            hasDestructor = true;
//        }
//    }
//    
//    if (!hasDestructor) {
//        return nullptr;
//    }
//    
//    vector<Type*> argTypes;
//    argTypes.push_back(getThisType(compiler, result)->llvmRefType(compiler, result));
//    auto functionType = FunctionType::get(Type::getVoidTy(compiler->context), argTypes, false);
//    auto function = Function::Create(functionType, type == FT_Public ? Function::ExternalLinkage : Function::PrivateLinkage, strprintf("%s_destructor", name.c_str()).c_str(), compiler->module.get());
//    function->args().begin()->setName("this");
//    
//    return function;
//}
//
//void CFunction::compileDestructorBody(Compiler* compiler, CResult& result, Function* function) {
//    assert(compiler->state == CompilerState::Compile);
//    
//    // Create body of function
//    // Create a new basic block to start insertion into.
//    auto entryBuilder = compiler->getEntryBuilder(function);
//    
//#ifdef DWARF_ENABLED
//    SmallVector<Metadata *, 8> EltTys;
//    EltTys.push_back(getThisType(compiler, result)->getDIType(compiler, result));
//    auto ditypes = compiler->DBuilder->createSubroutineType(compiler->DBuilder->getOrCreateTypeArray(EltTys));
//    
//    // Create a subprogram DIE for this function.
//    DIFile *Unit = loc.fileName ? compiler->DBuilder->createFile(*loc.fileName.get(), ".") : compiler->DBuilder->createFile(compiler->TheCU->getFilename(), compiler->TheCU->getDirectory());
//    DIScope *FContext = Unit;
//    unsigned LineNo = loc.line;
//    unsigned ScopeLine = LineNo;
//    DISubprogram *SP = compiler->DBuilder->createFunction(FContext, name.c_str(), StringRef(), Unit, LineNo, ditypes, false /* internal linkage */, true /* definition */, ScopeLine, DINode::FlagPrototyped, false);
//    function->setSubprogram(SP);
//    
//    // Push the current scope.
//    compiler->LexicalBlocks.push_back(SP);
//    
//    // Unset the location for the prologue emission (leading instructions with no
//    // location in a function are considered part of the prologue and the debugger
//    // will run past them when breaking on a function)
//    compiler->emitLocation(entryBuilder.get(), nullptr);
//#endif
//
//    auto bodyBB = BasicBlock::Create(compiler->context, "body", function);
//    IRBuilder<> bodyBuilder(bodyBB);
//    
//    shared_ptr<ReturnValue> returnValue = nullptr;
//    Argument* thisArgument = (Argument*)function->args().begin();
//    
//    if (destroyBlock) {
//        destroyBlock->compile(compiler, result, shared_from_this(), nullptr, thisArgument, &bodyBuilder, nullptr, RRT_Auto);
//    }
//    
//    for (auto it : thisVars) {
//        auto type = it->getType(compiler, result);
//        if (!type->parent.expired() && !isSimpleType(type->llvmRefType(compiler, result))) {
//            auto value = it->getLoadValue(compiler, result, nullptr, thisArgument, true, thisArgument, &bodyBuilder, nullptr, RRT_Auto);
//            assert(value->type == RVT_HEAP);
//            if (it->getHeapVar(compiler, result, nullptr)) {
//                value->valueFunction->releaseHeap(compiler, result, &bodyBuilder, value->value);
//            } else {
//                value->valueFunction->releaseStack(compiler, result, &bodyBuilder, value->value);
//            }
//        }
//    }
//    
//    entryBuilder->CreateBr(bodyBB);
//    
//#ifdef DWARF_ENABLED
//    compiler->LexicalBlocks.pop_back();
//#endif
//    
//    bodyBuilder.CreateRetVoid();
//}
//
//shared_ptr<ReturnValue> CFunction::call(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, shared_ptr<CVar> calleeVar, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters, ReturnRefType returnRefType) {
//    if (!getHasThis()) {
//        vector<shared_ptr<ReturnValue>> argReturnValues;
//        vector<Value *> argValues;
//        auto func = getFunction(compiler, result, calleeVar);
//        auto calleeFunction = calleeVar->getCFunctionForValue(compiler, result);
//
//        // Add "parent" to "this"
//        auto hasParent = getHasParent(compiler, result);
//        shared_ptr<ReturnValue> dotReturnValue;
//        if (hasParent) {
//            Value* parentValue = thisValue;
//            if (dotVar) {
//                dotReturnValue = dotVar->getLoadValue(compiler, result, thisVar, thisValue, true, thisValue, builder, catchBB, RRT_Auto);
//                parentValue = dotReturnValue->value;
//            } else {
//                // if recursively calling ourselves then re-use parent
//                if (shared_from_this() == thisFunction) {
//                    parentValue = getParentValue(compiler, result, builder, true, parentValue);
//                } else {
//                    auto temp = static_pointer_cast<CBaseFunction>(thisFunction);
//                    while (temp && temp != parent.lock()) {
//                        parentValue = temp->getParentValue(compiler, result, builder, true, parentValue);
//                        temp = temp->parent.lock();
//                    }
//                }
//            }
//            
//            argValues.push_back(parentValue);
//        }
//        
//        assert(argValues.size() == getArgStart(compiler, result));
//        auto argIndex = 0;
//        // Fill in "this" with normal arguments
//        for (auto defaultAssignment : argDefaultValues) {
//            auto argVar = argVars[argIndex];
//            auto argHeapVar = argVar->getHeapVar(compiler, result, thisVar);            
//            auto argType = argVar->getType(compiler, result);
//            auto isDefaultAssignment = parameters[argIndex] == defaultAssignment;
//            shared_ptr<ReturnValue> argReturnValue;
//            
//            if (isDefaultAssignment) {
//                auto paramVar = parameters[argIndex]->getVar(compiler, result, shared_from_this(), calleeVar);
//                if (paramVar) {
//                    auto paramHeapVar = paramVar->getHeapVar(compiler, result, thisVar);
//                    assert(paramHeapVar == argHeapVar);
//                }
//                argReturnValue = parameters[argIndex]->compile(compiler, result, shared_from_this(), calleeVar, nullptr, builder, catchBB, RRT_Auto);
//            } else {
//                auto paramVar = parameters[argIndex]->getVar(compiler, result, shared_from_this(), thisVar);
//                if (paramVar) {
//                    auto paramHeapVar = paramVar->getHeapVar(compiler, result, thisVar);
//                    assert(paramHeapVar == argHeapVar);
//                }
//                argReturnValue = parameters[argIndex]->compile(compiler, result, shared_from_this(), thisVar, thisValue, builder, catchBB, RRT_Auto);
//            }
//            
//            if (!argReturnValue) {
//                result.addError(loc, CErrorCode::TypeMismatch, "value is empty");
//                return nullptr;
//            }
//            
//            if (argReturnValue->value->getType() != argType->llvmRefType(compiler, result)) {
//                result.addError(loc, CErrorCode::TypeMismatch, "value does not match");
//                return nullptr;
//            }
//            
//            argReturnValues.push_back(argReturnValue);
//            argValues.push_back(argReturnValue->value);
//            argIndex++;
//        }
//        
//        auto returnType = getReturnType(compiler, result, calleeVar);
//        auto returnFunction = returnType->parent.lock();
//        
//        if (type == FT_Extern) {
//            auto returnValue = builder->CreateCall(func, argValues);
//            // All extern function must return a var that needs to be released
//            for (auto it : argReturnValues) {
//                it->releaseIfNeeded(compiler, result, builder);
//            }
//            return make_shared<ReturnValue>(returnFunction, returnFunction ? RVR_MustRelease : RVR_MustRetain, returnFunction ? RVT_HEAP : RVT_SIMPLE, false, returnValue);
//        } else {
//            Value* returnValue = nullptr;
//            
//            if (catchBB) {
//                auto continueBB = BasicBlock::Create(compiler->context);
//                returnValue = builder->CreateInvoke(func, continueBB, catchBB, argValues);
//                
//                Function *function = builder->GetInsertBlock()->getParent();
//                function->getBasicBlockList().push_back(continueBB);
//                builder->SetInsertPoint(continueBB);
//            } else {
//                returnValue = builder->CreateCall(func, argValues);
//            }
//            
//            auto mustRelease = calleeFunction->getReturnMustRelease(compiler, result);
//            
//            if (dotReturnValue) {
//                dotReturnValue->releaseIfNeeded(compiler, result, builder);
//            }
//            
//            return make_shared<ReturnValue>(returnFunction, mustRelease ? RVR_MustRelease : RVR_MustRetain, returnFunction ? RVT_HEAP : RVT_SIMPLE, false, returnValue);
//        }
//    } else {
//        vector<shared_ptr<ReturnValue>> argReturnValues;
//
//        // Create this on stack, and get a pointer
//        Value* calleeValue = nullptr;
//        auto calleeType = getThisType(compiler, result);
//        auto calleeHeapVar = calleeVar->getHeapVar(compiler, result, thisVar);
//        auto calleeFunction = calleeVar->getCFunctionForValue(compiler, result);
//        auto calleeInEntry = false;
//        
//        if (calleeHeapVar) {
//            // heap alloc this
//            auto allocFunc = compiler->getAllocFunction();
//            
//            // Compute the size of the struct by getting a pointer to the second element from null
//            vector<Value*> v;
//            v.push_back(ConstantInt::get(compiler->context, APInt(32, 1)));
//            auto thisPointerType = calleeType->llvmAllocType(compiler, result)->getPointerTo();
//            auto nullPtr = ConstantPointerNull::get(thisPointerType);
//            auto sizePtr = builder->CreateGEP(nullPtr, ArrayRef<llvm::Value *>(v));
//            auto sizeValue = builder->CreatePtrToInt(sizePtr, Type::getInt64Ty(compiler->context));
//            
//            // Allocate and mutate to correct type
//            vector<Value*> allocArgs;
//            allocArgs.push_back(sizeValue);
//            auto calleeValueAsVoidPtr = builder->CreateCall(allocFunc, allocArgs);
//            calleeValue = builder->CreateBitCast(calleeValueAsVoidPtr, thisPointerType);
//            calleeFunction->initHeap(compiler, result, builder, calleeValue);
//            calleeInEntry = false;
//        } else {
//            // stack alloc this
//            auto entryBuilder = compiler->getEntryBuilder(getFunctionFromBuilder(builder));
//            calleeValue = entryBuilder->CreateAlloca(calleeType->llvmAllocType(compiler, result), 0, calleeType->name.c_str());
//            calleeFunction->initStack(compiler, result, builder, calleeValue);
//            calleeInEntry = true;
//        }
//        
//        // Fill in "this" with normal arguments
//        auto argIndex = 0;
//        for (auto defaultAssignment : argDefaultValues) {
//            auto argVar = argVars[argIndex];
//            auto argHeapVar = argVar->getHeapVar(compiler, result, thisVar);
//            auto argType = argVar->getType(compiler, result);
//            auto isDefaultAssignment = parameters[argIndex] == defaultAssignment;
//            shared_ptr<ReturnValue> argReturnValue;
//            if (isDefaultAssignment) {
//                auto paramVar = parameters[argIndex]->getVar(compiler, result, shared_from_this(), calleeVar);
//                if (paramVar) {
//                    auto paramHeapVar = paramVar->getHeapVar(compiler, result, thisVar);
//                    assert(paramHeapVar == argHeapVar);
//                }
//                argReturnValue = parameters[argIndex]->compile(compiler, result, shared_from_this(), calleeVar, calleeValue, builder, catchBB, RRT_Auto);
//            } else {
//                auto paramVar = parameters[argIndex]->getVar(compiler, result, shared_from_this(), thisVar);
//                if (paramVar) {
//                    auto paramHeapVar = paramVar->getHeapVar(compiler, result, thisVar);
//                    assert(paramHeapVar == argHeapVar);
//                }
//                argReturnValue = parameters[argIndex]->compile(compiler, result, shared_from_this(), thisVar, thisValue, builder, catchBB, RRT_Auto);
//            }
//                        
//            if (!argReturnValue) {
//                result.addError(loc, CErrorCode::TypeMismatch, "value is empty");
//                return nullptr;
//            }
//            
//            if (argReturnValue->value->getType() != argType->llvmRefType(compiler, result)) {
//                result.addError(loc, CErrorCode::TypeMismatch, "value does not match");
//                return nullptr;
//            }
//         
//            argReturnValue->retainIfNeeded(compiler, result, builder);
//            argReturnValues.push_back(argReturnValue);
//            auto paramPtr = getArgumentPointer(compiler, result, calleeInEntry, calleeValue, argIndex, builder);
//            builder->CreateStore(argReturnValue->value, paramPtr);
//            
//            argIndex++;
//        }
//        
//        // Add "parent" to "this"
//        auto hasParent = getHasParent(compiler, result);
//        shared_ptr<ReturnValue> dotReturnValue;
//        if (hasParent) {
//            Value* parentValue = thisValue;
//            if (dotVar) {
//                dotReturnValue = dotVar->getLoadValue(compiler, result, thisVar, thisValue, true, thisValue, builder, catchBB, RRT_Auto);
//                parentValue = dotReturnValue->value;
//            } else {
//                // if recursively calling ourselves then re-use parent
//                if (shared_from_this() == thisFunction) {
//                    parentValue = getParentValue(compiler, result, builder, true, parentValue);
//                } else {
//                    auto temp = static_pointer_cast<CBaseFunction>(thisFunction);
//                    while (temp && temp != parent.lock()) {
//                        parentValue = temp->getParentValue(compiler, result, builder, true, parentValue);
//                        temp = temp->parent.lock();
//                    }
//                }
//            }
//            
//            auto paramPtr = getParentPointer(compiler, result, builder, calleeInEntry, calleeValue);
//            builder->CreateStore(parentValue, paramPtr, "parent");
//        }
//        
//        vector<Value *> argsV;
//        argsV.push_back(calleeValue);
//        auto func = getFunction(compiler, result, calleeVar);
//        
//        auto returnType = getReturnType(compiler, result, calleeVar);
//        auto returnFunction = returnType->parent.lock();
//        Value* returnValue = nullptr;
//        if (catchBB) {
//            auto continueBB = BasicBlock::Create(compiler->context);
//            returnValue = builder->CreateInvoke(func, continueBB, catchBB, argsV);
//            
//            Function *function = builder->GetInsertBlock()->getParent();
//            function->getBasicBlockList().push_back(continueBB);
//            builder->SetInsertPoint(continueBB);
//        } else {
//            returnValue = builder->CreateCall(func, argsV);
//        }
//        
//        auto mustRelease = calleeFunction->getReturnMustRelease(compiler, result);
//
//        if (returnType == calleeType) {
//            assert(!mustRelease);
//            mustRelease = true;
//            // If calleeType is returnType then the function is returning "this", make the caller free it
//        } else if (calleeFunction) {
//            // Release "this" value
//            if (calleeHeapVar) {
//                calleeFunction->releaseHeap(compiler, result, builder, calleeValue);
//            } else {
//                calleeFunction->releaseStack(compiler, result, builder, calleeValue);
//            }
//        }
//        
//        if (dotReturnValue) {
//            dotReturnValue->releaseIfNeeded(compiler, result, builder);
//        }
//        
//        return make_shared<ReturnValue>(returnFunction, mustRelease ? RVR_MustRelease : RVR_MustRetain, returnFunction ? RVT_HEAP : RVT_SIMPLE, false, returnValue);
//    }
//}

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
            ss << alloc_mode(compiler, result, thisVar, it);
            ss << it->name;
            ss << "'" << it->getType(compiler, result)->name;
            ss << (it->isMutable ? "=" : ":");
        }
    }
    
    ss << ")";
    
    if (block) {
        ss << " ";
        block->dump(compiler, result, shared_from_this(), thisVar, functions, ss, level);
    }
}

//shared_ptr<ReturnValue> CFunction::cast(Compiler* compiler, CResult& result, IRBuilder<>* builder, shared_ptr<ReturnValue> fromValue, bool isHeap, shared_ptr<CInterface> interface) {
//    if (!interfaces) {
//        result.addError(loc, CErrorCode::InterfaceDoesNotExist, "function does not implement interface '%s'", interface->name.c_str());
//        return nullptr;
//    }
//
//    bool foundInterface = false;
//    for (auto it : *interfaces) {
//        if (it == interface) {
//            foundInterface = true;
//        }
//    }
//    
//    if (!foundInterface) {
//        result.addError(loc, CErrorCode::InterfaceDoesNotExist, "function does not implement interface '%s'", interface->name.c_str());
//        return nullptr;
//    }
//    
//    // get all function pointers for the interface
//    // TODO: cache function list
//    vector<Function*> interfaceMethods = vector<Function*>();
//    for (auto it : interface->methods) {
//        auto cfunc = static_pointer_cast<CFunction>(getCFunction(compiler, result, it->name, nullptr, nullptr));
//        if (!cfunc) {
//            result.addError(loc, CErrorCode::InterfaceMethodDoesNotExist, "cannot find interface method: '%s'", it->name.c_str());
//            return nullptr;
//        }
//        
//        assert(!cfunc->getHasThis());
//        assert(cfunc->getHasParent(compiler, result));
//        
//        auto fun = cfunc->getFunction(compiler, result, nullptr);
//        auto returnType = cfunc->getReturnType(compiler, result, nullptr);
//        if (!returnType->parent.expired()) {
//            assert(cfunc->getReturnMustRelease(compiler, result));
//        }
//
//        // TODO: Verify func type matches
//        interfaceMethods.push_back(fun);
//    }
//    
//    // pass function pointers & fromValue into interface::cast
//    return interface->cast(compiler, result, builder, fromValue, isHeap, interfaceMethods);
//}



void CFunction::createThisVar(Compiler* compiler, CResult& result, shared_ptr<CVar>& thisVar) {
    thisVar = CNormalVar::createThisVar(loc, shared_from_this(), getThisType(compiler, result));
    getVarBody(compiler, result, thisVar);
    setHeapVarBody(compiler, result, thisVar);

    if (interfaces) {
        // Make all functions used by an interface are defined
        for (auto interface : *interfaces) {
            for (auto it : interface->methods) {
                auto cfunc = static_pointer_cast<CFunction>(getCFunction(compiler, result, it->name, nullptr, nullptr));
                if (!cfunc) {
                    result.addError(loc, CErrorCode::InterfaceMethodDoesNotExist, "cannot find interface method: '%s'", it->name.c_str());
                    return;
                }
                
                assert(!cfunc->getHasThis());
                cfunc->setHasParent(compiler, result); // All interface methods must take the parent has first pointer even if they don't need it
                cfunc->getVarBody(compiler, result, nullptr);
                cfunc->setHeapVarBody(compiler, result, nullptr);
            }
        }
    }
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
        
        if (returnType == nullptr && type == FT_Extern) {
            result.addError(loc, CErrorCode::InvalidFunction, "extern function must specify return type");
            returnType = nullptr;
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
    if (type == FT_Extern) {
        return false;
    }
    
    if (!hasRefCount) {
        return false;
    }
    
    return true;
}

shared_ptr<CType> CFunction::getThisType(Compiler* compiler, CResult& result) {
    if (!thisType) {
        thisType = make_shared<CType>(name.c_str(), shared_from_this());
    }
    
    return thisType;
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
            auto parentType = parent.lock()->getThisType(compiler, result);
            ctypeList->push_back(make_pair("_parent", parentType));
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

//shared_ptr<vector<Type*>> CFunction::getTypeList(Compiler* compiler, CResult& result) {
//    if (!typeList) {
//        typeList = make_shared<vector<Type*>>();
//        
//        if (hasRefCount) {
//            indexRefCount = typeList->size();
//            typeList->push_back(Type::getInt64Ty(compiler->context));
//        }
//        
//        if (hasParent) {
//            indexParent = typeList->size();
//            auto parentType = parent.lock()->getThisType(compiler, result);
//            auto parentLLVMType = parentType->llvmRefType(compiler, result);
//            assert(parentLLVMType);
//            typeList->push_back(parentLLVMType);
//        }
//        
//        indexVars = typeList->size();
//        for (auto it : thisVars) {
//            auto ctype = it->getType(compiler, result);
//            if (!ctype) {
//                result.addError(it->nassignment->loc, CErrorCode::InvalidType, "cannot determine type for '%s'", it->name.c_str());
//                return nullptr;
//            }
//            auto llvmType = ctype->llvmRefType(compiler, result);
//            assert(llvmType);
//            typeList->push_back(llvmType);
//        }
//    }
//    return typeList;
//}
//
//Type* CFunction::getStructType(Compiler* compiler, CResult& result) {
//    if (!getHasThis()) {
//        return nullptr;
//    }
//    
//    if (!_structType) {
//        _structType = StructType::create(compiler->context, name);
//        auto typeList = getTypeList(compiler, result);
//        _structType->setBody(ArrayRef<Type *>(*typeList.get()));
//    }
//    return _structType;
//}
//
//Function* CFunction::getFunction(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
//    assert(compiler->state == CompilerState::Compile);
//    
//    if (isInGetFunction) {
//        result.addError(loc, CErrorCode::TypeLoop, "while trying to determine type a cycle was detected");
//        return nullptr;
//    }
//    
//    if (!function) {
//        isInGetFunction = true;
//        function = compileDefinition(compiler, result, thisVar);
//        isInGetFunction = false;
//        
//        if (function) {
//            returnMustRelease = compileBody(compiler, result, thisVar, function);
//        }
//    }
//    
//    return function;
//}

bool CFunction::getReturnMustRelease(Compiler* compiler, CResult& result) {
    //assert(function);
    return returnMustRelease;
}

//Function* CFunction::getDestructor(Compiler* compiler, CResult& result) {
//    if (!destructorFunction) {
//        destructorFunction = compileDestructorDefinition(compiler, result);
//        if (destructorFunction) {
//            compileDestructorBody(compiler, result, destructorFunction);
//        }
//    }
//    
//    return destructorFunction;
//}
//
//Value* CFunction::getThisArgument(Compiler* compiler, CResult& result) {
//    assert(getHasThis());
//    return (Argument*)function->args().begin();
//}
//
//Value* CFunction::getArgumentPointer(Compiler* compiler, CResult& result, bool thisInEntry, Value* thisValue, int index, IRBuilder<>* builder) {
//    if (thisInEntry) {
//        auto function = getFunctionFromBuilder(builder);
//        auto it = argumentPointers[function][thisValue].find(index);
//        if (it == argumentPointers[function][thisValue].end()) {
//            Value* argValue = nullptr;
//            auto entryBuilder = compiler->getEntryBuilder(function);
//            if (getHasThis()) {
//                assert(thisValue->getType() == thisType->llvmRefType(compiler, result));
//                vector<Value*> v;
//                v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
//                v.push_back(ConstantInt::get(compiler->context, APInt(32, index + getArgStart(compiler, result))));
//                argValue = entryBuilder->CreateInBoundsGEP(thisType->llvmAllocType(compiler, result), thisValue, ArrayRef<Value *>(v), "paramPtr");
//            } else {
//                auto t = (Argument*)std::next(function->args().begin(), index + indexVars);
//                auto argType = thisVars[index]->getType(compiler, result);
//                argValue = entryBuilder->CreateAlloca(argType->llvmRefType(compiler, result));
//                entryBuilder->CreateStore(t, argValue);
//            }
//            argumentPointers[function][thisValue][index] = argValue;
//            return argValue;
//        } else {
//            return it->second;
//        }
//    } else {
//        assert(getHasThis());
//        assert(thisValue->getType() == thisType->llvmRefType(compiler, result));
//        vector<Value*> v;
//        v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
//        v.push_back(ConstantInt::get(compiler->context, APInt(32, index + getArgStart(compiler, result))));
//        return builder->CreateInBoundsGEP(thisType->llvmAllocType(compiler, result), thisValue, ArrayRef<Value *>(v), "paramPtr");
//    }
//}

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
    auto def = static_pointer_cast<CFunctionDefinition>(definition.lock());
    auto t = def->interfacesByName.find(name);
    if (t != def->interfacesByName.end()) {
        auto interfaceDef = t->second;
        
        vector<shared_ptr<CType>> templateTypes;
        if (!getTemplateTypes(compiler, result, loc, shared_from_this(), callerFunction, templateTypeNames, interfaceDef->ninterface->templateTypeNames, templateTypes)) {
            return nullptr;
        }
        
        return interfaceDef->getInterface(compiler, result, templateTypes, shared_from_this());
    }
    return nullptr;
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

int CFunction::getArgStart(Compiler* compiler, CResult& result) {
    getThisType(compiler, result);
    return (int)indexVars;
}

shared_ptr<CType> CFunction::getVarType(Compiler* compiler, CResult& result, shared_ptr<CTypeName> typeName) {
    if (typeName->category == CTC_Interface) {
        auto interface = getCInterface(compiler, result, typeName->name, nullptr, typeName->templateTypeNames);
        if (interface) {
            return interface->getThisType(compiler, result);
        }
    } else {
        assert(typeName->category == CTC_Value);
        if (typeName->templateTypeNames == nullptr) {
            auto t = templateTypesByName.find(typeName->name);
            if (t != templateTypesByName.end()) {
                return t->second;
            }
        }
        
        auto functionDefinition = static_pointer_cast<CFunctionDefinition>(definition.lock());
        auto t2 = functionDefinition->funcsByName.find(typeName->name);
        if (t2 != functionDefinition->funcsByName.end()) {
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
            
            auto cfunc = t2->second->getFunction(compiler, result, loc, templateTypes, shared_from_this());
            return cfunc->getThisType(compiler, result);
        }
    }
    
    if (!parent.expired()) {
        return parent.lock()->getVarType(compiler, result, typeName);
    }
    
    if (typeName->category == CTC_Value) {
        return compiler->getType(typeName->name);
    }
    return nullptr;
}

//Value* CFunction::getParentPointer(Compiler* compiler, CResult& result, IRBuilder<>* builder, bool thisInEntry, Value* thisValue) {
//    assert(hasParent);
//    if (thisInEntry) {
//        auto function = getFunctionFromBuilder(builder);
//        auto it = parentPointers.find(function);
//        if (it == parentPointers.end()) {
//            Value* parentValue = nullptr;
//            if (getHasThis()) {
//                vector<Value*> v;
//                v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
//                v.push_back(ConstantInt::get(compiler->context, APInt(32, indexParent)));
//                parentValue = compiler->getEntryBuilder(function)->CreateInBoundsGEP(thisType->llvmAllocType(compiler, result), thisValue, ArrayRef<Value *>(v), "parent");
//            } else {
//                auto entryBuilder = compiler->getEntryBuilder(function);
//                auto t = (Argument*)std::next(function->args().begin(), indexParent);
//                auto argType = parent.lock()->getThisType(compiler, result);
//                parentValue = entryBuilder->CreateAlloca(argType->llvmRefType(compiler, result));
//                entryBuilder->CreateStore(t, parentValue);
//            }
//            parentPointers[function] = parentValue;
//            return parentValue;
//        } else {
//            return it->second;
//        }
//    } else {
//        assert(getHasThis());
//        vector<Value*> v;
//        v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
//        v.push_back(ConstantInt::get(compiler->context, APInt(32, indexParent)));
//        return builder->CreateInBoundsGEP(thisType->llvmAllocType(compiler, result), thisValue, ArrayRef<Value *>(v), "parent");
//    }
//}
//
//Value* CFunction::getParentValue(Compiler* compiler, CResult& result, IRBuilder<>* builder, bool thisInEntry, Value* thisValue) {
//    assert(hasParent);
//    if (thisInEntry) {
//        auto function = getFunctionFromBuilder(builder);
//        auto it = parentValues.find(function);
//        if (it == parentValues.end()) {
//            auto parentPointer = getParentPointer(compiler, result, builder, thisInEntry, thisValue);
//            auto parentValue = compiler->getEntryBuilder(function)->CreateLoad(parentPointer, "parent");
//            parentValues[function] = parentValue;
//            return parentValue;
//        } else {
//            return it->second;
//        }
//    } else {
//        auto parentPointer = getParentPointer(compiler, result, builder, thisInEntry, thisValue);
//        return builder->CreateLoad(parentPointer, "parent");
//    }
//}
//
//Value* CFunction::getRefCount(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
//    assert(_structType);
//    assert(hasRefCount);
//    if (hasRefCount) {
//        vector<Value*> v;
//        v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
//        v.push_back(ConstantInt::get(compiler->context, APInt(32, indexRefCount)));
//        return builder->CreateInBoundsGEP(thisType->llvmAllocType(compiler, result), thisValue, ArrayRef<Value *>(v), "refCount");
//    }
//    return nullptr;
//}

shared_ptr<CFunctionDefinition> CFunctionDefinition::create(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> parent, CFunctionType type, const string& name, shared_ptr<vector<pair<shared_ptr<CInterfaceDefinition>, shared_ptr<CTypeNameList>>>> interfaceDefinitions, shared_ptr<NFunction> node) {
    auto c = make_shared<CFunctionDefinition>();
    c->parent = parent;
    c->type = type;
    c->name = name;
    c->interfaceDefinitions = interfaceDefinitions;
    c->node = node;
    
    if (node) {
        for (auto it : node->functions) {
            assert(type != FT_Extern && "Not allowed for extern functions");
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
    auto it = cfunctions.find(templateTypes);
    if (it != cfunctions.end()) {
        func = it->second;
    } else {
        assert(funcParent.expired() || funcParent.lock()->definition.lock() == parent.lock());
        
        shared_ptr<vector<shared_ptr<CInterface>>> interfaces;
        if (interfaceDefinitions) {
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

        if (interfaceDefinitions) {
            for (auto it : *interfaceDefinitions) {
                vector<shared_ptr<CType>> interfaceTemplateTypes;
                if (!it.first->ninterface) {
                    result.addError(loc, CErrorCode::InterfaceDoesNotExist, "cannot find interface '%s'", it.first->typeName->getName().c_str());
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
        
        cfunctions[templateTypes] = func;
    }
    return func;
}

void CFunctionDefinition::dump(Compiler* compiler, CResult& result, int level) {
    // Skip if this is the function around global
    if (funcsByName.size() > 0) {
        for (auto it : funcsByName) {
            it.second->dump(compiler, result, level);
        }
    }
}
