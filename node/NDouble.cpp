#include "Node.h"

NodeType NDouble::getNodeType() const {
    return NodeType_Double;
}

shared_ptr<CType> NDouble::getReturnType(Compiler* compiler, CResult& result) const {
    return compiler->typeFloat;
}

Value* NDouble::compile(Compiler* compiler, CResult& result) const {
    compiler->emitLocation(this);

    char* e;
    auto t = strtod(value.c_str(), &e);
    if (*e != '\0') {
        result.errors.push_back(CError(loc, CErrorCode::InvalidNumber));
        return nullptr;
    }
    
    return ConstantFP::get(compiler->context, APFloat(t));
}
