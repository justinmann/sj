#include "Node.h"

class CGlobalPtrVar : public CVar {
public:
    CGlobalPtrVar(CLoc loc, shared_ptr<CBaseFunction> scope, string varName, string str) : CVar(loc, scope, "", false), varName(varName), str(str) { }
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    void transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
private:
    string varName;
    string str;
};

shared_ptr<CType> CGlobalPtrVar::getType(Compiler* compiler, CResult& result) {
    return compiler->typePtr;
}

void CGlobalPtrVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    trOutput->strings[varName] = str;
    auto resultValue = make_shared<TrValue>(compiler->typePtr, "(uintptr_t)" + varName);
    storeValue->setValue(compiler, result, loc, trBlock, resultValue);
}

void CGlobalPtrVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
}

class NGlobalPtrVar : public NBase {
public:
    NGlobalPtrVar(CLoc loc, const string& varName, const string& str) : NBase(NodeType_Integer, loc), varName(varName), str(str) {}
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {}
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode);
    
private:
    string varName;
    string str;
};

shared_ptr<CVar> NGlobalPtrVar::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode) {
    return make_shared<CGlobalPtrVar>(loc, thisFunction, varName, str);
}

shared_ptr<CVar> NString::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    assert(varName.size() == 0);
    varName = TrBlock::nextVarName("sjg_string");

    auto createArray = make_shared<NCall>(
        loc,
        "array",
        make_shared<CTypeNameList>(CTC_Value, CTM_Stack, compiler->typeChar->name, false),
        make_shared<NodeList>(
            make_shared<NInteger>(loc, str.size() + 1),
            make_shared<NGlobalPtrVar>(loc, varName, str)));

    auto createString = make_shared<NCall>(
        loc,
        "string",
        nullptr,
        make_shared<NodeList>(
            make_shared<NInteger>(loc, str.size()),
            createArray));

    return createString->getVar(compiler, result, thisFunction, thisVar, dotVar, returnMode);
}
