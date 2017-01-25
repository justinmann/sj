#include "Node.h"

void NBlock::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    for (auto it : statements) {
        it->define(compiler, result, thisFunction);
    }
}

shared_ptr<CVar> NBlock::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    shared_ptr<CVar> lastVar = nullptr;
    for (auto it : statements) {
        lastVar = it->getVar(compiler, result, thisFunction);
    }
    return lastVar;
}

shared_ptr<CType> NBlock::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    if (statements.size() == 0) {
        return compiler->typeVoid;
    }
    return statements.back()->getType(compiler, result, thisFunction);
}

int NBlock::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, bool isHeapVar) {
    auto count = 0;
    for (auto it : statements) {
        auto isLast = it == statements.back();
        count += it->setHeapVar(compiler, result, thisFunction, isLast ? isHeapVar : false);
    }
    return count;
}

Value* NBlock::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
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
