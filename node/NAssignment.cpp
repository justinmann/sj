#include "Node.h"

bool CAssignVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CAssignVar::getType(Compiler* compiler) {
    return leftVar->getType(compiler);
}

void CAssignVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    assert(compiler->state == CompilerState::Compile);
   
    auto leftType = leftVar->getType(compiler);
    auto leftStoreValue = leftVar->getStoreValue(compiler, trOutput, trBlock, nullptr, thisValue, op, isFirstAssignment);
    if (!leftStoreValue) {
        return;
    }

    rightVar->transpile(compiler, trOutput, trBlock, nullptr, thisValue, leftStoreValue);
    if (!leftStoreValue->hasSetValue) {
        compiler->addError(loc, CErrorCode::TypeMismatch, "no return value");
        return;
    }
    
    storeValue->retainValue(compiler, loc, trBlock, leftStoreValue->getValue());
}

void CAssignVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    auto type = getType(compiler);
    leftVar->dump(compiler, dotVar, functions, ss, dotSS, level);
    auto leftType = leftVar->getType(compiler);
    ss << "'" << (leftType ? leftType->fullName.c_str() : "unknown");
    ss << (isMutable ? " = " : " : ");
    if (rightVar) {
        rightVar->dump(compiler, nullptr, functions, ss, dotSS, level);
    } else {
        ss << "undefined";
    }
}

NAssignment::NAssignment(CLoc loc, shared_ptr<NVariableBase> var, shared_ptr<CTypeName> typeName, const char* name, shared_ptr<NBase> rightSide_, AssignOp op) : NBase(NodeType_Assignment, loc), var(var), typeName(typeName), name(name), inFunctionDeclaration(false), rightSide(rightSide_), op(op), _isFirstAssignment(false) {
    // If we are assigning a function to a var then we will call the function to get its value
    if (rightSide && rightSide->nodeType == NodeType_Function) {
        nfunction = static_pointer_cast<NFunction>(rightSide);
        rightSide = make_shared<NCall>(loc, nfunction->name.c_str(), nullptr, nullptr);
    }
}

void NAssignment::defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    
    if (var) {
        var->define(compiler, thisFunction);
    }
    
    if (nfunction) {
        nfunction->define(compiler, thisFunction);
    }
    
    if (rightSide) {
        rightSide->define(compiler, thisFunction);
    }
}

