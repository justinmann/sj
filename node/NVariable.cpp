#include "Node.h"

shared_ptr<CVar> NVariableBase::getVar(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar) {
    if (!_hasGetVar) {
        _var = getVarImpl(compiler, result, thisFunction, thisVar, dotVar);
        _hasGetVar = true;
    }
    return _var;
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
    
    return cfunction->getCVar(compiler, result, name);
}

int NVariable::setHeapVarImpl(Compiler *compiler, CResult &result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, bool isHeapVar) {
    auto var = getVar(compiler, result, thisFunction, thisVar, dotVar);
    if (var && isHeapVar) {
        return var->setHeapVar(compiler, result, thisVar);
    }
    return 0;
}

shared_ptr<CType> NVariable::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* output, TrFunction* function, stringstream& line) {
	line << name;
	return getType(compiler, result, thisFunction, thisVar);
}
