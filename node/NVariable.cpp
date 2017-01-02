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
    return getParentValue(compiler, result, loc, names, nullptr);
}

shared_ptr<CType> NVariable::getParentValue(Compiler* compiler, CResult& result, const CLoc& loc, const vector<string>& names, Value** value) {
    if (names.size() == 1 && names[0] == "this") {
        if (value) {
            *value = compiler->currentFunction->getThis();
        }
        return compiler->currentFunction->getThisType(compiler, result);
    }
    
    shared_ptr<CType> varType = nullptr;
    if (value) {
        *value = nullptr;
    }
    auto isFirst = true;
    for (auto name : names) {
        if (isFirst) {
            isFirst = false;
            if (name == "this") {
                varType = compiler->currentFunction->getThisType(compiler, result);
                if (value) {
                    *value = compiler->currentFunction->getThis();
                }
            } else {
                // Now we need to look up the parent chain
                auto cfunction = compiler->currentFunction;
                shared_ptr<CVar> cvar = nullptr;
                shared_ptr<CType> parentType = nullptr;
                Value* thisValue = nullptr;
                
                if (value) {
                    thisValue = compiler->currentFunction->getThis();
                }
                
                while (cfunction && !cvar) {
                    parentType = cfunction->getThisType(compiler, result);
                    if (parentType == nullptr) {
                        cfunction = nullptr;
                    } else {
                        cvar = cfunction->getCVariable(name);
                        if (!cvar) {
                            if (value) {
                                auto parentIndex = parentType->cfunction.lock()->getThisIndex("parent");
                                vector<Value*> v;
                                v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
                                v.push_back(ConstantInt::get(compiler->context, APInt(32, parentIndex)));
                                auto ptr = compiler->builder.CreateInBoundsGEP(parentType->llvmAllocType, thisValue, ArrayRef<Value *>(v), "paramPtr");
                                thisValue = compiler->builder.CreateLoad(ptr);
                            }
                            cfunction = shared_ptr<CFunction>(cfunction->parent);
                        }
                    }
                }
                
                if (cfunction == nullptr) {
                    result.addError(loc, CErrorCode::UnknownVariable, "cannot find var '%s'", name.c_str());
                    return nullptr;
                }
                
                varType = cvar->getType(compiler, result);
                if (value) {
                    auto ptr = cvar->getValue(compiler, result, thisValue);
                    *value = compiler->builder.CreateLoad(ptr);
                }
            }
        } else {
            auto it = varType->membersByName.find(name);
            if (it == varType->membersByName.end()) {
                result.addError(loc, CErrorCode::UnknownVariable, "cannot find var '%s'", name.c_str());
                return nullptr;
            }
            
            if (value) {
                auto varIndex = it->second.first;
                vector<Value*> v;
                v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
                v.push_back(ConstantInt::get(compiler->context, APInt(32, varIndex)));
                auto ptr = compiler->builder.CreateInBoundsGEP(varType->llvmAllocType, *value, ArrayRef<Value *>(v), "paramPtr");
                *value = compiler->builder.CreateLoad(ptr);
            }
            varType = it->second.second;
        }
    }
    
    return varType;
}

Value* NVariable::compile(Compiler* compiler, CResult& result) const {
    compiler->emitLocation(this);
    Value* value = nullptr;
    getParentValue(compiler, result, loc, names, &value);
    return value;
}
