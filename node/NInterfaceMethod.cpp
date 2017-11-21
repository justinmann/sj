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

bool CInterfaceMethodReturnVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CInterfaceMethodReturnVar::getType(Compiler* compiler, CResult& result) {
    return returnType;
}

void CInterfaceMethodReturnVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    assert(false);
}

void CInterfaceMethodReturnVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    assert(false);
}

bool CInterfaceMethodArgVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CInterfaceMethodArgVar::getType(Compiler* compiler, CResult& result) {
    return returnType;
}

void CInterfaceMethodArgVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    assert(false);
}

void CInterfaceMethodArgVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "interfaceArg";
}

CInterfaceMethod::CInterfaceMethod(string& name, weak_ptr<CInterface> parent, int methodIndex, CTypeMode returnMode) : CBaseFunction(CFT_InterfaceMethod, name, parent, weak_ptr<CBaseFunctionDefinition>()), returnMode(returnMode) {
    
}

shared_ptr<CInterfaceMethod> CInterfaceMethod::init(Compiler* compiler, CResult& result, shared_ptr<NInterfaceMethod> method, shared_ptr<CBaseFunction> thisFunction) {
    hasParent = true;
    loc = method->loc;
    returnType = getVarType(loc, compiler, result, method->returnTypeName, returnMode);
    if (!returnType) {
        result.addError(method->loc, CErrorCode::InvalidType, "type '%s' is not defined", method->returnTypeName->name.c_str());
        return nullptr;
    }

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
        if (returnMode == CTM_Heap) {
            ss << "_heap";
        }
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
        ss << argVar->getType(compiler, result)->cname;
        if (includeNames) {
            ss << " " << argVar->name;
        }
    }
    if (returnType != nullptr && returnType != compiler->typeVoid) {
        ss << ", ";
        ss << returnType->cname << "*";
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

shared_ptr<CType> CInterfaceMethod::getVarType(CLoc loc, Compiler* compiler, CResult& result, shared_ptr<CTypeName> typeName, CTypeMode defaultMode) {
    if (!parent.expired()) {
        return parent.lock()->getVarType(loc, compiler, result, typeName, defaultMode);
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

void CInterfaceMethod::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> parentValue, CLoc& calleeLoc, vector<pair<bool, shared_ptr<NBase>>>& parameters, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    assert(compiler->state == CompilerState::Compile);
    assert(parentValue != nullptr);

    auto returnType = getReturnType(compiler, result);
    if (!returnType) {
        return;
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
        auto argStoreValue = trBlock->createTempStoreVariable(loc, thisFunction, argType, "interfaceParam");

        stringstream argStream;
        auto paramVar = parameters[argIndex].second->getVar(compiler, result, isDefaultAssignment ? nullptr : thisFunction, isDefaultAssignment ? calleeVar : thisVar, CTM_Undefined);
        paramVar->transpile(compiler, result, trOutput, trBlock, nullptr, thisValue, argStoreValue);

        if (!argStoreValue->hasSetValue) {
            result.addError(calleeLoc, CErrorCode::TypeMismatch, "parameter '%s' has no value", argVar->name.c_str());
            return;
        }

        argValues.push_back(ArgData(argVar, argStoreValue));
        argIndex++;
    }

    // Call function
    stringstream line;
    line << parentValue->name << "->" << name;
    if (returnMode == CTM_Heap) {
        line << "_heap";
    }
    line << "(";
    line << parentValue->name << "->_parent";
    for (auto argValue : argValues) {
        line << ", ";
        line << argValue.name;
    }
    if (returnType != compiler->typeVoid) {
        line << ", ";
        line << "&" << storeValue->name;
    }
    line << ")";
    trBlock->statements.push_back(line.str()); 
    storeValue->hasSetValue = true;
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
