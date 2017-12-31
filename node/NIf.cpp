#include <sjc.h>


bool CIfElseVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CIfElseVar::getType(Compiler* compiler) {
    if (ifVar && elseVar) {
        return ifVar->getType(compiler);
    }    
    return compiler->typeVoid;
}

void CIfElseVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    if (!storeValue->isVoid) {
        storeValue->getName(trBlock); // Force capture values to become named
    }
    
    auto ifStoreValue = storeValue;
    auto elseStoreValue = storeValue;
    if (ifVar && elseVar) {
        auto ifType = ifVar->getType(compiler);
        auto elseType = elseVar->getType(compiler);
        if (ifType != elseType) {
            if (!storeValue->isVoid) {
                compiler->addError(loc, CErrorCode::TypeMismatch, "if block return type '%s' does not match else block return type '%s'", ifType->fullName.c_str(), elseType->fullName.c_str());
                return;
            }
            else {
                ifStoreValue = trBlock->createVoidStoreVariable(loc, ifType);
                elseStoreValue = trBlock->createVoidStoreVariable(loc, elseType);
            }
        }
    }

    auto type = getType(compiler);
    auto conditionTrValue = trBlock->createCaptureStoreVariable(loc, nullptr, compiler->typeBool);
    condVar->transpile(compiler, trOutput, trBlock, thisValue, conditionTrValue);
    if (!conditionTrValue->hasSetValue) {
        return;
    }

    stringstream ifLine;
    auto condText = conditionTrValue->getCaptureText();
    auto condParensRequired = TrStoreValue::parensRequired(condText, true);
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

    if (ifLocalVarScope) {
        scope.lock()->pushLocalVarScope(ifLocalVarScope);
    }
    ifVar->transpile(compiler, trOutput, trIfBlock.get(), thisValue, ifStoreValue);
    if (ifLocalVarScope) {
        scope.lock()->popLocalVarScope(ifLocalVarScope);
    }

    if (elseVar) {
        auto trElseBlock = make_shared<TrBlock>(trBlock);
        trElseBlock->localVarParent = trBlock;
        trElseBlock->hasThis = trBlock->hasThis;
        trStatement.elseBlock = trElseBlock;

        if (elseLocalVarScope) {
            scope.lock()->pushLocalVarScope(elseLocalVarScope);
        }
        elseVar->transpile(compiler, trOutput, trElseBlock.get(), thisValue, elseStoreValue);
        if (elseLocalVarScope) {
            scope.lock()->popLocalVarScope(elseLocalVarScope);
        }
    }
    else {
        if (!storeValue->isVoid) {
            compiler->addError(loc, CErrorCode::NoDefaultValue, "if you store the result of an if clause then you must specify an else clause");
        }
    }

    trBlock->statements.push_back(trStatement);
}

void CIfElseVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "if ";
    condVar->dump(compiler, functions, ss, level);

    if (ifVar) {
        ss << " ";
        if (ifLocalVarScope) {
            scope.lock()->pushLocalVarScope(ifLocalVarScope);
        }
        ifVar->dump(compiler, functions, ss, level);
        if (ifLocalVarScope) {
            scope.lock()->popLocalVarScope(ifLocalVarScope);
        }
    }
    
    if (elseVar) {
        ss << " else ";
        if (elseLocalVarScope) {
            scope.lock()->pushLocalVarScope(elseLocalVarScope);
        }
        elseVar->dump(compiler, functions, ss, level);
        if (elseLocalVarScope) {
            scope.lock()->popLocalVarScope(elseLocalVarScope);
        }
    }
}

void NIf::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    condition->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);

    if (elseBlock) {
        elseBlock->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    }
    
    if (ifBlock) {
        ifBlock->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    }
}

void NIf::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    condition->initVars(compiler, scope, returnMode);

    if (elseBlock) {
        elseBlock->initVars(compiler, scope, returnMode);
    }

    if (ifBlock) {
        ifBlock->initVars(compiler, scope, returnMode);
    }
}

shared_ptr<CVar> NIf::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
    auto condVar = condition->getVar(compiler, scope, compiler->typeBool, CTM_Undefined);
    if (condVar == nullptr) {
        return nullptr;
    }

    shared_ptr<LocalVarScope> elseLocalVarScope;
    shared_ptr<CVar> elseVar;
    if (elseBlock) {
        if (useLocalVarScope) {
            elseLocalVarScope = make_shared<LocalVarScope>();
            scope->pushLocalVarScope(elseLocalVarScope);
        }
        elseVar = elseBlock->getVar(compiler, scope, returnType, returnMode);
        if (useLocalVarScope) {
            scope->popLocalVarScope(elseLocalVarScope);
        }
    }

    shared_ptr<LocalVarScope> ifLocalVarScope;
    if (useLocalVarScope) {
        ifLocalVarScope = make_shared<LocalVarScope>();
        scope->pushLocalVarScope(ifLocalVarScope);
    }
    auto ifVar = ifBlock->getVar(compiler, scope, returnType, returnMode);
    if (useLocalVarScope) {
        scope->popLocalVarScope(ifLocalVarScope);
    }
    if (ifVar == nullptr) {
        return nullptr;
    }

    auto ifType = ifVar->getType(compiler);
    if (!ifType) {
        return nullptr;
    }
    
    if (elseVar) {
        auto elseType = elseVar->getType(compiler);
        if (!elseType) {
            return nullptr;
        }
    }
    
    return make_shared<CIfElseVar>(loc, ifVar->scope.lock(), condVar, ifVar, ifLocalVarScope, elseVar, elseLocalVarScope);
}

