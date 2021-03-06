#include <sjc.h>


bool CParentVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CParentVar::getType(Compiler* compiler) {
    auto parentTypes = function->getThisTypes(compiler);
    if (!parentTypes) {
        return nullptr;
    }
    return function->hasHeapThis ? parentTypes->heapValueType : parentTypes->localValueType;
}

void CParentVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto parentTypes = function->getThisTypes(compiler);
    if (!parentTypes) {
        return;
    }

    if (dotVar) {
        auto dotValue = trBlock->createCaptureStoreVariable(loc, nullptr, dotVar->getType(compiler)->getTempType());
        dotVar->transpile(compiler, trOutput, trBlock, thisValue, dotValue);
        storeValue->retainValue(compiler, loc, trBlock, make_shared<TrValue>(nullptr, getType(compiler), dotValue->getCaptureText() + "->_parent", false));
    }
    else {
        storeValue->retainValue(compiler, loc, trBlock, make_shared<TrValue>(nullptr, getType(compiler), "_parent", false));
    }
}

void CParentVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    if (dotVar) {
        dotVar->dump(compiler, functions, ss, level);
        ss << ".";
    }

    ss << "parent";
}

shared_ptr<CVar> NParent::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
    if (dotVar) {
        compiler->addError(loc, CErrorCode::InvalidVariable, "this must be the first var in a dot chain");
        return nullptr;
    }

    auto parentFunction = static_pointer_cast<CFunction>(scope->function->parent.lock());
    parentFunction->setHasThis();
    return make_shared<CParentVar>(loc, scope, nullptr, parentFunction);
}
