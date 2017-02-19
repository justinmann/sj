#include "Node.h"

NInterfaceMethod::NInterfaceMethod(CLoc loc, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<NodeList> arguments_, shared_ptr<CTypeName> returnTypeName) : NFunction(NodeType_InterfaceMethod, loc), name(name), templateTypeNames(templateTypeNames), returnTypeName(returnTypeName) {
    if (arguments_) {
        for (auto it : *arguments_) {
            assert(it->nodeType == NodeType_Assignment);
            assignments.push_back(static_pointer_cast<NAssignment>(it));
        }
    }
}

shared_ptr<CType> NInterfaceMethod::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeVoid;
}

shared_ptr<ReturnValue> NInterfaceMethod::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(builder, this);
    return nullptr;
}

shared_ptr<CType> NInterfaceMethod::getBlockType(Compiler* compiler, CResult& result, shared_ptr<CInterfaceMethod> method) {
    assert(compiler->state >= CompilerState::FixVar);
    /* TODO:
    shared_ptr<CType> valueType = method->getVarType(compiler, result, loc, returnTypeName);
    if (!valueType) {
        result.addError(loc, CErrorCode::InvalidType, "explicit type '%s' does not exist", returnTypeName->name.c_str());
        return nullptr;
    }
    return valueType; */
    return nullptr;
}

void NInterfaceMethod::dump(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CFunction>, string>& functions, stringstream& ss, int level) {
    ss << name;
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

    ss << "(";
    
    for (auto it : assignments) {
        if (it != assignments.front()) {
            ss << ", ";
        }
        it->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
    }
    
    ss << ")'" << returnTypeName->getName();
}
