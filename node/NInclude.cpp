#include "Node.h"

void NInclude::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    if (thisFunction->name != "global") {
        result.addError(loc, CErrorCode::IncludeOnlyInGlobal, "can only use include in the global scope");
    }
    
    compiler->includeFile(result, fileName);
}

shared_ptr<CVar> NInclude::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    return nullptr;
}

shared_ptr<CType> NInclude::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    return compiler->typeVoid;
}

Value* NInclude::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, bool isReturnRetained) {
    return nullptr;
}

void NInclude::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NThis'");
}

