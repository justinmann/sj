#include "Node.h"

bool CWhileVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CWhileVar::getType(Compiler* compiler, CResult& result) {
    return compiler->typeVoid;
}

void CWhileVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto whileValue = trBlock->createTempStoreVariable(loc, nullptr, compiler->typeBool, "whileValue");
    
    condVar->transpile(compiler, result,trOutput, trBlock, nullptr, thisValue, whileValue);
    stringstream whileLine;
    whileLine << "while (" << whileValue->name << ")";
    auto trWhileBlock = make_shared<TrBlock>();
    trWhileBlock->parent = trBlock;
    trWhileBlock->hasThis = trBlock->hasThis;
    bodyVar->transpile(compiler, result, trOutput, trWhileBlock.get(), nullptr, thisValue, trBlock->createVoidStoreVariable(loc));
    condVar->transpile(compiler, result, trOutput, trWhileBlock.get(), nullptr, thisValue, whileValue);    
    trBlock->statements.push_back(TrStatement(whileLine.str(), trWhileBlock));
}

void CWhileVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "while ";
    condVar->dump(compiler, result, nullptr, functions, ss, dotSS, level);
    bodyVar->dump(compiler, result, nullptr, functions, ss, dotSS, level);
}

void NWhile::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    cond->define(compiler, result, thisFunction);
    body->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NWhile::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode) {
    auto condVar = cond->getVar(compiler, result, thisFunction, thisVar, CTM_Undefined);
    if (!condVar) {
        return nullptr;
    }
    
    auto bodyVar = body->getVar(compiler, result, thisFunction, thisVar, CTM_Undefined);
    if (!bodyVar) {
        return nullptr;
    }
    
    return make_shared<CWhileVar>(loc, thisFunction, condVar, bodyVar);
}
