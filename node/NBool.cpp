#include "Node.h"

shared_ptr<CType> NBool::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeBool;
}

//shared_ptr<ReturnValue> NBool::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    assert(compiler->state == CompilerState::Compile);
//    compiler->emitLocation(builder, &this->loc);
//    return make_shared<ReturnValue>(false, ConstantInt::get(compiler->context, APInt(1, value)));
//}

shared_ptr<ReturnValue> NBool::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue) {
	return make_shared<ReturnValue>(compiler->typeBool, false, RVR_MustRetain, bool_to_str(value));
}


void NBool::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << bool_to_str(value);
}
