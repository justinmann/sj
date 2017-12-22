#include "Node.h"

NInterface::NInterface(CLoc loc, const string& name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<vector<string>> attributes, shared_ptr<NodeList> methodList_) : NBaseFunction(NodeType_Interface, loc), name(name), templateTypeNames(templateTypeNames) {
    boost::algorithm::to_lower(this->name);

    if (methodList_) {
        for (auto it : *methodList_) {
            assert(it->nodeType == NodeType_InterfaceMethod);
            methodList.push_back(static_pointer_cast<NInterfaceMethod>(it));
        }
    }
}

void NInterface::defineImpl(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    auto parentFunction = static_pointer_cast<CFunctionDefinition>(thisFunction);
    auto def = parentFunction->getDefinedInterfaceDefinition(packageNamespace, name);
    if (def != nullptr) {
        compiler->addError(loc, CErrorCode::InvalidType, "interface can only be defined once: '%s'", name.c_str());
        return;
    }
    def = parentFunction->createDefinedInterfaceDefinition(compiler, loc, importNamespaces, packageNamespace, name);
    def->typeName = make_shared<CTypeName>(CTC_Interface, CTM_Stack, packageNamespace, name, templateTypeNames, false);
    def->ninterface = shared_from_this();

    for (auto it : methodList) {
        it->define(compiler, importNamespaces, packageNamespace, thisFunction);
    }
}

//void NInterface::dump(Compiler* compiler, shared_ptr<CScope> scope, CTypeMode returnMode, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
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
//    ss << "(\n";
//    for (auto it : methodList) {
//        dumpf(ss, level + 1);
//        it->dump(compiler, scope, CTM_Undefined, functions, ss, level + 1);
//        ss << "\n";
//    }
//    dumpf(ss, level);
//    ss << ")";
//}

shared_ptr<NInterface> NInterface::shared_from_this() {
    return static_pointer_cast<NInterface>(NBase::shared_from_this());
}

CInterfaceVar::CInterfaceVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CInterface> interface) : CVar(loc, scope) {
//    parent = interface;
}

bool CInterfaceVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CInterfaceVar::getType(Compiler* compiler) {
    assert(false);
    return nullptr; // parent.lock()->getThisTypes(compiler);
}

void CInterfaceVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    assert(false);
}

void CInterfaceVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    assert(false);
}

CInterface::CInterface(CLoc loc, weak_ptr<CInterfaceDefinition> definition, weak_ptr<CFunction> parent) : CBaseFunction(CFT_Interface, definition.lock()->name, definition.lock()->safeName, parent, definition, false), loc(loc) {
    setHasThis();
}

shared_ptr<CInterface> CInterface::init(Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, shared_ptr<NInterface> node, vector<shared_ptr<CType>>& templateTypes) {
    this->templateTypes = templateTypes;

    if (node->templateTypeNames) {
        assert(node->templateTypeNames->size() == templateTypes.size());
        auto index = 0;
        for (auto templateTypeName : *node->templateTypeNames) {
            if (templateTypeName->templateTypeNames != nullptr) {
                compiler->addError(node->loc, CErrorCode::InvalidType, "cannot use ! in template type name");
                return nullptr;
            }
            assert(templateTypes[index]);
            templateTypesByName[templateTypeName->valueName] = templateTypes[index];
            index++;
        }
    }
    
    auto argIndex = 0;
    for (auto it : node->methodList) {
        // need to create a stack and heap version if return typename is not explicit
        if (it->name[0] == '_') {
            compiler->addError(it->loc, CErrorCode::InvalidType, "interface methods cannot be private");
            return nullptr;
        }

        auto method = make_shared<CInterfaceMethod>(it->name, shared_from_this(), argIndex, CTM_Stack);
        method = method->init(compiler, importNamespaces, it, shared_from_this());
        if (!method) {
            return nullptr;
        }
        auto returnType = method->getReturnType(compiler, CTM_Stack);
        assert(returnType->typeMode != CTM_Undefined);
        if (returnType->typeMode == CTM_Stack || returnType->typeMode == CTM_Value || returnType->typeMode == CTM_Local) {
            methods.push_back(method);
            methodByName[method->name][CTM_Stack] = method;
            argIndex++;
        }

        method = make_shared<CInterfaceMethod>(it->name, shared_from_this(), argIndex, CTM_Heap);
        method = method->init(compiler, importNamespaces, it, shared_from_this());
        if (!method) {
            return nullptr;
        }
        returnType = method->getReturnType(compiler, CTM_Heap);
        assert(returnType->typeMode != CTM_Undefined);
        if (returnType->typeMode == CTM_Heap) {
            methods.push_back(method);
            methodByName[method->name][CTM_Heap] = method;
            argIndex++;
        }
    }
    
    return shared_from_this();
}

