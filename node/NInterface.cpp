#include "Node.h"

NInterface::NInterface(CLoc loc, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<NodeList> methodList_) : NBaseFunction(NodeType_Interface, loc), name(name), templateTypeNames(templateTypeNames) {
    if (methodList_) {
        for (auto it : *methodList_) {
            assert(it->nodeType == NodeType_InterfaceMethod);
            methodList.push_back(static_pointer_cast<NInterfaceMethod>(it));
        }
    }
}

void NInterface::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    auto parentFunction = static_pointer_cast<CFunctionDefinition>(thisFunction);
    auto def = parentFunction->getDefinedInterfaceDefinition(name);
    if (def != nullptr) {
        result.addError(loc, CErrorCode::InvalidType, "interface can only be defined once: '%s'", name.c_str());
        return;
    }
    def = parentFunction->createDefinedInterfaceDefinition(loc, name);
    def->typeName = make_shared<CTypeName>(CTC_Interface, CTM_Stack, name, templateTypeNames, false);
    def->ninterface = shared_from_this();

    for (auto it : methodList) {
        it->define(compiler, result, thisFunction);
    }
}

//void NInterface::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
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
//        it->dump(compiler, result, thisFunction, thisVar, CTM_Undefined, functions, ss, level + 1);
//        ss << "\n";
//    }
//    dumpf(ss, level);
//    ss << ")";
//}

shared_ptr<NInterface> NInterface::shared_from_this() {
    return static_pointer_cast<NInterface>(NBase::shared_from_this());
}

CInterfaceVar::CInterfaceVar(CLoc loc, shared_ptr<CBaseFunction> scope, shared_ptr<CInterface> interface) : CVar(loc, scope, "", false) {
//    parent = interface;
}

bool CInterfaceVar::getReturnThis() {
    return false;
}

shared_ptr<CType> CInterfaceVar::getType(Compiler* compiler, CResult& result) {
    assert(false);
    return nullptr; // parent.lock()->getThisTypes(compiler, result);
}

void CInterfaceVar::transpile(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    assert(false);
}

void CInterfaceVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    assert(false);
}

