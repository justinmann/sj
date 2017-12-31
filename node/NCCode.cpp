#include <sjc.h>

string expandMacro(Compiler* compiler, CLoc loc, shared_ptr<CScope> scope, TrOutput* trOutput, TrBlock* trBlock, string macro, shared_ptr<TrStoreValue> returnValue, vector<shared_ptr<CBaseFunction>>& functions, map<string, map<string, bool>>& includes , shared_ptr<CType>& returnType) {
    auto paramStart = macro.find('(');
    auto functionName = macro.substr(0, paramStart);
    auto t = macro.substr(paramStart + 1, macro.size() - paramStart - 2);
    vector<string> params;
    auto lastI = 0;
    auto parenCount = 0;
    for (auto i = 0; i < (int)t.size(); i++) {
        if (t[i] == ',' && parenCount == 0) {
            params.push_back(t.substr(lastI, i - lastI));
            lastI = i + 1;
        }
        if (t[i] == '(') { parenCount++; }
        if (t[i] == ')') { parenCount--; }
    }

    params.push_back(t.substr(lastI, t.size() - lastI));

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
    else if (functionName.compare("safeName") == 0) {
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
            return ctype->safeName;
        }
        else {
            compiler->addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", params[0].c_str());
        }
    }
    else if (functionName.compare("functionStack") == 0 || functionName.compare("functionHeap") == 0) {
        auto typeMode = functionName.compare("functionStack") == 0 ? CTM_Stack : CTM_Heap;
        if (params.size() != 1 && params.size() != 2) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "functionStack requires 1 or 2 parameters");
            return "";
        }

        if (params.size() == 2) {
            shared_ptr<CType> ctype;
            if (params[0] == "this") {
                ctype = scope->function->getThisTypes(compiler)->stackValueType;
            }
            else if (params[0] == "parent") {
                ctype = scope->function->parent.lock()->getThisTypes(compiler)->stackValueType;
            }
            else {
                auto ctypeName = CTypeName::parse(params[0]);
                if (!ctypeName) {
                    compiler->addError(loc, CErrorCode::InvalidMacro, "invalid type specification '%s'", params[0].c_str());
                }
                ctype = scope->getVarType(loc, compiler, ctypeName, CTM_Undefined);
            }

            if (ctype) {
                auto ctypeName2 = CTypeName::parse(params[1]);
                if (!ctypeName2) {
                    compiler->addError(loc, CErrorCode::InvalidMacro, "invalid type specification '%s'", params[1].c_str());
                }

                if (!ctype->parent.expired()) {
                    auto cfunction = static_pointer_cast<CBaseFunction>(ctype->parent.lock()->getCFunction(compiler, loc, ctypeName2->valueName, scope, ctypeName2->templateTypeNames, CTM_Stack));
                    if (cfunction) {
                        functions.push_back(cfunction);
                        if (trOutput) {
                            // Do they want the stack or heap version
                            return cfunction->getCFunctionName(compiler, trOutput, typeMode);
                        }
                        else {
                            return "INVALID";
                        }
                    }
                }

                string helperFunctionName = ctype->valueName + "_" + ctypeName2->valueName;
                auto cfunction = static_pointer_cast<CBaseFunction>(scope->function->getCFunction(compiler, loc, helperFunctionName, scope, ctypeName2->templateTypeNames, typeMode));
                if (cfunction) {
                    functions.push_back(cfunction);
                    if (trOutput) {
                        // Do they want the stack or heap version
                        return cfunction->getCFunctionName(compiler, trOutput, typeMode);
                    }
                    else {
                        return "INVALID";
                    }
                }
                else {
                    compiler->addError(loc, CErrorCode::InvalidMacro, "cannot find function '%s' for type '%s'", params[1].c_str(), ctype->fullName.c_str());
                }
            }
            else {
                compiler->addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", params[0].c_str());
            }
        }
        else {
            auto ctypeName = CTypeName::parse(params[0]);
            if (!ctypeName) {
                compiler->addError(loc, CErrorCode::InvalidMacro, "invalid type specification '%s'", params[0].c_str());
            }

            auto cfunction = scope->function->getCFunction(compiler, loc, ctypeName->valueName, scope, ctypeName->argTypeNames, typeMode);
            if (cfunction) {
                functions.push_back(cfunction);
                // Do they want the stack or heap version
                return cfunction->getCFunctionName(compiler, trOutput, CTM_Stack);
            }
            else {
                compiler->addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", params[0].c_str());
            }
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
            if (ctype->typeMode == CTM_Local) {
                ctype = ctype->getStackType() ? ctype->getStackType() : ctype->getHeapType();
            }

            if (returnType != nullptr && returnType != ctype) {
                compiler->addError(loc, CErrorCode::InvalidType, "all return types must agree");
            }
            returnType = ctype;
            TrBlock block(trBlock);
            stringstream retainStream;

            if (trOutput) {
                auto rightValue = make_shared<TrValue>(scope, ctype, rightName, false);
                if (ctype->typeMode == CTM_Stack) {
                    returnValue->op.isCopy = true;
                }
                returnValue->retainValue(compiler, loc, &block, rightValue);
                block.writeVariablesToStream(compiler, retainStream, 0);
                block.writeBodyToStream(compiler, retainStream, 0);
            }
            retainStream << "return;";
            return retainStream.str();
        }
        else {
            compiler->addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", typeName.c_str());
        }
    }
    else if (functionName.compare("returnEmpty") == 0) {
        if (params.size() != 1) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "returnEmpty requires 1 parameter");
            return "";
        }

        auto typeName = params[0];

        auto ctypeName = CTypeName::parse(typeName);
        if (!ctypeName) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "invalid type specification '%s'", typeName.c_str());
        }

        auto ctype = scope->getVarType(loc, compiler, ctypeName, CTM_Undefined);
        if (ctype) {
            if (ctype->typeMode == CTM_Local) {
                ctype = ctype->getStackType() ? ctype->getStackType() : ctype->getHeapType();
            }

            if (returnType != nullptr && returnType != ctype->getOptionType()) {
                compiler->addError(loc, CErrorCode::InvalidType, "all return types must agree");
            }
            returnType = ctype->getOptionType();
            TrBlock block(trBlock);
            stringstream retainStream;

            if (trOutput) {
                returnType->transpileDefaultValue(compiler, loc, &block, returnValue);
                block.writeVariablesToStream(compiler, retainStream, 0);
                block.writeBodyToStream(compiler, retainStream, 0);
            }
            retainStream << "return;";
            return retainStream.str();
        }
        else {
            compiler->addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", typeName.c_str());
        }
    }
    else if (functionName.compare("returnValue") == 0) {
        if (params.size() != 2) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "returnValue requires 2 parameters");
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
            if (ctype->typeMode == CTM_Local) {
                ctype = ctype->getStackType() ? ctype->getStackType() : ctype->getHeapType();
            }

            if (returnType != nullptr && returnType != ctype->getOptionType()) {
                compiler->addError(loc, CErrorCode::InvalidType, "all return types must agree");
            }
            returnType = ctype->getOptionType();
            TrBlock block(trBlock);
            stringstream retainStream;

            if (trOutput) {
                if (returnType->parent.expired() && returnType->category != CTC_Function) {
                    stringstream line1;
                    line1 << "_return->isvalid = true";
                    block.statements.push_back(TrStatement(loc, line1.str()));

                    stringstream line2;
                    line2 << "_return->value = " << rightName;
                    block.statements.push_back(TrStatement(loc, line2.str()));
                }
                else {
                    if (ctype->typeMode == CTM_Stack) {
                        auto rightValue = make_shared<TrValue>(scope, returnType, rightName, false);
                        returnValue->op.isCopy = true;
                        returnValue->retainValue(compiler, loc, &block, rightValue);
                    }
                    else {
                        auto rightValue = make_shared<TrValue>(scope, returnType, rightName, false);
                        returnValue->retainValue(compiler, loc, &block, rightValue);
                    }
                }
                block.writeVariablesToStream(compiler, retainStream, 0);
                block.writeBodyToStream(compiler, retainStream, 0);
            }
            retainStream << "return;";
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
            TrBlock block(trBlock);
            stringstream retainStream;
            auto leftStoreValue = make_shared<TrStoreValue>(loc, scope, ctype, leftName, AssignOp::create(true, false, ctype->typeMode == CTM_Stack, ctype->typeMode));
            auto rightVar = scope->getCVar(compiler, scope, nullptr, rightName, VSM_LocalThisParent);
            if (!rightVar) {
                auto rightValue = make_shared<TrValue>(scope, ctype, rightName, false);
                if (trOutput) {
                    leftStoreValue->retainValue(compiler, loc, &block, rightValue);
                    block.writeVariablesToStream(compiler, retainStream, 0);
                    block.writeBodyToStream(compiler, retainStream, 0);
                }
            }
            else {
                if (trOutput) {
                    rightVar->transpile(compiler, trOutput, &block, nullptr, leftStoreValue);
                    block.writeVariablesToStream(compiler, retainStream, 0);
                    block.writeBodyToStream(compiler, retainStream, 0);
                }
            }
            return retainStream.str();
        }
        else {
            compiler->addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", typeName.c_str());
        }
    }
    else if (functionName.compare("release") == 0) {
        if (params.size() < 2) {
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
            TrValue(scope, ctype, varName, false).writeReleaseToStream(compiler, trBlock, releaseStream, 0);
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
    else if (functionName.compare("isStack") == 0) {
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
            return ctype->typeMode == CTM_Stack ? "true" : "false";
        }
        else {
            compiler->addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", params[0].c_str());
        }
    }
    else if (functionName.compare("isWeak") == 0) {
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
            return ctype->typeMode == CTM_Weak ? "true" : "false";
        }
        else {
            compiler->addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", params[0].c_str());
        }
    }
    else if (functionName.compare("isPtrEqual") == 0) {
        if (params.size() != 3) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "isPtrEqual requires 3 parameter");
            return "";
        }

        auto ctypeName = CTypeName::parse(params[0]);
        if (!ctypeName) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "invalid type specification '%s'", params[0].c_str());
        }

        auto ctype = scope->getVarType(loc, compiler, ctypeName, CTM_Undefined);
        if (ctype) {
            if (ctype->category == CTC_Function) {
                return "(" + params[1] + "._parent == " + params[2] + "._parent && " + params[1] + "._cb == " + params[2] + "._cb)";
            }
            else if (ctype->category == CTC_Interface) {
                return "(" + params[1] + "._parent == " + params[2] + "._parent)";
            }
            else {
                return "(" + params[1] + " == " + params[2] + ")";
            }
        }
        else {
            compiler->addError(loc, CErrorCode::InvalidMacro, "cannot find type '%s'", params[0].c_str());
        }
    }
    else if (functionName.compare("parent") == 0) {
        if (params.size() != 2) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "parent requires 3 parameter");
            return "";
        }

        auto ctypeName = CTypeName::parse(params[0]);
        if (!ctypeName) {
            compiler->addError(loc, CErrorCode::InvalidMacro, "invalid type specification '%s'", params[0].c_str());
        }

        auto ctype = scope->getVarType(loc, compiler, ctypeName, CTM_Undefined);
        if (ctype) {
            if (ctype->category == CTC_Function) {
                return params[1] + "._parent";
            }
            else if (ctype->category == CTC_Interface) {
                return params[1] + "._parent";
            }
            else {
                return params[1];
            }
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

string expandMacros(Compiler* compiler, CLoc loc, shared_ptr<CScope> scope, TrOutput* trOutput, TrBlock* trBlock, string& code, shared_ptr<TrStoreValue> returnValue, vector<shared_ptr<CBaseFunction>>& functions, map<string, map<string, bool>>& includes, shared_ptr<CType>& returnType) {
    char finalCode[1024];
    char macro[1024];
    int finalIndex = 0;
    int macroIndex = 0;
    int macroParenCount = 0;

    bool isInMacro = false;
    bool isInWhitespace = true;
    int parenCount = 0;
    for (auto ch : code) {
        if (isInWhitespace) {
            if (ch == ' ' || ch == '\t' || ch == ' ') {
                continue;
            }
            else {
                isInWhitespace = false;
            }
        }

        if (isInMacro) {
            if (ch == ')') {
                parenCount--;
                macro[macroIndex] = ch;
                macroIndex++;
                if (parenCount == macroParenCount) {
                    isInMacro = false;
                    macro[macroIndex] = 0;
                    string t = macro;
                    auto expandedMacro = expandMacro(compiler, loc, scope, trOutput, trBlock, t, returnValue, functions, includes, returnType);
                    for (auto i : expandedMacro) {
                        finalCode[finalIndex] = i;
                        finalIndex++;
                    }
                    macroIndex = 0;
                }
            }
            else if (ch == '#') {
                isInMacro = false;
                finalCode[finalIndex] = ch;
                finalIndex++;
                macroIndex = 0;
            }
            else if (ch == '(') {
                parenCount++;
                macro[macroIndex] = ch;
                macroIndex++;
            }
            else {
                macro[macroIndex] = ch;
                macroIndex++;
            }
        }
        else if (ch == '#') {
            isInMacro = true;
            macroParenCount = parenCount;
        }
        else {
            finalCode[finalIndex] = ch;
            finalIndex++;
        }
    }

    finalCode[finalIndex] = 0;
    return string(finalCode);
}

bool CCCodeVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CCCodeVar::getType(Compiler* compiler) {
    return returnType;
}

void CCCodeVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    vector<shared_ptr<CBaseFunction>> functions;
    map<string, map<string, bool>> includes;
    shared_ptr<CType> returnType;
    auto lineIndex = -1;
    for (auto line : lines) {
        lineIndex++;

        auto finalLine = expandMacros(compiler, loc, scope.lock(), trOutput, trBlock, line, storeValue, functions, includes, returnType);
        if (finalLine.size() == 0) {
            continue;
        }

        switch (codeType) {
        case NCC_VAR:
            assert(false);
            break;
        case NCC_BLOCK:
            trBlock->statements.push_back(TrStatement(CLoc(loc.fullFileName, loc.shortFileName, loc.line + lineIndex, 1), finalLine, true));
            break;
        case NCC_DEFINE:
            trOutput->ccodeDefines.push_back(finalLine);
            break;
        case NCC_STRUCT:
            trOutput->ccodeStructs.push_back(finalLine);
            break;
        case NCC_INCLUDE:
            trOutput->ccodeIncludes.push_back(finalLine);
            break;
        case NCC_TYPEDEF:
            trOutput->ccodeTypedefs.push_back(finalLine);
            break;
        case NCC_FUNCTION:
            trOutput->ccodeFunctions.push_back(finalLine);
            break;
        }
    }

    for (auto cfunction : functions) {
        cfunction->transpileDefinition(compiler, trOutput);
    }

    for (auto include : includes) {
        for (auto ifdef : include.second) {
            trOutput->includes[include.first][ifdef.first] = true;
        }
    }
}

void CCCodeVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    vector<shared_ptr<CBaseFunction>> functions2;
    map<string, map<string, bool>> includes;
    shared_ptr<CType> returnType;

    switch (codeType) {
    case NCC_VAR:
        ss << "--cvar--\n";
        break;
    case NCC_BLOCK:
        ss << "--c--\n";
        break;
    case NCC_DEFINE:
        ss << "--cdefine--\n";
        break;
    case NCC_STRUCT:
        ss << "--cstruct--\n";
        break;
    case NCC_INCLUDE:
        ss << "--cinclude--\n";
        break;
    case NCC_TYPEDEF:
        ss << "--ctypedef--\n";
        break;
    case NCC_FUNCTION:
        ss << "--cfunction--\n";
        break;
    }

    for (auto line : lines) {
        auto finalLine = expandMacros(compiler, loc, scope.lock(), nullptr, nullptr, line, nullptr, functions2, includes, returnType);
        if (finalLine.size() == 0) {
            continue;
        }

        dumpf(ss, level);
        ss << finalLine;
        ss << "\n";
    }

    dumpf(ss, level);
    switch (codeType) {
    case NCC_VAR:
        ss << "--cvar--";
        break;
    case NCC_BLOCK:
        ss << "--c--";
        break;
    case NCC_DEFINE:
        ss << "--cdefine--";
        break;
    case NCC_STRUCT:
        ss << "--cstruct--";
        break;
    case NCC_INCLUDE:
        ss << "--cinclude--";
        break;
    case NCC_TYPEDEF:
        ss << "--ctypedef--";
        break;
    case NCC_FUNCTION:
        ss << "--cfunction--";
        break;
    }
}

shared_ptr<CVar> NCCode::getVarImpl(Compiler* compiler, shared_ptr<CScope> scope, shared_ptr<CType> returnType_, CTypeMode returnMode) {
    vector<shared_ptr<CBaseFunction>> functions;
    map<string, map<string, bool>> includes;
    shared_ptr<CType> returnType = nullptr;
    for (auto line : lines) {
        expandMacros(compiler, loc, scope, nullptr, nullptr, line, nullptr, functions, includes, returnType);
    }

    if (!returnType) {
        returnType = compiler->typeVoid;
    }

    return make_shared<CCCodeVar>(loc, scope, codeType, lines, returnType);
}


void NCCode::addToStruct(Compiler* compiler, shared_ptr<CScope> scope, vector<string>& structLines) {
    vector<shared_ptr<CBaseFunction>> functions;
    map<string, map<string, bool>> includes;
    shared_ptr<CType> returnType = nullptr;

    for (auto line : lines) {
        auto finalLine = expandMacros(compiler, loc, scope, nullptr, nullptr, line, nullptr, functions, includes, returnType);
        if (finalLine.size() == 0) {
            continue;
        }

        structLines.push_back(finalLine);
    }
}
