#include "Node.h"

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

shared_ptr<CVar> NAssignment::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);

    // function vars are not created here, this is only for local vars
    if (!inFunctionDeclaration) {
        // We need to see if var already exists, if not create a new local var
        auto cfunction = thisFunction;
        shared_ptr<CVar> parentVar = nullptr;
        if (var) {
            parentVar = var->getVar(compiler, result, thisFunction, thisVar, nullptr);
            if (!parentVar) {
                return nullptr;
            }
            cfunction = static_pointer_cast<CFunction>(parentVar->getCFunctionForValue(compiler, result));
            if (!cfunction) {
                result.addError(loc, CErrorCode::InvalidVariable, "var must be a function: '%s'", parentVar->fullName().c_str());
                return nullptr;
            }
        }
        
        _assignVar = cfunction->getCVar(compiler, result, name);
        if (_assignVar) {
            if (!isMutable) {
                result.addError(loc, CErrorCode::ImmutableAssignment, "immutable assignment to existing var");
                return nullptr;
            } else if (!_assignVar->isMutable) {
                result.addError(loc, CErrorCode::ImmutableAssignment, "immutable assignment to existing var");
                return nullptr;
            }
        } else {
            if (!var) {
                auto fun = static_pointer_cast<CFunction>(cfunction);
            
                auto iter = fun->localVarsByName.find(name);
                if (iter != fun->localVarsByName.end()) {
                    result.addError(loc, CErrorCode::Internal, "the previous search on NVariable should find a local value with same name");
                    return nullptr;
                }
                _assignVar = CNormalVar::createLocalVar(loc, name, thisFunction, shared_from_this());
                fun->localVarsByName[name] = _assignVar;
                _isFirstAssignment = true;
            }
        }
        
        if (var) {
            _assignVar = CDotVar::create(parentVar, _assignVar);
        }
    }
    
    if (nfunction) {
        nfunction->getVar(compiler, result, thisFunction, thisVar);
    }
    
    if (rightSide) {
        return rightSide->getVar(compiler, result, thisFunction, thisVar);
    }
    
    return nullptr;
}

shared_ptr<CType> NAssignment::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);

    if (typeName) {
        auto valueType = thisFunction->getVarType(compiler, result, typeName);
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
    
    return rightSide->getType(compiler, result, thisFunction, thisVar);
}

int NAssignment::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    auto count = 0;
    
    if (_assignVar != nullptr && _assignVar->mode != Var_Local) {
        // TODO: does not need to be a heap var if parent is a local var
        isHeapVar = true;
    }
    
    if (rightSide) {
        count += rightSide->setHeapVar(compiler, result, thisFunction, thisVar, isHeapVar);
        
        // Check if right side is heap, if so the var being assigned must also be heap
        if (_assignVar) {
            auto rightVar = rightSide->getVar(compiler, result, thisFunction, thisVar);
            if (rightVar && rightVar->getHeapVar(compiler, result, thisVar)) {
                count += _assignVar->setHeapVar(compiler, result, thisVar);
            }
            
            if (rightVar) {
                auto t = rightVar->getType(compiler, result);
                if (!t->parent.expired()) {
                    t->parent.lock()->setHasRefCount();
                }
            }
        }
    }
    
    return count;
}

shared_ptr<ReturnValue> NAssignment::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, stringstream& trLine) {
	assert(compiler->state == CompilerState::Compile);
	    
	if (!rightSide) {
	    result.addError(loc, CErrorCode::Internal, "only required assignment should not have a right side, and they should not be compiled");
		return nullptr;
	}
		    
    auto leftReturn = _assignVar->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, trLine, nullptr);    
    if (_assignVar->mode == Var_Local) {
        auto var = trBlock->getVariable(_assignVar->name);
        if (!var) {
            auto assignVarFunction = _assignVar->getCFunctionForValue(compiler, result);
            var = trBlock->createVariable(
                _assignVar->name, leftReturn->type->nameRef,
                assignVarFunction && _assignVar->getHeapVar(compiler, result, thisVar) ? TRM_RELEASE : TRM_DONOTHING,
                assignVarFunction ? assignVarFunction->getCDestroyFunctionName() : "");
        } else {
            if (!isMutable) {
                result.addError(loc, CErrorCode::ImmutableAssignment, "immutable assignment to existing var");
                return nullptr;
            }
        }
    }
    
	trLine << " = ";

    stringstream rightLine;
	auto rightReturn = rightSide->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, rightLine);
	if (rightReturn->type != leftReturn->type) {
		result.addError(loc, CErrorCode::TypeMismatch, "returned type '%s' does not match explicit type '%s'", rightReturn ? rightReturn->type->name.c_str() : "empty", leftReturn ? leftReturn->type->name.c_str() : "empty");
		return nullptr;
	}
    trLine << rightLine.str();

	return leftReturn;
}

//shared_ptr<ReturnValue> NAssignment::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    assert(compiler->state == CompilerState::Compile);
//    compiler->emitLocation(builder, &this->loc);
//    
//    if (!rightSide) {
//        result.addError(loc, CErrorCode::Internal, "only required assignment should not have a right side, and they should not be compiled");
//        return nullptr;
//    }
//
//    if (!inFunctionDeclaration && nfunction) {
//        nfunction->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, RRT_Auto);
//    }
//    
//    // Compute value
//    auto value = rightSide->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, returnRefType);
//    if (!value) {
//        result.addError(loc, CErrorCode::ExpressionEmpty, "trying to assign an empty value");
//        return nullptr;
//    }
//    
//    if (typeName) {
//        shared_ptr<CType> valueType = thisFunction->getVarType(compiler, result, typeName);
//        if (!valueType) {
//            result.addError(loc, CErrorCode::InvalidType, "explicit type does not exist");
//            return nullptr;
//        }
//
//        if (value->value->getType() != valueType->llvmRefType(compiler, result)) {
//            result.addError(loc, CErrorCode::TypeMismatch, "returned type '%s' does not match explicit type '%s'", Type_print(value->value->getType()).c_str(), Type_print(valueType->llvmRefType(compiler, result)).c_str());
//            return nullptr;
//        }
//    }
//    
//    value->retainIfNeeded(compiler, result, builder);
//    
//    // Get place to store data
//    auto alloca = _assignVar->getStoreValue(compiler, result, thisVar, thisValue, true, thisValue, builder, catchBB);
//    if (!alloca) {
//        result.addError(loc, CErrorCode::InvalidVariable, "var cannot be assigned '%s'", name.c_str());
//        return nullptr;
//    }
//    
//    if (value->valueFunction && !_isFirstAssignment) {
//        auto currentValue = builder->CreateLoad(alloca);
//        value->valueFunction->releaseHeap(compiler, result, builder, currentValue);
//    }
//    
//    // Store value
//    builder->CreateStore(value->value, alloca);
//    return make_shared<ReturnValue>(value->valueFunction, RVR_MustRetain, value->type, value->inEntry, value->value);
//}

void NAssignment::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    auto type = getType(compiler, result, thisFunction, thisVar);
    if (_assignVar) {
        ss << alloc_mode(compiler, result, thisVar, _assignVar);
    }
    ss << name;
    ss << "'" << (type ? type->name.c_str() : "unknown");
    ss << (isMutable ? " = " : " : ");
    if (rightSide) {
        rightSide->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
    } else {
        ss << "undefined";
    }
}

shared_ptr<NAssignment> NAssignment::shared_from_this() {
    return static_pointer_cast<NAssignment>(NBase::shared_from_this());
}

