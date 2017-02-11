#include "Node.h"

int NFunction::counter = 0;

NFunction::NFunction(CLoc loc, CFunctionType type, shared_ptr<CTypeName> returnTypeName, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<NodeList> arguments, shared_ptr<NBase> block, shared_ptr<NBase> catchBlock, shared_ptr<NBase> destroyBlock) : type(type), returnTypeName(returnTypeName), name(name), templateTypeNames(templateTypeNames), block(block), catchBlock(catchBlock), destroyBlock(destroyBlock), isInGetType(false), NBase(NodeType_Function, loc) {
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

NFunction::NFunction(CLoc loc, CFunctionType type, const char* externName, shared_ptr<CTypeName> returnTypeName, const char* name, shared_ptr<NodeList> arguments): type(type), externName(externName), returnTypeName(returnTypeName), name(name), NBase(NodeType_Function, loc) {
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


void NFunction::defineImpl(Compiler *compiler, CResult& result, shared_ptr<CFunctionDefinition> parentFunction) {
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
        
        auto thisFunction = CFunctionDefinition::create(compiler, result, parentFunction, type, name, shared_from_this());
        parentFunction->funcsByName[name] = thisFunction;
        
        for (auto it : assignments) {
            it->define(compiler, result, thisFunction);
        }
        
        if (block) {
            block->define(compiler, result, thisFunction);
        }
    } else {
        auto thisFunction = CFunctionDefinition::create(compiler, result, parentFunction, type, name, shared_from_this());
        parentFunction->funcsByName[name] = thisFunction;

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

shared_ptr<CVar> NFunction::getVarImpl(Compiler *compiler, CResult& result, shared_ptr<CFunction> parentFunction, shared_ptr<CVar> parentVar) {
    return nullptr;
}

shared_ptr<CType> NFunction::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> parentFunction, shared_ptr<CVar> parentVar) {
    assert(compiler->state >= CompilerState::FixVar);
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return nullptr;
    }
    
    return compiler->typeVoid;
}

shared_ptr<ReturnValue> NFunction::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> parentFunction, shared_ptr<CVar> parentVar, Value* parentValue, IRBuilder<>* builder, BasicBlock* parentCatchBB) {
    return nullptr;
}

shared_ptr<CVar> NFunction::getReturnVar(Compiler *compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    if (block) {
        return block->getVar(compiler, result, thisFunction, thisVar);
    }
    return nullptr;
}

void NFunction::getVarBody(Compiler *compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return;
    }
    
    for (auto it : functions) {
        it->getVar(compiler, result, thisFunction, thisVar);
    }

    for (auto it : assignments) {
        it->getVar(compiler, result, thisFunction, thisVar);
    }
    
    if (block) {
        block->getVar(compiler, result, thisFunction, thisVar);
    }
    
    if (catchBlock) {
        catchBlock->getVar(compiler, result, thisFunction, thisVar);
    }
    
    if (destroyBlock) {
        destroyBlock->getVar(compiler, result, thisFunction, thisVar);
    }
    
    getBlockType(compiler, result, thisFunction, thisVar);
}

int NFunction::setHeapVarBody(Compiler *compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);
    auto count = 0;
    do {
        count = 0;
        for (auto it : functions) {
            count += it->setHeapVar(compiler, result, thisFunction, thisVar, false);
        }
        
        for (auto it : assignments) {
            count += it->setHeapVar(compiler, result, thisFunction, thisVar, false);
        }
        
        if (block) {
            count += block->setHeapVar(compiler, result, thisFunction, thisVar, true);
        }
        
        if (catchBlock) {
            count += catchBlock->setHeapVar(compiler, result, thisFunction, thisVar, true);
        }
        
        if (destroyBlock) {
            count += destroyBlock->setHeapVar(compiler, result, thisFunction, thisVar, true);
        }
    } while (count > 0);
    return 0;
}

shared_ptr<CType> NFunction::getBlockType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    assert(thisFunction->node.get() == this);
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return nullptr;
    }

    if (returnTypeName) {
        shared_ptr<CType> valueType = thisFunction->getVarType(compiler, result, loc, returnTypeName);
        if (!valueType) {
            result.addError(loc, CErrorCode::InvalidType, "explicit type '%s' does not exist", returnTypeName->name.c_str());
            return nullptr;
        }
        return valueType;
    }

    if (type == FT_Extern) {
        result.addError(loc, CErrorCode::InvalidFunction, "extern function must specify return type");
        return nullptr;
    }
    
    if (block) {
        if (isInGetType) {
            result.addError(CLoc::undefined, CErrorCode::TypeLoop, "while trying to determine type a cycle was detected");
            return nullptr;
        }
        
        isInGetType = true;
        auto type = block->getType(compiler, result, thisFunction, thisVar);
        isInGetType = false;
        return type;
    }
    
    return compiler->typeVoid;
}

