#include "Node.h"

NodeType NBlock::getNodeType() const {
    return NodeType_Block;
}

void NBlock::define(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    for (auto it : statements) {
        it->define(compiler, result, thisFunction);
    }
}

void NBlock::fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    for (auto it : statements) {
        it->fixVar(compiler, result, thisFunction);
    }
}

shared_ptr<CType> NBlock::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    if (statements.size() == 0) {
        return compiler->typeVoid;
    }
    return statements.back()->getReturnType(compiler, result, thisFunction);
}

Value* NBlock::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const {
    assert(compiler->state == CompilerState::Compile);
    Value *last = nullptr;
    for (auto it : statements) {
        last = it->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    }
    return last;
}

void NBlock::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NBlock'");
    if (statements.size() > 0) {
        dumpf(level, "statements: [");
        dumpf(level + 1, "{");
        for (auto it : statements) {
            it->dump(compiler, level + 2);
        }
        dumpf(level + 1, "}");
        dumpf(level, "]");
    }
}
