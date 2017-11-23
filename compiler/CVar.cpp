//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "../node/Node.h"

shared_ptr<CType> CNormalVar::getType(Compiler* compiler) {
    return type;
}

bool CNormalVar::getReturnThis() {
    return false;
}

void CNormalVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    if (dotValue) {
        auto returnValue = trBlock->createTempVariable(scope.lock(), type, "dotTemp");
        stringstream lineStream;
        lineStream << returnValue->name << " = " << dotValue->name;
        if (dotValue->type->typeMode == CTM_Stack) {
            lineStream << ".";
        }
        else {
            lineStream << "->";
        }
        lineStream << name;
        trBlock->statements.push_back(lineStream.str());
        storeValue->retainValue(compiler, trBlock, returnValue);
    } else if (trBlock->hasThis && (mode == Var_Public || mode == Var_Private)) {
        auto returnValue = trBlock->createTempVariable(scope.lock(), type, "dotTemp");
        stringstream lineStream;
        lineStream << returnValue->name << " = " << "_this->" << name;
        trBlock->statements.push_back(lineStream.str());
        storeValue->retainValue(compiler, trBlock, returnValue);
    } else {
        auto returnValue = make_shared<TrValue>(scope.lock(), type, name, false);
        storeValue->retainValue(compiler, trBlock, returnValue);
    }
}

shared_ptr<TrStoreValue> CNormalVar::getStoreValue(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, AssignOp op, bool isFirstAssignment) {
    stringstream lineStream;

    string varName;
    if (dotValue) {
        if (dotValue->type->typeMode == CTM_Stack) {
            varName = dotValue->name + "." + name;
        }
        else {
            varName = dotValue->name + "->" + name;
        }
    }
    else if (trBlock->hasThis && (mode == Var_Public || mode == Var_Private)) {
        varName = "_this->" + name;
    }
    else {
        if (!trBlock->getVariable(name)) {
            trBlock->createVariable(scope.lock(), type, name);
        }
        else if (!isMutable) {
            // Check is mutable or first assignment
            compiler->addError(loc, CErrorCode::TypeMismatch, "cannot assign to immutable variable");
            return nullptr;
        }
        varName = name;
    }
    
    return make_shared<TrStoreValue>(loc, scope.lock(), type, varName, op, isFirstAssignment);
}

void CNormalVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    if (dotSS.gcount()) {
        ss << dotSS.str() << ".";
    }
    
    if (mode == Var_Public || mode == Var_Private) {
        ss << "this.";
    }
    
    ss << name;
}


