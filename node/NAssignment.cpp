#include "Node.h"

NAssignment::NAssignment(CLoc loc, const char* typeName, const char* name, shared_ptr<NBase> rightSide_, bool isMutable) : typeName(typeName), rightSide(rightSide_), isMutable(isMutable), inFunctionDeclaration(false),NBase(loc) {
    fullName = name;

    istringstream f(name);
    string s;
    while (getline(f, s, '.')) {
        names.push_back(s);
    }

    // If we are assigning a function to a var then we will call the function to get its value
    if (rightSide && rightSide->getNodeType() == NodeType::NodeType_Function) {
        nfunction = static_pointer_cast<NFunction>(rightSide);
        rightSide = make_shared<NCall>(loc, nfunction->name.c_str(), nullptr, NodeList());
    }
}

NodeType NAssignment::getNodeType() const {
    return NodeType_Assignment;
}

void NAssignment::define(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    
    if (nfunction) {
        nfunction->define(compiler, result, thisFunction);
    }
    
    if (rightSide) {
        rightSide->define(compiler, result, thisFunction);
    }
}

void NAssignment::fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);

    // function vars are not created here, this is only for local vars
    if (!inFunctionDeclaration) {
        // We need to see if var already exists, if not create a new local var
        auto cvar = NVariable::getParentValue(compiler, result, loc, thisFunction, nullptr, nullptr, names, VT_STORE, nullptr);
        if (cvar) {
            if (!isMutable) {
                result.addError(loc, CErrorCode::ImmutableAssignment, "immutable assignment to existing var");
                return;
            } else if (!cvar->isMutable) {
                result.addError(loc, CErrorCode::ImmutableAssignment, "immutable assignment to existing var");
                return;
            }
        } else {
            if (names.size() == 1) {
                auto iter = thisFunction->localVarsByName.find(names[0]);
                if (iter != thisFunction->localVarsByName.end()) {
                    result.addError(loc, CErrorCode::Internal, "the previous search on NVariable should find a local value with same name");
                    return;
                }
                thisFunction->localVarsByName[names[0]] = CLocalVar::create(loc, names[0], thisFunction, shared_from_this());;
            }
        }
    }
    
    if (nfunction) {
        nfunction->fixVar(compiler, result, thisFunction);
    }
    
    if (rightSide) {
        rightSide->fixVar(compiler, result, thisFunction);
    }
}

shared_ptr<CType> NAssignment::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    
    if (typeName.size() > 0) {
        auto valueType = thisFunction->getVarType(compiler, result, loc, typeName, nullptr);
        if (!valueType) {
            result.addError(loc, CErrorCode::InvalidType, "explicit type does not exist");
            return nullptr;
        }
        return valueType;
    }
    
    if (!rightSide) {
        result.addError(loc, CErrorCode::Internal, "only required assignment should not have a right side, and they must have typeName");
        return nullptr;
    }
    
    return rightSide->getReturnType(compiler, result, thisFunction);
}

Value* NAssignment::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    if (!rightSide) {
        result.addError(loc, CErrorCode::Internal, "only required assignment should not have a right side, and they should not be compiled");
        return nullptr;
    }

    if (!inFunctionDeclaration && nfunction) {
        nfunction->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    }
    
    // Compute value
    Value *value = rightSide->compile(compiler, result, thisFunction, thisValue, builder, catchBB);

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
            result.addError(loc, CErrorCode::TypeMismatch, "returned type '%s' does not match explicit type '%s'", Type_print(value->getType()).c_str(), Type_print(valueType->llvmRefType(compiler, result)).c_str());
            return nullptr;
        }
    }
    
    // Get place to store data
    Value* alloca = nullptr;
    auto cvar = NVariable::getParentValue(compiler, result, loc, thisFunction, thisValue, builder, names, VT_STORE, &alloca);
    if (!cvar) {
        result.addError(loc, CErrorCode::InvalidVariable, "var does not exist '%s'", fullName.c_str());
        return nullptr;
    }
    
    if (!alloca) {
        result.addError(loc, CErrorCode::InvalidVariable, "var cannot be assigned '%s'", fullName.c_str());
        return nullptr;
    }
    
    // Store value
    builder->CreateStore(value, alloca);
    return value;
}

void NAssignment::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NAssignment'");
    dumpf(level, "name: %s", fullName.c_str());
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

shared_ptr<NAssignment> NAssignment::shared_from_this() {
    return static_pointer_cast<NAssignment>(NBase::shared_from_this());
}

