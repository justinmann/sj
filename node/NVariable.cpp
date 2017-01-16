#include "Node.h"
#include <sstream>

NVariable::NVariable(CLoc loc, const char* name) : NBase(loc) {
    fullName = name;
    
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
    getParentValue(compiler, result, loc, thisFunction, nullptr, nullptr, names, VT_LOAD, nullptr);
}

shared_ptr<CType> NVariable::getReturnType(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction) const {
    assert(compiler->state >= CompilerState::FixVar);
    auto cvar = getParentValue(compiler, result, loc, thisFunction, nullptr, nullptr, names, VT_LOAD, nullptr);
    if (!cvar) {
        return nullptr;
    }
    return cvar->getType(compiler, result);
}

Value* NVariable::compile(Compiler* compiler, CResult& result, shared_ptr<CFunction> thisFunction, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB) const {
    assert(compiler->state == CompilerState::Compile);
    compiler->emitLocation(this);
    Value* value = nullptr;
    getParentValue(compiler, result, loc, thisFunction, thisValue, builder, names, VT_LOAD, &value);
    return value;
}

shared_ptr<CVar> NVariable::getParentValue(Compiler* compiler, CResult& result, const CLoc& loc, shared_ptr<CFunction> thisFunction, Value* thisValue22, IRBuilder<>* builder, const vector<string>& names, ValueType vt, Value** value) {
    if (value) {
        *value = nullptr;
    }
    
    if (names.size() == 1 && names[0] == "this") {
        if (value) {
            *value = thisValue22;
        }
        
        return CThisVar::create(thisFunction);
    }
    
    auto cfunction = thisFunction;
    shared_ptr<CVar> cvarResult = nullptr;
    auto isFirst = true;
    for (auto name : names) {
        auto isLast = name == names.back();
        if (isFirst) {
            isFirst = false;
            if (name == "this") {
                if (value) {
                    if (vt == VT_STORE) {
                        result.addError(loc, CErrorCode::ImmutableAssignment, "cannot store value in this");
                        return nullptr;
                    }
                    *value = thisValue22;
                }
                
                cvarResult = CThisVar::create(thisFunction);
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
                            auto hasParent = cfunction->getHasParent(compiler, result);
                            if (!hasParent) {
                                cfunction = nullptr;
                            } else {
                                auto ptr = cfunction->getParentPointer(compiler, result, builder, thisValue);
                                thisValue = builder->CreateLoad(ptr, "parent");
                            }
                        }
                        
                        if (cfunction) {
                            cfunction = cfunction->parent.lock();
                        }
                    }
                }
                
                if (cfunction == nullptr) {
                    return nullptr;
                }
                
                if (cfunction != thisFunction && cvar->mode == CVarType::Local) {
                    cvar = cfunction->localVarToThisVar(compiler, static_pointer_cast<CLocalVar>(cvar));
                }
                
                auto cthisvar = static_pointer_cast<CFunctionVar>(cvar);
                if (value) {
                    // local vars can only be accessed within their function
                    assert(cvar->mode != CVarType::Local || cfunction == thisFunction);
                    
                    if (vt == VT_LOAD || !isLast) {
                        *value = cvar->getLoadValue(compiler, result, thisValue, builder);
                    } else {
                        *value = cvar->getStoreValue(compiler, result, thisValue, builder);
                    }
                }

                cfunction = cthisvar->getCFunctionForValue(compiler, result);
                cvarResult = cthisvar;
            }
        } else {
            auto cvar = cfunction->getCVar(name);
            if (!cvar) {
                return nullptr;
            }
            
            if (cvar->mode == CVarType::Local) {
                cvar = cfunction->localVarToThisVar(compiler, static_pointer_cast<CLocalVar>(cvar));
            }
            
            auto cthisvar = static_pointer_cast<CFunctionVar>(cvar);
            if (value) {
                if (vt == VT_LOAD || !isLast) {
                    *value = cthisvar->getLoadValue(compiler, result, *value, builder);
                } else {
                    *value = cthisvar->getStoreValue(compiler, result, *value, builder);
                }
            }
            
            cfunction = cthisvar->getCFunctionForValue(compiler, result);
            cvarResult = cthisvar;
        }
    }
    
    return cvarResult;
}

void NVariable::dump(Compiler* compiler, int level) const {
    dumpf(level, "type: 'NVariable'");
    dumpf(level, "name: '%s'", fullName.c_str());
}

