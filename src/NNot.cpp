#include <sjc.h>


bool CNotVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CNotVar::getType(Compiler* compiler) {
    if (isLogicalNot) {
        return var->getType(compiler);
    }
    else {
        return compiler->typeBool;
    }
}

void CNotVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto value = trBlock->createCaptureStoreVariable(loc, nullptr, compiler->typeBool);
    var->transpile(compiler, trOutput, trBlock, thisValue, value);
    auto resultValue = trBlock->createTempVariable(nullptr, compiler->typeBool, "result");
    stringstream line;
    line << resultValue->name << " = ";
    if (isLogicalNot) {
        line << "!";
    }
    else {
        line << "~";
    }
    line << value->getCaptureText();
    trBlock->statements.push_back(TrStatement(loc, line.str()));
    storeValue->retainValue(compiler, loc, trBlock, resultValue);
}

void CNotVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << (isLogicalNot ? "!" : "not ");
    var->dump(compiler, functions, ss, level);
}

void NNot::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
}

void NNot::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    node->initVars(compiler, scope, returnMode);
}

shared_ptr<CVar> NNot::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
    auto var = node->getVar(compiler, scope, nullptr, CTM_Undefined);
    if (!var) {
        return nullptr;
    }

    auto varType = var->getType(compiler);
    if (isLogicalNot) {
        if (varType != compiler->typeBool) {
            compiler->addError(loc, CErrorCode::InvalidType, "! only works for bool type");
            return nullptr;
        }
    }
    else {
        if (varType != compiler->typeI32 && varType != compiler->typeI64 && varType != compiler->typeU32 && varType != compiler->typeU64) {
            compiler->addError(loc, CErrorCode::InvalidType, "not only works for integer types i32, i64, u32, u64");
            return nullptr;
        }
    }

    return make_shared<CNotVar>(loc, scope, var, isLogicalNot);
}

