#include "Node.h"

NodeType NStringArray::getNodeType() const {
    return NodeType_StringArray;
}

void NStringArray::define(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
}

void NStringArray::fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    createCall = make_shared<NCall>(loc, "array", make_shared<TemplateTypeNames>("char"), nullptr);
}

shared_ptr<CType> NStringArray::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    return createCall->getReturnType(compiler, result, thisFunction);
}

Value* NStringArray::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    return builder->CreateGlobalStringPtr(str);
}

void NStringArray::dump(Compiler* compiler, int level) const {
    // dumpf(level, "value: %s", value.c_str());
}

NodeType NString::getNodeType() const {
    return NodeType_String;
}

void NString::fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    auto size = make_shared<NInteger>(loc, str.size());
    auto stringArray = make_shared<NStringArray>(loc, str);
    createCall = make_shared<NCall>(loc, "list", make_shared<TemplateTypeNames>("char"), make_shared<NodeList>(size, size, stringArray));
}

shared_ptr<CType> NString::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    return createCall->getReturnType(compiler, result, thisFunction);
}

Value* NString::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const {
    assert(compiler->state == CompilerState::Compile);
    return createCall->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
}

void NString::dump(Compiler* compiler, int level) const {
    dumpf(level, "value: 'string'");
}
