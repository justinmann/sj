#include "Node.h"

bool CIfValueVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CIfValueVar::getType(Compiler* compiler) {
    if (elseVar) {
        return elseVar->getType(compiler);
    }
    
    if (ifVar) {
        return ifVar->getType(compiler);
    }
    
    return nullptr;
}

void CIfValueVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto type = getType(compiler);
    vector<shared_ptr<TrStoreValue>> isEmptyValues;
    for (auto optionalVar : optionalVars) {
        auto trValue = trBlock->createTempStoreVariable(loc, nullptr, compiler->typeBool, "isEmpty");
        optionalVar.isEmptyVar->transpile(compiler, trOutput, trBlock, thisValue, trValue);
        if (!trValue->hasSetValue) {
            return;
        }
        isEmptyValues.push_back(trValue);
    }

    bool isFirst = true;
    stringstream ifLine;
    ifLine << "if (";
    for (auto isEmptyValue : isEmptyValues) {
        if (isFirst) {
            isFirst = false;
        } else {
            ifLine << " && ";
        }
        ifLine << "!" << isEmptyValue->getName(trBlock);
    }
    ifLine << ")";

    auto trIfBlock = make_shared<TrBlock>();
    trIfBlock->hasThis = trBlock->hasThis;
    trIfBlock->localVarParent = ifLocalVarScope ? nullptr : trBlock;
    auto trStatement = TrStatement(loc, ifLine.str(), trIfBlock);

    scope.lock()->pushLocalVarScope(ifLocalVarScope);
    
    for (auto optionalVar : optionalVars) {
        auto localStoreValue = optionalVar.storeVar->getStoreValue(compiler, scope.lock(), trOutput, trIfBlock.get(), thisValue, AssignOp::immutableCreate);
        optionalVar.getValueVar->transpile(compiler, trOutput, trIfBlock.get(), thisValue, localStoreValue);
    }
    
    ifVar->transpile(compiler, trOutput, trIfBlock.get(), thisValue, storeValue);
    scope.lock()->popLocalVarScope(ifLocalVarScope);

    if (elseVar) {
        auto trElseBlock = make_shared<TrBlock>();
        trElseBlock->localVarParent = elseLocalVarScope ? nullptr : trBlock;
        trElseBlock->hasThis = trBlock->hasThis;
        trStatement.elseBlock = trElseBlock;

        scope.lock()->pushLocalVarScope(elseLocalVarScope);
        elseVar->transpile(compiler, trOutput, trElseBlock.get(), thisValue, storeValue);
        scope.lock()->popLocalVarScope(elseLocalVarScope);
    }
    else {
        if (!storeValue->isVoid) {
            compiler->addError(loc, CErrorCode::NoDefaultValue, "if you store the result of an if clause then you must specify an else clause");
        }
    }

    trBlock->statements.push_back(trStatement);
}

void CIfValueVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "ifValue ";
    // condVar->dump(compiler, functions, ss, level);

    if (ifVar) {
        ss << " ";
        scope.lock()->pushLocalVarScope(ifLocalVarScope);
        ifVar->dump(compiler, functions, ss, level);
        scope.lock()->popLocalVarScope(ifLocalVarScope);
    }
    
    if (elseVar) {
        ss << " elseEmpty ";
        scope.lock()->pushLocalVarScope(elseLocalVarScope);
        elseVar->dump(compiler, functions, ss, level);
        scope.lock()->popLocalVarScope(elseLocalVarScope);
    }
}

void NIfValue::defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
//    condition->define(compiler, thisFunction);

    if (elseBlock) {
        elseBlock->define(compiler, importNamespaces, packageNamespace, thisFunction);
    }
    
    if (ifBlock) {
        ifBlock->define(compiler, importNamespaces, packageNamespace, thisFunction);
    }
}

