#include <sjc.h>


bool CAndVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CAndVar::getType(Compiler* compiler) {
    return compiler->typeBool;
}

void CAndVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    storeValue->getName(trBlock); // Force capture values to become named

    auto leftValue = trBlock->createCaptureStoreVariable(loc, scope.lock(), compiler->typeBool);
    leftVar->transpile(compiler, trOutput, trBlock, thisValue, leftValue);
    
    auto condText = leftValue->getCaptureText();
    auto condParensRequired = TrStoreValue::parensRequired(condText, true);
    stringstream ifLine;
    ifLine << "if ";
    if (condParensRequired) {
        ifLine << "(";
    }
    ifLine << condText;
    if (condParensRequired) {
        ifLine << ")";
    }
    auto trIfBlock = make_shared<TrBlock>(trBlock);
    trIfBlock->hasThis = trBlock->hasThis;
    trIfBlock->localVarParent = trBlock;
    auto trStatement = TrStatement(loc, ifLine.str(), trIfBlock);
    auto rightValue = trBlock->createCaptureStoreVariable(loc, scope.lock(), compiler->typeBool);
    rightVar->transpile(compiler, trOutput, trIfBlock.get(), thisValue, rightValue);
    trIfBlock->statements.push_back(TrStatement(loc, storeValue->getName(trBlock) + " = " + rightValue->getCaptureText()));

    auto trElseBlock = make_shared<TrBlock>(trBlock);
    trElseBlock->hasThis = trBlock->hasThis;
    trElseBlock->localVarParent = trBlock;
    trElseBlock->statements.push_back(TrStatement(loc, storeValue->getName(trBlock) + " = false"));
    trStatement.elseBlock = trElseBlock;

    trBlock->statements.push_back(trStatement);
    storeValue->hasSetValue = true;
}

void CAndVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    leftVar->dump(compiler, functions, ss, level);
    ss << " && ";
    rightVar->dump(compiler, functions, ss, level);
}

void NAnd::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    left->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    right->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
}

void NAnd::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    left->initVars(compiler, scope, returnMode);
    right->initVars(compiler, scope, returnMode);
}

shared_ptr<CVar> NAnd::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
    auto leftVar = left->getVar(compiler, scope, nullptr, nullptr, CTM_Undefined);
    if (!leftVar) {
        return nullptr;
    }
    auto rightVar = right->getVar(compiler, scope, nullptr, nullptr, CTM_Undefined);
    if (!rightVar) {
        return nullptr;
    }
    return make_shared<CAndVar>(loc, scope, leftVar, rightVar);
}
