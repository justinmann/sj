#include <sjc.h>


bool CCastVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CCastVar::getType(Compiler* compiler) {
    return typeTo;
}

void CCastVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto rightStoreValue = trBlock->createTempStoreVariable(loc, scope.lock(), var->getType(compiler)->getTempType(), "cast");
    var->transpile(compiler, trOutput, trBlock, thisValue, rightStoreValue);
    if (!rightStoreValue->hasSetValue) {
        return;
    }

    auto rightValue = rightStoreValue->getValue();
    
    if (!typeTo->isOption) {
        if (rightValue->type->isOption) {
            compiler->addError(loc, CErrorCode::InvalidCast, "cannot cast an option type '%s' to non-option type '%s'", rightValue->type->fullName.c_str(), typeTo->fullName.c_str());
            return;
        }
        
        if (typeTo->category == CTC_Interface && rightValue->type->category == CTC_Interface) {
            compiler->addError(loc, CErrorCode::InvalidCast, "cannot cast an interface '%s' to non-option interface '%s'", rightValue->type->fullName.c_str(), typeTo->fullName.c_str());
            return;
        }
    }

    if (typeTo != nullptr && typeTo->category == CTC_Interface) {
        auto interface = static_pointer_cast<CInterface>(typeTo->parent.lock());
        interface->transpileDefinition(compiler, trOutput);
        
        if (rightValue->type->isOption) {
            auto ifBlock = make_shared<TrBlock>(trBlock);
            stringstream ifStream;
            if (rightValue->type->category == CTC_Interface) {
                ifStream << "if (" << rightValue->name << "._parent != 0)";
            }
            else {
                ifStream << "if (" << rightValue->name << " != 0)";
            }
            interface->transpileCast(compiler, trOutput, ifBlock.get(), rightValue, storeValue);

            auto elseBlock = make_shared<TrBlock>(trBlock);
            stringstream line;
            if (storeValue->type->category == CTC_Interface) {
                line << storeValue->getName(trBlock) << "._parent = 0";
            }
            else {
                line << storeValue->getName(trBlock) << " = 0";
            }
            elseBlock->statements.push_back(TrStatement(loc, line.str()));
            storeValue->hasSetValue = true;
            
            auto statement = TrStatement(loc, ifStream.str(), ifBlock);
            statement.elseBlock = elseBlock;
            trBlock->statements.push_back(statement);            
        }
        else {
            interface->transpileCast(compiler, trOutput, trBlock, rightValue, storeValue);
        }
    }
    else {
        if (!typeTo->parent.expired() || !rightValue->type->parent.expired()) {
            compiler->addError(loc, CErrorCode::InvalidCast, "cannot cast from type '%s' to type '%s'", rightValue->type->fullName.c_str(), typeTo->fullName.c_str());
            return;            
        }
        
        auto tempValue = make_shared<TrValue>(nullptr, typeTo, "(" + typeTo->cname + ")" + rightValue->name, false);
        storeValue->retainValue(compiler, loc, trBlock, tempValue);
    }
}

void CCastVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    var->dump(compiler, functions, ss, level);
    ss << " as " << typeTo->fullName;
}


void NCast::initFunctionsImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    node->initFunctions(compiler, importNamespaces, packageNamespace, thisFunction);
}

void NCast::initVarsImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    node->initVars(compiler, scope, returnMode);
}

shared_ptr<CVar> NCast::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, shared_ptr<CType> returnType, CTypeMode returnMode) {
    auto var = node->getVar(compiler, scope, nullptr, nullptr, returnMode);
    if (!var) {
        return nullptr;
    }

    auto fromType = var->getType(compiler);

    auto type = scope->getVarType(loc, compiler, typeName, (fromType->typeMode == CTM_Stack || fromType->typeMode == CTM_Heap || fromType->typeMode == CTM_Weak) ? fromType->typeMode : CTM_Undefined);
    if (!type) {
        compiler->addError(loc, CErrorCode::InvalidType, "type '%s' does not exist", typeName->getFullName().c_str());
        return nullptr;
    }

    auto functionName = "as" + type->shortName;
    bool isHelperFunction;
    auto cfunction = NCall::getCFunction(compiler, loc, scope, var, functionName, nullptr, returnMode, &isHelperFunction);
    if (cfunction) {
        auto operatorOverloadNode = make_shared<NDot>(loc, node, make_shared<NCall>(loc, functionName, nullptr, nullptr));
        return operatorOverloadNode->getVar(compiler, scope, nullptr, returnType, returnMode);
    } else {
        return make_shared<CCastVar>(loc, scope, type, var);
    }
}

