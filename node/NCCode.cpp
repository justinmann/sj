#include "Node.h"

shared_ptr<CType> CCCodeVar::getType(Compiler* compiler, CResult& result) {
    return compiler->typeVoid;
}

shared_ptr<ReturnValue> CCCodeVar::transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    for (auto cfunction : functions) {
        cfunction->transpileDefinition(compiler, result, trOutput, CTM_Heap);
    }

    switch (codeType) {
    case NCC_BLOCK:
        trBlock->statements.push_back(code);
        break;
    case NCC_DEFINE:
        trOutput->ccodeDefines.push_back(code);
        break;
    case NCC_FUNCTION:
        trOutput->ccodeFunctions.push_back(code);
        break;
    }

    for (auto include : includes) {
        trOutput->includes[include] = true;
    }
    return nullptr;
}

void CCCodeVar::transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) {
    assert(false);
}

void CCCodeVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    switch (codeType) {
    case NCC_BLOCK:
        ss << "c{\n";
        break;
    case NCC_DEFINE:
        ss << "cdefine{\n";
        break;
    case NCC_FUNCTION:
        ss << "cfunction{\n";
        break;
    }
    ss << code;
    switch (codeType) {
    case NCC_BLOCK:
        ss << "\n}c";
        break;
    case NCC_DEFINE:
        ss << "\n}cdefine";
        break;
    case NCC_FUNCTION:
        ss << "\n}cfunction";
        break;
    }
}

shared_ptr<CVar> NCCode::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar) {
    stringstream finalCode;
    stringstream macro;
    bool isInMacro = false;
    for (auto ch : code) {
        if (isInMacro) {
            if (ch == ')') {
                macro << ch;
                isInMacro = false;
                finalCode << expandMacro(compiler, result, thisFunction, thisVar, macro.str());
                macro.str("");
                macro.clear();
            }
            else if (ch == '\n') {
                isInMacro = false;
                finalCode << expandMacro(compiler, result, thisFunction, thisVar, macro.str()) << '\n';
                macro.str("");
                macro.clear();
            }
            else if (ch == '#') {
                isInMacro = false;
                finalCode << '#';
                macro.str("");
                macro.clear();
            }
            else {
                macro << ch;
            }
        }
        else if (ch == '#') {
            isInMacro = true;
        }
        else {
            finalCode << ch;
        }
    }
    return make_shared<CCCodeVar>(loc, codeType, finalCode.str(), _functions[thisFunction.get()], _includes);
}

string NCCode::expandMacro(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, string macro) {
    auto paramStart = macro.find('(');
    auto functionName = macro.substr(0, paramStart);
    auto param = macro.substr(paramStart + 1, macro.size() - paramStart - 2);

    if (functionName.compare("forceParent") == 0) {
        thisFunction->setHasParent(compiler, result);
        return "";
    }
    else if (functionName.compare("include") == 0) {
        _includes.push_back(param);
    }
    else if (functionName.compare("type") == 0) {
        auto ctypeName = CTypeName::parse(param);
        if (!ctypeName) {
            result.addError(loc, CErrorCode::InvalidMacro, "invalid type specification '%s'", param.c_str());
        }

        auto ctype = thisFunction->getVarType(compiler, result, ctypeName);
        if (ctype) {
            return ctype->nameRef;
        }
        else {
            result.addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", param.c_str());
        }
    }
    else if (functionName.compare("function") == 0) {
        assert(false); // This only supports the function that returns heap
        auto ctypeName = CTypeName::parse(param);
        if (!ctypeName) {
            result.addError(loc, CErrorCode::InvalidMacro, "invalid type specification '%s'", param.c_str());
        }
        
        auto cfunction = static_pointer_cast<CFunction>(thisFunction->getCFunction(compiler, result, ctypeName->name, thisFunction, ctypeName->argTypeNames));
        if (cfunction) {
            _functions[thisFunction.get()].push_back(cfunction);
            assert(false); // Do they want the stack or heap version
            // TODO: return cfunction->getCInitFunctionName(CTM_Heap);
        }
        else {
            result.addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", param.c_str());
        }
    }
    else if (functionName.compare("retain") == 0) {
        auto comma = param.find(',');
        auto typeName = param.substr(0, comma);
        auto varName = param.substr(comma + 1, param.size() - comma - 1);

        auto ctypeName = CTypeName::parse(typeName);
        if (!ctypeName) {
            result.addError(loc, CErrorCode::InvalidMacro, "invalid type specification '%s'", typeName.c_str());
        }

        auto ctype = thisFunction->getVarType(compiler, result, ctypeName);
        if (ctype) {
            stringstream retainStream;
            if (!ctype->parent.expired()) {
                retainStream << varName << "->_refCount++;\n";
            }
            return retainStream.str();
        }
        else {
            result.addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", typeName.c_str());
        }
    }
    else if (functionName.compare("release") == 0) {
        auto comma = param.find(',');
        auto typeName = param.substr(0, comma);
        auto varName = param.substr(comma + 1, param.size() - comma - 1);

        auto ctypeName = CTypeName::parse(typeName);
        if (!ctypeName) {
            result.addError(loc, CErrorCode::InvalidMacro, "invalid type specification '%s'", typeName.c_str());
        }

        auto ctype = thisFunction->getVarType(compiler, result, ctypeName);
        if (ctype) {
            stringstream releaseStream;
            ReturnValue(ctype, varName).writeReleaseToStream(nullptr, releaseStream, 0);
            return releaseStream.str();
        }
        else {
            result.addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", typeName.c_str());
        }
    }
    else if (functionName.compare("isValue") == 0) {
        auto ctypeName = CTypeName::parse(param);
        if (!ctypeName) {
            result.addError(loc, CErrorCode::InvalidMacro, "invalid type specification '%s'", param.c_str());
        }

        auto ctype = thisFunction->getVarType(compiler, result, ctypeName);
        if (ctype) {
            return ctype->parent.expired() ? "true" : "false";
        }
        else {
            result.addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", param.c_str());
        }
    }
    else {
        result.addError(loc, CErrorCode::InvalidMacro, "macro '%s' does not exist", functionName.c_str());
    }

    return "";
}
