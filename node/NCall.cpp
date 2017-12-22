#include "Node.h"

shared_ptr<vector<FunctionParameter>> CCallVar::getParameters(Compiler* compiler, CLoc loc, shared_ptr<CScope> callerScope, shared_ptr<CBaseFunction> callee, shared_ptr<NodeList> arguments, bool isHelperFunction, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto parameters = make_shared<vector<FunctionParameter>>(callee->getArgCount(returnMode));

    if (parameters->size() < arguments->size()) {
        compiler->addError(loc, CErrorCode::TooManyParameters, "too many parameters");
        return nullptr;
    }

    auto calleeFunction = dynamic_pointer_cast<CFunction>(callee);
    auto calleeScope = calleeFunction ? calleeFunction->getScope(compiler, returnMode) : nullptr;
    auto argIndex = (size_t)0;
    auto hasSetByName = false;

    if (isHelperFunction) {
        (*parameters)[argIndex].isDefaultValue = false;
        (*parameters)[argIndex].op = AssignOp::immutableCreate;
        (*parameters)[argIndex].var = dotVar;
        argIndex++;
    }

    for (auto it : *arguments) {
        if (it->nodeType == NodeType_Assignment) {
            auto parameterAssignment = static_pointer_cast<NAssignment>(it);
            assert(parameterAssignment->inFunctionDeclaration);
            auto index = callee->getArgIndex(parameterAssignment->name, returnMode);
            if (index < 0) {
                compiler->addError(loc, CErrorCode::ParameterDoesNotExist, "cannot find parameter '%s'", parameterAssignment->name.c_str());
                return nullptr;
            }

            if ((*parameters)[index].var != nullptr) {
                compiler->addError(loc, CErrorCode::ParameterRedefined, "defined parameter '%s' twice", parameterAssignment->name.c_str());
                return nullptr;
            }

            (*parameters)[index].isDefaultValue = false;
            (*parameters)[index].op = parameterAssignment->op;
            (*parameters)[index].var = parameterAssignment->rightSide->getVar(compiler, callerScope, CTM_Undefined);
            hasSetByName = true;
        }
        else {
            if (hasSetByName) {
                compiler->addError(loc, CErrorCode::ParameterByIndexAfterByName, "all named parameters must be after the un-named parameters");
                return nullptr;
            }

            if ((*parameters)[argIndex].var != nullptr) {
                compiler->addError(loc, CErrorCode::Internal, "re-defining the same parameters which should be impossible for un-named parameters");
                return nullptr;
            }

            (*parameters)[argIndex].isDefaultValue = false;
            (*parameters)[argIndex].op = AssignOp::immutableCreate;
            (*parameters)[argIndex].var = it->getVar(compiler, callerScope, CTM_Undefined);
        }
        argIndex++;
    }
    
    if (callee->argDefaultValues.size() > 0) {
        argIndex = 0;
        for (auto it : callee->argDefaultValues) {
            if (argIndex < parameters->size() && (*parameters)[argIndex].var == nullptr) {
                if (it.value == nullptr) {
                    compiler->addError(loc, CErrorCode::ParameterRequired, "parameter %d is required for function '%s'", argIndex, callee->name.c_str());
                    return nullptr;
                }
                assert(it.value->nodeType != NodeType_Assignment);
                (*parameters)[argIndex].isDefaultValue = true;
                (*parameters)[argIndex].op = it.op;
                (*parameters)[argIndex].var = it.value->getVar(compiler, calleeScope, CTM_Undefined);
            }
            argIndex++;
        }
    }

    if (argIndex != parameters->size()) {
        for (auto i = argIndex; i < parameters->size(); i++) {
            compiler->addError(loc, CErrorCode::ParameterRequired, "parameter %d is required for function '%s'", i, callee->name.c_str());
        }
        return nullptr;
    }

    return parameters;
}

