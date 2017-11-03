#include "Node.h"

class CForVar : public CVar {
public:
    CForVar(shared_ptr<CBaseFunction> parent_, const string& name_) {
        name = name_;
        mode = CVarType::Var_Local;
        isMutable = false;
        parent = parent_;
        isHeapVar = false;
    }
    
    virtual shared_ptr<CType> getType(Compiler* compiler, CResult& result) {
        return compiler->typeI32;
    }
    
    //virtual shared_ptr<ReturnValue> getLoadValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
    //    assert(value);
    //    return make_shared<ReturnValue>(false, value);
    //}
    //
    //virtual Value* getStoreValue(Compiler* compiler, CResult& result, shared_ptr<CVar> thisVar, Value* thisValue, bool dotInEntry, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    //    assert(false);
    //    return nullptr;
    //}
    
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
    
    shared_ptr<CType> transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, stringstream& trLine, shared_ptr<CVar> dotVar) {
        trLine << name;
		return getType(compiler, result);
	}

    virtual void dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
        ss << name;
    }

    //Value* value;
    bool isHeapVar;
};

void NFor::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    start->define(compiler, result, thisFunction);
    end->define(compiler, result, thisFunction);
    body->define(compiler, result, thisFunction);
}

shared_ptr<CVar> NFor::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);
    start->getVar(compiler, result, thisFunction, thisVar);
    end->getVar(compiler, result, thisFunction, thisVar);
    
    auto thisFun = static_pointer_cast<CFunction>(thisFunction);

    if (thisFun->localVarsByName.find(varName) != thisFun->localVarsByName.end()) {
        result.addError(loc, CErrorCode::InvalidVariable, "var '%s' already exists within function, must have a unique name", varName.c_str());
        return nullptr;
    }
    
    _forVar = make_shared<CForVar>(thisFunction, varName);
    
    thisFun->localVarsByName[varName] = _forVar;

    body->getVar(compiler, result, thisFunction, thisVar);

    thisFun->localVarsByName.erase(varName);
    
    return nullptr;
}

shared_ptr<CType> NFor::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    return compiler->typeVoid;
}

int NFor::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    auto count = start->setHeapVar(compiler, result, thisFunction, thisVar, false);
    count += end->setHeapVar(compiler, result, thisFunction, thisVar, false);
    auto thisFun = static_pointer_cast<CFunction>(thisFunction);
    thisFun->localVarsByName[varName] = _forVar;
    count += body->setHeapVar(compiler, result, thisFunction, thisVar, false);
    thisFun->localVarsByName.erase(varName);
    return count;
}

shared_ptr<CType> NFor::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, stringstream& trLine) {
    trBlock->variables[varName] = make_shared<TrVariable>(compiler->typeI32->nameRef, varName);
    auto trLoopEndVar = trBlock->createTempVariable("loopEnd", compiler->typeI32->nameValue);
    
    stringstream loopCounterLine;
    loopCounterLine << varName << " = ";
    auto loopCounterType = start->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, loopCounterLine);
    if (loopCounterType != compiler->typeI32) {
        result.addError(loc, CErrorCode::TypeMismatch, "start value must be a int");
        return nullptr;
    }
    trBlock->statements.push_back(loopCounterLine.str());
    
    stringstream loopEndLine;
    loopEndLine << trLoopEndVar->name << " = ";
    auto loopEndType = end->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, loopEndLine);
    if (loopEndType != compiler->typeI32) {
        result.addError(loc, CErrorCode::TypeMismatch, "end value must be a int");
        return nullptr;
    }
    trBlock->statements.push_back(loopEndLine.str());
    
    auto trForBlock = make_shared<TrBlock>();
    trForBlock->parent = trBlock;
	trForBlock->hasThis = trBlock->hasThis;
    stringstream whileLine;
    whileLine << "while (" << varName << " <= " << trLoopEndVar->name << ")";
    trBlock->statements.push_back(TrStatement(whileLine.str(), trForBlock));

    stringstream bodyLine;
    body->transpile(compiler, result, thisFunction, thisVar, trOutput, trForBlock.get(), bodyLine);
    trForBlock->statements.push_back(bodyLine.str());

    stringstream loopCounterIncLine;
    loopCounterIncLine << varName << "++";
    trForBlock->statements.push_back(loopCounterIncLine.str());

    return compiler->typeVoid;
}

