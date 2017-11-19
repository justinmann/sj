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

shared_ptr<CType> CNormalVar::getType(Compiler* compiler, CResult& result, CTypeMode returnMode) {
    return type;
}

shared_ptr<ReturnValue> CNormalVar::transpileGet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, CTypeMode returnMode, shared_ptr<ReturnValue> dotValue, const char* thisName) {
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

void CNormalVar::transpileSet(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, shared_ptr<ReturnValue> dotValue, shared_ptr<ReturnValue> returnValue, const char* thisName) {
    stringstream lineStream;

    if (!returnValue)
        return;

    auto returnType = getType(compiler, result, CTM_Undefined);
    if (returnType != returnValue->type) {
        result.addError(loc, CErrorCode::TypeMismatch, "returned type '%s' does not match explicit type '%s'", returnType->name.c_str(), returnValue->type->name.c_str());
        return;
    }

    string varName;
    bool isFirstAssignment = false;

    if (dotValue) {
        varName = dotValue->name + "->" + name;
    }
    else if (trBlock->hasThis && (mode == Var_Public || mode == Var_Private)) {
        if (!isMutable) {
            // TODO: this may not be the first assignment
            isFirstAssignment = true;
        }
        varName = "_this->" + name;
    }
    else {
        if (!trBlock->getVariable(name)) {
            isFirstAssignment = true;
            trBlock->createVariable(returnType, name);
        }
        else if (!isMutable) {
            // Check is mutable or first assignment
            result.addError(loc, CErrorCode::TypeMismatch, "cannot assign to immutable variable", returnType->name.c_str(), returnValue->type->name.c_str());
            return;
        }
        varName = name;
    }
    
    auto varValue = make_shared<ReturnValue>(returnType, varName);
    varValue->addAssignToStatements(trBlock, returnValue->name, isFirstAssignment);
}

void CNormalVar::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CThisVar> thisVar, CTypeMode returnMode, shared_ptr<CVar> dotVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, stringstream& dotSS, int level) {
    if (dotSS.gcount()) {
        ss << dotSS.str() << ".";
    }
    
    if (mode == Var_Public || mode == Var_Private) {
        ss << "this.";
    }
    
    ss << name;
}


