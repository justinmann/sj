#include "Node.h"

bool CCastVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CCastVar::getType(Compiler* compiler, CResult& result) {
    return typeTo;
}

void CCastVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    auto rightStoreValue = trBlock->createTempStoreVariable(loc, scope.lock(), var->getType(compiler, result), "cast");
    var->transpile(compiler, result, trOutput, trBlock, nullptr, thisValue, rightStoreValue);
    auto rightValue = rightStoreValue->getValue();
    if (!rightValue) {
        return;
    }
    
    if (!typeTo->isOption) {
        if (rightValue->type->isOption) {
            result.addError(loc, CErrorCode::InvalidCast, "cannot cast an option type '%s' to non-option type '%s'", rightValue->type->name.c_str(), typeTo->name.c_str());
            return;
        }
        
        if (typeTo->category == CTC_Interface && rightValue->type->category == CTC_Interface) {
            result.addError(loc, CErrorCode::InvalidCast, "cannot cast an interface '%s' to non-option interface '%s'", rightValue->type->name.c_str(), typeTo->name.c_str());
            return;
        }
    }
    
    if (typeTo != nullptr && typeTo->category == CTC_Interface) {
        auto interface = static_pointer_cast<CInterface>(typeTo->parent.lock());
        interface->transpileDefinition(compiler, result, trOutput);
        
        if (rightValue->type->isOption) {
            auto ifBlock = make_shared<TrBlock>();
            stringstream ifStream;
            ifStream << "if (" << rightValue->name << " != 0)";
            interface->transpileCast(compiler, result, trOutput, ifBlock.get(), rightValue, storeValue);

            auto elseBlock = make_shared<TrBlock>();
            stringstream line;
            auto nullValue = make_shared<TrValue>(scope.lock(), typeTo, "0");
            storeValue->retainValue(compiler, result, elseBlock.get(), nullValue);
            
            auto statement = TrStatement(ifStream.str(), ifBlock);
            statement.elseBlock = elseBlock;
            trBlock->statements.push_back(statement);            
        }
        else {
            interface->transpileCast(compiler, result, trOutput, trBlock, rightValue, storeValue);
        }
    }
    else {
        if (!typeTo->parent.expired()) {
            result.addError(loc, CErrorCode::InvalidCast, "cannot cast to type '%s'", typeTo->name.c_str());
            return;
        }
        
        auto tempValue = make_shared<TrValue>(nullptr, typeTo, "(" + typeTo->cname + ")" + rightValue->name);
        storeValue->retainValue(compiler, result, trBlock, tempValue);
    }
}

void CCastVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    var->dump(compiler, result, nullptr, functions, ss, dotSS, level);
    ss << " as " << typeTo->name;
}


void NCast::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NCast::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    auto type = thisFunction->getVarType(loc, compiler, result, typeName, returnMode);
    if (!type) {
        result.addError(loc, CErrorCode::InvalidType, "type '%s' does not exist", typeName->getName().c_str());
        return nullptr;
    }

    auto var = node->getVar(compiler, result, thisFunction, thisVar, nullptr, type->typeMode);
    if (!var) {
        return nullptr;
    }

    auto fromType = var->getType(compiler, result);
    return make_shared<CCastVar>(loc, thisFunction, type, var);
}

