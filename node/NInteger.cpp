#include "Node.h"
#include <climits>

shared_ptr<CType> CConstantVar::getType(Compiler* compiler, CResult& result) {
    return type;
}

void CConstantVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    storeValue->setValue(compiler, result, loc, trBlock, make_shared<TrValue>(type, value));
}

void CConstantVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << value;
    if (type == compiler->typeI32) {
        ss << "i";
    }
    else if (type == compiler->typeU32) {
        ss << "u";
    }
    else if (type == compiler->typeI64) {
        ss << "l";
    }
    else if (type == compiler->typeU64) {
        ss << "v";
    }
    else if (type == compiler->typeF32) {
        ss << "f";
    }
    else if (type == compiler->typeF64) {
        ss << "d";
    }
}


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

shared_ptr<CVar> NInteger::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
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
            return make_shared<CConstantVar>(loc, thisFunction, compiler->typeI32, line.str());
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
            return make_shared<CConstantVar>(loc, thisFunction, compiler->typeU32, "(uint32_t)" + line.str());
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
            return make_shared<CConstantVar>(loc, thisFunction, compiler->typeI64, line.str());
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
            return make_shared<CConstantVar>(loc, thisFunction, compiler->typeU64, line.str());
        }
        else {
            assert(false);
            return nullptr;
        }
    } else if (hasValue) {
        stringstream line;
        line << value;
        return make_shared<CConstantVar>(loc, thisFunction, compiler->typeI32, line.str());
    }
    return nullptr;
}

