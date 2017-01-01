#include "Node.h"

NodeType NBool::getNodeType() const {
    return NodeType_Bool;
}

shared_ptr<CType> NBool::getReturnType(Compiler* compiler, CResult& result) const {
    return compiler->typeBool;
}

Value* NBool::compile(Compiler* compiler, CResult& result) const {
    compiler->emitLocation(this);
    return ConstantInt::get(compiler->context, APInt(1, value));
}
