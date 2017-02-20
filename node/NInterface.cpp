#include "Node.h"

NInterface::NInterface(CLoc loc, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<NodeList> methodList_) : NBaseFunction(NodeType_Interface, loc), name(name), templateTypeNames(templateTypeNames) {
    if (methodList_) {
        for (auto it : *methodList_) {
            assert(it->nodeType == NodeType_InterfaceMethod);
            methodList.push_back(static_pointer_cast<NInterfaceMethod>(it));
        }
    }
}

shared_ptr<CType> NInterface::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeVoid;
}

shared_ptr<ReturnValue> NInterface::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(builder, this);
    return nullptr;
}

void NInterface::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    auto def = compiler->getInterfaceDefinition(name);
    if (def->ninterface) {
        result.addError(loc, CErrorCode::InvalidType, "interface can only be defined once: '%s'", name.c_str());
        return;
    }
    def->ninterface = shared_from_this();

    for (auto it : methodList) {
        it->define(compiler, result, thisFunction);
    }
}

void NInterface::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "#" << name;
    if (templateTypeNames) {
        if (templateTypeNames->size() == 1) {
            ss << "!" << (*templateTypeNames)[0]->getName();
        } else {
            ss << "![";
            for (auto it : *templateTypeNames) {
                ss << it->getName();
            }
            ss << "]";
        }
    }
    ss << "(\n";
    for (auto it : methodList) {
        dumpf(ss, level + 1);
        it->dump(compiler, result, thisFunction, thisVar, functions, ss, level + 1);
        ss << "\n";
    }
    dumpf(ss, level);
    ss << ")";
}

shared_ptr<NInterface> NInterface::shared_from_this() {
    return static_pointer_cast<NInterface>(NBase::shared_from_this());
}

CInterface::CInterface(weak_ptr<CInterfaceDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CFunction> parent) {
}

shared_ptr<CInterface> CInterface::init(Compiler* compiler, CResult& result, shared_ptr<NInterface> node) {
    return shared_from_this();
}

shared_ptr<CType> CInterface::getVarType(Compiler* compiler, CResult& result, shared_ptr<CTypeName> typeName) {
    if (typeName->templateTypeNames == nullptr) {
        auto t = templateTypesByName.find(typeName->name);
        if (t != templateTypesByName.end()) {
            return t->second;
        }
    }
    
    return compiler->getType(typeName->name);
}

CInterfaceDefinition::CInterfaceDefinition(string& name_) {
    name = name_;
}

string CInterfaceDefinition::fullName() {
    return name;
}

void CInterfaceDefinition::addChildFunction(string& name, shared_ptr<CBaseFunctionDefinition> childFunction) {
    methods.push_back(childFunction);
}

shared_ptr<CInterface> CInterfaceDefinition::getInterface(Compiler* compiler, CResult& result, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CFunction> funcParent) {
    shared_ptr<CInterface> interface;
    auto it = cinterfaces.find(templateTypes);
    if (it != cinterfaces.end()) {
        interface = it->second;
    } else {
        if (!ninterface) {
            return nullptr;
        }
        
        interface = make_shared<CInterface>(shared_from_this(), templateTypes, funcParent);
        interface = interface->init(compiler, result, ninterface);
        cinterfaces[templateTypes] = interface;
    }
    return interface;
}
