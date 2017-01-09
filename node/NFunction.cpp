#include "Node.h"

int NFunction::counter = 0;

NFunction::NFunction(CLoc loc, CFunctionType type, const char* typeName, const char* name, NodeList arguments, shared_ptr<NBase> block, shared_ptr<NBase> catchBlock) : type(type), typeName(typeName), name(name), block(block), catchBlock(catchBlock), NBase(loc) {
    if (this->name == "^") {
        this->name = strprintf("anon_%d", counter++);
    }
    
    for (auto it : arguments) {
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

NodeType NFunction::getNodeType() const {
    return NodeType_Function;
}

void NFunction::define(Compiler *compiler, CResult& result, shared_ptr<CFunction> parentFunction) {
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
        
        auto thisFunction = CFunction::create(compiler, result, parentFunction, type, name, shared_from_this());
        parentFunction->funcsByName[name] = thisFunction;
        
        for (auto it : assignments) {
            it->define(compiler, result, thisFunction);
        }
    } else {
        auto thisFunction = CFunction::create(compiler, result, parentFunction, type, name, shared_from_this());
        parentFunction->funcsByName[name] = thisFunction;

        for (auto it : functions) {
            it->define(compiler, result, thisFunction);
        }
        
        for (auto it : assignments) {
            it->define(compiler, result, thisFunction);
        }

        block->define(compiler, result, thisFunction);
    }
}

void NFunction::fixVar(Compiler *compiler, CResult& result, shared_ptr<CFunction> parentFunction) {
    assert(compiler->state == CompilerState::FixVar);
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return;
    }
    
    auto thisFunction = parentFunction->getCFunction(name);
    assert(thisFunction);
    
    for (auto it : functions) {
        it->fixVar(compiler, result, thisFunction);
    }

    for (auto it : assignments) {
        it->fixVar(compiler, result, thisFunction);
    }
    
    if (block) {
        block->fixVar(compiler, result, thisFunction);
    }
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
    assert(thisFunction->name == name);
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

    if (!block && type == FT_Extern) {
        result.addError(loc, CErrorCode::InvalidFunction, "extern function must specify return type");
        return nullptr;
    }
    
    return block->getReturnType(compiler, result, thisFunction);
}

Value* NFunction::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> parentFunction, Value* parentValue, IRBuilder<>* builder, BasicBlock* parentCatchBB) const {
    assert(compiler->state == CompilerState::Compile);
    
    if (block == nullptr) {
        // This is an extern function definition, there is no code to comile
        return nullptr;
    }
    
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return nullptr;
    }
    
    auto thisFunction = parentFunction->getCFunction(name);
    assert(thisFunction);
    auto function = thisFunction->getFunction(compiler, result);
    if (!function) {
        return nullptr;
    }
    
    IRBuilder<> newBuilder(thisFunction->basicBlock);
    Value *RetVal = nullptr;
    
    // Create all of the inner functions, before creating the code for this function
    for (auto it : functions) {
        it->compile(compiler, result, thisFunction, thisFunction->getThisArgument(compiler, result), nullptr, nullptr);
    }
    
    BasicBlock* catchBB = nullptr;
    if (catchBlock) {
        catchBB = BasicBlock::Create(compiler->context);
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
        
        Value *RetVal = catchBlock->compile(compiler, result, thisFunction, thisFunction->getThisArgument(compiler, result), &catchBuilder, nullptr);
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
    
    RetVal = block->compile(compiler, result, thisFunction, thisFunction->getThisArgument(compiler, result), &newBuilder, catchBB);
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
    return nullptr;
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

