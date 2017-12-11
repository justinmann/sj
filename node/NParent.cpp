#include "Node.h"

bool CParentVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CParentVar::getType(Compiler* compiler) {
    auto parentTypes = function->getThisTypes(compiler);
    if (!parentTypes) {
        return nullptr;
    }
    return isHeap ? parentTypes->heapValueType : parentTypes->localValueType;
}

void CParentVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto parentTypes = function->getThisTypes(compiler);
    if (!parentTypes) {
        return;
    }

    if (dotVar) {
        auto dotValue = trBlock->createTempStoreVariable(loc, nullptr, dotVar->getType(compiler)->getLocalType(), "dot");
        dotVar->transpile(compiler, trOutput, trBlock, thisValue, dotValue);
        storeValue->retainValue(compiler, loc, trBlock, make_shared<TrValue>(nullptr, parentTypes->localValueType, dotValue->getName(trBlock) + "->_parent", false));
    }
    else {
        if (storeValue->type->typeMode == CTM_Heap) {
            if (scope.lock()->function->getHasHeapParent()) {
                storeValue->retainValue(compiler, loc, trBlock, make_shared<TrValue>(nullptr, parentTypes->heapValueType, "(" + parentTypes->heapValueType->cname + ")((char*)_parent - sizeof(intptr_t))", false));
            }
            else {
                compiler->addError(loc, CErrorCode::InvalidType, "parent must be heap");                
            }
        }
        else {
            storeValue->retainValue(compiler, loc, trBlock, make_shared<TrValue>(nullptr, parentTypes->localValueType, "_parent", false));
        }
    }
}

void CParentVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    if (dotVar) {
        dotVar->dump(compiler, functions, ss, level);
        ss << ".";
    }

    if (isHeap) {
        ss << "heap ";
    }
    ss << "parent";
}

shared_ptr<CVar> NParent::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    if (dotVar) {
        compiler->addError(loc, CErrorCode::InvalidVariable, "this must be the first var in a dot chain");
        return nullptr;
    }

    if (isHeap) {
        scope->function->setHasHeapParent();
    }
    
    auto parentFunction = static_pointer_cast<CFunction>(scope->function->parent.lock());
    parentFunction->setHasThis();
    return make_shared<CParentVar>(loc, scope, nullptr, parentFunction, isHeap);
}
