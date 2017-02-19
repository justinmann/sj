#include "Node.h"

NThis::NThis(CLoc loc) : NVariableBase(NodeType_This, loc) { }

shared_ptr<CVar> NThis::getVarImpl(Compiler *compiler, CResult &result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar) {
    if (dotVar) {
        result.addError(loc, CErrorCode::InvalidVariable, "this must be the first var in a dot chain");
        return nullptr;
    }
    return thisVar;
}