Function* NFunction::compileDefinition(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::Compile);
    assert(thisFunction->node.get() == this);

    auto returnType = getBlockType(compiler, result, thisFunction, thisVar);
    if (!returnType) {
        return nullptr;
    }
    
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return nullptr;
    }
    
    if (type == FT_Extern) {
        vector<Type*> argTypes;
        for (auto it : thisFunction->thisVars) {
            auto ctype = it->getType(compiler, result);
            if (!ctype) {
                result.addError(it->nassignment->loc, CErrorCode::InvalidType, "cannot determine type for '%s'", it->name.c_str());
                return nullptr;
            }
            
            argTypes.push_back(ctype->llvmRefType(compiler, result));
        }
        
        auto functionType = FunctionType::get(returnType->llvmRefType(compiler, result), argTypes, false);
        return Function::Create(functionType, Function::ExternalLinkage, externName.c_str(), compiler->module.get());
    } else {
        vector<Type*> argTypes;
        argTypes.push_back(thisFunction->getThisType(compiler, result)->llvmRefType(compiler, result));
        auto functionType = FunctionType::get(returnType->llvmRefType(compiler, result), argTypes, false);
        auto function = Function::Create(functionType, type == FT_Public ? Function::ExternalLinkage : Function::PrivateLinkage, name.c_str(), compiler->module.get());
        function->args().begin()->setName("this");
        function->setPersonalityFn(compiler->exception->getPersonality());
        
#ifdef DWARF_ENABLED
        SmallVector<Metadata *, 8> EltTys;
        for (auto &argType : argTypes) {
            EltTys.push_back(compiler->getDIType(argType));
        }
        auto ditypes = compiler->DBuilder->createSubroutineType(compiler->DBuilder->getOrCreateTypeArray(EltTys));
        
        // Create a subprogram DIE for this function.
        DIFile *Unit = compiler->DBuilder->createFile(compiler->TheCU->getFilename(), compiler->TheCU->getDirectory());
        DIScope *FContext = Unit;
        unsigned LineNo = node->loc.line;
        unsigned ScopeLine = LineNo;
        DISubprogram *SP = compiler->DBuilder->createFunction(FContext, node->name.c_str(), StringRef(), Unit, LineNo, ditypes, false /* internal linkage */, true /* definition */, ScopeLine, DINode::FlagPrototyped, false);
        func->setSubprogram(SP);
        
        // Push the current scope.
        compiler->LexicalBlocks.push_back(SP);
        
        // Unset the location for the prologue emission (leading instructions with no
        // location in a function are considered part of the prologue and the debugger
        // will run past them when breaking on a function)
        compiler->emitLocation(nullptr);
#endif
        return function;
    }
}

