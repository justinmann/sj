#include "Node.h"

shared_ptr<CCallVar> CCallVar::create(CLoc loc_, const string& name_, shared_ptr<NodeList> arguments_, shared_ptr<CFunction> thisFunction_, weak_ptr<CVar> dotVar_, shared_ptr<CFunction> callee_) {
    assert(callee_);

    auto c = make_shared<CCallVar>();
    c->name = name_;
    c->mode = Local;
    c->isMutable = true;
    c->nassignment = nullptr;
    c->loc = loc_;
    c->arguments = arguments_;
    c->thisFunction = thisFunction_;
    c->dotVar = dotVar_;
    c->callee = callee_;
    return c;
}

shared_ptr<CType> CCallVar::getType(Compiler* compiler, CResult& result) {
    return callee->getReturnType(compiler, result);
}

Value* CCallVar::getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    // compiler->emitLocation(call.get());
    
    if (arguments->size() > callee->node->assignments.size()) {
        result.addError(loc, CErrorCode::TooManyParameters, "passing %d, but expecting max of %d", arguments->size(), callee->node->assignments.size());
        return nullptr;
    }
    
    // Fill in parameters
    vector<shared_ptr<NBase>> parameters(callee->node->assignments.size());
    auto argIndex = 0;
    auto hasSetByName = false;
    for (auto it : *arguments) {
        if (it->nodeType == NodeType_Assignment) {
            auto parameterAssignment = static_pointer_cast<NAssignment>(it);
            assert(parameterAssignment->inFunctionDeclaration);
            auto index = callee->getThisIndex(parameterAssignment->name);
            if (index < 0) {
                result.addError(loc, CErrorCode::ParameterDoesNotExist, "cannot find parameter '%s'", parameterAssignment->name.c_str());
                return nullptr;
            }
            
            if (parameters[index] != nullptr) {
                result.addError(loc, CErrorCode::ParameterRedefined, "defined parameter '%s' twice", parameterAssignment->name.c_str());
                return nullptr;
            }
            
            parameters[index] = parameterAssignment->rightSide;
            hasSetByName = true;
        } else {
            if (hasSetByName) {
                result.addError(loc, CErrorCode::ParameterByIndexAfterByName, "all named parameters must be after the un-named parameters");
                return nullptr;
            }
            
            if (parameters[argIndex] != nullptr) {
                result.addError(loc, CErrorCode::Internal, "re-defining the same parameters which should be impossible for un-named parameters");
                return nullptr;
            }
            
            parameters[argIndex] = it;
        }
        argIndex++;
    }
    
    argIndex = 0;
    for (auto it : callee->node->assignments) {
        if (parameters[argIndex] == nullptr) {
            auto defaultAssignment = static_pointer_cast<NAssignment>(it);
            assert(defaultAssignment->inFunctionDeclaration);
            if (!defaultAssignment->rightSide) {
                result.addError(loc, CErrorCode::ParameterRequired, "must assign value to parameter '%s'", it->name.c_str());
                return nullptr;
            }
            parameters[argIndex] = defaultAssignment->rightSide;
        }
        argIndex++;
    }
    
    return callee->node->call(compiler, result, thisFunction, thisValue, callee, dotVar.lock(), builder, catchBB, parameters);
}

Value* CCallVar::getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    result.addError(loc, CErrorCode::ImmutableAssignment, "cannot assign value to function result");
    return nullptr;
}

string CCallVar::fullName() {
    return name + "()";
}

bool CCallVar::getHeapVar(Compiler* compiler, CResult& result) {
    auto returnVar = thisFunction->getReturnVar(compiler, result);
    if (returnVar) {
        return returnVar->getHeapVar(compiler, result);
    }
    return false;
}

int CCallVar::setHeapVar(Compiler* compiler, CResult& result) {
    auto returnVar = callee->getReturnVar(compiler, result);
    if (returnVar) {
        return returnVar->setHeapVar(compiler, result);
    }
    return 0;
}

