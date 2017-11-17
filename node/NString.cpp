#include "Node.h"

class NGlobalPtrVar : public NBase {
public:
    NGlobalPtrVar(CLoc loc, const string& varName, const string& str);
    
protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeReturnMode returnMode);
    virtual shared_ptr<ReturnValue> transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, const char* thisName);
    virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeReturnMode returnMode, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
private:
    string varName;
    string str;
};

NGlobalPtrVar::NGlobalPtrVar(CLoc loc, const string& varName, const string& str_) : NBase(NodeType_Integer, loc), varName(varName), str(str_) {
}

void NGlobalPtrVar::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
}

shared_ptr<CVar> NGlobalPtrVar::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar) {
    return nullptr;
}

shared_ptr<CType> NGlobalPtrVar::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeReturnMode returnMode) {
    return compiler->typePtr;
}

shared_ptr<ReturnValue> NGlobalPtrVar::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, const char* thisName) {
    trOutput->strings[varName] = str;
    return make_shared<ReturnValue>(compiler->typePtr, "(uintptr_t)" + varName);
}

void NGlobalPtrVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeReturnMode returnMode, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level)  {
    
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
