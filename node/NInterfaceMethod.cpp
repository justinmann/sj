#include "Node.h"

NInterfaceMethod::NInterfaceMethod(CLoc loc, const char* name, shared_ptr<CTypeNameList> templateTypeNames, shared_ptr<NodeList> arguments_, shared_ptr<CTypeName> returnTypeName) : NBaseFunction(NodeType_InterfaceMethod, loc), name(name), templateTypeNames(templateTypeNames), returnTypeName(returnTypeName) {
    if (arguments_) {
        for (auto it : *arguments_) {
            assert(it->nodeType == NodeType_Assignment);
            assignments.push_back(static_pointer_cast<NAssignment>(it));
        }
    }
}

shared_ptr<CType> NInterfaceMethod::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeVoid;
}

shared_ptr<ReturnValue> NInterfaceMethod::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(builder, this);
    return nullptr;
}

void NInterfaceMethod::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
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

shared_ptr<CType> CInterfaceMethodReturnVar::getType(Compiler* compiler, CResult& result) {
    return returnType;
}

shared_ptr<ReturnValue> CInterfaceMethodReturnVar::getLoadValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(false);
    return nullptr;
}

Value* CInterfaceMethodReturnVar::getStoreValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(false);
    return nullptr;
}

bool CInterfaceMethodReturnVar::getHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    return isHeapVar;
}

int CInterfaceMethodReturnVar::setHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
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

void CInterfaceMethodReturnVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    assert(false);
}


shared_ptr<CType> CInterfaceMethodArgVar::getType(Compiler* compiler, CResult& result) {
    return returnType;
}

shared_ptr<ReturnValue> CInterfaceMethodArgVar::getLoadValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(false);
    return nullptr;
}

Value* CInterfaceMethodArgVar::getStoreValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(false);
    return nullptr;
}

bool CInterfaceMethodArgVar::getHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    return isHeapVar;
}

int CInterfaceMethodArgVar::setHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
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

void CInterfaceMethodArgVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    assert(false);
}

CInterfaceMethod::CInterfaceMethod(string& name, weak_ptr<CInterface> parent, int structIndex) : functionType(nullptr), structIndex(structIndex), CBaseFunction(name, parent, weak_ptr<CBaseFunctionDefinition>()) {
    
}

shared_ptr<CInterfaceMethod> CInterfaceMethod::init(Compiler* compiler, CResult& result, shared_ptr<NInterfaceMethod> method) {
    hasParent = true;
    loc = method->loc;
    returnType = getVarType(compiler, result, method->returnTypeName);
    if (!returnType) {
        result.addError(method->loc, CErrorCode::InvalidType, "type '%s' is not defined", method->returnTypeName->name.c_str());
        return nullptr;
    }
    

    for (auto it : method->assignments) {
        if (it->var) {
            result.addError(it->loc, CErrorCode::InvalidDot, "cannot use '.' in variable declaration for a function: '%s'", it->name.c_str());
            return nullptr;
        }
        
        int index = (int)argVars.size();
        auto argType = it->getType(compiler, result, nullptr, nullptr);
        auto argVar = make_shared<CInterfaceMethodArgVar>(argType);
        argVars.push_back(argVar);
        argDefaultValues.push_back(it->rightSide);
    }
    
    for (auto it : method->assignments) {
        auto argType = it->getType(compiler, result, parent.lock(), nullptr);
        if (!argType) {
            return nullptr;
        }
    }
    
    return shared_from_this();
}

string CInterfaceMethod::fullName(bool includeTemplateTypes) {
    assert(false);
    return "";
}

bool CInterfaceMethod::getHasThis() {
    assert(false);
    return false;
}

shared_ptr<CType> CInterfaceMethod::getThisType(Compiler* compiler, CResult& result) {
    return nullptr;
}

int CInterfaceMethod::getThisIndex(const string& name) const {
    assert(false);
    return -1;
}

void CInterfaceMethod::createThisVar(Compiler* compiler, CResult& result, shared_ptr<CVar>& thisVar) {
}

Type* CInterfaceMethod::getStructType(Compiler* compiler, CResult& result) {
    assert(false);
    return nullptr;
}

Value* CInterfaceMethod::getRefCount(Compiler* compiler, CResult& result, IRBuilder<>* builder, Value* thisValue) {
    assert(false);
    return nullptr;
}

shared_ptr<CVar> CInterfaceMethod::getCVar(Compiler* compiler, CResult& result, const string& name) {
    assert(false);
    return nullptr;
}

shared_ptr<CBaseFunction> CInterfaceMethod::getCFunction(Compiler* compiler, CResult& result, const string& name, shared_ptr<CBaseFunction> callerFunction, shared_ptr<CTypeNameList> templateTypeNames) {
    assert(false);
    return nullptr;
}

Value* CInterfaceMethod::getParentValue(Compiler* compiler, CResult& result, IRBuilder<>* builder, bool thisInEntry, Value* thisValue) {
    assert(false);
    return nullptr;
}

shared_ptr<CType> CInterfaceMethod::getVarType(Compiler* compiler, CResult& result, shared_ptr<CTypeName> typeName) {
    if (!parent.expired()) {
        return parent.lock()->getVarType(compiler, result, typeName);
    }
    
    return compiler->getType(typeName->name);
}

