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
    auto c = make_shared<CParentDotVar>(loc);
    c->parentFunction = parentFunction_;
    c->childVar = childVar_;

    parentFunction_->setHasParent(compiler, result);

    return c;
}

shared_ptr<CType> CParentDotVar::getType(Compiler* compiler, CResult& result) {
    return childVar->getType(compiler, result);
}

shared_ptr<ReturnValue> CParentDotVar::transpileGet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    shared_ptr<ReturnValue> parentValue;
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

        parentValue = make_shared<ReturnValue>(parentThisTypes->localValueType, parentFunction->hasThis ? string(thisName) + "->_parent" : "_parent");
    }
    return childVar->transpileGet(compiler, result, trOutput, trBlock, parentValue, thisName);
}

void CParentDotVar::transpileSet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) {
    shared_ptr<ReturnValue> parentValue;
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
        
        parentValue = make_shared<ReturnValue>(parentThisTypes->localValueType, parentFunction->hasThis ? string(thisName) + "->_parent" : "_parent");
    }
    childVar->transpileSet(compiler, result, trOutput, trBlock, parentValue, returnValue, thisName);
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
