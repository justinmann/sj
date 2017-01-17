#include "Node.h"

NCall::NCall(CLoc loc, const char* name, shared_ptr<TemplateTypeNames> templateTypeNames, NodeList arguments) : templateTypeNames(templateTypeNames), arguments(arguments), NBase(loc) {
    istringstream f(name);
    string s;
    while (getline(f, s, '.')) {
        dotNames.push_back(s);
    }
    functionName = dotNames.back();
    dotNames.pop_back();

    for (auto it : arguments) {
        if (it->getNodeType() == NodeType_Assignment) {
            auto parameterAssignment = static_pointer_cast<NAssignment>(it);
            parameterAssignment->inFunctionDeclaration = true;
        }
    }
}

NodeType NCall::getNodeType() const {
    return NodeType_Call;
}

void NCall::define(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    for (auto it : arguments) {
        if (it->getNodeType() == NodeType_Assignment) {
            auto parameterAssignment = static_pointer_cast<NAssignment>(it);
            parameterAssignment->define(compiler, result, thisFunction);
        } else {
            it->define(compiler, result, thisFunction);
        }
    }
}

void NCall::fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {    
    assert(compiler->state == CompilerState::FixVar);
    auto callee = getCFunction(compiler, result, thisFunction, nullptr, nullptr);
    if (!callee) {
        return;
    }

    for (auto it : arguments) {
        if (it->getNodeType() == NodeType_Assignment) {
            auto parameterAssignment = static_pointer_cast<NAssignment>(it);
            assert(parameterAssignment->inFunctionDeclaration);
            parameterAssignment->fixVar(compiler, result, thisFunction);
        } else {
            it->fixVar(compiler, result, thisFunction);
        }
    }
}

shared_ptr<CFunction> NCall::getCFunction(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder) const {
    assert(compiler->state >= CompilerState::FixVar);

    // parentFunction will be specified if the NCall is used as the default NAssignment for a NFunction
    auto cfunction = thisFunction;
    
    // If more than one name in the list, then we need to iterate down to correct function
    if (dotNames.size() > 0) {
        auto cvar = NVariable::getParentValue(compiler, result, loc, thisFunction, thisValue, builder, dotNames, VT_LOAD, nullptr);
        if (!cvar) {
            result.addError(loc, CErrorCode::UnknownFunction, "function '%s' does not exist", dotNames.back().c_str());
            return nullptr;
        }
        
        cfunction = cvar->getCFunctionForValue(compiler, result);

        if (!cfunction) {
            result.addError(loc, CErrorCode::UnknownFunction, "function '%s' does not exist", dotNames.back().c_str());
            return nullptr;
        }
    }
    
    // Handle last name in list
    auto callee = cfunction->getCFunction(compiler, result, loc, functionName, templateTypeNames);
    if (!callee) {
        // If we are still using "this" then we can check to see if it is a function on parent
        if (cfunction == thisFunction) {
            while (cfunction && !cfunction->parent.expired() && !callee) {
                cfunction = cfunction->parent.lock();
                if (cfunction) {
                    callee = cfunction->getCFunction(compiler, result, loc, functionName, templateTypeNames);
                }
            }
        }
    }
    
    if (!callee) {
        result.addError(loc, CErrorCode::UnknownFunction, "function '%s' does not exist", functionName.c_str());
        return nullptr;
    }
    
    return callee;
}

shared_ptr<CType> NCall::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    auto callee = getCFunction(compiler, result, thisFunction, nullptr, nullptr);
    if (!callee) {
        return nullptr;
    }
    
    auto type = callee->getReturnType(compiler, result);
    
    return type;
}

Value* NCall::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    auto callee = getCFunction(compiler, result, thisFunction, thisValue, builder);
    if (!callee) {
        return nullptr;
    }
    
    if (arguments.size() > callee->node->assignments.size()) {
        result.addError(loc, CErrorCode::TooManyParameters, "passing %d, but expecting max of %d", arguments.size(), callee->node->assignments.size());
        return nullptr;
    }
    
    // Fill in parameters
    vector<shared_ptr<NBase>> parameters(callee->node->assignments.size());
    auto argIndex = 0;
    auto hasSetByName = false;
    for (auto it : arguments) {
        if (it->getNodeType() == NodeType_Assignment) {
            auto parameterAssignment = static_pointer_cast<NAssignment>(it);
            assert(parameterAssignment->inFunctionDeclaration);
            auto index = callee->getThisIndex(parameterAssignment->names[0]);
            if (index < 0) {
                result.addError(loc, CErrorCode::ParameterDoesNotExist, "cannot find parameter '%s'", parameterAssignment->fullName.c_str());
                return nullptr;
            }
            
            if (parameters[index] != nullptr) {
                result.addError(loc, CErrorCode::ParameterRedefined, "defined parameter '%s' twice", parameterAssignment->fullName.c_str());
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
                result.addError(loc, CErrorCode::ParameterRequired, "must assign value to parameter '%s'", it->fullName.c_str());
                return nullptr;
            }
            parameters[argIndex] = defaultAssignment->rightSide;
        }
        argIndex++;
    }
    
    return callee->node->call(compiler, result, thisFunction, thisValue, callee, builder, catchBB, dotNames, parameters);
}

void NCall::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NCall'");
    dumpf(level, "functionName: '%s'", functionName.c_str());

    if (arguments.size() > 0) {
        dumpf(level, "arguments: {");
        auto argIndex = 0;
        for (auto it : arguments) {
            if (it->getNodeType() == NodeType_Assignment) {
                auto parameterAssignment = static_pointer_cast<NAssignment>(it);
                assert(parameterAssignment->inFunctionDeclaration);
                dumpf(level + 1, "%s: {", parameterAssignment->fullName.c_str());
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

