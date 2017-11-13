#include "Node.h"

class CCodeReturnVar : public CVar {
public:
    CCodeReturnVar() : _isHeapVar(false) {}
    
    shared_ptr<CType> getType(Compiler* compiler, CResult& result) {
        assert(false);
        return nullptr;
    }

    bool getHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
        return _isHeapVar;
    }

    int setHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
        if (!_isHeapVar) {
            _isHeapVar = true;
            return 1;
        }
        return 0;
    }

    shared_ptr<ReturnValue> transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue, shared_ptr<ReturnValue> dotValue) {
        assert(false);
        return nullptr;
    }

    void transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue) {
        assert(false);
    }

    void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
        assert(false);
    }

private:
    bool _isHeapVar;
};

shared_ptr<CType> NCCode::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    return compiler->typeVoid;
}

shared_ptr<CVar> NCCode::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
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
    _final[thisFunction.get()] = finalCode.str();

    return make_shared<CCodeReturnVar>();
}

string NCCode::expandMacro(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, string macro) {
    auto paramStart = macro.find('(');
    auto functionName = macro.substr(0, paramStart);
    auto param = macro.substr(paramStart + 1, macro.size() - paramStart - 2);

    if (functionName.compare("forceParent") == 0) {
        thisFunction->setHasParent(compiler, result);
        return "";
    }
    else if (functionName.compare("forceHeap") == 0) {
        auto cvar = thisFunction->getCVar(compiler, result, param);
        if (cvar) {
            cvar->setHeapVar(compiler, result, thisVar);
        }
        else {
            result.addError(loc, CErrorCode::InvalidMacro, "cannot find variable '%s'", param.c_str());
        }
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
            ReturnValue(ctype, true, RVR_MustRetain, varName).writeReleaseToStream(nullptr, releaseStream, 0);
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
    //*#forceParent# ->force current function to include a parent
    //    * #forceHeap(class)# ->force a var to be on heap
    //    * #type(class)# ->sjf_class*
    //    * #functionName(class)# ->sjf_class
    //    * #structName(class)# ->sjs_class
    //    * #isHeap(class)# -> true
    //    * #isValue(i32)# -> true
}

shared_ptr<ReturnValue> NCCode::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue) {
    trBlock->statements.push_back(_final[thisFunction.get()]);
    
    for (auto include : _includes) {
        trOutput->includes[include] = true;
    }
    return nullptr;
}

void NCCode::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "c{\n" << code << "\n}c";
}

