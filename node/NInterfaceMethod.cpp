#include "Node.h"

NInterfaceMethod::NInterfaceMethod(CLoc loc, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<NodeList> arguments_, shared_ptr<CTypeName> returnTypeName) : NBaseFunction(NodeType_InterfaceMethod, loc), name(name), templateTypeNames(templateTypeNames), returnTypeName(returnTypeName) {
    if (arguments_) {
        for (auto it : *arguments_) {
            assert(it->nodeType == NodeType_Assignment);
            assignments.push_back(static_pointer_cast<NAssignment>(it));
        }
    }
}

//void NInterfaceMethod::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
//    ss << name;
//    if (templateTypeNames) {
//        if (templateTypeNames->size() == 1) {
//            ss << "!" << (*templateTypeNames)[0]->getName();
//        } else {
//            ss << "![";
//            for (auto it : *templateTypeNames) {
//                ss << it->getName();
//            }
//            ss << "]";
//        }
//    }
//
//    ss << "(";
//
//    for (auto it : assignments) {
//        if (it != assignments.front()) {
//            ss << ", ";
//        }
//        auto var = it->getVar(compiler, result, thisFunction, thisVar);
//        stringstream dotSS;
//        var->dump(compiler, result, thisFunction, thisVar, returnMode, nullptr, functions, ss, dotSS, level);
//    }
//
//    ss << ")'" << returnTypeName->getName();
//}

shared_ptr<CType> CInterfaceMethodReturnVar::getType(Compiler* compiler, CResult& result) {
    return returnType;
}

shared_ptr<ReturnValue> CInterfaceMethodReturnVar::transpileGet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    assert(false);
	return nullptr;
}

void CInterfaceMethodReturnVar::transpileSet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName, AssignOp op, bool isFirstAssignment) {
    assert(false);
}

void CInterfaceMethodReturnVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    assert(false);
}


shared_ptr<CType> CInterfaceMethodArgVar::getType(Compiler* compiler, CResult& result) {
    return returnType;
}

shared_ptr<ReturnValue> CInterfaceMethodArgVar::transpileGet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    assert(false);
	return nullptr;
}

void CInterfaceMethodArgVar::transpileSet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName, AssignOp op, bool isFirstAssignment) {
    assert(false);
}

void CInterfaceMethodArgVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    assert(false);
}

CInterfaceMethod::CInterfaceMethod(string& name, weak_ptr<CInterface> parent, int methodIndex, CTypeMode returnMode) : CBaseFunction(CFT_InterfaceMethod, name, parent, weak_ptr<CBaseFunctionDefinition>()), returnMode(returnMode) {
    
}

shared_ptr<CInterfaceMethod> CInterfaceMethod::init(Compiler* compiler, CResult& result, shared_ptr<NInterfaceMethod> method, shared_ptr<CBaseFunction> thisFunction) {
    hasParent = true;
    loc = method->loc;
    returnType = getVarType(compiler, result, method->returnTypeName);
    if (!returnType) {
        result.addError(method->loc, CErrorCode::InvalidType, "type '%s' is not defined", method->returnTypeName->name.c_str());
        return nullptr;
    }
    
    
    // TODO: assert(false); // might need to pass in returntype to the init method

    for (auto it : method->assignments) {
        if (it->var) {
            result.addError(it->loc, CErrorCode::InvalidDot, "cannot use '.' in variable declaration for a function: '%s'", it->name.c_str());
            return nullptr;
        }
        
        // int index = (int)argVars.size();
        auto argType = it->getType(compiler, result, thisFunction, nullptr, CTM_Undefined);
        auto argVar = make_shared<CInterfaceMethodArgVar>(loc, thisFunction, argType);
        argVars.push_back(argVar);
        argDefaultValues.push_back(it->rightSide);
    }
    
    for (auto it : method->assignments) {
        auto argType = it->getType(compiler, result, parent.lock(), nullptr, CTM_Undefined);
        if (!argType) {
            return nullptr;
        }
    }
    
    return shared_from_this();
}

string CInterfaceMethod::fullName(bool includeTemplateTypes) {
    // TODO: includeTemplateTypes
    return name;
}

shared_ptr<CTypes> CInterfaceMethod::getThisTypes(Compiler* compiler, CResult& result) {
    return nullptr;
}

int CInterfaceMethod::getThisIndex(const string& name) const {
    assert(false);
    return -1;
}

shared_ptr<CVar> CInterfaceMethod::getThisVar(Compiler* compiler, CResult& result) {
    return nullptr;
}

shared_ptr<CVar> CInterfaceMethod::getCVar(Compiler* compiler, CResult& result, const string& name) {
    assert(false);
    return nullptr;
}

shared_ptr<CBaseFunction> CInterfaceMethod::getCFunction(Compiler* compiler, CResult& result, const string& name, shared_ptr<CBaseFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames, CTypeMode returnMode) {
    assert(false);
    return nullptr;
}

