#include "Node.h"
#include <sstream>

NCall::NCall(CLoc loc, const char* name, NodeList arguments) : arguments(arguments), NBase(loc) {
    istringstream f(name);
    string s;
    while (getline(f, s, '.')) {
        dotNames.push_back(s);
    }
    functionName = dotNames.back();
    dotNames.pop_back();
}

NodeType NCall::getNodeType() const {
    return NodeType_Call;
}

CFunction* NCall::getCFunction(Compiler *compiler, CResult& result) const {
    auto cfunction = compiler->currentFunction;
    
    // If more than one name in the list, then we need to iterate down to correct function
    if (dotNames.size() > 0) {
        auto ctype = NVariable::getParentValue(compiler, result, loc, dotNames, nullptr);
        if (!ctype) {
            result.addError(loc, CErrorCode::UnknownFunction, "function '%s' does not exist", dotNames.back().c_str());
            return nullptr;
        }
        
        cfunction = ctype->cfunction;
    }
    
    // Handle last name in list
    CFunction* callee = cfunction->getCFunction(functionName);
    
    if (!callee) {
        // If we are still using "this" then we can check to see if it is a function on parent
        if (cfunction == compiler->currentFunction) {
            while (cfunction && !callee) {
                cfunction = cfunction->parent;
                callee = cfunction->getCFunction(functionName);
            }
        }
    }
    
    if (!callee) {
        result.addError(loc, CErrorCode::UnknownFunction, "function '%s' does not exist", functionName.c_str());
        return nullptr;
    }
    
    return callee;
}

shared_ptr<CType> NCall::getReturnType(Compiler *compiler, CResult& result) const {
    auto callee = getCFunction(compiler, result);
    if (!callee) {
        return nullptr;
    }
    
    auto prev = compiler->currentFunction;
    compiler->currentFunction = callee->parent;

    auto type = callee->getReturnType(compiler, result);
    
    compiler->currentFunction = prev;
    
    return type;
}

Value* NCall::compile(Compiler* compiler, CResult& result) const {
    compiler->emitLocation(this);
    
    auto callee = getCFunction(compiler, result);
    if (!callee) {
        return nullptr;
    }
    
    // Create this on stack, and get a pointer
    auto thisType = callee->getThisType(compiler, result);
    auto thisValue = compiler->builder.CreateAlloca(thisType->llvmAllocType, 0, "thisValue");
    
    if (arguments.size() > callee->node->assignments.size()) {
        result.errors.push_back(CError(CLoc::undefined, CErrorCode::TooManyParameters));
        return nullptr;
    }
    
    // Fill in parameters
    vector<NBase*> parameters(callee->node->assignments.size());
    auto argIndex = 0;
    auto hasSetByName = false;
    for (auto it : arguments) {
        if (it->getNodeType() == NodeType_Assignment) {
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
    for (auto it : callee->node->assignments) {
        if (parameters[argIndex] == nullptr) {
            if (it->getNodeType() != NodeType_Assignment) {
                result.errors.push_back(CError(CLoc::undefined, CErrorCode::NotVariable));
                return nullptr;
            }
            auto defaultAssignment = (const NAssignment*)it.get();
            parameters[argIndex] = defaultAssignment->rightSide.get();
        }
        argIndex++;
    }
    
    
    // Fill in "this" with normal arguments
    argIndex = 0;
    for (auto it : callee->node->assignments) {
        if (it->getNodeType() != NodeType_Assignment) {
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
    
    // Add "parent" to "this"
    argIndex = callee->getThisIndex("parent");
    if (argIndex != -1) {
        Value* parentValue = compiler->currentFunction->getThis();
        if (dotNames.size() > 0) {
            NVariable::getParentValue(compiler, result, loc, dotNames, &parentValue);
        } else {
            // if recursively calling ourselves then re-use parent
            if (callee == compiler->currentFunction) {
                auto parentIndex = compiler->currentFunction->getThisIndex("parent");
                vector<Value*> v;
                v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
                v.push_back(ConstantInt::get(compiler->context, APInt(32, parentIndex)));
                auto ptr = compiler->builder.CreateInBoundsGEP(compiler->currentFunction->getThisType(compiler, result)->llvmAllocType, parentValue, ArrayRef<Value *>(v), "paramPtr");
                parentValue = compiler->builder.CreateLoad(ptr);
            } else {
                auto temp = compiler->currentFunction;
                while (temp && temp != callee->parent) {
                    auto parentIndex = temp->getThisIndex("parent");
                    vector<Value*> v;
                    v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
                    v.push_back(ConstantInt::get(compiler->context, APInt(32, parentIndex)));
                    auto ptr = compiler->builder.CreateInBoundsGEP(temp->getThisType(compiler, result)->llvmAllocType, parentValue, ArrayRef<Value *>(v), "paramPtr");
                    parentValue = compiler->builder.CreateLoad(ptr);
                    
                    temp = temp->parent;
                }
            }
        }
        
        vector<Value*> v;
        v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
        v.push_back(ConstantInt::get(compiler->context, APInt(32, argIndex)));
        auto paramPtr = compiler->builder.CreateInBoundsGEP(thisType->llvmAllocType, thisValue, ArrayRef<Value *>(v), "paramPtr");
        
        compiler->builder.CreateStore(parentValue, paramPtr);
    }
    
    vector<Value *> argsV;
    argsV.push_back(thisValue);
    
    auto func = callee->getFunction(compiler, result);
    return compiler->builder.CreateCall(func, argsV, "calltmp");
}
