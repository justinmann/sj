#include "Node.h"

void NCast::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NCast::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar) {
    assert(compiler->state == CompilerState::FixVar);
    node->getVar(compiler, result, thisFunction, thisVar, nullptr);
    
    auto toType = thisFunction->getVarType(compiler, result, typeName);
    if (toType != nullptr && toType->category == CTC_Interface) {
        auto interface = static_pointer_cast<CInterface>(toType->parent.lock());
        interfaceVar = interface->getThisVar(compiler, result, returnMode);
        return interfaceVar;
    }

    return nullptr;
}

shared_ptr<CType> NCast::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeReturnMode returnMode) {
    assert(compiler->state >= CompilerState::FixVar);
    auto t = thisFunction->getVarType(compiler, result, typeName);
    if (!t) {
        result.addError(loc, CErrorCode::InvalidType, "type '%s' does not exist", typeName->getName().c_str());
        return nullptr;
    }
    return t;
}

shared_ptr<ReturnValue> NCast::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeReturnMode returnMode, const char* thisName) {
    auto type = getType(compiler, result, thisFunction, thisVar);
    if (type == nullptr) {
        return nullptr;
    }

    auto returnValue = node->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, thisName);
    if (!returnValue) {
        assert(false);
        return nullptr;
    }

    if (!type->isOption) {
        if (returnValue->type->isOption) {
            result.addError(loc, CErrorCode::InvalidCast, "cannot cast an option type '%s' to non-option type '%s'", returnValue->type->name.c_str(), type->name.c_str());
            return nullptr;
        }

        if (type->category == CTC_Interface && returnValue->type->category == CTC_Interface) {
            result.addError(loc, CErrorCode::InvalidCast, "cannot cast an interface '%s' to non-option interface '%s'", returnValue->type->name.c_str(), type->name.c_str());
            return nullptr;
        }
    }

    if (type != nullptr && type->category == CTC_Interface) {
        auto resultValue = trBlock->createTempVariable(type, "result");
        auto interface = static_pointer_cast<CInterface>(type->parent.lock());
        interface->transpileDefinition(compiler, result, trOutput, returnValue->type->typeMode);
        interfaceVar = interface->getThisVar(compiler, result, returnMode);

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
        
        auto rightName = interface->transpileCast(returnValue->type->typeMode, returnValue->type->parent.lock(), returnValue->name, returnValue->type->typeMode);
        resultValue->addAssignToStatements(innerBlock, rightName, true);
        return resultValue;
    }
    else {
        if (!type->parent.expired()) {
            result.addError(loc, CErrorCode::InvalidCast, "cannot cast to type '%s'", type->name.c_str());
            return nullptr;
        }

        auto resultValue = trBlock->createTempVariable(type, "result");
        stringstream line;
        line << resultValue->name << " = " << "(" << type->nameRef << ")" << returnValue->name;
        trBlock->statements.push_back(line.str());
        return resultValue;
    }
}

void NCast::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeReturnMode returnMode, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    node->dump(compiler, result, thisFunction, thisVar, returnMode, functions, ss, level);
    ss << " as " << typeName->getName();
}
