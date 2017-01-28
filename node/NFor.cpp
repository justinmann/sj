#include "Node.h"

class CForVar : public CVar {
public:
    CForVar(shared_ptr<CFunction> parent_, const string& name_) {
        name = name_;
        mode = CVarType::Local;
        isMutable = false;
        parent = parent_;
    }
    
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result) {
        return compiler->typeInt;
    }
    
    virtual Value* getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB, bool isReturnRetained) {
        assert(value);
        return value;
    }
    
    virtual Value* getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
        assert(false);
        return nullptr;
    }

    Value* value;
};

void NFor::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    start->define(compiler, result, thisFunction);
    end->define(compiler, result, thisFunction);
    body->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NFor::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    start->getVar(compiler, result, thisFunction);
    end->getVar(compiler, result, thisFunction);

    if (thisFunction->localVarsByName.find(varName) != thisFunction->localVarsByName.end()) {
        result.addError(loc, CErrorCode::InvalidVariable, "var '%s' already exists within function, must have a unique name", varName.c_str());
        return nullptr;
    }
    
    _forVar = make_shared<CForVar>(thisFunction, varName);
    
    thisFunction->localVarsByName[varName] = _forVar;

    body->getVar(compiler, result, thisFunction);

    thisFunction->localVarsByName.erase(varName);
    
    return nullptr;
}

shared_ptr<CType> NFor::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeVoid;
}

int NFor::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, bool isHeapVar) {
    auto count = start->setHeapVar(compiler, result, thisFunction, false);
    count += end->setHeapVar(compiler, result, thisFunction, false);
    thisFunction->localVarsByName[varName] = _forVar;
    count += body->setHeapVar(compiler, result, thisFunction, false);
    thisFunction->localVarsByName.erase(varName);
    return count;
}

Value* NFor::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, bool isReturnRetained) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    // Emit the start code first, without 'variable' in scope.
    Value *StartVal = start->compile(compiler, result, thisFunction, thisValue, builder, catchBB, false);
    if (!StartVal) {
        return nullptr;
    }
    
    if (!StartVal->getType()->isIntegerTy(64)) {
        result.addError(loc, CErrorCode::TypeMismatch, "start value must be a int");
        return nullptr;
    }
    
    // Compute the end condition.
    Value *EndVal = end->compile(compiler, result, thisFunction, thisValue, builder, catchBB, false);
    if (!EndVal) {
        return nullptr;
    }
    
    if (!EndVal->getType()->isIntegerTy(64)) {
        result.addError(loc, CErrorCode::TypeMismatch, "end value must be a int");
        return nullptr;
    }
    
    auto loopBB = BasicBlock::Create(compiler->context, "loop");
    auto afterBB = BasicBlock::Create(compiler->context, "afterloop");
    
    auto startCondition = builder->CreateICmpSLE(StartVal, EndVal);
    builder->CreateCondBr(startCondition, loopBB, afterBB);

    // Make the new basic block for the loop header, inserting after current
    // block.
    Function *TheFunction = builder->GetInsertBlock()->getParent();
    BasicBlock *preheaderBB = builder->GetInsertBlock();
    TheFunction->getBasicBlockList().push_back(loopBB);
    
    // Start insertion in LoopBB.
    builder->SetInsertPoint(loopBB);
    
    // Start the PHI node with an entry for Start.
    auto Variable = builder->CreatePHI(Type::getInt64Ty(compiler->context), 2, varName);
    Variable->addIncoming(StartVal, preheaderBB);
    
    // Within the loop, the variable is defined equal to the PHI node.  If it
    // shadows an existing variable, we have to restore it, so save it now.
    if (thisFunction->localVarsByName.find(varName) != thisFunction->localVarsByName.end()) {
        result.addError(loc, CErrorCode::InvalidVariable, "var '%s' already exists within function, must have a unique name", varName.c_str());
        return nullptr;
    }
    
    thisFunction->localVarsByName[varName] = _forVar;
    _forVar->value = Variable;
    
    // Emit the body of the loop.  This, like any other expr, can change the
    // current BB.  Note that we ignore the value computed by the body, but don't
    // allow an error.
    body->compile(compiler, result, thisFunction, thisValue, builder, catchBB, false);
    
    // Emit the step value.
    Value *StepVal = ConstantInt::get(compiler->context, APInt(64, 1));
    Value *NextVar = builder->CreateAdd(Variable, StepVal, "nextvar");
    
    // Convert condition to a bool by comparing equal to 0.0.
    auto endCondition = builder->CreateICmpSLT(Variable, EndVal);
    
    // Create the "after loop" block and insert it.
    BasicBlock *loopEndBB = builder->GetInsertBlock();
    
    // Insert the conditional branch into the end of LoopEndBB.
    builder->CreateCondBr(endCondition, loopBB, afterBB);
    
    // Any new code will be inserted in AfterBB.
    TheFunction->getBasicBlockList().push_back(afterBB);
    builder->SetInsertPoint(afterBB);
    
    // Add a new entry to the PHI node for the backedge.
    Variable->addIncoming(NextVar, loopEndBB);
    
    // Restore the unshadowed variable.
    
    thisFunction->localVarsByName.erase(varName);
    _forVar->value = nullptr;

    // for expr always returns 0.0.
    return nullptr;
}

void NFor::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NFor'");
    dumpf(level, "varName: %s", varName.c_str());

    if (start) {
        dumpf(level, "start: {");
        start->dump(compiler, level + 1);
        dumpf(level, "}");
    }

    if (end) {
        dumpf(level, "end: {");
        end->dump(compiler, level + 1);
        dumpf(level, "}");
    }
}

