//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "Node.h"

shared_ptr<CType> CFunctionVar::getType(Compiler* compiler, CResult& result) {
    if (isInGetType) {
        result.errors.push_back(CError(CLoc::undefined, CErrorCode::TypeLoop));
        return nullptr;
    }
    
    isInGetType = true;
    if (!type) {
        type = nassignment->getReturnType(compiler, result);
    }
    isInGetType = false;
    return type;
}

Value* CFunctionVar::getValue(Compiler* compiler, CResult& result) {
    if (!value) {
        value = parent->getArgumentValue(index, compiler);
    }
    return value;
}

CFunction::CFunction(CFunction* parent, const NFunction* node) : parent(parent), node(node), returnType(nullptr), thisType(nullptr), func(nullptr), isInGetType(false), isInGeCFunction(false) {
    if (node) {
        int index = 0;
        for (auto &arg : node->assignments) {
            if (arg->getNodeType() == NodeType_Assignment) {
                auto t = (const NAssignment*)arg.get();
                vars[t->name] = shared_ptr<CVar>((CVar*)new CFunctionVar(this, node, index, t));
            }
            index++;
        }
    }
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
    if (!thisType) {
        // Verify all arguments are assignments with valid types
        vector<pair<string, shared_ptr<CType>>> memberTypes;
        for (auto &it : node->assignments) {
            if (it->getNodeType() != NodeType_Assignment) {
                result.errors.push_back(CError(CLoc::undefined, CErrorCode::NotVariable));
                return nullptr;
            }
            auto t = (const NAssignment*)it.get();
            
            auto memberType = t->getReturnType(compiler, result);
            if (!memberType) {
                assert(false);
                return nullptr;
            }
            memberTypes.push_back(pair<string, shared_ptr<CType>>(t->name, shared_ptr<CType>(memberType)));
        }
        
        thisType = make_shared<CType>(compiler, node->name.c_str(), memberTypes);
    }
    return thisType;
}

Function* CFunction::geCFunction(Compiler* compiler, CResult& result) {
    if (isInGeCFunction) {
        result.errors.push_back(CError(CLoc::undefined, CErrorCode::TypeLoop));
        return nullptr;
    }
    
    isInGeCFunction = true;
    if (!func) {
        auto returnType = getReturnType(compiler, result);
        if (returnType) {
            vector<Type*> argTypes;
            argTypes.push_back(getThisType(compiler, result)->llvmRefType);
            FunctionType *FT = FunctionType::get(returnType->llvmRefType, argTypes, false);
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
            DISubprogram *SP = compiler->DBuilder->createFunction(FContext, node->name.c_str(), StringRef(), Unit, LineNo,
                                                                  ditypes, false /* internal linkage */, true /* definition */, ScopeLine,
                                                                  DINode::FlagPrototyped, false);
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
    isInGeCFunction = false;
   
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

Value* CFunction::getArgumentValue(int index, Compiler* compiler) {
    assert(func != nullptr);
    auto thisValue = getThis();
    vector<Value*> v;
    v.push_back(ConstantInt::get(compiler->context, APInt(32, 0)));
    v.push_back(ConstantInt::get(compiler->context, APInt(32, index)));
    auto paramPtr = compiler->builder.CreateInBoundsGEP(thisType->llvmAllocType, thisValue, ArrayRef<Value *>(v), "paramPtr");
    return paramPtr;
}


CFunction* CFunction::getCFunction(const string& name) const {
    auto t = funcs.find(name);
    if (t != funcs.end()) {
        return t->second.get();
    }
    if (parent) {
        return parent->getCFunction(name);
    }
    return nullptr;
}

CVar* CFunction::getCVariable(const string& name) const {
    auto t = vars.find(name);
    if (t != vars.end()) {
        return t->second.get();
    }
    if (parent) {
        return parent->getCVariable(name);
    }
    return nullptr;
}

int CFunction::getThisIndex(const string& name) const {
    auto argIndex = 0;
    for (auto it : node->assignments) {
        if (it->getNodeType() == NodeType_Assignment) {
            auto t = (const NAssignment*)it.get();
            if (t->name == name) {
                return argIndex;
            }
        }
        argIndex++;
    }
    return -1;
}


