#include "Node.h"

NThis::NThis(CLoc loc) : NVariableBase(loc) { }

NodeType NThis::getNodeType() const {
    return NodeType_This;
}

void NThis::fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar) const {
    assert(compiler->state == CompilerState::FixVar);
}

string NThis::getName() const {
    return "this";
}

shared_ptr<CVar> NThis::getVar(Compiler *compiler, CResult &result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar) const {
    if (dotVar) {
        result.addError(loc, CErrorCode::InvalidVariable, "this must be the first var in a dot chain");
        return nullptr;
    }
    return CThisVar::create(loc, thisFunction);
}

void NThis::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NThis'");
}

