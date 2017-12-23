#include "Node.h"

class CGlobalPtrVar : public CVar {
public:
    CGlobalPtrVar(CLoc loc, shared_ptr<CScope> scope, string varName, string str) : CVar(loc, scope), varName(varName), str(str) { }
    bool getReturnThis();
    shared_ptr<CType> getType(Compiler* compiler);
    void transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue);
    void dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level);
    
private:
    string varName;
    string str;
};

bool CGlobalPtrVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CGlobalPtrVar::getType(Compiler* compiler) {
    return compiler->typePtr;
}

void CGlobalPtrVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    trOutput->strings[varName] = str;
    auto resultValue = make_shared<TrValue>(nullptr, compiler->typePtr, "(void*)" + varName, false);
    storeValue->retainValue(compiler, loc, trBlock, resultValue);
}

void CGlobalPtrVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
}

class NGlobalPtrVar : public NBase {
public:
    NGlobalPtrVar(CLoc loc, const string& varName, const string& str) : NBase(NodeType_Integer, loc), varName(varName), str(str) {}
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {}
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {}
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode);
    
private:
    string varName;
    string str;
};

shared_ptr<CVar> NGlobalPtrVar::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    return make_shared<CGlobalPtrVar>(loc, scope, varName, str);
}

shared_ptr<CVar> NString::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    if (returnMode != CTM_Heap) {
        returnMode = CTM_Stack;
    }
    
    auto varName = TrBlock::nextVarName("sjg_string");

    auto createArrayCallee = scope->function->getCFunction(compiler, loc, "array", scope, make_shared<CTypeNameList>(CTC_Value, CTM_Stack, emptyNamespace, compiler->typeChar->valueName, false), CTM_Stack);
    if (!createArrayCallee) {
        return nullptr;
    }

    auto createArrayParameters = CCallVar::getParameters(compiler, loc, scope, createArrayCallee, 
        CallArgument::createList(
            make_shared<CConstantVar>(loc, scope, compiler->typeI32, to_string(str.size() + 1)),
            make_shared<CGlobalPtrVar>(loc, scope, varName, str),
            make_shared<CConstantVar>(loc, scope, compiler->typeBool, "true"),
            make_shared<CConstantVar>(loc, scope, compiler->typeI32, to_string(str.size() + 1))
        ), false, nullptr, CTM_Stack);
    auto createArrayVar = CCallVar::create(compiler, loc, "array", nullptr, createArrayParameters, scope, createArrayCallee, CTM_Stack);
    if (!createArrayVar) {
        return nullptr;
    }


    auto creatStringCallee = scope->function->getCFunction(compiler, loc, "string", scope, nullptr, returnMode);
    if (!creatStringCallee) {
        return nullptr;
    }

    auto createStringParameters = CCallVar::getParameters(compiler, loc, scope, creatStringCallee,
        CallArgument::createList(
            make_shared<CConstantVar>(loc, scope, compiler->typeI32, to_string(str.size())),
            createArrayVar
        ), false, nullptr, returnMode);
    auto createStringVar = CCallVar::create(compiler, loc, "string", nullptr, createStringParameters, scope, creatStringCallee, returnMode);
    if (!createStringVar) {
        return nullptr;
    }

    return createStringVar;
}
