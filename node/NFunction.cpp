#include "Node.h"

int NFunction::counter = 0;

NFunction::NFunction(CLoc loc, CFunctionType type, const char* typeName, const char* name, shared_ptr<TemplateTypeNames> templateTypeNames, shared_ptr<NodeList> arguments, shared_ptr<NBase> block, shared_ptr<NBase> catchBlock) : type(type), typeName(typeName), name(name), templateTypeNames(templateTypeNames), block(block), catchBlock(catchBlock), NBase(loc) {
    if (this->name == "^") {
        this->name = strprintf("anon_%d", counter++);
    }
    
    if (arguments) {
        for (auto it : *arguments) {
            if (it->getNodeType() == NodeType_Assignment) {
                auto nassignment = static_pointer_cast<NAssignment>(it);
                nassignment->inFunctionDeclaration = true;
                assignments.push_back(nassignment);
                
                if (nassignment->nfunction) {
                    functions.push_back(nassignment->nfunction);
                }
            } else if (it->getNodeType() == NodeType_Function) {
                functions.push_back(static_pointer_cast<NFunction>(it));
            } else {
                invalid.push_back(it);
            }
        }
    }
}

NodeType NFunction::getNodeType() const {
    return NodeType_Function;
}

void NFunction::define(Compiler *compiler, CResult& result, shared_ptr<CFunctionDefinition> parentFunction) {
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

void NFunction::fixVar(Compiler *compiler, CResult& result, shared_ptr<CFunction> parentFunction) {
}

void NFunction::fixVarBody(Compiler *compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return;
    }
    
    for (auto it : functions) {
        it->fixVar(compiler, result, thisFunction);
    }

    for (auto it : assignments) {
        it->fixVar(compiler, result, thisFunction);
    }
    
    if (block) {
        block->fixVar(compiler, result, thisFunction);
    }
    
    if (catchBlock) {
        catchBlock->fixVar(compiler, result, thisFunction);
    }
    
    getBlockType(compiler, result, thisFunction);
}

shared_ptr<CType> NFunction::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> parentFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return nullptr;
    }

    return compiler->typeVoid;
}

shared_ptr<CType> NFunction::getBlockType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    assert(thisFunction->node.get() == this);
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return nullptr;
    }

    if (typeName.size() > 0) {
        shared_ptr<CType> valueType = compiler->getType(typeName.c_str());
        if (!valueType) {
            result.addError(loc, CErrorCode::InvalidType, "explicit type does not exist");
            return nullptr;
        }
        return valueType;
    }

    if (type == FT_Extern) {
        result.addError(loc, CErrorCode::InvalidFunction, "extern function must specify return type");
        return nullptr;
    }
    
    if (block) {
        return block->getReturnType(compiler, result, thisFunction);
    }
    
    return compiler->typeVoid;
}

Value* NFunction::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> parentFunction, Value* parentValue, IRBuilder<>* builder, BasicBlock* parentCatchBB) const {
    return nullptr;
}

Function* NFunction::compileDefinition(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state == CompilerState::Compile);
    assert(thisFunction->node.get() == this);

    auto returnType = getBlockType(compiler, result, thisFunction);
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
        return Function::Create(functionType, Function::ExternalLinkage, name.c_str(), compiler->module.get());
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

void NFunction::compileBody(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Function* function) const {
    assert(compiler->state == CompilerState::Compile);
    assert(thisFunction->node.get() == this);
    
    if (!block) {
        return;
    }
    
    // Create body of function
    // Create a new basic block to start insertion into.
    auto basicBlock = BasicBlock::Create(compiler->context, "entry", function);
    IRBuilder<> newBuilder(basicBlock);
    Value *RetVal = nullptr;
    Argument* thisArgument = nullptr;
    
    BasicBlock* catchBB = nullptr;
    if (catchBlock) {
        catchBB = BasicBlock::Create(compiler->context, "catch", function);
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
        Value *RetVal = catchBlock->compile(compiler, result, thisFunction, thisArgument, &catchBuilder, nullptr);
        if (function->getReturnType()->isVoidTy()) {
            catchBuilder.CreateRetVoid();
        } else {
            if (!RetVal) {
                result.addError(loc, CErrorCode::TypeMismatch, "no return for non-void function");
                goto error;
            }
            
            if (function->getReturnType() != RetVal->getType()) {
                result.addError(loc, CErrorCode::TypeMismatch, "return type '%s' does not match return value type '%s'", Type_print(function->getReturnType()).c_str(), Type_print(RetVal->getType()).c_str());
                goto error;
            }
            
            catchBuilder.CreateRet(RetVal);
        } 
    }
    
    thisArgument = (Argument*)function->args().begin();
    RetVal = block->compile(compiler, result, thisFunction, thisArgument, &newBuilder, catchBB);
    if (function->getReturnType()->isVoidTy()) {
        newBuilder.CreateRetVoid();
    } else {
        if (!RetVal) {
            result.addError(loc, CErrorCode::TypeMismatch, "no return for non-void function");
            goto error;
        }
        
        if (function->getReturnType() != RetVal->getType()) {
            result.addError(loc, CErrorCode::TypeMismatch, "return type '%s' does not match return value type '%s'", Type_print(function->getReturnType()).c_str(), Type_print(RetVal->getType()).c_str());
            goto error;
        }

        newBuilder.CreateRet(RetVal);
    }
    
error:
    if (catchBB) {
        function->getBasicBlockList().remove(catchBB);
        function->getBasicBlockList().push_back(catchBB);
    }
    
    // Validate the generated code, checking for consistency.
    if (result.errors.size() == 0 && verifyFunction(*function)) {
        function->dump();
        auto output = new raw_os_ostream(std::cout);
        verifyFunction(*function, output);
        output->flush();
        assert(false);
    }
    
    /*
    compiler->TheFPM->run(*function);
    */
}