shared_ptr<CVar> NIfValue::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    vector<CIfParameter> optionalVars;
    
    for (auto var : *vars) {
        if (var->nodeType == NodeType_Assignment) {
            CIfParameter param;
            auto cname = TrBlock::nextVarName("ifValue");
            auto assignment = static_pointer_cast<NAssignment>(var);
            auto optionalVar = assignment->rightSide->getVar(compiler, scope, CTM_Undefined);
            if (!optionalVar) {
                return nullptr;
            }
            param.isEmptyVar = make_shared<CIsEmptyVar>(loc, scope, optionalVar);
            param.getValueVar = make_shared<CGetValueVar>(loc, scope, optionalVar, true);
            auto storeType = param.getValueVar->getType(compiler);
            if (!storeType) {
                return nullptr;
            }
            if (storeType->typeMode == CTM_Stack) {
                storeType = storeType->getLocalType();
            }
            param.storeVar = make_shared<CNormalVar>(loc, scope, storeType, assignment->name, cname, false, CVarType::Var_Local, nullptr);
            optionalVars.push_back(param);
        } else if (var->nodeType == NodeType_Variable) {
            CIfParameter param;
            auto cname = TrBlock::nextVarName("ifValue");
            auto variable = static_pointer_cast<NVariable>(var);
            auto optionalVar = variable->getVar(compiler, scope, nullptr, CTM_Undefined);
            if (!optionalVar) {
                return nullptr;
            }
            param.isEmptyVar = make_shared<CIsEmptyVar>(loc, scope, optionalVar);
            param.getValueVar = make_shared<CGetValueVar>(loc, scope, optionalVar, true);
            auto storeType = param.getValueVar->getType(compiler);
            if (!storeType) {
                return nullptr;
            }
            if (storeType->typeMode == CTM_Stack) {
                storeType = storeType->getLocalType();
            }
            param.storeVar = make_shared<CNormalVar>(loc, scope, storeType, variable->name, cname, false, CVarType::Var_Local, nullptr);
            optionalVars.push_back(param);
        } else {
            compiler->addError(loc, CErrorCode::Internal, "ifValue can only have var or assignment");
            return nullptr;
        }
    }
    
    shared_ptr<LocalVarScope> elseLocalVarScope;
    shared_ptr<CVar> elseVar;
    if (elseBlock) {
        elseLocalVarScope = make_shared<LocalVarScope>();
        scope->pushLocalVarScope(elseLocalVarScope);
        elseVar = elseBlock->getVar(compiler, scope, returnMode);
        scope->popLocalVarScope(elseLocalVarScope);
    }
    
    shared_ptr<LocalVarScope> ifLocalVarScope;
    shared_ptr<CVar> ifVar;
    ifLocalVarScope = make_shared<LocalVarScope>();
    scope->pushLocalVarScope(ifLocalVarScope);
    
    for (auto optionalVar : optionalVars) {
        scope->setLocalVar(compiler, loc, optionalVar.storeVar, true);
    }
    
    ifVar = ifBlock->getVar(compiler, scope, returnMode);
    scope->popLocalVarScope(ifLocalVarScope);
    if (ifVar == nullptr) {
        return nullptr;
    }

    auto ifType = ifVar->getType(compiler);
    if (!ifType) {
        return nullptr;
    }
    
    if (elseVar) {
        auto elseType = elseVar->getType(compiler);
        if (!elseType) {
            return nullptr;
        }

        if (ifType != elseType) {
            compiler->addError(loc, CErrorCode::TypeMismatch, "if block return type '%s' does not match else block return type '%s'", ifType->fullName.c_str(), elseType->fullName.c_str());
            return nullptr;
        }

        if (ifType->typeMode == CTM_Stack && elseVar->scope.lock() != ifVar->scope.lock()) {
            compiler->addError(loc, CErrorCode::TypeMismatch, "if block return value scope does not match else block return value scope", ifType->fullName.c_str(), elseType->fullName.c_str());
            return nullptr;
        }
    }
    
    return make_shared<CIfValueVar>(loc, ifVar->scope.lock(), optionalVars, ifVar, ifLocalVarScope, elseVar, elseLocalVarScope);
}

