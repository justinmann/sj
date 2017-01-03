#include "Node.h"

NAssignment::NAssignment(CLoc loc, const char* typeName, const char* name, shared_ptr<NBase> rightSide, bool isMutable) : typeName(typeName), name(name), rightSide(rightSide), isMutable(isMutable), NBase(loc) {
    // If we are assigning a function to a var then we will call the function to get its value
    if (rightSide && rightSide->getNodeType() == NodeType::NodeType_Function) {
        auto nfunction = static_pointer_cast<NFunction>(rightSide);
        call = make_shared<NCall>(loc, nfunction->name.c_str(), NodeList());
    }
}

NodeType NAssignment::getNodeType() const {
    return NodeType_Assignment;
}

void NAssignment::define(Compiler* compiler, CResult& result) {
    assert(compiler->state == CompilerState::Define);
    auto iter = compiler->currentFunction->localVarsByName.find(name);
    if (iter == compiler->currentFunction->localVarsByName.end()) {
        compiler->currentFunction->localVarsByName[name] = CLocalVar::create(name, compiler->currentFunction, shared_from_this());;
    } else if (!isMutable) {
        result.errors.push_back(CError(loc, CErrorCode::ImmutableAssignment));
    }
    
    if (call) {
        call->define(compiler, result);
    }
    
    rightSide->define(compiler, result);
}

void NAssignment::fixVar(Compiler* compiler, CResult& result) {
    assert(compiler->state == CompilerState::FixVar);
    if (call) {
        call->fixVar(compiler, result);
    }
    
    rightSide->fixVar(compiler, result);
}

shared_ptr<CType> NAssignment::getReturnType(Compiler *compiler, CResult& result) const {
    assert(compiler->state >= CompilerState::FixVar);
    if (call) {
        return call->getReturnType(compiler, result);
    }
    return rightSide->getReturnType(compiler, result);
}

Value* NAssignment::compile(Compiler* compiler, CResult& result) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    // Compute value
    Value *value = rightSide->compile(compiler, result);

    // If we have a "call" then the right side is a function declaration, execute the function
    if (call) {
        assert(value == nullptr);
        value = call->compile(compiler, result);
    }
    
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

        if (value->getType() != valueType->llvmRefType(compiler, result)) {
            result.errors.push_back(CError(loc, CErrorCode::TypeMismatch, "invalid type"));
            return nullptr;
        }
    }
    
    // Get place to store data
    auto cvar = compiler->currentFunction->getCVar(name);
    if (!cvar) {
        result.errors.push_back(CError(loc, CErrorCode::Internal, "var disappeared"));
        return nullptr;
    }
    auto alloca = cvar->getValue(compiler, result, compiler->currentFunction->getThis());
    
    // Store value
    compiler->builder.CreateStore(value, alloca);
    return value;
}
