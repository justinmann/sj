#include <sjc.h>
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
    if (!storeValue->isVoid) {
        storeValue->getName(trBlock); // Force capture values to become named
    }

    auto type = getType(compiler);
    TrStatement* previousStatement = nullptr;

    if (valueVar) {
        auto underscoreValue = trBlock->createVariable(scope.lock(), underscoreType, underscoreName);
        auto underscoreStoreValue = make_shared<TrStoreValue>(loc, scope.lock(), underscoreType, underscoreName, AssignOp::immutableCreate);
        valueVar->transpile(compiler, trOutput, trBlock, thisValue, underscoreStoreValue);
    }

    for (auto clauseVar : clauseVars) {
        TrBlock* currentBlock = nullptr;
        if (previousStatement) {
            auto t = make_shared<TrBlock>(trBlock);
            t->hasThis = trBlock->hasThis;
            previousStatement->elseBlock = t;
            currentBlock = t.get();
        }
        else {
            currentBlock = trBlock;
        }

        auto conditionTrValue = currentBlock->createCaptureStoreVariable(loc, nullptr, compiler->typeBool);
        clauseVar.condVar->transpile(compiler, trOutput, currentBlock, thisValue, conditionTrValue);
        if (!conditionTrValue->hasSetValue) {
            return;
        }

        stringstream ifLine;
        auto condText = conditionTrValue->getCaptureText();
        auto condParensRequired = TrStoreValue::parensRequired(condText, true);
        ifLine << "if ";
        if (condParensRequired) {
            ifLine << "(";
        }
        ifLine << condText;
        if (condParensRequired) {
            ifLine << ")";
        }

        auto trIfBlock = make_shared<TrBlock>(trBlock);
        trIfBlock->hasThis = trBlock->hasThis;
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
            auto t = make_shared<TrBlock>(trBlock);
            t->hasThis = trBlock->hasThis;
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
        ss << " ";
    }
    ss << "{";

    level++;

    for (auto clause : clauseVars) {
        ss << "\n";
        dumpf(ss, level);
        if (clause.condVar) {
            clause.condVar->dump(compiler, functions, ss, level);
        }
        ss << " ";

        scope.lock()->pushLocalVarScope(clause.localVarScope);
        clause.blockVar->dump(compiler, functions, ss, level + 1);
        scope.lock()->popLocalVarScope(clause.localVarScope);
    }

    if (defaultClauseVar) {
        ss << "\n";
        dumpf(ss, level);
        ss << "default ";
        scope.lock()->pushLocalVarScope(defaultClauseVar->localVarScope);
        defaultClauseVar->blockVar->dump(compiler, functions, ss, level + 1);
        scope.lock()->popLocalVarScope(defaultClauseVar->localVarScope);
    }

    ss << "\n";
    level--;
    dumpf(ss, level);
    ss << "}";
}

void NSwitchClause::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    if (condition) {
        condition->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    }

    if (block) {
        block->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    }
}

void NSwitchClause::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    if (condition) {
        condition->initVars(compiler, scope, returnMode);
    }

    if (block) {
        block->initVars(compiler, scope, returnMode);
    }
}

shared_ptr<CVar> NSwitchClause::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CType> returnType, CTypeMode returnMode) {
    assert(false);
    return nullptr;
}

void NSwitch::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    if (value) {
        value->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    }

    for (auto clause : clauses) {
        clause->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
    }
}

void NSwitch::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    if (value) {
        value->initVars(compiler, scope, returnMode);
    }

    for (auto clause : clauses) {
        clause->initVars(compiler, scope, returnMode);
    }
}

shared_ptr<CVar> NSwitch::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CType> returnType, CTypeMode returnMode) {
    shared_ptr<CVar> valueVar;
    string underscoreName;
    shared_ptr<CType> underscoreType;
    shared_ptr<CVar> underscoreVar;
    vector<CSwitchClause> clauseVars;
    shared_ptr<CSwitchClause> defaultClauseVar;

    if (value) {
        valueVar = value->getVar(compiler, scope, nullptr, CTM_Undefined);
        if (!valueVar) {
            return nullptr;
        }

        underscoreName = TrBlock::nextVarName("underscore");
        underscoreType = valueVar->getType(compiler)->getTempType();
        underscoreVar = make_shared<CTempVar>(loc, scope, underscoreType, underscoreName);
    }

    for (auto clause : clauses) {
        auto localVarScope = make_shared<LocalVarScope>();
        scope->pushLocalVarScope(localVarScope);
        auto blockVar = clause->block->getVar(compiler, scope, nullptr, CTM_Undefined);
        scope->popLocalVarScope(localVarScope);
        if (!blockVar) {
            return nullptr;
        }

        if (clause->condition) {
            if (underscoreVar) {
                scope->pushUnderscore(underscoreVar);
            }
            auto condVar = clause->condition->getVar(compiler, scope, nullptr, CTM_Undefined);
            if (underscoreVar) {
                scope->popUnderscore(underscoreVar);
            }

            if (!condVar) {
                return nullptr;
            }

            auto condType = condVar->getType(compiler);
            if (condType != compiler->typeBool) {
                if (!CType::isSameExceptMode(condType, underscoreType)) {
                    if (underscoreType) {
                        compiler->addError(clause->condition->loc, CErrorCode::InvalidType, "condition returned '%s' must return bool or '%s'", condType->valueName.c_str(), underscoreType->valueName.c_str());
                    }
                    else {
                        compiler->addError(clause->condition->loc, CErrorCode::InvalidType, "condition returned '%s' must return bool", condType->valueName.c_str(), underscoreType->valueName.c_str());
                    }
                    return nullptr;
                }

                NCompare t = NCompare(clause->condition->loc, make_shared<NUnderscore>(clause->condition->loc), NCompareOp::EQ, clause->condition);
                if (underscoreVar) {
                    scope->pushUnderscore(underscoreVar);
                }
                condVar = t.getVar(compiler, scope, nullptr, nullptr, CTM_Undefined);
                if (underscoreVar) {
                    scope->popUnderscore(underscoreVar);
                }
                if (!condVar) {
                    return nullptr;
                }
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

    return make_shared<CSwitchVar>(loc, scope, valueVar, underscoreName, underscoreType, clauseVars, defaultClauseVar);
}

