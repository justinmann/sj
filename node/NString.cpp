#include "Node.h"

class NGlobalPtrVar : public NBase {
public:
    NGlobalPtrVar(CLoc loc, const string& str);
    
protected:
    virtual void defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction);
    virtual shared_ptr<CVar> getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
    virtual shared_ptr<CType> getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar);
    virtual int setHeapVarImpl(Compiler *compiler, CResult &result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar);
    virtual shared_ptr<ReturnValue> transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue);
    virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
private:
    string str;
};

NGlobalPtrVar::NGlobalPtrVar(CLoc loc, const string& str_) : NBase(NodeType_Integer, loc), str(str_) {
}

void NGlobalPtrVar::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
}

shared_ptr<CVar> NGlobalPtrVar::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    return nullptr;
}

int NGlobalPtrVar::setHeapVarImpl(Compiler *compiler, CResult &result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    return 0;
}

shared_ptr<CType> NGlobalPtrVar::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    return compiler->typePtr;
}

shared_ptr<ReturnValue> NGlobalPtrVar::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue) {
    return make_shared<ReturnValue>(compiler->typePtr, false, RVR_MustRetain, str);
}

void NGlobalPtrVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level)  {
    
}

NString::NString(CLoc loc, const string& str_) : NBlock(loc), str(str_) {
}

shared_ptr<CVar> NString::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar) {
    initStatements(compiler, result, thisFunction, thisVar);
    return NBlock::getVarImpl(compiler, result, thisFunction, thisVar, dotVar);
}

shared_ptr<CType> NString::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    initStatements(compiler, result, thisFunction, thisVar);
    return NBlock::getTypeImpl(compiler, result, thisFunction, thisVar);
}

void NString::initStatements(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    if (statements.size() > 0)
        return;
    
    varName = TrBlock::nextVarName("sjg_string");
    
    auto createArray = make_shared<NCall>(
                                          loc,
                                          "array",
                                          make_shared<CTypeNameList>(CTC_Value, compiler->typeChar->name),
                                          make_shared<NodeList>(
                                                                make_shared<NInteger>(loc, str.size()),
                                                                make_shared<NGlobalPtrVar>(loc, varName)
                                                                ));
    statements.push_back(createArray);
}

shared_ptr<ReturnValue> NString::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue) {
    trOutput->strings[varName] = str;
    return NBlock::transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, isReturnValue);
}

