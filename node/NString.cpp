#include "Node.h"

class CGlobalPtrVar : public CVar {
public:
    CGlobalPtrVar(CLoc loc, string varName, string str) : CVar(loc, "", false), varName(varName), str(str) { }
    shared_ptr<CType> getType(Compiler* compiler, CResult& result);
    shared_ptr<ReturnValue> transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName);
    void transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName);
    void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level);
    
private:
    string varName;
    string str;
};

shared_ptr<CType> CGlobalPtrVar::getType(Compiler* compiler, CResult& result) {
    return compiler->typePtr;
}

shared_ptr<ReturnValue> CGlobalPtrVar::transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    trOutput->strings[varName] = str;
    return make_shared<ReturnValue>(compiler->typePtr, "(uintptr_t)" + varName);
}

void CGlobalPtrVar::transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) {
    assert(false);
}

void CGlobalPtrVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
}

class NGlobalPtrVar : public NBase {
public:
    NGlobalPtrVar(CLoc loc, const string& varName, const string& str) : NBase(NodeType_Integer, loc), varName(varName), str(str) {}
    void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {}
    shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar);
    
private:
    string varName;
    string str;
};

shared_ptr<CVar> NGlobalPtrVar::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar) {
    return make_shared<CGlobalPtrVar>(loc, varName, str);
}

shared_ptr<CVar> NString::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar) {
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

    return createString->getVar(compiler, result, thisFunction, thisVar, dotVar);
}
