#include "Node.h"

NodeType NInteger::getNodeType() const {
    return NodeType_Integer;
}

shared_ptr<CType> NInteger::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeInt;
}

Value* NInteger::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    char* e;
    errno = 0;
    auto t = strtoll(value.c_str(), &e, 10);
    
    if (ERANGE == errno) {
        result.addError(loc, CErrorCode::InvalidNumber, "not a valid int '%s'", value.c_str());
        return nullptr;
    }

    if (*e != '\0') {
        result.addError(loc, CErrorCode::InvalidNumber, "not a valid int '%s'", value.c_str());
        return nullptr;
    }
    
    return ConstantInt::get(compiler->context, APInt(64, t));
}

void NInteger::dump(Compiler* compiler, int level) const {
    dumpf(level, "value: %s", value.c_str());
}
