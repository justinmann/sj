#include "Node.h"

shared_ptr<CType> NInteger::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeInt;
}

shared_ptr<ReturnValue> NInteger::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    if (strValue.size() > 0) {
        char* e;
        errno = 0;
        auto v = strtoll(strValue.c_str(), &e, 10);
        
        if (ERANGE == errno) {
            result.addError(loc, CErrorCode::InvalidNumber, "not a valid int '%s'", strValue.c_str());
            return nullptr;
        }

        if (*e != '\0') {
            result.addError(loc, CErrorCode::InvalidNumber, "not a valid int '%s'", strValue.c_str());
            return nullptr;
        }
        return make_shared<ReturnValue>(ConstantInt::get(compiler->context, APInt(64, v)));
    } else {
        return make_shared<ReturnValue>(ConstantInt::get(compiler->context, APInt(64, value)));
    }
}

void NInteger::dump(Compiler* compiler, int level) const {
    dumpf(level, "value: %s", strValue.c_str());
}
