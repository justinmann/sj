#include <sjc.h>


CBlockVar::CBlockVar(CLoc loc, shared_ptr<CScope> scope, vector<shared_ptr<CVar>> statements) : CVar(loc, scope), statements(statements) {
    for (auto it : statements) {
        assert(it != nullptr);
    }
}

bool CBlockVar::getReturnThis() {
    return statements.back()->getReturnThis();
}

shared_ptr<CType> CBlockVar::getType(Compiler* compiler) {
    if (statements.size() == 0) {
        return compiler->typeVoid;
    }
    return statements.back()->getType(compiler);
}

void CBlockVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    for (auto it : statements) {
        auto isLastStatement = it == statements.back();
        auto type = it->getType(compiler);
        if (!type) {
            compiler->addError(it->loc, CErrorCode::InvalidType, "line has no type");
            continue;
        }
        it->transpile(compiler, trOutput, trBlock, thisValue, isLastStatement ? storeValue : trBlock->createVoidStoreVariable(loc, type));
    }
}

void CBlockVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "{\n";
    for (auto it : statements) {
        stringstream line;
        it->dump(compiler, functions, line, level + 1);
        auto t = line.str();
        if (t.size() > 0) {
            dumpf(ss, level + 1);
            ss << t << "\n";
        }
    }
    dumpf(ss, level);
    ss << "}";
}


void NBlock::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    for (auto it : statements) {
        it->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    }
}

void NBlock::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    for (auto it : statements) {
        it->initVars(compiler, scope, returnMode);
    }
}

shared_ptr<CVar> NBlock::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
    vector<shared_ptr<CVar>> statementVars;
    for (auto it : statements) {
        auto isLastStatement = it == statements.back();
        auto resultVar = it->getVar(compiler, scope, isLastStatement ? returnType : nullptr, isLastStatement ? returnMode : CTM_Undefined);
        if (resultVar) {
            statementVars.push_back(resultVar);
        }
    }
    return make_shared<CBlockVar>(loc, scope, statementVars);
}
