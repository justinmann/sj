#include "Node.h"

shared_ptr<CType> CAssignVar::getType(Compiler* compiler, CResult& result) {
    return rightVar->getType(compiler, result);
}

shared_ptr<ReturnValue> CAssignVar::transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    assert(compiler->state == CompilerState::Compile);
   
    auto leftType = leftVar->getType(compiler, result);
    auto rightReturn = rightVar->transpileGet(compiler, result, thisFunction, thisVar, trOutput, trBlock, leftType->typeMode, nullptr, thisName);
    if (!rightReturn) {
        result.addError(loc, CErrorCode::TypeMismatch, "no return value");
        return nullptr;
    }
    
    if (leftType != rightReturn->type) {
        result.addError(loc, CErrorCode::TypeMismatch, "returned type '%s' does not match explicit type '%s'", rightReturn->type->name.c_str(), leftType->name.c_str());
        return nullptr;
    }

    leftVar->transpileSet(compiler, result, thisFunction, thisVar, trOutput, trBlock, nullptr, rightReturn, thisName);
    
    return rightReturn;
}

void CAssignVar::transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) {
    assert(false);
}

void CAssignVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    auto type = getType(compiler, result);
    leftVar->dump(compiler, result, thisFunction, thisVar, returnMode, dotVar, functions, ss, dotSS, level);
    auto leftType = leftVar->getType(compiler, result);
    ss << "'" << (leftType ? leftType->name.c_str() : "unknown");
    ss << (isMutable ? " = " : " : ");
    if (rightVar) {
        rightVar->dump(compiler, result, thisFunction, thisVar, returnMode, nullptr, functions, ss, dotSS, level);
    } else {
        ss << "undefined";
    }
}

NAssignment::NAssignment(CLoc loc, shared_ptr<NVariableBase> var, shared_ptr<CTypeName> typeName, const char* name, shared_ptr<NBase> rightSide_, bool isMutable) : NBase(NodeType_Assignment, loc), var(var), typeName(typeName), name(name), inFunctionDeclaration(false), rightSide(rightSide_), isMutable(isMutable), _isFirstAssignment(false) {
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

shared_ptr<CVar> NAssignment::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);

    // function vars are not created here, this is only for local vars
    if (inFunctionDeclaration) {
        return nullptr;
    }
    
    // We need to see if var already exists, if not create a new local var
    auto cfunction = thisFunction;
    shared_ptr<CVar> parentVar = nullptr;
    if (var) {
        parentVar = var->getVar(compiler, result, thisFunction, thisVar, nullptr);
        if (!parentVar) {
            return nullptr;
        }

        auto parentType = parentVar->getType(compiler, result);
        cfunction = static_pointer_cast<CFunction>(parentType->parent.lock());
        if (!cfunction) {
            result.addError(loc, CErrorCode::InvalidVariable, "var must be a function");
            return nullptr;
        }
    }
    
    // Check for operator overload first
    string temp = name;
    temp[0] = toupper(temp[0]);
    string setFunctionName = "set" + temp;
    auto setFunction = cfunction->getCFunction(compiler, result, setFunctionName, thisFunction, nullptr);
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
            if (!isMutable) {
                result.addError(loc, CErrorCode::ImmutableAssignment, "immutable assignment to existing var '%s'", name.c_str());
                return nullptr;
            }
            else if (!isMutable) {
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
                leftVar = CNormalVar::createLocalVar(loc, name, thisFunction, shared_from_this());
                fun->localVarsByName[name] = _assignVar;
                isFirstAssignment = true;
            }
        }

        if (var) {
            leftVar = CDotVar::create(loc, parentVar, leftVar);
        }

        auto rightVar = rightSide->getVar(compiler, result, thisFunction, thisVar);
        if (!rightVar) {
            assert(false);
        }
        return make_shared<CAssignVar>(loc, isMutable, leftVar, rightVar);
    }

    return nullptr;
}

shared_ptr<CType> NAssignment::getType(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode) {
    assert(compiler->state >= CompilerState::FixVar);

    if (typeName) {
        auto valueType = thisFunction->getVarType(compiler, result, typeName);
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
    
    auto rightVar = rightSide->getVar(compiler, result, thisFunction, thisVar);
    if (!rightVar) {
        assert(false);
        return nullptr;
    }
    
    return rightVar->getType(compiler, result);
}

shared_ptr<NAssignment> NAssignment::shared_from_this() {
    return static_pointer_cast<NAssignment>(NBase::shared_from_this());
}

