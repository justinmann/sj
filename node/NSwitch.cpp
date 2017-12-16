#include "Node.h"

bool CSwitchVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CSwitchVar::getType(Compiler* compiler) {
    if (clauseVars.size() > 0) {
        return clauseVars[0].blockVar->getType(compiler);
    }
    return compiler->typeVoid;
}

void CSwitchVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto type = getType(compiler);
    TrStatement* previousStatement = nullptr;

    for (auto clauseVar : clauseVars) {
        TrBlock* currentBlock = nullptr;
        if (previousStatement) {
            auto t = make_shared<TrBlock>();
            t->hasThis = trBlock->hasThis;
            t->parent = trBlock;
            previousStatement->elseBlock = t;
            currentBlock = t.get();
        }
        else {
            currentBlock = trBlock;
        }

        auto conditionTrValue = currentBlock->createTempStoreVariable(loc, nullptr, compiler->typeBool, "switch");
        clauseVar.condVar->transpile(compiler, trOutput, currentBlock, thisValue, conditionTrValue);
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

        scope.lock()->pushLocalVarScope(clauseVar.localVarScope);
        clauseVar.blockVar->transpile(compiler, trOutput, trIfBlock.get(), thisValue, storeValue);
        scope.lock()->popLocalVarScope(clauseVar.localVarScope);

        currentBlock->statements.push_back(trStatement);
        previousStatement = &currentBlock->statements.back();
    }

    if (!defaultClauseVar) {
        if (!storeValue->isVoid) {
            compiler->addError(loc, CErrorCode::NoDefaultValue, "if you store the result of an switch then you must specify a default clause");
        }
    }
    else {
        TrBlock* currentBlock = nullptr;
        if (previousStatement) {
            auto t = make_shared<TrBlock>();
            t->hasThis = trBlock->hasThis;
            t->parent = trBlock;
            previousStatement->elseBlock = t;
            currentBlock = t.get();
        }
        else {
            currentBlock = trBlock;
        }

        scope.lock()->pushLocalVarScope(defaultClauseVar->localVarScope);
        defaultClauseVar->blockVar->transpile(compiler, trOutput, currentBlock, thisValue, storeValue);
        scope.lock()->popLocalVarScope(defaultClauseVar->localVarScope);
    }
}

void CSwitchVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "switch";
    if (valueVar) {
        ss << " ";
        valueVar->dump(compiler, functions, ss, level);
    }

    for (auto clause : clauseVars) {
        if (clause.condVar) {
            clause.condVar->dump(compiler, functions, ss, level);
        }

        ss << " {\n";
        scope.lock()->pushLocalVarScope(clause.localVarScope);
        clause.blockVar->dump(compiler, functions, ss, level + 1);
        scope.lock()->popLocalVarScope(clause.localVarScope);
        ss << "\n";
        ss << "}";
    }

    if (defaultClauseVar) {
        ss << "default {\n";
        scope.lock()->pushLocalVarScope(defaultClauseVar->localVarScope);
        defaultClauseVar->blockVar->dump(compiler, functions, ss, level + 1);
        scope.lock()->popLocalVarScope(defaultClauseVar->localVarScope);
        ss << "\n";
        ss << "}";
    }
}

void NSwitchClause::defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    if (condition) {
        condition->define(compiler, importNamespaces, packageNamespace, thisFunction);
    }

    if (block) {
        block->define(compiler, importNamespaces, packageNamespace, thisFunction);
    }
}

shared_ptr<CVar> NSwitchClause::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    assert(false);
    return nullptr;
}

void NSwitch::defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    if (value) {
        value->define(compiler, importNamespaces, packageNamespace, thisFunction);
    }

    for (auto clause : clauses) {
        clause->define(compiler, importNamespaces, packageNamespace, thisFunction);
    }
}

shared_ptr<CVar> NSwitch::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    shared_ptr<CVar> valueVar;
    vector<CSwitchClause> clauseVars;
    shared_ptr<CSwitchClause> defaultClauseVar;

    if (value) {
        valueVar = value->getVar(compiler, scope, CTM_Undefined);
        if (!valueVar) {
            return nullptr;
        }
    }

    for (auto clause : clauses) {
        auto localVarScope = make_shared<LocalVarScope>();
        scope->pushLocalVarScope(localVarScope);
        auto blockVar = clause->block->getVar(compiler, scope, CTM_Undefined);
        scope->popLocalVarScope(localVarScope);
        if (!blockVar) {
            return nullptr;
        }

        if (clause->condition) {
            auto condVar = clause->condition->getVar(compiler, scope, CTM_Undefined);
            if (!condVar) {
                return nullptr;
            }
            clauseVars.push_back(CSwitchClause(condVar, blockVar, localVarScope));
        }
        else {
            // No condition means this is default
            if (defaultClauseVar) {
                compiler->addError(clause->loc, CErrorCode::InvalidType, "switch can only have one default clause");
                return nullptr;
            }

            defaultClauseVar = make_shared<CSwitchClause>(nullptr, blockVar, localVarScope);
        }
    }

    return make_shared<CSwitchVar>(loc, scope, valueVar, clauseVars, defaultClauseVar);
}

