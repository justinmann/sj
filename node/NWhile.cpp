#include "Node.h"

void NWhile::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    cond->define(compiler, result, thisFunction);
    body->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NWhile::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);
    cond->getVar(compiler, result, thisFunction, thisVar);
    body->getVar(compiler, result, thisFunction, thisVar);
    return nullptr;
}

shared_ptr<CType> NWhile::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeVoid;
}

int NWhile::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    auto count = cond->setHeapVar(compiler, result, thisFunction, thisVar, false);
    count += body->setHeapVar(compiler, result, thisFunction, thisVar, false);
    return count;
}

shared_ptr<ReturnValue> NWhile::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(builder, this);
    
    Function *TheFunction = builder->GetInsertBlock()->getParent();
    auto loopBB = BasicBlock::Create(compiler->context, "loop");
    auto continueBB = BasicBlock::Create(compiler->context, "continue");
    auto afterBB = BasicBlock::Create(compiler->context, "afterloop");
    
    builder->CreateBr(loopBB);
    
    // Make the new basic block for the loop header, inserting after current block.
    TheFunction->getBasicBlockList().push_back(loopBB);
    builder->SetInsertPoint(loopBB);
    
    auto condition = cond->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB);
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
    auto bodyResult = body->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB);
    if (bodyResult) {
        bodyResult->releaseIfNeeded(compiler, result, builder);
    }
    
    builder->CreateBr(loopBB);
    
    // Any new code will be inserted in AfterBB.
    TheFunction->getBasicBlockList().push_back(afterBB);
    builder->SetInsertPoint(afterBB);
    
    return nullptr;
}

void NWhile::dump(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CFunction>, string>& functions, stringstream& ss, int level) {
    ss << "while ";

    if (cond) {
        cond->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
    }

    if (body) {
        body->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
    }
}

