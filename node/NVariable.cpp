#include "Node.h"

shared_ptr<CVar> NVariableBase::getVar(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar) {
    if (_var.find(thisFunction.get()) == _var.end()) {
        _var[thisFunction.get()] = getVarImpl(compiler, result, thisFunction, thisVar, dotVar);
    }
    return _var[thisFunction.get()];
}

int NVariableBase::setHeapVar(Compiler *compiler, CResult &result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, bool isHeapVar) {
    return setHeapVarImpl(compiler, result, thisFunction, thisVar, dotVar, isHeapVar);
}

shared_ptr<CParentVar> CParentVar::create(Compiler *compiler, CResult &result, shared_ptr<CFunction> parentFunction_, shared_ptr<CVar> childVar_) {
    auto c = make_shared<CParentVar>();
    c->name = "";
    c->mode = childVar_->mode;
    c->isMutable = childVar_->isMutable;
    c->nassignment = nullptr;
    c->parentFunction = parentFunction_;
    c->childVar = childVar_;

    parentFunction_->setHasParent(compiler, result);

    return c;
}

shared_ptr<CType> CParentVar::getType(Compiler* compiler, CResult& result) {
    return childVar->getType(compiler, result);
}

bool CParentVar::getHeapVar(Compiler *compiler, CResult &result, shared_ptr<CVar> thisVar) {
    return childVar->getHeapVar(compiler, result, thisVar);
}

int CParentVar::setHeapVar(Compiler *compiler, CResult &result, shared_ptr<CVar> thisVar) {
    return childVar->setHeapVar(compiler, result, thisVar);
}

//shared_ptr<ReturnValue> CParentVar::getLoadValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    auto parentValue = parentFunction->getParentValue(compiler, result, builder, dotInEntry, dotValue);
//    if (!parentValue) {
//        return nullptr;
//    }
//
//    return childVar->getLoadValue(compiler, result, thisVar, thisValue, dotInEntry, parentValue, builder, catchBB, returnRefType);
//}
//
//Value* CParentVar::getStoreValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
//    auto parentValue = parentFunction->getParentValue(compiler, result, builder, dotInEntry, dotValue);
//    if (!parentValue) {
//        return nullptr;
//    }
//
//    return childVar->getStoreValue(compiler, result, thisVar, thisValue, dotInEntry, parentValue, builder, catchBB);
//}

string CParentVar::fullName() {
    return childVar->fullName();
}

shared_ptr<ReturnValue> CParentVar::transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue, shared_ptr<ReturnValue> dotValue) {
    shared_ptr<ReturnValue> parentValue;
    if (dotValue) {
        parentValue = trBlock->createTempVariable(
            "temp",
            parentFunction->parent.lock()->getThisType(compiler, result, false),
            false,
            RVR_MustRetain);

        stringstream line;
        line << parentValue->name << " = " << dotValue->name << "->_parent";
        trBlock->statements.push_back(line.str());
    }
    else {
        parentValue = make_shared<ReturnValue>(
            parentFunction->parent.lock()->getThisType(compiler, result, false),
            false,
            RVR_MustRetain,
            "_parent");
    }
    return childVar->transpileGet(compiler, result, thisFunction, thisVar, trOutput, trBlock, isReturnValue, parentValue);
}

void CParentVar::transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue) {
    shared_ptr<ReturnValue> parentValue;
    if (dotValue) {
        parentValue = trBlock->createTempVariable(
            "temp",
            parentFunction->parent.lock()->getThisType(compiler, result, false),
            false,
            RVR_MustRetain);
        
        stringstream line;
        line << parentValue->name << " = " << dotValue->name << "->_parent";
        trBlock->statements.push_back(line.str());
    }
    else {
        parentValue = make_shared<ReturnValue>(
            parentFunction->parent.lock()->getThisType(compiler, result, false),
            false,
            RVR_MustRetain,
            "_parent");
    }
    childVar->transpileSet(compiler, result, thisFunction, thisVar, trOutput, trBlock, parentValue, returnValue);
}

void CParentVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << ".parent";
    childVar->dump(compiler, result, thisFunction, thisVar, dotVar, functions, ss, dotSS, level);
}

NVariable::NVariable(CLoc loc, const char* name) : NVariableBase(NodeType_Variable, loc), name(name) { }

shared_ptr<CVar> NVariable::getVarImpl(Compiler *compiler, CResult &result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar) {
    auto cfunction = static_pointer_cast<CBaseFunction>(thisFunction);
    if (dotVar) {
        cfunction = dotVar->getCFunctionForValue(compiler, result);
    }
    
    if (dotVar && cfunction) {
        string nameWithUpper = name;
        nameWithUpper[0] = (char)toupper(nameWithUpper[0]);
        auto getPropertyFunction = cfunction->getCFunction(compiler, result, "get" + nameWithUpper, nullptr, nullptr);
        if (getPropertyFunction != nullptr) {
            return CCallVar::create(compiler, result, loc, name, make_shared<NodeList>(), thisFunction, thisVar, dotVar, getPropertyFunction);
        }
    }

    if (cfunction) {
        return cfunction->getCVar(compiler, result, name);
    }
    return nullptr;
}

int NVariable::setHeapVarImpl(Compiler *compiler, CResult &result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, bool isHeapVar) {
    auto var = getVar(compiler, result, thisFunction, thisVar, dotVar);
    if (var && isHeapVar) {
        return var->setHeapVar(compiler, result, thisVar);
    }
    return 0;
}
