#include "Node.h"

shared_ptr<CType> CForIndexVar::getType(Compiler* compiler, CResult& result) {
    return compiler->typeI32;
}

void CForIndexVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    storeValue->setValue(compiler, result, loc, trBlock, make_shared<TrValue>(getType(compiler, result), name));
}

void CForIndexVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << name;
}

shared_ptr<CType> CForLoopVar::getType(Compiler* compiler, CResult& result) {
    return compiler->typeVoid;
}

void CForLoopVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    
    trBlock->createVariable(compiler->typeI32, indexVar->name);

    auto loopStartTrValue = trBlock->createTempStoreVariable(compiler->typeI32, "loopStart");
    startVar->transpile(compiler, result, trOutput, trBlock, nullptr, thisValue, loopStartTrValue);
    
    stringstream loopCounterLine;
    loopCounterLine << indexVar->name << " = " << loopStartTrValue->name;
    trBlock->statements.push_back(loopCounterLine.str());
    
    auto loopEndTrValue = trBlock->createTempStoreVariable(compiler->typeI32, "loopEnd");
    endVar->transpile(compiler, result, trOutput, trBlock, nullptr, thisValue, loopEndTrValue);
        
    auto trForBlock = make_shared<TrBlock>();
    trForBlock->parent = trBlock;
    trForBlock->hasThis = trBlock->hasThis;
    stringstream whileLine;
    whileLine << "while (" << indexVar->name << " < " << loopEndTrValue->name << ")";
    trBlock->statements.push_back(TrStatement(whileLine.str(), trForBlock));
    
    if (thisFunction->localVarsByName.find(indexVar->name) != thisFunction->localVarsByName.end()) {
        result.addError(loc, CErrorCode::InvalidVariable, "var '%s' already exists within function, must have a unique name", indexVar->name.c_str());
    }

    thisFunction->localVarsByName[indexVar->name] = indexVar;

    bodyVar->transpile(compiler, result, trOutput, trForBlock.get(), nullptr, thisValue, trBlock->createVoidStoreVariable());
    
    thisFunction->localVarsByName.erase(indexVar->name);

    stringstream loopCounterIncLine;
    loopCounterIncLine << indexVar->name << "++";
    trForBlock->statements.push_back(loopCounterIncLine.str());
}

void CForLoopVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "for " << indexVar->name << " : ";
    startVar->dump(compiler, result, nullptr, functions, ss, dotSS, level + 1);
    ss << " to ";
    endVar->dump(compiler, result, nullptr, functions, ss, dotSS, level + 1);
    ss << " ";
    bodyVar->dump(compiler, result, nullptr, functions, ss, dotSS, level);
}


void NFor::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    start->define(compiler, result, thisFunction);
    end->define(compiler, result, thisFunction);
    body->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NFor::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode) {
    auto startVar = start->getVar(compiler, result, thisFunction, thisVar, CTM_Undefined);
    auto endVar = end->getVar(compiler, result, thisFunction, thisVar, CTM_Undefined);
    auto indexVar = make_shared<CForIndexVar>(loc, thisFunction, varName);

    auto thisFun = static_pointer_cast<CFunction>(thisFunction);
    if (thisFun->localVarsByName.find(indexVar->name) != thisFun->localVarsByName.end()) {
        result.addError(loc, CErrorCode::InvalidVariable, "var '%s' already exists within function, must have a unique name", indexVar->name.c_str());
        return nullptr;
    }
    
    thisFun->localVarsByName[indexVar->name] = indexVar;

    auto bodyVar = body->getVar(compiler, result, thisFunction, thisVar, CTM_Undefined);

    thisFun->localVarsByName.erase(indexVar->name);
    
    return make_shared<CForLoopVar>(loc, thisFun, indexVar, startVar, endVar, bodyVar);
}

