#include "Node.h"
#include <sstream>

NCall::NCall(CLoc loc, const char* name, NodeList arguments) : arguments(arguments), NBase(loc) {
    istringstream f(name);
    string s;
    while (getline(f, s, '.')) {
        names.push_back(s);
    }
}

NodeType NCall::getNodeType() const {
    return NodeType_Call;
}

CFunction* NCall::getCFunction(Compiler *compiler, CResult& result) const {
    auto cfunction = compiler->currentFunction;
    
    // If more than one name in the list, then we need to iterate down to correct function
    if (names.size() > 1) {
        // Handle first name in list, the first name can come a local var or function argument
        auto cvar = cfunction->getCVariable(names[0]);
        if (!cvar) {
            result.addError(loc, CErrorCode::UnknownFunction, "function '%s' does not exist", names[0].c_str());
            return nullptr;
        }
        auto ctype = cvar->getType(compiler, result);
        
        // Iterate through the member vars
        for (int i = 1; i < names.size() - 1; i++) {
            auto it = ctype->membersByName.find(names[i]);
            if (it == ctype->membersByName.end()) {
                result.addError(loc, CErrorCode::UnknownFunction, "function '%s' does not exist", names[i].c_str());
                return nullptr;
            }
            ctype = it->second.second;
        }
        
        cfunction = ctype->cfunction;
        if (!cfunction) {
            result.addError(loc, CErrorCode::UnknownFunction, "function '%s' does not exist", names[names.size() - 2].c_str());
            return nullptr;
        }
    }
    
    // Handle last name in list
    CFunction* callee = cfunction->getCFunction(names.back());
    if (!callee) {
        result.addError(loc, CErrorCode::UnknownFunction, "function '%s' does not exist", names.back().c_str());
        return nullptr;
    }
    
    return callee;
}

shared_ptr<CType> NCall::getReturnType(Compiler *compiler, CResult& result) const {
    auto callee = getCFunction(compiler, result);
    if (!callee) {
        return nullptr;
    }
    return callee->getReturnType(compiler, result);
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
    
    
    // Fill in "this"
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
    
    vector<Value *> argsV;
    argsV.push_back(thisValue);
    
    auto func = callee->getFunction(compiler, result);
    return compiler->builder.CreateCall(func, argsV, "calltmp");
}
