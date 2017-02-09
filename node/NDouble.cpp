#include "Node.h"

shared_ptr<CType> NDouble::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeFloat;
}

shared_ptr<ReturnValue> NDouble::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);

    char* e;
    auto t = strtod(value.c_str(), &e);
    if (*e != '\0') {
        result.addError(loc, CErrorCode::InvalidNumber, "not a valid float '%s'", value.c_str());
        return nullptr;
    }
    
    return make_shared<ReturnValue>(ConstantFP::get(compiler->context, APFloat(t)));
}

void NDouble::dump(Compiler* compiler, int level) const {
    dumpf(level, "value: %s", value.c_str());
}
