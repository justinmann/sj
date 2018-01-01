//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include <sjc.h>

CNormalVar::CNormalVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type, string name, bool isMutable, CVarType mode) : 
CStoreVar(loc, scope, name, mode == Var_Local ? (scope->function->name == "global" ? "g_" : "") + name : name, isMutable), 
mode(mode), type(type) {}

CNormalVar::CNormalVar(CLoc loc, shared_ptr<CScope> scope, shared_ptr<CType> type, string name, string cname, bool isMutable, CVarType mode, shared_ptr<CVar> dotVar) : 
CStoreVar(loc, scope, name, cname, isMutable), 
mode(mode), type(type), dotVar(dotVar) {}

shared_ptr<CType> CNormalVar::getType(Compiler* compiler) {
    if (dotVar && type->typeMode == CTM_ValuePtr) {
        return type->getStackType();
    }
    return type;
}

shared_ptr<CNormalVar> CNormalVar::createForDot(shared_ptr<CVar> dotVar) {
    assert(this->dotVar == nullptr);
    assert(dotVar != nullptr);
    assert(mode == Var_Public || mode == Var_Private);
    return make_shared<CNormalVar>(loc, scope.lock(), type, name, cname, isMutable, mode, dotVar);
}

bool CNormalVar::getReturnThis() {
    return false;
}

void CNormalVar::transpile(Compiler* compiler, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, shared_ptr<TrStoreValue> storeValue) {
    if (dotVar) {
        if (type->typeMode == CTM_ValuePtr) {
            auto dotValue = trBlock->createCaptureStoreVariable(loc, nullptr, dotVar->getType(compiler)->getTempType());
            dotVar->transpile(compiler, trOutput, trBlock, thisValue, dotValue);
            auto returnValue = make_shared<TrValue>(scope.lock(), type->getStackType(), "*" + TrValue::convertToLocalName(dotValue->type, dotValue->getCaptureText(), false) + "->" + cname, false);
            storeValue->retainValue(compiler, storeValue->loc, trBlock, returnValue);
        }
        else {
            auto dotValue = trBlock->createCaptureStoreVariable(loc, nullptr, dotVar->getType(compiler)->getTempType());
            dotVar->transpile(compiler, trOutput, trBlock, thisValue, dotValue);
            auto returnValue = make_shared<TrValue>(scope.lock(), type, TrValue::convertToLocalName(dotValue->type, dotValue->getCaptureText(), false) + "->" + cname, false);
            storeValue->retainValue(compiler, storeValue->loc, trBlock, returnValue);
        }
    } else if (trBlock->hasThis && (mode == Var_Public || mode == Var_Private)) {
        auto returnValue = make_shared<TrValue>(scope.lock(), type, "_this->" + cname, false);
        storeValue->retainValue(compiler, storeValue->loc, trBlock, returnValue);
    } else {
        auto returnValue = make_shared<TrValue>(scope.lock(), type, cname, false);
        storeValue->retainValue(compiler, storeValue->loc, trBlock, returnValue);
    }
}

bool CNormalVar::getCanStoreValue() {
    return isMutable;
}

shared_ptr<TrStoreValue> CNormalVar::getStoreValue(Compiler* compiler, shared_ptr<CScope> scope_, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<TrValue> thisValue, AssignOp op) {
    stringstream lineStream;

    string varName;
    if (dotVar) {
        if (type->typeMode == CTM_ValuePtr) {
            auto dotValue = trBlock->createCaptureStoreVariable(loc, nullptr, dotVar->getType(compiler)->getTempType());
            dotVar->transpile(compiler, trOutput, trBlock, thisValue, dotValue);
            if (dotValue->type->typeMode == CTM_Stack) {
                varName = "*" + dotValue->getCaptureText() + "." + cname;
            }
            else {
                varName = "*" + dotValue->getCaptureText() + "->" + cname;
            }
            return make_shared<TrStoreValue>(loc, scope.lock(), type->getStackType(), varName, op);
        }
        else {
            auto dotValue = trBlock->createCaptureStoreVariable(loc, nullptr, dotVar->getType(compiler)->getTempType());
            dotVar->transpile(compiler, trOutput, trBlock, thisValue, dotValue);
            if (dotValue->type->typeMode == CTM_Stack) {
                varName = dotValue->getCaptureText() + "." + cname;
            }
            else {
                varName = dotValue->getCaptureText() + "->" + cname;
            }
        }
    }
    else if (trBlock->hasThis && (mode == Var_Public || mode == Var_Private)) {
        varName = "_this->" + cname;
    }
    else {
        if (op.isFirstAssignment) {
            if (scope.lock()->function->name != "global" || scope.lock()->function == scope_->function) {
                trBlock->createVariable(scope.lock(), type, cname);
            }
        }
        else if (!isMutable) {
            // Check is mutable or first assignment
            compiler->addError(loc, CErrorCode::TypeMismatch, "cannot assign to immutable variable");
            return nullptr;
        }
        varName = cname;
    }
    
    return make_shared<TrStoreValue>(loc, scope.lock(), type, varName, op);
}

void CNormalVar::dump(Compiler* compiler, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    if (dotVar) {
        dotVar->dump(compiler, functions, ss, level);
        ss << ".";
    }
    ss << name;
}


