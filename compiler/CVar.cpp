//
//  Compiler.cpp
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#include "../node/Node.h"

void CNormalVar::makeFunctionVar() {
    assert(mode == CVarType::Var_Local);
    mode = CVarType::Var_Public;
}

shared_ptr<CType> CNormalVar::getType(Compiler* compiler, CResult& result) {
    return type;
}

shared_ptr<ReturnValue> CNormalVar::transpileGet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, const char* thisName) {
    if (dotValue) {
        auto returnValue = trBlock->createTempVariable(type, "dotTemp");
        stringstream lineStream;
        lineStream << returnValue->name << " = " << dotValue->name << "->" << name;
        trBlock->statements.push_back(lineStream.str());
        return returnValue;
    } else if (trBlock->hasThis && (mode == Var_Public || mode == Var_Private)) {
        auto returnValue = trBlock->createTempVariable(type, "dotTemp");
        stringstream lineStream;
        lineStream << returnValue->name << " = " << "_this->" << name;
        trBlock->statements.push_back(lineStream.str());
        return returnValue;
    } else {
        return make_shared<ReturnValue>(type, name);
    }    
}

void CNormalVar::transpileSet(Compiler* compiler, CResult& result, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName, AssignOp op, bool isFirstAssignment) {
    stringstream lineStream;

    if (!returnValue)
        return;

    auto leftType = getType(compiler, result);
    auto rightType = returnValue->type;
    if (!CType::isSameExceptMode(leftType, rightType)) {
        result.addError(loc, CErrorCode::TypeMismatch, "right type '%s' does not match left type '%s'", rightType->name.c_str(), leftType->name.c_str());
        return;
    }

    if (leftType->typeMode != CTM_Local && leftType->typeMode != rightType->typeMode && op != ASSIGN_MutableCopy && op != ASSIGN_ImmutableCopy) {
        result.addError(loc, CErrorCode::TypeMismatch, "right type '%s' cannot change mode to left type '%s' without using a :copy or =copy assignment", rightType->name.c_str(), leftType->name.c_str());
        return;
    }

    string varName;
    if (dotValue) {
        varName = dotValue->name + "->" + name;
    }
    else if (trBlock->hasThis && (mode == Var_Public || mode == Var_Private)) {
        varName = "_this->" + name;
    }
    else {
        if (!trBlock->getVariable(name)) {
            isFirstAssignment = true;
            trBlock->createVariable(leftType, name);
        }
        else if (!isMutable) {
            // Check is mutable or first assignment
            result.addError(loc, CErrorCode::TypeMismatch, "cannot assign to immutable variable", leftType->name.c_str(), rightType->name.c_str());
            return;
        }
        varName = name;
    }
    
    auto varValue = make_shared<ReturnValue>(leftType, varName);
    if (op == ASSIGN_MutableCopy || op == ASSIGN_ImmutableCopy) {
        varValue->addCopyToStatements(trBlock, returnValue->type, returnValue->name, isFirstAssignment);
    }
    else {
        varValue->addAssignToStatements(trBlock, returnValue->type, returnValue->name, isFirstAssignment);
    }
}

void CNormalVar::dump(Compiler* compiler, CResult& result, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    if (dotSS.gcount()) {
        ss << dotSS.str() << ".";
    }
    
    if (mode == Var_Public || mode == Var_Private) {
        ss << "this.";
    }
    
    ss << name;
}


