#include "Node.h"

shared_ptr<CType> NVoid::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeReturnMode returnMode) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeVoid;
}

//shared_ptr<ReturnValue> NVoid::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    assert(compiler->state == CompilerState::Compile);
//    compiler->emitLocation(builder, &this->loc);
//    return nullptr;
//}

shared_ptr<ReturnValue> NVoid::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, const char* thisName) {
	return nullptr;
}

void NVoid::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeReturnMode returnMode, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "void";
}
