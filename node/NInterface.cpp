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

//shared_ptr<ReturnValue> NInterface::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    assert(compiler->state == CompilerState::Compile);
//    compiler->emitLocation(builder, &this->loc);
//    return nullptr;
//}

void NInterface::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    auto def = compiler->getInterfaceDefinition(name);
    if (def->ninterface) {
        result.addError(loc, CErrorCode::InvalidType, "interface can only be defined once: '%s'", name.c_str());
        return;
    }
    def->typeName = make_shared<CTypeName>(CTC_Interface, name, templateTypeNames);
    def->ninterface = shared_from_this();

    for (auto it : methodList) {
        it->define(compiler, result, thisFunction);
    }
    
    auto fun = static_pointer_cast<CFunctionDefinition>(thisFunction);
    fun->interfacesByName[name] = def;
}

shared_ptr<CType> NInterface::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, stringstream& trLine) {
	assert(false);
	return nullptr;
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

CInterfaceVar::CInterfaceVar(shared_ptr<CInterface> interface) : isHeapVar(false) {
    parent = interface;
}

shared_ptr<CType> CInterfaceVar::getType(Compiler* compiler, CResult& result) {
    return parent.lock()->getThisType(compiler, result);
}

//shared_ptr<ReturnValue> CInterfaceVar::getLoadValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    assert(false);
//    return nullptr;
//}
//
//Value* CInterfaceVar::getStoreValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
//    assert(false);
//    return nullptr;
//}

bool CInterfaceVar::getHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    return isHeapVar;
}

int CInterfaceVar::setHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    if (!isHeapVar) {
        isHeapVar = true;
        
        auto t = getType(compiler, result);
        if (!t->parent.expired()) {
            t->parent.lock()->setHasRefCount();
        }
        
        return 1;
    }
    return 0;
}

shared_ptr<CType> CInterfaceVar::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, stringstream& trLine, shared_ptr<CVar> dotVar) {
    assert(false);
	return nullptr;
}

void CInterfaceVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    assert(false);
}

CInterface::CInterface(weak_ptr<CInterfaceDefinition> definition, weak_ptr<CFunction> parent) : /*_structType(nullptr),*/ CBaseFunction(definition.lock()->name, parent, definition) {
}

shared_ptr<CInterface> CInterface::init(Compiler* compiler, CResult& result, shared_ptr<NInterface> node, vector<shared_ptr<CType>>& templateTypes) {
    if (node->templateTypeNames) {
        assert(node->templateTypeNames->size() == templateTypes.size());
        auto index = 0;
        for (auto templateTypeName : *node->templateTypeNames) {
            if (templateTypeName->templateTypeNames != nullptr) {
                result.addError(node->loc, CErrorCode::InvalidType, "cannot use ! in template type name");
                return nullptr;
            }
            assert(templateTypes[index]);
            templateTypesByName[templateTypeName->name] = templateTypes[index];
            index++;
        }
    }
    
    auto argIndex = 0;
    for (auto it : node->methodList) {
        auto method = make_shared<CInterfaceMethod>(it->name, shared_from_this(), argIndex);
        method = method->init(compiler, result, it);
        if (!method) {
            return nullptr;
        }
        methods.push_back(method);
        methodByName[method->name] = method;
        argIndex++;
    }
    
    return shared_from_this();
}

string CInterface::fullName(bool includeTemplateTypes) {
    assert(false);
    return "";
}

bool CInterface::getHasThis() {
    assert(false);
    return false;
}

shared_ptr<CType> CInterface::getThisType(Compiler* compiler, CResult& result) {
    if (!thisType) {
        thisType = make_shared<CType>(name.c_str(), shared_from_this());
    }
    return thisType;
}

int CInterface::getThisIndex(const string& name) const {
    assert(false);
    return -1;
}

void CInterface::createThisVar(Compiler* compiler, CResult& result, shared_ptr<CVar>& thisVar) {
    thisVar = make_shared<CInterfaceVar>(shared_from_this());
}

//Type* CInterface::getStructType(Compiler* compiler, CResult& result) {
//    if (!_structType) {
//        _structType = StructType::create(compiler->context, name + "_interface");
//        
//        auto typeList = vector<Type*>();
//        typeList.push_back(Type::getInt8PtrTy(compiler->context));
//        
//        if (hasRefCount) {
//            typeList.push_back(Type::getInt64Ty(compiler->context));
//        }
//        
//        for (auto it : methods) {
//            typeList.push_back(it->getFunctionType(compiler, result)->getPointerTo());
//        }
//        
//        _structType->setBody(ArrayRef<Type *>(typeList));
//    }
//    return _structType;
//}
//
//Value* CInterface::getRefCount(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
//    return builder->CreateStructGEP(_structType, thisValue, 1);
//}

int CInterface::getArgStart() {
    if (hasRefCount) {
        return 2;
    }
    return 1;
}

shared_ptr<CVar> CInterface::getCVar(Compiler* compiler, CResult& result, const string& name) {
    assert(false);
    return nullptr;
}

shared_ptr<CBaseFunction> CInterface::getCFunction(Compiler* compiler, CResult& result, const string& name, shared_ptr<CBaseFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames) {
    if (templateTypeNames == nullptr) {
        auto it = methodByName.find(name);
        if (it != methodByName.end()) {
            return it->second;
        }        
    }
    return nullptr;
}

