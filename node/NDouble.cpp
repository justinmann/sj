#include "Node.h"

NDouble::NDouble(CLoc loc, const char* value_) : NVariableBase(NodeType_Double, loc), isF64(true), value(value_) {
    if (value.back() == 'f') {
        isF64 = false;
        value = value.substr(0, value.size() - 1);
    }
    else if (value.back() == 'd') {
        value = value.substr(0, value.size() - 1);
    }
}

shared_ptr<CType> NDouble::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return isF64 ? compiler->typeF64 : compiler->typeF32;
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

shared_ptr<ReturnValue> NDouble::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue) {
    if (isF64) {
        return make_shared<ReturnValue>(compiler->typeF64, false, RVR_MustRetain, value);
    }
    else {
        return make_shared<ReturnValue>(compiler->typeF32, false, RVR_MustRetain, value + "f");
    }
}

void NDouble::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << value;
    if (isF64) {
        ss << "d";
    }
    else {
        ss << "f";
    }
}
