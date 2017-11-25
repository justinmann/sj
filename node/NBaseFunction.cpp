#include "Node.h"

FunctionParameter FunctionParameter::create(bool isDefaultValue, AssignOp op, shared_ptr<CVar> var) {
    FunctionParameter param;
    param.isDefaultValue = isDefaultValue;
    param.op = op;
    param.var = var;
    return param;
}

void CBaseFunction::setHasThis() {
    assert(name != "global");
    hasThis = true;
}

bool CBaseFunction::getHasParent(Compiler* compiler) {
    getThisTypes(compiler);
    return hasParent;
}

void CBaseFunction::setHasParent(Compiler* compiler) {
    assert(name != "global");
    if (parent.expired()) {
        return;
    }
    
    // Force parent to have a "this" struct
    parent.lock()->setHasThis();    
    if (!hasParent) {
        hasParent = true;
    }
}