bool NFunction::compileBody(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, Function* function) {
    assert(compiler->state == CompilerState::Compile);
    assert(thisFunction->node.get() == this);
    
    if (!block) {
        return false;
    }
    
    // Create body of function
    // Create a new basic block to start insertion into.
    auto basicBlock = BasicBlock::Create(compiler->context, "entry", function);
    IRBuilder<> newBuilder(basicBlock);
    shared_ptr<ReturnValue> returnValue = nullptr;
    Argument* thisArgument = nullptr;
    shared_ptr<CVar> returnVar = nullptr;
    auto returnType = block->getType(compiler, result, thisFunction, thisVar);
    auto returnFunction = returnType->parent.expired() ? nullptr : returnType->parent.lock();
    
    compiler->callPushFunction(&newBuilder, name);
    
    BasicBlock* catchBB = nullptr;
    if (catchBlock) {
        catchBB = BasicBlock::Create(compiler->context, "catch", function);
    }
    
    thisArgument = (Argument*)function->args().begin();
    returnVar = block->getVar(compiler, result, thisFunction, thisVar);
    returnValue = block->compile(compiler, result, thisFunction, thisVar, thisArgument, &newBuilder, catchBB);

    compiler->callPopFunction(&newBuilder);
    
    if (function->getReturnType()->isVoidTy()) {
        newBuilder.CreateRetVoid();
    } else {
        if (!returnValue) {
            result.addError(loc, CErrorCode::TypeMismatch, "no return for non-void function");
            goto error;
        }
        
        if (function->getReturnType() != returnValue->value->getType()) {
            result.addError(loc, CErrorCode::TypeMismatch, "return type '%s' does not match return value type '%s'", Type_print(function->getReturnType()).c_str(), Type_print(returnValue->value->getType()).c_str());
            goto error;
        }
        
        // Store return value, before releasing everything
        auto entryBuilder = getEntryBuilder(&newBuilder);
        auto returnAlloca = entryBuilder.CreateAlloca(returnValue->value->getType());
        newBuilder.CreateStore(returnValue->value, returnAlloca);

        auto releaseBlock = BasicBlock::Create(compiler->context, "release", function);
        newBuilder.CreateBr(releaseBlock);
        newBuilder.SetInsertPoint(releaseBlock);
        
        // Release all of the local vars
        for (auto it : thisFunction->localVarsByName) {
            auto type = it.second->getType(compiler, result);
            if (!type->parent.expired()) {
                auto localValue = it.second->getLoadValue(compiler, result, thisVar, thisArgument, nullptr, &newBuilder, catchBB);
                if (localValue->type == RVT_HEAP) {
                    assert(!localValue->mustRelease);
                    if (it.second->getHeapVar(compiler, result, thisVar)) {
                        type->parent.lock()->releaseHeap(compiler, result, &newBuilder, localValue->value);
                    } else {
                        type->parent.lock()->releaseStack(compiler, result, &newBuilder, localValue->value);
                    }
                }
            }
        }
        
        auto returnBlock = BasicBlock::Create(compiler->context, "return", function);
        newBuilder.CreateBr(returnBlock);
        newBuilder.SetInsertPoint(returnBlock);
        newBuilder.CreateRet(newBuilder.CreateLoad(returnAlloca));
    }
    
    if (catchBlock) {
        IRBuilder<> catchBuilder(catchBB);
        
        llvm::Type *caughtResultFieldTypes[] = {
            catchBuilder.getInt8PtrTy(),
            catchBuilder.getInt32Ty()
        };
        auto caughtResultType = llvm::StructType::get(compiler->context, ArrayRef<Type*>(caughtResultFieldTypes));
        auto caughtResult = catchBuilder.CreateLandingPad(caughtResultType, 1);
        caughtResult->addClause(compiler->module->getGlobalVariable("sjExceptionType"));
        // Value *unwindException = catchBuilder.CreateExtractValue(caughtResult, 0);
        // Value *retTypeInfoIndex = catchBuilder.CreateExtractValue(caughtResult, 1);
        
        auto thisArgument = (Argument*)function->args().begin();
        returnVar = catchBlock->getVar(compiler, result, thisFunction, thisVar);
        auto catchReturnValue = catchBlock->compile(compiler, result, thisFunction, thisVar, thisArgument, &catchBuilder, nullptr);
        if (function->getReturnType()->isVoidTy()) {
            catchBuilder.CreateRetVoid();
        } else {
            if (!catchReturnValue) {
                result.addError(loc, CErrorCode::TypeMismatch, "no return for non-void function");
                goto error;
            }
            
            if (function->getReturnType() != catchReturnValue->value->getType()) {
                result.addError(loc, CErrorCode::TypeMismatch, "return type '%s' does not match return value type '%s'", Type_print(function->getReturnType()).c_str(), Type_print(catchReturnValue->value->getType()).c_str());
                goto error;
            }
            
            assert(catchReturnValue->type == returnValue->type);
            assert(catchReturnValue->mustRelease == returnValue->mustRelease);
            catchBuilder.CreateRet(catchReturnValue->value);
        }
    }
    
error:
    if (catchBB) {
        function->getBasicBlockList().remove(catchBB);
        function->getBasicBlockList().push_back(catchBB);
    }
    
    // Validate the generated code, checking for consistency.
    if (result.errors.size() == 0 && verifyFunction(*function)) {
        // compiler->module->dump();
        function->dump();
        auto output = new raw_os_ostream(std::cout);
        verifyFunction(*function, output);
        output->flush();
        assert(false);
    }
    
    assert(!returnValue || returnValue->type == RVT_SIMPLE || returnValue->type == RVT_HEAP);
    return returnValue ? returnValue->mustRelease : false;
}

