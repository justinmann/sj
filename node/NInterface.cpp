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
    
    auto fun = static_pointer_cast<CFunctionDefinition>(thisFunction);
    fun->interfacesByName[name] = def;
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

CInterface::CInterface(weak_ptr<CInterfaceDefinition> definition, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CFunction> parent) : _structType(nullptr), CBaseFunction(definition.lock()->name, parent, definition) {
}

shared_ptr<CInterface> CInterface::init(Compiler* compiler, CResult& result, shared_ptr<NInterface> node) {
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
    assert(false);
}

Type* CInterface::getStructType(Compiler* compiler, CResult& result) {
    if (!_structType) {
        _structType = StructType::create(compiler->context, name + "_interface");
        
        auto typeList = vector<Type*>();
        typeList.push_back(Type::getInt8PtrTy(compiler->context));
        
        for (auto it : methods) {
            typeList.push_back(it->getFunction()->getType());
        }
        
        _structType->setBody(ArrayRef<Type *>(typeList));
    }
    return _structType;
}

Value* CInterface::getRefCount(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
    assert(false);
    return nullptr;
}

shared_ptr<CVar> CInterface::getCVar(Compiler* compiler, CResult& result, const string& name) {
    assert(false);
    return nullptr;
}

shared_ptr<CBaseFunction> CInterface::getCFunction(Compiler* compiler, CResult& result, const string& name, shared_ptr<CBaseFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames) {
    assert(false);
    return nullptr;
}

Value* CInterface::getParentValue(Compiler* compiler, CResult& result, IRBuilder<>* builder, bool thisInEntry, Value* thisValue) {
    assert(false);
    return nullptr;
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

shared_ptr<CType> CInterface::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    assert(false);
    return nullptr;
}

shared_ptr<CVar> CInterface::getReturnVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    assert(false);
    return nullptr;
}

shared_ptr<ReturnValue> CInterface::call(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, shared_ptr<CVar> calleeVar, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters) {
    assert(false);
}

void CInterface::dumpBody(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    assert(false);
}

bool CInterface::getReturnMustRelease(Compiler* compiler, CResult& result) {
    assert(false);
    return false;
}

Function* CInterface::getDestructor(Compiler* compiler, CResult& result) {
    return nullptr;
}

shared_ptr<ReturnValue> CInterface::cast(Compiler* compiler, CResult& result, IRBuilder<>* builder, shared_ptr<ReturnValue> fromValue, bool isHeap, vector<Function*>& interfaceMethodValues) {
    auto interfaceType = getStructType(compiler, result);
    Value* value;
    // alloc instance of struct type
    if (isHeap) {
        // heap alloc this
        auto allocFunc = compiler->getAllocFunction();
        
        // Compute the size of the struct by getting a pointer to the second element from null
        vector<Value*> v;
        v.push_back(ConstantInt::get(compiler->context, APInt(32, 1)));
        auto thisPointerType = interfaceType->getPointerTo();
        auto nullPtr = ConstantPointerNull::get(thisPointerType);
        auto sizePtr = builder->CreateGEP(nullPtr, ArrayRef<llvm::Value *>(v));
        auto sizeValue = builder->CreatePtrToInt(sizePtr, Type::getInt64Ty(compiler->context));
        
        // Allocate and mutate to correct type
        vector<Value*> allocArgs;
        allocArgs.push_back(sizeValue);
        auto valueAsVoidPtr = builder->CreateCall(allocFunc, allocArgs);
        value = builder->CreateBitCast(valueAsVoidPtr, thisPointerType);
        initHeap(compiler, result, builder, value);
    } else {
        value = builder->CreateAlloca(interfaceType);
        initStack(compiler, result, builder, value);
    }

    // store "this"
    auto index = 0;
    auto thisPtr = builder->CreateStructGEP(interfaceType, value, index);
    auto fromVoidPtr = builder->CreateBitCast(fromValue->value, Type::getInt8PtrTy(compiler->context));
    builder->CreateStore(fromVoidPtr, thisPtr);
    index++;

    // retain "this"
    fromValue->retainIfNeeded(compiler, result, builder);
    
    // store interfaceMethods
    for (auto it : interfaceMethodValues) {
        auto functionPtr = builder->CreateStructGEP(interfaceType, value, index);
        builder->CreateStore(it, functionPtr);
        index++;
    }
    
    // create return value
    return make_shared<ReturnValue>(shared_from_this(), true, RVT_HEAP, false, value);
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
