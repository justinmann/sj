#include "Node.h"

shared_ptr<CVar> NVariableBase::getVar(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto key1 = scope.get();
    
    if (_var.find(key1) == _var.end()) {
        _var[key1] = getVarImpl(compiler, scope, dotVar, returnMode);
    }
    return _var[key1];
}

shared_ptr<CParentDotVar> CParentDotVar::create(CLoc loc, Compiler *compiler, shared_ptr<CFunction> parentFunction_, shared_ptr<CVar> childVar_) {
    auto c = make_shared<CParentDotVar>(loc, nullptr);
    c->parentFunction = parentFunction_;
    c->childVar = childVar_;

    parentFunction_->setHasParent(compiler);

    return c;
}

bool CParentDotVar::getReturnThis() {
    return childVar->getReturnThis();
}

shared_ptr<CType> CParentDotVar::getType(Compiler* compiler) {
    return childVar->getType(compiler);
}

void CParentDotVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    shared_ptr<TrValue> parentValue;
    if (dotValue) {
        auto parentThisTypes = parentFunction->parent.lock()->getThisTypes(compiler);
        if (!parentThisTypes || !parentThisTypes->localValueType) {
            assert(false);
            return;
        }
        
        parentValue = trBlock->createTempVariable(nullptr, parentThisTypes->localValueType, "tempParent");
        stringstream line;
        line << parentValue->name << " = " << dotValue->name << "->_parent";
        trBlock->statements.push_back(line.str());
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

shared_ptr<TrStoreValue> CParentDotVar::getStoreValue(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, AssignOp op, bool isFirstAssignment) {
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
        trBlock->statements.push_back(line.str());
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
    return childStoreVar->getStoreValue(compiler, trOutput, trBlock, parentValue, thisValue, op, isFirstAssignment);
}

void CParentDotVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << ".parent";
    childVar->dump(compiler, dotVar, functions, ss, dotSS, level);
}

NVariable::NVariable(CLoc loc, const char* name) : NVariableBase(NodeType_Variable, loc), name(name) { }

shared_ptr<CVar> NVariable::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto varScope = scope;
    if (dotVar) {
        varScope = CScope::getScopeForType(compiler, dotVar->getType(compiler));
    }
    
    if (dotVar && varScope) {
        string nameWithUpper = name;
        nameWithUpper[0] = (char)toupper(nameWithUpper[0]);
        auto getPropertyFunction = varScope->function->getCFunction(compiler, loc, "get" + nameWithUpper, scope, nullptr, returnMode);
        if (getPropertyFunction != nullptr) {
            return CCallVar::create(compiler, loc, name, make_shared<NodeList>(), scope, dotVar, getPropertyFunction, returnMode);
        }
    }

    if (varScope) {
        auto cvar = varScope->getCVar(compiler, name);
        if (cvar == nullptr && dotVar == nullptr) {
            vector<shared_ptr<CFunction>> parents;
            parents.push_back(static_pointer_cast<CFunction>(varScope->function));
            auto parent = varScope->function->parent.lock();
            while (cvar == nullptr && parent != nullptr) {
                cvar = parent->getCVar(compiler, name, CTM_Undefined);
                if (cvar == nullptr) {
                    parents.push_back(varScope->function);
                    parent = parent->parent.lock();
                }
            }

            if (cvar) {
                if (parent->name == "global") {
                    // If we made it up the parent chain to the top then we do not need to parent.parent to get there, we can just reference global vars directly
                }
                else {
                    for (auto i = parents.rbegin(); i != parents.rend(); ++i) {
                        cvar = CParentDotVar::create(loc, compiler, *i, cvar);
                    }
                }
            }
        }

        if (!cvar) {
            compiler->addError(loc, CErrorCode::InvalidVariable, "cannot find variable '%s'", name.c_str());
            return nullptr;
        }
        return cvar;
    }
    return nullptr;
}
