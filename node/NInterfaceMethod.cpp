#include "Node.h"

NInterfaceMethod::NInterfaceMethod(CLoc loc, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<NodeList> arguments_, shared_ptr<CTypeName> returnTypeName) : NBaseFunction(NodeType_InterfaceMethod, loc), name(name), templateTypeNames(templateTypeNames), returnTypeName(returnTypeName) {
    if (arguments_) {
        for (auto it : *arguments_) {
            assert(it->nodeType == NodeType_Assignment);
            assignments.push_back(static_pointer_cast<NAssignment>(it));
        }
    }
}

//void NInterfaceMethod::dump(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
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
//        auto var = it->getVar(compiler, scope);
//        stringstream dotSS;
//        var->dump(compiler, scope, returnMode, nullptr, functions, ss, dotSS, level);
//    }
//
//    ss << ")'" << returnTypeName->getName();
//}

bool CInterfaceMethodReturnVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CInterfaceMethodReturnVar::getType(Compiler* compiler) {
    return returnType;
}

void CInterfaceMethodReturnVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    assert(false);
}

void CInterfaceMethodReturnVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    assert(false);
}

bool CInterfaceMethodArgVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CInterfaceMethodArgVar::getType(Compiler* compiler) {
    return returnType;
}

void CInterfaceMethodArgVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    assert(false);
}

void CInterfaceMethodArgVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    ss << "interfaceArg";
}

CInterfaceMethod::CInterfaceMethod(string& name, weak_ptr<CInterface> parent, int methodIndex, CTypeMode returnMode) : CBaseFunction(CFT_InterfaceMethod, name, parent, weak_ptr<CBaseFunctionDefinition>(), true), returnMode(returnMode) {
    
}

shared_ptr<CInterfaceMethod> CInterfaceMethod::init(Compiler* compiler, shared_ptr<NInterfaceMethod> method, shared_ptr<CBaseFunction> thisFunction) {
    hasParent = true;
    loc = method->loc;
    returnType = getVarType(loc, compiler, method->returnTypeName, returnMode);
    if (!returnType) {
        compiler->addError(method->loc, CErrorCode::InvalidType, "type '%s' is not defined", method->returnTypeName->getFullName().c_str());
        return nullptr;
    }

    auto parentScope = static_pointer_cast<CInterface>(parent.lock())->getScope();
    for (auto it : method->assignments) {
        if (it->var) {
            compiler->addError(it->loc, CErrorCode::InvalidDot, "cannot use '.' in variable declaration for a function: '%s'", it->name.c_str());
            return nullptr;
        }
        
        auto argType = it->getType(compiler, parentScope, CVarType::Var_Public, CTM_Undefined);
        if (!argType) {
            return nullptr;
        }

        auto argVar = make_shared<CInterfaceMethodArgVar>(loc, shared_from_this(), argType, it->name);
        argVars.push_back(argVar);
        FunctionDefaultValue defaultValue;
        defaultValue.op = it->op;
        defaultValue.value = it->rightSide;
        argDefaultValues.push_back(defaultValue);
        
        argIndex[it->name] = (int)argDefaultValues.size() - 1;
    }
    
    return shared_from_this();
}

string CInterfaceMethod::fullName(bool includeTemplateTypes) {
    // TODO: includeTemplateTypes
    return name;
}

shared_ptr<CTypes> CInterfaceMethod::getThisTypes(Compiler* compiler) {
    return nullptr;
}

int CInterfaceMethod::getArgIndex(const string& name, CTypeMode returnMode) {
    if (argIndex.find(name) != argIndex.end()) {
        return argIndex[name];
    }
    return -1;
}

shared_ptr<CVar> CInterfaceMethod::getArgVar(int index, CTypeMode returnMode) {
    return argVars[index];
}

int CInterfaceMethod::getArgCount(CTypeMode returnMode) {
    return (int)argVars.size();
}

shared_ptr<CVar> CInterfaceMethod::getThisVar(Compiler* compiler) {
    return nullptr;
}