Value* NFunction::call(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, shared_ptr<CFunction> callee, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters) {
    if (type == FT_Extern) {
        vector<Value *> argsV;
        auto func = callee->getFunction(compiler, result);
        
        // Fill in "this" with normal arguments
        auto argIndex = 0;
        for (auto defaultAssignment : assignments) {
            assert(defaultAssignment->inFunctionDeclaration);
            auto argType = defaultAssignment->getReturnType(compiler, result, thisFunction);
            auto isDefaultAssignment = parameters[argIndex] == defaultAssignment->rightSide;
            Value* value;
            if (isDefaultAssignment) {
                value = parameters[argIndex]->compile(compiler, result, callee, nullptr, builder, catchBB);
            } else {
                value = parameters[argIndex]->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
            }
            
            if (!value) {
                result.addError(CLoc::undefined, CErrorCode::TypeMismatch, "value is empty");
                return nullptr;
            }
            
            if (value->getType() != argType->llvmRefType(compiler, result)) {
                result.addError(CLoc::undefined, CErrorCode::TypeMismatch, "value does not match");
                return nullptr;
            }
            
            argsV.push_back(value);
            
            argIndex++;
        }
        
        return builder->CreateCall(func, argsV);
    } else {
        // Create this on stack, and get a pointer
        auto newType = callee->getThisType(compiler, result);
        auto entryBuilder = getEntryBuilder(builder);
        auto newValue = entryBuilder.CreateAlloca(newType->llvmAllocType(compiler, result), 0, newType->name.c_str());
        
        // Fill in "this" with normal arguments
        auto argIndex = 0;
        for (auto defaultAssignment : assignments) {
            assert(defaultAssignment->inFunctionDeclaration);
            auto argType = defaultAssignment->getReturnType(compiler, result, callee);
            auto isDefaultAssignment = parameters[argIndex] == defaultAssignment->rightSide;
            Value* value;
            if (isDefaultAssignment) {
                value = parameters[argIndex]->compile(compiler, result, callee, newValue, builder, catchBB);
            } else {
                value = parameters[argIndex]->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
            }
            
            if (!value) {
                result.addError(CLoc::undefined, CErrorCode::TypeMismatch, "value is empty");
                return nullptr;
            }
            
            if (value->getType() != argType->llvmRefType(compiler, result)) {
                result.addError(CLoc::undefined, CErrorCode::TypeMismatch, "value does not match");
                return nullptr;
            }
            
            auto paramPtr = callee->getArgumentPointer(compiler, result, newValue, argIndex, builder);
            builder->CreateStore(value, paramPtr);
            
            argIndex++;
        }
        
        // Add "parent" to "this"
        auto hasParent = callee->getHasParent(compiler, result);
        if (hasParent) {
            Value* parentValue = thisValue;
            if (dotVar) {
                parentValue = dotVar->getLoadValue(compiler, result, thisValue, thisValue, builder, catchBB);
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
            
            auto paramPtr = callee->getParentPointer(compiler, result, builder, newValue);
            builder->CreateStore(parentValue, paramPtr, "parent");
        }
        
        vector<Value *> argsV;
        argsV.push_back(newValue);
        
        auto func = callee->getFunction(compiler, result);
        
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
        
        return returnValue;
    }
}

void NFunction::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NFunction'");
    dumpf(level, "name: '%s'", name.c_str());
    
    if (functions.size() > 0) {
        dumpf(level, "functions: {");
        for (auto it : functions) {
            dumpf(level + 1, "%s: {", it->name.c_str());
            it->dump(compiler, level + 2);
            dumpf(level + 1, "}");
        }
        dumpf(level, "}");
    }
    
    if (assignments.size() > 0) {
        dumpf(level, "assignments: {");
        for (auto it : assignments) {
            dumpf(level + 1, "%s: {", it->name.c_str());
            it->dump(compiler, level + 2);
            dumpf(level + 1, "}");
        }
        dumpf(level, "}");
    }
    
    if (block) {
        dumpf(level, "block: {");
        block->dump(compiler, level + 1);
        dumpf(level, "}");
    }
}

