#include "Node.h"

shared_ptr<CType> CIfElseVar::getType(Compiler* compiler, CResult& result) {
    if (elseVar) {
        return elseVar->getType(compiler, result);
    }
    
    if (ifVar) {
        return ifVar->getType(compiler, result);
    }
    
    return nullptr;
}

void CIfElseVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto type = getType(compiler, result);
    auto conditionTrValue = trBlock->createTempStoreVariable(compiler->typeBool, "cond");
    condVar->transpile(compiler, result, trOutput, trBlock, nullptr, thisValue, conditionTrValue);
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

    ifVar->transpile(compiler, result, trOutput, trIfBlock.get(), nullptr, thisValue, storeValue);
    if (elseVar || type != compiler->typeVoid) {
        auto trElseBlock = make_shared<TrBlock>();
        trElseBlock->parent = trBlock;
        trElseBlock->hasThis = trBlock->hasThis;
        trStatement.elseBlock = trElseBlock;

        if (elseVar) {
            elseVar->transpile(compiler, result, trOutput, trElseBlock.get(), nullptr, thisValue, storeValue);
        }
        else {
            type->transpileDefaultValue(compiler, result, loc, trBlock, storeValue);
        }
    }

    trBlock->statements.push_back(trStatement);
}

void CIfElseVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "if ";
    condVar->dump(compiler, result, nullptr, functions, ss, dotSS, level);

    if (ifVar) {
        ss << " ";
        ifVar->dump(compiler, result, nullptr, functions, ss, dotSS, level);
    }
    
    if (elseVar) {
        ss << " else ";
        elseVar->dump(compiler, result, nullptr, functions, ss, dotSS, level);
    }
}

void NIf::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    condition->define(compiler, result, thisFunction);

    if (elseBlock) {
        elseBlock->define(compiler, result, thisFunction);
    }
    
    if (ifBlock) {
        ifBlock->define(compiler, result, thisFunction);
    }
}

shared_ptr<CVar> NIf::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto condVar = condition->getVar(compiler, result, thisFunction, thisVar, CTM_Undefined);
    if (condVar == nullptr) {
        return nullptr;
    }
    
    shared_ptr<CVar> elseVar;
    if (elseBlock) {
        elseVar = elseBlock->getVar(compiler, result, thisFunction, thisVar, returnMode);
    }
    
    shared_ptr<CVar> ifVar;
    ifVar = ifBlock->getVar(compiler, result, thisFunction, thisVar, returnMode);
    if (condVar == nullptr) {
        return nullptr;
    }

    auto ifType = ifVar->getType(compiler, result);
    if (elseVar) {
        auto elseType = elseVar->getType(compiler, result);
        if (ifType != elseType) {
            result.addError(loc, CErrorCode::TypeMismatch, "if block return type '%s' does not match else block return type '%s'", ifType->name.c_str(), elseType->name.c_str());
            return nullptr;
        }

        if (ifType->typeMode == CTM_Stack && elseVar->scope.lock() != ifVar->scope.lock()) {
            result.addError(loc, CErrorCode::TypeMismatch, "if block return value scope does not match else block return value scope", ifType->name.c_str(), elseType->name.c_str());
            return nullptr;
        }
    }
    
    return make_shared<CIfElseVar>(loc, ifVar->scope.lock(), condVar, ifVar, elseVar);
}

