//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "Node.h"

shared_ptr<CFunctionVar> CFunctionVar::create(const string& name, shared_ptr<CFunction> parent, shared_ptr<NFunction> nfunction, int index, shared_ptr<NAssignment> nassignment, shared_ptr<CType> type) {
    auto c = make_shared<CFunctionVar>();
    c->mode = CVarType::Public;
    c->name = name;
    c->nfunction = nfunction;
    c->index = index;
    c->nassignment = nassignment;
    c->parent = parent;
    c->type = type;
    return c;
}

shared_ptr<CType> CFunctionVar::getType(Compiler* compiler, CResult& result) {
    if (isInGetType) {
        result.errors.push_back(CError(CLoc::undefined, CErrorCode::TypeLoop));
        return nullptr;
    }
    
    isInGetType = true;
    if (!type) {
        auto t = compiler->currentFunction;
        compiler->currentFunction = parent.lock();
        
        type = nassignment->getReturnType(compiler, result);
        
        compiler->currentFunction = t;
    }
    isInGetType = false;
    return type;
}

Value* CFunctionVar::getValue(Compiler* compiler, CResult& result, Value* thisValue) {
    return parent.lock()->getArgumentValue(compiler, result, thisValue, index);
}

shared_ptr<CFunction> CFunctionVar::getParentCFunction(Compiler* compiler, CResult& result) {
    auto ctype = getType(compiler, result);
    if (ctype && !ctype->cfunction.expired()) {
        return ctype->cfunction.lock();
    }
    return nullptr;
}

shared_ptr<CFunction> CFunction::create(Compiler* compiler, CResult& result, shared_ptr<CFunction> parent, const string& name, shared_ptr<NFunction> node) {
    auto c = make_shared<CFunction>();
    c->parent = parent;
    c->name = name;
    c->node = node;
    
    if (node) {
        for (auto it : node->assignments) {
            int index = (int)c->thisVars.size();
            auto thisVar = CFunctionVar::create(it->name, c, node, index, it, nullptr);
            c->thisVarsByName[it->name] = pair<int, shared_ptr<CFunctionVar>>(index, thisVar);
            c->thisVars.push_back(thisVar);
        }
        
        if (parent) {
            auto parentType = parent->getThisType(compiler, result);
            if (parentType) {
                int index = (int)c->thisVars.size();
                auto parentVar = CFunctionVar::create("parent", c, node, index, nullptr, parentType);
                c->thisVarsByName[parentVar->name] = pair<int, shared_ptr<CFunctionVar>>(index, parentVar);
                c->thisVars.push_back(parentVar);
            }
        }
        
        for (auto it : node->functions) {
            c->funcsByName[it->name] = CFunction::create(compiler, result, c, it->name, it);
        }
    }
    return c;
}

shared_ptr<CType> CFunction::getReturnType(Compiler* compiler, CResult& result) {
    if (isInGetType) {
        result.errors.push_back(CError(CLoc::undefined, CErrorCode::TypeLoop));
        return nullptr;
    }
    
    isInGetType = true;
    if (!returnType) {
        returnType = shared_ptr<CType>(node->getBlockType(compiler, result));
    }
    isInGetType = false;
    return returnType;
}

shared_ptr<CType> CFunction::getThisType(Compiler* compiler, CResult& result) {
    if (!thisType && node != nullptr) {
        thisType = make_shared<CType>(compiler, node->name.c_str(), shared_from_this());
    }
    return thisType;
}

Function* CFunction::getFunction(Compiler* compiler, CResult& result) {
    if (isInGetFunction) {
        result.errors.push_back(CError(CLoc::undefined, CErrorCode::TypeLoop));
        return nullptr;
    }
    
    isInGetFunction = true;
    if (!func) {
        auto returnType = getReturnType(compiler, result);
        if (returnType) {
            vector<Type*> argTypes;
            argTypes.push_back(getThisType(compiler, result)->llvmRefType(compiler, result));
            FunctionType *FT = FunctionType::get(returnType->llvmRefType(compiler, result), argTypes, false);
            func = Function::Create(FT, Function::ExternalLinkage, node->name.c_str(), compiler->module.get());
            func->args().begin()->setName("this");
            
            // Create a new basic block to start insertion into.
            basicBlock = BasicBlock::Create(compiler->context, "entry", func);
            auto prevInsertPoint = compiler->builder.saveIP();
            compiler->builder.SetInsertPoint(basicBlock);
            
    #ifdef DWARF_ENABLED
            SmallVector<Metadata *, 8> EltTys;
            for (auto &argType : argTypes) {
                EltTys.push_back(compiler->getDIType(argType));
            }
            auto ditypes = compiler->DBuilder->createSubroutineType(compiler->DBuilder->getOrCreateTypeArray(EltTys));
            
            // Create a subprogram DIE for this function.
            DIFile *Unit = compiler->DBuilder->createFile(compiler->TheCU->getFilename(), compiler->TheCU->getDirectory());
            DIScope *FContext = Unit;
            unsigned LineNo = node->loc.line;
            unsigned ScopeLine = LineNo;
            DISubprogram *SP = compiler->DBuilder->createFunction(FContext, node->name.c_str(), StringRef(), Unit, LineNo, ditypes, false /* internal linkage */, true /* definition */, ScopeLine, DINode::FlagPrototyped, false);
            func->setSubprogram(SP);
            
            // Push the current scope.
            compiler->LexicalBlocks.push_back(SP);
            
            // Unset the location for the prologue emission (leading instructions with no
            // location in a function are considered part of the prologue and the debugger
            // will run past them when breaking on a function)
            compiler->emitLocation(nullptr);
    #endif

            compiler->builder.restoreIP(prevInsertPoint);
        }
    }
    isInGetFunction = false;
   
    return func;
}

