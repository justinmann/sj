#include "Node.h"
#include <boost/algorithm/string.hpp>

string expandMacro(Compiler* compiler, CLoc loc, shared_ptr<CScope> scope, TrOutput* trOutput, string macro, shared_ptr<TrStoreValue> returnValue, vector<shared_ptr<CFunction>>& functions, map<string, map<string, bool>>& includes , shared_ptr<CType>& returnType) {
    auto paramStart = macro.find('(');
    auto functionName = macro.substr(0, paramStart);
    auto t = macro.substr(paramStart + 1, macro.size() - paramStart - 2);
    vector<string> params;
    boost::split(params, t, boost::is_any_of(","), boost::token_compress_on);
    for (auto i = 0; i < (int)params.size(); i++) {
        boost::trim(params[i]);
    }

    if (functionName.compare("include") == 0) {
        if (params.size() != 1 && params.size() != 2) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "include requires 1 or 2 parameters");
            return "";
        }

        includes[params[0]][(params.size() == 2) ? params[1] : ""] = true;
    }
    else if (functionName.compare("type") == 0) {
        if (params.size() != 1) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "type requires 1 parameter");
            return "";
        }

        auto ctypeName = CTypeName::parse(params[0]);
        if (!ctypeName) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "invalid type specification '%s'", params[0].c_str());
        }

        auto ctype = scope->getVarType(loc, compiler, ctypeName, CTM_Undefined);
        if (ctype) {
            return ctype->cname;
        }
        else {
            compiler->addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", params[0].c_str());
        }
    }
    else if (functionName.compare("functionHeap") == 0) {
        if (params.size() != 1) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "functionHeap requires 1 parameter");
            return "";
        }

        auto ctypeName = CTypeName::parse(params[0]);
        if (!ctypeName) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "invalid type specification '%s'", params[0].c_str());
        }

        auto cfunction = static_pointer_cast<CFunction>(scope->function->getCFunction(compiler, loc, ctypeName->valueName, scope, ctypeName->argTypeNames, CTM_Heap));
        if (cfunction) {
            functions.push_back(cfunction);
            // Do they want the stack or heap version
            return cfunction->getCInitFunctionName(CTM_Heap);
        }
        else {
            compiler->addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", params[0].c_str());
        }
    }
    else if (functionName.compare("functionStack") == 0) {
        if (params.size() != 1) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "functionStack requires 1 parameter");
            return "";
        }

        auto ctypeName = CTypeName::parse(params[0]);
        if (!ctypeName) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "invalid type specification '%s'", params[0].c_str());
        }

        auto cfunction = static_pointer_cast<CFunction>(scope->function->getCFunction(compiler, loc, ctypeName->valueName, scope, ctypeName->argTypeNames, CTM_Stack));
        if (cfunction) {
            functions.push_back(cfunction);
            // Do they want the stack or heap version
            return cfunction->getCInitFunctionName(CTM_Stack);
        }
        else {
            compiler->addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", params[0].c_str());
        }
    }
    else if (functionName.compare("return") == 0) {
        if (params.size() != 2) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "return requires 2 parameters");
            return "";
        }

        auto typeName = params[0];
        auto rightName = params[1];

        auto ctypeName = CTypeName::parse(typeName);
        if (!ctypeName) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "invalid type specification '%s'", typeName.c_str());
        }

        auto ctype = scope->getVarType(loc, compiler, ctypeName, CTM_Undefined);
        if (ctype) {
            returnType = ctype;
            TrBlock block;
            stringstream retainStream;

            if (trOutput) {
                auto rightValue = make_shared<TrValue>(scope, ctype, rightName, false);
                if (ctype->typeMode == CTM_Stack) {
                    returnValue->op.isCopy = true;
                }
                returnValue->retainValue(compiler, loc, &block, rightValue);
                block.writeVariablesToStream(retainStream, 0);
                block.writeBodyToStream(retainStream, 0);
            }
            return retainStream.str();
        }
        else {
            compiler->addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", typeName.c_str());
        }
    }
    else if (functionName.compare("retain") == 0) {
        if (params.size() != 3) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "retain requires 3 parameters");
            return "";
        }

        auto typeName = params[0];
        auto leftName = params[1];
        auto rightName = params[2];

        auto ctypeName = CTypeName::parse(typeName);
        if (!ctypeName) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "invalid type specification '%s'", typeName.c_str());
        }

        auto ctype = scope->getVarType(loc, compiler, ctypeName, CTM_Undefined);
        if (ctype) {
            TrBlock block;
            stringstream retainStream;
            auto leftStoreValue = make_shared<TrStoreValue>(loc, scope, ctype, leftName, AssignOp::create(false, ctype->typeMode == CTM_Stack, ctype->typeMode), true);
            auto rightVar = scope->getCVar(compiler, rightName, VSM_LocalThisParent);
            if (!rightVar) {
                compiler->addError(loc, CErrorCode::InvalidMacro, "cannot find var '%s'", rightName.c_str());
                return "";
            }

            if (trOutput) {
                rightVar->transpile(compiler, trOutput, &block, nullptr, nullptr, leftStoreValue);
                block.writeVariablesToStream(retainStream, 0);
                block.writeBodyToStream(retainStream, 0);
            }
            return retainStream.str();
        }
        else {
            compiler->addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", typeName.c_str());
        }
    }
    else if (functionName.compare("release") == 0) {
        if (params.size() != 2) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "release requires 2 parameters");
            return "";
        }

        auto typeName = params[0];
        auto varName = params[1];

        auto ctypeName = CTypeName::parse(typeName);
        if (!ctypeName) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "invalid type specification '%s'", typeName.c_str());
        }

        auto ctype = scope->getVarType(loc, compiler, ctypeName, CTM_Undefined);
        if (ctype) {
            stringstream releaseStream;
            TrValue(scope, ctype, varName, false).writeReleaseToStream(releaseStream, 0);
            return releaseStream.str();
        }
        else {
            compiler->addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", typeName.c_str());
        }
    }
    else if (functionName.compare("isValue") == 0) {
        if (params.size() != 1) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "isValue requires 1 parameter");
            return "";
        }

        auto ctypeName = CTypeName::parse(params[0]);
        if (!ctypeName) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "invalid type specification '%s'", params[0].c_str());
        }

        auto ctype = scope->getVarType(loc, compiler, ctypeName, CTM_Undefined);
        if (ctype) {
            return ctype->parent.expired() ? "true" : "false";
        }
        else {
            compiler->addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", params[0].c_str());
        }
    }
    else {
        compiler->addError(loc, CErrorCode::InvalidMacro, "macro '%s' does not exist", functionName.c_str());
    }

    return "";
}

