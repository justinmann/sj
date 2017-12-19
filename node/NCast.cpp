#include "Node.h"

bool CCastVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CCastVar::getType(Compiler* compiler) {
    return typeTo;
}

void CCastVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto rightStoreValue = trBlock->createTempStoreVariable(loc, scope.lock(), var->getType(compiler), "cast");
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
            auto ifBlock = make_shared<TrBlock>();
            stringstream ifStream;
            if (rightValue->type->category == CTC_Interface) {
                ifStream << "if (" << rightValue->name << "._parent != 0)";
            }
            else {
                ifStream << "if (" << rightValue->name << " != 0)";
            }
            interface->transpileCast(compiler, trOutput, ifBlock.get(), rightValue, storeValue);

            auto elseBlock = make_shared<TrBlock>();
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
        if (!typeTo->parent.expired()) {
            compiler->addError(loc, CErrorCode::InvalidCast, "cannot cast to type '%s'", typeTo->fullName.c_str());
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


void NCast::defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, importNamespaces, packageNamespace, thisFunction);
}

shared_ptr<CVar> NCast::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto type = scope->getVarType(loc, compiler, typeName, returnMode);
    if (!type) {
        compiler->addError(loc, CErrorCode::InvalidType, "type '%s' does not exist", typeName->getFullName().c_str());
        return nullptr;
    }

    auto var = node->getVar(compiler, scope, nullptr, type->typeMode);
    if (!var) {
        return nullptr;
    }

    auto fromType = var->getType(compiler);
    return make_shared<CCastVar>(loc, scope, type, var);
}