Function* NFunction::compileDestructorDefinition(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::Compile);
    assert(thisFunction->node.get() == this);
    
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return nullptr;
    }
    
    if (type == FT_Extern) {
        return nullptr;
    }
    
    auto hasDestructor = destroyBlock != nullptr;
    for (auto it : thisFunction->thisVars) {
        if (!it->getType(compiler, result)->parent.expired()) {
            hasDestructor = true;
        }
    }
    
    if (!hasDestructor) {
        return nullptr;
    }
    
    vector<Type*> argTypes;
    argTypes.push_back(thisFunction->getThisType(compiler, result)->llvmRefType(compiler, result));
    auto functionType = FunctionType::get(Type::getVoidTy(compiler->context), argTypes, false);
    auto function = Function::Create(functionType, type == FT_Public ? Function::ExternalLinkage : Function::PrivateLinkage, strprintf("%s_destructor", name.c_str()).c_str(), compiler->module.get());
    function->args().begin()->setName("this");
    
#ifdef DWARF_ENABLED
    SmallVector<Metadata *, 8> EltTys;
    for (auto &argType : argTypes) {
        EltTys.push_back(compiler->getDIType(argType));
    }
    auto ditypes = compiler->DBuilder->createSubroutineType(compiler->DBuilder->getOrCreateTypeArray(EltTys));
    
    // Create a subprogram DIE for this function.
    DIFile *Unit = compiler->DBuilder->createFile(compiler->TheCU->getFilename(), compiler->TheCU->getDirectory());
    DIScope *FContext = Unit;
    unsigned LineNo = node->loc.line;
    unsigned ScopeLine = LineNo;
    DISubprogram *SP = compiler->DBuilder->createFunction(FContext, node->name.c_str(), StringRef(), Unit, LineNo, ditypes, false /* internal linkage */, true /* definition */, ScopeLine, DINode::FlagPrototyped, false);
    func->setSubprogram(SP);
    
    // Push the current scope.
    compiler->LexicalBlocks.push_back(SP);
    
    // Unset the location for the prologue emission (leading instructions with no
    // location in a function are considered part of the prologue and the debugger
    // will run past them when breaking on a function)
    compiler->emitLocation(nullptr);
#endif
    return function;
}

void NFunction::compileDestructorBody(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Function* function) {
    assert(compiler->state == CompilerState::Compile);
    assert(thisFunction->node.get() == this);
    
    // Create body of function
    // Create a new basic block to start insertion into.
    auto basicBlock = BasicBlock::Create(compiler->context, "entry", function);
    IRBuilder<> newBuilder(basicBlock);
    shared_ptr<ReturnValue> returnValue = nullptr;
    Argument* thisArgument = (Argument*)function->args().begin();
    
    if (destroyBlock) {
        destroyBlock->compile(compiler, result, thisFunction, nullptr, thisArgument, &newBuilder, nullptr);
    }
    
    for (auto it : thisFunction->thisVars) {
        if (!it->getType(compiler, result)->parent.expired()) {
            auto value = it->getLoadValue(compiler, result, nullptr, thisArgument, thisArgument, &newBuilder, nullptr);
            if (value->type == RVT_HEAP) {
                if (it->getHeapVar(compiler, result, nullptr)) {
                    value->valueFunction->releaseHeap(compiler, result, &newBuilder, value->value);
                } else {
                    value->valueFunction->releaseStack(compiler, result, &newBuilder, value->value);
                }
            }
        }
    }
    
    newBuilder.CreateRetVoid();
}

