#include "Node.h"

NodeType NInteger::getNodeType() const {
    return NodeType_Integer;
}

shared_ptr<CType> NInteger::getReturnType(Compiler* compiler, CResult& result) const {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeInt;
}

Value* NInteger::compile(Compiler* compiler, CResult& result) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    char* e;
    errno = 0;
    auto t = strtoll(value.c_str(), &e, 10);
    
    if (ERANGE == errno) {
        result.errors.push_back(CError(loc, CErrorCode::InvalidNumber));
        return nullptr;
    }

    if (*e != '\0') {
        result.errors.push_back(CError(loc, CErrorCode::InvalidNumber));
        return nullptr;
    }
    
    return ConstantInt::get(compiler->context, APInt(64, t));
}
