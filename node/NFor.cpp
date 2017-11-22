#include "Node.h"

bool CForIndexVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CForIndexVar::getType(Compiler* compiler) {
    return compiler->typeI32;
}

void CForIndexVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    storeValue->retainValue(compiler, trBlock, make_shared<TrValue>(nullptr, getType(compiler), name));
}

void CForIndexVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << name;
}

bool CForLoopVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CForLoopVar::getType(Compiler* compiler) {
    return compiler->typeVoid;
}

void CForLoopVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    
    trBlock->createVariable(nullptr, compiler->typeI32, indexVar->name);

    auto loopStartTrValue = trBlock->createTempStoreVariable(loc, nullptr, compiler->typeI32, "forStart");
    startVar->transpile(compiler, trOutput, trBlock, nullptr, thisValue, loopStartTrValue);
    
    stringstream loopCounterLine;
    loopCounterLine << indexVar->name << " = " << loopStartTrValue->name;
    trBlock->statements.push_back(loopCounterLine.str());
    
    auto loopEndTrValue = trBlock->createTempStoreVariable(loc, nullptr, compiler->typeI32, "forEnd");
    endVar->transpile(compiler, trOutput, trBlock, nullptr, thisValue, loopEndTrValue);
        
    auto trForBlock = make_shared<TrBlock>();
    trForBlock->parent = trBlock;
    trForBlock->hasThis = trBlock->hasThis;
    stringstream whileLine;
    whileLine << "while (" << indexVar->name << " < " << loopEndTrValue->name << ")";
    trBlock->statements.push_back(TrStatement(whileLine.str(), trForBlock));
    
    scope.lock()->pushLocalVar(compiler, loc, indexVar);
    bodyVar->transpile(compiler, trOutput, trForBlock.get(), nullptr, thisValue, trBlock->createVoidStoreVariable(loc));
    scope.lock()->popLocalVar(compiler, indexVar);

    stringstream loopCounterIncLine;
    loopCounterIncLine << indexVar->name << "++";
    trForBlock->statements.push_back(loopCounterIncLine.str());
}

void CForLoopVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "for " << indexVar->name << " : ";
    startVar->dump(compiler, nullptr, functions, ss, dotSS, level + 1);
    ss << " to ";
    endVar->dump(compiler, nullptr, functions, ss, dotSS, level + 1);
    ss << " ";
    bodyVar->dump(compiler, nullptr, functions, ss, dotSS, level);
}


void NFor::defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    start->define(compiler, thisFunction);
    end->define(compiler, thisFunction);
    body->define(compiler, thisFunction);
}

shared_ptr<CVar> NFor::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    auto startVar = start->getVar(compiler, scope, CTM_Undefined);
    auto endVar = end->getVar(compiler, scope, CTM_Undefined);
    auto indexVar = make_shared<CForIndexVar>(loc, scope, varName);

    scope->pushLocalVar(compiler, loc, indexVar);
    auto bodyVar = body->getVar(compiler, scope, CTM_Undefined);
    scope->popLocalVar(compiler, indexVar);

    return make_shared<CForLoopVar>(loc, scope, indexVar, startVar, endVar, bodyVar);
}

