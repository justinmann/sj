#include "Node.h"

NodeType NMethodCall::getNodeType() const {
    return NodeType::MethodCall;
}

shared_ptr<CType> NMethodCall::getReturnType(Compiler *compiler, CResult& result) const {
    TFunction* callee = compiler->currentFunction->getTFunction(name);
    return callee->getReturnType(compiler, result);
}

Value* NMethodCall::compile(Compiler* compiler, CResult& result) const {
    compiler->emitLocation(this);
    
    TFunction* callee = compiler->currentFunction->getTFunction(name);
    
    // Look up the name in the global module table.
    if (!callee) {
        result.errors.push_back(CError(loc, CErrorCode::UnknownFunction, name.c_str()));
        return nullptr;
    }
    
    // Create this on stack, and get a pointer
    auto thisType = callee->getThisType(compiler, result);
    auto thisValue = compiler->builder.CreateAlloca(thisType->llvmAllocType, 0, "thisValue");
    
    if (arguments->size() > callee->node->arguments->size()) {
        result.errors.push_back(CError(CLoc::undefined, CErrorCode::TooManyParameters));
        return nullptr;
    }
    
    // Fill in parameters
    vector<NBase*> parameters(callee->node->arguments->size());
    auto argIndex = 0;
    auto hasSetByName = false;
    for (auto it : *arguments) {
        if (it->getNodeType() == NodeType::Assignment) {
            auto parameterAssignment = (const NAssignment*)it.get();
            auto index = callee->getThisIndex(parameterAssignment->name);
            if (index == -1) {
                result.errors.push_back(CError(CLoc::undefined, CErrorCode::ParameterDoesNotExist));
                return nullptr;
            }
            
            if (parameters[index] != nullptr) {
                result.errors.push_back(CError(CLoc::undefined, CErrorCode::ParameterRedefined));
                return nullptr;
            }
            
            parameters[index] = parameterAssignment->rightSide.get();
            hasSetByName = true;
        } else {
            if (hasSetByName) {
                result.errors.push_back(CError(CLoc::undefined, CErrorCode::ParameterByIndexAfterByName));
                return nullptr;
            }
            
            if (parameters[argIndex] != nullptr) {
                result.errors.push_back(CError(CLoc::undefined, CErrorCode::ParameterRedefined));
                return nullptr;
            }
            
            parameters[argIndex] = it.get();
        }
        argIndex++;
    }
    
    argIndex = 0;
    for (auto it : *callee->node->arguments) {
        if (parameters[argIndex] == nullptr) {
            if (it->getNodeType() != NodeType::Assignment) {
                result.errors.push_back(CError(CLoc::undefined, CErrorCode::NotVariable));
                return nullptr;
            }
            auto defaultAssignment = (const NAssignment*)it.get();
            parameters[argIndex] = defaultAssignment->rightSide.get();
        }
        argIndex++;
    }
    
    
    // Fill in "this"
    argIndex = 0;
    for (auto it : *callee->node->arguments) {
        if (it->getNodeType() != NodeType::Assignment) {
            result.errors.push_back(CError(CLoc::undefined, CErrorCode::NotVariable));
            return nullptr;
        }
        auto defaultAssignment = (const NAssignment*)it.get();
        auto argType = defaultAssignment->getReturnType(compiler, result);
        
        vector<Value*> v;
        v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
        v.push_back(ConstantInt::get(compiler->context, APInt(32, argIndex)));
        auto paramPtr = compiler->builder.CreateInBoundsGEP(thisType->llvmAllocType, thisValue, ArrayRef<Value *>(v), "paramPtr");
        
        auto value = parameters[argIndex]->compile(compiler, result);
        if (!value) {
            result.errors.push_back(CError(CLoc::undefined, CErrorCode::TypeMismatch, "value is empty"));
            return nullptr;
        }
        
        if (value->getType() != argType->llvmRefType) {
            result.errors.push_back(CError(CLoc::undefined, CErrorCode::TypeMismatch, "value does not match"));
            return nullptr;
        }

        compiler->builder.CreateStore(value, paramPtr);

        argIndex++;
    }    
    
    vector<Value *> argsV;
    argsV.push_back(thisValue);
    
    auto func = callee->getFunction(compiler, result);
    return compiler->builder.CreateCall(func, argsV, "calltmp");
}