shared_ptr<CVar> NAssignment::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    // function vars are not created here, this is only for local vars
    if (inFunctionDeclaration) {
        return nullptr;
    }
    
    // We need to see if var already exists, if not create a new local var
    auto cfunction = scope->function;
    shared_ptr<CVar> parentVar = nullptr;
    if (var) {
        parentVar = var->getVar(compiler, scope, nullptr, returnMode);
        if (!parentVar) {
            return nullptr;
        }

        auto parentType = parentVar->getType(compiler);
        cfunction = dynamic_pointer_cast<CFunction>(parentType->parent.lock());
        if (!cfunction) {
            compiler->addError(loc, CErrorCode::InvalidVariable, "var must be a function");
            return nullptr;
        }
    }
    
    // Check for operator overload first
    string temp = name;
    temp[0] = toupper(temp[0]);
    string setFunctionName = "set" + temp;
    auto setFunction = cfunction->getCFunction(compiler, loc, setFunctionName, scope, nullptr, returnMode);
    if (setFunction) {
        if (returnMode != CTM_Heap) {
            returnMode = CTM_Stack;
        }

        auto parameters = CCallVar::getParameters(compiler, loc, scope, setFunction, make_shared<NodeList>(rightSide), returnMode);
        return CCallVar::create(compiler, loc, setFunctionName, parameters, scope, parentVar, setFunction, returnMode);
    }
    else {
        if (!rightSide) {
            assert(false);
        }
        
        auto isFirstAssignment = false;
        shared_ptr<CStoreVar> leftStoreVar;
        if (var) {
            auto dotVar = var->getVar(compiler, scope, nullptr, CTM_Undefined);
            if (!dotVar) {
                return nullptr;
            }

            auto dotScope = CScope::getScopeForType(compiler, dotVar->getType(compiler));
            auto leftVar = dotScope->getCVar(compiler, name, VSM_ThisOnly);
            if (leftVar) {
                if (!op.isMutable) {
                    compiler->addError(loc, CErrorCode::ImmutableAssignment, "immutable assignment to existing var '%s'", name.c_str());
                    return nullptr;
                }
                else if (!leftVar->isMutable) {
                    compiler->addError(loc, CErrorCode::ImmutableAssignment, "immutable assignment to existing var '%s'", name.c_str());
                    return nullptr;
                }
                isFirstAssignment = false;
            }
            leftVar = CDotVar::create(loc, dotScope, dotVar, leftVar);

            leftStoreVar = dynamic_pointer_cast<CStoreVar>(leftVar);
            if (!leftStoreVar) {
                assert(false);
            }
        }
        else {
            auto leftVar = scope->getCVar(compiler, name, VSM_LocalThisParent);
            if (leftVar) {
                leftStoreVar = dynamic_pointer_cast<CStoreVar>(leftVar);
                if (!leftStoreVar) {
                    assert(false);
                }

                if (!op.isMutable) {
                    compiler->addError(loc, CErrorCode::ImmutableAssignment, "immutable assignment to existing var '%s'", name.c_str());
                    return nullptr;
                }
                else if (!leftStoreVar->getCanStoreValue()) {
                    compiler->addError(loc, CErrorCode::ImmutableAssignment, "immutable assignment to existing var '%s'", name.c_str());
                    return nullptr;
                }
                isFirstAssignment = false;
            }
            else {
                auto fun = static_pointer_cast<CFunction>(cfunction);
                
                auto leftType = getType(compiler, scope, CVarType::Var_Local, (op.typeMode == CTM_Undefined) ? returnMode : op.typeMode);
                if (!leftType) {
                    return nullptr;
                }
                leftStoreVar = make_shared<CNormalVar>(loc, scope, leftType, name, op.isMutable, CVarType::Var_Local);
                isFirstAssignment = true;
                
                scope->addOrUpdateLocalVar(compiler, name, leftStoreVar);
            }
        }

        auto leftType = leftStoreVar->getType(compiler);
        if (op.typeMode != CTM_Undefined && leftType->typeMode != op.typeMode) {
            compiler->addError(loc, CErrorCode::Internal, "var '%s' was already defined as '%s' cannot convert to %s", name.c_str(), leftType->fullName.c_str(), op.typeMode == CTM_Heap ? "heap" : op.typeMode == CTM_Stack ? "stack" : "local");
            return nullptr;
        }

        auto rightVar = rightSide->getVar(compiler, scope, leftType->typeMode);
        if (!rightVar) {
            assert(compiler->errors.size() > 0);
            return nullptr;
        }

        return make_shared<CAssignVar>(loc, leftStoreVar->scope.lock(), op, isFirstAssignment, leftStoreVar, rightVar);
    }

    return nullptr;
}

shared_ptr<CType> NAssignment::getType(Compiler* compiler, shared_ptr<CScope> scope, CVarType varType, CTypeMode returnMode) {
    if (typeName) {
        auto valueType = scope->getVarType(loc, compiler, typeName, returnMode);
        if (!valueType) {
            compiler->addError(loc, CErrorCode::InvalidType, "explicit type '%s' does not exist", typeName->getFullName().c_str());
            return nullptr;
        }
        return valueType;
    }
    
    if (!rightSide) {
        compiler->addError(loc, CErrorCode::Internal, "only required assignment should not have a right side, and they must have typeName");
        return nullptr;
    }
    
    auto rightVar = rightSide->getVar(compiler, scope, returnMode);
    if (!rightVar) {
        compiler->addError(loc, CErrorCode::Internal, "no right side");
        return nullptr;
    }

    auto rightType = rightVar->getType(compiler);
    if (returnMode != CTM_Undefined && returnMode != rightType->typeMode && rightType->typeMode != CTM_Value) {
        if (returnMode == CTM_Local) {
            return rightType->getLocalType();
        }
        else {
            compiler->addError(loc, CErrorCode::TypeMismatch, "cannot convert right side to %s", returnMode == CTM_Heap ? "heap" : "stack");
            return nullptr;
        }
    }
    return rightType;
}

shared_ptr<NAssignment> NAssignment::shared_from_this() {
    return static_pointer_cast<NAssignment>(NBase::shared_from_this());
}

