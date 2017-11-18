#include "Node.h"

shared_ptr<CCallVar> CCallVar::create(Compiler* compiler, CResult& result, CLoc loc_, const string& name_, shared_ptr<NodeList> arguments_, shared_ptr<CBaseFunction> thisFunction_, shared_ptr<CThisVar> thisVar, weak_ptr<CVar> dotVar_, shared_ptr<CBaseFunction> callee_) {
    assert(callee_);

    auto c = make_shared<CCallVar>(loc_);
    c->arguments = arguments_;
    c->thisFunction = thisFunction_;
    c->dotVar = dotVar_;
    c->callee = callee_;
    
    auto onHasParent = [callee_, thisFunction_](Compiler* compiler, CResult& result) {
        if (callee_ == thisFunction_) {
            callee_->setHasParent(compiler, result);
        } else {
            auto temp = static_pointer_cast<CBaseFunction>(thisFunction_);
            while (temp && temp != callee_->parent.lock()) {
                auto nextParent = temp->parent.lock();
                // If my parent does not have a parent then leave off the parent
                if (nextParent != nullptr && !nextParent->parent.expired()) {
                    temp->setHasParent(compiler, result);
                }
                temp = nextParent;
            }
        }
    };
    
    if (callee_->getHasParent(compiler, result)) {
        onHasParent(compiler, result);
    } else {
        callee_->onHasParent(onHasParent);
    }

    return c;
}

shared_ptr<CType> CCallVar::getType(Compiler* compiler, CResult& result) {
    return callee->getReturnType(compiler, result, CTM_MatchReturn);
}

bool CCallVar::getParameters(Compiler* compiler, CResult& result, vector<pair<bool, shared_ptr<NBase>>>& parameters) {
    if (parameters.size() < arguments->size()) {
        result.addError(loc, CErrorCode::TooManyParameters, "too many parameters");
        return false;
    }
    
    auto argIndex = (size_t)0;
    auto hasSetByName = false;
    for (auto it : *arguments) {
        if (it->nodeType == NodeType_Assignment) {
            auto parameterAssignment = static_pointer_cast<NAssignment>(it);
            assert(parameterAssignment->inFunctionDeclaration);
            auto index = callee->getThisIndex(parameterAssignment->name);
            if (index < 0) {
                result.addError(loc, CErrorCode::ParameterDoesNotExist, "cannot find parameter '%s'", parameterAssignment->name.c_str());
                return false;
            }
            
            if (parameters[index].second != nullptr) {
                result.addError(loc, CErrorCode::ParameterRedefined, "defined parameter '%s' twice", parameterAssignment->name.c_str());
                return false;
            }
            
            parameters[index] = make_pair(false, parameterAssignment->rightSide);
            hasSetByName = true;
        } else {
            if (hasSetByName) {
                result.addError(loc, CErrorCode::ParameterByIndexAfterByName, "all named parameters must be after the un-named parameters");
                return false;
            }
            
            if (parameters[argIndex].second != nullptr) {
                result.addError(loc, CErrorCode::Internal, "re-defining the same parameters which should be impossible for un-named parameters");
                return false;
            }
            
            parameters[argIndex] = make_pair(false, it);
        }
        argIndex++;
    }
    
    argIndex = 0;
    for (auto it : callee->argDefaultValues) {
        if (argIndex < parameters.size() && parameters[argIndex].second == nullptr) {
            if (it == nullptr) {
                result.addError(loc, CErrorCode::ParameterRequired, "parameter %d is required", argIndex);
                return false;
            }
            assert(it->nodeType != NodeType_Assignment);
            parameters[argIndex] = make_pair(true, it);
        }
        argIndex++;
    }
    
    return true;
}

shared_ptr<ReturnValue> CCallVar::transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    assert(compiler->state == CompilerState::Compile);

    if (arguments->size() > callee->argDefaultValues.size()) {
        result.addError(loc, CErrorCode::TooManyParameters, "passing %d, but expecting max of %d", arguments->size(), callee->argDefaultValues.size());
        return nullptr;
    }

    // Fill in parameters
    vector<pair<bool, shared_ptr<NBase>>> parameters(callee->argDefaultValues.size());
    if (!getParameters(compiler, result, parameters)) {
        return nullptr;
    }

    auto returnValue = callee->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, dotValue, loc, parameters, thisName, returnMode);
    assert(returnValue != nullptr);
    return returnValue;
}

void CCallVar::transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) {
    assert(false);
}


void CCallVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    if (functions.find(callee) == functions.end()) {
        functions[callee] = "";
        stringstream temp;
        callee->dumpBody(compiler, result, returnMode, functions, temp, 0);
        functions[callee] = temp.str();
    }

    ss << callee->fullName(true) << "(";

    vector<pair<bool, shared_ptr<NBase>>> parameters(callee->argDefaultValues.size());
    if (!getParameters(compiler, result, parameters)) {
        return;
    }

    if (callee->getHasThis()) {
        ss << "this" << " = ";
        ss << callee->fullName(true) << "(";

        if (parameters.size() > 0 || callee->getHasParent(compiler, result)) {
            ss << "\n";
            dumpf(ss, level + 1);

            if (callee->getHasParent(compiler, result)) {
                ss << "parent: ";
                auto t = dotSS.str();
                if (t.size() > 0) {
                    ss << t;
                } else {
                    ss << "this";
                }

                if (parameters.size() > 0) {
                    ss << ",\n";
                    dumpf(ss, level + 1);
                }
            }

            auto paramIndex = (size_t)0;
            for (auto it : parameters) {
                auto paramVar = callee->argVars[paramIndex];
                ss << paramVar->name.c_str();
                auto ctype = paramVar->getType(compiler, result);
                ss << "'" << (ctype != nullptr ? ctype->name : "ERROR");
                ss << (paramVar->isMutable ? " = " : " : ");
                // TODO: it.second->dump(compiler, result, it.first ? callee : thisFunction, thisVar, CTM_Undefined, functions, ss, level + 1);
                if (paramIndex != parameters.size() - 1) {
                    ss << ",\n";
                    dumpf(ss, level + 1);
                }
                paramIndex++;
            }
            ss << "\n";
            dumpf(ss, level);
        }
        ss << "))";
    } else {
        if (parameters.size() > 0 || callee->getHasParent(compiler, result)) {
            ss << "\n";
            dumpf(ss, level + 1);

            if (callee->getHasParent(compiler, result)) {
                ss << "parent: ";
                auto t = dotSS.str();
                if (t.size() > 0) {
                    ss << t;
                } else {
                    ss << "this";
                }

                if (parameters.size() > 0) {
                    ss << ",\n";
                    dumpf(ss, level + 1);
                }
            }

            auto paramIndex = (size_t)0;
            for (auto it : parameters) {
                auto paramVar = callee->argVars[paramIndex];
                ss << paramVar->name.c_str();
                ss << "'" << paramVar->getType(compiler, result)->name.c_str();
                ss << (paramVar->isMutable ? " = " : " : ");
                // TODO: it.second->dump(compiler, result, thisFunction, thisVar, CTM_Undefined, functions, ss, level + 1);
                if (paramIndex != parameters.size() - 1) {
                    ss << ",\n";
                    dumpf(ss, level + 1);
                }
                paramIndex++;
            }
            ss << "\n";
            dumpf(ss, level);
        }
        ss << ")";
    }
}


NCall::NCall(CLoc loc, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<NodeList> arguments) : NVariableBase(NodeType_Call, loc), name(name), templateTypeNames(templateTypeNames), arguments(arguments) {
    if (!this->arguments) {
        this->arguments = make_shared<NodeList>();
    } else {
        for (auto it : *arguments) {
            if (it != nullptr && it->nodeType == NodeType_Assignment) {
                auto parameterAssignment = static_pointer_cast<NAssignment>(it);
                parameterAssignment->inFunctionDeclaration = true;
            }
        }
    }
}

void NCall::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
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

shared_ptr<CBaseFunction> NCall::getCFunction(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> dotVar) {
    assert(compiler->state >= CompilerState::FixVar);
    
    // parentFunction will be specified if the NCall is used as the default NAssignment for a NFunction
    auto cfunction = static_pointer_cast<CBaseFunction>(thisFunction);
    
    if (dotVar) {
        cfunction = dotVar->getType(compiler, result)->parent.lock();
        if (!cfunction) {
            result.addError(loc, CErrorCode::InvalidVariable, "parent is not a function");
            return nullptr;
        }
    }
    
    // Handle last name in list
    auto callee = cfunction->getCFunction(compiler, result, name, thisFunction, templateTypeNames);
    if (!callee) {
        // If we are still using "this" then we can check to see if it is a function on parent
        if (cfunction == thisFunction) {
            while (cfunction && !cfunction->parent.expired() && !callee) {
                cfunction = cfunction->parent.lock();
                if (cfunction) {
                    callee = cfunction->getCFunction(compiler, result, name, thisFunction, templateTypeNames);
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

shared_ptr<CVar> NCall::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar) {
    auto callee = getCFunction(compiler, result, thisFunction, dotVar);
    if (!callee) {
        return nullptr;
    }
    
    if (!_callVar) {
        _callVar = CCallVar::create(compiler, result, loc, name, arguments, thisFunction, thisVar, dotVar, callee);
        if (!_callVar) {
            return nullptr;
        }
    }
    return _callVar;
}
