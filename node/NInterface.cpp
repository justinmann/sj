#include "Node.h"

NInterface::NInterface(CLoc loc, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<NodeList> methodList_) : NBaseFunction(NodeType_Interface, loc), name(name), templateTypeNames(templateTypeNames) {
    if (methodList_) {
        for (auto it : *methodList_) {
            assert(it->nodeType == NodeType_InterfaceMethod);
            methodList.push_back(static_pointer_cast<NInterfaceMethod>(it));
        }
    }
}

void NInterface::defineImpl(Compiler* compiler, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    auto parentFunction = static_pointer_cast<CFunctionDefinition>(thisFunction);
    auto def = parentFunction->getDefinedInterfaceDefinition(name);
    if (def != nullptr) {
        compiler->addError(loc, CErrorCode::InvalidType, "interface can only be defined once: '%s'", name.c_str());
        return;
    }
    def = parentFunction->createDefinedInterfaceDefinition(loc, name);
    def->typeName = make_shared<CTypeName>(CTC_Interface, CTM_Stack, name, templateTypeNames, false);
    def->ninterface = shared_from_this();

    for (auto it : methodList) {
        it->define(compiler, thisFunction);
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

CInterfaceVar::CInterfaceVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CInterface> interface) : CVar(loc, scope, "", false) {
//    parent = interface;
}

bool CInterfaceVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CInterfaceVar::getType(Compiler* compiler) {
    assert(false);
    return nullptr; // parent.lock()->getThisTypes(compiler);
}

void CInterfaceVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    assert(false);
}

void CInterfaceVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    assert(false);
}

CInterface::CInterface(CLoc loc, weak_ptr<CInterfaceDefinition> definition, weak_ptr<CFunction> parent) : CBaseFunction(CFT_Interface, definition.lock()->name, parent, definition), loc(loc) {
    setHasThis();
}

