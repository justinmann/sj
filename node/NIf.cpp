#include "Node.h"

shared_ptr<CType> CIfElseVar::getType(Compiler* compiler, CResult& result, CTypeReturnMode returnMode) {
    if (elseVar) {
        return elseVar->getType(compiler, result, returnMode);
    }
    
    if (ifVar) {
        return ifVar->getType(compiler, result, returnMode);
    }
    
    return nullptr;
}

shared_ptr<ReturnValue> CIfElseVar::transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    auto type = getType(compiler, result, returnMode);
    shared_ptr<ReturnValue> trResultVar;
    if (type != compiler->typeVoid) {
        trResultVar = trBlock->createTempVariable(type, "ifResult");
    }

    auto conditionReturnValue = condVar->transpileGet(compiler, result, thisFunction, thisVar, trOutput, trBlock, CTRM_NoPref, nullptr, thisName);
    if (!conditionReturnValue) {
        return nullptr;
    }

    stringstream ifLine;
    if (conditionReturnValue->name.front() == '(' && conditionReturnValue->name.back() == ')') {
        ifLine << "if " << conditionReturnValue->name;
    }
    else {
        ifLine << "if (" << conditionReturnValue->name << ")";
    }
    auto trIfBlock = make_shared<TrBlock>();
    trIfBlock->hasThis = trBlock->hasThis;
    trIfBlock->parent = trBlock;
    auto trStatement = TrStatement(ifLine.str(), trIfBlock);

    auto ifReturnValue = ifVar->transpileGet(compiler, result, thisFunction, thisVar, trOutput, trIfBlock.get(), returnMode, nullptr, thisName);
    if (type != compiler->typeVoid) {
        stringstream resultLine;
        if (type != compiler->typeVoid) {
            resultLine << trResultVar->name + " = " << ifReturnValue->name;
        }

        trIfBlock->statements.push_back(resultLine.str());
    }

    if (elseVar || type != compiler->typeVoid) {
        shared_ptr<ReturnValue> elseReturnValue;
        auto trElseBlock = make_shared<TrBlock>();
        trElseBlock->parent = trBlock;
        trElseBlock->hasThis = trBlock->hasThis;
        trStatement.elseBlock = trElseBlock;

        if (elseVar) {
            elseReturnValue = elseVar->transpileGet(compiler, result, thisFunction, thisVar, trOutput, trElseBlock.get(), returnMode, nullptr, thisName);
        }
        else {
            elseReturnValue = type->transpileDefaultValue(compiler, result, thisFunction, thisVar);
        }

        if (type != compiler->typeVoid) {
            stringstream resultLine;
            if (type != compiler->typeVoid) {
                resultLine << trResultVar->name + " = " << elseReturnValue->name;
            }

            trElseBlock->statements.push_back(resultLine.str());
        }
    }

    trBlock->statements.push_back(trStatement);

    return trResultVar;
}

void CIfElseVar::transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) {
    assert(false);
}

void CIfElseVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, CTypeReturnMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "if ";
    condVar->dump(compiler, result, thisFunction, thisVar, CTRM_NoPref, nullptr, functions, ss, dotSS, level);

    if (ifVar) {
        ss << " ";
        ifVar->dump(compiler, result, thisFunction, thisVar, returnMode, nullptr, functions, ss, dotSS, level);
    }
    
    if (elseVar) {
        ss << " else ";
        elseVar->dump(compiler, result, thisFunction, thisVar, returnMode, nullptr, functions, ss, dotSS, level);
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

shared_ptr<CVar> NIf::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, CTypeReturnMode returnMode) {
    assert(compiler->state == CompilerState::FixVar);
    auto condVar = condition->getVar(compiler, result, thisFunction, thisVar, CTRM_NoPref);
    
    shared_ptr<CVar> elseVar;
    if (elseBlock) {
        elseVar = elseBlock->getVar(compiler, result, thisFunction, thisVar, returnMode);
    }
    
    shared_ptr<CVar> ifVar;
    if (ifBlock) {
        ifVar = ifBlock->getVar(compiler, result, thisFunction, thisVar, returnMode);
    }
    
    return make_shared<CIfElseVar>(loc, condVar, ifVar, elseVar);
}