shared_ptr<CType> CInterfaceMethod::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    return returnType;
}

shared_ptr<CVar> CInterfaceMethod::getReturnVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
    if (!returnVar) {
        returnVar = make_shared<CInterfaceMethodReturnVar>(returnType);
    }
    return returnVar;
}

shared_ptr<ReturnValue> CInterfaceMethod::call(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, shared_ptr<CVar> calleeVar, shared_ptr<CVar> dotVar, IRBuilder<>* builder, BasicBlock* catchBB, vector<shared_ptr<NBase>>& parameters) {
    auto interfaceType = parent.lock()->getStructType(compiler, result);
    
    vector<shared_ptr<ReturnValue>> argReturnValues;
    vector<Value *> argValues;
    
    // Add "parent" to "this"
    assert(dotVar);
    assert(getHasParent(compiler, result));
    auto dotReturnValue = dotVar->getLoadValue(compiler, result, thisVar, thisValue, true, thisValue, builder, catchBB);
    auto interfaceValue = dotReturnValue->value;
    auto parentValuePtr = builder->CreateStructGEP(interfaceType, interfaceValue, 0);
    auto parentValue = builder->CreateLoad(parentValuePtr);
    argValues.push_back(parentValue);
    
    auto functionPtr = builder->CreateStructGEP(interfaceType, interfaceValue, structIndex);
    auto function = builder->CreateLoad(functionPtr);
    // auto function = builder->CreateBitCast(functionVoid, getFunctionType(compiler, result)-);
    
    auto argIndex = 0;
    // Fill in "this" with normal arguments
    for (auto defaultAssignment : argDefaultValues) {
        auto argVar = argVars[argIndex];
        auto argHeapVar = argVar->getHeapVar(compiler, result, thisVar);
        auto argType = argVar->getType(compiler, result);
        auto isDefaultAssignment = parameters[argIndex] == defaultAssignment;
        shared_ptr<ReturnValue> argReturnValue;
        
        if (isDefaultAssignment) {
            auto paramVar = parameters[argIndex]->getVar(compiler, result, shared_from_this(), calleeVar);
            if (paramVar) {
                auto paramHeapVar = paramVar->getHeapVar(compiler, result, thisVar);
                assert(paramHeapVar == argHeapVar);
            }
            argReturnValue = parameters[argIndex]->compile(compiler, result, shared_from_this(), calleeVar, nullptr, builder, catchBB);
        } else {
            auto paramVar = parameters[argIndex]->getVar(compiler, result, shared_from_this(), thisVar);
            if (paramVar) {
                auto paramHeapVar = paramVar->getHeapVar(compiler, result, thisVar);
                assert(paramHeapVar == argHeapVar);
            }
            argReturnValue = parameters[argIndex]->compile(compiler, result, shared_from_this(), thisVar, thisValue, builder, catchBB);
        }
        
        if (!argReturnValue) {
            result.addError(loc, CErrorCode::TypeMismatch, "value is empty");
            return nullptr;
        }
        
        if (argReturnValue->value->getType() != argType->llvmRefType(compiler, result)) {
            result.addError(loc, CErrorCode::TypeMismatch, "value does not match");
            return nullptr;
        }
        
        argReturnValues.push_back(argReturnValue);
        argValues.push_back(argReturnValue->value);
        argIndex++;
    }
    
    auto returnType = getReturnType(compiler, result, calleeVar);
    auto returnFunction = returnType->parent.lock();
    
    Value* returnValue = nullptr;
    
    if (catchBB) {
        auto continueBB = BasicBlock::Create(compiler->context);
        returnValue = builder->CreateInvoke(function, continueBB, catchBB, argValues);
        
        Function *function = builder->GetInsertBlock()->getParent();
        function->getBasicBlockList().push_back(continueBB);
        builder->SetInsertPoint(continueBB);
    } else {
        returnValue = builder->CreateCall(function, argValues);
    }
    
    auto mustRelease = getReturnMustRelease(compiler, result);
    
    if (dotReturnValue) {
        dotReturnValue->releaseIfNeeded(compiler, result, builder);
    }
    
    return make_shared<ReturnValue>(returnFunction, mustRelease, returnFunction ? RVT_HEAP : RVT_SIMPLE, false, returnValue);
}

void CInterfaceMethod::dumpBody(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    assert(false);
}

bool CInterfaceMethod::getReturnMustRelease(Compiler* compiler, CResult& result) {
    return true;
}

Function* CInterfaceMethod::getDestructor(Compiler* compiler, CResult& result) {
    return nullptr;
}

Type* CInterfaceMethod::getFunctionType(Compiler* compiler, CResult& result) {
    if (!functionType) {
        vector<Type*> argLLVMTypes;
        argLLVMTypes.push_back(Type::getInt8PtrTy(compiler->context));
        for (auto it : argTypes) {
            argLLVMTypes.push_back(it->llvmRefType(compiler, result));
        }
        functionType = FunctionType::get(returnType->llvmRefType(compiler, result), argLLVMTypes, false);
    }
    return functionType;
}
