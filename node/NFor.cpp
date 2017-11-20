#include "Node.h"

shared_ptr<CType> CForIndexVar::getType(Compiler* compiler, CResult& result) {
    return compiler->typeI32;
}

shared_ptr<ReturnValue> CForIndexVar::transpileGet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    return make_shared<ReturnValue>(getType(compiler, result), name);
}

void CForIndexVar::transpileSet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName, AssignOp op, bool isFirstAssignment) {
    assert(false);
}

void CForIndexVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << name;
}

shared_ptr<CType> CForLoopVar::getType(Compiler* compiler, CResult& result) {
    return compiler->typeVoid;
}

shared_ptr<ReturnValue> CForLoopVar::transpileGet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    
    trBlock->createVariable(compiler->typeI32, indexVar->name);
    auto trLoopEndVar = trBlock->createTempVariable(compiler->typeI32, "loopEnd");
    
    auto loopCounterReturnValue = startVar->transpileGet(compiler, result, trOutput, trBlock, nullptr, thisName);
    if (loopCounterReturnValue->type != compiler->typeI32) {
        result.addError(loc, CErrorCode::TypeMismatch, "start value must be a int");
        return nullptr;
    }
    
    stringstream loopCounterLine;
    loopCounterLine << indexVar->name << " = " << loopCounterReturnValue->name;
    trBlock->statements.push_back(loopCounterLine.str());
    
    auto loopEndReturnValue = endVar->transpileGet(compiler, result, trOutput, trBlock, nullptr, thisName);
    if (!loopEndReturnValue || loopEndReturnValue->type != compiler->typeI32) {
        result.addError(loc, CErrorCode::TypeMismatch, "end value must be a int");
        return nullptr;
    }
    
    stringstream loopEndLine;
    loopEndLine << trLoopEndVar->name << " = " << loopEndReturnValue->name;
    trBlock->statements.push_back(loopEndLine.str());
    
    auto trForBlock = make_shared<TrBlock>();
    trForBlock->parent = trBlock;
    trForBlock->hasThis = trBlock->hasThis;
    stringstream whileLine;
    whileLine << "while (" << indexVar->name << " < " << trLoopEndVar->name << ")";
    trBlock->statements.push_back(TrStatement(whileLine.str(), trForBlock));
    
    if (thisFunction->localVarsByName.find(indexVar->name) != thisFunction->localVarsByName.end()) {
        result.addError(loc, CErrorCode::InvalidVariable, "var '%s' already exists within function, must have a unique name", indexVar->name.c_str());
        return nullptr;
    }

    thisFunction->localVarsByName[indexVar->name] = indexVar;

    bodyVar->transpileGet(compiler, result, trOutput, trForBlock.get(), nullptr, thisName);
    
    thisFunction->localVarsByName.erase(indexVar->name);

    stringstream loopCounterIncLine;
    loopCounterIncLine << indexVar->name << "++";
    trForBlock->statements.push_back(loopCounterIncLine.str());
    
    return nullptr;
}

void CForLoopVar::transpileSet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName, AssignOp op, bool isFirstAssignment) {
    assert(false);
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

