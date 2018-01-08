#include <sjc.h>


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
    auto resultValue = make_shared<TrValue>(nullptr, compiler->typePtr, "&" + varName, false);
    storeValue->retainValue(compiler, loc, trBlock, resultValue);
}

void CGlobalPtrVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
}

class NGlobalPtrVar : public NBase {
public:
    NGlobalPtrVar(CLoc loc, const string& varName, const string& str) : NBase(NodeType_Integer, loc), varName(varName), str(str) {}
    void initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {}
    void initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {}
    shared_ptr<CVar> getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CType> returnType, CTypeMode returnMode);
    
private:
    string varName;
    string str;
};

shared_ptr<CVar> NGlobalPtrVar::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CType> returnType, CTypeMode returnMode) {
    return make_shared<CGlobalPtrVar>(loc, scope, varName, str);
}

shared_ptr<CVar> NString::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
    if (returnMode != CTM_Heap) {
        returnMode = CTM_Stack;
    }
    
    string varName = varNames[str];
    if (varName.size() == 0) {
        varName = TrBlock::nextVarName("sjg_string");
        varNames[str] = varName;
    }

    auto createArrayCallee = scope->function->getCFunction(compiler, loc, "array", scope, make_shared<CTypeNameList>(CTC_Value, CTM_Stack, emptyNamespace, compiler->typeChar->valueName, false), CTM_Stack);
    if (!createArrayCallee) {
        return nullptr;
    }

    auto createArrayParameters = CCallVar::getParameters(compiler, loc, scope, createArrayCallee, 
        CallArgument::createList(
            make_shared<CGlobalPtrVar>(loc, scope, varName, str)
        ), false, nullptr, CTM_Stack);
    auto createArrayVar = make_shared<CCallVar>(loc, scope, nullptr, createArrayParameters, createArrayCallee, CTM_Stack);
    if (!createArrayVar) {
        return nullptr;
    }


    auto creatStringCallee = scope->function->getCFunction(compiler, loc, "string", scope, nullptr, returnMode);
    if (!creatStringCallee) {
        return nullptr;
    }

    int chars = 0;
    bool previousSlash = false;
    for (auto ch : str) {
        if (ch == '\\') {
            if (previousSlash) {
                previousSlash = false;
                chars++;
            } else {
                previousSlash = true;
            }
        } else {
            previousSlash = false;
            chars++;
        }
    }

    auto createStringParameters = CCallVar::getParameters(compiler, loc, scope, creatStringCallee,
        CallArgument::createList(
            make_shared<CConstantVar>(loc, scope, compiler->typeI32, to_string(0)),
            make_shared<CConstantVar>(loc, scope, compiler->typeI32, to_string(chars)),
            createArrayVar
        ), false, nullptr, returnMode);
    auto createStringVar = make_shared<CCallVar>(loc, scope, nullptr, createStringParameters, creatStringCallee, returnMode);
    if (!createStringVar) {
        return nullptr;
    }

    return createStringVar;
}


map<string, string> NString::varNames;