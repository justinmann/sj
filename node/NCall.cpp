#include "Node.h"

shared_ptr<CCallVar> CCallVar::create(Compiler* compiler, CLoc loc_, const string& name_, shared_ptr<NodeList> arguments_, shared_ptr<CScope> scope, weak_ptr<CVar> dotVar_, shared_ptr<CBaseFunction> callee_, CTypeMode returnMode) {
    assert(callee_);

    if (returnMode == CTM_Undefined || returnMode == CTM_Value || returnMode == CTM_Local) {
        returnMode = CTM_Stack;
    }
    
    auto c = make_shared<CCallVar>(loc_, scope, returnMode);
    c->arguments = arguments_;
    c->scope = scope;
    c->dotVar = dotVar_;
    c->callee = callee_;
    
    auto onHasParent = [callee_, scope](Compiler* compiler) {
        if (callee_ == scope->function) {
            callee_->setHasParent(compiler);
        } else {
            auto temp = static_pointer_cast<CBaseFunction>(scope->function);
            while (temp && temp != callee_->parent.lock()) {
                auto nextParent = temp->parent.lock();
                // If my parent does not have a parent then leave off the parent
                if (nextParent != nullptr && !nextParent->parent.expired()) {
                    temp->setHasParent(compiler);
                }
                temp = nextParent;
            }
        }
    };
    
    if (callee_->getHasParent(compiler)) {
        onHasParent(compiler);
    } else {
        callee_->onHasParent(onHasParent);
    }

    return c;
}

bool CCallVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CCallVar::getType(Compiler* compiler) {
    return callee->getReturnType(compiler, returnMode);
}

bool CCallVar::getParameters(Compiler* compiler, vector<pair<bool, shared_ptr<NBase>>>& parameters) {
    if (parameters.size() < arguments->size()) {
        compiler->addError(loc, CErrorCode::TooManyParameters, "too many parameters");
        return false;
    }
    
    auto argIndex = (size_t)0;
    auto hasSetByName = false;
    for (auto it : *arguments) {
        if (it->nodeType == NodeType_Assignment) {
            auto parameterAssignment = static_pointer_cast<NAssignment>(it);
            assert(parameterAssignment->inFunctionDeclaration);
            auto index = callee->getArgIndex(parameterAssignment->name, returnMode);
            if (index < 0) {
                compiler->addError(loc, CErrorCode::ParameterDoesNotExist, "cannot find parameter '%s'", parameterAssignment->name.c_str());
                return false;
            }
            
            if (parameters[index].second != nullptr) {
                compiler->addError(loc, CErrorCode::ParameterRedefined, "defined parameter '%s' twice", parameterAssignment->name.c_str());
                return false;
            }
            
            parameters[index] = make_pair(false, parameterAssignment->rightSide);
            hasSetByName = true;
        } else {
            if (hasSetByName) {
                compiler->addError(loc, CErrorCode::ParameterByIndexAfterByName, "all named parameters must be after the un-named parameters");
                return false;
            }
            
            if (parameters[argIndex].second != nullptr) {
                compiler->addError(loc, CErrorCode::Internal, "re-defining the same parameters which should be impossible for un-named parameters");
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
                compiler->addError(loc, CErrorCode::ParameterRequired, "parameter %d is required", argIndex);
                return false;
            }
            assert(it->nodeType != NodeType_Assignment);
            parameters[argIndex] = make_pair(true, it);
        }
        argIndex++;
    }
    
    return true;
}

void CCallVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    assert(compiler->state == CompilerState::Compile);

    if (arguments->size() > callee->argDefaultValues.size()) {
        compiler->addError(loc, CErrorCode::TooManyParameters, "passing %d, but expecting max of %d", arguments->size(), callee->argDefaultValues.size());
        return;
    }

    // Fill in parameters
    vector<pair<bool, shared_ptr<NBase>>> parameters(callee->argDefaultValues.size());
    if (!getParameters(compiler, parameters)) {
        return;
    }

    callee->transpile(compiler, scope.lock(), trOutput, trBlock, dotValue, loc, parameters, thisValue, storeValue, returnMode);
}

void CCallVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    if (functions.find(callee) == functions.end()) {
        functions[callee] = "";
        stringstream temp;
        callee->dumpBody(compiler, functions, temp, 0, returnMode);
        functions[callee] = temp.str();
    }

    ss << callee->fullName(true) << "(";

    vector<pair<bool, shared_ptr<NBase>>> parameters(callee->argDefaultValues.size());
    if (!getParameters(compiler, parameters)) {
        return;
    }

    if (callee->hasThis) {
        ss << "this" << " = ";
        ss << callee->fullName(true) << "(";

        if (parameters.size() > 0 || callee->getHasParent(compiler)) {
            ss << "\n";
            dumpf(ss, level + 1);

            if (callee->getHasParent(compiler)) {
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

            auto paramIndex = 0;
            for (auto it : parameters) {
                auto paramVar = callee->getArgVar(paramIndex, returnMode);
                ss << paramVar->name.c_str();
                auto ctype = paramVar->getType(compiler);
                ss << "'" << (ctype != nullptr ? ctype->fullName : "ERROR");
                ss << (paramVar->isMutable ? " = " : " : ");
                stringstream dotSS;
                paramVar->dump(compiler, nullptr, functions, ss, dotSS, level + 1);
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
        if (parameters.size() > 0 || callee->getHasParent(compiler)) {
            ss << "\n";
            dumpf(ss, level + 1);

            if (callee->getHasParent(compiler)) {
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

            auto paramIndex = 0;
            for (auto it : parameters) {
                auto paramVar = callee->getArgVar(paramIndex, returnMode);
                ss << paramVar->name.c_str();
                ss << "'" << paramVar->getType(compiler)->fullName.c_str();
                ss << (paramVar->isMutable ? " = " : " : ");
                stringstream dotSS;
                paramVar->dump(compiler, nullptr, functions, ss, dotSS, level + 1);
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

void NCall::defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    for (auto it : *arguments) {
        if (it->nodeType == NodeType_Assignment) {
            auto parameterAssignment = static_pointer_cast<NAssignment>(it);
            parameterAssignment->define(compiler, thisFunction);
        } else {
            it->define(compiler, thisFunction);
        }
    }
}

shared_ptr<CBaseFunction> NCall::getCFunction(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    // parentFunction will be specified if the NCall is used as the default NAssignment for a NFunction
    auto cfunction = static_pointer_cast<CBaseFunction>(scope->function);
    
    if (dotVar) {
        cfunction = dotVar->getType(compiler)->parent.lock();
        if (!cfunction) {
            compiler->addError(loc, CErrorCode::InvalidVariable, "parent is not a function");
            return nullptr;
        }
    }
    
    // Handle last name in list
    auto callee = cfunction->getCFunction(compiler, loc, name, scope, templateTypeNames, returnMode);
    if (!callee) {
        // If we are still using "this" then we can check to see if it is a function on parent
        if (cfunction == scope->function) {
            while (cfunction && !cfunction->parent.expired() && !callee) {
                cfunction = cfunction->parent.lock();
                if (cfunction) {
                    callee = cfunction->getCFunction(compiler, loc, name, scope, templateTypeNames, returnMode);
                }
            }
        }
    }
    
    if (!callee) {
        compiler->addError(loc, CErrorCode::UnknownFunction, "function '%s' does not exist", name.c_str());
        return nullptr;
    }
    
    return callee;
}

shared_ptr<CVar> NCall::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto callee = getCFunction(compiler, scope, dotVar, returnMode);
    if (!callee) {
        return nullptr;
    }

    return CCallVar::create(compiler, loc, name, arguments, scope, dotVar, callee, returnMode);
}
