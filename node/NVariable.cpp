#include "Node.h"

shared_ptr<CVar> NVariableBase::getVar(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto key1 = thisFunction.get();
    auto key2 = returnMode;
    
    if (_var[key1].find(key2) == _var[key1].end()) {
        _var[key1][key2] = getVarImpl(compiler, result, thisFunction, thisVar, dotVar, returnMode);
        _thisVars[key1][key2] = thisVar.get();
    }
    assert(_thisVars[key1][key2] == thisVar.get());
    return _var[key1][key2];
}

shared_ptr<CParentDotVar> CParentDotVar::create(CLoc loc, Compiler *compiler, CResult &result, shared_ptr<CFunction> parentFunction_, shared_ptr<CVar> childVar_) {
    auto c = make_shared<CParentDotVar>(loc, nullptr);
    c->parentFunction = parentFunction_;
    c->childVar = childVar_;

    parentFunction_->setHasParent(compiler, result);

    return c;
}

bool CParentDotVar::getReturnThis() {
    return childVar->getReturnThis();
}

shared_ptr<CType> CParentDotVar::getType(Compiler* compiler, CResult& result) {
    return childVar->getType(compiler, result);
}

void CParentDotVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    shared_ptr<TrValue> parentValue;
    if (dotValue) {
        auto parentThisTypes = parentFunction->parent.lock()->getThisTypes(compiler, result);
        if (!parentThisTypes || !parentThisTypes->localValueType) {
            assert(false);
            return;
        }
        
        parentValue = trBlock->createTempVariable(parentThisTypes->localValueType, "tempParent");
        stringstream line;
        line << parentValue->name << " = " << dotValue->name << "->_parent";
        trBlock->statements.push_back(line.str());
    }
    else {
        auto parentThisTypes = parentFunction->parent.lock()->getThisTypes(compiler, result);
        if (!parentThisTypes || !parentThisTypes->localValueType) {
            assert(false);
            return;
        }

        parentValue = make_shared<TrValue>(parentThisTypes->localValueType, parentFunction->hasThis ? thisValue->getDotName("_parent") : "_parent");
    }
    childVar->transpile(compiler, result, trOutput, trBlock, parentValue, thisValue, storeValue);
}

shared_ptr<TrStoreValue> CParentDotVar::getStoreValue(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, AssignOp op, bool isFirstAssignment) {
    shared_ptr<TrValue> parentValue;
    if (dotValue) {
        auto parentThisTypes = parentFunction->parent.lock()->getThisTypes(compiler, result);
        if (!parentThisTypes || !parentThisTypes->localValueType) {
            assert(false);
            return nullptr;
        }
        
        parentValue = trBlock->createTempVariable(parentThisTypes->localValueType, "tempParent");
        stringstream line;
        line << parentValue->name << " = " << dotValue->name << "->_parent";
        trBlock->statements.push_back(line.str());
    }
    else {
        auto parentThisTypes = parentFunction->parent.lock()->getThisTypes(compiler, result);
        if (!parentThisTypes || !parentThisTypes->localValueType) {
            assert(false);
            return nullptr;
        }
        
        parentValue = make_shared<TrValue>(parentThisTypes->localValueType, parentFunction->hasThis ? thisValue->getDotName("_parent") : "_parent");
    }

    auto childStoreVar = dynamic_pointer_cast<CStoreVar>(childVar);
    return childStoreVar->getStoreValue(compiler, result, trOutput, trBlock, parentValue, thisValue, op, isFirstAssignment);
}

void CParentDotVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << ".parent";
    childVar->dump(compiler, result, dotVar, functions, ss, dotSS, level);
}

NVariable::NVariable(CLoc loc, const char* name) : NVariableBase(NodeType_Variable, loc), name(name) { }

shared_ptr<CVar> NVariable::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto cfunction = thisFunction;
    if (dotVar) {
        auto dotType = dotVar->getType(compiler, result);
        cfunction = static_pointer_cast<CFunction>(dotType->parent.lock());
    }
    
    if (dotVar && cfunction) {
        string nameWithUpper = name;
        nameWithUpper[0] = (char)toupper(nameWithUpper[0]);
        auto getPropertyFunction = cfunction->getCFunction(compiler, result, "get" + nameWithUpper, nullptr, nullptr, returnMode);
        if (getPropertyFunction != nullptr) {
            return CCallVar::create(compiler, result, loc, name, make_shared<NodeList>(), thisFunction, thisVar, dotVar, getPropertyFunction);
        }
    }

    if (cfunction) {
        auto cvar = cfunction->getCVar(compiler, result, name);
        if (!cvar) {
            result.addError(loc, CErrorCode::InvalidVariable, "cannot find variable '%s'", name.c_str());
            return nullptr;
        }
        return cvar;
    }
    return nullptr;
}
