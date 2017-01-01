#include "Node.h"
#include <sstream>

NVariable::NVariable(CLoc loc, const char* name) : NBase(loc) {
    istringstream f(name);
    string s;
    while (getline(f, s, '.')) {
        names.push_back(s);
    }
}

NodeType NVariable::getNodeType() const {
    return NodeType_Variable;
}

shared_ptr<CType> NVariable::getReturnType(Compiler* compiler, CResult& result) const {
    if (names.size() == 1 && names[0] == "this") {
        return compiler->currentFunction->getThisType(compiler, result);
    }
    
    shared_ptr<CType> varType = nullptr;
    auto isFirst = true;
    for (auto name : names) {
        if (isFirst) {
            isFirst = false;
            if (name == "this") {
                varType = compiler->currentFunction->getThisType(compiler, result);
            } else {
                auto CVar = compiler->currentFunction->getCVariable(name);
                if (!CVar) {
                    result.addError(loc, CErrorCode::UnknownVariable, "cannot find var '%s'", name.c_str());
                    return nullptr;
                }
                varType = CVar->getType(compiler, result);
            }
        } else {
            auto it = varType->membersByName.find(name);
            if (it == varType->membersByName.end()) {
                result.addError(loc, CErrorCode::UnknownVariable, "cannot find var '%s'", name.c_str());
                return nullptr;
            }
            varType = it->second.second;
        }
    }

    return varType;
}

Value* NVariable::compile(Compiler* compiler, CResult& result) const {
    compiler->emitLocation(this);
    
    if (names.size() == 1 && names[0] == "this") {
        return compiler->currentFunction->getThis();
    }
    
    shared_ptr<CType> varType = nullptr;
    Value* value = nullptr;
    auto isFirst = true;
    for (auto name : names) {
        if (isFirst) {
            isFirst = false;
            if (name == "this") {
                varType = compiler->currentFunction->getThisType(compiler, result);
                value = compiler->currentFunction->getThis();
            } else {
                auto CVar = compiler->currentFunction->getCVariable(name);
                if (!CVar) {
                    result.addError(loc, CErrorCode::UnknownVariable, "cannot find var '%s'", name.c_str());
                    return nullptr;
                }
                varType = CVar->getType(compiler, result);
                auto ptr = CVar->getValue(compiler, result);
                value = compiler->builder.CreateLoad(ptr);
            }
        } else {
            auto it = varType->membersByName.find(name);
            if (it == varType->membersByName.end()) {
                result.addError(loc, CErrorCode::UnknownVariable, "cannot find var '%s'", name.c_str());
                return nullptr;
            }
            
            auto structIndex = it->second.first;
            vector<Value*> v;
            v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
            v.push_back(ConstantInt::get(compiler->context, APInt(32, structIndex)));
            auto ptr = compiler->builder.CreateInBoundsGEP(varType->llvmAllocType, value, ArrayRef<Value *>(v), "paramPtr");
            
            varType = it->second.second;
            value = compiler->builder.CreateLoad(ptr);
        }
    }
    
    return value;
}
