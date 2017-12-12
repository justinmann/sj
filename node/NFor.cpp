#include "Node.h"

bool CForIndexVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CForIndexVar::getType(Compiler* compiler) {
    return compiler->typeI32;
}

void CForIndexVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    storeValue->retainValue(compiler, loc, trBlock, make_shared<TrValue>(nullptr, getType(compiler), name, false));
}

void CForIndexVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << name;
}

bool CForLoopVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CForLoopVar::getType(Compiler* compiler) {
    return compiler->typeVoid;
}

void CForLoopVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    trBlock->createVariable(nullptr, compiler->typeI32, indexVar->name);

    auto loopStartTrValue = trBlock->createTempStoreVariable(loc, nullptr, compiler->typeI32, "forStart");
    startVar->transpile(compiler, trOutput, trBlock, thisValue, loopStartTrValue);

    auto loopEndTrValue = trBlock->createTempStoreVariable(loc, nullptr, compiler->typeI32, "forEnd");
    endVar->transpile(compiler, trOutput, trBlock, thisValue, loopEndTrValue);

    if (isAscending) {
        stringstream loopCounterLine;
        loopCounterLine << indexVar->name << " = " << loopStartTrValue->getName(trBlock);
        trBlock->statements.push_back(TrStatement(loc, loopCounterLine.str()));

        auto trForBlock = make_shared<TrBlock>();
        trForBlock->parent = trBlock;
        trForBlock->hasThis = trBlock->hasThis;
        stringstream whileLine;
        whileLine << "while (" << indexVar->name << " < " << loopEndTrValue->getName(trBlock) << ")";
        trBlock->statements.push_back(TrStatement(loc, whileLine.str(), trForBlock));

        scope.lock()->pushFunctionBlock(forBlock);
        auto bodyType = bodyVar->getType(compiler);
        bodyVar->transpile(compiler, trOutput, trForBlock.get(), thisValue, trBlock->createVoidStoreVariable(loc, bodyType));
        scope.lock()->popFunctionBlock(forBlock);

        stringstream loopCounterIncLine;
        loopCounterIncLine << indexVar->name << "++";
        trForBlock->statements.push_back(TrStatement(loc, loopCounterIncLine.str()));
    }
    else {
        stringstream loopCounterLine;
        loopCounterLine << indexVar->name << " = " << loopEndTrValue->getName(trBlock) << " - 1";
        trBlock->statements.push_back(TrStatement(loc, loopCounterLine.str()));

        auto trForBlock = make_shared<TrBlock>();
        trForBlock->parent = trBlock;
        trForBlock->hasThis = trBlock->hasThis;
        stringstream whileLine;
        whileLine << "while (" << indexVar->name << " >= " << loopStartTrValue->getName(trBlock) << ")";
        trBlock->statements.push_back(TrStatement(loc, whileLine.str(), trForBlock));

        scope.lock()->pushFunctionBlock(forBlock);
        auto bodyType = bodyVar->getType(compiler);
        bodyVar->transpile(compiler, trOutput, trForBlock.get(), thisValue, trBlock->createVoidStoreVariable(loc, bodyType));
        scope.lock()->popFunctionBlock(forBlock);

        stringstream loopCounterIncLine;
        loopCounterIncLine << indexVar->name << "--";
        trForBlock->statements.push_back(TrStatement(loc, loopCounterIncLine.str()));
    }
}

void CForLoopVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "for " << indexVar->name << " : ";
    startVar->dump(compiler, functions, ss, level + 1);
    if (isAscending) {
        ss << " to ";
    }
    else {
        ss << " toReverse ";
    }
    endVar->dump(compiler, functions, ss, level + 1);
    ss << " ";
    scope.lock()->pushFunctionBlock(forBlock);
    bodyVar->dump(compiler, functions, ss, level);
    scope.lock()->popFunctionBlock(forBlock);
}


void NFor::defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    start->define(compiler, thisFunction);
    end->define(compiler, thisFunction);
    body->define(compiler, thisFunction);
}

shared_ptr<CVar> NFor::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    auto startVar = start->getVar(compiler, scope, CTM_Undefined);
    if (!startVar) {
        return nullptr;
    }

    auto endVar = end->getVar(compiler, scope, CTM_Undefined);
    if (!endVar) {
        return nullptr;
    }

    auto indexVar = make_shared<CForIndexVar>(loc, scope, varName);
    if (!indexVar) {
        return nullptr;
    }

    auto forBlock = make_shared<FunctionBlock>();
    scope->pushFunctionBlock(forBlock);
    scope->setLocalVar(compiler, loc, indexVar, false);
    auto bodyVar = body->getVar(compiler, scope, CTM_Undefined);
    scope->popFunctionBlock(forBlock);

    if (!bodyVar) {
        return nullptr;
    }

    return make_shared<CForLoopVar>(loc, scope, indexVar, startVar, endVar, bodyVar, forBlock, isAscending);
}

