#include "Node.h"

shared_ptr<CType> NChar::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, CTypeReturnMode returnMode) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeChar;
}

//shared_ptr<ReturnValue> NChar::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    assert(compiler->state == CompilerState::Compile);
//    compiler->emitLocation(builder, &this->loc);    
//    return make_shared<ReturnValue>(false, ConstantInt::get(compiler->context, APInt(8, value)));
//}

shared_ptr<ReturnValue> NChar::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, const char* thisName) {
    return make_shared<ReturnValue>(compiler->typeChar, "'" + value + "'");
}

void NChar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, CTypeReturnMode returnMode, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "'" << value << "'";
}
