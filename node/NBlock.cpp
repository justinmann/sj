#include "Node.h"

NodeType NBlock::getNodeType() const {
    return NodeType_Block;
}

void NBlock::define(Compiler* compiler, CResult& result) {
    for (auto it : statements) {
        it->define(compiler, result);
    }
}

shared_ptr<CType> NBlock::getReturnType(Compiler* compiler, CResult& result) const {
    if (statements.size() == 0) {
        return nullptr;
    }
    return statements.back()->getReturnType(compiler, result);
}

Value* NBlock::compile(Compiler* compiler, CResult& result) const {
    Value *last = nullptr;
    for (auto it : statements) {
        last = it->compile(compiler, result);
    }
    return last;
}