CInterface::CInterface(CLoc loc, weak_ptr<CInterfaceDefinition> definition, weak_ptr<CFunction> parent, CTypeMode returnMode) : CBaseFunction(CFT_Interface, definition.lock()->name, parent, definition), loc(loc), _returnMode(returnMode) {
    setHasThis();
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
        // TODO: need to create a stack and heap version if return typename is not explicit
        auto method = make_shared<CInterfaceMethod>(it->name, shared_from_this(), argIndex, CTM_Stack);
        method = method->init(compiler, result, it, shared_from_this());
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

shared_ptr<CTypes> CInterface::getThisTypes(Compiler* compiler, CResult& result) {
    if (!thisTypes) {
        thisTypes = CType::create(name.c_str(), shared_from_this());
    }
    return thisTypes;
}

int CInterface::getThisIndex(const string& name) const {
    assert(false);
    return -1;
}

shared_ptr<CVar> CInterface::getThisVar(Compiler* compiler, CResult& result) {
    return make_shared<CInterfaceVar>(loc, nullptr, shared_from_this());
}

int CInterface::getArgStart() {
    if (hasThis) {
        return 2;
    }
    return 1;
}

shared_ptr<CVar> CInterface::getCVar(Compiler* compiler, CResult& result, const string& name) {
    assert(false);
    return nullptr;
}

shared_ptr<CBaseFunction> CInterface::getCFunction(Compiler* compiler, CResult& result, const string& name, shared_ptr<CBaseFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames, CTypeMode returnMode) {
    if (templateTypeNames == nullptr) {
        auto it = methodByName.find(name);
        if (it != methodByName.end()) {
            return it->second;
        }        
    }
    return nullptr;
}

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

shared_ptr<CType> CInterface::getReturnType(Compiler* compiler, CResult& result) {
    assert(false);
    return nullptr;
}

string CInterface::getCInitFunctionName() {
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

    switch (typeMode) {
    case CTM_Stack:
        break;
    case CTM_Heap:
        functionName += "_heap";
        break;
    default:
        assert(false);
        break;
    }

    return functionName;
}

string CInterface::getCStructName(CTypeMode typeMode) {
    return "sji_" + getCBaseName(typeMode);
}

string CInterface::getCCopyFunctionName() {
    return getCStructName(_returnMode) + "_copy";
}

string CInterface::getCDestroyFunctionName() {
    return getCStructName(_returnMode) + "_destroy";
}

string CInterface::getCTypeIdName() {
    return getCStructName(_returnMode) + "_typeId";
}

string CInterface::getCCastFunctionName(CTypeMode toTypeMode, shared_ptr<CBaseFunction> fromFunction) {
    stringstream line;
    line << fromFunction->getCInitFunctionName() << "_as_" << getCStructName(toTypeMode);
    return line.str();
}

void CInterface::transpileCast(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> fromValue, shared_ptr<TrStoreValue> toValue) {
    if (fromValue->type->parent.lock()->classType == CFT_Interface) {
        auto fromInterface = static_pointer_cast<CInterface>(fromValue->type->parent.lock());
        stringstream line;
        line << "(" << getCStructName(toValue->type->typeMode) << "*)" << fromValue->name << "->asInterface(" << fromValue->name << "->_parent, " << getCTypeIdName() << ")";
        toValue->setValue(compiler, result, loc, trBlock, make_shared<TrValue>(toValue->type, line.str()));
    }
    else {
        stringstream line;
        line << getCCastFunctionName(toValue->type->typeMode, fromValue->type->parent.lock()) << "(" << fromValue->name << ")";
        toValue->setValue(compiler, result, loc, trBlock, make_shared<TrValue>(toValue->type, line.str()));
    }
}

void CInterface::transpileDefinition(Compiler* compiler, CResult& result, TrOutput* trOutput) {
    // Create stack struct
    string stackStructName = getCStructName(CTM_Stack);
    if (trOutput->structs.find(stackStructName) == trOutput->structs.end()) {
        trOutput->structs[stackStructName].push_back("sjs_object* _parent");
        trOutput->structs[stackStructName].push_back("void (*destroy)(sjs_object* _this)");
        trOutput->structs[stackStructName].push_back("sjs_object* (*asInterface)(sjs_object* _this, int typeId)");
        for (auto method : methods) {
            trOutput->structs[stackStructName].push_back(method->getCTypeName(compiler, result, true));
        }
        trOutput->structOrder.push_back(stackStructName);
    }

    if (_returnMode == CTM_Heap) {
        string heapStructName = getCStructName(CTM_Heap);
        if (trOutput->structs.find(heapStructName) == trOutput->structs.end()) {
            trOutput->structs[heapStructName].push_back("int _refCount");
            trOutput->structs[heapStructName].push_back(stackStructName + " _data");
            trOutput->structOrder.push_back(heapStructName);
        }
    }

    string destroyInterfaceName = "void " + getCDestroyFunctionName() + "(" + stackStructName + "* _this)";
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

void CInterface::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> parentValue, CLoc& calleeLoc, vector<pair<bool, shared_ptr<NBase>>>& parameters, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    assert(false);
    return;
}

void CInterface::dumpBody(Compiler* compiler, CResult& result, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
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
//shared_ptr<TrValue> CInterface::cast(Compiler* compiler, CResult& result, IRBuilder<>* builder, shared_ptr<TrValue> fromValue, bool isHeap, vector<Function*>& interfaceMethodValues) {
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

shared_ptr<CInterface> CInterfaceDefinition::getInterface(Compiler* compiler, CResult& result, vector<shared_ptr<CType>>& templateTypes, weak_ptr<CFunction> funcParent, CTypeMode returnMode) {
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
        
        interface = make_shared<CInterface>(loc, shared_from_this(), funcParent, returnMode);
        interface = interface->init(compiler, result, ninterface, templateTypes);
        cinterfaces[templateTypes] = interface;
    }
    return interface;
}
