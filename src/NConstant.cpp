#include <sjc.h>


bool CConstantVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CConstantVar::getType(Compiler* compiler) {
    return type;
}

void CConstantVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    storeValue->retainValue(compiler, loc, trBlock, make_shared<TrValue>(nullptr, type, value, false));
}

void CConstantVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << value;
    if (type == compiler->typeI32) {
        ss << "i";
    }
    else if (type == compiler->typeU32) {
        ss << "u";
    }
    else if (type == compiler->typeI64) {
        ss << "l";
    }
    else if (type == compiler->typeU64) {
        ss << "v";
    }
    else if (type == compiler->typeF32) {
        ss << "f";
    }
    else if (type == compiler->typeF64) {
        ss << "d";
    }
}

NConstant::NConstant(CLoc loc, const char* value_, shared_ptr<CType> overrideType) : NVariableBase(NodeType_Constant, loc), strValue(value_), overrideType(overrideType) {
}

shared_ptr<CVar> NConstant::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
    return make_shared<CConstantVar>(loc, scope, overrideType, strValue);
}

