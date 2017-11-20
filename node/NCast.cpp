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
        auto resultValue = trBlock->createTempVariable(scope.lock(), typeTo, "result");
        auto interface = static_pointer_cast<CInterface>(typeTo->parent.lock());
        interface->transpileDefinition(compiler, result, trOutput);
        
        shared_ptr<TrBlock> ifNullBlock;
        auto innerBlock = trBlock;
        if (rightValue->type->isOption) {
            ifNullBlock = make_shared<TrBlock>();
            stringstream ifStream;
            ifStream << "if (" << rightValue->name << " != 0)";
            
            auto elseBlock = make_shared<TrBlock>();
            stringstream line;
            line << resultValue->name << " = 0";
            elseBlock->statements.push_back(line.str());
            
            auto statement = TrStatement(ifStream.str(), ifNullBlock);
            statement.elseBlock = elseBlock;
            trBlock->statements.push_back(statement);
            
            innerBlock = ifNullBlock.get();
        }
        
        interface->transpileCast(compiler, result, trOutput, trBlock, rightValue, storeValue);
    }
    else {
        if (!typeTo->parent.expired()) {
            result.addError(loc, CErrorCode::InvalidCast, "cannot cast to type '%s'", typeTo->name.c_str());
            return;
        }
        
        auto tempValue = make_shared<TrValue>(nullptr, typeTo, "(" + typeTo->cname + ")" + rightValue->name);
        storeValue->setValue(compiler, result, trBlock, tempValue);
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
    auto var = node->getVar(compiler, result, thisFunction, thisVar, nullptr, CTM_Undefined);
    if (!var) {
        return nullptr;
    }
    auto fromType = var->getType(compiler, result);

    if (typeName->typeMode == CTM_Undefined) {
        typeName->typeMode = fromType->typeMode;
    }

    auto type = thisFunction->getVarType(loc, compiler, result, typeName, returnMode);
    if (!type) {
        result.addError(loc, CErrorCode::InvalidType, "type '%s' does not exist", typeName->getName().c_str());
        return nullptr;
    }
    
    return make_shared<CCastVar>(loc, thisFunction, type, var);
}

