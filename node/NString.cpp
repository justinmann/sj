#include "Node.h"

void NStringArray::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
}

shared_ptr<CVar> NStringArray::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    createCall = make_shared<NCall>(loc, "array", make_shared<CTypeNameList>(CTC_Value, "char"), nullptr);
    return createCall->getVar(compiler, result, thisFunction, thisVar, nullptr);
}

shared_ptr<CType> NStringArray::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return createCall->getType(compiler, result, thisFunction, thisVar);
}

int NStringArray::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    return createCall->NBase::setHeapVar(compiler, result, thisFunction, thisVar, isHeapVar);
}

shared_ptr<ReturnValue> NStringArray::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(builder, this);
    auto varFunction = createCall->getVar(compiler, result, thisFunction, thisVar, nullptr)->getCFunctionForValue(compiler, result);
    return make_shared<ReturnValue>(varFunction, RVR_Value, RVT_SIMPLE, false, builder->CreateGlobalStringPtr(str));
}

void NStringArray::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    // dumpf(level, "value: %s", value.c_str());
}

NString::NString(CLoc loc, const string& str_) : NBase(NodeType_String, loc) {
    isValid = true;
    stringstream ss;
    bool isEscaped = false;
    for (auto it : str_) {
        if (isEscaped) {
            switch (it) {
                case '\'': ss << '\''; break;
                case '\"': ss << '\"'; break;
                case '\\': ss << '\\'; break;
                case 'a': ss << '\a'; break;
                case 'b': ss << '\b'; break;
                case 'f': ss << '\f'; break;
                case 'n': ss << '\n'; break;
                case 'r': ss << '\r'; break;
                case 't': ss << '\t'; break;
                case 'v': ss << '\v'; break;
                default: isValid = false; break;
            }
            isEscaped = false;
        } else if (it == '\\') {
            isEscaped = true;
        } else {
            ss << it;
        }
    }
    
    if (isEscaped) {
        isValid = false;
    }
    
    str = ss.str();
}

shared_ptr<CVar> NString::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    if (!isValid) {
        result.addError(loc, CErrorCode::InvalidString, "string contains an invalid escape");
        return nullptr;
    }
    
    auto size = make_shared<NInteger>(loc, str.size());
    auto stringArray = make_shared<NStringArray>(loc, str);
    createCall = make_shared<NCall>(loc, "list", make_shared<CTypeNameList>(CTC_Value, "char"), make_shared<NodeList>(size, size, stringArray));
    return createCall->getVar(compiler, result, thisFunction, thisVar, nullptr);
}

shared_ptr<CType> NString::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    if (!isValid) {
        result.addError(loc, CErrorCode::InvalidString, "string contains an invalid escape");
        return nullptr;
    }

    return createCall->getType(compiler, result, thisFunction, thisVar);
}

int NString::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    if (!isValid) {
        result.addError(loc, CErrorCode::InvalidString, "string contains an invalid escape");
        return 0;
    }

    return createCall->setHeapVar(compiler, result, thisFunction, thisVar, nullptr, isHeapVar);
}

shared_ptr<ReturnValue> NString::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
    assert(compiler->state == CompilerState::Compile);
    if (!isValid) {
        result.addError(loc, CErrorCode::InvalidString, "string contains an invalid escape");
        return nullptr;
    }

    return createCall->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, returnRefType);
}

void NString::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "\"" << str << "\"";
}
