#include "Node.h"

bool CIfElseVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CIfElseVar::getType(Compiler* compiler) {
    if (elseVar) {
        return elseVar->getType(compiler);
    }
    
    if (ifVar) {
        return ifVar->getType(compiler);
    }
    
    return nullptr;
}

void CIfElseVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto type = getType(compiler);
    auto conditionTrValue = trBlock->createTempStoreVariable(loc, nullptr, compiler->typeBool, "ifElse");
    condVar->transpile(compiler, trOutput, trBlock, nullptr, thisValue, conditionTrValue);
    if (!conditionTrValue->hasSetValue) {
        return;
    }

    stringstream ifLine;
    if (conditionTrValue->name.front() == '(' && conditionTrValue->name.back() == ')') {
        ifLine << "if " << conditionTrValue->name;
    }
    else {
        ifLine << "if (" << conditionTrValue->name << ")";
    }
    auto trIfBlock = make_shared<TrBlock>();
    trIfBlock->hasThis = trBlock->hasThis;
    trIfBlock->parent = trBlock;
    auto trStatement = TrStatement(ifLine.str(), trIfBlock);

    ifVar->transpile(compiler, trOutput, trIfBlock.get(), nullptr, thisValue, storeValue);
    if (elseVar || type != compiler->typeVoid) {
        auto trElseBlock = make_shared<TrBlock>();
        trElseBlock->parent = trBlock;
        trElseBlock->hasThis = trBlock->hasThis;
        trStatement.elseBlock = trElseBlock;

        if (elseVar) {
            elseVar->transpile(compiler, trOutput, trElseBlock.get(), nullptr, thisValue, storeValue);
        }
        else {
            type->transpileDefaultValue(compiler, loc, trBlock, storeValue);
        }
    }

    trBlock->statements.push_back(trStatement);
}

void CIfElseVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "if ";
    condVar->dump(compiler, nullptr, functions, ss, dotSS, level);

    if (ifVar) {
        ss << " ";
        ifVar->dump(compiler, nullptr, functions, ss, dotSS, level);
    }
    
    if (elseVar) {
        ss << " else ";
        elseVar->dump(compiler, nullptr, functions, ss, dotSS, level);
    }
}

void NIf::defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    condition->define(compiler, thisFunction);

    if (elseBlock) {
        elseBlock->define(compiler, thisFunction);
    }
    
    if (ifBlock) {
        ifBlock->define(compiler, thisFunction);
    }
}

shared_ptr<CVar> NIf::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto condVar = condition->getVar(compiler, scope, CTM_Undefined);
    if (condVar == nullptr) {
        return nullptr;
    }
    
    shared_ptr<CVar> elseVar;
    if (elseBlock) {
        elseVar = elseBlock->getVar(compiler, scope, returnMode);
    }
    
    shared_ptr<CVar> ifVar;
    ifVar = ifBlock->getVar(compiler, scope, returnMode);
    if (condVar == nullptr) {
        return nullptr;
    }

    auto ifType = ifVar->getType(compiler);
    if (elseVar) {
        auto elseType = elseVar->getType(compiler);
        if (ifType != elseType) {
            compiler->addError(loc, CErrorCode::TypeMismatch, "if block return type '%s' does not match else block return type '%s'", ifType->name.c_str(), elseType->name.c_str());
            return nullptr;
        }

        if (ifType->typeMode == CTM_Stack && elseVar->scope.lock() != ifVar->scope.lock()) {
            compiler->addError(loc, CErrorCode::TypeMismatch, "if block return value scope does not match else block return value scope", ifType->name.c_str(), elseType->name.c_str());
            return nullptr;
        }
    }
    
    return make_shared<CIfElseVar>(loc, ifVar->scope.lock(), condVar, ifVar, elseVar);
}

