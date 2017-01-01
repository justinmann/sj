#include "Node.h"

NodeType NAssignment::getNodeType() const {
    return NodeType_Assignment;
}

void NAssignment::define(Compiler* compiler, CResult& result) {
    auto iter = compiler->currentFunction->vars.find(name);
    if (iter != compiler->currentFunction->vars.end()) {
        if (!isMutable) {
            result.errors.push_back(CError(loc, CErrorCode::ImmutableAssignment));
        } else {
            var = iter->second;
        }
    } else {
        var = shared_ptr<CVar>((CVar*)new CLocalVar(compiler->currentFunction, this));
        compiler->currentFunction->vars[name] = var;
    }
}

shared_ptr<CType> NAssignment::getReturnType(Compiler *compiler, CResult& result) const {
    return rightSide->getReturnType(compiler, result);
}

Value* NAssignment::compile(Compiler* compiler, CResult& result) const {
    compiler->emitLocation(this);
    
    // Compute value
    Value *value = rightSide->compile(compiler, result);
    if (!value) {
        result.errors.push_back(CError(loc, CErrorCode::ExpressionEmpty, "trying to assign an empty value"));
        return nullptr;
    }
    
    if (typeName.size() > 0) {
        shared_ptr<CType> valueType = compiler->getType(typeName.c_str());
        if (!valueType) {
            result.errors.push_back(CError(loc, CErrorCode::InvalidType, "explicit type does not exist"));
            return nullptr;
        }

        if (value->getType() != valueType->llvmRefType) {
            result.errors.push_back(CError(loc, CErrorCode::TypeMismatch, "invalid type"));
            return nullptr;
        }
    }
    
    // Get place to store data
    auto alloca = var->getValue(compiler, result);
    
    // Store value
    compiler->builder.CreateStore(value, alloca);
    return value;
}
