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

void NCall::define(Compiler* compiler, CResult& result) {
    assert(compiler->state == CompilerState::Define);
    for (auto it : arguments) {
        if (it->getNodeType() == NodeType_Assignment) {
            auto parameterAssignment = static_pointer_cast<NAssignment>(it);
            parameterAssignment->rightSide->define(compiler, result);
        } else {
            it->define(compiler, result);
        }
    }
}

void NCall::fixVar(Compiler* compiler, CResult& result) {
    assert(compiler->state == CompilerState::FixVar);
    NVariable::getParentValue(compiler, result, loc, dotNames, nullptr);

    for (auto it : arguments) {
        if (it->getNodeType() == NodeType_Assignment) {
            auto parameterAssignment = static_pointer_cast<NAssignment>(it);
            parameterAssignment->rightSide->fixVar(compiler, result);
        } else {
            it->fixVar(compiler, result);
        }
    }
}

shared_ptr<CFunction> NCall::getCFunction(Compiler *compiler, CResult& result) const {
    auto cfunction = compiler->currentFunction;
    
    // If more than one name in the list, then we need to iterate down to correct function
    if (dotNames.size() > 0) {
        shared_ptr<CType> ctype = NVariable::getParentValue(compiler, result, loc, dotNames, nullptr);
        if (!ctype) {
            result.addError(loc, CErrorCode::UnknownFunction, "function '%s' does not exist", dotNames.back().c_str());
            return nullptr;
        }
        
        cfunction = ctype->cfunction.lock();
    }
    
    // Handle last name in list
    auto callee = cfunction->getCFunction(functionName);    
    if (!callee) {
        // If we are still using "this" then we can check to see if it is a function on parent
        if (cfunction == compiler->currentFunction) {
            while (cfunction && !callee) {
                cfunction = shared_ptr<CFunction>(cfunction->parent);
                if (cfunction) {
                    callee = cfunction->getCFunction(functionName);
                }
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
    assert(compiler->state >= CompilerState::FixVar);
    auto callee = getCFunction(compiler, result);
    if (!callee) {
        return nullptr;
    }
    
    auto prev = compiler->currentFunction;
    compiler->currentFunction = shared_ptr<CFunction>(callee->parent);

    auto type = callee->getReturnType(compiler, result);
    
    compiler->currentFunction = prev;
    
    return type;
}

Value* NCall::compile(Compiler* compiler, CResult& result) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    auto callee = getCFunction(compiler, result);
    if (!callee) {
        return nullptr;
    }
    
    // Create this on stack, and get a pointer
    auto thisType = callee->getThisType(compiler, result);
    auto thisValue = compiler->builder.CreateAlloca(thisType->llvmAllocType(compiler, result), 0, "thisValue");
    
    if (arguments.size() > callee->node->assignments.size()) {
        result.errors.push_back(CError(CLoc::undefined, CErrorCode::TooManyParameters));
        return nullptr;
    }
    
    // Fill in parameters
    vector<shared_ptr<NBase>> parameters(callee->node->assignments.size());
    auto argIndex = 0;
    auto hasSetByName = false;
    for (auto it : arguments) {
        if (it->getNodeType() == NodeType_Assignment) {
            auto parameterAssignment = static_pointer_cast<NAssignment>(it);
            auto index = callee->getThisIndex(parameterAssignment->name);
            if (index == -1) {
                result.errors.push_back(CError(CLoc::undefined, CErrorCode::ParameterDoesNotExist));
                return nullptr;
            }
            
            if (parameters[index] != nullptr) {
                result.errors.push_back(CError(CLoc::undefined, CErrorCode::ParameterRedefined));
                return nullptr;
            }
            
            parameters[index] = parameterAssignment->rightSide;
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
            
            parameters[argIndex] = it;
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
            auto defaultAssignment = static_pointer_cast<NAssignment>(it);
            parameters[argIndex] = defaultAssignment->rightSide;
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
        auto defaultAssignment = static_pointer_cast<NAssignment>(it);
        auto argType = defaultAssignment->getReturnType(compiler, result);
        
        vector<Value*> v;
        v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
        v.push_back(ConstantInt::get(compiler->context, APInt(32, argIndex)));
        auto paramPtr = compiler->builder.CreateInBoundsGEP(thisType->llvmAllocType(compiler, result), thisValue, ArrayRef<Value *>(v), defaultAssignment->name.c_str());
        
        auto value = parameters[argIndex]->compile(compiler, result);
        if (!value) {
            result.errors.push_back(CError(CLoc::undefined, CErrorCode::TypeMismatch, "value is empty"));
            return nullptr;
        }
        
        if (value->getType() != argType->llvmRefType(compiler, result)) {
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
                auto ptr = compiler->builder.CreateInBoundsGEP(compiler->currentFunction->getThisType(compiler, result)->llvmAllocType(compiler, result), parentValue, ArrayRef<Value *>(v), "parent");
                parentValue = compiler->builder.CreateLoad(ptr, "parent");
            } else {
                auto temp = compiler->currentFunction;
                while (temp && temp != callee->parent.lock()) {
                    auto parentIndex = temp->getThisIndex("parent");
                    vector<Value*> v;
                    v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
                    v.push_back(ConstantInt::get(compiler->context, APInt(32, parentIndex)));
                    auto ptr = compiler->builder.CreateInBoundsGEP(temp->getThisType(compiler, result)->llvmAllocType(compiler, result), parentValue, ArrayRef<Value *>(v), "parent");
                    parentValue = compiler->builder.CreateLoad(ptr, "parent");
                    
                    temp = shared_ptr<CFunction>(temp->parent);
                }
            }
        }
        
        vector<Value*> v;
        v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
        v.push_back(ConstantInt::get(compiler->context, APInt(32, argIndex)));
        auto paramPtr = compiler->builder.CreateInBoundsGEP(thisType->llvmAllocType(compiler, result), thisValue, ArrayRef<Value *>(v), "parent");
        
        compiler->builder.CreateStore(parentValue, paramPtr, "parent");
    }
    
    vector<Value *> argsV;
    argsV.push_back(thisValue);
    
    auto prev = compiler->currentFunction;
    compiler->currentFunction = shared_ptr<CFunction>(callee->parent);
    
    auto func = callee->getFunction(compiler, result);
    
    compiler->currentFunction = prev;

    return compiler->builder.CreateCall(func, argsV, "calltmp");
}