string CInterfaceMethod::getCTypeName(Compiler* compiler, bool includeNames) {
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
    ss << ")(void*";
    if (includeNames) {
        ss << " _parent";
    }
    for (auto argVar : argVars) {
        ss << ",";
        if (includeNames) {
            ss << " ";
        }
        ss << argVar->getType(compiler)->getLocalType()->cname;
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

shared_ptr<CType> CInterfaceMethod::getVarType(CLoc loc, Compiler* compiler, shared_ptr<CTypeName> typeName, CTypeMode defaultMode) {
    if (!parent.expired()) {
        return parent.lock()->getVarType(loc, compiler, typeName, defaultMode);
    }
    
    return compiler->getType(typeName->valueName);
}

bool CInterfaceMethod::getIsReturnModeValid(Compiler* compiler, CTypeMode returnMode) {
    if (returnType->typeMode == CTM_Heap) {
        return returnMode == CTM_Heap;
    } else {
        return returnMode == CTM_Stack;
    }
}

shared_ptr<CType> CInterfaceMethod::getReturnType(Compiler* compiler, CTypeMode returnMode) {
    return returnType;
}

string CInterfaceMethod::getCFunctionName(CTypeMode returnMode) {
    assert(false);
    return "";
}

string CInterfaceMethod::getCCallbackFunctionName(Compiler* compiler, TrOutput* trOutput, CTypeMode returnMode) {
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

void CInterfaceMethod::transpileDefinition(Compiler* compiler, TrOutput* trOutput) {
}

void CInterfaceMethod::transpile(Compiler* compiler, shared_ptr<CScope> callerScope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> parentValue, CLoc& calleeLoc, shared_ptr<vector<FunctionParameter>> parameters, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue, CTypeMode /*returnMode*/) {
    assert(compiler->state == CompilerState::Compile);
    assert(parentValue != nullptr);

    auto returnType = getReturnType(compiler, returnMode);
    if (!returnType) {
        return;
    }

    // Call function
    stringstream line;
    line << parentValue->name << "->" << name;
    if (returnMode == CTM_Heap) {
        line << "_heap";
    }
    line << "(";
    line << TrValue::convertToLocalName(CTM_Heap, parentValue->name + "->_parent", false);

    // Fill in "this" with normal arguments
    auto argIndex = 0;
    for (auto defaultAssignment : argDefaultValues) {
        auto argVar = argVars[argIndex];
        auto argType = argVar->getType(compiler);
        auto isDefaultAssignment = (*parameters)[argIndex].isDefaultValue;
        
        stringstream argStream;
        auto parameterVar = (*parameters)[argIndex].var;
        if (!parameterVar) {
            assert(compiler->errors.size() > 0);
            return;
        }
        auto argStoreValue = trBlock->createTempStoreVariable(loc, callerScope, argType->typeMode == CTM_Heap ? argType : argType->getLocalValueType(), "interfaceParam");
        parameterVar->transpile(compiler, trOutput, trBlock, nullptr, isDefaultAssignment ? nullptr : thisValue, argStoreValue);
        
        if (!argStoreValue->hasSetValue) {
            compiler->addError(calleeLoc, CErrorCode::TypeMismatch, "parameter '%s' has no value", argVar->name.c_str());
            return;
        }
        
        line << ", ";
        line << argStoreValue->getName(trBlock);
        argIndex++;
    }
    
    if (returnType != compiler->typeVoid) {
        TrValue(storeValue->scope, storeValue->type, storeValue->getName(trBlock), storeValue->isReturnValue).addInitToStatements(trBlock);
        line << ", ";
        if (storeValue->isReturnValue) {
            line << "_return";
        }
        else {
            line << "&" << storeValue->getName(trBlock);
        }
    }
    line << ")";
    trBlock->statements.push_back(TrStatement(calleeLoc, line.str())); 
    storeValue->hasSetValue = true;
}

void CInterfaceMethod::dumpBody(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level, CTypeMode returnMode) {
}

bool CInterfaceMethod::getReturnMustRelease(Compiler* compiler) {
    return true;
}