//Value* CInterface::getParentValue(Compiler* compiler, CResult& result, IRBuilder<>* builder, bool thisInEntry, Value* thisValue) {
//    assert(false);
//    return nullptr;
//}

shared_ptr<CType> CInterface::getVarType(Compiler* compiler, CResult& result, shared_ptr<CTypeName> typeName) {
    if (typeName->templateTypeNames == nullptr) {
        auto t = templateTypesByName.find(typeName->name);
        if (t != templateTypesByName.end()) {
            return t->second;
        }
    }
    
    if (!parent.expired()) {
        return parent.lock()->getVarType(compiler, result, typeName);
    }
    
    return compiler->getType(typeName->name);
}

shared_ptr<CType> CInterface::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    assert(false);
    return nullptr;
}

shared_ptr<CVar> CInterface::getReturnVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    assert(false);
    return nullptr;
}

string CInterface::getCInitFunctionName() {
    assert(false);
    return "";
}

string CInterface::getCDestroyFunctionName() {
    assert(false);
    return "";
}

shared_ptr<CType> CInterface::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, stringstream& trLine, shared_ptr<CVar> calleeVar, vector<shared_ptr<NBase>>& parameters) {
    assert(false);
    return nullptr;
}

//shared_ptr<ReturnValue> CInterface::call(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, shared_ptr<CVar> calleeVar, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters, ReturnRefType returnRefType) {
//    assert(false);
//}

void CInterface::dumpBody(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    assert(false);
}

bool CInterface::getReturnMustRelease(Compiler* compiler, CResult& result) {
    assert(false);
    return false;
}

//Function* CInterface::getDestructor(Compiler* compiler, CResult& result) {
//    return nullptr;
//}
//
//shared_ptr<ReturnValue> CInterface::cast(Compiler* compiler, CResult& result, IRBuilder<>* builder, shared_ptr<ReturnValue> fromValue, bool isHeap, vector<Function*>& interfaceMethodValues) {
//    auto interfaceType = getStructType(compiler, result);
//    Value* value;
//    // alloc instance of struct type
//    if (isHeap) {
//        // heap alloc this
//        auto allocFunc = compiler->getAllocFunction();
//        
//        // Compute the size of the struct by getting a pointer to the second element from null
//        vector<Value*> v;
//        v.push_back(ConstantInt::get(compiler->context, APInt(32, 1)));
//        auto thisPointerType = interfaceType->getPointerTo();
//        auto nullPtr = ConstantPointerNull::get(thisPointerType);
//        auto sizePtr = builder->CreateGEP(nullPtr, ArrayRef<llvm::Value *>(v));
//        auto sizeValue = builder->CreatePtrToInt(sizePtr, Type::getInt64Ty(compiler->context));
//        
//        // Allocate and mutate to correct type
//        vector<Value*> allocArgs;
//        allocArgs.push_back(sizeValue);
//        auto valueAsVoidPtr = builder->CreateCall(allocFunc, allocArgs);
//        value = builder->CreateBitCast(valueAsVoidPtr, thisPointerType);
//        initHeap(compiler, result, builder, value);
//    } else {
//        value = builder->CreateAlloca(interfaceType);
//        initStack(compiler, result, builder, value);
//    }
//
//    // store "this"
//    auto structIndex = 0;
//    auto thisPtr = builder->CreateStructGEP(interfaceType, value, structIndex);
//    auto fromVoidPtr = builder->CreateBitCast(fromValue->value, Type::getInt8PtrTy(compiler->context));
//    builder->CreateStore(fromVoidPtr, thisPtr);
//    structIndex++;
//    
//    if (hasRefCount) {
//        structIndex++;
//    }
//
//    // retain "this"
//    fromValue->retainIfNeeded(compiler, result, builder);
//    
//    // store interfaceMethods
//    auto methodIndex = 0;
//    for (auto it : interfaceMethodValues) {
//        auto functionPtr = builder->CreateStructGEP(interfaceType, value, structIndex);
//        auto t = methods[methodIndex]->getFunctionType(compiler, result)->getPointerTo();
//        auto functionWithVoidForParent = builder->CreateBitCast(it, t);
//        builder->CreateStore(functionWithVoidForParent, functionPtr);
//        methodIndex++;
//        structIndex++;
//    }
//    
//    // create return value
//    return make_shared<ReturnValue>(shared_from_this(), RVR_MustRelease, RVT_HEAP, false, value);
//}

CInterfaceDefinition::CInterfaceDefinition(string& name) {
}

string CInterfaceDefinition::fullName() {
    return typeName->getName();
}

void CInterfaceDefinition::addChildFunction(string& name, shared_ptr<CBaseFunctionDefinition> childFunction) {
    assert(false);
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
        
        if (typeName->templateTypeNames) {
            assert(templateTypes.size() == typeName->templateTypeNames->size());
        } else {
            assert(templateTypes.size() == 0);
        }
        
        interface = make_shared<CInterface>(shared_from_this(), funcParent);
        interface = interface->init(compiler, result, ninterface, templateTypes);
        cinterfaces[templateTypes] = interface;
    }
    return interface;
}
