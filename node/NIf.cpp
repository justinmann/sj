#include "Node.h"

NodeType NIf::getNodeType() const {
    return NodeType_If;
}

void NIf::define(Compiler* compiler, CResult& result) {
    assert(compiler->state == CompilerState::Define);
    condition->define(compiler, result);

    if (elseBlock) {
        elseBlock->define(compiler, result);
    }
    
    if (ifBlock) {
        ifBlock->define(compiler, result);
    }
}

void NIf::fixVar(Compiler* compiler, CResult& result) {
    assert(compiler->state == CompilerState::FixVar);
    condition->fixVar(compiler, result);
    
    if (elseBlock) {
        elseBlock->fixVar(compiler, result);
    }

    if (ifBlock) {
        ifBlock->fixVar(compiler, result);
    }
}

shared_ptr<CType> NIf::getReturnType(Compiler* compiler, CResult& result) const {
    assert(compiler->state >= CompilerState::FixVar);
    if (elseBlock) {
        return elseBlock->getReturnType(compiler, result);
    }
    
    if (ifBlock) {
        return ifBlock->getReturnType(compiler, result);
    }

    return nullptr;
}

Value* NIf::compile(Compiler* compiler, CResult& result) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    shared_ptr<CType> returnType = getReturnType(compiler, result);
    
    Function *function = compiler->builder.GetInsertBlock()->getParent();
    auto ifBB = BasicBlock::Create(compiler->context);
    auto elseBB = BasicBlock::Create(compiler->context);
    auto mergeBB = BasicBlock::Create(compiler->context);
    
    // If block
    function->getBasicBlockList().push_back(ifBB);
    auto c = condition->compile(compiler, result);
    compiler->builder.CreateCondBr(c, ifBB, elseBB);
    compiler->builder.SetInsertPoint(ifBB);
    auto ifValue = ifBlock->compile(compiler, result);
    if (returnType != compiler->typeVoid && !ifValue) {
        result.errors.push_back(CError(loc, CErrorCode::NoDefaultValue, "type does not have a default value"));
        return nullptr;
    }
    compiler->builder.CreateBr(mergeBB);
    
    // Else block
    function->getBasicBlockList().push_back(elseBB);
    compiler->builder.SetInsertPoint(elseBB);
    Value* elseValue = nullptr;
    if (elseBlock) {
        elseValue = elseBlock->compile(compiler, result);
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
    compiler->builder.CreateBr(mergeBB);
    
    // Merge block
    function->getBasicBlockList().push_back(mergeBB);
    compiler->builder.SetInsertPoint(mergeBB);
    if (returnType == compiler->typeVoid) {
        return nullptr;
    }
    
    if (ifValue->getType() != elseValue->getType()) {
        result.errors.push_back(CError(loc, CErrorCode::TypeMismatch, "if and else clause have different return types"));
        return nullptr;
    }
    
    auto phiNode = compiler->builder.CreatePHI(returnType->llvmRefType(compiler, result), (unsigned)2, "iftmp");
    phiNode->addIncoming(ifValue, ifBB);
    phiNode->addIncoming(elseValue, elseBB);
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

