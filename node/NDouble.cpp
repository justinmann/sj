#include "Node.h"

shared_ptr<CType> NDouble::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeF64;
}

//shared_ptr<ReturnValue> NDouble::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    assert(compiler->state == CompilerState::Compile);
//    compiler->emitLocation(builder, &this->loc);
//
//    char* e;
//    auto t = strtod(value.c_str(), &e);
//    if (*e != '\0') {
//        result.addError(loc, CErrorCode::InvalidNumber, "not a valid float '%s'", value.c_str());
//        return nullptr;
//    }
//    
//    return make_shared<ReturnValue>(false, ConstantFP::get(compiler->context, APFloat(t)));
//}

shared_ptr<ReturnValue> NDouble::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, stringstream& trLine) {
	trLine << value;
	return make_shared<ReturnValue>(compiler->typeF64, RVR_MustRetain);
}

void NDouble::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << value;
}
