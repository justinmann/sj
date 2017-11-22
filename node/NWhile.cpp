#include "Node.h"

bool CWhileVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CWhileVar::getType(Compiler* compiler) {
    return compiler->typeVoid;
}

void CWhileVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto whileValue = trBlock->createTempStoreVariable(loc, nullptr, compiler->typeBool, "while");
    
    condVar->transpile(compiler,trOutput, trBlock, nullptr, thisValue, whileValue);
    stringstream whileLine;
    whileLine << "while (" << whileValue->getName(trBlock) << ")";
    auto trWhileBlock = make_shared<TrBlock>();
    trWhileBlock->parent = trBlock;
    trWhileBlock->hasThis = trBlock->hasThis;
    auto bodyType = bodyVar->getType(compiler);
    bodyVar->transpile(compiler, trOutput, trWhileBlock.get(), nullptr, thisValue, trBlock->createVoidStoreVariable(loc, bodyType));
    condVar->transpile(compiler, trOutput, trWhileBlock.get(), nullptr, thisValue, whileValue);    
    trBlock->statements.push_back(TrStatement(whileLine.str(), trWhileBlock));
}

void CWhileVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "while ";
    condVar->dump(compiler, nullptr, functions, ss, dotSS, level);
    bodyVar->dump(compiler, nullptr, functions, ss, dotSS, level);
}

void NWhile::defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    cond->define(compiler, thisFunction);
    body->define(compiler, thisFunction);
}

shared_ptr<CVar> NWhile::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    auto condVar = cond->getVar(compiler, scope, CTM_Undefined);
    if (!condVar) {
        return nullptr;
    }
    
    auto bodyVar = body->getVar(compiler, scope, CTM_Undefined);
    if (!bodyVar) {
        return nullptr;
    }
    
    return make_shared<CWhileVar>(loc, scope, condVar, bodyVar);
}
