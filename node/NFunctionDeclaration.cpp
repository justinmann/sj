#include "Node.h"

NodeType NFunctionDeclaration::getNodeType() const {
    return NodeType::FunctionDeclaration;
}

void NFunctionDeclaration::define(Compiler *compiler, CResult& result) {
    auto tf = make_shared<TFunction>(compiler->currentFunction, this);
    compiler->currentFunction->funcs[name] = tf;   
    auto prev = compiler->currentFunction;
    compiler->currentFunction = tf.get();

    block->define(compiler, result);
    
    compiler->currentFunction = prev;
}

shared_ptr<CType> NFunctionDeclaration::getReturnType(Compiler *compiler, CResult& result) const {
    return compiler->typeVoid;
}

shared_ptr<CType> NFunctionDeclaration::getBlockType(Compiler *compiler, CResult& result) const {
    auto tf = compiler->currentFunction->getTFunction(name);
    auto prev = compiler->currentFunction;
    compiler->currentFunction = tf;

    auto returnType = block->getReturnType(compiler, result);

    compiler->currentFunction = prev;
    return returnType;
}

Value* NFunctionDeclaration::compile(Compiler* compiler, CResult& result) const {
    auto tf = compiler->currentFunction->getTFunction(name);
    auto function = tf->getFunction(compiler, result);
    if (!function) {
        return nullptr;
    }
    
    auto prev = compiler->currentFunction;
    compiler->currentFunction = tf;
    
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
    
    compiler->builder.restoreIP(prevInsertPoint);
    compiler->currentFunction = prev;
    
    return nullptr;
}