NCall::NCall(CLoc loc, const char* name, shared_ptr<TemplateTypeNames> templateTypeNames, shared_ptr<NodeList> arguments) : name(name), templateTypeNames(templateTypeNames), arguments(arguments), NVariableBase(NodeType_Call, loc) {
    if (!this->arguments) {
        this->arguments = make_shared<NodeList>();
    } else {
        for (auto it : *arguments) {
            if (it->nodeType == NodeType_Assignment) {
                auto parameterAssignment = static_pointer_cast<NAssignment>(it);
                parameterAssignment->inFunctionDeclaration = true;
            }
        }
    }
}

void NCall::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    for (auto it : *arguments) {
        if (it->nodeType == NodeType_Assignment) {
            auto parameterAssignment = static_pointer_cast<NAssignment>(it);
            parameterAssignment->define(compiler, result, thisFunction);
        } else {
            it->define(compiler, result, thisFunction);
        }
    }
}

shared_ptr<CFunction> NCall::getCFunction(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar) {
    assert(compiler->state >= CompilerState::FixVar);
    
    // parentFunction will be specified if the NCall is used as the default NAssignment for a NFunction
    auto cfunction = thisFunction;
    
    if (dotVar) {
        cfunction = dotVar->getCFunctionForValue(compiler, result);
        if (!cfunction) {
            result.addError(loc, CErrorCode::InvalidVariable, "parent is not a function: '%s'", dotVar->fullName().c_str());
            return nullptr;
        }
    }
    
    // Handle last name in list
    auto callee = cfunction->getCFunction(compiler, result, loc, name, thisFunction, templateTypeNames);
    if (!callee) {
        // If we are still using "this" then we can check to see if it is a function on parent
        if (cfunction == thisFunction) {
            while (cfunction && !cfunction->parent.expired() && !callee) {
                cfunction = cfunction->parent.lock();
                if (cfunction) {
                    callee = cfunction->getCFunction(compiler, result, loc, name, thisFunction, templateTypeNames);
                }
            }
        }
    }
    
    if (!callee) {
        result.addError(loc, CErrorCode::UnknownFunction, "function '%s' does not exist", name.c_str());
        return nullptr;
    }
    
    return callee;
}

shared_ptr<CVar> NCall::getVarImpl(Compiler *compiler, CResult &result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar) {
    auto callee = getCFunction(compiler, result, thisFunction, dotVar);
    if (!callee) {
        return nullptr;
    }
    
    for (auto it : *arguments) {
        if (it->nodeType == NodeType_Assignment) {
            auto parameterAssignment = static_pointer_cast<NAssignment>(it);
            assert(parameterAssignment->inFunctionDeclaration);
            parameterAssignment->getVar(compiler, result, thisFunction);
        } else {
            it->getVar(compiler, result, thisFunction);
        }
    }
    
    return CCallVar::create(loc, name, arguments, thisFunction, dotVar, callee);
}

int NCall::setHeapVarImpl(Compiler *compiler, CResult &result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar, bool isHeapVar) {
    auto count = 0;
    for (auto it : *arguments) {
        if (it->nodeType == NodeType_Assignment) {
            auto parameterAssignment = static_pointer_cast<NAssignment>(it);
            assert(parameterAssignment->inFunctionDeclaration);
            count += parameterAssignment->setHeapVar(compiler, result, thisFunction, isHeapVar);
        } else {
            count += it->setHeapVar(compiler, result, thisFunction, isHeapVar);
        }
    }

    if (isHeapVar) {
        auto var = getVar(compiler, result, thisFunction, dotVar);
        count += var->setHeapVar(compiler, result);
    }
    return count;
}

void NCall::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NCall'");
    dumpf(level, "functionName: '%s'", name.c_str());

    if (arguments->size() > 0) {
        dumpf(level, "arguments: {");
        auto argIndex = 0;
        for (auto it : *arguments) {
            if (it->nodeType == NodeType_Assignment) {
                auto parameterAssignment = static_pointer_cast<NAssignment>(it);
                assert(parameterAssignment->inFunctionDeclaration);
                dumpf(level + 1, "%s: {", parameterAssignment->name.c_str());
                parameterAssignment->dump(compiler, level + 2);
                dumpf(level + 1, "}");
            } else {
                dumpf(level + 1, "'%d': {", argIndex);
                it->dump(compiler, level + 2);
                dumpf(level + 1, "}");
            }
            argIndex ++;
        }
        dumpf(level, "}");
    }
}

