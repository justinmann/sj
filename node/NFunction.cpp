#include "Node.h"

NFunction::NFunction(CLoc loc, const char* type, const char* name, NodeList arguments, shared_ptr<NBlock> block) : type(type), name(name), block(block), NBase(loc) {
    for (auto it : arguments) {
        if (it->getNodeType() == NodeType_Assignment) {
            assignments.push_back(static_pointer_cast<NAssignment>(it));
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

void NFunction::define(Compiler *compiler, CResult& result) {
    assert(compiler->state == CompilerState::Define);
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return;
    }
    
    auto tf = CFunction::create(compiler, result, compiler->currentFunction, shared_from_this());
    compiler->currentFunction->funcsByName[name] = tf;
    auto prev = compiler->currentFunction;
    compiler->currentFunction = tf;

    for (auto it : functions) {
        it->define(compiler, result);
    }
    
    for (auto it : assignments) {
        it->rightSide->define(compiler, result);
    }

    block->define(compiler, result);
    
    compiler->currentFunction = prev;
}

void NFunction::fixVar(Compiler *compiler, CResult& result) {
    assert(compiler->state == CompilerState::FixVar);
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return;
    }
    
    auto tf = compiler->currentFunction->getCFunction(name);
    assert(tf);
    auto prev = compiler->currentFunction;
    compiler->currentFunction = tf;
    
    for (auto it : functions) {
        it->fixVar(compiler, result);
    }

    for (auto it : assignments) {
        it->rightSide->fixVar(compiler, result);
    }
    
    block->fixVar(compiler, result);
    
    compiler->currentFunction = prev;
}

shared_ptr<CType> NFunction::getReturnType(Compiler *compiler, CResult& result) const {
    assert(compiler->state >= CompilerState::FixVar);
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return nullptr;
    }

    return compiler->typeVoid;
}

shared_ptr<CType> NFunction::getBlockType(Compiler *compiler, CResult& result) const {
    assert(compiler->state >= CompilerState::FixVar);
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return nullptr;
    }

    auto tf = compiler->currentFunction->getCFunction(name);
    assert(tf);
    auto prev = compiler->currentFunction;
    compiler->currentFunction = tf;

    auto returnType = block->getReturnType(compiler, result);

    compiler->currentFunction = prev;
    return returnType;
}

Value* NFunction::compile(Compiler* compiler, CResult& result) const {
    assert(compiler->state == CompilerState::Compile);
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return nullptr;
    }
    
    auto tf = compiler->currentFunction->getCFunction(name);
    assert(tf);
    auto function = tf->getFunction(compiler, result);
    if (!function) {
        return nullptr;
    }
    
    auto prev = compiler->currentFunction;
    compiler->currentFunction = tf;
    
    // Create all of the inner functions, before creating the code for this function
    for (auto it : functions) {
        it->compile(compiler, result);
    }
    
    auto prevInsertPoint = compiler->builder.saveIP();
    compiler->builder.SetInsertPoint(tf->getBasicBlock());
    
    Value *RetVal = block->compile(compiler, result);
    if (RetVal) {
        if (function->getReturnType() != RetVal->getType()) {
            result.addError(loc, CErrorCode::TypeMismatch, "return type '%s' does not match return value type '%s'", Type_print(function->getReturnType()).c_str(), Type_print(RetVal->getType()).c_str());
        }
        compiler->builder.CreateRet(RetVal);
    } else {
        if (!function->getReturnType()->isVoidTy()) {
            result.errors.push_back(CError(loc, CErrorCode::TypeMismatch, "no return for non-void function"));
        }
        compiler->builder.CreateRetVoid();        
    }
    
    assert(tf->getBasicBlock()->getTerminator());
    
    // Validate the generated code, checking for consistency.
    verifyFunction(*function);
    
    // compiler->TheFPM->run(*function);
    
    compiler->builder.restoreIP(prevInsertPoint);
    compiler->currentFunction = prev;
    
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
            it->rightSide->dump(compiler, level + 2);
            dumpf(level + 1, "}");
        }
        dumpf(level, "}");
    }
    
    dumpf(level, "block: {");
    block->dump(compiler, level + 1);
    dumpf(level, "}");
}