string CInterface::fullName(bool includeTemplateTypes) {
    assert(false);
    return "";
}

shared_ptr<CTypes> CInterface::getThisTypes(Compiler* compiler) {
    if (!thisTypes) {
        thisTypes = CType::create(compiler, static_pointer_cast<CInterfaceDefinition>(definition.lock())->packageNamespace, name, safeName, shared_from_this());
    }
    return thisTypes;
}

shared_ptr<CScope> CInterface::getScope() {
    if (_scope == nullptr) {
        _scope = make_shared<CScope>(shared_from_this());
    }
    return _scope;
}

int CInterface::getArgIndex(const string& name, CTypeMode returnMode) {
    assert(false);
    return -1;
}

shared_ptr<CVar> CInterface::getArgVar(int index, CTypeMode returnMode) {
    return argVars[index];
}

int CInterface::getArgCount(CTypeMode returnMode) {
    return (int)argVars.size();
}

shared_ptr<CVar> CInterface::getThisVar(Compiler* compiler) {
    return make_shared<CInterfaceVar>(loc, nullptr, shared_from_this());
}

shared_ptr<CBaseFunction> CInterface::getCFunction(Compiler* compiler, CLoc locCaller, const string& name, shared_ptr<CScope> callerScope, shared_ptr<CTypeNameList> templateTypeNames, CTypeMode returnMode) {
    shared_ptr<CBaseFunction> interfaceMethod;
    if (templateTypeNames == nullptr) {
        auto t = methodByName.find(name);
        if (t != methodByName.end()) {
            if (returnMode == CTM_Undefined || returnMode == CTM_Stack || returnMode == CTM_Value) {
                if (t->second[CTM_Stack]) {
                    return t->second[CTM_Stack];
                }
                return t->second[CTM_Heap];
            }
            else {
                if (t->second[CTM_Heap]) {
                    return t->second[CTM_Heap];
                }
                return t->second[CTM_Stack];
            }
        }
    }
    return interfaceMethod;
}

shared_ptr<CType> CInterface::getVarType(CLoc loc, Compiler* compiler, vector<pair<string, vector<string>>>& importNamespaces, shared_ptr<CTypeName> typeName, CTypeMode defaultMode) {
    if (typeName->templateTypeNames == nullptr) {
        auto t = templateTypesByName.find(typeName->valueName);
        if (t != templateTypesByName.end()) {
            return t->second;
        }
    }
    
    if (!parent.expired()) {
        return parent.lock()->getVarType(loc, compiler, importNamespaces, typeName, defaultMode);
    }
    
    return compiler->getType(typeName->valueName, typeName->isOption);
}

bool CInterface::getIsReturnModeValid(Compiler* compiler, CTypeMode returnMode) {
    return returnMode == CTM_Heap;
}

shared_ptr<CType> CInterface::getReturnType(Compiler* compiler, CTypeMode returnMode) {
    assert(false);
    return nullptr;
}

string CInterface::getCFunctionName(Compiler* compiler, TrOutput* trOutput, CTypeMode returnMode) {
    assert(false);
    return "";
}

string CInterface::getCCallbackFunctionName(Compiler* compiler, TrOutput* trOutput, CTypeMode returnMode) {
    assert(false);
    return "";
}

string CInterface::getCBaseName(CTypeMode typeMode) {
    stringstream ss;
    for (auto ns : static_pointer_cast<CInterfaceDefinition>(definition.lock())->packageNamespace) {
        ss << ns << "_";
    }

    ss << definition.lock()->name;
    if (templateTypes.size() > 0) {
        ss << "_";
    }

    for (auto it : templateTypes) {
        if (it != templateTypes.front()) {
            ss << "_";
        }

        ss << it->safeName;
    }

    return ss.str();
}

string CInterface::getCStructName(CTypeMode typeMode) {
    return "sji_" + getCBaseName(CTM_Undefined);
}

string CInterface::getCVtblName() {
    return "sji_" + getCBaseName(CTM_Undefined) + "_vtbl";
}

string CInterface::getCCopyFunctionName() {
    assert(false);
    return "INVALID";
}

string CInterface::getCDestroyFunctionName() {
    assert(false);
    return "INVALID";
}

string CInterface::getCTypeIdName() {
    return getCStructName(CTM_Stack) + "_typeId";
}

string CInterface::getCCastFunctionName(Compiler* compiler, TrOutput* trOutput, shared_ptr<CBaseFunction> fromFunction, CTypeMode returnMode) {
    stringstream line;
    line << fromFunction->getCFunctionName(compiler, trOutput, returnMode) << "_as_" << getCStructName(CTM_Stack);
    return line.str();
}

