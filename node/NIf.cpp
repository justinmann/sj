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

void CIfElseVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto type = getType(compiler);
    auto conditionTrValue = trBlock->createTempStoreVariable(loc, nullptr, compiler->typeBool, "ifElse");
    condVar->transpile(compiler, trOutput, trBlock, thisValue, conditionTrValue);
    if (!conditionTrValue->hasSetValue) {
        return;
    }

    stringstream ifLine;
    if (conditionTrValue->getName(trBlock).front() == '(' && conditionTrValue->getName(trBlock).back() == ')') {
        ifLine << "if " << conditionTrValue->getName(trBlock);
    }
    else {
        ifLine << "if (" << conditionTrValue->getName(trBlock) << ")";
    }
    auto trIfBlock = make_shared<TrBlock>();
    trIfBlock->hasThis = trBlock->hasThis;
    trIfBlock->parent = trBlock;
    auto trStatement = TrStatement(loc, ifLine.str(), trIfBlock);

    scope.lock()->pushFunctionBlock(ifFunctionBlock);
    ifVar->transpile(compiler, trOutput, trIfBlock.get(), thisValue, storeValue);
    scope.lock()->popFunctionBlock(ifFunctionBlock);

    if (elseVar) {
        auto trElseBlock = make_shared<TrBlock>();
        trElseBlock->parent = trBlock;
        trElseBlock->hasThis = trBlock->hasThis;
        trStatement.elseBlock = trElseBlock;

        scope.lock()->pushFunctionBlock(elseFunctionBlock);
        elseVar->transpile(compiler, trOutput, trElseBlock.get(), thisValue, storeValue);
        scope.lock()->popFunctionBlock(elseFunctionBlock);
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
        ifVar->dump(compiler, functions, ss, level);
    }
    
    if (elseVar) {
        ss << " else ";
        elseVar->dump(compiler, functions, ss, level);
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
    
    shared_ptr<FunctionBlock> elseFunctionBlock;
    shared_ptr<CVar> elseVar;
    if (elseBlock) {
        elseFunctionBlock = make_shared<FunctionBlock>();
        scope->pushFunctionBlock(elseFunctionBlock);
        elseVar = elseBlock->getVar(compiler, scope, returnMode);
        scope->popFunctionBlock(elseFunctionBlock);
    }
    
    shared_ptr<FunctionBlock> ifFunctionBlock;
    shared_ptr<CVar> ifVar;
    ifFunctionBlock = make_shared<FunctionBlock>();
    scope->pushFunctionBlock(ifFunctionBlock);
    ifVar = ifBlock->getVar(compiler, scope, returnMode);
    scope->popFunctionBlock(ifFunctionBlock);
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

        if (ifType != elseType) {
            compiler->addError(loc, CErrorCode::TypeMismatch, "if block return type '%s' does not match else block return type '%s'", ifType->fullName.c_str(), elseType->fullName.c_str());
            return nullptr;
        }

        if (ifType->typeMode == CTM_Stack && elseVar->scope.lock() != ifVar->scope.lock()) {
            compiler->addError(loc, CErrorCode::TypeMismatch, "if block return value scope does not match else block return value scope", ifType->fullName.c_str(), elseType->fullName.c_str());
            return nullptr;
        }
    }
    
    return make_shared<CIfElseVar>(loc, ifVar->scope.lock(), condVar, ifVar, ifFunctionBlock, elseVar, elseFunctionBlock);
}