BasicBlock* CFunction::getBasicBlock() {
    assert(func != nullptr);
    return basicBlock;
}

Argument* CFunction::getThis() {
    assert(func != nullptr);
    return (Argument*)func->args().begin();
}

Value* CFunction::getArgumentValue(Compiler* compiler, CResult& result, Value* thisValue, int index) {
    assert(thisValue->getType() == thisType->llvmRefType(compiler, result));
    vector<Value*> v;
    v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
    v.push_back(ConstantInt::get(compiler->context, APInt(32, index)));
    auto paramPtr = compiler->builder.CreateInBoundsGEP(thisType->llvmAllocType(compiler, result), thisValue, ArrayRef<Value *>(v), "paramPtr");
    return paramPtr;
}


shared_ptr<CFunction> CFunction::getCFunction(const string& name) const {
    auto t = funcsByName.find(name);
    if (t != funcsByName.end()) {
        return t->second;
    }
    return nullptr;
}

shared_ptr<CVar> CFunction::getCVar(const string& name) const {
    auto t1 = localVarsByName.find(name);
    if (t1 != localVarsByName.end()) {
        return t1->second;
    }

    auto t2 = thisVarsByName.find(name);
    if (t2 != thisVarsByName.end()) {
        return t2->second.second;
    }
    
    return nullptr;
}

int CFunction::getThisIndex(const string& name) const {
    auto it = thisVarsByName.find(name);
    if (it != thisVarsByName.end()) {
        return it->second.first;
    }
    return -1;
}

shared_ptr<CFunctionVar> CFunction::localVarToThisVar(Compiler* compiler, shared_ptr<CLocalVar> localVar) {
    assert(compiler->state <= CompilerState::FixVar); // Cannot change vars after type has been created
    assert(localVar->mode == CVarType::Local);
    
    auto pos = localVarsByName.end();
    for (auto it = localVarsByName.begin(); it != localVarsByName.end(); it++) {
        if (it->second == localVar) {
            pos = it;
            break;
        }
    }
    
    if (pos == localVarsByName.end()) {
        assert(false);
        return nullptr;
    }
    
    
    auto thisVar = CFunctionVar::create(localVar->name, shared_from_this(), node, (int)thisVars.size(), localVar->nassignment, nullptr);
    int index = (int)thisVars.size();
    thisVars.push_back(thisVar);
    thisVarsByName[pos->first] = pair<int, shared_ptr<CFunctionVar>>(index, thisVar);
    localVarsByName.erase(pos);
    
    return thisVar;
}

string CFunction::fullName() {
    string n = name;
    auto p = parent;
    while (!p.expired() && !p.lock()->parent.expired()) {
        n.insert(0, ".");
        n.insert(0, p.lock()->name);
        p = p.lock()->parent;
    }
    return n;
}

void CFunction::dump(Compiler* compiler, CResult& result, int level) {
    // Skip if this is the function around global
    if (!parent.expired()) {
        dumpf(level, "%s: {", fullName().c_str());
        
        if ((thisVarsByName.size() > 1) || (thisVarsByName.size() > 0 && thisVarsByName.find("parent") == thisVarsByName.end())) {
            dumpf(level + 1, "thisVars: {");
            for (auto it : thisVarsByName) {
                if (it.first == "parent")
                    continue;
                
                auto ctype = it.second.second->getType(compiler, result);
                dumpf(level + 2, "%s: '%s'", it.second.second->name.c_str(), ctype ? ctype->name.c_str() : "undefined");
            }
            dumpf(level + 1, "}");
        }

        if (localVarsByName.size() > 0) {
            dumpf(level + 1, "localVars: {");
            for (auto it : localVarsByName) {
                auto ctype = it.second->getType(compiler, result);
                dumpf(level + 2, "%s: '%s'", it.second->name.c_str(), ctype ? ctype->name.c_str() : "undefined");
            }
            dumpf(level + 1, "}");
        }
        
        dumpf(level, "}");
        dumpf(level, "");
    }
    
    if (funcsByName.size() > 0) {
        for (auto it : funcsByName) {
            it.second->dump(compiler, result, level);
        }
    }    
}


