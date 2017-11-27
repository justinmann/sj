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
        lineStream << cname;
        trBlock->statements.push_back(lineStream.str());
        storeValue->retainValue(compiler, storeValue->loc, trBlock, returnValue);
    } else if (trBlock->hasThis && (mode == Var_Public || mode == Var_Private)) {
        auto returnValue = trBlock->createTempVariable(scope.lock(), type, "dotTemp");
        stringstream lineStream;
        lineStream << returnValue->name << " = " << "_this->" << cname;
        trBlock->statements.push_back(lineStream.str());
        storeValue->retainValue(compiler, storeValue->loc, trBlock, returnValue);
    } else {
        auto returnValue = make_shared<TrValue>(scope.lock(), type, cname, false);
        storeValue->retainValue(compiler, storeValue->loc, trBlock, returnValue);
    }
}

bool CNormalVar::getCanStoreValue() {
    return isMutable;
}

shared_ptr<TrStoreValue> CNormalVar::getStoreValue(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> dotValue, shared_ptr<TrValue> thisValue, AssignOp op, bool isFirstAssignment) {
    stringstream lineStream;

    string varName;
    if (dotValue) {
        if (dotValue->type->typeMode == CTM_Stack) {
            varName = dotValue->name + "." + cname;
        }
        else {
            varName = dotValue->name + "->" + cname;
        }
    }
    else if (trBlock->hasThis && (mode == Var_Public || mode == Var_Private)) {
        varName = "_this->" + cname;
    }
    else {
        if (!trBlock->getVariable(cname)) {
            trBlock->createVariable(scope.lock(), type, cname);
        }
        else if (!isMutable) {
            // Check is mutable or first assignment
            compiler->addError(loc, CErrorCode::TypeMismatch, "cannot assign to immutable variable");
            return nullptr;
        }
        varName = cname;
    }
    
    return make_shared<TrStoreValue>(loc, scope.lock(), type, varName, op, isFirstAssignment);
}

void CNormalVar::dump(Compiler* compiler, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    auto t = dotSS.str();
    if (t.size() > 0) {
        ss << t << ".";
    }    
    else if (mode == Var_Public || mode == Var_Private) {
        ss << "this.";
    }
    
    ss << name;
}