shared_ptr<CInterface> CInterface::init(Compiler* compiler, shared_ptr<NInterface> node, vector<shared_ptr<CType>>& templateTypes) {
    if (node->templateTypeNames) {
        assert(node->templateTypeNames->size() == templateTypes.size());
        auto index = 0;
        for (auto templateTypeName : *node->templateTypeNames) {
            if (templateTypeName->templateTypeNames != nullptr) {
                compiler->addError(node->loc, CErrorCode::InvalidType, "cannot use ! in template type name");
                return nullptr;
            }
            assert(templateTypes[index]);
            templateTypesByName[templateTypeName->name] = templateTypes[index];
            index++;
        }
    }
    
    auto argIndex = 0;
    for (auto it : node->methodList) {
        // need to create a stack and heap version if return typename is not explicit

        if (it->returnTypeName->typeMode == CTM_Stack || it->returnTypeName->typeMode == CTM_Undefined || it->returnTypeName->typeMode == CTM_Value) {
            auto method = make_shared<CInterfaceMethod>(it->name, shared_from_this(), argIndex, CTM_Stack);
            method = method->init(compiler, it, shared_from_this());
            if (!method) {
                return nullptr;
            }
            methods.push_back(method);
            methodByName[method->name][CTM_Stack] = method;
            argIndex++;
        }

        if (it->returnTypeName->typeMode == CTM_Heap || it->returnTypeName->typeMode == CTM_Undefined) {
            auto method = make_shared<CInterfaceMethod>(it->name, shared_from_this(), argIndex, CTM_Heap);
            method = method->init(compiler, it, shared_from_this());
            if (!method) {
                return nullptr;
            }
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
        thisTypes = CType::create(compiler, name.c_str(), shared_from_this());
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

int CInterface::getArgStart() {
    if (hasThis) {
        return 2;
    }
    return 1;
}

shared_ptr<CVar> CInterface::getCVar(Compiler* compiler, const string& name, CTypeMode returnMode) {
    assert(false);
    return nullptr;
}

shared_ptr<CBaseFunction> CInterface::getCFunction(Compiler* compiler, const string& name, shared_ptr<CScope> callerScope, shared_ptr<CTypeNameList> templateTypeNames, CTypeMode returnMode) {
    shared_ptr<CBaseFunction> interfaceMethod;
    if (templateTypeNames == nullptr) {
        auto t = methodByName.find(name);
        if (t != methodByName.end()) {
            if (returnMode == CTM_Undefined) {
                if (t->second[CTM_Stack]) {
                    return t->second[CTM_Stack];
                }
                return t->second[CTM_Heap];
            }
            else if (returnMode == CTM_Value) {
                return t->second[CTM_Stack];
            }
            return t->second[returnMode];
        }
    }
    return interfaceMethod;
}

shared_ptr<CType> CInterface::getVarType(CLoc loc, Compiler* compiler, shared_ptr<CTypeName> typeName, CTypeMode defaultMode) {
    if (typeName->templateTypeNames == nullptr) {
        auto t = templateTypesByName.find(typeName->name);
        if (t != templateTypesByName.end()) {
            return t->second;
        }
    }
    
    if (!parent.expired()) {
        return parent.lock()->getVarType(loc, compiler, typeName, defaultMode);
    }
    
    return compiler->getType(typeName->name);
}

shared_ptr<CType> CInterface::getReturnType(Compiler* compiler, CTypeMode returnMode) {
    assert(false);
    return nullptr;
}

string CInterface::getCInitFunctionName(CTypeMode returnMode) {
    assert(false);
    return "";
}

string CInterface::getCBaseName(CTypeMode typeMode) {
    auto functionName = name.substr(1, name.size() - 1);
    if (!parent.expired()) {
        auto tempType = parent.lock();
        while (tempType != nullptr && tempType->name.compare("global") != 0 && tempType->name.size() > 0) {
            functionName.insert(0, "_");
            assert(tempType->classType == CFT_Function);
            functionName.insert(0, static_pointer_cast<CFunction>(tempType)->getCFullName(true));
            tempType = tempType->parent.lock();
        }
    }
    return functionName;
}

string CInterface::getCStructName(CTypeMode typeMode) {
    return "sji_" + getCBaseName(typeMode);
}

string CInterface::getCCopyFunctionName() {
    return getCStructName(CTM_Stack) + "_copy";
}

string CInterface::getCDestroyFunctionName() {
    return getCStructName(CTM_Stack) + "_destroy";
}

string CInterface::getCTypeIdName() {
    return getCStructName(CTM_Stack) + "_typeId";
}

string CInterface::getCCastFunctionName(shared_ptr<CBaseFunction> fromFunction, CTypeMode returnMode) {
    stringstream line;
    line << fromFunction->getCInitFunctionName(returnMode) << "_as_" << getCStructName(CTM_Stack);
    return line.str();
}

void CInterface::transpileCast(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> fromValue, shared_ptr<TrStoreValue> toValue) {
    assert(fromValue->type->typeMode == CTM_Heap);
    if (fromValue->type->parent.lock()->classType == CFT_Interface) {
        auto fromInterface = static_pointer_cast<CInterface>(fromValue->type->parent.lock());
        stringstream line;
        line << "(" << getCStructName(CTM_Heap) << "*)" << fromValue->name << "->asInterface(" << fromValue->name << "->_parent, " << getCTypeIdName() << ")";
        toValue->takeOverValue(compiler, trBlock, make_shared<TrValue>(nullptr, toValue->type, line.str()));
    }
    else {
        stringstream line;
        line << "(" << getCStructName(CTM_Heap) << "*)" << getCCastFunctionName(fromValue->type->parent.lock(), fromValue->type->typeMode) << "(" << fromValue->name << ")";
        toValue->takeOverValue(compiler, trBlock, make_shared<TrValue>(nullptr, toValue->type, line.str()));
    }    
}

void CInterface::transpileDefinition(Compiler* compiler, TrOutput* trOutput) {
    // Create stack struct
    string heapStructName = getCStructName(CTM_Heap);
    if (trOutput->structs.find(heapStructName) == trOutput->structs.end()) {
        trOutput->structs[heapStructName].push_back("int _refCount");
        trOutput->structs[heapStructName].push_back("sjs_object* _parent");
        trOutput->structs[heapStructName].push_back("void (*destroy)(sjs_object* _this)");
        trOutput->structs[heapStructName].push_back("sjs_object* (*asInterface)(sjs_object* _this, int typeId)");
        for (auto method : methods) {
            trOutput->structs[heapStructName].push_back(method->getCTypeName(compiler, true));
        }
        trOutput->structOrder.push_back(heapStructName);
    }

    string destroyInterfaceName = "void " + getCDestroyFunctionName() + "(" + heapStructName + "* _this)";
    if (trOutput->functions.find(destroyInterfaceName) == trOutput->functions.end()) {
        auto destroyBlock = make_shared<TrBlock>();
        destroyBlock->definition = destroyInterfaceName;

        string name = "_this->_parent";

        stringstream lineStream;
        lineStream << name << "->_refCount--";
        destroyBlock->statements.push_back(lineStream.str());

#ifdef DEBUG_ALLOC
        stringstream logStream;
        logStream << "printf(\"RELEASE\\t" << destroyInterfaceName << "\\t%0x\\t" << destroyBlock->getFunctionName() << "\\t" << "%d\\n\", (uintptr_t)" << name << ", " << name << "->_refCount);";
        destroyBlock->statements.push_back(logStream.str());
#endif

        auto ifBlock = make_shared<TrBlock>();
        stringstream ifStream;
        ifStream << "if (" << name << "->_refCount <= 0)";
        destroyBlock->statements.push_back(TrStatement(ifStream.str(), ifBlock));

        stringstream destroyStream;
        destroyStream << "_this->destroy(" << name << ")";
        ifBlock->statements.push_back(destroyStream.str());

        stringstream freeStream;
        freeStream << "free(" << name << ")";
        ifBlock->statements.push_back(freeStream.str());

        trOutput->functions[destroyInterfaceName] = destroyBlock;
    }
}

void CInterface::transpile(Compiler* compiler, shared_ptr<CScope> scope, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> parentValue, CLoc& calleeLoc, vector<pair<bool, shared_ptr<NBase>>>& parameters, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue, CTypeMode returnMode) {
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

//Function* CInterface::getDestructor(Compiler* compiler) {
//    return nullptr;
//}
//
//shared_ptr<TrValue> CInterface::cast(Compiler* compiler, IRBuilder<>* builder, shared_ptr<TrValue> fromValue, bool isHeap, vector<Function*>& interfaceMethodValues) {
//    auto interfaceType = getStructType(compiler);
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
//        initHeap(compiler, builder, value);
//    } else {
//        value = builder->CreateAlloca(interfaceType);
//        initStack(compiler, builder, value);
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
//    fromValue->retainIfNeeded(compiler, builder);
//    
//    // store interfaceMethods
//    auto methodIndex = 0;
//    for (auto it : interfaceMethodValues) {
//        auto functionPtr = builder->CreateStructGEP(interfaceType, value, structIndex);
//        auto t = methods[methodIndex]->getFunctionType(compiler)->getPointerTo();
//        auto functionWithVoidForParent = builder->CreateBitCast(it, t);
//        builder->CreateStore(functionWithVoidForParent, functionPtr);
//        methodIndex++;
//        structIndex++;
//    }
//    
//    // create return value
//    return make_shared<TrValue>(shared_from_this(), RVR_MustRelease, RVT_HEAP, false, value);
//}

CInterfaceDefinition::CInterfaceDefinition(CLoc loc, string& name_) : CBaseFunctionDefinition(CFT_Interface), loc(loc) {
    name = name_;
}

string CInterfaceDefinition::fullName() {
    return typeName->getName();
}

void CInterfaceDefinition::addChildFunction(string& name, shared_ptr<CBaseFunctionDefinition> childFunction) {
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
        interface = interface->init(compiler, ninterface, templateTypes);
        cinterfaces[templateTypes] = interface;
    }
    return interface;
}
