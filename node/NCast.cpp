#include "Node.h"

void NCast::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    node->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NCast::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar) {
    assert(compiler->state == CompilerState::FixVar);
    node->getVar(compiler, result, thisFunction, thisVar, nullptr);
    
    auto toType = thisFunction->getVarType(compiler, result, typeName);
    if (toType != nullptr && toType->category == CTC_Interface) {
        auto interface = static_pointer_cast<CInterface>(toType->parent.lock());
        interfaceVar = interface->getThisVar(compiler, result);
        return interfaceVar;
    }

    return nullptr;
}

shared_ptr<CType> NCast::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    auto t = thisFunction->getVarType(compiler, result, typeName);
    if (!t) {
        result.addError(loc, CErrorCode::InvalidType, "type does not exist");
    }
    return t;
}

int NCast::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, bool isHeapVar_) {
    isHeapVar = isHeapVar_;
    return node->setHeapVar(compiler, result, thisFunction, thisVar, nullptr, false);
}

shared_ptr<ReturnValue> NCast::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, bool isReturnValue) {
    auto type = getType(compiler, result, thisFunction, thisVar);

    auto returnValue = node->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, false);
    if (!returnValue) {
        assert(false);
        return nullptr;
    }

    auto resultValue = trBlock->createTempVariable("result", type, false, RVR_MustRetain);
    stringstream line;
    line << resultValue->name << " = " << "(" << type->nameRef << ")" << returnValue->name;
    trBlock->statements.push_back(line.str());

	return resultValue;
}

//shared_ptr<ReturnValue> NCast::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    assert(compiler->state == CompilerState::Compile);
//    compiler->emitLocation(builder, &this->loc);
//    
//    auto v = node->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, RRT_Auto);
//    if (!v)
//        return nullptr;
//    
//    auto fromType = node->getType(compiler, result, thisFunction, thisVar);
//    auto toType = thisFunction->getVarType(compiler, result, typeName);
//    
//    if (!toType) {
//        result.addError(loc, CErrorCode::InvalidType, "type does not exist");
//    }
//
//    if (fromType == toType) {
//        return v;
//    }
//    
//    if (fromType == compiler->typeInt && toType == compiler->typeFloat) {
//        assert(v->type == RVT_SIMPLE);
//        return make_shared<ReturnValue>(false, builder->CreateSIToFP(v->value, toType->llvmRefType(compiler, result)));
//    }
//
//    if (fromType == compiler->typeFloat && toType == compiler->typeInt) {
//        assert(v->type == RVT_SIMPLE);
//        return make_shared<ReturnValue>(false, builder->CreateFPToSI(v->value, toType->llvmRefType(compiler, result)));
//    }
//    
//    if (toType->category == CTC_Interface) {
//        auto interface = static_pointer_cast<CInterface>(toType->parent.lock());
//        auto function = static_pointer_cast<CFunction>(v->valueFunction);
//        return function->cast(compiler, result, builder, v, isHeapVar, interface);
//    }
//    
//    result.addError(loc, CErrorCode::InvalidCast, "cannot cast");
//    
//    return NULL;
//}

void NCast::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    node->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
    ss << " as " << typeName->getName();
}