//shared_ptr<ReturnValue> NFor::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    assert(compiler->state == CompilerState::Compile);
//    compiler->emitLocation(builder, &this->loc);
//    
//    // Emit the start code first, without 'variable' in scope.
//    auto startValue = start->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, RRT_Auto);
//    if (!startValue) {
//        return nullptr;
//    }
//    
//    assert(startValue->type == RVT_SIMPLE);
//    
//    if (!startValue->value->getType()->isIntegerTy(64)) {
//        result.addError(loc, CErrorCode::TypeMismatch, "start value must be a int");
//        return nullptr;
//    }
//    
//    // Compute the end condition.
//    auto endValue = end->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, RRT_Auto);
//    if (!endValue) {
//        return nullptr;
//    }
//    
//    assert(endValue->type == RVT_SIMPLE);
//    
//    if (!endValue->value->getType()->isIntegerTy(64)) {
//        result.addError(loc, CErrorCode::TypeMismatch, "end value must be a int");
//        return nullptr;
//    }
//    
//    auto loopBB = BasicBlock::Create(compiler->context, "loop");
//    auto afterBB = BasicBlock::Create(compiler->context, "afterloop");
//    
//    auto startCondition = builder->CreateICmpSLE(startValue->value, endValue->value);
//    builder->CreateCondBr(startCondition, loopBB, afterBB);
//
//    // Make the new basic block for the loop header, inserting after current
//    // block.
//    Function *TheFunction = builder->GetInsertBlock()->getParent();
//    BasicBlock *preheaderBB = builder->GetInsertBlock();
//    TheFunction->getBasicBlockList().push_back(loopBB);
//    
//    // Start insertion in LoopBB.
//    builder->SetInsertPoint(loopBB);
//    
//    // Start the PHI node with an entry for Start.
//    auto Variable = builder->CreatePHI(Type::getInt64Ty(compiler->context), 2, varName);
//    Variable->addIncoming(startValue->value, preheaderBB);
//    
//    // Within the loop, the variable is defined equal to the PHI node.  If it
//    // shadows an existing variable, we have to restore it, so save it now.
//    auto thisFun = static_pointer_cast<CFunction>(thisFunction);
//    if (thisFun->localVarsByName.find(varName) != thisFun->localVarsByName.end()) {
//        result.addError(loc, CErrorCode::InvalidVariable, "var '%s' already exists within function, must have a unique name", varName.c_str());
//        return nullptr;
//    }
//    
//    thisFun->localVarsByName[varName] = _forVar;
//    _forVar->value = Variable;
//    
//    // Emit the body of the loop.  This, like any other expr, can change the
//    // current BB.  Note that we ignore the value computed by the body, but don't
//    // allow an error.
//    auto bodyValue = body->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, RRT_Auto);
//    if (bodyValue) {
//        bodyValue->releaseIfNeeded(compiler, result, builder);
//    }
//    
//    // Emit the step value.
//    Value *StepVal = ConstantInt::get(compiler->context, APInt(64, 1));
//    Value *NextVar = builder->CreateAdd(Variable, StepVal, "nextvar");
//    
//    // Convert condition to a bool by comparing equal to 0.0.
//    auto endCondition = builder->CreateICmpSLT(Variable, endValue->value);
//    
//    // Create the "after loop" block and insert it.
//    BasicBlock *loopEndBB = builder->GetInsertBlock();
//    
//    // Insert the conditional branch into the end of LoopEndBB.
//    builder->CreateCondBr(endCondition, loopBB, afterBB);
//    
//    // Any new code will be inserted in AfterBB.
//    TheFunction->getBasicBlockList().push_back(afterBB);
//    builder->SetInsertPoint(afterBB);
//    
//    // Add a new entry to the PHI node for the backedge.
//    Variable->addIncoming(NextVar, loopEndBB);
//    
//    // Restore the unshadowed variable.
//    
//    thisFun->localVarsByName.erase(varName);
//    _forVar->value = nullptr;
//
//    // for expr always returns 0.0.
//    return nullptr;
//}

void NFor::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
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

