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

void NVariable::fixVar(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) {
    assert(compiler->state == CompilerState::FixVar);
    getParentValue(compiler, result, loc, thisFunction, nullptr, nullptr, names, nullptr);
}

shared_ptr<CType> NVariable::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    return getParentValue(compiler, result, loc, thisFunction, nullptr, nullptr, names, nullptr);
}

Value* NVariable::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    Value* value = nullptr;
    getParentValue(compiler, result, loc, thisFunction, thisValue, builder, names, &value);
    return value;
}

shared_ptr<CType> NVariable::getParentValue(Compiler* compiler, CResult& result, const CLoc& loc, shared_ptr<CFunction> thisFunction, Value* thisValue22, IRBuilder<>* builder, const vector<string>& names, Value** value) {
    if (value) {
        *value = nullptr;
    }
    
    if (names.size() == 1 && names[0] == "this") {
        if (value) {
            *value = thisValue22;
        }
        
        return thisFunction->getThisType(compiler, result);
    }
    
    auto cfunction = thisFunction;
    shared_ptr<CType> ctype = nullptr;
    auto isFirst = true;
    for (auto name : names) {
        if (isFirst) {
            isFirst = false;
            if (name == "this") {
                ctype = thisFunction->getThisType(compiler, result);
                if (value) {
                    *value = thisValue22;
                }
            } else {
                // Now we need to look up the parent chain
                shared_ptr<CVar> cvar = nullptr;
                Value* thisValue = nullptr;
                
                if (value) {
                    thisValue = thisValue22;
                }
                
                while (cfunction && !cvar) {
                    cvar = cfunction->getCVar(name);
                    if (!cvar) {
                        if (value) {
                            auto thisType = cfunction->getThisType(compiler, result);
                            auto parentIndex = cfunction->getThisIndex("parent");
                            if (parentIndex == -1) {
                                cfunction = nullptr;
                            } else {
                                vector<Value*> v;
                                v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
                                v.push_back(ConstantInt::get(compiler->context, APInt(32, parentIndex)));
                                auto llvmAllocType = thisType->llvmAllocType(compiler, result);
                                auto thisValueType = thisValue->getType();
                                assert(thisValueType == llvmAllocType->getPointerTo());
                                auto ptr = builder->CreateInBoundsGEP(llvmAllocType, thisValue, ArrayRef<Value *>(v), "paramPtr");
                                thisValue = builder->CreateLoad(ptr, "parent");
                            }
                        }
                        
                        if (cfunction) {
                            cfunction = cfunction->parent.lock();
                        }
                    }
                }
                
                if (cfunction == nullptr) {
                    result.addError(loc, CErrorCode::UnknownVariable, "cannot find var '%s'", name.c_str());
                    return nullptr;
                }
                
                if (cfunction != thisFunction && cvar->mode == CVarType::Local) {
                    cvar = cfunction->localVarToThisVar(compiler, static_pointer_cast<CLocalVar>(cvar));
                }
                
                auto cthisvar = static_pointer_cast<CFunctionVar>(cvar);
                ctype = cvar->getType(compiler, result);
                if (value) {
                    // local vars can only be accessed within their function
                    assert(cvar->mode != CVarType::Local || cfunction == thisFunction);
                    auto ptr = cvar->getValue(compiler, result, thisValue, builder);
                    *value = builder->CreateLoad(ptr);
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
                auto ptr = builder->CreateInBoundsGEP(thisType->llvmAllocType(compiler, result), *value, ArrayRef<Value *>(v), name.c_str());
                *value = builder->CreateLoad(ptr);
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

