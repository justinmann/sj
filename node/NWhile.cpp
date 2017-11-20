#include "Node.h"

shared_ptr<CType> CWhileVar::getType(Compiler* compiler, CResult& result) {
    return compiler->typeVoid;
}

shared_ptr<ReturnValue> CWhileVar::transpileGet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    auto whileValue = trBlock->createTempVariable(compiler->typeBool, "whileValue");
    
    auto condReturnValue = condVar->transpileGet(compiler, result,trOutput, trBlock, nullptr, thisName);
    if (condReturnValue->type != compiler->typeBool) {
        result.addError(loc, CErrorCode::TypeMismatch, "condition for while must be a bool");
        return nullptr;
    }
    
    stringstream setWhileLine;
    setWhileLine << whileValue->name << " = " << condReturnValue->name;
    trBlock->statements.push_back(setWhileLine.str());
    
    stringstream whileLine;
    whileLine << "while (" << whileValue->name << ")";
    auto trWhileBlock = make_shared<TrBlock>();
    trWhileBlock->parent = trBlock;
    trWhileBlock->hasThis = trBlock->hasThis;
    bodyVar->transpileGet(compiler, result, trOutput, trWhileBlock.get(), nullptr, thisName);
    
    auto innerCondReturnValue = condVar->transpileGet(compiler, result, trOutput, trWhileBlock.get(), nullptr, thisName);
    if (innerCondReturnValue->type != compiler->typeBool) {
        result.addError(loc, CErrorCode::TypeMismatch, "condition for while must be a bool");
        return nullptr;
    }
    
    stringstream innerSetWhileLine;
    innerSetWhileLine << whileValue->name << " = " << innerCondReturnValue->name;
    trWhileBlock->statements.push_back(innerSetWhileLine.str());
    
    trBlock->statements.push_back(TrStatement(whileLine.str(), trWhileBlock));
    
    return nullptr;
}

void CWhileVar::transpileSet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) {
    assert(false);
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
    
    return make_shared<CWhileVar>(loc, condVar, bodyVar);
}
