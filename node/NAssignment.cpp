#include "Node.h"

bool CAssignVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CAssignVar::getType(Compiler* compiler, CResult& result) {
    return rightVar->getType(compiler, result);
}

void CAssignVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    assert(compiler->state == CompilerState::Compile);
   
    auto leftType = leftVar->getType(compiler, result);
    auto leftStoreValue = leftVar->getStoreValue(compiler, result, trOutput, trBlock, nullptr, thisValue, op, isFirstAssignment);

    rightVar->transpile(compiler, result, trOutput, trBlock, nullptr, thisValue, leftStoreValue);
    if (!leftStoreValue->hasSetValue) {
        result.addError(loc, CErrorCode::TypeMismatch, "no return value");
        return;
    }
    
    storeValue->setValue(compiler, result, trBlock, leftStoreValue->getValue());
}

void CAssignVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    auto type = getType(compiler, result);
    leftVar->dump(compiler, result, dotVar, functions, ss, dotSS, level);
    auto leftType = leftVar->getType(compiler, result);
    ss << "'" << (leftType ? leftType->name.c_str() : "unknown");
    ss << (isMutable ? " = " : " : ");
    if (rightVar) {
        rightVar->dump(compiler, result, nullptr, functions, ss, dotSS, level);
    } else {
        ss << "undefined";
    }
}

NAssignment::NAssignment(CLoc& loc, shared_ptr<NVariableBase> var, shared_ptr<CTypeName> typeName, const char* name, shared_ptr<NBase> rightSide_, AssignOp op) : NBase(NodeType_Assignment, loc), var(var), typeName(typeName), name(name), inFunctionDeclaration(false), rightSide(rightSide_), op(op), _isFirstAssignment(false) {
    // If we are assigning a function to a var then we will call the function to get its value
    if (rightSide && rightSide->nodeType == NodeType_Function) {
        nfunction = static_pointer_cast<NFunction>(rightSide);
        rightSide = make_shared<NCall>(loc, nfunction->name.c_str(), nullptr, nullptr);
    }
}

void NAssignment::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    
    if (var) {
        var->define(compiler, result, thisFunction);
    }
    
    if (nfunction) {
        nfunction->define(compiler, result, thisFunction);
    }
    
    if (rightSide) {
        rightSide->define(compiler, result, thisFunction);
    }
}

shared_ptr<CVar> NAssignment::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode) {
    // function vars are not created here, this is only for local vars
    if (inFunctionDeclaration) {
        return nullptr;
    }
    
    // We need to see if var already exists, if not create a new local var
    auto cfunction = thisFunction;
    shared_ptr<CVar> parentVar = nullptr;
    if (var) {
        parentVar = var->getVar(compiler, result, thisFunction, thisVar, nullptr, returnMode);
        if (!parentVar) {
            return nullptr;
        }

        auto parentType = parentVar->getType(compiler, result);
        cfunction = dynamic_pointer_cast<CFunction>(parentType->parent.lock());
        if (!cfunction) {
            result.addError(loc, CErrorCode::InvalidVariable, "var must be a function");
            return nullptr;
        }
    }
    
    // Check for operator overload first
    string temp = name;
    temp[0] = toupper(temp[0]);
    string setFunctionName = "set" + temp;
    auto setFunction = cfunction->getCFunction(compiler, result, setFunctionName, thisFunction, nullptr, returnMode);
    if (setFunction) {
        auto arguments = make_shared<NodeList>();
        arguments->push_back(rightSide);
        return CCallVar::create(compiler, result, loc, setFunctionName, arguments, thisFunction, thisVar, parentVar, setFunction);
    }
    else {
        if (!rightSide) {
            assert(false);
        }
        
        auto isFirstAssignment = false;
        auto leftVar = cfunction->getCVar(compiler, result, name);
        if (leftVar) {
            if (op == ASSIGN_Immutable || op == ASSIGN_ImmutableCopy) {
                result.addError(loc, CErrorCode::ImmutableAssignment, "immutable assignment to existing var '%s'", name.c_str());
                return nullptr;
            }
            else if (!leftVar->isMutable) {
                result.addError(loc, CErrorCode::ImmutableAssignment, "immutable assignment to existing var '%s'", name.c_str());
                return nullptr;
            }
            isFirstAssignment = false;
        }
        else {
            if (!var) {
                auto fun = static_pointer_cast<CFunction>(cfunction);

                auto iter = fun->localVarsByName.find(name);
                if (iter != fun->localVarsByName.end()) {
                    result.addError(loc, CErrorCode::Internal, "the previous search on NVariable should find a local value with same name");
                    return nullptr;
                }

                auto leftType = getType(compiler, result, thisFunction, thisVar, returnMode);
                if (!leftType) {
                    return nullptr;
                }
                leftVar = make_shared<CNormalVar>(loc, thisFunction, leftType, name, op == ASSIGN_Mutable || op == ASSIGN_MutableCopy, CVarType::Var_Local);
                fun->localVarsByName[name] = leftVar;
                isFirstAssignment = true;
            }
        }

        if (var) {
            leftVar = CDotVar::create(loc, leftVar->scope.lock(), parentVar, leftVar);
        }

        auto leftType = leftVar->getType(compiler, result);
        auto rightVar = rightSide->getVar(compiler, result, thisFunction, thisVar, leftType->typeMode);
        if (!rightVar) {
            assert(result.errors.size() > 0);
            return nullptr;
        }

        auto leftStoreVar = dynamic_pointer_cast<CStoreVar>(leftVar);
        if (!leftStoreVar) {
            assert(false);
        }
        return make_shared<CAssignVar>(loc, leftVar->scope.lock(), op, isFirstAssignment, leftStoreVar, rightVar);
    }

    return nullptr;
}

shared_ptr<CType> NAssignment::getType(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode) {
    assert(compiler->state >= CompilerState::FixVar);

    if (typeName) {
        auto valueType = thisFunction->getVarType(loc, compiler, result, typeName, returnMode);
        if (!valueType) {
            result.addError(loc, CErrorCode::InvalidType, "explicit type '%s' does not exist", typeName->name.c_str());
            return nullptr;
        }
        return valueType;
    }
    
    if (!rightSide) {
        result.addError(loc, CErrorCode::Internal, "only required assignment should not have a right side, and they must have typeName");
        return nullptr;
    }
    
    auto rightVar = rightSide->getVar(compiler, result, thisFunction, thisVar, returnMode);
    if (!rightVar) {
        result.addError(loc, CErrorCode::Internal, "no right side");
        return nullptr;
    }
    
    return rightVar->getType(compiler, result);
}

shared_ptr<NAssignment> NAssignment::shared_from_this() {
    return static_pointer_cast<NAssignment>(NBase::shared_from_this());
}

