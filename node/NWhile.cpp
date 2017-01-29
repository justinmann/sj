#include "Node.h"

void NWhile::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    cond->define(compiler, result, thisFunction);
    body->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NWhile::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    cond->getVar(compiler, result, thisFunction);
    body->getVar(compiler, result, thisFunction);
    return nullptr;
}

shared_ptr<CType> NWhile::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeVoid;
}

int NWhile::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, bool isHeapVar) {
    auto count = cond->setHeapVar(compiler, result, thisFunction, false);
    count += body->setHeapVar(compiler, result, thisFunction, false);
    return count;
}

shared_ptr<ReturnValue> NWhile::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    Function *TheFunction = builder->GetInsertBlock()->getParent();
    auto loopBB = BasicBlock::Create(compiler->context, "loop");
    auto continueBB = BasicBlock::Create(compiler->context, "continue");
    auto afterBB = BasicBlock::Create(compiler->context, "afterloop");
    
    builder->CreateBr(loopBB);
    
    // Make the new basic block for the loop header, inserting after current block.
    TheFunction->getBasicBlockList().push_back(loopBB);
    builder->SetInsertPoint(loopBB);
    
    auto condition = cond->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    if (!condition->value->getType()->isIntegerTy(1)) {
        result.addError(loc, CErrorCode::TypeMismatch, "condition for while must be a bool");
        return nullptr;
    }
    assert(condition->type == RVT_SIMPLE);

    builder->CreateCondBr(condition->value, continueBB, afterBB);
    
    TheFunction->getBasicBlockList().push_back(continueBB);
    builder->SetInsertPoint(continueBB);
    
    // Emit the body of the loop.  This, like any other expr, can change the
    // current BB.  Note that we ignore the value computed by the body, but don't
    // allow an error.
    auto bodyResult = body->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    if (bodyResult) {
        bodyResult->releaseIfNeeded(compiler, result, builder);
    }
    
    builder->CreateBr(loopBB);
    
    // Any new code will be inserted in AfterBB.
    TheFunction->getBasicBlockList().push_back(afterBB);
    builder->SetInsertPoint(afterBB);
    
    return nullptr;
}

void NWhile::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NWhile'");

    if (cond) {
        dumpf(level, "cond: {");
        cond->dump(compiler, level + 1);
        dumpf(level, "}");
    }

    if (body) {
        dumpf(level, "body: {");
        body->dump(compiler, level + 1);
        dumpf(level, "}");
    }
}

