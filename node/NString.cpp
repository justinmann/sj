#include "Node.h"

void NStringArray::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
}

shared_ptr<CVar> NStringArray::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    createCall = make_shared<NCall>(loc, "array", make_shared<TemplateTypeNames>("char"), nullptr);
    return createCall->getVar(compiler, result, thisFunction, nullptr);
}

shared_ptr<CType> NStringArray::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    return createCall->getType(compiler, result, thisFunction);
}

int NStringArray::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, bool isHeapVar) {
    return 0;
}

shared_ptr<ReturnValue> NStringArray::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    auto varFunction = createCall->getVar(compiler, result, thisFunction, nullptr)->getCFunctionForValue(compiler, result);
    return make_shared<ReturnValue>(varFunction, false, RVT_GLOBAL, builder->CreateGlobalStringPtr(str));
}

void NStringArray::dump(Compiler* compiler, int level) const {
    // dumpf(level, "value: %s", value.c_str());
}

shared_ptr<CVar> NString::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    auto size = make_shared<NInteger>(loc, str.size());
    auto stringArray = make_shared<NStringArray>(loc, str);
    createCall = make_shared<NCall>(loc, "list", make_shared<TemplateTypeNames>("char"), make_shared<NodeList>(size, size, stringArray));
    return createCall->getVar(compiler, result, thisFunction, nullptr);
}

shared_ptr<CType> NString::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    return createCall->getType(compiler, result, thisFunction);
}

int NString::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, bool isHeapVar) {
    return createCall->setHeapVar(compiler, result, thisFunction, nullptr, isHeapVar);
}

shared_ptr<ReturnValue> NString::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    return createCall->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
}

void NString::dump(Compiler* compiler, int level) const {
    dumpf(level, "value: 'string'");
}
