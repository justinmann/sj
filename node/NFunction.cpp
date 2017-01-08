#include "Node.h"

int NFunction::counter = 0;

NFunction::NFunction(CLoc loc, const char* type, const char* name, NodeList arguments, shared_ptr<NBlock> block) : type(type), name(name), block(block), NBase(loc) {
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
    
    auto thisFunction = CFunction::create(compiler, result, parentFunction, name, shared_from_this());
    parentFunction->funcsByName[name] = thisFunction;

    for (auto it : functions) {
        it->define(compiler, result, thisFunction);
    }
    
    for (auto it : assignments) {
        it->define(compiler, result, thisFunction);
    }

    block->define(compiler, result, thisFunction);
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
    
    block->fixVar(compiler, result, thisFunction);
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

    auto returnType = block->getReturnType(compiler, result, thisFunction);

    return returnType;
}

Value* NFunction::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> parentFunction, Value* parentValue, IRBuilder<>* builder) const {
    assert(compiler->state == CompilerState::Compile);
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
    
    // Create all of the inner functions, before creating the code for this function
    IRBuilder<> newBuilder(thisFunction->basicBlock);
    
    for (auto it : functions) {
        it->compile(compiler, result, thisFunction, thisFunction->getThisArgument(compiler, result), &newBuilder);
    }
    
    Value *RetVal = block->compile(compiler, result, thisFunction, thisFunction->getThisArgument(compiler, result), &newBuilder);
    if (RetVal) {
        if (function->getReturnType() != RetVal->getType()) {
            result.addError(loc, CErrorCode::TypeMismatch, "return type '%s' does not match return value type '%s'", Type_print(function->getReturnType()).c_str(), Type_print(RetVal->getType()).c_str());
        }
        newBuilder.CreateRet(RetVal);
    } else {
        if (!function->getReturnType()->isVoidTy()) {
            result.addError(loc, CErrorCode::TypeMismatch, "no return for non-void function");
        }
        newBuilder.CreateRetVoid();
    }
    
    // Validate the generated code, checking for consistency.
    if (verifyFunction(*function) && result.errors.size() == 0) {
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
    
    dumpf(level, "block: {");
    block->dump(compiler, level + 1);
    dumpf(level, "}");
}

