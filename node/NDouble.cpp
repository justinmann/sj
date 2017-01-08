#include "Node.h"

NodeType NDouble::getNodeType() const {
    return NodeType_Double;
}

shared_ptr<CType> NDouble::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeFloat;
}

Value* NDouble::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);

    char* e;
    auto t = strtod(value.c_str(), &e);
    if (*e != '\0') {
        result.addError(loc, CErrorCode::InvalidNumber, "not a valid float '%s'", value.c_str());
        return nullptr;
    }
    
    return ConstantFP::get(compiler->context, APFloat(t));
}

void NDouble::dump(Compiler* compiler, int level) const {
    dumpf(level, "value: %s", value.c_str());
}
