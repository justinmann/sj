#include "Node.h"

void NBlock::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    for (auto it : statements) {
        it->define(compiler, result, thisFunction);
    }
}

shared_ptr<CVar> NBlock::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);
    shared_ptr<CVar> lastVar = nullptr;
    for (auto it : statements) {
        lastVar = it->getVar(compiler, result, thisFunction, thisVar);
    }
    return lastVar;
}

shared_ptr<CType> NBlock::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    if (statements.size() == 0) {
        return compiler->typeVoid;
    }
    return statements.back()->getType(compiler, result, thisFunction, thisVar);
}

int NBlock::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    auto count = 0;
    for (auto it : statements) {
        auto isLast = it == statements.back();
        count += it->setHeapVar(compiler, result, thisFunction, thisVar, isLast ? isHeapVar : false);
    }
    return count;
}

shared_ptr<ReturnValue> NBlock::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    shared_ptr<ReturnValue> last = nullptr;
    for (auto it : statements) {
        auto isLast = it == statements.back();
        last = it->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB);
        if (!isLast && last) {
            last->releaseIfNeeded(compiler, result, builder);
        }
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
