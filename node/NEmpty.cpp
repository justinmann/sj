#include "Node.h"

struct i32_optional {
    bool isEmpty;
    int32_t value;
};

static i32_optional i32_optional_empty = { true };

bool getIsEmpty(i32_optional t) {
    return t.isEmpty;
}

NEmpty::NEmpty(CLoc loc, shared_ptr<CTypeName> typeName_) : NVariableBase(NodeType_Empty, loc), typeName(typeName_) {
    if (!typeName->isOption) {
        typeName->isOption = true;
        typeName->name = typeName->name + "?";
    }
}

shared_ptr<CType> NEmpty::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    auto ctype = thisFunction->getVarType(compiler, result, typeName);
    if (!ctype) {
        result.addError(loc, CErrorCode::InvalidType, "cannot find type '%s'", typeName->getName().c_str());
        return nullptr;
    }
    return ctype;
}

//shared_ptr<ReturnValue> NEmpty::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
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

shared_ptr<ReturnValue> NEmpty::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue) {
    auto ctype = getType(compiler, result, thisFunction, thisVar);
    if (!ctype) {
        result.addError(loc, CErrorCode::InvalidType, "cannot find type '%s'", typeName->getName().c_str());
        return nullptr;
    }

    return ctype->transpileDefaultValue(compiler, result, thisFunction, thisVar);
}

void NEmpty::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "empty'" << typeName->getName();
}
