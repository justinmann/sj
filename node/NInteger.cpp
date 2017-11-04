#include "Node.h"
#include <climits>

shared_ptr<CType> NInteger::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeI32;
}

//shared_ptr<ReturnValue> NInteger::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    assert(compiler->state == CompilerState::Compile);
//    compiler->emitLocation(builder, &this->loc);
//    
//    if (strValue.size() > 0) {
//        char* e;
//        errno = 0;
//        auto v = strtoll(strValue.c_str(), &e, 10);
//        
//        if (ERANGE == errno) {
//            result.addError(loc, CErrorCode::InvalidNumber, "not a valid int '%s'", strValue.c_str());
//            return nullptr;
//        }
//
//        if (*e != '\0') {
//            result.addError(loc, CErrorCode::InvalidNumber, "not a valid int '%s'", strValue.c_str());
//            return nullptr;
//        }
//        return make_shared<ReturnValue>(false, ConstantInt::get(compiler->context, APInt(64, v)));
//    } else {
//        return make_shared<ReturnValue>(false, ConstantInt::get(compiler->context, APInt(64, value)));
//    }
//}

shared_ptr<CType> NInteger::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, stringstream& trLine) {

    if (strValue.size() > 0) {
        char* e;
        errno = 0;
        auto v = strtol(strValue.c_str(), &e, 10);

        if (ERANGE == errno || v > INT_MAX || v < INT_MIN) {
            result.addError(loc, CErrorCode::InvalidNumber, "not a valid int '%s'", strValue.c_str());
            return nullptr;
        }

        if (*e != '\0') {
            result.addError(loc, CErrorCode::InvalidNumber, "not a valid int '%s'", strValue.c_str());
            return nullptr;
        }

        trLine << v;
    }
    
	return compiler->typeI32;
}

void NInteger::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << strValue;
}
