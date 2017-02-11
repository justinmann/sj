#include "Node.h"

class CForVar : public CVar {
public:
    CForVar(shared_ptr<CFunction> parent_, const string& name_) {
        name = name_;
        mode = CVarType::Var_Local;
        isMutable = false;
        parent = parent_;
        isHeapVar = false;
    }
    
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result) {
        return compiler->typeInt;
    }
    
    virtual shared_ptr<ReturnValue> getLoadValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
        assert(value);
        return make_shared<ReturnValue>(value);
    }
    
    virtual Value* getStoreValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
        assert(false);
        return nullptr;
    }
    
    virtual bool getHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
        return isHeapVar;
    }
    
    virtual int setHeapVar(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar) {
        if (!isHeapVar) {
            isHeapVar = true;
            return 1;
        }
        return 0;
    }
    
    virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, map<shared_ptr<CFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
        ss << name;
    }

    Value* value;
    bool isHeapVar;
};

void NFor::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    start->define(compiler, result, thisFunction);
    end->define(compiler, result, thisFunction);
    body->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NFor::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);
    start->getVar(compiler, result, thisFunction, thisVar);
    end->getVar(compiler, result, thisFunction, thisVar);

    if (thisFunction->localVarsByName.find(varName) != thisFunction->localVarsByName.end()) {
        result.addError(loc, CErrorCode::InvalidVariable, "var '%s' already exists within function, must have a unique name", varName.c_str());
        return nullptr;
    }
    
    _forVar = make_shared<CForVar>(thisFunction, varName);
    
    thisFunction->localVarsByName[varName] = _forVar;

    body->getVar(compiler, result, thisFunction, thisVar);

    thisFunction->localVarsByName.erase(varName);
    
    return nullptr;
}

shared_ptr<CType> NFor::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeVoid;
}

int NFor::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    auto count = start->setHeapVar(compiler, result, thisFunction, thisVar, false);
    count += end->setHeapVar(compiler, result, thisFunction, thisVar, false);
    thisFunction->localVarsByName[varName] = _forVar;
    count += body->setHeapVar(compiler, result, thisFunction, thisVar, false);
    thisFunction->localVarsByName.erase(varName);
    return count;
}

shared_ptr<ReturnValue> NFor::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(builder, this);
    
    // Emit the start code first, without 'variable' in scope.
    auto startValue = start->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB);
    if (!startValue) {
        return nullptr;
    }
    
    assert(startValue->type == RVT_SIMPLE);
    
    if (!startValue->value->getType()->isIntegerTy(64)) {
        result.addError(loc, CErrorCode::TypeMismatch, "start value must be a int");
        return nullptr;
    }
    
    // Compute the end condition.
    auto endValue = end->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB);
    if (!endValue) {
        return nullptr;
    }
    
    assert(endValue->type == RVT_SIMPLE);
    
    if (!endValue->value->getType()->isIntegerTy(64)) {
        result.addError(loc, CErrorCode::TypeMismatch, "end value must be a int");
        return nullptr;
    }
    
    auto loopBB = BasicBlock::Create(compiler->context, "loop");
    auto afterBB = BasicBlock::Create(compiler->context, "afterloop");
    
    auto startCondition = builder->CreateICmpSLE(startValue->value, endValue->value);
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
    Variable->addIncoming(startValue->value, preheaderBB);
    
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
    auto bodyValue = body->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB);
    if (bodyValue) {
        bodyValue->releaseIfNeeded(compiler, result, builder);
    }
    
    // Emit the step value.
    Value *StepVal = ConstantInt::get(compiler->context, APInt(64, 1));
    Value *NextVar = builder->CreateAdd(Variable, StepVal, "nextvar");
    
    // Convert condition to a bool by comparing equal to 0.0.
    auto endCondition = builder->CreateICmpSLT(Variable, endValue->value);
    
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

void NFor::dump(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CFunction>, string>& functions, stringstream& ss, int level) {
    ss << "for " << varName << " : ";
    if (start) {
        start->dump(compiler, result, thisFunction, thisVar, functions, ss, level + 1);
    }
    
    ss << " to ";

    if (end) {
        end->dump(compiler, result, thisFunction, thisVar, functions, ss, level + 1);
    }
    
    ss << " ";
    
    body->dump(compiler, result, thisFunction, thisVar, functions, ss, level);
}

