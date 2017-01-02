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
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return;
    }
    
    auto tf = make_shared<CFunction>(compiler->currentFunction, this);
    compiler->currentFunction->funcs[name] = tf;   
    auto prev = compiler->currentFunction;
    compiler->currentFunction = tf.get();

    block->define(compiler, result);
    
    compiler->currentFunction = prev;
}

shared_ptr<CType> NFunction::getReturnType(Compiler *compiler, CResult& result) const {
    if (invalid.size() > 0) {
        result.addError(loc, CErrorCode::InvalidFunction, "function init block can only contain assignments or function definitions");
        return nullptr;
    }

    return compiler->typeVoid;
}

shared_ptr<CType> NFunction::getBlockType(Compiler *compiler, CResult& result) const {
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
        if (function->getReturnType() != compiler->typeVoid->llvmRefType) {
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