void CInterface::transpileCast(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> fromValue, shared_ptr<TrStoreValue> toValue) {
    if (fromValue->type->parent.lock()->classType == CFT_Interface) {
        auto fromInterface = static_pointer_cast<CInterface>(fromValue->type->parent.lock());
        stringstream line;
        line << fromValue->name << "._vtbl->asinterface(" << fromValue->name << "._parent, " << getCTypeIdName() << ", (sjs_interface*)&" << toValue->getName(trBlock) << ")";
        trBlock->statements.push_back(TrStatement(loc, line.str()));
        toValue->getValue()->addRetainToStatements(trBlock);
        toValue->hasSetValue = true;
    }
    else {
        stringstream line;
        line << getCCastFunctionName(compiler, trOutput, fromValue->type->parent.lock(), CTM_Stack) << "(" << TrValue::convertToLocalName(fromValue->type, fromValue->name, false) << ", &" << toValue->getName(trBlock) << ")";
        trBlock->statements.push_back(TrStatement(loc, line.str()));
        toValue->getValue()->addRetainToStatements(trBlock);
        toValue->hasSetValue = true;
    }
}

void CInterface::transpileStructDefinition(Compiler* compiler, TrOutput* trOutput) {
    // Create stack struct
    string vtblStructName = getCVtblName();
    if (trOutput->structs.find(vtblStructName) == trOutput->structs.end()) {
        trOutput->structs[vtblStructName].push_back("void (*destroy)(void* _this)");
        trOutput->structs[vtblStructName].push_back("void (*asinterface)(sjs_object* _this, int typeId, sjs_interface* _return)");
        for (auto method : methods) {
            for (auto argVar : method->argVars) {
                auto argType = argVar->getType(compiler);
                if (!argType->parent.expired()) {
                    argType->parent.lock()->transpileDefinition(compiler, trOutput);
                }
            }

            auto returnType = method->getReturnType(compiler, method->returnMode);
            if (!returnType->parent.expired()) {
                returnType->parent.lock()->transpileDefinition(compiler, trOutput);
            }

            trOutput->structs[vtblStructName].push_back(method->getCTypeName(compiler, true));
        }
        trOutput->structOrder.push_back(vtblStructName);
    }

    string structName = getCStructName(CTM_Heap);
    if (trOutput->structs.find(structName) == trOutput->structs.end()) {
        trOutput->structs[structName].push_back("sjs_object* _parent");
        trOutput->structs[structName].push_back(vtblStructName + "* _vtbl");
        trOutput->structOrder.push_back(structName);
    }
}

void CInterface::transpileDefinition(Compiler* compiler, TrOutput* trOutput) {
    transpileStructDefinition(compiler, trOutput);
}

void CInterface::transpile(Compiler* compiler, shared_ptr<CScope> scope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<CVar> parentVar, CLoc& calleeLoc, shared_ptr<vector<FunctionParameter>> parameters, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue, CTypeMode returnMode) {
    assert(false);
    return;
}

void CInterface::dumpBody(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level, CTypeMode returnMode) {
    assert(false);
}

bool CInterface::getReturnMustRelease(Compiler* compiler) {
    assert(false);
    return false;
}

CInterfaceDefinition::CInterfaceDefinition(CLoc loc, vector<pair<string, vector<string>>>& importNamespaces, vector<string>& packageNamespace, string& name_) : CBaseFunctionDefinition(CFT_Interface), loc(loc), importNamespaces(importNamespaces), packageNamespace(packageNamespace) {
    name = name_;
    safeName = "iface_" + name_;
}

string CInterfaceDefinition::fullName() {
    return typeName->getFullName();
}

void CInterfaceDefinition::addChildFunction(Compiler* compiler, CLoc loc, vector<string> packageNamespace, string& name, shared_ptr<CBaseFunctionDefinition> childFunction) {
    assert(false);
}

shared_ptr<CInterface> CInterfaceDefinition::getInterface(Compiler* compiler, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CFunction> funcParent) {
    shared_ptr<CInterface> interface;
    auto it = cinterfaces.find(templateTypes);
    if (it != cinterfaces.end()) {
        interface = it->second;
    } else {
        if (!ninterface) {
            return nullptr;
        }
        
        if (typeName->templateTypeNames) {
            assert(templateTypes.size() == typeName->templateTypeNames->size());
        } else {
            assert(templateTypes.size() == 0);
        }
        
        interface = make_shared<CInterface>(loc, shared_from_this(), funcParent);
        cinterfaces[templateTypes] = interface;
        interface = interface->init(compiler, importNamespaces, ninterface, templateTypes);
    }
    return interface;
}
