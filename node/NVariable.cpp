#include "Node.h"

shared_ptr<CVar> NVariableBase::getVar(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto key1 = scope.get();
    
    if (_var.find(key1) == _var.end()) {
        _var[key1] = getVarImpl(compiler, scope, dotVar, returnMode);
    }
    return _var[key1];
}
/*
bool CParentDotVar::getReturnThis() {
    return childVar->getReturnThis();
}

shared_ptr<CType> CParentDotVar::getType(Compiler* compiler) {
    return childVar->getType(compiler);
}

void CParentDotVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    shared_ptr<TrValue> parentValue;
    if (dotVar) {
        auto parentThisTypes = parentFunction->parent.lock()->getThisTypes(compiler);
        if (!parentThisTypes || !parentThisTypes->localValueType) {
            assert(false);
            return;
        }
        
        parentValue = trBlock->createTempVariable(nullptr, parentThisTypes->localValueType, "tempParent");
        stringstream line;
        line << parentValue->name << " = " << dotValue->name << "->_parent";
        trBlock->statements.push_back(TrStatement(loc, line.str()));
    }
    else {
        auto parentThisTypes = parentFunction->parent.lock()->getThisTypes(compiler);
        if (!parentThisTypes || !parentThisTypes->localValueType) {
            assert(false);
            return;
        }

        parentValue = make_shared<TrValue>(nullptr, parentThisTypes->localValueType, parentFunction->hasThis ? thisValue->getDotName("_parent") : "_parent", false);
    }
    childVar->transpile(compiler, trOutput, trBlock, parentValue, thisValue, storeValue);
}

bool CParentDotVar::getCanStoreValue() {
    auto rightStoreVar = dynamic_pointer_cast<CStoreVar>(childVar);
    if (rightStoreVar) {
        return rightStoreVar->getCanStoreValue();
    }
    return false;
}

shared_ptr<TrStoreValue> CParentDotVar::getStoreValue(Compiler* compiler, shared_ptr<CScope> scope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, AssignOp op) {
    shared_ptr<TrValue> parentValue;
    if (dotValue) {
        auto parentThisTypes = parentFunction->parent.lock()->getThisTypes(compiler);
        if (!parentThisTypes || !parentThisTypes->localValueType) {
            assert(false);
            return nullptr;
        }
        
        parentValue = trBlock->createTempVariable(nullptr, parentThisTypes->localValueType, "tempParent");
        stringstream line;
        line << parentValue->name << " = " << dotValue->name << "->_parent";
        trBlock->statements.push_back(TrStatement(loc, line.str()));
    }
    else {
        auto parentThisTypes = parentFunction->parent.lock()->getThisTypes(compiler);
        if (!parentThisTypes || !parentThisTypes->localValueType) {
            assert(false);
            return nullptr;
        }
        
        parentValue = make_shared<TrValue>(nullptr, parentThisTypes->localValueType, parentFunction->hasThis ? thisValue->getDotName("_parent") : "_parent", false);
    }

    auto childStoreVar = dynamic_pointer_cast<CStoreVar>(childVar);
    return childStoreVar->getStoreValue(compiler, scope, trOutput, trBlock, parentValue, thisValue, op);
}

void CParentDotVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    auto t = dotSS.str();
    if (t.size() > 0) {
        dotSS << ".";
    }
    dotSS << "parent";
    childVar->dump(compiler, dotVar, functions, ss, dotSS, level);
}
*/
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
