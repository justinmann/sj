#include "Node.h"

/*
bool CConstantVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CConstantVar::getType(Compiler* compiler) {
    return type;
}

void CConstantVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    storeValue->retainValue(compiler, loc, trBlock, make_shared<TrValue>(nullptr, type, value, false));
}

void CConstantVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
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
*/

shared_ptr<CVar> NEnum::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CVar> dotVar, CTypeMode returnMode) {
    /* if (strValue.size() > 0) {
        if (type == NIT_I32) {
            char* e;
            errno = 0;
            auto v = strtol(strValue.c_str(), &e, 10);
            if (ERANGE == errno || v < INT32_MIN || v > INT32_MAX) {
                compiler->addError(loc, CErrorCode::InvalidNumber, "i32 '%s' is out range", strValue.c_str());
                return nullptr;
            }

            if (*e != '\0') {
                compiler->addError(loc, CErrorCode::InvalidNumber, "not a valid i32 '%s'", strValue.c_str());
                return nullptr;
            }

            stringstream line;
            if (v == INT32_MIN) {
                line << "(" << v + 1 << " - 1)";
            }
            else {
                line << v;
            }
            return make_shared<CConstantVar>(loc, scope, compiler->typeI32, line.str());
        }
        else if (type == NIT_U32) {
            char* e;
            errno = 0;
            auto v = strtoul(strValue.c_str(), &e, 10);
            if (ERANGE == errno || v > UINT32_MAX) {
                compiler->addError(loc, CErrorCode::InvalidNumber, "u32 '%s' is out range", strValue.c_str());
                return nullptr;
            }

            if (*e != '\0') {
                compiler->addError(loc, CErrorCode::InvalidNumber, "not a valid u32 '%s'", strValue.c_str());
                return nullptr;
            }

            stringstream line;
            line << v << "u";
            return make_shared<CConstantVar>(loc, scope, compiler->typeU32, "(uint32_t)" + line.str());
        }
        else if (type == NIT_I64) {
            char* e;
            errno = 0;
            auto v = strtoll(strValue.c_str(), &e, 10);
            if (ERANGE == errno) {
                compiler->addError(loc, CErrorCode::InvalidNumber, "i64 '%s' is out range", strValue.c_str());
                return nullptr;
            }

            if (*e != '\0') {
                compiler->addError(loc, CErrorCode::InvalidNumber, "not a valid i64 '%s'", strValue.c_str());
                return nullptr;
            }

            stringstream line;
            if (v == INT64_MIN) {
                line << "(" << v + 1 << "ll" << " - 1ll)";
            }
            else {
                line << v << "ll";
            }
            return make_shared<CConstantVar>(loc, scope, compiler->typeI64, line.str());
        }
        else if (type == NIT_U64) {
            char* e;
            errno = 0;
            auto v = strtoull(strValue.c_str(), &e, 10);
            if (ERANGE == errno) {
                compiler->addError(loc, CErrorCode::InvalidNumber, "u64 '%s' is out range", strValue.c_str());
                return nullptr;
            }

            if (*e != '\0') {
                compiler->addError(loc, CErrorCode::InvalidNumber, "not a valid u64 '%s'", strValue.c_str());
                return nullptr;
            }

            stringstream line;
            line << v << "ull";
            return make_shared<CConstantVar>(loc, scope, compiler->typeU64, line.str());
        }
        else {
            assert(false);
            return nullptr;
        }
    } else if (hasValue) {
        stringstream line;
        line << value;
        return make_shared<CConstantVar>(loc, scope, compiler->typeI32, line.str());
    } */
    return nullptr;
}
