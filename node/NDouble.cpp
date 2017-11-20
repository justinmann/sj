#include "Node.h"

NDouble::NDouble(CLoc& loc, const char* value_) : NVariableBase(NodeType_Double, loc), isF64(true), value(value_) {
    if (value.back() == 'f') {
        isF64 = false;
        value = value.substr(0, value.size() - 1);
    }
    else if (value.back() == 'd') {
        value = value.substr(0, value.size() - 1);
    }
}

shared_ptr<CVar> NDouble::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto type = isF64 ? compiler->typeF64 : compiler->typeF32;
    return make_shared<CConstantVar>(loc, thisFunction, type, isF64 ? value : value + "f");
}