shared_ptr<ReturnValue> NFunction::call(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, shared_ptr<CFunction> callee, shared_ptr<CVar> calleeVar, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters) {
    if (type == FT_Extern) {
        vector<shared_ptr<ReturnValue>> argReturnValues;
        vector<Value *> argValues;
        auto func = callee->getFunction(compiler, result, calleeVar);
        
        // Fill in "this" with normal arguments
        auto argIndex = 0;
        for (auto defaultAssignment : assignments) {
            auto argVar = callee->thisVars[argIndex];
            auto argHeapVar = argVar->getHeapVar(compiler, result, thisVar);
            
            assert(defaultAssignment->inFunctionDeclaration);
            auto argType = defaultAssignment->getType(compiler, result, thisFunction, thisVar);
            auto isDefaultAssignment = parameters[argIndex] == defaultAssignment->rightSide;
            shared_ptr<ReturnValue> argReturnValue;
            
            if (isDefaultAssignment) {
                auto paramVar = parameters[argIndex]->getVar(compiler, result, callee, calleeVar);
                if (paramVar) {
                    auto paramHeapVar = paramVar->getHeapVar(compiler, result, thisVar);
                    assert(paramHeapVar == argHeapVar);
                }
                argReturnValue = parameters[argIndex]->compile(compiler, result, callee, calleeVar, nullptr, builder, catchBB);
            } else {
                auto paramVar = parameters[argIndex]->getVar(compiler, result, thisFunction, thisVar);
                if (paramVar) {
                    auto paramHeapVar = paramVar->getHeapVar(compiler, result, thisVar);
                    assert(paramHeapVar == argHeapVar);
                }
                argReturnValue = parameters[argIndex]->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB);
            }
            
            if (!argReturnValue) {
                result.addError(CLoc::undefined, CErrorCode::TypeMismatch, "value is empty");
                return nullptr;
            }
            
            if (argReturnValue->value->getType() != argType->llvmRefType(compiler, result)) {
                result.addError(CLoc::undefined, CErrorCode::TypeMismatch, "value does not match");
                return nullptr;
            }
            
            argReturnValues.push_back(argReturnValue);
            argValues.push_back(argReturnValue->value);
            argIndex++;
        }
        
        auto returnType = callee->getReturnType(compiler, result, calleeVar);
        auto returnFunction = returnType->parent.lock();
        auto returnValue = builder->CreateCall(func, argValues);
        for (auto it : argReturnValues) {
            it->releaseIfNeeded(compiler, result, builder);
        }
        
        // All extern function must return a var that needs to be released
        return make_shared<ReturnValue>(returnFunction, returnFunction ? true : false, returnFunction ? RVT_HEAP : RVT_SIMPLE, returnValue);
    } else {
        vector<shared_ptr<ReturnValue>> argReturnValues;

        // Create this on stack, and get a pointer
        Value* calleeValue = nullptr;
        auto calleeType = callee->getThisType(compiler, result);
        auto calleeHeapVar = calleeVar->getHeapVar(compiler, result, thisVar);
        auto calleeFunction = calleeVar->getCFunctionForValue(compiler, result);

        if (calleeHeapVar) {
            // heap alloc this
            auto allocFunc = compiler->getAllocFunction();
            
            // Compute the size of the struct by getting a pointer to the second element from null
            vector<Value*> v;
            v.push_back(ConstantInt::get(compiler->context, APInt(32, 1)));
            auto thisPointerType = calleeType->llvmAllocType(compiler, result)->getPointerTo();
            auto nullPtr = ConstantPointerNull::get(thisPointerType);
            auto sizePtr = builder->CreateGEP(nullPtr, ArrayRef<llvm::Value *>(v));
            auto sizeValue = builder->CreatePtrToInt(sizePtr, Type::getInt64Ty(compiler->context));
            
            // Allocate and mutate to correct type
            vector<Value*> allocArgs;
            allocArgs.push_back(sizeValue);
            auto calleeValueAsVoidPtr = builder->CreateCall(allocFunc, allocArgs);
            calleeValue = builder->CreateBitCast(calleeValueAsVoidPtr, thisPointerType);
            calleeFunction->initHeap(compiler, result, builder, calleeValue);
        } else {
            // stack alloc this
            auto entryBuilder = getEntryBuilder(builder);
            calleeValue = entryBuilder.CreateAlloca(calleeType->llvmAllocType(compiler, result), 0, calleeType->name.c_str());
            calleeFunction->initStack(compiler, result, builder, calleeValue);
        }
        
        // Fill in "this" with normal arguments
        auto argIndex = 0;
        for (auto defaultAssignment : assignments) {
            auto argVar = callee->thisVars[argIndex];
            auto argHeapVar = argVar->getHeapVar(compiler, result, thisVar);

            assert(defaultAssignment->inFunctionDeclaration);
            auto argType = defaultAssignment->getType(compiler, result, callee, calleeVar);
            auto isDefaultAssignment = parameters[argIndex] == defaultAssignment->rightSide;
            shared_ptr<ReturnValue> argReturnValue;
            if (isDefaultAssignment) {
                auto paramVar = parameters[argIndex]->getVar(compiler, result, callee, calleeVar);
                if (paramVar) {
                    auto paramHeapVar = paramVar->getHeapVar(compiler, result, thisVar);
                    assert(paramHeapVar == argHeapVar);
                }
                argReturnValue = parameters[argIndex]->compile(compiler, result, callee, calleeVar, calleeValue, builder, catchBB);
            } else {
                auto paramVar = parameters[argIndex]->getVar(compiler, result, thisFunction, thisVar);
                if (paramVar) {
                    auto paramHeapVar = paramVar->getHeapVar(compiler, result, thisVar);
                    assert(paramHeapVar == argHeapVar);
                }
                argReturnValue = parameters[argIndex]->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB);
            }
                        
            if (!argReturnValue) {
                result.addError(CLoc::undefined, CErrorCode::TypeMismatch, "value is empty");
                return nullptr;
            }
            
            if (argReturnValue->value->getType() != argType->llvmRefType(compiler, result)) {
                result.addError(CLoc::undefined, CErrorCode::TypeMismatch, "value does not match");
                return nullptr;
            }
         
            argReturnValue->retainIfNeeded(compiler, result, builder);
            argReturnValues.push_back(argReturnValue);
            auto paramPtr = callee->getArgumentPointer(compiler, result, calleeValue, argIndex, builder);
            builder->CreateStore(argReturnValue->value, paramPtr);
            
            argIndex++;
        }
        
        // Add "parent" to "this"
        auto hasParent = callee->getHasParent(compiler, result);
        shared_ptr<ReturnValue> dotReturnValue;
        if (hasParent) {
            Value* parentValue = thisValue;
            if (dotVar) {
                dotReturnValue = dotVar->getLoadValue(compiler, result, thisVar, thisValue, thisValue, builder, catchBB);
                parentValue = dotReturnValue->value;
            } else {
                // if recursively calling ourselves then re-use parent
                if (callee == thisFunction) {
                    auto parentPtr = callee->getParentPointer(compiler, result, builder, parentValue);
                    parentValue = builder->CreateLoad(parentPtr);
                } else {
                    auto temp = thisFunction;
                    while (temp && temp != callee->parent.lock()) {
                        auto parentPtr = temp->getParentPointer(compiler, result, builder, parentValue);
                        parentValue = builder->CreateLoad(parentPtr);
                        temp = temp->parent.lock();
                    }
                }
            }
            
            auto paramPtr = callee->getParentPointer(compiler, result, builder, calleeValue);
            builder->CreateStore(parentValue, paramPtr, "parent");
        }
        
        vector<Value *> argsV;
        argsV.push_back(calleeValue);
        auto func = callee->getFunction(compiler, result, calleeVar);
        
        auto returnType = callee->getReturnType(compiler, result, calleeVar);
        auto returnFunction = returnType->parent.lock();
        Value* returnValue = nullptr;
        if (catchBB) {
            auto continueBB = BasicBlock::Create(compiler->context);
            returnValue = builder->CreateInvoke(func, continueBB, catchBB, argsV);
            
            Function *function = builder->GetInsertBlock()->getParent();
            function->getBasicBlockList().push_back(continueBB);
            builder->SetInsertPoint(continueBB);
        } else {
            returnValue = builder->CreateCall(func, argsV);
        }
        
        auto mustRelease = calleeFunction->getReturnMustRelease(compiler, result);

        if (returnType == calleeType) {
            assert(!mustRelease);
            mustRelease = true;
            // If calleeType is returnType then the function is returning "this", make the caller free it
        } else if (calleeFunction) {
            // Release "this" value
            if (calleeHeapVar) {
                calleeFunction->releaseHeap(compiler, result, builder, calleeValue);
            } else {
                calleeFunction->releaseStack(compiler, result, builder, calleeValue);
            }
        }
        
        if (dotReturnValue) {
            dotReturnValue->releaseIfNeeded(compiler, result, builder);
        }
        
        return make_shared<ReturnValue>(returnFunction, mustRelease, returnFunction ? RVT_HEAP : RVT_SIMPLE, returnValue);
    }
}

void NFunction::dumpBody(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CFunction>, string>& functions, stringstream& ss, int level) {
    ss << thisFunction->fullName(true);
    ss << "(";
    
    if (assignments.size() > 0) {
        auto argIndex = 0;
        for (auto it : assignments) {
            auto argVar = thisFunction->thisVars[argIndex];
            if (it != assignments.front()) {
                printf(", ");
            }
            ss << alloc_mode(compiler, result, thisVar, argVar);
            it->dump(compiler, result, thisFunction, thisVar, functions, ss, level + 1);
            argIndex++;
        }
    }
    
    ss << ")";
    
    if (block) {
        ss << " ";
        block->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
    }
}

