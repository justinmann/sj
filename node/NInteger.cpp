#include "Node.h"
#include <climits>

NInteger::NInteger(CLoc loc, const char* value_) : NVariableBase(NodeType_Integer, loc), strValue(value_), hasValue(false) {
    if (strValue.back() == 'i') {
        type = NIT_I32;
        strValue = strValue.substr(0, strValue.size() - 1);
    }
    else if (strValue.back() == 'u') {
        type = NIT_U32;
        strValue = strValue.substr(0, strValue.size() - 1);
    }
    else if (strValue.back() == 'v') {
        type = NIT_U64;
        strValue = strValue.substr(0, strValue.size() - 1);
    }
    else if (strValue.back() == 'l') {
        type = NIT_I64;
        strValue = strValue.substr(0, strValue.size() - 1);
    }
    else {
        type = NIT_I32;
    }
}

shared_ptr<CType> NInteger::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    switch (type) {
    case NIT_I32:
        return compiler->typeI32;
    case NIT_U32:
        return compiler->typeU32;
    case NIT_I64:
        return compiler->typeI64;
    case NIT_U64:
        return compiler->typeU64;
    default:
        assert(false);
        return nullptr;
    }
}

//shared_ptr<ReturnValue> NInteger::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    assert(compiler->state == CompilerState::Compile);
//    compiler->emitLocation(builder, &this->loc);
//    
//    if (strValue.size() > 0) {
//        char* e;
//        errno = 0;
//        auto v = strtoll(strValue.c_str(), &e, 10);
//        
//        if (ERANGE == errno) {
//            result.addError(loc, CErrorCode::InvalidNumber, "not a valid int '%s'", strValue.c_str());
//            return nullptr;
//        }
//
//        if (*e != '\0') {
//            result.addError(loc, CErrorCode::InvalidNumber, "not a valid int '%s'", strValue.c_str());
//            return nullptr;
//        }
//        return make_shared<ReturnValue>(false, ConstantInt::get(compiler->context, APInt(64, v)));
//    } else {
//        return make_shared<ReturnValue>(false, ConstantInt::get(compiler->context, APInt(64, value)));
//    }
//}

shared_ptr<ReturnValue> NInteger::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue) {

    if (strValue.size() > 0) {
        if (type == NIT_I32) {
            char* e;
            errno = 0;
            auto v = strtol(strValue.c_str(), &e, 10);
            if (ERANGE == errno || v < INT32_MIN || v > INT32_MAX) {
                result.addError(loc, CErrorCode::InvalidNumber, "i32 '%s' is out range", strValue.c_str());
                return nullptr;
            }

            if (*e != '\0') {
                result.addError(loc, CErrorCode::InvalidNumber, "not a valid i32 '%s'", strValue.c_str());
                return nullptr;
            }

            stringstream line;
            line << v;
            return make_shared<ReturnValue>(compiler->typeI32, false, RVR_MustRetain, line.str());
        }
        else if (type == NIT_U32) {
            char* e;
            errno = 0;
            auto v = strtoul(strValue.c_str(), &e, 10);
            if (ERANGE == errno || v > UINT32_MAX) {
                result.addError(loc, CErrorCode::InvalidNumber, "u32 '%s' is out range", strValue.c_str());
                return nullptr;
            }

            if (*e != '\0') {
                result.addError(loc, CErrorCode::InvalidNumber, "not a valid u32 '%s'", strValue.c_str());
                return nullptr;
            }

            stringstream line;
            line << v << "u";
            return make_shared<ReturnValue>(compiler->typeU32, false, RVR_MustRetain, "(uint32_t)" + line.str());
        }
        else if (type == NIT_I64) {
            char* e;
            errno = 0;
            auto v = strtoll(strValue.c_str(), &e, 10);
            if (ERANGE == errno) {
                result.addError(loc, CErrorCode::InvalidNumber, "i64 '%s' is out range", strValue.c_str());
                return nullptr;
            }

            if (*e != '\0') {
                result.addError(loc, CErrorCode::InvalidNumber, "not a valid i64 '%s'", strValue.c_str());
                return nullptr;
            }

            stringstream line;
            if (v == INT64_MIN) {
                line << "(" << v + 1 << "ll" << " - 1ll)";
            }
            else {
                line << v << "ll";
            }
            return make_shared<ReturnValue>(compiler->typeI64, false, RVR_MustRetain, line.str());
        }
        else if (type == NIT_U64) {
            char* e;
            errno = 0;
            auto v = strtoull(strValue.c_str(), &e, 10);
            if (ERANGE == errno) {
                result.addError(loc, CErrorCode::InvalidNumber, "u64 '%s' is out range", strValue.c_str());
                return nullptr;
            }

            if (*e != '\0') {
                result.addError(loc, CErrorCode::InvalidNumber, "not a valid u64 '%s'", strValue.c_str());
                return nullptr;
            }

            stringstream line;
            line << v << "ull";
            return make_shared<ReturnValue>(compiler->typeU64, false, RVR_MustRetain, line.str());
        }
        else {
            assert(false);
            return nullptr;
        }
    } else if (hasValue) {
        stringstream line;
        line << value;
        return make_shared<ReturnValue>(compiler->typeI32, false, RVR_MustRetain, line.str());
    }
    return nullptr;
}

void NInteger::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << strValue;
    switch (type) {
    case NIT_I32:
        ss << "i";
        break;
    case NIT_U32:
        ss << "u";
        break;
    case NIT_I64:
        ss << "l";
        break;
    case NIT_U64:
        ss << "v";
        break;
    }
}
