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

void NVariable::fixVar(Compiler* compiler, CResult& result) {
    assert(compiler->state == CompilerState::FixVar);
    getParentValue(compiler, result, loc, names, nullptr);
}

shared_ptr<CType> NVariable::getReturnType(Compiler* compiler, CResult& result) const {
    assert(compiler->state >= CompilerState::FixVar);
    return getParentValue(compiler, result, loc, names, nullptr);
}

Value* NVariable::compile(Compiler* compiler, CResult& result) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    Value* value = nullptr;
    getParentValue(compiler, result, loc, names, &value);
    return value;
}

shared_ptr<CType> NVariable::getParentValue(Compiler* compiler, CResult& result, const CLoc& loc, const vector<string>& names, Value** value) {
    if (value) {
        *value = nullptr;
    }
    
    if (names.size() == 1 && names[0] == "this") {
        if (value) {
            *value = compiler->currentFunction->getThis();
        }
        
        return compiler->currentFunction->getThisType(compiler, result);
    }
    
    auto cfunction = compiler->currentFunction;
    shared_ptr<CType> ctype = nullptr;
    auto isFirst = true;
    for (auto name : names) {
        if (isFirst) {
            isFirst = false;
            if (name == "this") {
                ctype = compiler->currentFunction->getThisType(compiler, result);
                if (value) {
                    *value = compiler->currentFunction->getThis();
                }
            } else {
                // Now we need to look up the parent chain
                shared_ptr<CVar> cvar = nullptr;
                Value* thisValue = nullptr;
                
                if (value) {
                    thisValue = compiler->currentFunction->getThis();
                }
                
                while (cfunction && !cvar) {
                    cvar = cfunction->getCVar(name);
                    if (!cvar) {
                        if (value) {
                            auto thisType = cfunction->getThisType(compiler, result);
                            auto parentIndex = cfunction->getThisIndex("parent");
                            vector<Value*> v;
                            v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
                            v.push_back(ConstantInt::get(compiler->context, APInt(32, parentIndex)));
                            auto ptr = compiler->builder.CreateInBoundsGEP(thisType->llvmAllocType(compiler, result), thisValue, ArrayRef<Value *>(v), "paramPtr");
                            thisValue = compiler->builder.CreateLoad(ptr, "parent");
                        }
                        cfunction = shared_ptr<CFunction>(cfunction->parent);
                    }
                }
                
                if (cfunction == nullptr) {
                    result.addError(loc, CErrorCode::UnknownVariable, "cannot find var '%s'", name.c_str());
                    return nullptr;
                }
                
                if (cfunction != compiler->currentFunction && cvar->mode == CVarType::Local) {
                    cvar = cfunction->localVarToThisVar(compiler, static_pointer_cast<CLocalVar>(cvar));
                }
                
                auto cthisvar = static_pointer_cast<CFunctionVar>(cvar);
                ctype = cvar->getType(compiler, result);
                if (value) {
                    // local vars can only be accessed within their function
                    assert(cvar->mode != CVarType::Local || cfunction == compiler->currentFunction);
                    auto ptr = cvar->getValue(compiler, result, thisValue);
                    *value = compiler->builder.CreateLoad(ptr);
                }

                
                cfunction = cthisvar->getParentCFunction(compiler, result);
            }
        } else {
            auto cvar = cfunction->getCVar(name);
            if (!cvar) {
                result.addError(loc, CErrorCode::UnknownVariable, "cannot find var '%s'", name.c_str());
                return nullptr;
            }
            
            if (cvar->mode == CVarType::Local) {
                cvar = cfunction->localVarToThisVar(compiler, static_pointer_cast<CLocalVar>(cvar));
            }
            
            auto cthisvar = static_pointer_cast<CFunctionVar>(cvar);
            ctype = cthisvar->getType(compiler, result);
            if (value) {
                auto thisType = cfunction->getThisType(compiler, result);
                auto varIndex = cthisvar->index;
                vector<Value*> v;
                v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
                v.push_back(ConstantInt::get(compiler->context, APInt(32, varIndex)));
                auto ptr = compiler->builder.CreateInBoundsGEP(thisType->llvmAllocType(compiler, result), *value, ArrayRef<Value *>(v), name.c_str());
                *value = compiler->builder.CreateLoad(ptr);
            }
            
            cfunction = cthisvar->getParentCFunction(compiler, result);
        }
    }
    
    return ctype;
}

void NVariable::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NVariable'");
    dumpf(level, "name: '%s'", names[0].c_str());
}

