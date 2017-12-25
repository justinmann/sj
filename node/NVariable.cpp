#include "Node.h"

shared_ptr<CVar> NVariableBase::getVar(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> leftType, CTypeMode returnMode) {
    auto key1 = scope.get();
    
    if (_var.find(key1) == _var.end()) {
        _var[key1] = getVarImpl(compiler, scope, dotVar, leftType, returnMode);
    }
    return _var[key1];
}

NVariable::NVariable(CLoc loc, const char* name, shared_ptr<CTypeNameList> templateTypeNames) : NVariableBase(NodeType_Variable, loc), name(name), templateTypeNames(templateTypeNames) {
    boost::algorithm::to_lower(this->name);
}

shared_ptr<CVar> NVariable::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
    auto varScope = scope;
    if (dotVar) {
        auto dotType = dotVar->getType(compiler);
        if (!dotType) {
            return nullptr;
        }
        varScope = CScope::getScopeForType(compiler, dotType);
    }
    
    if (dotVar && varScope && !templateTypeNames) {
        auto getPropertyFunction = varScope->getCFunction(compiler, loc, "get" + name, scope, nullptr, returnMode);
        if (getPropertyFunction != nullptr) {
            if (returnMode != CTM_Heap) {
                returnMode = CTM_Stack;
            }

            auto parameters = CCallVar::getParameters(compiler, loc, scope, getPropertyFunction, CallArgument::emptyList, false, nullptr, returnMode);
            return make_shared<CCallVar>(loc, scope, dotVar, parameters, getPropertyFunction, returnMode);
        }
    }

    if (varScope) {
        shared_ptr<CVar> cvar;
        if (!templateTypeNames) {
            cvar = varScope->getCVar(compiler, scope, dotVar, name, dotVar ? VSM_ThisOnly : VSM_LocalThisParent);
        }

        if (!cvar) {
            auto cfunction = varScope->getCFunction(compiler, loc, name, varScope, templateTypeNames, returnMode);
            if (dotVar) {
                auto dotFunction = dotVar->getType(compiler)->parent.lock();
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
