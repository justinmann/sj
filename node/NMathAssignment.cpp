#include "Node.h"

NMathAssignment::NMathAssignment(CLoc loc, const char* name, NMathAssignmentOp op, shared_ptr<NBase> rightSide) : op(op), rightSide(rightSide), NBase(loc) {
    fullName = name;

    istringstream f(name);
    string s;
    while (getline(f, s, '.')) {
        names.push_back(s);
    }
}

NodeType NMathAssignment::getNodeType() const {
    return NodeType_MathAssignment;
}

void NMathAssignment::define(Compiler* compiler, CResult& result, shared_ptr<CFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    if (rightSide) {
        rightSide->define(compiler, result, thisFunction);
    }
}

void NMathAssignment::fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    if (rightSide) {
        rightSide->fixVar(compiler, result, thisFunction);
    }
}

shared_ptr<CType> NMathAssignment::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    auto cvar = NVariable::getParentValue(compiler, result, loc, thisFunction, nullptr, nullptr, names, VT_STORE, nullptr);
    auto ctype = cvar->getType(compiler, result);
    if (ctype != compiler->typeInt) {
        result.addError(loc, CErrorCode::TypeMismatch, "operation only valid on int");
        return nullptr;
    }
    return ctype;
}

Value* NMathAssignment::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    
    Value* destValue = nullptr;
    auto cvar = NVariable::getParentValue(compiler, result, loc, thisFunction, thisValue, builder, names, VT_STORE, &destValue);
    if (!cvar) {
        result.addError(loc, CErrorCode::InvalidVariable, "cannot find var '%s'", fullName.c_str());
        return nullptr;
    }
    
    if (!cvar->isMutable) {
        result.addError(loc, CErrorCode::ImmutableAssignment, "invalid on immutable variable", fullName.c_str());
        return nullptr;
    }
    
    Value* leftValue = builder->CreateLoad(destValue);
    
    // Compute value
    Value *rightValue = nullptr;
    if (rightSide) {
        rightValue = rightSide->compile(compiler, result, thisFunction, thisValue, builder, catchBB);
    }

    Value* resultValue = nullptr;
    switch (op) {
        case NMAO_Add:
            if (!rightValue) {
                result.addError(loc, CErrorCode::ExpressionEmpty, "add by an empty value");
                return nullptr;
            }
            
            if (!rightValue->getType()->isIntegerTy(64)) {
                result.addError(loc, CErrorCode::TypeMismatch, "can only add by int");
                return nullptr;
            }
            
            resultValue = builder->CreateAdd(leftValue, rightValue);
            break;
        case NMAO_Sub:
            if (!rightValue) {
                result.addError(loc, CErrorCode::ExpressionEmpty, "add by an empty value");
                return nullptr;
            }
            
            if (!rightValue->getType()->isIntegerTy(64)) {
                result.addError(loc, CErrorCode::TypeMismatch, "can only add by int");
                return nullptr;
            }
            
            resultValue = builder->CreateSub(leftValue, rightValue);
            break;
        case NMAO_Inc:
            resultValue = builder->CreateAdd(leftValue, ConstantInt::get(compiler->context, APInt(64, 1)));
            break;
        case NMAO_Dec:
            resultValue = builder->CreateSub(leftValue, ConstantInt::get(compiler->context, APInt(64, 1)));
            break;
    }

    // Store value
    builder->CreateStore(resultValue, destValue);
    return resultValue;
}

void NMathAssignment::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NMathAssignment'");
    dumpf(level, "name: %s", fullName.c_str());
    dumpf(level, "op: %d", op);
    
    if (rightSide) {
        dumpf(level, "rightSide: {");
        rightSide->dump(compiler, level + 1);
        dumpf(level, "}");
    }
}
