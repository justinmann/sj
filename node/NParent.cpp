#include "Node.h"

NParent::NParent(CLoc loc) : NVariableBase(NodeType_Parent, loc) { }

shared_ptr<ReturnValue> NParent::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue) {
    auto parentFunction = thisFunction->parent.lock();
    
    return make_shared<ReturnValue>(
        parentFunction->getThisType(compiler, result, false),
        parentFunction->getThisVar(compiler, result)->getHeapVar(compiler, result, thisVar),
        RVR_MustRetain, 
        "_parent");
}

shared_ptr<CVar> NParent::getVarImpl(Compiler *compiler, CResult &result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar) {
    if (dotVar) {
        result.addError(loc, CErrorCode::InvalidVariable, "this must be the first var in a dot chain");
        return nullptr;
    }
    
    auto parentFunction = thisFunction->parent.lock();
    auto parentVar = parentFunction->getThisVar(compiler, result);
    parentVar->parent.lock()->setHasRefCount();
    return parentVar;
}
