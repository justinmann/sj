#include "Node.h"

NAssignment::NAssignment(CLoc loc, const char* typeName, const char* name, shared_ptr<NBase> rightSide_, bool isMutable) : typeName(typeName), name(name), rightSide(rightSide_), isMutable(isMutable), inFunctionDeclaration(false),NBase(loc) {
    // If we are assigning a function to a var then we will call the function to get its value
    if (rightSide && rightSide->getNodeType() == NodeType::NodeType_Function) {
        nfunction = static_pointer_cast<NFunction>(rightSide);
        rightSide = make_shared<NCall>(loc, nfunction->name.c_str(), NodeList());
    }
}

NodeType NAssignment::getNodeType() const {
    return NodeType_Assignment;
}

void NAssignment::define(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    
    if (!inFunctionDeclaration) {
        auto iter = thisFunction->localVarsByName.find(name);
        if (iter == thisFunction->localVarsByName.end()) {
            thisFunction->localVarsByName[name] = CLocalVar::create(name, thisFunction, shared_from_this());;
        } else if (!isMutable) {
            result.addError(loc, CErrorCode::ImmutableAssignment, "assigning to immutable variable is not allowed");
        }
    }
    
    if (nfunction) {
        nfunction->define(compiler, result, thisFunction);
    }
    
    rightSide->define(compiler, result, thisFunction);
}

void NAssignment::fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    if (nfunction) {
        nfunction->fixVar(compiler, result, thisFunction);
    }
    
    rightSide->fixVar(compiler, result, thisFunction);
}

shared_ptr<CType> NAssignment::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    return rightSide->getReturnType(compiler, result, thisFunction);
}

Value* NAssignment::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    // Compute value
    Value *value = rightSide->compile(compiler, result, thisFunction, thisValue, builder);

    if (!value) {
        result.addError(loc, CErrorCode::ExpressionEmpty, "trying to assign an empty value");
        return nullptr;
    }
    
    if (typeName.size() > 0) {
        shared_ptr<CType> valueType = compiler->getType(typeName.c_str());
        if (!valueType) {
            result.addError(loc, CErrorCode::InvalidType, "explicit type does not exist");
            return nullptr;
        }

        if (value->getType() != valueType->llvmRefType(compiler, result)) {
            result.addError(loc, CErrorCode::TypeMismatch, "invalid type");
            return nullptr;
        }
    }
    
    // Get place to store data
    auto cvar = thisFunction->getCVar(name);
    if (!cvar) {
        result.addError(loc, CErrorCode::Internal, "var disappeared");
        return nullptr;
    }
    auto alloca = cvar->getValue(compiler, result, thisValue, builder);
    
    // Store value
    builder->CreateStore(value, alloca);
    return value;
}

void NAssignment::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NAssignment'");
    dumpf(level, "name: %s", name.c_str());
    dumpf(level, "typeName: %s", typeName.c_str());
    dumpf(level, "isMutable: %s", bool_to_str(isMutable));
    
    if (nfunction) {
        dumpf(level, "function: {");
        nfunction->dump(compiler, level + 1);
        dumpf(level, "}");
    }
    
    dumpf(level, "rightSide: {");
    rightSide->dump(compiler, level + 1);
    dumpf(level, "}");
}
