#include "Node.h"

shared_ptr<CType> CCastVar::getType(Compiler* compiler, CResult& result) {
    return typeTo;
}

shared_ptr<ReturnValue> CCastVar::transpileGet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    auto returnValue = var->transpileGet(compiler, result, trOutput, trBlock, nullptr, thisName);
    if (!returnValue) {
        return nullptr;
    }
    
    if (!typeTo->isOption) {
        if (returnValue->type->isOption) {
            result.addError(loc, CErrorCode::InvalidCast, "cannot cast an option type '%s' to non-option type '%s'", returnValue->type->name.c_str(), typeTo->name.c_str());
            return nullptr;
        }
        
        if (typeTo->category == CTC_Interface && returnValue->type->category == CTC_Interface) {
            result.addError(loc, CErrorCode::InvalidCast, "cannot cast an interface '%s' to non-option interface '%s'", returnValue->type->name.c_str(), typeTo->name.c_str());
            return nullptr;
        }
    }
    
    if (typeTo != nullptr && typeTo->category == CTC_Interface) {
        auto resultValue = trBlock->createTempVariable(typeTo, "result");
        auto interface = static_pointer_cast<CInterface>(typeTo->parent.lock());
        interface->transpileDefinition(compiler, result, trOutput);
        
        shared_ptr<TrBlock> ifNullBlock;
        auto innerBlock = trBlock;
        if (returnValue->type->isOption) {
            ifNullBlock = make_shared<TrBlock>();
            stringstream ifStream;
            ifStream << "if (" << returnValue->name << " != 0)";
            
            auto elseBlock = make_shared<TrBlock>();
            stringstream line;
            line << resultValue->name << " = 0";
            elseBlock->statements.push_back(line.str());
            
            auto statement = TrStatement(ifStream.str(), ifNullBlock);
            statement.elseBlock = elseBlock;
            trBlock->statements.push_back(statement);
            
            innerBlock = ifNullBlock.get();
        }
        
        auto rightName = interface->transpileCast(returnValue->type->typeMode, returnValue->type->parent.lock(), returnValue->name);
        resultValue->addAssignToStatements(innerBlock, rightName, true);
        return resultValue;
    }
    else {
        if (!typeTo->parent.expired()) {
            result.addError(loc, CErrorCode::InvalidCast, "cannot cast to type '%s'", typeTo->name.c_str());
            return nullptr;
        }
        
        auto resultValue = trBlock->createTempVariable(typeTo, "result");
        stringstream line;
        line << resultValue->name << " = " << "(" << typeTo->nameRef << ")" << returnValue->name;
        trBlock->statements.push_back(line.str());
        return resultValue;
    }
}

void CCastVar::transpileSet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) {
    assert(false);
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

    auto type = thisFunction->getVarType(compiler, result, typeName);
    if (!type) {
        result.addError(loc, CErrorCode::InvalidType, "type '%s' does not exist", typeName->getName().c_str());
        return nullptr;
    }
    
    return make_shared<CCastVar>(loc, type, var);
}