shared_ptr<CCallVar> CCallVar::create(Compiler* compiler, CLoc loc_, const string& name_, shared_ptr<CVar> dotVar, shared_ptr<vector<FunctionParameter>> parameters_, shared_ptr<CScope> scope, shared_ptr<CBaseFunction> callee_, CTypeMode returnMode) {
    assert(callee_);
    assert(returnMode == CTM_Stack || returnMode == CTM_Heap);
    // TODO: assert(callee_->getIsReturnModeValid(compiler, returnMode));
    
    auto c = make_shared<CCallVar>(loc_, scope, dotVar, returnMode);
    c->parameters = parameters_;
    c->scope = scope;
    c->callee = callee_;
    return c;
}

bool CCallVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CCallVar::getType(Compiler* compiler) {
    return callee->getReturnType(compiler, returnMode);
}

void CCallVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    assert(compiler->state == CompilerState::Compile);

    shared_ptr<TrStoreValue> calleeStoreValue;
    auto calleeReturnType = callee->getReturnType(compiler, returnMode);
    if (calleeReturnType == storeValue->type) {
        calleeStoreValue = storeValue;
    }
    else {
        calleeStoreValue = trBlock->createTempStoreVariable(loc, scope.lock(), calleeReturnType, "call");
    }

    if (!calleeStoreValue->op.isFirstAssignment) {
        calleeStoreValue->getValue()->addReleaseToStatements(trBlock);
    }

    callee->transpile(compiler, scope.lock(), trOutput, trBlock, dotVar, loc, parameters, thisValue, calleeStoreValue, returnMode);

    if (calleeStoreValue != storeValue) {
        storeValue->retainValue(compiler, loc, trBlock, calleeStoreValue->getValue());
    }
}

void CCallVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    if (functions.find(callee) == functions.end()) {
        functions[callee] = "";
        stringstream temp;
        callee->dumpBody(compiler, functions, temp, 0, returnMode);
        functions[callee] = temp.str();
    }

    ss << callee->fullName(true) << "(";

    if (callee->hasThis) {
        ss << "this" << " = ";
        ss << callee->fullName(true) << "(";

        if (parameters->size() > 0 || callee->hasParent) {
            ss << "\n";
            dumpf(ss, level + 1);

            if (callee->hasParent) {
                ss << "parent: ";
                ss << "this";

                if (parameters->size() > 0) {
                    ss << ",\n";
                    dumpf(ss, level + 1);
                }
            }

            auto paramIndex = 0;
            for (auto it : *parameters) {
                auto paramVar = callee->getArgVar(paramIndex, returnMode);
                ss << paramVar->name.c_str();
                auto ctype = paramVar->getType(compiler);
                ss << "'" << (ctype != nullptr ? ctype->fullName : "ERROR");
                ss << (paramVar->isMutable ? " = " : " : ");
                paramVar->dump(compiler, functions, ss, level + 1);
                if (paramIndex != parameters->size() - 1) {
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
        if (parameters->size() > 0 || callee->hasParent) {
            ss << "\n";
            dumpf(ss, level + 1);

            if (callee->hasParent) {
                ss << "parent: ";
                ss << "this";

                if (parameters->size() > 0) {
                    ss << ",\n";
                    dumpf(ss, level + 1);
                }
            }

            auto paramIndex = 0;
            for (auto it : *parameters) {
                auto paramVar = callee->getArgVar(paramIndex, returnMode);
                ss << paramVar->name.c_str();
                ss << "'" << paramVar->getType(compiler)->fullName.c_str();
                ss << (paramVar->isMutable ? " = " : " : ");
                paramVar->dump(compiler, functions, ss, level + 1);
                if (paramIndex != parameters->size() - 1) {
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


NCall::NCall(CLoc loc, string name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<NodeList> arguments) : NVariableBase(NodeType_Call, loc), name(name), templateTypeNames(templateTypeNames), arguments(arguments) {
    boost::algorithm::to_lower(this->name);

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

void NCall::defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    for (auto it : *arguments) {
        if (it->nodeType == NodeType_Assignment) {
            auto parameterAssignment = static_pointer_cast<NAssignment>(it);
            if (!parameterAssignment->op.isFirstAssignment) {
                compiler->addError(loc, CErrorCode::InvalidFunction, "assignment '%s' must be : or :=", parameterAssignment->name.c_str());
            }
            parameterAssignment->define(compiler, importNamespaces, packageNamespace, thisFunction);
        } else {
            it->define(compiler, importNamespaces, packageNamespace, thisFunction);
        }
    }
}

shared_ptr<CBaseFunction> NCall::getCFunction(Compiler* compiler, CLoc loc, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, string name, shared_ptr<CTypeNameList> templateTypeNames, CTypeMode returnMode, bool* pisHelperFunction) {
    
    // Check for the x.name() style function call  
    *pisHelperFunction = false;
    auto cfunction = static_pointer_cast<CBaseFunction>(scope->function);
    auto cfunctionReturnMode = scope->returnMode;    
    if (dotVar) {
        cfunction = dotVar->getType(compiler)->parent.lock();
        cfunctionReturnMode = dotVar->getType(compiler)->typeMode == CTM_Heap ? CTM_Heap : CTM_Stack;
    }    
    if (cfunction) {
        // Handle last name in list
        auto callee = cfunction->getCFunction(compiler, loc, name, scope, templateTypeNames, returnMode);
        if (!callee) {
            // If we are still using "this" then we can check to see if it is a function on parent
            if (cfunction == scope->function) {
                auto temp = cfunction;
                while (temp && !temp->parent.expired() && !callee) {
                    temp = temp->parent.lock();
                    if (temp) {
                        callee = temp->getCFunction(compiler, loc, name, scope, templateTypeNames, returnMode);
                    }
                }
            }
        }

        if (callee) {
            return callee;
        }
    }

    // Check for type_name(x) style function call
    if (dotVar) {
        auto functionName = dotVar->getType(compiler)->valueName + "_" + name;
        auto callee = scope->function->getCFunction(compiler, loc, functionName, scope, templateTypeNames, returnMode);
        if (callee) {
            *pisHelperFunction = true;
            return callee;
        }
    }

    // Check for callback var
    shared_ptr<CVar> var;
    if (dotVar) {
        auto temp = dynamic_pointer_cast<CFunction>(cfunction);
        if (temp) {
            var = temp->getCVar(compiler, scope, vector<shared_ptr<LocalVarScope>>(), vector<string>(), dotVar, name, VSM_ThisOnly, cfunctionReturnMode);
        }
    }
    else {
        var = scope->getCVar(compiler, scope, nullptr, name, VSM_LocalThisParent);
    }

    if (var) {
        auto type = var->getType(compiler);
        if (type && type->category == CTC_Function) {
            auto callee = type->callback.lock()->getFunction(compiler, var);
            if (callee) {
                return callee;
            }
        }
    }

    return nullptr;
}

shared_ptr<CVar> NCall::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    bool isHelperFunction = false;
    auto callee = getCFunction(compiler, loc, scope, dotVar, name, templateTypeNames, returnMode, &isHelperFunction);
    if (!callee) {
        compiler->addError(loc, CErrorCode::UnknownFunction, "function '%s' does not exist", name.c_str());
        return nullptr;
    }

    if (returnMode != CTM_Heap) {
        if (callee->getIsReturnModeValid(compiler, CTM_Stack)) {
            returnMode = CTM_Stack;
        }
        else {
            returnMode = CTM_Heap;
        }
    }

    if ((int)arguments->size() + (isHelperFunction ? 1 : 0) > callee->getArgCount(returnMode)) {
        compiler->addError(loc, CErrorCode::TooManyParameters, "passing %d, but expecting max of %d", arguments->size() + (isHelperFunction ? 1 : 0), callee->getArgCount(returnMode));
        return nullptr;
    }

    // Fill in parameters
    auto parameters = CCallVar::getParameters(compiler, loc, scope, callee, arguments, isHelperFunction, dotVar, returnMode);
    if (!parameters) {
        return nullptr;
    }

    return CCallVar::create(compiler, loc, name, isHelperFunction ? nullptr : dotVar, parameters, scope, callee, returnMode);
}