string expandMacros(Compiler* compiler, CLoc loc, shared_ptr<CScope> scope, TrOutput* trOutput, string& code, shared_ptr<TrStoreValue> returnValue, vector<shared_ptr<CFunction>>& functions, map<string, map<string, bool>>& includes, shared_ptr<CType>& returnType) {
    stringstream finalCode;
    stringstream macro;
    bool isInMacro = false;
    for (auto ch : code) {
        if (isInMacro) {
            if (ch == ')') {
                macro << ch;
                isInMacro = false;
                finalCode << expandMacro(compiler, loc, scope, trOutput, macro.str(), returnValue, functions, includes, returnType);
                macro.str("");
                macro.clear();
            }
            else if (ch == '\n') {
                isInMacro = false;
                finalCode << expandMacro(compiler, loc, scope, trOutput, macro.str(), returnValue, functions, includes, returnType) << '\n';
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
    return finalCode.str();
}

bool CCCodeVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CCCodeVar::getType(Compiler* compiler) {
    return returnType;
}

void CCCodeVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    vector<shared_ptr<CFunction>> functions;
    map<string, map<string, bool>> includes;
    shared_ptr<CType> returnType;
    string finalCode = expandMacros(compiler, loc, scope.lock(), trOutput, code, storeValue, functions, includes, returnType);

    for (auto cfunction : functions) {
        cfunction->transpileDefinition(compiler, trOutput);
    }

    switch (codeType) {
    case NCC_VAR:
        assert(false);
        break;
    case NCC_BLOCK:
        trBlock->statements.push_back(finalCode);
        break;
    case NCC_DEFINE:
        trOutput->ccodeDefines.push_back(finalCode);
        break;
    case NCC_STRUCT:
        trOutput->ccodeStructs.push_back(finalCode);
        break;
    case NCC_INCLUDE:
        trOutput->ccodeIncludes.push_back(finalCode);
        break;
    case NCC_FUNCTION:
        trOutput->ccodeFunctions.push_back(finalCode);
        break;
    }

    for (auto include : includes) {
        for (auto ifdef : include.second) {
            trOutput->includes[include.first][ifdef.first] = true;
        }
    }
}

void CCCodeVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    switch (codeType) {
    case NCC_VAR:
        ss << "cvar{\n";
        break;
    case NCC_BLOCK:
        ss << "c{\n";
        break;
    case NCC_DEFINE:
        ss << "cdefine{\n";
        break;
    case NCC_STRUCT:
        ss << "cstruct{\n";
        break;
    case NCC_INCLUDE:
        ss << "cinclude{\n";
        break;
    case NCC_FUNCTION:
        ss << "cfunction{\n";
        break;
    }
    ss << code;
    switch (codeType) {
    case NCC_VAR:
        ss << "\n}cvar";
        break;
    case NCC_BLOCK:
        ss << "\n}c";
        break;
    case NCC_DEFINE:
        ss << "\n}cdefine";
        break;
    case NCC_STRUCT:
        ss << "\n}cstruct";
        break;
    case NCC_INCLUDE:
        ss << "cinclude{\n";
        break;
    case NCC_FUNCTION:
        ss << "\n}cfunction";
        break;
    }
}

shared_ptr<CVar> NCCode::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode) {
    vector<shared_ptr<CFunction>> functions;
    map<string, map<string, bool>> includes;
    shared_ptr<CType> returnType = compiler->typeVoid;
    string finalCode = expandMacros(compiler, loc, scope, nullptr, code, nullptr, functions, includes, returnType);

    return make_shared<CCCodeVar>(loc, scope, codeType, code, returnType);
}


void NCCode::addToStruct(Compiler* compiler, shared_ptr<CScope> scope, vector<string>& lines) {
    vector<shared_ptr<CFunction>> functions;
    map<string, map<string, bool>> includes;
    shared_ptr<CType> returnType = compiler->typeVoid;
    string finalCode = expandMacros(compiler, loc, scope, nullptr, code, nullptr, functions, includes, returnType);
    lines.push_back(finalCode);
}