string CInterfaceMethod::getCTypeName(Compiler* compiler, CResult& result, bool includeNames) {
    stringstream ss;
    ss << "void";
    if (includeNames) {
        ss << " ";
    }
    ss << "(*";
    if (includeNames) {
        ss << name;
    }
    ss << ")(sjs_object*";
    if (includeNames) {
        ss << " _parent";
    }
    for (auto argVar : argVars) {
        ss << ",";
        if (includeNames) {
            ss << " ";
        }
        ss << argVar->getType(compiler, result)->nameRef;
        if (includeNames) {
            ss << " " << argVar->name;
        }
    }
    if (returnType != nullptr && returnType != compiler->typeVoid) {
        ss << ", ";
        ss << returnType->nameRef << "*";
        if (includeNames) {
            ss << " _return";
        }
    }
    ss << ")";
    return ss.str();
}

//Value* CInterfaceMethod::getParentValue(Compiler* compiler, CResult& result, IRBuilder<>* builder, bool thisInEntry, Value* thisValue) {
//    assert(false);
//    return nullptr;
//}

shared_ptr<CType> CInterfaceMethod::getVarType(Compiler* compiler, CResult& result, shared_ptr<CTypeName> typeName) {
    if (!parent.expired()) {
        return parent.lock()->getVarType(compiler, result, typeName);
    }
    
    return compiler->getType(typeName->name);
}

shared_ptr<CType> CInterfaceMethod::getReturnType(Compiler* compiler, CResult& result) {
    return returnType;
}

string CInterfaceMethod::getCInitFunctionName() {
    assert(false);
    return "";
}

string CInterfaceMethod::getCCopyFunctionName() {
    assert(false);
    return "";
}

string CInterfaceMethod::getCDestroyFunctionName() {
    assert(false);
    return "";
}

void CInterfaceMethod::transpileDefinition(Compiler* compiler, CResult& result, TrOutput* trOutput) {

}

shared_ptr<ReturnValue> CInterfaceMethod::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> calleeValue, CLoc& calleeLoc, vector<pair<bool, shared_ptr<NBase>>>& parameters, const char* thisName) {
    assert(compiler->state == CompilerState::Compile);
    assert(calleeValue != nullptr);

    auto returnType = getReturnType(compiler, result);
    if (!returnType) {
        return nullptr;
    }

    shared_ptr<ReturnValue> returnValue;
    if (returnType != compiler->typeVoid) {
        if (!returnType->parent.expired()) {
            returnValue = trBlock->createTempVariable(returnType, "result");
            stringstream initReturnStream;
            initReturnStream << returnValue->name << " = 0";
            trBlock->statements.push_back(initReturnStream.str());
        }
        else {
            returnValue = trBlock->createTempVariable(returnType, "result");
        }
    }

    auto thisTypes = getThisTypes(compiler, result);
    auto calleeVar = make_shared<CThisVar>(loc, nullptr, thisTypes, CTM_Heap);
    vector<ArgData> argValues;
    auto argIndex = 0;
    // Fill in "this" with normal arguments
    for (auto defaultAssignment : argDefaultValues) {
        auto argVar = argVars[argIndex];
        auto argType = argVar->getType(compiler, result);
        auto isDefaultAssignment = parameters[argIndex].second == defaultAssignment;
        assert(isDefaultAssignment == parameters[argIndex].first);
        shared_ptr<ReturnValue> argReturnValue;

        stringstream argStream;
        auto paramVar = parameters[argIndex].second->getVar(compiler, result, isDefaultAssignment ? nullptr : thisFunction, isDefaultAssignment ? calleeVar : thisVar, CTM_Undefined);
        argReturnValue = paramVar->transpileGet(compiler, result, trOutput, trBlock, nullptr, thisName);

        if (argReturnValue == nullptr) {
            result.addError(calleeLoc, CErrorCode::TypeMismatch, "parameter '%s' has no value", argVar->name.c_str());
            return nullptr;
        }

        if (argType == nullptr) {
            result.addError(calleeLoc, CErrorCode::TypeMismatch, "parameter '%s' type is undefined", argVar->name.c_str());
            return nullptr;
        }

        if (argReturnValue->type != argType) {
            result.addError(calleeLoc, CErrorCode::TypeMismatch, "parameter '%s' type '%s' does not match '%s'", argVar->name.c_str(), argReturnValue->type->name.c_str(), argType->name.c_str());
            return nullptr;
        }

        // TODO: assert(argReturnValue == nullptr || argReturnValue->release == RVR_MustRetain);

        argValues.push_back(ArgData(argVar, argReturnValue));
        argIndex++;
    }

    // Call function
    stringstream line;
    line << calleeValue->name << "->" << name << "(";
    line << calleeValue->name << "->_parent";
    for (auto argValue : argValues) {
        line << ", ";
        line << argValue.name;
    }
    if (returnValue) {
        line << ", ";
        line << "&" << returnValue->name;
    }
    line << ")";
    trBlock->statements.push_back(line.str());
    return returnValue;
}

void CInterfaceMethod::dumpBody(Compiler* compiler, CResult& result, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    //for (auto it : implementations) {
    //    if (functions.find(it) == functions.end()) {
    //        functions[it] = "";
    //        stringstream temp;
    //        it->dumpBody(compiler, result, nullptr, functions, temp, 0);
    //        functions[it] = temp.str();
    //    }
    //}
    //// TODO:
    //ss << name << "(" << ")";
}

bool CInterfaceMethod::getReturnMustRelease(Compiler* compiler, CResult& result) {
    return true;
}
