#include "Node.h"

shared_ptr<CVar> NVariableBase::getVar(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto key1 = scope.get();
    
    if (_var.find(key1) == _var.end()) {
        _var[key1] = getVarImpl(compiler, scope, dotVar, returnMode);
    }
    return _var[key1];
}

NVariable::NVariable(CLoc loc, const char* name, shared_ptr<CTypeNameList> templateTypeNames) : NVariableBase(NodeType_Variable, loc), name(name), templateTypeNames(templateTypeNames) { }

shared_ptr<CVar> NVariable::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto varScope = scope;
    if (dotVar) {
        varScope = CScope::getScopeForType(compiler, dotVar->getType(compiler));
    }
    
    if (dotVar && varScope && !templateTypeNames) {
        string nameWithUpper = name;
        nameWithUpper[0] = (char)toupper(nameWithUpper[0]);
        auto getPropertyFunction = varScope->function->getCFunction(compiler, loc, "get" + nameWithUpper, scope, nullptr, returnMode);
        if (getPropertyFunction != nullptr) {
            if (returnMode != CTM_Heap) {
                returnMode = CTM_Stack;
            }

            auto parameters = CCallVar::getParameters(compiler, loc, scope, getPropertyFunction, make_shared<NodeList>(), false, nullptr, returnMode);
            return CCallVar::create(compiler, loc, name, dotVar, parameters, scope, getPropertyFunction, returnMode);
        }
    }

    if (varScope) {
        shared_ptr<CVar> cvar;
        if (!templateTypeNames) {
            cvar = varScope->getCVar(compiler, dotVar, name, dotVar ? VSM_ThisOnly : VSM_LocalThisParent);
        }

        if (!cvar) {
            auto cfunction = varScope->function->getCFunction(compiler, loc, name, varScope, templateTypeNames, returnMode);
            if (dotVar) {
                auto dotFunction = dynamic_pointer_cast<CFunction>(dotVar->getType(compiler)->parent.lock());
                if (dotFunction) {
                    cfunction = dotFunction->getCFunction(compiler, loc, name, varScope, templateTypeNames, returnMode);
                    if (cfunction) {
                        return CCallback::getVar(compiler, scope, loc, dotVar, cfunction, returnMode);
                    }
                }
            } 
            else if (cfunction) {
                return CCallback::getVar(compiler, scope, loc, nullptr, cfunction, returnMode);
            }
            else {
                compiler->addError(loc, CErrorCode::InvalidVariable, "cannot find variable '%s'", name.c_str());
            }
            return nullptr;
        }
        return cvar;
    }
    return nullptr;
}
