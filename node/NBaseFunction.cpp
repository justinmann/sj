#include <sjc.h>
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