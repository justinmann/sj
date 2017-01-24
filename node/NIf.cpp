#include "Node.h"

shared_ptr<CIfElseVar> CIfElseVar::create(const CLoc& loc_, shared_ptr<CFunction> thisFunction_, shared_ptr<NBase> condition_, shared_ptr<NBase> ifBlock_, shared_ptr<NBase> elseBlock_) {
    auto c = make_shared<CIfElseVar>();
    c->name = "";
    c->mode = Private;
    c->isMutable = true;
    c->nassignment = nullptr;
    c->loc = loc_;
    c->thisFunction = thisFunction_;
    c->condition = condition_;
    c->ifBlock = ifBlock_;
    c->elseBlock = elseBlock_;
    return c;
}

shared_ptr<CType> CIfElseVar::getType(Compiler* compiler, CResult& result) {
    if (elseBlock) {
        return elseBlock->getType(compiler, result, thisFunction);
    }
    
    if (ifBlock) {
        return ifBlock->getType(compiler, result, thisFunction);
    }
    
    return nullptr;
}

Value* CIfElseVar::getLoadValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(compiler->state == CompilerState::Compile);
    shared_ptr<CType> returnType = getType(compiler, result);
    
    Function *function = builder->GetInsertBlock()->getParent();
    auto ifBB = BasicBlock::Create(compiler->context);
    auto elseBB = BasicBlock::Create(compiler->context);
    auto mergeBB = BasicBlock::Create(compiler->context);
    
    // If block
    function->getBasicBlockList().push_back(ifBB);
    auto c = condition->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    if (!c) {
        return nullptr;
    }
    builder->CreateCondBr(c, ifBB, elseBB);
    builder->SetInsertPoint(ifBB);
    auto ifValue = ifBlock->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    if (returnType != compiler->typeVoid && !ifValue) {
        result.errors.push_back(CError(loc, CErrorCode::NoDefaultValue, "type does not have a default value"));
        return nullptr;
    }
    auto ifEndBB = builder->GetInsertBlock();
    builder->CreateBr(mergeBB);
    
    // Else block
    function->getBasicBlockList().push_back(elseBB);
    builder->SetInsertPoint(elseBB);
    Value* elseValue = nullptr;
    if (elseBlock) {
        elseValue = elseBlock->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
        if (returnType != compiler->typeVoid && !elseValue) {
            result.errors.push_back(CError(loc, CErrorCode::NoDefaultValue, "type does not have a default value"));
            return nullptr;
        }
    } else if (returnType != compiler->typeVoid) {
        elseValue = returnType->getDefaultValue(compiler, result, thisFunction, thisValue, builder, catchBB);
        if (!elseValue) {
            result.errors.push_back(CError(loc, CErrorCode::NoDefaultValue, "type does not have a default value"));
            return nullptr;
        }
    }
    
    auto elseEndBB = builder->GetInsertBlock();
    builder->CreateBr(mergeBB);
    
    // Merge block
    function->getBasicBlockList().push_back(mergeBB);
    builder->SetInsertPoint(mergeBB);
    if (returnType == compiler->typeVoid) {
        return nullptr;
    }
    
    if (ifValue->getType() != elseValue->getType()) {
        result.errors.push_back(CError(loc, CErrorCode::TypeMismatch, "if and else clause have different return types"));
        return nullptr;
    }
    
    auto phiNode = builder->CreatePHI(returnType->llvmRefType(compiler, result), (unsigned)2, "iftmp");
    phiNode->addIncoming(ifValue, ifEndBB);
    phiNode->addIncoming(elseValue, elseEndBB);
    return phiNode;
}

Value* CIfElseVar::getStoreValue(Compiler* compiler, CResult& result, Value* thisValue, Value* dotValue, IRBuilder<>* builder, BasicBlock* catchBB) {
    assert(false);
    return nullptr;
}

string CIfElseVar::fullName() {
    return "";
}

void NIf::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    condition->define(compiler, result, thisFunction);

    if (elseBlock) {
        elseBlock->define(compiler, result, thisFunction);
    }
    
    if (ifBlock) {
        ifBlock->define(compiler, result, thisFunction);
    }
}

shared_ptr<CVar> NIf::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, shared_ptr<CVar> dotVar) {
    assert(compiler->state == CompilerState::FixVar);
    condition->getVar(compiler, result, thisFunction);
    
    if (elseBlock) {
        elseBlock->getVar(compiler, result, thisFunction);
    }
    
    if (ifBlock) {
        ifBlock->getVar(compiler, result, thisFunction);
    }
    
    return CIfElseVar::create(loc, thisFunction, condition, ifBlock, elseBlock);
}

void NIf::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NIf'");
    
    if (condition) {
        dumpf(level, "condition: {");
        condition->dump(compiler, level + 1);
        dumpf(level, "}");
    }

    if (ifBlock) {
        dumpf(level, "if: {");
        ifBlock->dump(compiler, level + 1);
        dumpf(level, "}");
    }

    if (elseBlock) {
        dumpf(level, "else: {");
        elseBlock->dump(compiler, level + 1);
        dumpf(level, "}");
    }
}

