#include "Node.h"

NodeType NInclude::getNodeType() const {
    return NodeType_Include;
}

void NInclude::define(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    if (thisFunction->name != "global") {
        result.addError(loc, CErrorCode::IncludeOnlyInGlobal, "can only use include in the global scope");
    }
    
    compiler->includeFile(result, fileName);
}

void NInclude::fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
}

shared_ptr<CType> NInclude::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    return compiler->typeVoid;
}

Value* NInclude::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const {
    return nullptr;
}

void NInclude::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NThis'");
}

