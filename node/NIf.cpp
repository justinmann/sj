#include "Node.h"

NodeType NIf::getNodeType() const {
    return NodeType_If;
}

void NIf::define(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    condition->define(compiler, result, thisFunction);

    if (elseBlock) {
        elseBlock->define(compiler, result, thisFunction);
    }
    
    if (ifBlock) {
        ifBlock->define(compiler, result, thisFunction);
    }
}

void NIf::fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    condition->fixVar(compiler, result, thisFunction);
    
    if (elseBlock) {
        elseBlock->fixVar(compiler, result, thisFunction);
    }

    if (ifBlock) {
        ifBlock->fixVar(compiler, result, thisFunction);
    }
}

shared_ptr<CType> NIf::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    if (elseBlock) {
        return elseBlock->getReturnType(compiler, result, thisFunction);
    }
    
    if (ifBlock) {
        return ifBlock->getReturnType(compiler, result, thisFunction);
    }

    return nullptr;
}

Value* NIf::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    shared_ptr<CType> returnType = getReturnType(compiler, result, thisFunction);
    
    Function *function = builder->GetInsertBlock()->getParent();
    auto ifBB = BasicBlock::Create(compiler->context);
    auto elseBB = BasicBlock::Create(compiler->context);
    auto mergeBB = BasicBlock::Create(compiler->context);
    
    // If block
    function->getBasicBlockList().push_back(ifBB);
    auto c = condition->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
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
        elseValue = compiler->getDefaultValue(returnType);
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

